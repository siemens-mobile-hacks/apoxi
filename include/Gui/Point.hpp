/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Point_hpp)
#define Apoxi_Point_hpp

#include <Kernel/Os/Os.hpp>


class Rect;

class Point {
    public:
        Point(XYDIM x = 0, XYDIM y = 0) : m_x(x), m_y(y) {}

        Point(const Point& point) : m_x(point.GetX()), m_y(point.GetY()) {}

        void SetX(XYDIM x) { m_x = x; }

        XYDIM GetX() const { return m_x; }

        void SetY(XYDIM y) { m_y = y; }

        XYDIM GetY() const { return m_y; }

        BOOLEAN IsInside(const Rect& rect) const;

        void Move(XYDIM dx, XYDIM dy) { m_x += dx; m_y += dy; }

    private:
        XYDIM m_x;
        XYDIM m_y;
};

#endif  // Apoxi_Point_hpp


