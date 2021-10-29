// ImageClassTester.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <stdio.h>
#include <iostream>
#include "MyImage.h"
#include "MyHisto.h"
#include <time.h>

#define ABSOLUTE

int main(int argc, char *argv[]) {
    // resize image
#ifdef ABSOLUTE
    string loadPath = "/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/Bilder/";
    string savePath = "/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/out/";
#else
    char* loadPath = "./Bilder/";
    char*  savePath = "./out/";
#endif
    CMyImage testImage = CMyImage();
    testImage.ReadBmpFile(((string(loadPath).append("Kap.bmp")).c_str()));

    // resize image
    testImage.Resize(20, 20);
    testImage.WriteBmpFile((string(savePath).append("resize.bmp")).c_str());

    // invert image with getter
    testImage.ReadBmpFile((string(loadPath).append("Kap.bmp")).c_str());
    clock_t start, finish, startDirectAccess, finishDirectAccess;

    int width = testImage.GetWidth();
    int height = testImage.GetHeight();
    start = clock();
    // set all pixels manually
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            testImage.SetPixel(i, j, 255 - testImage.GetPixel(i, j));
        }
    }
    finish = clock();
    double indirectAccessTime = (double)(finish - start) / CLOCKS_PER_SEC;
    // write image for check
    testImage.WriteBmpFile((string(savePath).append("getter.bmp")).c_str());

    // invert image with pointer memory access
    startDirectAccess = clock();
    unsigned char* testImageData = testImage.GetData();
    int size = width * height;
    for (int i = 0; i < size; i++) {
        testImageData[i] = 255 - testImageData[i];
    }
    finishDirectAccess = clock();
    double directAccessTime = (double)(finishDirectAccess - startDirectAccess) / CLOCKS_PER_SEC;
    // write image for check (image should look like source image again)
    testImage.WriteBmpFile((string(savePath).append("direct.bmp")).c_str());

    // print results
    cout << "\nindirectAccessTime: " + std::to_string(indirectAccessTime) + " seconds\n";
    cout << "directAccessTime: " + std::to_string(directAccessTime) + " seconds\n";
    cout << "factor: " + std::to_string(indirectAccessTime/directAccessTime) + "\n";

    // makeBinary
    testImage.ReadBmpFile((string(loadPath).append("Kap.bmp")).c_str());
    testImage.MakeBinary(150);
    // write image for check
    testImage.WriteBmpFile((string(savePath).append("makeBinary.bmp")).c_str());

    // calcHisto
    testImage.ReadBmpFile((string(loadPath).append("Zellen1.bmp")).c_str());
    CMyHisto histo = CMyHisto();
    testImage.CalcHisto(histo);
    // write image for check
    histo.WriteHistoBmp((string(savePath).append("calcHisto.bmp")).c_str());
    return 0;
}
