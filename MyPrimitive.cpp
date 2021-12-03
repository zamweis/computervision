//
// Created by lluks on 19/11/2021.
//

#include "MyPrimitive.h"


CMyPrimitive::CMyPrimitive(void) {

}

CMyPrimitive::~CMyPrimitive(void) {

}

void CMyPrimitive::Append(int x, int y) {
    if (x >= 0 && y >= 0) {
        m_points.push_back(CMyPoint(x, y));
    }
};

bool CMyPrimitive::FitCircle(double &mx, double &my, double &r) {
    if () return false;
    return true;
}