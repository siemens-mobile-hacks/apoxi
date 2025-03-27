/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpOutTransfer_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpOutTransfer_hpp

#include <Afs/Rfs/File.hpp>
#include "FtpTransfer.hpp"
#include "FtpSocket.hpp"

class FtpOutTransfer;

typedef NiSharedPtr<FtpOutTransfer> FtpOutTransferPtr;


class FtpOutTransfer : public FtpTransfer
{
    typedef FtpTransfer Base;

    friend class FtpServer;
    friend class FtpDataSocket;

    public:
        FtpOutTransfer(FtpSocketPtr ftpSocket,
            FilePtr file,
            UINT32 offset = 0,
            BOOLEAN running = TRUE);

        virtual ~FtpOutTransfer();

    protected:
        virtual FtpTransferError Start();

};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpOutTransfer_hpp

