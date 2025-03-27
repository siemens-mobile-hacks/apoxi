/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FatTypes_hpp)
#define Apoxi_FatTypes_hpp

#if !defined(APOXI_LIB_ADDON_AFSFAT)
    #error The FAT filesystem (FAT) add-on is not activated properly - please enable feature AFSFAT!
#elif defined(APOXI_RTOS_WIN32)
    // Host simulator for FAT devices.
    #include <AddOns/AfsFat/FatSim.hpp>
#else
    #include <stack/driver.h>
#endif

#include <Kernel/Types.hpp>

const UINT c_max_fat_filename_len = FS_MAXPATH;
const UINT c_max_fat_max_no_open_files = FS_MAX_NO_OPEN_FILES;

typedef fs_fd_type FatHandle;

// FS error codes:
enum FatError {
    FatErrorFailure                 = FS_FAILURE,
    FatErrorSuccess                 = FS_SUCCESS,
    FatErrorOperationNotPossible    = FS_ERR_OPERATION_NOT_POSSIBLE,
    FatErrorUserIdError             = FS_ERR_USER_ID_ERROR,

    /* Arguments to critical_error_handler() */
    FatErrorBadFormat               = FS_ERR_BAD_FORMAT,
    FatErrorNoCard                  = FS_ERR_NO_MEDIA,
    FatErrorBadCard                 = FS_ERR_BAD_MEDIA,
    FatChangedCard                  = FS_ERR_MEDIA_CHANGED,
    FatErrorCardFailure             = FS_ERR_MEDIA_FAILURE,
    FatErrorIdError                 = FS_ERR_ID_ERROR,
    FatErrorEccError                = FS_ERR_ECC_ERROR,

    /* Filesystem Errno values */
    FatErrorNotExist                = FS_ERR_NOENT, /* File not found or path to file not found */
    FatErrorBadFileDescriptor       = FS_ERR_BADF,  /* Invalid file descriptor */
    FatErrorAccessDenied            = FS_ERR_ACCES, /* Attempt to open a read only file or a special (directory) */
    FatErrorFileAlreadyExist        = FS_ERR_EXIST, /* Exclusive access requested but file already exists. */
    FatErrorUnknown                 = FS_ERR_FAULT, /* Unknown error. */
    FatErrorIO                      = FS_ERR_IO,    /* I/O error. */
    FatErrorNegativeFilePointer     = FS_ERR_INVAL, /* Seek to negative file pointer attempted. */
    FatErrorTooManyFileOpen         = FS_ERR_MFILE, /* No file descriptors available (too many files open) */
    FatErrorNoSpace                 = FS_ERR_NOSPC, /* Write failed. Presumably because of no space */
    FatErrorShare                   = FS_ERR_SHARE, /* Open failed do to sharing */
    FatErrorNoDisk                  = FS_ERR_DEVICE /* No Valid Disk Present */
};

/* File open modes */
enum FatOpenMode {
    FatReadOnlyMode     = FS_IREAD,
    FatReadAndWriteMode = FS_IREAD | FS_IWRITE
};

/* File access flags */
#define FatAccessFlagRdOnly         FS_RDONLY
#define FatAccessFlagWrOnly         FS_WRONLY
#define FatAccessFlagRdWr           FS_RDWR
#define FatAccessFlagAppend         FS_APPEND
#define FatAccessFlagCreate         FS_CREAT
#define FatAccessFlagTrunc          FS_TRUNC
#define FatAccessFlagExcl           FS_EXCL
#define FatAccessFlagText           FS_TEXT
#define FatAccessFlagBinary         FS_BINARY
#define FatAccessFlagNoShareAny     FS_NOSHAREANY
#define FatAccessFlagNoShareWrite   FS_NOSHAREWRITE

/* Arguments to seek */
#define FatSeekBegin                FS_SEEK_SET
#define FatSeekCurrent              FS_SEEK_CUR
#define FatSeekEnd                  FS_SEEK_END

typedef DATESTR FatTimeRecord;

/* File info type */
struct FatFileInfo {
    UINT32          st_mode;        /* (see S_xxxx below) */
    UINT32          st_size;        /* file size, in bytes */
    INT32           st_blksize;     /* optimal block size for I/O (cluster size) */
    INT32           st_blocks;      /* blocks allocated for file */
    FatTimeRecord   st_atime;       /* last access (all times are the same) */
    FatTimeRecord   st_mtime;       /* last modification */
    FatTimeRecord   st_ctime;       /* last file status change */
    INT16           st_dev;         /* (drive number, rtfs) */
    INT16           st_ino;         /* inode number (0) */
    INT16           st_nlink;       /* (always 1) */
    INT16           st_rdev;        /* (drive number, rtfs) */
    UINT16          fattribute;     /* File attributes - DOS attributes (non standard but useful) */
    UINT16          padding;
};

/* Definition of the supported device types */
typedef enum {
    // Zero is a reserved value
    FsMmcSdDev = FS_MMCSD_DEV,
    FsNandDev = FS_FTL_DEVICE1,
    FsFatFfsDev = FS_FFS_DEVICE
    // Insert new device types here
} FsDeviceType;

// =============================================================================
//  FS Registration Info
// =============================================================================

typedef struct {
    FsDeviceType    device;
    CHAR            drive_letter;
    BOOLEAN         removable;
    BOOLEAN         indication;
    BOOLEAN         media_present;
    void            (*notification_func)(FsDeviceType device, BOOLEAN media_present, void *client_arg);
    void            *client_arg;
} FsRegistrationInfo;

/* Structure for user to do recursive search for files in a selected drive */
struct FatFindData {
    CHAR    fname[10];      /* Null terminated file and extension */
    CHAR    fext[4];
    UINT16  fattribute;     /* File attributes */
    UINT16  ftime;          /* Time & Date last modified. See date */
    UINT16  fdate;          /* and time handlers for getting info */
    UINT32  fsize;          /* File size */
    INT16   driveno;
    CHAR    longFileName[FS_MAXPATH];
    CHAR    pname[10];      /* Pattern. */
    CHAR    pext[4];
    CHAR    path[FS_MAXPATH];
    CHAR    plongFileName[FS_MAXPATH];
    void    *pobj;
    void    *pmom;
};

enum FatFileAttribute {
    FatFileAttrRdOnly       = ARDONLY,
    FatFileAttrHidden       = AHIDDEN,
    FatFileAttrSystem       = ASYSTEM,
    FatFileAttrVolume       = AVOLUME,
    FatFileAttrDirectory    = ADIRENT,
    FatFileAttrArchive      = ARCHIVE,
    FatFileAttrNormal       = ANORMAL,
    FatFileAttrChicagoExt   = CHICAGO_EXT
};

#endif  // Apoxi_FatTypes_hpp

