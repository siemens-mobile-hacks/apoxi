/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_WbmpDecoder_hpp)
#define Apoxi_WbmpDecoder_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include <Auxiliary/BinData.hpp>
#include <Gui/Image.hpp>
#include <Gui/ImageDecoder.hpp>

#define BITMASK_EXT_HEADERS 0x01
#define BITMASK_EXT_FIELD_TYPES 0x06
#define BITMASK_NAME_LENGTH 0x0E
#define BITMASK_VALUE_LENGTH 0xF0
#define BITMASK_HAS_MORE_PARAMS 0x01

class WbmpDecoder : public ImageDecoder {
    typedef ImageDecoder Base;

    public:
        static WbmpDecoder* GetInstance();

        virtual BOOLEAN GetMetaData(Image& image, Image::MetaData* meta_data);

        virtual BOOLEAN BeginDecoding(const Image& image, INT frame_idx = 0);

        UINT32 GetDataIndex() const { return m_data_index; }
        
    private:
        UINT32 m_data_index;

        static WbmpDecoder m_decoder;

        WbmpDecoder();
        BOOLEAN ReadHeader(const BinData& bin_data,
                           UINT32* parse_idx,
                           XYDIM* width = 0,
                           XYDIM* height = 0) const;

        BOOLEAN UInt2Long(const BinData& bin_data, UINT32* parse_idx, INT32* return_val) const; 
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif


