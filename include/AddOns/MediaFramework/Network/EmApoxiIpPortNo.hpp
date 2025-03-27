/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiIpPortNo_hpp)
#define EmApoxiIpPortNo_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"

class IpPortNo;

class EmApoxiIpPortNo
{

    public:

        EmApoxiIpPortNo(EmApoxiUINT16 port = 0, 
            EmApoxiBOOLEAN convert_from_native = EmApoxiFALSE);

        ~EmApoxiIpPortNo();

        IpPortNo *GetIpPortNo() const {return mp_ip_port_no;}


    protected:


    private:
        IpPortNo *mp_ip_port_no;
        
}; // EmApoxiIpPortNo

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiIpPortNo_hpp

