/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_CTProgressBarView_hpp)
#define Apoxi_CTProgressBarView_hpp

#include <Gui/ProgressBar.hpp>

/*  ------------------------------------------------------------------------
    CTProgressBarView
    ------------------------------------------------------------------------*/
class CTProgressBarView : public ProgressBarView {
    typedef ProgressBarView Base;

    public:
        CTProgressBarView();
        explicit CTProgressBarView(XYDIM default_height);
        virtual void Update(const Theme& theme);
        virtual ~CTProgressBarView() {}
        
        void SetDefaultProgressBarHeight(XYDIM height);

    protected:
        virtual void DrawProgressBar(const ProgressBar& progress_bar, DeviceContext* dc, const Rect& repaint_rect) const;

    private:
        static WString m_percent_str;
        mutable XYDIM m_throbber;
        
};

#endif  // Apoxi_CTProgressBarView_hpp


