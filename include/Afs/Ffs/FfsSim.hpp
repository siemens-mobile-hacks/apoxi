/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(FFS_SIM_hpp)
#define FFS_SIM_hpp

#include <stdio.h>

#define FFS_MAX_SOF_FILENAME    48
#define FFS_MAX_SOF_DIR_NAME    128
#define FFS_BLOCK_SIZE          0x10000L    //64K (Byte size)
#define FFS_SECTOR_SIZE         1024        //Byte size, must be an even number >= 56.
#define FFS_NOF_DYNAMIC_BLOCKS  42
#define FFS_FILETYPE_SMS_POOL_SIZE_PHYSICAL 74752   //Including FFS overhead
#define FFS_MAX_FILESIZE 0xFFFFF   // 1 Mbytes-1

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long ulong;
typedef int BOOL;
typedef FILE *ffs_handle_type;

#define FFS_STREAMING   (0xFEFEFEFE)    //Used as the "size" parameter when creating "streaming files"

// =============================================================================
//  Error Codes
// =============================================================================
typedef enum {
  FFS_FALSE,
  FFS_TRUE,
  FFS_SUCCESS,
  FFS_INITIALIZING,
  FFS_ALREADY_OPEN,
  FFS_NOT_OPEN,
  FFS_FILE_NOT_FOUND,
  FFS_EXISTS,
  FFS_ILLIGAL_ID,
  FFS_ILLIGAL_FILE_HANDLE,
  FFS_ILLIGAL_TYPE,
  FFS_ILLIGAL_MODE,
  FFS_FILE_RANGE_ERROR,
  FFS_OPERATION_NOT_POSSIBLE,
  FFS_WRITE_ERROR,
  FFS_USER_ID_ERROR,
  FFS_INTERNAL_FATAL_ERROR,
  FFS_MEMORY_RES_ERROR,
  FFS_MAX_NOF_FILES_EXCEEDED,
  FFS_REQUESTED_MEM_NOT_AVAILABLE,
  FFS_INVALID_NAME,
  FFS_STREAMING_NOT_ENABLED,
  FFS_OPERATION_NOT_ALLOWED_ON_STATIC_FILE,
  FFS_MEM_TABLES_INCONSISTENCY,
  FFS_NOT_A_FACTORY_DEFAULT_FILE,
  FFS_REQUESTED_MEM_TEMP_NOT_AVAILABLE,
  FFS_ILLIGAL_DIR_OPERATION,
  FFS_DIR_SPACE_NOT_AVAILABLE
} ffs_error_code_type;

//Define old errorcodes to ensure backward compatibility:
#define FFS_FILE_ALREADY_CREATED   FFS_EXISTS
#define FFS_INVALID_FILENAME       FFS_INVALID_NAME

// =============================================================================
//  File Types
// =============================================================================
typedef enum {
    FFS_GENERIC_FILETYPE,         //For files with no specific type, or for temp-files.
    FFS_FILETYPE_APOXI_SETTING,
    FFS_FILETYPE_AVI,
    FFS_FILETYPE_BMP,
    FFS_FILETYPE_GIF,
    FFS_FILETYPE_HTM,
    FFS_FILETYPE_HTML,
    FFS_FILETYPE_ICS,             // vCalendar File
    FFS_FILETYPE_JAD,             // java application descriptor
    FFS_FILETYPE_JAR,             // java archive
    FFS_FILETYPE_JRS,             // java record store
    FFS_FILETYPE_JPG,
    FFS_FILETYPE_JPE,
    FFS_FILETYPE_JPEG,
    FFS_FILETYPE_MIDI,
    FFS_FILETYPE_MMF,             // For Polytone melodies.
    FFS_FILETYPE_MMI_SETTING,
    FFS_FILETYPE_MOV,
    FFS_FILETYPE_MP3,
    FFS_FILETYPE_MPGA,
    FFS_FILETYPE_MPE,
    FFS_FILETYPE_MPEG,
    FFS_FILETYPE_MPG,
    FFS_FILETYPE_PNG,
    FFS_FILETYPE_TIF,
    FFS_FILETYPE_TXT,
    FFS_FILETYPE_VCF,             // vCard File
    FFS_FILETYPE_WAP_SETTING,
    FFS_FILETYPE_WAV,
    FFS_FILETYPE_WBMP,            // wireless bmp
    FFS_FILETYPE_WML,
    FFS_FILETYPE_WMLS,            // WML Script
    FFS_FILETYPE_XHTML,
    FFS_FILETYPE_XML,
    FFS_FILETYPE_AIM,             // Apoxi native image
    FFS_FILETYPE_AAN,             // Apoxi animation format
    FFS_FILETYPE_IMELODY,
    FFS_FILETYPE_AMR,
    FFS_FILETYPE_FR,
    FFS_FILETYPE_MMF_PHRASE,
    FFS_FILETYPE_BROWSER_CACHE,
    FFS_FILETYPE_BROWSER_DATBASE,
    FFS_FILETYPE_SECURITY_CERTIFICATES,
    FFS_FILETYPE_PUSH_MESSAGES,
    FFS_FILETYPE_JAM_BACKUP,
    FFS_FILETYPE_JAM_DEFAULT,
    FFS_FILETYPE_MMS_STORAGE,
    FFS_FILETYPE_MMS_REPORTS,
    FFS_FILETYPE_MMS_NOTIFICATION,
    FFS_FILETYPE_MMS_BACKUP,
    FFS_FILETYPE_MMS_TEST,
    FFS_FILETYPE_MMS_APP_REPORT,
    FFS_FILETYPE_MMT,
    FFS_FILETYPE_MYSTUFF,
    FFS_FILETYPE_SMS,
    FFS_FILETYPE_MMS_PRE,
    FFS_FILETYPE_SETTINGS,
    FFS_FILETYPE_EMS_BMP,
    FFS_FILETYPE_SAF,
    FFS_FILETYPE_SPF,
    FFS_FILETYPE_DRM_RO,
    FFS_FILETYPE_REGISTRY,
    FFS_FILETYPE_3GP,
    FFS_FILETYPE_SVG,
    FFS_FILETYPE_SVGZ,
    FFS_FILETYPE_MMS,
    FFS_FILETYPE_DRM,
    FFS_FILETYPE_FRAME,
    FFS_FILETYPE_AAC,
    FFS_FILETYPE_M4A,
    // All new types shall be inserted above this line.
    FFS_NOF_FILETYPES,
    FFS_FILETYPE_GARBAGE,         // Special filetype for garbage collector ONLY.
    FFS_ALL_FILETYPES = 0xFF
} ffs_filetype_type;

// =============================================================================
//  FFS file ID reservations
// =============================================================================
typedef enum {
    // Dummy element = first ID returned by FfsHandler::GetNextFreeId()
    FFS_NOF_RES_ID = 300
} ffs_pit;

// =============================================================================
//  Memory Pool Reservations
// =============================================================================
const ulong ffs_memory_pool_reservations[FFS_NOF_FILETYPES] = {
 /* FFS_GENERIC_FILETYPE                */     10000,
 /* FFS_FILETYPE_APOXI_SETTING          */         0,
 /* FFS_FILETYPE_AVI                    */         0,
 /* FFS_FILETYPE_BMP                    */         0,
 /* FFS_FILETYPE_GIF                    */      4096,
 /* FFS_FILETYPE_HTM                    */         0,
 /* FFS_FILETYPE_HTML                   */         0,
 /* FFS_FILETYPE_ICS                    */         0,
 /* FFS_FILETYPE_JAD                    */         0,
 /* FFS_FILETYPE_JAR                    */         0,
 /* FFS_FILETYPE_JRS                    */         0,
 /* FFS_FILETYPE_JPG                    */         0,
 /* FFS_FILETYPE_JPE                    */         0,
 /* FFS_FILETYPE_JPEG                   */         0,
 /* FFS_FILETYPE_MIDI                   */         0,
 /* FFS_FILETYPE_MMF                    */      4096,
 /* FFS_FILETYPE_MMI_SETTING            */         0,
 /* FFS_FILETYPE_MOV                    */         0,
 /* FFS_FILETYPE_MP3                    */         0,
 /* FFS_FILETYPE_MPGA                   */      4096,
 /* FFS_FILETYPE_MPE                    */         0,
 /* FFS_FILETYPE_MPEG                   */         0,
 /* FFS_FILETYPE_MPG                    */         0,
 /* FFS_FILETYPE_PNG                    */         0,
 /* FFS_FILETYPE_TIF                    */         0,
 /* FFS_FILETYPE_TXT                    */         0,
 /* FFS_FILETYPE_VCF                    */         0,
 /* FFS_FILETYPE_WAP_SETTING            */         0,
 /* FFS_FILETYPE_WAV                    */         0,
 /* FFS_FILETYPE_WBMP                   */         0,
 /* FFS_FILETYPE_WML                    */         0,
 /* FFS_FILETYPE_WMLS                   */         0,
 /* FFS_FILETYPE_XHTML                  */         0,
 /* FFS_FILETYPE_XML                    */         0,
 /* FFS_FILETYPE_AIM                    */         0,
 /* FFS_FILETYPE_AAN                    */         0,
 /* FFS_FILETYPE_IMELODY                */         0,
 /* FFS_FILETYPE_AMR                    */         0,
 /* FFS_FILETYPE_FR                     */         0,
 /* FFS_FILETYPE_MMF_PHRASE             */         0,
 /* FFS_FILETYPE_BROWSER_CACHE,         */         0,
 /* FFS_FILETYPE_BROWSER_DATBASE,       */         0,
 /* FFS_FILETYPE_SECURITY_CERTIFICATES, */         0,
 /* FFS_FILETYPE_PUSH_MESSAGES,         */         0,
 /* FFS_FILETYPE_JAM_BACKUP,            */         0,
 /* FFS_FILETYPE_JAM_DEFAULT,           */         0,
 /* FFS_FILETYPE_MMS_STORAGE,           */         0,
 /* FFS_FILETYPE_MMS_REPORTS,           */         0,
 /* FFS_FILETYPE_MMS_NOTIFICATION,      */         0,
 /* FFS_FILETYPE_MMS_BACKUP,            */         0,
 /* FFS_FILETYPE_MMS_TEST,              */         0,
 /* FFS_FILETYPE_MMS_APP_REPORT,        */         0,
 /* FFS_FILETYPE_MMT,                   */         0,
 /* FFS_FILETYPE_MYSTUFF                */         0,
 /* FFS_FILETYPE_SMS                    */         FFS_FILETYPE_SMS_POOL_SIZE_PHYSICAL,
 /* FFS_FILETYPE_MMS_PRE                */         0,
 /* FFS_FILETYPE_SETTINGS               */         0,
 /* FFS_FILETYPE_EMS_BMP                */         0,
 /* FFS_FILETYPE_SAF                    */         0,
 /* FFS_FILETYPE_SPF                    */         0,
 /* FFS_FILETYPE_DRM_RO                 */         0,
 /* FFS_FILETYPE_REGISTRY               */         0,
 /* FFS_FILETYPE_3GP                    */         0,
 /* FFS_FILETYPE_SVG                    */         0,
 /* FFS_FILETYPE_SVGZ                   */         0,
 /* FFS_FILETYPE_MMS                    */         0,
 /* FFS_FILETYPE_DRM                    */         0,
 /* FFS_FILETYPE_FRAME                  */         0,
 /* FFS_FILETYPE_AAC                    */         0,
 /* FFS_FILETYPE_M4A                    */         0
};

// =============================================================================
//  Open File Modes
// =============================================================================
typedef enum {
  FFS_FILE_OPEN_READ,
  FFS_FILE_OPEN_APPEND,
  FFS_FILE_OPEN_MODIFY,
  FFS_FILE_OPEN_READ_STREAMING
} ffs_open_file_mode_type;

// =============================================================================
//  User Types
// =============================================================================
typedef enum {
  FFS_INTERNAL,
  FFS_DWDIO,
  FFS_MP3,
  FFS_VR,
  FFS_SMS,
  FFS_AUDIO,
  FFS_MMI,
  FFS_MMS,
  FFS_JAVA,
  FFS_WAP,
  FFS_APCON01,
  FFS_APCON02,
  FFS_APCON03,
  FFS_APCON04,
  FFS_APCON05,
  FFS_APCON06,
  FFS_APCON07,
  FFS_APCON08,
  FFS_APCON09,
  FFS_APCON10,
  FFS_APCON11,
  FFS_APCON12,
  FFS_APCON13,
  FFS_APCON14,
  FFS_APCON15,
  FFS_ATC,
  FFS_NOF_USERS       //Dummy element
} ffs_user_type;

// =============================================================================
//  Time record
// =============================================================================
typedef struct {
  word year;
  byte month;
  byte date;
  byte hour;
  byte min;
} ffs_time_record_type;

// =============================================================================
//  DRM attributes structure
// =============================================================================
typedef struct {
  word local_id;
  word mime_type;
} ffs_drm_attrib_type;

// =============================================================================
//  File info type
// =============================================================================
typedef struct {
  ffs_filetype_type     type;
  ulong                 size;
  ffs_time_record_type  timestamp;
  byte                  dynamic;
  byte                  reserved;
  ffs_drm_attrib_type   drm_attrib;
#ifdef FFS_FACTORY_FILES
  word                  linked_id;
#endif
} ffs_file_info_type;

// =============================================================================
//  Callback type
// =============================================================================
#ifdef FFS_EXTENDED_CALLBACK
  #define ffs_callback_type void (*)(ffs_error_code_type, void*)
#else
  #define ffs_callback_type void(*)(ffs_error_code_type)
#endif

// =============================================================================
//  Directory support
// =============================================================================
//Directory Id type:
typedef word dir_id_type;

typedef struct {
  word                   finding_dirs;
  dir_id_type            dir_id;
  word                   file_id;
  } ffs_ref_type;

ffs_error_code_type FFS_initialize (void);

ffs_error_code_type FFS_ready (void);

void FFS_deactivate (void);

ffs_error_code_type FFS_open (ffs_user_type user_id, word id, ffs_handle_type *hp,
                                ffs_open_file_mode_type mode);

ffs_error_code_type FFS_open_fn (ffs_user_type user_id, char *filename, ffs_handle_type *hp,
                                ffs_open_file_mode_type mode);

ffs_error_code_type FFS_close (ffs_user_type user_id, word id, ffs_handle_type h,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_close_fn (ffs_user_type user_id, char *filename, ffs_handle_type h,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_read (ffs_user_type user_id, word id, ffs_handle_type h,
                                byte *dst, ulong offset, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_read_fn (ffs_user_type user_id, char *filename, ffs_handle_type h,
                                byte *dst, ulong offset, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_create (ffs_user_type user_id, word id,
                                ffs_handle_type *hp, ffs_filetype_type type, ulong size,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_create_fn (ffs_user_type user_id, char *filename,
                                    ffs_handle_type *hp, ffs_filetype_type type, ulong size,
                                    void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_write (ffs_user_type user_id, word id, ffs_handle_type h,
                                byte *src, ulong offset, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_write_fn (ffs_user_type user_id, char *filename, ffs_handle_type h,
                                byte *src, ulong offset, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_modify (ffs_user_type user_id, word id, ffs_handle_type h,
                                byte *src, ulong offset, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_modify_fn (ffs_user_type user_id, char *filename, ffs_handle_type h,
                                byte *src, ulong offset, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_delete (ffs_user_type user_id, word id,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_delete_fn (ffs_user_type user_id, char *filename,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_append (ffs_user_type user_id, word id, ffs_handle_type h,
                                byte *src, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_append_fn (ffs_user_type user_id, char *filename, ffs_handle_type h,
                                byte *src, ulong nof,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_truncate(ffs_user_type user_id, word id, ulong new_size,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_truncate_fn(ffs_user_type user_id, char *filename, ulong new_size,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_rename (ffs_user_type user_id, word id, word new_id,
                                ffs_filetype_type new_type,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_rename_fn (ffs_user_type user_id, char *filename, char *new_filename,
                                ffs_filetype_type new_type,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_copy(ffs_user_type user_id, word src_id, word dst_id,
                                void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_copy_fn(ffs_user_type user_id, char *src_name, char *dst_name,
                                void (*callback)(ffs_error_code_type result));

word FFS_get_next_free_id (void);

BOOL FFS_file_exists (word id);

BOOL FFS_file_exists_fn (ffs_user_type user_id, char *filename);

BOOL FFS_findfirst (word *id_ptr, ffs_filetype_type type);

BOOL FFS_findfirst_fn (ffs_user_type user_id, char *filename_buffer,
                        char *filespec, ffs_filetype_type type);

#if defined(FFS_DIR_SUPPORT)
BOOL FFS_ffirst_fn(ffs_user_type        user_id,
                        char        *name_buffer,
                        char        *name_spec,
                        ffs_ref_type    *name_ref,
                        ffs_filetype_type type);
#endif //FFS_DIR_SUPPORT

BOOL FFS_findnext (word last_id, word *id_ptr, ffs_filetype_type type);

BOOL FFS_findnext_fn (ffs_user_type user_id, char *filename_buffer,
                        char *filespec, ffs_filetype_type type);

#if defined(FFS_DIR_SUPPORT)
BOOL FFS_fnext_fn(ffs_user_type     user_id,
                        char        *name_buffer,
                        char        *name_spec,
                        ffs_ref_type    *name_ref,
                        ffs_filetype_type type);
#endif //FFS_DIR_SUPPORT

ffs_error_code_type FFS_set_drm_attrib (ffs_user_type user_id, word id,
                                    ffs_drm_attrib_type *drm_attrib,
                                    void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_set_drm_attrib_fn (ffs_user_type user_id, char *filename,
                                    ffs_drm_attrib_type *drm_attrib,
                                    void (*callback)(ffs_error_code_type result));

ffs_error_code_type FFS_get_file_info (ffs_user_type user_id, word id, ffs_file_info_type *info);

ffs_error_code_type FFS_get_file_info_fn (ffs_user_type user_id, char *filename,
                                    ffs_file_info_type *info);

ffs_error_code_type FFS_get_file_name(ffs_user_type user_id, word id, char *filename_buffer);

ffs_error_code_type FFS_get_file_id(ffs_user_type user_id, char *filename_buffer, word *id);

word FFS_get_nof_files (void);

word FFS_get_nof_files_by_type (ffs_filetype_type type);

ulong FFS_get_free_space (void);

ulong FFS_get_free_space_by_type (ffs_filetype_type type);

ulong FFS_get_free_space_in_global_pool (void);

ulong FFS_get_raw_free_space_by_type(ffs_filetype_type type);

ulong FFS_get_raw_free_space_in_global_pool(void);

ulong FFS_get_reserved_space_by_type(ffs_filetype_type type);

ulong FFS_get_reserved_space_in_global_pool(void);

ulong FFS_get_used_space(void);

ulong FFS_get_used_space_by_type(ffs_filetype_type type);

ulong FFS_get_used_space_in_global_pool(void);

ulong FFS_calculate_file_overhead(ulong filesize, BOOL use_filename);

#if defined(FFS_DIR_SUPPORT)
ffs_error_code_type FFS_mkdir(ffs_user_type user_id,
                const char *path,
                void (*callback)( ffs_error_code_type result));

ffs_error_code_type FFS_rmdir(ffs_user_type user_id,
                const char *path,
                void (*callback)( ffs_error_code_type result));

ffs_error_code_type FFS_getcwd(ffs_user_type user_id,
                char *path,
                void (*callback)( ffs_error_code_type result));

ffs_error_code_type FFS_setcwd(ffs_user_type user_id,
                const char *path,
                void (*callback)( ffs_error_code_type result));

ffs_error_code_type FFS_isdir(ffs_user_type user_id,
                const char *path,
                void (*callback)( ffs_error_code_type result));
#endif //FFS_DIR_SUPPORT

#endif  // FFS_SIM_hpp

