/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FfsTypes_hpp)
#define Apoxi_FfsTypes_hpp

#include <Kernel/Types.hpp>

#if defined(APOXI_RTOS_WIN32)
    // Host simulator for FFS.
    #include <Afs/Ffs/FfsSim.hpp>
#elif !defined(FFS_PRESENT)
    #error The flash file system (FFS) is a prerequisite for an APOXI target build - please enable feature FFS!
#else
    #include <stack/driver.h>
#endif

const UINT c_max_filename_len = FFS_MAX_SOF_FILENAME;

#if defined(FFS_DIR_SUPPORT)

    const UINT c_max_dirname_len = FFS_MAX_SOF_DIR_NAME;
#endif

typedef ffs_handle_type         FfsHandle;

typedef word                    FfsFileId;

const UINT32 c_ffs_streaming = FFS_STREAMING;

const UINT c_ffs_block_header_size = 3;
const UINT32 c_max_total_ffs_memory =
    ((FFS_BLOCK_SIZE - c_ffs_block_header_size * 2) / FFS_SECTOR_SIZE) *
    FFS_SECTOR_SIZE * (FFS_NOF_DYNAMIC_BLOCKS - 1);

// =============================================================================
//  Error Codes
// =============================================================================

enum FfsError {
    FfsErrorFalse                   = FFS_FALSE,
    FfsErrorTrue                    = FFS_TRUE,
    FfsErrorSuccess                 = FFS_SUCCESS,
    FfsErrorInitializing            = FFS_INITIALIZING,
    FfsErrorAlreadyOpen             = FFS_ALREADY_OPEN,
    FfsErrorNotOpen                 = FFS_NOT_OPEN,
    FfsErrorFileNotFound            = FFS_FILE_NOT_FOUND,
#if defined(APOXI_PLATFORM_BP30)

    FfsErrorFileAlreadyCreated      = FFS_FILE_ALREADY_CREATED,
#else

    FfsErrorFileAlreadyCreated      = FFS_EXISTS,
#endif

    FfsErrorIllegalId               = FFS_ILLIGAL_ID,
    FfsErrorIllegalFileHandle       = FFS_ILLIGAL_FILE_HANDLE,
    FfsErrorIllegalType             = FFS_ILLIGAL_TYPE,
    FfsErrorIllegalMode             = FFS_ILLIGAL_MODE,
    FfsErrorFileRangeError          = FFS_FILE_RANGE_ERROR,
    FfsErrorNotPossible             = FFS_OPERATION_NOT_POSSIBLE,
    FfsErrorWriteError              = FFS_WRITE_ERROR,
    FfsErrorUserIdError             = FFS_USER_ID_ERROR,
    FfsErrorIntFatalError           = FFS_INTERNAL_FATAL_ERROR,
    FfsErrorMemoryResError          = FFS_MEMORY_RES_ERROR,
    FfsErrorMaxNrOfFilesExcceeded   = FFS_MAX_NOF_FILES_EXCEEDED,
    FfsErrorReqMemNotAvailable      = FFS_REQUESTED_MEM_NOT_AVAILABLE,
    FfsErrorInvalidFilename         = FFS_INVALID_NAME,
    FfsErrorStreamingNotEnabled     = FFS_STREAMING_NOT_ENABLED,
    FfsErrorOpNotAllowedOnStatFile  = FFS_OPERATION_NOT_ALLOWED_ON_STATIC_FILE,
    FfsErrorMemTablesInconsistent   = FFS_MEM_TABLES_INCONSISTENCY,
    FfsErrorNoFactoryDefaultFile    = FFS_NOT_A_FACTORY_DEFAULT_FILE,
    FfsErrorReqMemTempNotAvailable  = FFS_REQUESTED_MEM_TEMP_NOT_AVAILABLE,

#if defined(FFS_DIR_SUPPORT)

    FfsErrorIllegalDirOperation     = FFS_ILLIGAL_DIR_OPERATION,
    FfsErrorDirSpaceNotAvailable    = FFS_DIR_SPACE_NOT_AVAILABLE
#endif

};

// =============================================================================
//  User Types
// =============================================================================

enum FfsUserType {
    FfsUserTypeDwdIo    = FFS_DWDIO,
    FfsUserTypeMp3      = FFS_MP3,
    FfsUserTypeVr       = FFS_VR,
    FfsUserTypeSms      = FFS_SMS,
    FfsUserTypeAudio    = FFS_AUDIO,
    FfsUserTypeMmi      = FFS_MMI,
    FfsUserTypeMms      = FFS_MMS,
    FfsUserTypeJava     = FFS_JAVA,
    FfsUserTypeWap      = FFS_WAP,
    FfsUserTypeAppCon01 = FFS_APCON01,
    FfsUserTypeAppCon02 = FFS_APCON02,
    FfsUserTypeAppCon03 = FFS_APCON03,
    FfsUserTypeAppCon04 = FFS_APCON04,
    FfsUserTypeAppCon05 = FFS_APCON05,
    FfsUserTypeAppCon06 = FFS_APCON06,
    FfsUserTypeAppCon07 = FFS_APCON07,
    FfsUserTypeAppCon08 = FFS_APCON08,
    FfsUserTypeAppCon09 = FFS_APCON09,
    FfsUserTypeAppCon10 = FFS_APCON10,
    FfsUserTypeAppCon11 = FFS_APCON11,
    FfsUserTypeAppCon12 = FFS_APCON12,
    FfsUserTypeAppCon13 = FFS_APCON13,
    FfsUserTypeAppCon14 = FFS_APCON14,
    FfsUserTypeAppCon15 = FFS_APCON15,
    FfsUserTypeAtc      = FFS_ATC,
    FfsNofUsers         = FFS_NOF_USERS    // Dummy element
};

#define ExtFfsUserType(type_name) ((FfsUserType)FFS_##type_name)

// =============================================================================
//  File Types
// =============================================================================

enum FfsFileType {
    FfsFileTypeGeneric              = FFS_GENERIC_FILETYPE,
    FfsFileTypeApoxiSetting         = FFS_FILETYPE_APOXI_SETTING,
    FfsFileTypeAvi                  = FFS_FILETYPE_AVI,
    FfsFileTypeBmp                  = FFS_FILETYPE_BMP,
    FfsFileTypeGif                  = FFS_FILETYPE_GIF,
    FfsFileTypeHtm                  = FFS_FILETYPE_HTM,
    FfsFileTypeHtml                 = FFS_FILETYPE_HTML,
    FfsFileTypeIcs                  = FFS_FILETYPE_ICS,
    FfsFileTypeJad                  = FFS_FILETYPE_JAD,
    FfsFileTypeJar                  = FFS_FILETYPE_JAR,
    FfsFileTypeJrs                  = FFS_FILETYPE_JRS,
    FfsFileTypeJpg                  = FFS_FILETYPE_JPG,
    FfsFileTypeJpe                  = FFS_FILETYPE_JPE,
    FfsFileTypeJpeg                 = FFS_FILETYPE_JPEG,
    FfsFileTypeMidi                 = FFS_FILETYPE_MIDI,
    FfsFileTypeMmf                  = FFS_FILETYPE_MMF,
    FfsFileTypeMmiSetting           = FFS_FILETYPE_MMI_SETTING,
    FfsFileTypeMov                  = FFS_FILETYPE_MOV,
    FfsFileTypeMp3                  = FFS_FILETYPE_MP3,
    FfsFileTypeMpga                 = FFS_FILETYPE_MPGA,
    FfsFileTypeMpe                  = FFS_FILETYPE_MPE,
    FfsFileTypeMpeg                 = FFS_FILETYPE_MPEG,
    FfsFileTypeMpg                  = FFS_FILETYPE_MPG,
    FfsFileTypePng                  = FFS_FILETYPE_PNG,
    FfsFileTypeTif                  = FFS_FILETYPE_TIF,
    FfsFileTypeTxt                  = FFS_FILETYPE_TXT,
    FfsFileTypeVcf                  = FFS_FILETYPE_VCF,
    FfsFileTypeWapSetting           = FFS_FILETYPE_WAP_SETTING,
    FfsFileTypeWav                  = FFS_FILETYPE_WAV,
    FfsFileTypeWbmp                 = FFS_FILETYPE_WBMP,
    FfsFileTypeWml                  = FFS_FILETYPE_WML,
    FfsFileTypeWmls                 = FFS_FILETYPE_WMLS,
    FfsFileTypeXhtml                = FFS_FILETYPE_XHTML,
    FfsFileTypeXml                  = FFS_FILETYPE_XML,
    FfsFileTypeAim                  = FFS_FILETYPE_AIM,
    FfsFileTypeAan                  = FFS_FILETYPE_AAN,
    FfsFileTypeIMelody              = FFS_FILETYPE_IMELODY,
    FfsFileTypeAmr                  = FFS_FILETYPE_AMR,
    FfsFileTypeFr                   = FFS_FILETYPE_FR,
    FfsFileTypeMmfPhrase            = FFS_FILETYPE_MMF_PHRASE,
    FfsFileTypeBrowserCache         = FFS_FILETYPE_BROWSER_CACHE,
    FfsFileTypeBrowserDatabase      = FFS_FILETYPE_BROWSER_DATBASE,
    FfsFileTypeSecurityCertificates = FFS_FILETYPE_SECURITY_CERTIFICATES,
    FfsFileTypePushMessages         = FFS_FILETYPE_PUSH_MESSAGES,
    FfsFileTypeJamBackup            = FFS_FILETYPE_JAM_BACKUP,
    FfsFileTypeJamDefault           = FFS_FILETYPE_JAM_DEFAULT,
    FfsFileTypeMmsStorage           = FFS_FILETYPE_MMS_STORAGE,
    FfsFileTypeMmsReports           = FFS_FILETYPE_MMS_REPORTS,
    FfsFileTypeMmsNotification      = FFS_FILETYPE_MMS_NOTIFICATION,
    FfsFileTypeMmsBackup            = FFS_FILETYPE_MMS_BACKUP,
    FfsFileTypeMmsTest              = FFS_FILETYPE_MMS_TEST,
    FfsFileTypeMmsAppReport         = FFS_FILETYPE_MMS_APP_REPORT,
    FfsFileTypeMmt                  = FFS_FILETYPE_MMT,
    FfsFileTypeMyStuff              = FFS_FILETYPE_MYSTUFF,
    FfsFileTypeSms                  = FFS_FILETYPE_SMS,
    FfsFileTypeMmsPre               = FFS_FILETYPE_MMS_PRE,
    FfsFileTypeSettings             = FFS_FILETYPE_SETTINGS,
    FfsFileTypeEmsBmp               = FFS_FILETYPE_EMS_BMP,
    FfsFileTypeSaf                  = FFS_FILETYPE_SAF,
    FfsFileTypeSpf                  = FFS_FILETYPE_SPF,
    FfsFileTypeDrmRo                = FFS_FILETYPE_DRM_RO,
    FfsFileTypeRegistry             = FFS_FILETYPE_REGISTRY,
    FfsFileType3gp                  = FFS_FILETYPE_3GP,
#if !defined(APOXI_PLATFORM_BP30)

    FfsFileTypeSvg                  = FFS_FILETYPE_SVG,
    FfsFileTypeSvgz                 = FFS_FILETYPE_SVGZ,
    FfsFileTypeMms                  = FFS_FILETYPE_MMS,
    FfsFileTypeDrm                  = FFS_FILETYPE_DRM,
    FfsFileTypeFrame                = FFS_FILETYPE_FRAME,
    FfsFileTypeAac                  = FFS_FILETYPE_AAC,
    FfsFileTypeM4a                  = FFS_FILETYPE_M4A,
#endif

    FfsNofFileTypes                 = FFS_NOF_FILETYPES,
    FfsFileTypeGarbage              = FFS_FILETYPE_GARBAGE,
    FfsFileTypeAll                  = FFS_ALL_FILETYPES
};

// =============================================================================
//  FFS file ID reservations
// =============================================================================
enum FfsPit {
    FfsNofResId = FFS_NOF_RES_ID    // Dummy element
};

#define ExtFfsPit(pit_name) ((FfsPit)FFS_##pit_name)

#define ExtFfsFileType(type_name) ((FfsFileType)FFS_FILETYPE_##type_name)

// =============================================================================
//  Open File Modes
// =============================================================================

enum FfsOpenMode {
    FfsOpenModeRead         = FFS_FILE_OPEN_READ,
    FfsOpenModeAppend       = FFS_FILE_OPEN_APPEND,
    FfsOpenModeModify       = FFS_FILE_OPEN_MODIFY,
    FfsOpenModeReadStr      = FFS_FILE_OPEN_READ_STREAMING
};

// =============================================================================
//  Time Record
// =============================================================================

struct FfsTimeRecord {
    UINT16  year;
    UINT8   month;
    UINT8   date;
    UINT8   hour;
    UINT8   min;
};

// =============================================================================
//  DRM Attribute Type
// =============================================================================

struct FfsDrmAttrib {
    UINT16  local_id;
    UINT16  mime_type;
};

// =============================================================================
//  File Reference Type
// =============================================================================

struct FfsRefType {
  UINT16        finding_dirs;
  UINT16        dir_id;
  UINT16        file_id;
};

// =============================================================================
//  File Info Type
// =============================================================================

struct FfsFileInfo {
    FfsFileType         type;
    UINT32              size;
    FfsTimeRecord       timestamp;
    UINT8               dynamic;
    UINT8               reserved;
    FfsDrmAttrib        drm_attrib;

#ifdef FFS_FACTORY_FILES

    UINT32              linked_id;
#endif

};

const FfsFileInfo EmptyFfsFileInfo =
    { FfsFileTypeAll, 0, { 0, 0, 0, 0, 0 }, 0, 0, 0
#ifdef FFS_FACTORY_FILES
        , 0
#endif
    };

#endif  // Apoxi_FfsTypes_hpp

