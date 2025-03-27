/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ResourceReader_hpp)
#define Apoxi_ResourceReader_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/ChildBinData.hpp>
#include <Auxiliary/BufferedData.hpp>

class BinData;
class File;
class Path;

typedef NiSharedPtr<File> FilePtr;

class ResourceReader {  

    public:

        enum DataType {
            BinaryData = 0,
            GuiCtdData,
            ThemeCtdData,
            ObjectPoolData
        };

        ResourceReader(const FilePtr& file);
        
        ResourceReader(const Path& file_path);

        ~ResourceReader();

        ChildBinData* GetData(UINT16 resource_id, DataType* type = 0) const;

        ChildBinData* GetDataByIndex(UINT16 idx, DataType* type = 0) const;

        BOOLEAN Contains(UINT16 resource_id) const;

        BOOLEAN GetDataType(UINT16 resource_id, ResourceReader::DataType& type) const;
        
        BOOLEAN GetDataInfoByIndex(UINT16 idx, UINT16& id, ResourceReader::DataType& type) const;

        INT GetFileVersion() const;

        BOOLEAN HasResourceFile() const { return m_has_resource_file; }

        UINT16 GetEntryCount() const { return m_toccount; }
            

    private:
        BOOLEAN ReadToc();

        BOOLEAN GetIndex(UINT16 resource_id, UINT16& idx) const;

        struct TocEntry {
            UINT16 m_id;
            UINT32 m_offset;
            UINT32 m_length;
            DataType m_type;
        };

        BinData* m_bindata;
        UINT8 m_file_version;
        UINT16 m_toccount;
        TocEntry* m_tocentries;
        BOOLEAN m_has_resource_file;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_ResourceReader_hpp

