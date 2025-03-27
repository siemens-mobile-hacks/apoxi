/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


/*  ------------------------------------------------------------------------
    All C++ unzip-interfaces have to be redone in future releases. It is
    strongly recommended to use the zlib-C-interface directly until the new
    interfaces are available.
    ------------------------------------------------------------------------ */

#ifndef _unzFFS_H
#define _unzFFS_H

#include <Afs/Ffs/FfsTypes.hpp>
#include <AddOns/zlib/zlib.h>
#include <AddOns/MultiMedia/Unzip.hpp>

/* file_in_zip_read_info_s contain internal information about a file in zipfile,
    when reading and decompress it */
typedef struct
{
    CHAR  *read_buffer;            /* internal buffer for compressed data */
    z_stream stream;               /* zLib stream structure for inflate */

    UINT32 pos_in_zipfile;         /* position in byte on the zipfile, for fseek*/
    UINT32 stream_initialised;     /* flag set if stream structure is initialised*/

    UINT32 offset_local_extrafield;/* offset of the local extra field */
    UINT  size_local_extrafield;   /* size of the local extra field */
    UINT32 pos_local_extrafield;   /* position in the local extra field in read*/

    UINT32 crc32;                   /* crc32 of all data uncompressed */
    UINT32 crc32_wait;              /* crc32 we must obtain after decompress all */
    UINT32 rest_read_compressed;    /* number of byte to be decompressed */
    UINT32 rest_read_uncompressed;  /*number of byte to be obtained after decomp*/

    const CHAR* jar_file_name;
    FfsHandle jar_file_handle;

    UINT32 compression_method;      /* compression method (0==store) */
    UINT32 byte_before_the_zipfile; /* byte before the zipfile, (>0 for sfx)*/
} FileInReadStatusInfo;

typedef struct
{
    CHAR*  jar_file_name;
    UINT16 jar_file_id;
    FfsHandle jar_file_handle;
    JarFileGlobalInfo gi;          /* public global information */
    UINT32 byte_before_the_zipfile;/* byte before the zipfile, (>0 for sfx)*/
    UINT32 num_file;               /* number of the current file in the zipfile*/
    UINT32 pos_in_central_dir;     /* pos of the current file in the central dir*/
    UINT32 current_file_ok;        /* flag about the usability of the current file*/
    UINT32 central_pos;            /* position of the beginning of the central dir*/

    UINT32 size_central_dir;       /* size of the central directory  */
    UINT32 offset_central_dir;     /* offset of start of central directory with
                                      respect to the starting disk number */

    FileInfo cur_file_info;                  /* public info about the current file in zip*/
    FileInfoInternal cur_file_info_internal; /* private info about it*/
    FileInReadStatusInfo* pfile_in_zip_read; /* structure about the current
                                                file if we are decompressing it */
} JarFileStatusInfo;


/*
 * <em>Open</em> opens an archive.
 * @param jar_file_id               the (unique) id of the file
 * @param jar_file_status_info      information about the jar-file status
 * @return                          UNZ_OK if the file is found. It becomes the current file.
                                    UNZ_END_OF_LIST_OF_FILE if the file is not found
 */
extern INT16 OpenFfs (const CHAR* jar_file_name, JarFileStatusInfo *jarFileStatusInfo);

/*
 * <em>Open</em> opens an archive.
 * @param jar_file_name             the filename including path information of the archive
  * @param jar_file_status_info     information about the jar-file status
 * @return                          UNZ_OK if the file is found. It becomes the current file.
                                    UNZ_END_OF_LIST_OF_FILE if the file is not found
 */
extern INT16 OpenFfs (UINT16 jar_file_id, JarFileStatusInfo *jarFileStatusInfo);

/*
 * <em>Close</em> closes an archive.
 * @param jar_file_status_info      information about the jar-file status
 */

extern INT16 CloseFfs (JarFileStatusInfo *jar_file_status_info);

/*
 * <em>LocateFile</em> finds searches a file in the archive
 * @param jar_file_status_info      the information about the jar archive
 * @param file_name                 the filename within the archive
 * @return                          UNZ_OK if the file is found. It becomes the current file.
                                    UNZ_END_OF_LIST_OF_FILE if the file is not found
*/
extern INT16 LocateFileFfs (JarFileStatusInfo *jarFileStatusInfo, 
                     const CHAR *szFileName);

/*
 * <em>OpenCurrentFile</em> opens the current file in the archive (has to be searched by
 * LocateFile before.
 * @param jar_file_status_info      the information about the jar archive
 */
extern INT16 OpenCurrentFileFfs (JarFileStatusInfo *jarFileStatusInfo);

/*
 * <em>CloseCurrentFile</em> closes the current file in the archive
 * @param jar_file_status_info      the information about the jar archive
 */
extern INT16 CloseCurrentFileFfs (JarFileStatusInfo *jarFileStatusInfo);

/*
 * <em>ReadCurrentFile</em> reads the local file content in the buffer
 * @param jar_file_status_info      the information about the jar archive
 * @param buf                       a void* buffer for the file content
 * @param len                       the buffersize
 */
extern INT16 ReadCurrentFileFfs  (JarFileStatusInfo *jarFileStatusInfo, void* buf, UINT16 len);

/*
 * <em>GetCurrentFileInfo</em> gets the file information for the current file
 * within the archive                                          
 * @param jar_file_status_info       the information about the jar archive
 * @param pfile_info                 the file information, set in this method
 * @param file_name                  the file name, set in this method
 * @param name_size                  the buffer size of file_name
 * @param extra_field                an extra field, set in this method
 * @param extra_size                 the buffer size of extra_field
 * @param file_comment               a comment, set in this method
 * @param comment_size               the buffer size of file_comment
 */
extern INT16 GetCurrentFileInfoFfs (JarFileStatusInfo *jar_file_status_info,
                                FileInfo *pfile_info,
                                CHAR *file_name,
                                UINT16 name_size,
                                void *extra_field,
                                UINT16 extra_size,
                                CHAR *file_comment,
                                UINT16 comment_size);

#endif //_unzFFS_H


