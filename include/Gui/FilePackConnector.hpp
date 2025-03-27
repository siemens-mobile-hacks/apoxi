/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FilePackConnector_hpp)
#define Apoxi_FilePackConnector_hpp

#include <Gui/FilePack.hpp>
#include <Auxiliary/MimeTypeTable.hpp>

class FilePackConnector {

    public:
        static void Init();

        static BOOLEAN IsFilePackAvailable();

        static INT GetNumberOfFiles();

        static const WCHAR *GetFileName(UINT16 index);

        static void GetFileNames(const WCHAR **file_names, INT size);

        static INT32 GetIndexOfFile(const WCHAR *file_name);

        static UINT32 GetFileSize(UINT16 index);

        static const UINT8 *GetData(UINT16 index);

        static MimeType GetMimeType(UINT16 file_index);

        static void CopyData(UINT16 file_index, UINT8 *buffer, UINT32 offset, UINT32 length);

    protected:

    private:

        static FilePack *       m_file_pack;
};

#endif  // Apoxi_FilePackConnector_hpp

