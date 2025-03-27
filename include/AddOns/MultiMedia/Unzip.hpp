/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
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






















































#if !defined(Apoxi_Unzip_hpp)
#define Apoxi_Unzip_hpp

/* define the constants and status information */
#define UNZ_OK                   (0)
#define UNZ_END_OF_LIST_OF_FILE  (-100)
#define UNZ_ERRNO                (Z_ERRNO)
#define UNZ_EOF                  (0)
#define UNZ_PARAMERROR           (-102)
#define UNZ_BADZIPFILE           (-103)
#define UNZ_INTERNALERROR        (-104)
#define UNZ_CRCERROR             (-105)


#define BUFREADCOMMENT (0x400)
#define SIZECENTRALDIRITEM (0x2e)
#define SIZEZIPLOCALHEADER (0x1e)

#define UNZ_MAXFILENAMEINZIP (256)
#define APOXI_UNZIP_BUFSIZE (256)

/* define max and min values for Apoxi data types for save casts */
#define MAX_UINT16 65535


typedef struct JarFileGlobalInfo_s
{
    UINT16 number_entry;         /* total number of entries in
                                    the central dir on this disk */
    UINT16 size_comment;         /* size of the global comment of the zipfile */
} JarFileGlobalInfo;

typedef struct FileInfo_s
{
    UINT16 version;              /* version made by                 2 bytes */
    UINT16 version_needed;       /* version needed to extract       2 bytes */
    UINT16 flag;                 /* general purpose bit flag        2 bytes */
    UINT16 compression_method;   /* compression method              2 bytes */
    UINT32 dosDate;              /* last mod file date in Dos fmt   4 bytes */
    UINT32 crc;                  /* crc-32                          4 bytes */
    UINT16 compressed_size;      /* compressed size                 2 bytes */ 
    UINT16 uncompressed_size;    /* uncompressed size               2 bytes */ 
    UINT16 size_filename;        /* filename length                 2 bytes */
    UINT16 size_file_extra;      /* extra field length              2 bytes */
    UINT16 size_file_comment;    /* file comment length             2 bytes */

    UINT16 disk_num_start;       /* disk number start               2 bytes */
    UINT16 internal_fa;          /* internal file attributes        2 bytes */
    UINT32 external_fa;          /* external file attributes        4 bytes */
} FileInfo;



/* unz_s contain internal information about the zipfile
*/
typedef struct FileInfoInternal_s
{
    UINT32 offset_curfile;/* relative offset of local header 4 bytes */
} FileInfoInternal;

#endif //Apoxi_Unzip_hpp


