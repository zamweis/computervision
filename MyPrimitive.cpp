//
// Created by lluks on 19/11/2021.
//

#include "MyPrimitive.h"
#include "math.h"


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
    // arithmetic middle
    mx = 0;
    my = 0;
    int m = GetSize();
    for (int i = 0; i < m; ++i) {
        mx += m_points[i].m_x;
        my += m_points[i].m_y;
    }
    if (mx != 0 && my != 0) {
        mx /= m;
        my /= m;
    }
    // center all pixels relative to the arithmetic middle
    for (int i = 0; i < m; ++i) {
        m_points[i].m_x -= mx;
        m_points[i].m_y -= my;
    }
    r = 0;
    for (int i = 0; i < GetSize(); i++) {
        r += sqrt(m_points[i].m_x * m_points[i].m_x + m_points[i].m_y * m_points[i].m_y);
    }
    r /= m;
    //std::cout << "radius: " << r << ", mx: " << mx << ", my: " << my <<"\n";
    return true;
}