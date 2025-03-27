/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpTransfer_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpTransfer_hpp

#include <Afs/Rfs/File.hpp>
#include "FtpTypes.hpp"
#include "FtpSocket.hpp"

class FtpTransfer;

typedef NiSharedPtr<FtpTransfer> FtpTransferPtr;


class FtpServer;


class FtpTransfer
{
    friend class FtpServer;
    friend class FtpClient;
    friend class FtpDataSocket;

    public:
        virtual ~FtpTransfer();

        virtual BOOLEAN IsRunning();

protected:
        FtpTransfer(
            UINT clientId,
            FtpSocketPtr ftpSocket,
            FilePtr file,
            UINT32 offset = 0,
            BOOLEAN running = TRUE);

        virtual void SetRunning(BOOLEAN running);

        virtual FtpTransferError Start() = 0;
    
        UINT m_clientId;    // ID of the client     
        FtpSocketPtr m_ftpSocket;   // socket for control connection        
        FilePtr m_file;     // file to transfer     
        UINT32 m_filesize;  // size of the file     
        UINT32 m_offset;    // offset when reading/writing the file
        BOOLEAN m_running;  // whether the transfer is currently runnig or not
        BOOLEAN m_disconnect_on_complete;   // disconnect client when transfer is complete
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpTransfer_hpp

