/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgIOWrapper_hpp)
#define Apoxi_SvgIOWrapper_hpp

class SvgIoWrapper 
{
    public: 
        virtual ~SvgIoWrapper(); 

        virtual UINT32 Read(UINT8 *p_dst_buffer, UINT32 bytes_wanted) = 0; 
}; 
#endif

