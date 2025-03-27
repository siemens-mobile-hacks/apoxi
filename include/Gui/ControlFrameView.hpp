/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ControlFrameView_hpp)
#define Apoxi_ControlFrameView_hpp

#include <Gui/View.hpp>
#include <Gui/Rect.hpp>

class LanguageManager;
class Control;

class ControlFrameView : public View {
    public:
        ControlFrameView();

        ControlFrameView(XYDIM left_size, XYDIM top_size, XYDIM right_size, XYDIM bottom_size);

        virtual ~ControlFrameView();

        XYDIM GetLeftSize() const { return m_left_size; }

        XYDIM GetTopSize() const { return m_top_size; }

        XYDIM GetRightSize() const { return m_right_size; }

        XYDIM GetBottomSize() const { return m_bottom_size; }

        virtual void Draw(const Component& component,
                          DeviceContext* dc,
                          const Rect& repaint_rect) const;

        virtual void DrawClientAreaBackground(const Control& control,
                                              DeviceContext* dc,
                                              const Rect& repaint_rect) const;

    protected:
        virtual void DrawControlFrame(const Control& control,  DeviceContext* dc, const Rect& repaint_rect) const = 0;

        void SetLeftSize(XYDIM left_size) { m_left_size = left_size; }

        void SetRightSize(XYDIM right_size) { m_right_size = right_size; }

        void SetTopSize(XYDIM top_size) { m_top_size = top_size; }

        void SetBottomSize(XYDIM bottom_size) { m_bottom_size = bottom_size; }

        void DrawFrameComponents(const Control& control,
                                 DeviceContext* dc,
                                 const Rect& repaint_rect) const;

    private:
        XYDIM m_left_size;
        XYDIM m_top_size;
        XYDIM m_right_size;
        XYDIM m_bottom_size;
};

#endif  // Apoxi_ControlFrameView_hpp


