/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CTResourceParser_hpp)
#define Apoxi_CTResourceParser_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include "CTResourcePack.hpp"

class CTResourceParser {
    public:

        CTResourceParser(BinData* bin_data, const WString& resource_uri);

        ~CTResourceParser();

        void Release();

        WString GetResourceUri() const { return m_resource_uri; }

        BOOLEAN GetPropertyValue(CTResourcePack::ParseType parse_type, void* value);

        UINT32 GetPos() const { return m_pos; }

        void SetPos(UINT32 pos) { m_pos = pos; }

        BOOLEAN Skip(UINT32 bytes);

        UINT32 ReadCompressedLength();

        BOOLEAN ReadBoolean();

        WString ReadWString();

        UINT8 ReadUInt8();
        UINT16 ReadUInt16();
        UINT32 ReadUInt32();

        INT8 ReadInt8();
        INT16 ReadInt16();
        INT32 ReadInt32();

    private:
        WString m_resource_uri;
        BinData* m_bin_data;
        UINT32 m_pos;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_CTResourceParser_hpp


