// ImageClassTester.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <stdio.h>
#include <iostream>
#include "MyImage.h"
#include "MyHisto.h"
#include <time.h>

int main(int argc, char *argv[]) {
    // resize image

    CMyImage testImage = CMyImage();
    testImage.ReadBmpFile("/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/Bilder/Kap.bmp");
    testImage.Resize(20, 20);
    testImage.WriteBmpFile("/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/out/resize.bmp");

    // get image (Kap.bmp)
    testImage.ReadBmpFile("/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/Bilder/Kap.bmp");
    clock_t start, finish, startDirectAccess, finishDirectAccess;

    int width = testImage.GetWidth();
    int height = testImage.GetHeight();


    cout << "height: " + std::to_string(height);
    cout << "\nwidth: " + std::to_string(width) + "\n";

    // invert image with getter
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
    testImage.WriteBmpFile("/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/out/getter.bmp");


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
    testImage.WriteBmpFile("/home/lluks/Work/HsKA/Semester_6/Bildverarbeuitungslabor/computervision/out/direct.bmp");

    // print results
    cout << "\nindirectAccessTime: " + std::to_string(indirectAccessTime) + " seconds\n";
    cout << "directAccessTime: " + std::to_string(directAccessTime) + " seconds\n";
    cout << "factor: " + std::to_string(indirectAccessTime/directAccessTime) + "\n";
    return 0;
}
