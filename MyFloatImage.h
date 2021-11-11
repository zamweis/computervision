#pragma once
#include "mytypeimage.h"

class CMyCharImage;

class CMyFloatImage :  public CMyTypeImage<float>
{
public:
    CMyFloatImage(void);
    ~CMyFloatImage(void);

    void Convert(const CMyCharImage& toCopy);

    // Apply fabs-function to pixel-values
    void ApplyAbs();


};
