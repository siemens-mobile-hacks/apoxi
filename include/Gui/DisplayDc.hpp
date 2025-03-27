/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DisplayDc_hpp)
#define Apoxi_DisplayDc_hpp

#include <Gui/DeviceContext.hpp>

class Control;

class DisplayDc : public DeviceContext {
    typedef DeviceContext Base;

    public:
        DisplayDc();
    
        DisplayDc(Display* display);

        virtual ~DisplayDc();

        void Init(Display* display);

        virtual void AdjustBoundingRect();  
};  // DisplayDc

#endif  // Apoxi_DisplayDc_hpp

