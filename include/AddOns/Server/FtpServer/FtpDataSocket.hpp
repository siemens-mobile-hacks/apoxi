/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpDataSocket_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpDataSocket_hpp

#include <Socket/TcpSocket.hpp>
#include "FtpTypes.hpp"
#include "FtpInTransfer.hpp"
#include "FtpOutTransfer.hpp"

class FtpDataSocket;

typedef NiSharedPtr<FtpDataSocket> FtpDataSocketPtr;

class FtpDataSocket : public TcpSocket
{
    typedef TcpSocket Base;

    friend class FtpServer;
    friend class FtpClient;
    friend class FtpInTransfer;
    friend class FtpOutTransfer;

    public:
        FtpDataSocket(FtpSocketPtr ftpSocket,
            UINT clientId = 0, 
            FtpTransferMode mode = c_ftp_transfer_mode_block,
            FtpTransferType type = c_ftp_transfer_type_ascii,
            FtpTransferStructure structure = c_ftp_transfer_structure_file);

        virtual ~FtpDataSocket();

protected:

        virtual void SetMode(FtpTransferMode mode);

        virtual void SetType(FtpTransferType type);

        virtual void SetStructure(FtpTransferStructure structure);

        virtual FtpSocketPtr GetFtpSocket();

        virtual void SetFtpSocket(FtpSocketPtr ftpSocket);

        virtual FtpInTransferPtr GetFtpInTransfer();

        virtual void SetFtpInTransfer(FtpInTransferPtr ftpInTransfer);

        virtual FtpTransferError ProgressFtpInTransfer(UINT32 bytes);

        virtual FtpOutTransferPtr GetFtpOutTransfer();

        virtual void SetFtpOutTransfer(FtpOutTransferPtr ftpOutTransfer);

        virtual FtpTransferError ProgressFtpOutTransfer();

        virtual void SetClientId(UINT clientId);

        virtual void OnAsyncEvent(Event event);

        Server* m_server;
        UINT m_clientId;
        FtpTransferMode m_mode;
        FtpTransferType m_type;
        FtpTransferStructure m_structure;

        FtpSocketPtr    m_ftpSocket;
        FtpInTransferPtr    m_ftpInTransfer;
        FtpOutTransferPtr   m_ftpOutTransfer;

        UINT8* m_data_in_buffer; // internal buffer for reading

        UINT8* m_data_out_buffer; // internal buffer for writing
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpDataSocket_hpp

