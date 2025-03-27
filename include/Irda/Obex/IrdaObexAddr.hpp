/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_IrdaObexAddress_hpp)
#define Apoxi_IrdaObexAddress_hpp

#include <stack/extensions.h>

#include <Obex/ObexAddress.hpp>

class IrdaObexClientAddr : public ObexClientAddr {

    public:
        typedef ObexClientAddr Base;

        IrdaObexClientAddr(ObexTransportId  transport_id,
                           IrDeviceAddr     remote_addr);

        virtual ObexResult ToString(String &  obex_url) const;
        inline IrDeviceAddr GetRemoteAddr() { return m_remote_addr; }

    private:
        IrDeviceAddr    m_remote_addr;
        U8              m_remote_lsap;
};


class IrdaObexServerAddr : public ObexServerAddr {

    public:
        typedef ObexServerAddr Base;
        IrdaObexServerAddr(ObexTransportId  transport_id,
            IrDeviceAddr        remote_addr);

        
        virtual ObexResult  ToString(String &  obex_url) const;
        inline IrDeviceAddr GetRemoteAddr() { return m_remote_addr; }

    private:
        IrDeviceAddr    m_remote_addr;
        U8              m_remote_lsap;
};

#endif  // Apoxi_IrdaObexAddress_hpp

