// TypeImageClassTester.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "MyCharImage.h"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>

#define ABSOLUTE
// resize image
#ifdef ABSOLUTE
string loadPath = "/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/Bilder/";
string savePath = "/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/out/";
#else
char* loadPath = "./Bilder/";
    char*  savePath = "./out/";
#endif

void applyThresh();

void copyChannel();

void applyMeanFilter();

void nextContour();

void rgb2hsi();

vector<string> images = {"Kreis.bmp", "KreisViertel.bmp", "KreisPunkte.bmp", "KreisHalb.bmp", "KreisGerade.bmp", "Kreis3Punkte.bmp", "Kreis2Punkte.bmp", "Ellipsen2.bmp"};
vector<string> imagesRGB = {"Spielzeug.bmp", "Rose.bmp", "Ferrari.bmp", "Ellipsen.bmp"};


int main(int argc, char *argv[]) {
    //copyChannel();
    //applyThresh();
    //applyMeanFilter();
    nextContour();
    rgb2hsi();
    return 0;
}

void applyThresh() {
    CMyCharImage rose = CMyCharImage();
    rose.ReadBmpFile((string(loadPath).append(images[0])).c_str());
    // makeBinary
    int channels = rose.GetDepth();
    for (int currentChannel = 0; currentChannel < channels; currentChannel++) {
        for (double thresh = 0; thresh < 255; thresh += 25) {
            //cout << "applyThresh(" << currentChannel << "x" << thresh << "\n";
            CMyCharImage testImage = CMyCharImage();
            testImage.ApplyThresh(rose, thresh, currentChannel);
            // write image for check
            testImage.WriteBmpFile(
                    (string(savePath).append("ApplyThresh").append("(").append(
                            std::to_string(currentChannel)).append(
                            "x").append(std::to_string((int) thresh)).append(")").append(images[0])).c_str());
        }
    }
}

void copyChannel() {
    CMyCharImage rose = CMyCharImage();
    // makeBinary
    rose.ReadBmpFile((string(loadPath).append(images[0])).c_str());
    int channels = rose.GetDepth();
    //cout << "depth: " << rose.GetDepth() << "\n";
    for (int currentChannel = 0; currentChannel < channels; currentChannel++) {
        //cout << "copyChannel(" << currentChannel << ")\n";
        CMyCharImage testImage = CMyCharImage();
        testImage.CopyChannel(rose, currentChannel);
        //cout << "channel copied\n";
        testImage.WriteBmpFile(
                (string(savePath).append("CopyChannel").append(std::to_string(currentChannel)).append("_").append(
                        images[0])).c_str());
        //cout << "image saved\n";
    }
}

void applyMeanFilter() {
    // makeBinary
    for (int i = 0; i < images.size(); ++i) {
        CMyCharImage testimage = CMyCharImage();
        testimage.ReadBmpFile((string(loadPath).append(images[i])).c_str());
        int channels = testimage.GetDepth();
        //cout << "depth: " << testimage.GetDepth() << "\n";
        cout << "\timage: " << images[i] << "\n";
        for (int currentChannel = 0; currentChannel < channels; currentChannel++) {
            CMyCharImage meanImage = CMyCharImage();
            meanImage.CopyChannel(testimage, currentChannel);
            cout << "\tchannel " << currentChannel << " copied\n";
            meanImage.ApplyMeanFilter(testimage);
            cout << "\tMeanfilter applied\n";
            meanImage.WriteBmpFile(
                    (string(savePath).append("MeanFilter_").append(std::to_string(currentChannel)).append("_").append(
                            images[i])).c_str());
            cout << "\tsaved\n";
        }
    }
}

void nextContour(){
    for (int i = 0; i < images.size(); i++) {
        CMyCharImage testimage = CMyCharImage();
        testimage.ReadBmpFile((string(loadPath).append(images[i])).c_str());
        CMyPrimitive globalList = CMyPrimitive();
        testimage.ExtractNextContour(globalList);
        unsigned char *data = (unsigned char *) testimage.GetData();
        //testimage.WriteBmpFile((string(savePath).append("FitCircle").append("_").append(images[i])).c_str());
        for (CMyPoint p: globalList.m_points) {
            data[p.m_y * testimage.GetWidth() + p.m_x] = 255;
        }
        double mx;
        double my;
        double r;
        globalList.FitCircle(mx, my, r);
        data[((int) my * testimage.GetWidth() + (int) mx)] = 125;
        testimage.WriteBmpFile((string(savePath).append("FitCircleDrawn").append("_").append(images[i])).c_str());
    }
}

void rgb2hsi(){
    for (int i = 0; i < imagesRGB.size(); i++) {
        CMyCharImage testimage = CMyCharImage();
        testimage.ReadBmpFile((string(loadPath).append(imagesRGB[i])).c_str());
        testimage.RGB2HSI(testimage);
        int channels = testimage.GetDepth();
        //cout << "depth: " << rose.GetDepth() << "\n";
        for (int currentChannel = 0; currentChannel < channels; currentChannel++) {
            //cout << "copyChannel(" << currentChannel << ")\n";
            CMyCharImage tmp = CMyCharImage();
            tmp.CopyChannel(testimage, currentChannel);
            //cout << "channel copied\n";
            tmp.WriteBmpFile((string(savePath).append("RGB2HSI").append(imagesRGB[i]).append("_").append(std::to_string(currentChannel))).c_str());
            //cout << "image saved\n";
        }
        testimage.WriteBmpFile((string(savePath).append("RGB2HSI").append("_").append(imagesRGB[i])).c_str());
    }
}
