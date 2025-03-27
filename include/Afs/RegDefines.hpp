/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RegDefines_hpp)
#define Apoxi_RegDefines_hpp

#include <Kernel/Types.hpp>

#define APOXI_REGISTRY_VERSION 1

#define APOXI_SIZE_16_KILO_BYTE 16384

#if !defined(APOXI_REG_NODE_FILE_SIZE_MAX) // size of node file in bytes
    //#define APOXI_REG_NODE_FILE_SIZE_MAX 4096
    #define APOXI_REG_NODE_FILE_SIZE_MAX 1024
#else
    //Size of Node File cannot exceed 16 KByte for 16-Bit Processor
    #if defined(APOXI_RTOS_OSE166) || defined (APOXI_RTOS_NUC16)
        #if APOXI_REG_NODE_FILE_SIZE_MAX > APOXI_SIZE_16_KILO_BYTE
            #pragma message("APOXI_REG_NODE_FILE_SIZE_MAX exceeds 16Kbyte")
            #pragma message("setting it to 4096 bytes")
            #undef APOXI_REG_NODE_FILE_SIZE_MAX
            #define APOXI_REG_NODE_FILE_SIZE_MAX 4096
        #endif
    #endif
#endif

#if defined(APOXI_REG_LARGE_BLOB_SIZE)
    #if defined(APOXI_RTOS_OSE166) || defined (APOXI_RTOS_NUC16)
        #if (APOXI_REG_LARGE_BLOB_SIZE > APOXI_SIZE_16_KILO_BYTE)
            #pragma message("APOXI_REG_LARGE_BLOB_SIZE exceeds 16Kbyte")
            #pragma message("setting it to 16k bytes")
            #undef APOXI_REG_LARGE_BLOB_SIZE
            #define APOXI_REG_LARGE_BLOB_SIZE APOXI_SIZE_16_KILO_BYTE
        #endif
    #endif
#else
        #define APOXI_REG_LARGE_BLOB_SIZE APOXI_SIZE_16_KILO_BYTE
#endif

#if !defined(APOXI_REG_URI_SIZE_MAX)
    #define APOXI_REG_URI_SIZE_MAX 255
#endif

#if !defined(APOXI_REG_NODE_NAME_SIZE_MAX)
    #define APOXI_REG_NODE_NAME_SIZE_MAX 50
#endif

#if !defined(APOXI_REG_SMALL_BLOB_SIZE_MAX)
    #define APOXI_REG_SMALL_BLOB_SIZE_MAX 512
#else
    #if APOXI_REG_SMALL_BLOB_SIZE_MAX > APOXI_REG_NODE_FILE_SIZE_MAX
        #error SMALL BLOB SIZE cannot exceed APOXI_REG_NODE_FILE_SIZE_MAX /
        Approprate size would be: less than half of APOXI_REG_NODE_FILE_SIZE_MAX
    #endif
#endif

#if !defined(APOXI_REG_MAP_FILE_RECORDS_MAX)
    #define APOXI_REG_MAP_FILE_RECORDS_MAX 64 // MAP File Size approximately comes to 3586 Bytes Inlcluding Header
#endif

//Calculate and set Memory Pool Buffers
#if !defined(APOXI_REG_MAX_POOL_BUFFERS)
    #if defined(APOXI_RTOS_OSE166) || defined (APOXI_RTOS_NUC16)
            #define APOXI_REG_MAX_POOL_BUFFERS  (APOXI_SIZE_16_KILO_BYTE / APOXI_REG_NODE_FILE_SIZE_MAX)
    #else
        #define APOXI_REG_MAX_POOL_BUFFERS 6 //
    #endif
#else
    #if defined(APOXI_RTOS_OSE166) || defined (APOXI_RTOS_NUC16)
        #if (APOXI_SIZE_16_KILO_BYTE / APOXI_REG_NODE_FILE_SIZE_MAX) >  APOXI_REG_MAX_POOL_BUFFERS
            #pragma message("Setting APOXI_REG_MAX_POOL_BUFFERS as specified")
        #else                                               //Cannot exceed (16 KiloBytes)
            #pragma message("Warning: APOXI_REG_MAX_POOL_BUFFERS exceeds 16Kbyte limit")
            #pragma message("         setting it to APPROPRIATE VALUE")
            #undef  APOXI_REG_MAX_POOL_BUFFERS
            #define APOXI_REG_MAX_POOL_BUFFERS  (APOXI_SIZE_16_KILO_BYTE / APOXI_REG_NODE_FILE_SIZE_MAX)
        #endif
    #endif
#endif

//Need to find out which is invalid fileid
#define APOXI_REG_INVALID_FILE_ID -1
#define APOXI_REG_MAX_RECURSION_DEPTH 3
#define APOXI_REG_INVALID_TRANSACTION_ID -1


static const INT c_reg_version = APOXI_REGISTRY_VERSION;

static const INT c_reg_uri_size_max = APOXI_REG_URI_SIZE_MAX;
static const INT c_reg_node_name_size_max = APOXI_REG_NODE_NAME_SIZE_MAX;
static const INT c_reg_node_file_size_max = APOXI_REG_NODE_FILE_SIZE_MAX;


static const INT c_reg_small_blob_size_max = APOXI_REG_SMALL_BLOB_SIZE_MAX;
static const INT c_reg_large_blob_size_max = APOXI_REG_LARGE_BLOB_SIZE;
static const INT c_reg_max_pool_buffers = APOXI_REG_MAX_POOL_BUFFERS;
static const INT c_max_interior_node_records = APOXI_REG_MAP_FILE_RECORDS_MAX;
static const INT16 c_reg_invalid_file_id = APOXI_REG_INVALID_FILE_ID;
static const INT c_reg_max_recursion_depth = APOXI_REG_MAX_RECURSION_DEPTH;
static const INT c_reg_invalid_transaction_id = APOXI_REG_INVALID_TRANSACTION_ID;


static const CHAR*  c_reg_dirty_file   = "dirtyfile"; 
static const CHAR*  c_reg_uri_map_file = "urimapfile";
static const CHAR*  c_reg_root_file    = "rootfile";




enum RegFileType {
    RegFileTypeDirty,   // 0x00
    RegFileTypeMap  ,   // 0x01
    RegFileTypeNode ,   // 0x02
    RegFileTypeBlob ,   // 0x03
    RegFileTypeBackup,   // 0x04
    RegFileTypeRootFile  // 0x05
};

struct RegFileHeader {
           UINT8 m_version;      // the file layout version
           UINT8 m_file_type;    // type of file [see above table]
           UINT16 m_node_count;  // number of node records
};

#endif


