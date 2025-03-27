/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_WinRect_hpp)
#define Apoxi_WinRect_hpp

#include <Kernel/Types.hpp>
#include <Gui/Rect.hpp>

class WinRect {
    public:
        WinRect();

        WinRect(const Rect &rect, XYDIM abs_left = 0, XYDIM abs_top = 0);

        void Init(const Rect &rect, XYDIM abs_left = 0, XYDIM abs_top = 0);

        void SetLeft(XYDIM left);

        XYDIM GetLeft() const   { return m_rel_rect.GetLeft(); }

        void SetTop(XYDIM top);

        XYDIM GetTop() const    { return m_rel_rect.GetTop(); }

        void SetRight(XYDIM right);

        XYDIM GetRight() const  { return m_rel_rect.GetRight(); }

        void SetBottom(XYDIM bottom);

        XYDIM GetBottom() const { return m_rel_rect.GetBottom(); }

        void SetWidth(XYDIM width) { m_rel_rect.SetWidth(width); }

        XYDIM GetWidth() const { return m_rel_rect.GetWidth(); }

        void SetHeight(XYDIM height) { m_rel_rect.SetHeight(height); }

        XYDIM GetHeight() const { return m_rel_rect.GetHeight(); }

        void SetSize(XYDIM width, XYDIM height) { m_rel_rect.SetSize(width, height); }

        Size GetSize() const { return m_rel_rect.GetSize(); }

        const Rect& GetRect() const;

        void UpdateAbsRect(XYDIM dx, XYDIM dy);

        const Rect& GetAbsRect() const;

        void Move(XYDIM dx, XYDIM dy) { m_rel_rect.Move(dx, dy); }

        XYDIM GetAbsLeft() const   { return m_abs_rect.GetLeft(); }

        XYDIM GetAbsTop() const    { return m_abs_rect.GetTop();  }

        XYDIM GetAbsRight() const  { return m_abs_rect.GetRight(); }

        XYDIM GetAbsBottom() const { return m_abs_rect.GetBottom(); }

    private:
        Rect m_rel_rect;
        Rect m_abs_rect;
};


#endif  // Apoxi_winRect_hpp


