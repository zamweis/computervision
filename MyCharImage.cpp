#include "StdAfx.h"
#include "MyCharImage.h"
#include "MyFloatImage.h"
#include "MyIntImage.h"
#include "math.h"

const double PI = 3.1415926535897932384626433832795;


CMyCharImage::CMyCharImage(void) {
}

CMyCharImage::~CMyCharImage(void) {
}

bool
CMyCharImage::CalcHisto(CMyHisto &histo, int channel) {
    histo.Reset();
    if ((channel < 0) || (channel >= m_depth))
        return false;

    int size = m_width * m_height;

    unsigned char *p = m_pData + channel;
    for (int i = 0; i < size; i++, p += m_depth)
        histo.Increment(*p);

    return true;
}

void
CMyCharImage::WriteBmpHeader(ostream &os, short int bbp, int offset, int sizeOfFile,
                             int sizeOfImage) const {
    int i;
    short int si;
    unsigned char ch;

    // ************************************ header = 14 byte ****************************

    // ASCII-Text BM = 2 bytes
    ch = 0x42;
    os.write((char *) &ch, 1);
    ch = 0x4D;
    os.write((char *) &ch, 1);

    // SizeOfFile
    os.write((char *) &sizeOfFile, 4);

    // Further Use, must be 0
    i = 0;
    os.write((char *) &i, 4);

    // Offset bis Bitmap in bytes = Header + BitmapInfo
    os.write((char *) &offset, 4);

    /************************* bitmap information = 44 bytes *************************/

    // number of bytes in header = 40
    i = 40;
    os.write((char *) &i, 4);

    // width and height in pixel
    os.write((char *) &m_width, 4);
    os.write((char *) &m_height, 4);

    // number of planes, must be 1
    si = 1;
    os.write((char *) &si, 2);
    // bits per pixel;
    os.write((char *) &bbp, 2);
    // compression 0 = no compression
    i = 0;
    os.write((char *) &i, 4);
    // size of image in bytes
    os.write((char *) &sizeOfImage, 4);
    // resolution, must be 0
    i = 0;
    os.write((char *) &i, 4);
    os.write((char *) &i, 4);
    // number of color indizes used and important
    i = 0; //256;
    os.write((char *) &i, 4);
    os.write((char *) &i, 4);
}

bool
CMyCharImage::ReadBmpHeader(istream &is, short int &bpp, int &width, int &height,
                            int &palEntries) const {
    int i, offset;
    unsigned char ch;
    short int si;

    // ************************************ header = 14 byte ****************************

    // ASCII-text BM = 2 bytes
    is.read((char *) &ch, 1);
    if (ch != 'B')
        return false;
    is.read((char *) &ch, 1);
    if (ch != 'M')
        return false;

    // size of file in bytes = header + bitmapInfo + palett entries + bitmap
    is.read((char *) &i, 4);
    // further use, must be 0
    is.read((char *) &i, 4);
    // offset till bitmap starts in bytes = header + bitmapInfo + palett entries
    is.read((char *) &offset, 4);

    /************************* Bitmap Information = 44 bytes *************************/

    // number of bytes in header (=40)
    is.read((char *) &i, 4);
    if (i != 40)
        return false;

    // width and height in pixel
    is.read((char *) &width, 4);
    is.read((char *) &height, 4);
    // number of planes, must be 1
    is.read((char *) &si, 2);
    if (si != 1)
        return false;

    // bits per pixel = 8;
    is.read((char *) &bpp, 2);
    // compression 0 = no compression
    is.read((char *) &i, 4);
    if (i != 0)
        return false;
    // size of image in bytes
    is.read((char *) &i, 4);

    // resolution, must be 0
    is.read((char *) &i, 4);
    is.read((char *) &i, 4);
    // number of color indizes used und important
    is.read((char *) &i, 4);
    is.read((char *) &i, 4);

    palEntries = (offset - 54);

    return ((bpp == 8) || (bpp == 24));
}

bool
CMyCharImage::ReadBmpFile(const char *fileName) {
    ifstream is(fileName, ios::binary);
    if (!is)
        return false;

    int width, height, palEntries;
    short int bpp;
    if (!ReadBmpHeader(is, bpp, width, height, palEntries))
        return false;

    unsigned char ch;
    unsigned char pixel;
    int i;

    if (bpp == 8)  // skip pal
    {
        for (i = 0; i < palEntries; i++)
            is.read((char *) &ch, 1);
    }

    Resize(width, height, bpp / 8);

    // increase no of bytes per line such that resulting number can be divided by 4
    int rest = (m_width * sizeof(unsigned char) * m_depth) % 4;
    if (rest != 0)
        rest = 4 - rest;

    unsigned char *p;
    int x, y, d, line;
    for (y = 0; y < m_height; y++) {
        line = m_height - y - 1;
        p = m_pData + line * m_width * m_depth;
        for (x = 0; x < m_width; x++) {
            for (d = m_depth - 1; d >= 0; d--) {
                is.read((char *) &ch, 1);
                pixel = ch;
                *(p + d) = pixel;
            }
            p += m_depth;
        }
        for (i = 0; i < rest; i++) {
            is.read((char *) &ch, 1);
        }
    }

    return true;
}


bool
CMyCharImage::WriteBmpFile(const char *fileName) const {
    if (m_width * m_height * m_depth <= 0)
        return false;

    if (m_pData == NULL)
        return false;

    if ((m_depth != 1) && (m_depth != 3))
        return false;

    /*  just for template classes
    if (typeid(T) != typeid(unsigned char))
      return false;
    */

    short int bpp;
    if (m_depth == 1)
        bpp = 8;
    if (m_depth == 3)
        bpp = 24;

    ofstream os(fileName, ios::binary);
    if (!os)
        return false;

    int i, x, y, d;
    unsigned char pixel = 0;
    unsigned char pixeldummy = 0;
    char ch;
    const unsigned char *p = m_pData;

    // increase no of bytes per line such that resulting number can be divided by 4
    int bytesProZeile = m_width * sizeof(unsigned char) * m_depth;
    int rest = bytesProZeile % 4;
    if (rest != 0) {
        rest = 4 - rest;
        bytesProZeile += rest;
    }

    int offset;
    int sizeOfFile;
    int sizeOfImage;
    if (bpp == 8) {
        // offset in bytes = Header + BitmapInfo + Palette
        offset = 1078;  // = 14 + 44 + 1024
    } else {
        // offset in bytes = Header + BitmapInfo
        offset = 54;  // = 14 + 44
    }
    // size of file in bytes = Header + BitmapInfo + Bitmap
    sizeOfFile = offset + m_height * bytesProZeile;
    // size of image in bytes
    sizeOfImage = m_height * bytesProZeile;

    WriteBmpHeader(os, bpp, offset, sizeOfFile, sizeOfImage);

    // ************************* palette entries = 1024 bytes *********************

    if (bpp == 8) {
        pixeldummy = 0;
        for (int j = 0; j < 256; j++) {
            ch = j;
            os.write((char *) &ch, 1);
            os.write((char *) &ch, 1);
            os.write((char *) &ch, 1);
            os.write((char *) &ch, 1);
        }
    }

    // ********* bitmap = height * bytesProZeile *********************************

    pixeldummy = 0;
    for (y = 0; y < m_height; y++) {
        p = m_pData + (m_height - y - 1) * m_width * m_depth;
        for (x = 0; x < m_width; x++) {
            for (d = m_depth - 1; d >= 0; d--)  // flip RGB to GBR
            {
                pixel = *(p + d);
                os.write((char *) &(pixel), 1);
            }
            p += m_depth;
        }
        for (i = 0; i < rest; i++)
            os.write((char *) &pixeldummy, 1);
    }

    os.close();

    return true;
}

void
CMyCharImage::Convert(const CMyFloatImage &toCopy) {
    if (m_pData != NULL) {
        free(m_pData);
        m_pData = NULL;
    }

    m_width = toCopy.GetWidth();
    m_height = toCopy.GetHeight();
    m_depth = toCopy.GetDepth();

    if (m_width * m_height * m_depth > 0) {
        m_pData = (unsigned char *) malloc(GetStorage());
        float value;
        const float *pSource = toCopy.GetData();
        unsigned char *pDest = m_pData;
        int size = m_width * m_height * m_depth;
        for (int i = 0; i < size; i++) {
            value = *pSource++;
            if (value > 255)
                value = 255;
            if (value < 0)
                value = 0;
            *pDest++ = (unsigned char) value;
        }
    } else
        m_pData = NULL;
}

int
CMyCharImage::CalculateThreshByOtsu(int channel) {
    CMyHisto histo;
    CalcHisto(histo, channel);

    if (histo.GetCount() == 0)
        return -1;

    double sigmaB = 0.0;
    double maxSigmaB = -1.0;

    int T;
    int TStar = -1;

    double count = (double) histo.GetCount();
    double mue = histo.CalcMean();
    double mueT = 0.0;
    double mueH = 0.0;
    double mueV = 0.0;
    double pH = 0.0;
    double hT = 0.0;
    for (T = 0; T < 255; T++) {
        hT = histo.GetEntry(T) / count;
        pH += hT;
        mueT += T * hT;
        if ((fabs(pH) > 1e-30) && (fabs(1 - pH) > 1e-30)) {
            sigmaB = pow(mue * pH - mueT, 2) / (pH * (1 - pH));
            if (sigmaB > maxSigmaB) {
                maxSigmaB = sigmaB;
                TStar = T;
            }
        }
    }
    return TStar;
}

/**********************************************************************************/
/***************************** Aufgaben *******************************************/
/**********************************************************************************/

bool
CMyCharImage::DifferenceImage(const CMyCharImage &image1, const CMyCharImage &image2) {
    /************** todo ****************/
    return true;
}


/**********************************************************************************/
/***************************** Tests **********************************************/
/**********************************************************************************/


bool
CMyCharImage::RGB2HSI(const CMyCharImage &source) {
    for (int y = 0; y < source.GetHeight(); ++y) {
        for (int x = 0; x < source.GetWidth(); ++x) {
            int p = y * GetWidth() * source.GetDepth() + x * source.GetDepth();
            double r = source.m_pData[p] / 255.0;
            double g = source.m_pData[p + 1] / 255.0;
            double b = source.m_pData[p + 2] / 255.0;
            double m = min(r, min(g, b));
            double h;
            if (r == g && g == b) {
                h = 0;
            } else {
                double phi = acos((0.5 * ((r - g) + (r - b))) / sqrt((r - g) * (r - g) + (r - b) * (g - b)));
                if (b <= g) {
                    h = phi;
                } else {
                    h = 2 * M_PI - phi;
                }
            }
            double s;
            if (r == g && r == b) {
                s = 0;
            } else {
                s = 1.0 - 3.0 * m / (r + g + b);
            }
            double i = (r + g + b) / 3.0;
            h = h * 180.0 / 2 * M_PI;
            s = s * 255.0;
            i = i * 255.0;
            if (h > 255) h = 255;
            if (s > 255) s = 255;
            if (i > 255) i = 255;
            if (h < 0) h = 0;
            if (s < 0) s = 0;
            if (i < 0) i = 0;
            source.m_pData[p] = (unsigned char) h;
            source.m_pData[p + 1] = (unsigned char) s;
            source.m_pData[p + 2] = (unsigned char) i;
        }
    }
    return true;
}

bool
CMyCharImage::HSI2RGB(const CMyCharImage &source) {
    /************** todo ****************/
    return true;
}

bool
CMyCharImage::ApplyMeanFilter(const CMyCharImage &source) {
    cout << "ApplyMeanFilter()\n";

    if (source.GetDepth() != 1) return false;

    int size = 25;
    int startX = 5 / 2;
    int startY = 5 / 2;
    int endX = source.GetWidth() - startX;
    int endY = source.GetHeight() - startY;
    CMyIntImage intImage = CMyIntImage();
    intImage.Resize(source.GetWidth(), source.GetHeight(), 1);
    Resize(source.GetWidth(), source.GetHeight(), 1);
    unsigned char *dataPointer = (unsigned char *) source.GetData() + startX;
    unsigned int *destinationDataPointer = (unsigned int *) intImage.GetData() + startX;

    // iterator going though all y
    for (int j = 0; j < m_height; j++) {
        // iterator going though all x
        for (int i = startX; i < endX; i++) {
            for (int x = -startX; x <= startX; x++) {
                *destinationDataPointer += *(dataPointer + x);
            }
            dataPointer++;
            destinationDataPointer++;
        }
        dataPointer += 4;
        destinationDataPointer += 4;
    }

    unsigned int *sourceDataPointer = (unsigned int *) intImage.GetData() + startX + startY * m_width;
    auto *thisDataPointer = m_pData + startX + (startY) * m_width;
    // iterator going though all x
    for (int i = startY; i < endY; i++) {
        for (int j = startX; j < endX; j++) {
            // iterator going though all y
            int puffer = 0;
            for (int y = -startY; y <= startY; y++) {
                puffer += *(sourceDataPointer + y * m_width);
            }
            *thisDataPointer = puffer / 25;
            thisDataPointer++;
            sourceDataPointer++;
        }
        thisDataPointer += 4;
        sourceDataPointer += 4;
    }
    return true;
}