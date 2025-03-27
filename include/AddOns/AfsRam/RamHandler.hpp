/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamHandler_hpp
#define Apoxi_RamHandler_hpp

#include <AddOns/AfsRam/RamTypes.hpp>
#include <AddOns/AfsRam/RamFileNode.hpp>
#include <AddOns/AfsRam/RamFileSystem.hpp>

class RamHandler
{
    public:
        static void Initialize();

        static void Deinitialize();

        static RamHandle Create(const WString &file_name,
                                UINT32 size);

        static RamHandle Find(const WString &file_name);

        static BOOLEAN Read(RamHandle hp,
                            INT32 offset,
                            void HUGE *buffer,
                            UINT32 count,
                            UINT32 &bytes_read);

        static BOOLEAN Write(RamHandle hp,
                             INT32 offset,
                             const void HUGE *buffer,
                             UINT32 count);

        static BOOLEAN Append(RamHandle hp,
                              const void HUGE *buffer,
                              UINT32 count);

        static BOOLEAN Rename(const WString &old_file_name,
                              const WString &new_file_name);

        static BOOLEAN Resize(RamHandle file_handle,
                              UINT32 new_size);

        static BOOLEAN Delete(const WString &file_name);

        static BOOLEAN MakeDir(const WString &dir_name);

        static BOOLEAN RemoveDir(const WString &dir_name);

        static BOOLEAN ChangeDir(const WString &dir_name);

        static BOOLEAN GetCurrentDir(WString &current_dir);

        static BOOLEAN IsCurrentDir(const RamHandle current_dir);

        static BOOLEAN FileExists(const WString &file_name);

        static UINT32 GetFreeSpaceSize();

        static UINT32 GetTotalSpaceSize();

        static UINT32 GetUsedSpaceSize();

        static BOOLEAN GetFileInfo(const WString &file_name,
                                   RamFileInfo *info);

        static BOOLEAN FindFirst(RamHandle *found_file,
                                 const WString &filespec);

        static BOOLEAN FindNext(RamHandle *found_file);

        static void FindDone();

        static BOOLEAN IsDirectory(const WString &dir_name);

        static BOOLEAN GetAttributes(const WString &filename,
                                     UINT16 &attr);

        static BOOLEAN SetAttributes(const WString &filename,
                                     UINT16 attr);

        static RamError GetLastError();

        static BOOLEAN Flush(RamHandle hp);

        static BOOLEAN Truncate(RamHandle hp,
                                UINT32 new_size);

        static BOOLEAN Format(UINT16 block_size = c_ram_storage_default_block_size);

    private:
        // static object which represents the file system
        static RamFileSystem *m_file_system;
        // static object which represents the working directory
        static RamFileNode *m_working_directory;

        // static object which saves the found entries used by FindFirst and FindNext
        static Vector<RamHandle> m_found_files;
        // static object which holds address of the iterator with the next found data
        static Vector<RamHandle>::Iterator m_next_found_file;

        // static object which stores the last occurred error
        static RamError m_last_error;

        static void FindData(const WString &filespec);

        static BOOLEAN Match(const WString &str, const WString &pattern);

        static Pathname GetAbsolutePathname(const WString &path_name);
};

#endif  // Apoxi_RamHandler_hpp


