/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamTypes_hpp
#define Apoxi_RamTypes_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/Date.hpp>

#ifndef APOXI_RTOS_WIN32
    #include <stack/driver.h>
#endif

// defines range for DBG_OUT
#define DBG_OUT_RANGE_AFSRAM_ALWAYS     35600
#define DBG_OUT_RANGE_AFSRAM_SUCCESS    35601
#define DBG_OUT_RANGE_AFSRAM_ERROR      35602
#define DBG_OUT_RANGE_AFSRAM_UNITTEST   35603

#if !defined APOXI_RAM_STORAGE_DEFAULT_BLOCK_SIZE
    #define APOXI_RAM_STORAGE_DEFAULT_BLOCK_SIZE 0x0400 // 1 KB
#endif

// used by RamStorageMapper
const UINT16 c_ram_storage_default_block_size = APOXI_RAM_STORAGE_DEFAULT_BLOCK_SIZE;

enum RamError {
// FS error codes:
    RamErrorSuccess                 = 0,
    RamErrorOperationNotPossible    = 3,

/* File system errno values */
    RamErrorNotExist                = 2,  /* File not found or path to file not found. */
    RamErrorBadFileDescriptor       = 9,  /* Invalid file descriptor. */
    RamErrorFileAlreadyExist        = 17, /* Exclusive access requested but file already exists. */
    RamErrorAccessDenied            = 13, /* Attempt to open a read only file or a special directory. */
    RamErrorNegativeFilePointer     = 22, /* Seek to negative file pointer attempted. */
    RamErrorNoSpace                 = 28, /* Write failed. Presumably because of no space. */
    RamErrorShare                   = 30  /* Open failed due to sharing. */
};

/* Open file modes */
enum RamOpenMode {
    RamOpenModeRead         = 0x0000200,
    RamOpenModeWrite        = 0x0000400
};

/* File info type */
struct RamFileInfo {
    UINT32          st_size;        /* file size, in bytes */
    INT32           st_blksize;     /* optimal block size for I/O (cluster size) */
    INT32           st_blocks;      /* blocks allocated for file */
    Date            st_atime;       /* last access (all times are the same) */
    Date            st_mtime;       /* last modification */
    Date            st_ctime;       /* last file status change */
    UINT16          fattribute;     /* file attributes - DOS attributes
                                       (non standard but useful) */
    UINT16          padding;
};

enum RamFileAttribute {
    RamFileAttrRdOnly       = 0x01,
    RamFileAttrHidden       = 0x02,
    RamFileAttrSystem       = 0x04,
    RamFileAttrVolume       = 0x08,
    RamFileAttrDirectory    = 0x10,
    RamFileAttrArchive      = 0x20,
    RamFileAttrNormal       = 0x40,
    RamFileAttrAll          = 0xFF
};

/*
    Defines a structure which represents a certain block index and the number of used bytes.

    e.g. block_size = 16;
    [x|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x]
    byte_count = 0

    [a|x|x|x|x|x|x|x|x|x|x|x|x|x|x|x]
    byte_count = 1

    [a|b|c|d|e|x|x|x|x|x|x|x|x|x|x|x]
    byte_count = 5

    [a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p]
    byte_count = 16
*/
struct RamBlockData {
    UINT32 block_index; // index of block in ram storage
    UINT32 used_bytes;  // number of bytes used in this block
};

#endif  // Apoxi_RamTypes_hpp


