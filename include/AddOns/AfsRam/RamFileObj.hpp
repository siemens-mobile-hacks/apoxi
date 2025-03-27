/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamFileObj_hpp
#define Apoxi_RamFileObj_hpp

#include <AddOns/AfsRam/RamTypes.hpp>
#include <Auxiliary/Vector.hpp>
#include <Afs/Rfs/Path.hpp>

class Pathname;

class RamFileObj
{
public:
    RamFileObj(const WString &pathname,
               UINT16 attributes = RamFileAttrNormal,
               UINT32 size = 0);
    RamFileObj(const Pathname &pathname,
               UINT16 attributes = RamFileAttrNormal,
               UINT32 size = 0);
    RamFileObj(const RamFileObj &another_file_obj);
    ~RamFileObj();

    BOOLEAN Reset(UINT32 size);
    BOOLEAN DeleteDataBlocks();
    BOOLEAN Resize(UINT32 new_size);

    BOOLEAN SetAttributes(UINT16 attributes);
    UINT16 GetAttributes() const;
    BOOLEAN SetReadOnly(BOOLEAN is_read_only);
    BOOLEAN IsReadOnly() const;
    BOOLEAN SetHidden(BOOLEAN is_hidden);
    BOOLEAN IsHidden() const;
    BOOLEAN SetSystem(BOOLEAN is_system);
    BOOLEAN IsSystem() const;
    BOOLEAN SetVolume(BOOLEAN is_volume);
    BOOLEAN IsVolume() const;
    BOOLEAN SetDirectory(BOOLEAN is_directory);
    BOOLEAN IsDirectory() const;
    BOOLEAN SetArchive(BOOLEAN is_archive);
    BOOLEAN IsArchive() const;

    void SetPathname(const Pathname &pathname);
    const Pathname& GetPathname() const;
    UINT32 GetSize() const;
    UINT32 GetAllocatedSize() const;

    const WString GetName() const; // e.g. "abc.txt"
    const WString GetNativeFilePathname() const; // e.g. "/mydir/abc.txt"
    const WString GetNativeDirectoryPathname() const; // e.g. "/mydir"

    // TODO implement file info method
    //RamFileInfo* GetFileInfo() const;
    BOOLEAN GetCreationDate(Date &date) const; // gives date of creation
    BOOLEAN GetModificationDate(Date &date) const; // gives date of last modification
    BOOLEAN GetAccessDate(Date &date) const; // gives date of last access

    BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 count, UINT32 &bytes_read);
    BOOLEAN Write(UINT32 offset, const void HUGE *buffer, UINT32 count);
    BOOLEAN Append(const void HUGE *buffer, UINT32 count);

    RamError GetLastError() const;
    UINT32 GetBlockCount() const;

private:
    Vector<RamBlockData> m_blocks; /* List of all data blocks in RAM for this file. */

    UINT16 m_file_attributes; /* Attributes of the file, e.g. read only, directory, ... */

    Date m_creation_date; /* Date of creation */
    Date m_modification_date; /* Date of last modification */
    Date m_access_date; /* Date of last access */

    Path m_path; /* Path of the file */

    mutable RamError m_last_error;

    void InitFileObj(const Pathname &pathname,
               UINT16 attributes = RamFileAttrNormal,
               UINT32 size = 0); /* initializes components in constructor */
    UINT32 AllocateStorage(UINT32 size); /* allocates blocks in the storage */

    BOOLEAN CopyDataBlocks(Vector<RamBlockData> &dest_vector, const Vector<RamBlockData> &src_vector) const;
    BOOLEAN DeleteDataBlocks(Vector<RamBlockData> &vect);

    BOOLEAN TruncateSize(UINT32 new_size);
    BOOLEAN ExtendSize(UINT32 new_size);

    UINT32 InternalWrite(UINT32 byte_index, const void HUGE *buffer, UINT32 count); // Writes a number of bytes to a specific place in file.
    UINT32 InternalRead(UINT32 byte_index, void HUGE *buffer, UINT32 count); // Reads a number of bytes from a specific place in file.
};

#endif  // Apoxi_RamFileObj_hpp


