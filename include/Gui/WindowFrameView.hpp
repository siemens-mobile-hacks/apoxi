/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_WindowFrameView_hpp)
#define Apoxi_WindowFrameView_hpp

#include <Gui/ControlFrameView.hpp>

class Window;

class WindowFrameView : public ControlFrameView {
    typedef ControlFrameView Base;

    public:
        WindowFrameView();
        WindowFrameView(XYDIM left_size,
                        XYDIM top_size,
                        XYDIM right_size,
                        XYDIM bottom_size,
                        XYDIM title_height,
                        XYDIM softkey_bar_height);
        virtual ~WindowFrameView();

        XYDIM GetTitleHeight() const { return m_title_height; }

        const TextFormat& GetTitleTextFormat() const { return m_title_text_format; }

        virtual void Draw(const Component& component, DeviceContext* dc, const Rect& repaint_rect) const;

        BOOLEAN IsActive(const Control& control) const;

        XYDIM GetSoftkeyBarHeight() const { return m_softkey_bar_height; }

    protected:
        virtual void DrawWindowExtensions(const Window& window,
                                          DeviceContext* dc,
                                          const Rect& repaint_rect) const = 0;

        void SetSoftkeyBarHeight(XYDIM height) { m_softkey_bar_height = height; }

        void SetTitleHeight(XYDIM height) { m_title_height = height; }

        void SetTitleTextFormat(const TextFormat& text_format) { m_title_text_format = text_format; }
                
    private:
        XYDIM m_title_height;
        XYDIM m_softkey_bar_height;
        TextFormat m_title_text_format;
};

#endif  // Apoxi_WindowFrameView_hpp


