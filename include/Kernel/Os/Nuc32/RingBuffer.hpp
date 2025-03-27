/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_RingBuffer_hpp)
#define Apoxi_RingBuffer_hpp

#include <Kernel/Types.hpp>

CHAR* get_ringbuffer(void);
void put_ringbuffer(CHAR* c);

#endif


