/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ResourceParser_hpp)
#define Apoxi_ResourceParser_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifndef APOXI_ARAGON_MAX_BUFFER_SIZE
    // maximum length is calculated as 9 * 256 (9 items in iconset, each path can be 256 chars long)
    #define APOXI_ARAGON_MAX_BUFFER_SIZE 2340
#endif

#include <Kernel/Types.hpp>
#include <Auxiliary/BinData.hpp>
#include <Gui/GuiObjectDescr.hpp>
#include <Config/GuiObjectFactory.hpp>

class ResourceParser {
    public:

        ResourceParser(BinData* bin_data, const WString& resource_uri);     

        ~ResourceParser();

        void Release();

        WString GetResourceUri() const { return m_resource_uri; }

        INT GetFileVersion() const { return m_file_version; }

        BOOLEAN GetPropertyValue(const GuiObjectFactory::PropertyId property_id, void* value);

        UINT32 GetPos() const { return m_pos; }

        void SetPos(UINT32 pos) { m_pos = pos; }

        BOOLEAN Skip(UINT32 bytes);

        GuiObjectDescr ReadGuiObjectDescr();

        UINT32 ReadCompressedLength();

        BOOLEAN ReadBoolean();

        String ReadString();
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
        INT m_file_version;

        static CHAR m_buffer[APOXI_ARAGON_MAX_BUFFER_SIZE];
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_ResourceParser_hpp

