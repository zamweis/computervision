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
    if (r < 1 || mx < 0 || my < 0) return false;
    // arithmetic middle
    double middleX = 0;
    double middleY = 0;
    int m = GetSize();
    for (int i = 0; i < m; ++i) {
        middleX += m_points[i].m_x;
        middleY += m_points[i].m_y;
    }
    if (middleX != 0 && middleY != 0) {
        middleX /= m;
        middleY /= m;
    }
    // center all pixels relative to the arithmetic middle
    for (int i = 0; i < m; ++i) {
        m_points[i].m_x -= middleX;
        m_points[i].m_y -= middleY;
    }
    double radius = 0;
    for (int i = 0; i <; i++) {
        radius += sqrt(m_points[i].m_x * m_points[i].m_x + m_points[i].m_y * m_points[i].m_y);
    }
    radius /= m;
    return true;
}