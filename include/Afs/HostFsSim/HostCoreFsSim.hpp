/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HostCoreFsSim_hpp)
#define Apoxi_HostCoreFsSim_hpp

#include <Kernel/Os/Win32/Win32.hpp>
#include <Kernel/Types.hpp>

#define MAX_NO_OPEN_FILES 100

/* Structure for user to do recursive search for files in a selected drive */
struct HostIterStatType {
    CHAR    fname[10];      /* Null terminated file and extension */
    CHAR    fext[4];
    UINT16  fattribute;     /* File attributes */
    UINT16  ftime;          /* Time & Date last modified. See date */
    UINT16  fdate;          /* and time handlers for getting info */
    UINT32  fsize;          /* File size */
    CHAR    path[MAX_PATH]; /* Null terminated directory path */
    CHAR    device_id[3];   /* device id */
    INT32   filehandle;
    CHAR    patternName[MAX_PATH];
    CHAR    longFileName[   MAX_PATH];
};

/* Date stamp structure */
struct DateStr {
    UINT16 date;            /* Current Date */
    UINT16 time;            /* Current time */
};

struct HostFileStatType {
    UINT32   st_mode;               /* (see S_xxxx below) */
    UINT32   st_size;               /* file size, in bytes */
    DateStr st_accesstime;          /* last access (all times are the same) */
    DateStr st_modificationtime;    /* last modification */
    DateStr st_creationtime;        /* last file status change */
    INT16   st_deviceId;            /* (drive number, rtfs) */
    INT16   st_inode;               /* inode number (0) */
    INT16   st_nlink;               /* (always 1) */
    INT16   st_rdev;                /* (drive number, rtfs) */
    UINT16  fattribute;             /* File attributes - DOS attributes
                                       (non standard but useful) */
};

INT32 Internal_open(const CHAR *filename, UINT16 flag, UINT16 mode);
BOOLEAN Internal_close(INT32 fd);
BOOLEAN Internal_exists(const CHAR *path);

UINT32 Internal_read(INT32 fd, UINT8 *buffer, UINT32 count);
UINT32 Internal_write(INT32 fd, const UINT8 *buffer, UINT32 count);
UINT32 Internal_seek(INT32 fd, INT32 offset, INT16 origin,
                    INT16 &err_flag);
BOOLEAN Internal_truncate(INT32 fd, UINT32 new_size);

BOOLEAN Internal_rename(const CHAR *old_filename, const CHAR *new_filename);
BOOLEAN Internal_delete(const CHAR *filename);
BOOLEAN Internal_copy(const CHAR *srcFilename, const CHAR *dstFilename);

BOOLEAN Internal_get_attributes(const CHAR *filename, UINT16 &pattributes);
BOOLEAN Internal_set_attributes(const CHAR *filename, UINT16 attributes);
BOOLEAN Internal_get_file_info(const CHAR *filename, HostFileStatType &pstat);

BOOLEAN Internal_is_dir(const CHAR *path);
BOOLEAN Internal_make_dir(const CHAR *path);
BOOLEAN Internal_change_dir(const CHAR *path);
BOOLEAN Internal_remove_dir(const CHAR *path);
BOOLEAN Internal_get_cwd(CHAR *path);

BOOLEAN Internal_findfirst(HostIterStatType *statobj, const CHAR *pattern,
                        const CHAR *device_id);
BOOLEAN Internal_findnext(HostIterStatType *statobj);
void Internal_finddone(HostIterStatType *statobj);

BOOLEAN Internal_format_device(const CHAR *device);

const CHAR* Internal_get_test_path(const CHAR *device, CHAR *full_device_spec);
CHAR* Internal_filename_to_full_path(CHAR *buf, const CHAR *filename,
                                     const CHAR *device);

#endif  // Apoxi_HostCoreFsSim_hpp

