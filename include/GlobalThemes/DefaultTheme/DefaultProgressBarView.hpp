/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultProgressBarView_hpp)
#define Apoxi_DefaultProgressBarView_hpp

#include <Gui/ProgressBar.hpp>

class DefaultProgressBarView : public ProgressBarView {
    typedef ProgressBarView Base;

    public:
        DefaultProgressBarView();
        explicit DefaultProgressBarView(XYDIM default_height);
        virtual void Update(const Theme& theme);
        virtual ~DefaultProgressBarView() {}

    protected:
        virtual void DrawProgressBar(const ProgressBar& progress_bar, DeviceContext* dc, const Rect& repaint_rect) const;

    private:
        static WString m_percent_str;
        
};

#endif  // Apoxi_DefaultProgressBarView_hpp


