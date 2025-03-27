/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultWindowFrameView_hpp)
#define Apoxi_DefaultWindowFrameView_hpp

#include <Gui/WindowFrameView.hpp>

/*  ------------------------------------------------------------------------
    DefaultWindowFrameView
    ------------------------------------------------------------------------ */
class DefaultWindowFrameView : public WindowFrameView {
    typedef WindowFrameView Base;

    public:
        DefaultWindowFrameView();
        DefaultWindowFrameView(XYDIM left_size,
                               XYDIM top_size,
                               XYDIM right_size,
                               XYDIM bottom_size,
                               XYDIM title_height,
                               XYDIM softkey_bar_height);
        
        virtual ~DefaultWindowFrameView();
        
        virtual void Update(const Theme &theme);
        

    protected:
        virtual void DrawControlFrame(const Control &control, DeviceContext *dc, const Rect &repaint_rect) const;

        virtual void DrawWindowExtensions(const Window &window,  DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_DefaultWindowFrameView_hpp


