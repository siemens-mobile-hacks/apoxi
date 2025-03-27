/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgFileWrapper_hpp)
#define Apoxi_SvgFileWrapper_hpp

#include <Auxiliary/RamData.hpp>

#include "SvgIoWrapper.hpp"

class SvgFileWrapper : public SvgIoWrapper
{
    public: 
        SvgFileWrapper(); 
        SvgFileWrapper(UINT8 *p_buffer, UINT32 buffer_length, BOOLEAN release_ramdata = FALSE);
        SvgFileWrapper(BinData *p_bin_data, BOOLEAN release_ramdata = FALSE);
        virtual ~SvgFileWrapper(); 
        virtual UINT32 Read(UINT8 *p_dst_buffer, UINT32 bytes_wanted); 

    private: 
        BinData *m_bin_data; 
        UINT32 m_buffer_offset; 
    BOOLEAN m_realease_ramdata;
}; 
#endif

