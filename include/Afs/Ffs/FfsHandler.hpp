/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_FfsHandler_hpp)
#define Adc_FfsHandler_hpp

#include <Afs/Ffs/FfsTypes.hpp>

class FfsHandler
{
    public:
        static FfsError Open(FfsFileId id, FfsHandle *hp, FfsOpenMode mode,
                        FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Open(const CHAR *filename, FfsHandle *hp, FfsOpenMode mode,
                        FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Close(FfsFileId id, FfsHandle h, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Close(const CHAR *filename, FfsHandle h, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Read(FfsFileId id, FfsHandle h, UINT32 offset, void FFS_HUGE *dst,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi, 
                        void (callback_func)(FfsError result) = NULL);
        static FfsError Read(const CHAR *filename, FfsHandle h, UINT32 offset, void FFS_HUGE *dst,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi, 
                        void (callback_func)(FfsError result) = NULL);

        static FfsError Create(FfsFileId id, FfsHandle *hp, FfsFileType type,
                        UINT32 size, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Create(const CHAR *filename, FfsHandle *hp, FfsFileType type,
                        UINT32 size, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Write(FfsFileId id, FfsHandle h, const void FFS_HUGE *src, UINT32 offset,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi,
                        void (callback_func)(FfsError result) = NULL);
        static FfsError Write(const CHAR *filename, FfsHandle h, const void FFS_HUGE *src, UINT32 offset,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi, 
                        void (callback_func)(FfsError result) = NULL);

        static FfsError Modify(FfsFileId id, FfsHandle h, const void FFS_HUGE *src, UINT32 offset,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Modify(const CHAR *filename, FfsHandle h, const void FFS_HUGE *src, UINT32 offset,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Delete(FfsFileId id, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Delete(const CHAR *filename, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError DeleteDir(const CHAR *dir_name, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError MakeDir(const CHAR *dir_name, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError ChangeDir(const CHAR *dir_name, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError GetCurrentDir(CHAR *current_dir, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Append(FfsFileId id, FfsHandle h, const void FFS_HUGE *src,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Append(const CHAR *filename, FfsHandle h, const void FFS_HUGE *src,
                        UINT32 no_bytes, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Truncate(FfsFileId id, UINT32 new_size, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Truncate(const CHAR *filename, UINT32 new_size, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Copy(FfsFileId id, FfsFileId dst_id, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Copy(const CHAR *filename, const CHAR *dst_filename, FfsUserType user_id = FfsUserTypeMmi);

        static BOOLEAN IsDirectory(const CHAR *pathname, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError Rename(FfsFileId id, FfsFileId new_id,
                        FfsFileType new_type, FfsUserType user_id = FfsUserTypeMmi);
        static FfsError Rename(const CHAR *filename, const CHAR *new_filename,
                        FfsFileType new_type, FfsUserType user_id = FfsUserTypeMmi);

        static BOOLEAN FileExist(FfsFileId id, FfsUserType user_id = FfsUserTypeMmi);
        static BOOLEAN FileExist(const CHAR *filename, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError GetFileInfo(FfsFileId id, FfsFileInfo *info,
                                FfsUserType user_id = FfsUserTypeMmi);
        static FfsError GetFileInfo(const CHAR *filename, FfsFileInfo *info,
                                FfsUserType user_id = FfsUserTypeMmi);

        static FfsError GetFileName(CHAR *filename, FfsFileId id, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError GetFileId(FfsFileId *id, const CHAR *filename, FfsUserType user_id = FfsUserTypeMmi);

        static FfsError SetDrmAttrib(FfsFileId id, const FfsDrmAttrib &attrib,
                                FfsUserType user_id = FfsUserTypeMmi);
        static FfsError SetDrmAttrib(const CHAR *filename, const FfsDrmAttrib &attrib,
                                FfsUserType user_id = FfsUserTypeMmi);

        static FfsError GetDrmAttrib(FfsFileId id, FfsDrmAttrib &attrib,
                                FfsUserType user_id = FfsUserTypeMmi);
        static FfsError GetDrmAttrib(const CHAR *filename, FfsDrmAttrib &attrib,
                                FfsUserType user_id = FfsUserTypeMmi);

        static BOOLEAN FindFirst(FfsFileId *id, FfsFileType type);
        static BOOLEAN FindFirst(CHAR *filename, const CHAR *name_spec, FfsFileType type,
                                FfsUserType user_id = FfsUserTypeMmi);

        static BOOLEAN FFindFirst(CHAR *filename, const CHAR *name_spec, FfsFileType type,
                                FfsRefType *ref_type, FfsUserType user_id = FfsUserTypeMmi);

        static BOOLEAN FFindNext(CHAR *filename, const CHAR *name_spec, FfsFileType type, FfsRefType *ref_type, FfsUserType user_id = FfsUserTypeMmi);

        static BOOLEAN FindNext(FfsFileId last_id, FfsFileId *id, FfsFileType type);
        static BOOLEAN FindNext(CHAR *filename, const CHAR *name_spec, FfsFileType type,
                                FfsUserType user_id = FfsUserTypeMmi);

        static FfsFileId GetNextFreeId();

        static UINT16 GetNofFiles();

        static UINT16 GetNofFilesByType(FfsFileType type);

        static UINT32 GetFreeFfsSpace();

        static UINT32 GetFreeSpaceByType(FfsFileType type);

        static UINT32 GetFreeSpaceInGlobalPool();

        static UINT32 GetTotalSpace();

        static UINT32 GetUsedSpace();

        static UINT32 GetUsedSpaceByType(FfsFileType type);

        static UINT32 GetReservedSpace(FfsFileType type);

        static UINT32 GetReservedSpace();

        static UINT32 GetUsedSpaceInGlobalPool();

        static UINT32 CalcFileMemOvrhd(UINT32 size, BOOLEAN use_name);

    private:
#if defined(APOXI_FFS_USER_MAPPING)
        static FfsUserType FetchUserType(FfsUserType user_type);
#endif

};

#endif  // Adc_FfsHandler_hpp


