/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ClientDc_hpp)
#define Apoxi_ClientDc_hpp

#include <Gui/ControlDc.hpp>


class Control;

class ClientDc : public ControlDc {
    typedef ControlDc Base;

    public:
        ClientDc(); 
        ClientDc(Control* control);
        ClientDc(VirtualDisplay* display);
        virtual void AdjustBoundingRect();
};  // ClientDc

#endif  // Apoxi_ClientDc_hpp

