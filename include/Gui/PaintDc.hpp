/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PaintDc_hpp)
#define Apoxi_PaintDc_hpp

#include <Gui/DeviceContext.hpp>

class PaintDc : public DeviceContext {
    typedef DeviceContext Base;

    public:
        PaintDc(DeviceContext* dc); 
        
        virtual ~PaintDc();
};

#endif  // Apoxi_PaintDc_hpp


