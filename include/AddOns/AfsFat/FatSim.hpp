/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FatSim_hpp)
#define Apoxi_FatSim_hpp

typedef unsigned char ubyte;
typedef signed short sshort;
typedef unsigned short ushort;
typedef signed int slong;

typedef unsigned long ulong;
typedef int BOOL;

/* We define huge to the empty string for removing the huge modifier from the
   \dwddrv\FS\src\fs.h interfaces (see below). */
#define huge

/****************************************************************************/
/*              \dwddrv\FS\src\fs_config.h                                  */
/****************************************************************************/

/* Maximum path length. */
#define FS_MAXPATH        256

/* Maximum number of open files.
   This is the number of simultaneous
   files that may be opened at one time. */
#define FS_MAX_NO_OPEN_FILES           100

#define FS_NOF_DEVICES 3 // This is the maximum number of device, which can be registered.

/* Definition of the supported device types */
typedef enum
{
    // Zero is a reserved value;
    FS_MMCSD_DEV    = 1,
    FS_FTL_DEVICE1,
    FS_FFS_DEVICE,
    // Insert new device types aboce this line

    // Form this point is special devices used in host test environment
    FS_TEST_DEVICE1 = 240,
    FS_TEST_DEVICE2,
    FS_TEST_DEVICE3
} fs_device_type;

/****************************************************************************/
/*              \dwddrv\FS\src\fs_sdapi.h                                   */
/****************************************************************************/

#define PCFD     long          /* file desc */
#define INVALID_PCFD    -1

/*********************** CRITICAL_ERROR_HANDLER ******************************/
/* Arguments to critical_error_handler() */
#define CRERR_BAD_FORMAT        301
#define CRERR_NO_MEDIA           302
#define CRERR_BAD_MEDIA          303
#define CRERR_MEDIA_CHANGED      304
#define CRERR_MEDIA_FAILURE      305
#define CRERR_ID_ERROR          306
#define CRERR_ECC_ERROR         307

/* Date stamp structure */
typedef struct datestr {
    ushort date;            /* Current Date */
    ushort time;            /* Current time */
} DATESTR;

/* Structure for user to do recursive search for files in a selected drive */
typedef struct dstat {
   char    fname[10];      /* Null terminated file and extension */
   char    fext[4];
   ushort  fattribute;     /* File attributes */
   ushort  ftime;          /* Time & Date last modified. See date */
   ushort  fdate;          /* and time handlers for getting info */
   ulong   fsize;          /* File size */
   sshort  driveno;
   char    longFileName[FS_MAXPATH];
   char    pname[10];      /* Pattern. */
   char    pext[4];
   char    path[FS_MAXPATH];
   char    plongFileName[FS_MAXPATH];
   void    *pobj;
   void    *pmom;
} DSTAT;

/****************************************************************************/
/**************************** FILE SYSTEM API *******************************/
/****************************************************************************/

#define ARDONLY         0x01    /* MS-DOS File attributes */
#define AHIDDEN         0x02
#define ASYSTEM         0x04
#define AVOLUME         0x08
#define ADIRENT         0x10
#define ARCHIVE         0x20
#define ANORMAL         0x00
#define CHICAGO_EXT     0x0F    /* Chicago extended filename attribute */

/*
** Structure for use by with file statistic.
** Portions of this structure and the macros were lifted from BSD sources.
** See the RTFS ANSI library for BSD terms & conditions.
*/
typedef struct fs_stat
{
    ulong   st_mode;        /* (see S_xxxx below) */
    ulong   st_size;        /* file size, in bytes */
    slong    st_blksize;     /* optimal blocksize for I/O (cluster size) */
    slong    st_blocks;      /* blocks allocated for file */
    DATESTR st_atime;       /* last access (all times are the same) */
    DATESTR st_mtime;       /* last modification */
    DATESTR st_ctime;       /* last file status change */
    sshort   st_dev;         /* (drive number, rtfs) */
    sshort   st_ino;         /* inode number (0) */
    sshort   st_nlink;       /* (always 1) */
    sshort   st_rdev;        /* (drive number, rtfs) */
    ushort  fattribute;     /* File attributes - DOS attributes
                            (non standard but useful)
                            */
    ushort  padding;
} STAT;

/* File creation permissions for open */
/* Note: OCTAL */
#define PS_IWRITE       0000400 /* Write permitted  */
#define PS_IREAD        0000200 /* Read permitted. (Always true anyway) */

/* File access flags */
#define PO_RDONLY       0x0000 /* Open for read only */
#define PO_WRONLY       0x0001 /* Open for write only */
#define PO_RDWR         0x0002 /* Read/write access allowed. */
#define PO_CREAT        0x0100 /* Create the file if it does not exist. */
#define PO_TRUNC        0x0200 /* Truncate the file if it already exists */
#define PO_EXCL         0x0400 /* Fail if creating and already exists */
#define PO_APPEND       0x0800 /* Seek to eof on each write */
#define PO_TEXT         0x4000 /* Ignored */
#define PO_BINARY       0x8000 /* Ignored. All file access is binary */
#define PO_NOSHAREANY   0x0010 /* Wants this open to fail if already open.
                                  Other opens will fail while this open
                                  is active */
#define PO_NOSHAREWRITE 0x0020 /* Wants this opens to fail if already open
                                  for write. Other open for write calls
                                  will fail while this open is active. */

/* ErrNO values */
#define PESUCCESS       1       /* No error */
#define PENOENT         2       /* File not found or path to file not found */
#define PEBADF          9       /* Invalid file descriptor */
#define PEACCES         13      /* Attempt to open a read only file or a special (directory) */
#define PEEXIST         17      /* Exclusive access requested but file already exists. */
#define PEFAULT         18      /* Unknown error. */
#define PEIO            19      /* I/O error.. */
#define PEINVAL         22      /* Seek to negative file pointer attempted. */
#define PEMFILE         24      /* No file descriptors available (too many files open) */
#define PENOSPC         28      /* Write failed. Presumably because of no space */
#define PESHARE         30      /* Open failed do to sharing */
#define PEDEVICE        31      /* No Valid Disk Present */

/* Arguments to SEEK */
#define PSEEK_SET       0       /* offset from begining of file */
#define PSEEK_CUR       1       /* offset from current file pointer */
#define PSEEK_END       2       /* offset from end of file */

/****************************************************************************/
/*              \dwddrv\FS\src\fs.h                                         */
/****************************************************************************/

// FS error codes:
#define FS_FAILURE                     0
#define FS_SUCCESS                     1
#define FS_ERR_OPERATION_NOT_POSSIBLE  3
#define FS_ERR_USER_ID_ERROR           4

/*********************** CRITICAL_ERROR_HANDLER ******************************/
/* Arguments to critical_error_handler() */
#define FS_ERR_BAD_FORMAT              CRERR_BAD_FORMAT        //301
#define FS_ERR_NO_MEDIA                CRERR_NO_MEDIA         //302
#define FS_ERR_BAD_MEDIA               CRERR_BAD_MEDIA        //303
#define FS_ERR_MEDIA_CHANGED           CRERR_MEDIA_CHANGED    //304
#define FS_ERR_MEDIA_FAILURE           CRERR_MEDIA_FAILURE    //305
#define FS_ERR_ID_ERROR                CRERR_ID_ERROR          //306
#define FS_ERR_ECC_ERROR               CRERR_ECC_ERROR         //307

/* Filesystem Errno values */
#define FS_ERR_NOENT                   PENOENT  //  2      /* File not found or path to file not found */
#define FS_ERR_BADF                    PEBADF   //  9      /* Invalid file descriptor */
#define FS_ERR_ACCES                   PEACCES  // 13      /* Attempt to open a read only file or a special (directory) */
#define FS_ERR_EXIST                   PEEXIST  // 17      /* Exclusive access requested but file already exists. */
#define FS_ERR_FAULT                   PEFAULT  // 18      /* Unknown error. */
#define FS_ERR_IO                      PEIO     // 19      /* I/O error. */
#define FS_ERR_INVAL                   PEINVAL  // 22      /* Seek to negative file pointer attempted. */
#define FS_ERR_MFILE                   PEMFILE  // 24      /* No file descriptors available (too many files open) */
#define FS_ERR_NOSPC                   PENOSPC  // 28      /* Write failed. Presumably because of no space */
#define FS_ERR_SHARE                   PESHARE  // 30      /* Open failed do to sharing */
#define FS_ERR_DEVICE                  PEDEVICE // 31      /* No Valid Disk Present */

/* Arguments to SEEK */
#define FS_SEEK_SET                    PSEEK_SET       /* offset from begining of file */
#define FS_SEEK_CUR                    PSEEK_CUR       /* offset from current file pointer */
#define FS_SEEK_END                    PSEEK_END       /* offset from end of file */

/* File open flags */
#define FS_RDONLY                      PO_RDONLY       /* Open for read only */
#define FS_WRONLY                      PO_WRONLY       /* Open for write only */
#define FS_RDWR                        PO_RDWR         /* Read/write access allowed. */
#define FS_APPEND                      PO_APPEND       /* Seek to eof on each write */
#define FS_CREAT                       PO_CREAT        /* Create the file if it does not exist. */
#define FS_TRUNC                       PO_TRUNC        /* Truncate the file if it already exists */
#define FS_EXCL                        PO_EXCL         /* Fail if creating and already exists */
#define FS_TEXT                        PO_TEXT         /* Ignored */
#define FS_BINARY                      PO_BINARY       /* Ignored. All file access is binary */
#define FS_NOSHAREANY                  PO_NOSHAREANY   /* Wants this open to fail if already open. Other opens will fail while this open is active */
#define FS_NOSHAREWRITE                PO_NOSHAREWRITE /* Wants this opens to fail if already open for write. Other open for write calls will fail while this open is active. */

/* File open modes */
#define FS_IWRITE                      PS_IWRITE /* Write permitted */
#define FS_IREAD                       PS_IREAD  /* Read permitted. (Always true anyway) */

typedef struct
{
    fs_device_type device;
    char           drive_letter;
    BOOL           removable;
    BOOL           indication;
    BOOL           media_present;
    void           (*notification_func)(fs_device_type device, BOOL media_present, void *client_arg);
    void           *client_arg;
}  fs_registered_info_type;

/* Structure for user to do recursive search for files in a selected drive */
typedef DSTAT fs_dstat_type;

/*
** Structure for use by with file statistic.
*/
typedef STAT fs_stat_type;

/*
** File handle returned by FS_open and used in later file operations.
*/
typedef PCFD fs_fd_type;
#define FS_INVALID_FILEHANDLE INVALID_PCFD

/*---------------------------------------*/
/* global functions.                     */
/*---------------------------------------*/

//Init/deactivate functions:
extern BOOL FS_init_rtos(void);
extern void FS_deactivate(void);

//Register devices
extern ubyte FS_get_registered_devices(const fs_registered_info_type **device_list) ;
extern BOOL FS_assign_driveletter(fs_device_type device, char drive_letter);
extern BOOL FS_register_media_status_notification(fs_device_type device, void (*notify_func)(fs_device_type device, BOOL media_present, void *client_arg), void *client_arg);
extern void FS_device_notify(long device_id, BOOL media_present);

//Disk/device services:
extern BOOL FS_diskopen(fs_device_type device);
extern BOOL FS_diskflush(fs_device_type device);
extern BOOL FS_diskclose(fs_device_type device);
extern void FS_diskabort(fs_device_type device);
extern BOOL FS_diskinfo(fs_device_type device, BOOL *mounted, ubyte *nof_partitions);

extern BOOL FS_format(fs_device_type device, BOOL quick);
extern ulong FS_free(fs_device_type device);

extern fs_device_type FS_get_default_device(void);
extern BOOL FS_set_default_device(fs_device_type device);

//FS directory operating functions:
extern BOOL FS_mkdir(const char *path);
extern BOOL FS_rmdir(const char *path);
extern BOOL FS_isdir(const char *path);

extern BOOL FS_getcwd(const char *drive, char *path);
extern BOOL FS_setcwd(const char *path);

extern BOOL FS_findfirst(fs_dstat_type *statobj, const char *pattern);
extern BOOL FS_findnext(fs_dstat_type *statobj);
extern void FS_finddone(fs_dstat_type *statobj);

//FS file operating functions:
extern fs_fd_type FS_open(const char *filename, ushort flag, ushort mode);
extern BOOL FS_close(fs_fd_type fd);
extern BOOL FS_read(fs_fd_type fd, ubyte huge *buffer, ulong count);
extern ulong FS_read_max(fs_fd_type fd, ubyte huge *buffer, ulong count);
extern BOOL FS_write(fs_fd_type fd, const ubyte huge *buffer, ulong count);
extern BOOL FS_flush(fs_fd_type fd);
extern BOOL FS_truncate(fs_fd_type fd, ulong new_size);

//FS Streaming data
extern BOOL FS_read_streaming(fs_fd_type fd, ubyte huge *buffer, ulong count, void (*callback)(sshort result, void *client_arg), void *client_arg);
extern BOOL FS_write_streaming(fs_fd_type fd, const ubyte huge *buffer, ulong count, void (*callback)(sshort result, void *client_arg), void *client_arg);
extern BOOL FS_get_file_length_streaming(fs_fd_type fd, ulong *file_size, void (*callback)(sshort result, void *client_arg), void *client_arg);
extern BOOL FS_get_file_pos_streaming(fs_fd_type fd, ulong *pos, void (*callback)(sshort result, void *client_arg), void *client_arg);
extern BOOL FS_set_file_pos_streaming(fs_fd_type fd, ulong pos, void (*callback)(sshort result, void *client_arg), void *client_arg);

extern BOOL FS_rename(const char *old_filename, const char *new_filename);
extern BOOL FS_delete(const char *filename);

extern BOOL FS_get_attributes(const char *filename, ushort *attributes);
extern BOOL FS_set_attributes(const char *filename, ushort attributes);

extern ulong FS_seek(fs_fd_type fd, slong offset, sshort origin, sshort *err_flag);
extern BOOL FS_stat(const char *filename, fs_stat_type *pstat);

//FS Errorhandling
extern sshort FS_get_last_error(void);
extern sshort FS_get_last_device_error(fs_device_type device);

/****************************************************************************/
/*              \dwddrv\FS\src\fs_massstorage_APOXI.h                       */
/****************************************************************************/

typedef enum {
    FS_MS_connect,
    FS_MS_disconnect
} ConnectType;

typedef BOOL (*FS_MS_StatusNotificationFunction_type)(
    fs_device_type drive_id,
    ConnectType request,
    void *user_data);

BOOL FS_MS_AssignStatusNotificationFunction(FS_MS_StatusNotificationFunction_type notification_function, void *user_data);

/****************************************************************************/
/*              non-driver related interface                                */
/****************************************************************************/

#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

// The host storage device descriptor.
struct HostFatFsDeviceDescriptor {
    String m_device_id;
    fs_device_type m_device;

    HostFatFsDeviceDescriptor() : m_device(static_cast<fs_device_type>(0))
    { }

    HostFatFsDeviceDescriptor(
        const String &m_device_id,
        fs_device_type m_device)
    :
        m_device_id(m_device_id),
        m_device(m_device)
    { }
};

// Maps the drive letter to the according host storage device descriptor.
typedef SimpleMap<const CHAR, HostFatFsDeviceDescriptor> HostFatFsDeviceDescMap;

// Shared pointer to the host storage device descriptor map.
typedef NiSharedPtr<HostFatFsDeviceDescMap> HostFatFsDeviceDescMapPtr;

// Initializes the host simulator with the available storage devices.
void HostInitFatFsStorageDevices(const HostFatFsDeviceDescMapPtr &device_map);

#endif  // Apoxi_FatSim_hpp

