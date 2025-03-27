/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_CTPositionIndicatorView_hpp)
#define Apoxi_CTPositionIndicatorView_hpp

#include <Gui/PositionIndicator.hpp>

/*  ------------------------------------------------------------------------
    DefaultPositionIndicatorView
    ------------------------------------------------------------------------*/
class CTPositionIndicatorView : public PositionIndicatorView {
    typedef PositionIndicatorView Base;

    public:
        CTPositionIndicatorView();
        explicit CTPositionIndicatorView(XYDIM size);
        virtual ~CTPositionIndicatorView() {}
        
        void SetPosIndSize(XYDIM size);

    protected:
        virtual void DrawPositionIndicator(const PositionIndicator& pos_ind, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_CTPositionIndicatorView_hpp


