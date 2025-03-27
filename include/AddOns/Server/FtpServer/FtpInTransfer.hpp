/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpInTransfer_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpInTransfer_hpp

#include "FtpTransfer.hpp"
#include "FtpSocket.hpp"
#include <Afs/Rfs/File.hpp>

class FtpInTransfer;

typedef NiSharedPtr<FtpInTransfer> FtpInTransferPtr;


class FtpInTransfer : public FtpTransfer
{
    typedef FtpTransfer Base;

    friend class FtpServer;
    friend class FtpDataSocket;

    public:
        FtpInTransfer(FtpSocketPtr ftpSocket,
            FilePtr file,
            UINT32 offset = 0,
            BOOLEAN running = TRUE);

        virtual ~FtpInTransfer();

    protected:
        virtual FtpTransferError Start();

};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpInTransfer_hpp

