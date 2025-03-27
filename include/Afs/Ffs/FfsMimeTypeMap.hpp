/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(FfsMimeTypeMap_hpp)
#define FfsMimeTypeMap_hpp

#if defined(APOXI_COMPAT_1_13_0)
    #include <Afs/Ffs/FfsHandler.hpp>
#endif

#include <Auxiliary/MimeTypeTable.hpp>
#include <Afs/Ffs/FfsTypes.hpp>

struct FfsMimeTypeMapEntry {
    MimeType    mime_type;
    FfsFileType ffs_type;
};

class FfsMimeTypeMap {
    public:
        inline static   MimeType    GetMimeTypeByFileType(FfsFileType file_type){
            UINT8 idx = 0;
            return GetMimeTypeByFileType(file_type, idx);
        }
        static  const CHAR* GetMimeStrByFileType(FfsFileType file_type);
        static  FfsFileType GetFileTypeByExt(const CHAR *extension);

        static  FfsFileType GetFileTypeByMimeType(MimeType mime_type, UINT8 offset = 0);
        static  FfsFileType GetFileTypeByMimeStr(const CHAR *mime_str);
        static  const CHAR* GetExtByFileType(FfsFileType file_type);
        static  INT         IsTextByFileType(FfsFileType file_type);
        static  INT         IsBinaryByFileType(FfsFileType file_type);

    private:
        FfsMimeTypeMap();
        FfsMimeTypeMap(const FfsMimeTypeMap&);
        ~FfsMimeTypeMap();
        FfsMimeTypeMap& operator=(const FfsMimeTypeMap&);
        
        static  MimeType    GetMimeTypeByFileType(FfsFileType file_type, UINT8 &offset);

        static const UINT                   m_map_table_entries;
        static const UINT                   m_max_index;
        static const FfsMimeTypeMapEntry    m_map_table[];
};

#endif  // FfsMimeTypeMap_hpp


