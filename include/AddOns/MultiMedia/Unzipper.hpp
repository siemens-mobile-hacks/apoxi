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






















































/*  <em>JarZipUtil.hpp</em> contains functions for extracting a single file from a .jar or .zip archive.
    JarZipUtil provides functions for archives stored in the FlashFileSystem (access using filename or file-id) 
    and archives represented in BinData-objects.
                  
    The uncompress algorithm is based on the zlib libray by Mark Adler. The algorithm and the source code
    of this library is used nearly unchanged, even we done some replacement of parameters and changed some
    data types for less memory usage.
    zlib is open source and free to use for anyone, for copyright please read "zlib.h" */

#if !defined(Apoxi_Unzipper_hpp)
#define Apoxi_Unzipper_hpp

#include <Auxiliary/BinData.hpp>
typedef UINT8 JarExtractId;

/*  <em>JVMa_getFileFromJar</em> extracts a file from a jar archive, which is specified by
    a file id, representing a file in the FlashFileSystem. The function calls JVMc_getFileFromJarResponse
    when finished with extracting.
    @param extractionId     an unique id for the request, which is used when calling JVMc_getFileFromJarResponse
    @param jarFileId        the id of the zip-file in the flash file system 
    @param fileName         the file name of the file to be extracted */
void JVMa_getFileFromJar (JarExtractId extractionId,
                          UINT32 jarFileId,
                          const char* fileName);


/*  <em>JVMa_getFileFromJar</em> extracts a file from a jar archive, which is specified by
    a file id, representing a file in the FlashFileSystem. The function calls JVMc_getFileFromJarResponse
    when finished with extracting.
    @param extractionId     an unique id for the request, which is used when calling JVMc_getFileFromJarResponse
    @param jarFileName      the file name of the zip-file in the flash file system 
    @param fileName         the file name of the file to be extracted */
void JVMa_getFileFromJar (JarExtractId extractionId,
                          const char* jarFileName,
                          const char* fileName);

/*  <em>JVMa_getFileFromJar</em> extracts a file from a jar archive, which is held by a BinData object.
    The function calls JVMc_getFileFromJarResponse when finished with extracting.
    @param extractionId     an unique id for the request, which is used when calling JVMc_getFileFromJarResponse
    @param bin_data         a BinData object containing the binary data of a zip-file
    @param fileName         the file name of the file to be extracted */
void JVMa_getFileFromJar (JarExtractId extractionId, BinData* bin_data, const CHAR* fileName);

class Unzipper {
    public:
        static BOOLEAN UnzipFfs(UINT32 zip_file_id, const CHAR* file_name, void* *extracted_buffer, UINT32* extracted_buffer_size);

        static BOOLEAN UnzipFfs(const CHAR* zip_file_name, const CHAR* file_name, void* *extracted_buffer, UINT32* extracted_buffer_size);

        static BOOLEAN UnzipBinData(BinData* bin_data, const CHAR* file_name, void* *extracted_buffer, UINT32* extracted_buffer_size);
};

#endif  // Apoxi_Unzipper_hpp


