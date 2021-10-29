#include "MyHisto.h"
#include "MyImage.h"
#include <math.h>

CMyHisto::CMyHisto(void) {
    Reset();
    m_count = 0;
}

CMyHisto::~CMyHisto(void) {
}

void CMyHisto::Reset() {
    m_count = 0;
    for (int i = 0; i < HISTO_SIZE; i++)
        m_data[i] = 0;
}

void CMyHisto::Increment(unsigned char value) {
    m_count++;
    m_data[value]++;
}

bool CMyHisto::WriteHisto(const char *fileName) {
    ofstream os(fileName);
    if (!os)
        return false;

    for (int i = 0; i < HISTO_SIZE; i++) {
        os << i << "\t" << m_data[i] << endl;
    }
    os << "\t" << m_count << endl;
    os.close();
    return true;
}

bool CMyHisto::WriteNormalizedHisto(const char *fileName) {
    ofstream os(fileName);
    if (!os)
        return false;

    double count = m_count;
    for (int i = 0; i < HISTO_SIZE; i++) {
        os << i << "\t" << m_data[i] / count << endl;
    }
    os << "\t" << m_count << endl;
    os.close();
    return true;
}

double CMyHisto::CalcMeanValue() {
    if (m_count < 1)
        return -1.0;

    double mean = 0.0;
    for (int i = 0; i < HISTO_SIZE; i++) {
        mean += i * (double) m_data[i];
    }
    return mean / m_count;
}

double CMyHisto::CalcStandardDeviation(double mean) {
    if (m_count < 2)
        return -1.0;

    double sigma = 0.0;
    for (int i = 0; i < HISTO_SIZE; i++) {
        sigma += pow(i - mean, 2) * (double) m_data[i];
    }
    return sqrt(sigma / (m_count - 1));
}

int CMyHisto::GetEntry(int i) const {
    if ((i < 0) || (i >= HISTO_SIZE))
        return -1;
    else
        return m_data[i];
};

double CMyHisto::GetNormalizedEntry(int i) const {
    if ((i < 0) || (i >= HISTO_SIZE))
        return -1.0;
    else
        return m_data[i] / (double) m_count;
}

void CMyHisto::WriteHistoBmp(const char* fileName) {
    CMyImage img = CMyImage();
    img.Resize(256, 256);
    double max = 0.0;
    for (int i = 0; i < 256; i++) {
        max = GetNormalizedEntry(i) > max ? GetNormalizedEntry(i) : max;
    }
    for (int x = 0; x < 256; x++) {
        int value = (int)(255 * (GetNormalizedEntry(x) / max));
        for (int y = 0; y < value; y++) {
            img.SetPixel(x, 255 - y, 255);
        }
    }
    img.WriteBmpFile(fileName);
}
