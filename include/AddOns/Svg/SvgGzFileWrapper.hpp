/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgGZFileWrapper_hpp)
#define Apoxi_SvgGZFileWrapper_hpp

#include <AddOns/zlib/zutil.h>

#include "SvgIoWrapper.hpp"


#define SVG_GZ_INPUT_BUFFER_SIZE 1024


class BinData;

class SvgGzFileWrapper : public SvgIoWrapper 
{
    public: 
        SvgGzFileWrapper(); 
        SvgGzFileWrapper(UINT8 *p_buffer, UINT32 buffer_length, BOOLEAN *p_success, BOOLEAN release_ramdata = FALSE);
        SvgGzFileWrapper(BinData *p_bin_data, BOOLEAN *p_success, BOOLEAN release_ramdata = FALSE); 
        virtual ~SvgGzFileWrapper(); 
        virtual UINT32 Read(UINT8 *p_dst_buffer, UINT32 bytes_wanted); 
        static BOOLEAN HasValidGzHeader(UINT8 *p_buffer, INT32 buffer_length); 
        static BOOLEAN HasValidGzHeader(BinData *p_bin_data); 

    private: 
        BOOLEAN InitializeGzStream(); 
        
        BinData *m_bin_data; 
        UINT32 m_buffer_offset; 
        BOOLEAN m_release_ramdata; 
        z_stream m_z_stream; 
        void *m_input_buffer; 

        // static callbacks that zlib needs
        static void* Callback_Malloc(void *p_userdata, unsigned int num, unsigned int size);
        static void  Callback_Free(void *p_userdata, void *p_memory); 
}; 
#endif

