/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_PppFrame_hpp)
#define Asc_PppFrame_hpp

#include <stack/stack.h>                 // necessary for type "T_AUTH_PPP_FRAME"
#include <Auxiliary/ByteBuffer.hpp>

class PppFrame : public ByteBuffer {

    typedef ByteBuffer Base;

    public:
        PppFrame()
            : Base() {  /* nothing to do here */ }  

        PppFrame(const T_AUTH_PPP_FRAME & ppp_frame)
            : Base((UINT8*) &ppp_frame, sizeof(T_AUTH_PPP_FRAME)) { /* nothing to do here */ }      

        PppFrame(const T_AUTH_PPP_FRAME * ppp_frame)
            : Base((UINT8*) ppp_frame, sizeof(T_AUTH_PPP_FRAME)) {  /* nothing to do here */ }

        operator T_AUTH_PPP_FRAME () const;

        PppFrame & operator = (const T_AUTH_PPP_FRAME & auth_ppp_frame);
};

#endif


