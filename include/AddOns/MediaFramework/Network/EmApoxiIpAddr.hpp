/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiIpAddr_hpp)
#define EmApoxiIpAddr_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"

class IpAddr;

class EmApoxiIpAddr
{

    public:

        EmApoxiIpAddr(EmApoxiUINT32 addr = 0,
            EmApoxiBOOLEAN convert_from_native = EmApoxiFALSE);

        ~EmApoxiIpAddr();

        EmApoxiBOOLEAN InitFrom(const char *str, EmApoxiINT len=-1);

        EmApoxiUINT32 GetAddr() const;

        IpAddr *GetIpAddr() const {return mp_ip_addr;}


    protected:


    private:
        IpAddr *mp_ip_addr;
        
}; // EmApoxiIpAddr

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiIpAddr_hpp

