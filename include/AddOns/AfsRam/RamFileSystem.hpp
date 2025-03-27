/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamFileSystem_hpp
#define Apoxi_RamFileSystem_hpp

#include <AddOns/AfsRam/RamFileNode.hpp>
#include <AddOns/AfsRam/RamStorageMapper.hpp>
#include <AddOns/AfsRam/RamTypes.hpp>

class RamFileSystem
{
    public:
        static RamFileSystem* GetInstance() { return &m_instance; }

        ~RamFileSystem();

        RamHandle GetRootNode();

        RamHandle FindNode(const Pathname &pathname, UINT16 attributes);

        RamHandle InsertNode(RamFileObj *file_obj);

        BOOLEAN DeleteNode(const Pathname &pathname, UINT16 attributes);

        BOOLEAN AssignDriveLetter(UINT8 drive_letter);

        UINT8 GetDriveLetter() const;

        BOOLEAN FormatFileSystem(UINT16 block_size = c_ram_storage_default_block_size);

        UINT32 GetSpaceSize() const;

        UINT32 GetFreeSpaceSize() const;

        UINT32 GetUsedSpaceSize() const;

        RamError GetLastError() const;

        WString GetTree(RamHandle node, UINT level = 0) const;

    private:
        RamFileSystem();

        void InitFileSystem();

        static void Deinitialize();

        RamHandle FindNodeHelper(RamHandle parent, const Pathname &pathname, UINT16 attributes, UINT8 level);

        RamHandle InsertNodeHelper(RamHandle parent, RamFileObj *file_obj);

        // represents the instance of the class
        static RamFileSystem m_instance;
        // represents the root directory of the file system
        RamFileNode m_root;
        // represents the storage mapper
        RamStorageMapper *m_storage_mapper;
        // represents the drive letter
        UINT8 m_drive_letter;
        // represents the last occurred error
        mutable RamError m_last_error;
};

#endif  // Apoxi_RamFileSystem_hpp


