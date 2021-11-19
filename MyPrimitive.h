//
// Created by lluks on 19/11/2021.
//

#ifndef UNTITLED_MYPRIMITIVE_H
#define UNTITLED_MYPRIMITIVE_H

struct CMyPoint {
    int m_x;
    int m_y;

    CMyPoint() {
        m_x = 0;
        m_y = 0;
    };

    CMyPoint(int x, int y) {
        m_x = x;
        m_y = y;
    };

    CMyPoint(const CMyPoint &toCopy) {
        m_x = toCopy.m_x;
        m_y = toCopy.m_y;
    };
};


class CMyPrimitive {
public :
    vector <CMyPoint> m_points;
public :
    CMyPrimitive(void);

    ~CMyPrimitive(void);

    void Reset() { m_points.empty(); };

    void Resize(int size) { m_points.resize(size); };

    void Append(int x, int y);
};

#endif //UNTITLED_MYPRIMITIVE_H
