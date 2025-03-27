/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Rect_hpp)
#define Apoxi_Rect_hpp

#include <Gui/Point.hpp>
#include <Gui/Size.hpp>
#include <Kernel/Os/Os.hpp>


class Rect {
    public:
        Rect();

        Rect(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom);

        Rect(const Point& pos, const Size& size);
        
        // needed because of a bug in the tasking-compiler
        Rect(const Rect& rect) { *this = rect; }

        void SetLeft(XYDIM left) { m_left = left; }

        XYDIM GetLeft() const { return m_left; }

        void SetTop(XYDIM top) { m_top = top; }

        XYDIM GetTop() const { return m_top; }

        void SetRight(XYDIM right)  { m_right = right; }

        XYDIM GetRight() const  { return m_right;}

        void SetBottom(XYDIM bottom) { m_bottom = bottom; }

        XYDIM GetBottom() const { return m_bottom; }

        void SetWidth(XYDIM width) { m_right = m_left + width - 1; }

        XYDIM GetWidth() const { return m_right - m_left + 1; }

        void SetHeight(XYDIM height) { m_bottom = m_top + height - 1; }

        XYDIM GetHeight() const { return m_bottom - m_top + 1; }

        void SetSize(const Size& size);

        void SetSize(XYDIM width, XYDIM height);

        Size GetSize() const { return Size(GetWidth(), GetHeight()); }

        void Move(XYDIM dx, XYDIM dy);

        void SetEmpty();

        BOOLEAN IsEmpty() const { return (m_right < m_left || m_bottom < m_top); }

        const Rect& Intersect(const Rect& rect);

        const Rect& Union(const Rect& rect);

        BOOLEAN IsInside(const Rect& rect) const;

        void Set(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom);

        void Expand(XYDIM left, XYDIM top = 0, XYDIM right = 0, XYDIM bottom = 0);

        BOOLEAN operator==(const Rect& rect) const;

        BOOLEAN operator!=(const Rect& rect) const;

        void SetPos(const Point& pos);

        void SetPos(XYDIM x, XYDIM y);

        Point GetPos() const;

        void SetXPos(XYDIM x);

        XYDIM GetXPos() const;
        
        void SetYPos(XYDIM y);

        XYDIM GetYPos() const;

    protected:
        XYDIM m_left;
        XYDIM m_top;
        XYDIM m_right;
        XYDIM m_bottom;
};

#endif  // Apoxi_Rect_hpp


