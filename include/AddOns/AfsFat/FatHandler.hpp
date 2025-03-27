/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_FatHandler_hpp
#define Apoxi_FatHandler_hpp

#include <AddOns/AfsFat/FatTypes.hpp>

class FatHandler
{
    public:
        static FatHandle Create(const CHAR *file_name, UINT32 size);

        static FatHandle Open(const CHAR *file_name, FatOpenMode mode);

        static BOOLEAN Close(FatHandle hp);

        static BOOLEAN Read(FatHandle hp, UINT8 HUGE *buffer, UINT32 count);

        static BOOLEAN ReadStreaming(FatHandle hp, UINT8 HUGE *buffer, 
                            UINT32 count, UINT32 bytes_read, void *client_arg);
        
        static BOOLEAN ReadStreamingAsync(FatHandle hp, UINT8 HUGE *buffer, 
                            UINT32 count, 
                            void (callback_func)(INT16 result, void *client_arg), 
                            void *client_arg);

        static BOOLEAN Write(FatHandle hp, const UINT8 HUGE *buffer, 
                            UINT32 count);
        
        static BOOLEAN WriteStreaming(FatHandle hp, const UINT8 HUGE *buffer, 
                            UINT32 count, void *client_arg);

        static BOOLEAN WriteStreamingAsync(FatHandle hp, 
                            const UINT8 HUGE *buffer, UINT32 count, 
                            void (callback_func)(INT16 result, void *client_arg), 
                            void *client_arg);


        static UINT32 Seek(FatHandle hp, INT32 offset, INT16 origin,
            INT16 &err_flag);

        static BOOLEAN Append(FatHandle hp, const UINT8 HUGE *buffer,
            UINT32 count);

        static BOOLEAN Rename(const CHAR *current_file_name,
                              const CHAR *new_file_name);

        static BOOLEAN Delete(const CHAR *file_name);

        static BOOLEAN MakeDir(const CHAR *dir_name);

        static BOOLEAN RemoveDir(const CHAR *dir_name);

        static BOOLEAN ChangeDir(const CHAR *dir_name);

        static BOOLEAN GetCurrentDir(const CHAR *drive_letter,
            CHAR *current_dir);

        static BOOLEAN FileExists(const CHAR *file_name);

        static UINT32 GetFreeSpaceSize();

        static BOOLEAN GetFileInfo(const CHAR *file_name, FatFileInfo &info);

        static BOOLEAN FindFirst(FatFindData &find_data, const CHAR *filespec);

        static BOOLEAN FindNext(FatFindData &find_data);

        static void FindDone(FatFindData &find_data);

        static BOOLEAN IsDirectory(const CHAR *pathname);

        static BOOLEAN GetAttributes(const CHAR *filename, UINT16 &attr);

        static BOOLEAN SetAttributes(const CHAR *filename, UINT16 attr);

        static FatError GetLastError();

        static BOOLEAN Flush(FatHandle hp);

        static BOOLEAN Truncate(FatHandle hp, UINT32 new_size);

        static BOOLEAN DiskOpen(FsDeviceType device);
        static BOOLEAN DiskClose(FsDeviceType device);
        static void DiskAbort(FsDeviceType device);
        static BOOLEAN DiskFormat(FsDeviceType device, BOOLEAN quick);
        static BOOLEAN DiskInfo(FsDeviceType device, BOOLEAN &mounted,
            UINT8 &nof_partitions);
        static BOOLEAN DiskAssignDriveLetter(FsDeviceType device,
            CHAR drive_letter);
        static BOOLEAN DiskSetDefaultDevice(FsDeviceType device);
        static BOOLEAN DiskFlush(FsDeviceType device);
        static UINT16 DiskGetLastDeviceError(FsDeviceType device);
};

#endif  // Apoxi_FatHandler_hpp

