// ImageClassTester.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <stdio.h>
#include <iostream>
#include "MyImage.h"
#include "MyHisto.h"
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
void resize();
void invert();
void makeBinary();
void calcHisto();
void calcThreshByOtsu();
string images[] = {"Flower.bmp", "Kap.bmp", "Pedestrians.bmp", "SinglePedestrian.bmp", "Zellen1.bmp", "Zellen2.bmp", "Zellen3.bmp"};

int main(int argc, char *argv[]) {
    //resize();
    //invert();
    makeBinary();
    calcHisto();
    calcThreshByOtsu();
    return 0;
}

void resize() {
    cout << "resizing image...\n";
    CMyImage testImage = CMyImage();
    testImage.ReadBmpFile(((string(loadPath).append("Kap.bmp")).c_str()));

    // resize image
    testImage.Resize(20, 20);
    testImage.WriteBmpFile((string(savePath).append("resize.bmp")).c_str());
    cout << "done\n";
}

void invert() {
    cout << "inverting image...\n";
    CMyImage testImage = CMyImage();
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
    double indirectAccessTime = (double) (finish - start) / CLOCKS_PER_SEC;
    // write image for check
    testImage.WriteBmpFile((string(savePath).append("indirectInvert.bmp")).c_str());


    testImage.ReadBmpFile((string(loadPath).append("Kap.bmp")).c_str());
    // invert image with pointer memory access
    startDirectAccess = clock();

    testImage.Invert();

    finishDirectAccess = clock();
    double directAccessTime = (double) (finishDirectAccess - startDirectAccess) / CLOCKS_PER_SEC;
    // write image for check
    testImage.WriteBmpFile((string(savePath).append("directInvert.bmp")).c_str());

    // print results
    cout << "\tindirectAccessTime: " + std::to_string(indirectAccessTime) + " seconds\n";
    cout << "\tdirectAccessTime: " + std::to_string(directAccessTime) + " seconds\n";
    cout << "\tfactor: " + std::to_string(indirectAccessTime / directAccessTime) + "\n";
    cout << "done\n";
}

void makeBinary() {
    CMyImage testImage = CMyImage();
    for (int i = 0; i < 7; ++i) {
        cout << "binarizing " + images[i] + "\n";
        // makeBinary
        testImage.ReadBmpFile((string(loadPath).append(images[i])).c_str());
        testImage.MakeBinary(150);
        // write image for check
        testImage.WriteBmpFile((string(savePath).append("makeBinary").append(images[i])).c_str());
    }
}

void calcHisto() {
    CMyImage testImage = CMyImage();
    for (int i = 0; i < 7; ++i) {
        cout << "generating histo image of " + images[i] + "\n";
        // makeBinary
        testImage.ReadBmpFile((string(loadPath).append(images[i])).c_str());
        CMyHisto histo = CMyHisto();
        testImage.CalcHisto(histo);
        // write image for check
        histo.WriteHistoBmp((string(savePath).append("histo").append(images[i])).c_str());
    }
}

void calcThreshByOtsu(){
    CMyImage testImage = CMyImage();
    int threshold;
    for (int i = 0; i < 7; ++i) {
        cout << "calculating thresholdByOtsu of " + images[i] + "\n";
        // makeBinary
        testImage.ReadBmpFile((string(loadPath).append(images[i])).c_str());

        threshold = testImage.CalcThreshByOtsu();
        cout << "\tthreshold is: " + std::to_string(threshold) + "\n";
    }
}