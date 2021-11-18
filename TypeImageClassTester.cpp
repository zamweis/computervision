// TypeImageClassTester.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "MyCharImage.h"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <time.h>

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

string images[] = {"Rose.bmp", "Pedestrians1.bmp", "Pedestrians2.bmp"};

int main(int argc, char *argv[]) {
    copyChannel();
    return 0;
}

void applyThresh() {
    CMyCharImage testImage = CMyCharImage();
    cout << "applyThresh() " + images[0] + "\n";
    // makeBinary
    testImage.ReadBmpFile((string(loadPath).append(images[0])).c_str());
    int channels = testImage.GetDepth();
    for (int currentChannel = 0; currentChannel < channels; currentChannel++) {
        for (double thresh = 0; thresh < 255; thresh += 50) {
            testImage.ApplyThresh(testImage, thresh, currentChannel);
            // write image for check
            testImage.WriteBmpFile(
                    (string(savePath).append("applyThresh").append("(").append(std::to_string(currentChannel)).append(
                            "x").append(std::to_string(thresh)).append(")").append(images[0])).c_str());
        }
    }
}

void copyChannel() {
    CMyCharImage rose = CMyCharImage();
    // makeBinary
    rose.ReadBmpFile((string(loadPath).append(images[0])).c_str());
    int channels = rose.GetDepth();
    cout << "depth: " << rose.GetDepth() << "\n";
    for (int currentChannel = 0; currentChannel < channels; currentChannel++) {
        CMyCharImage testImage = CMyCharImage();
        testImage.CopyChannel(rose, currentChannel);
        cout << "channel copied\n";
        testImage.WriteBmpFile((string(savePath).append("Channelv2_").append(std::to_string(currentChannel)).append("_").append(
                images[0])).c_str());
        cout << "image saved\n";
    }
}
