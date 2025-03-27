/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined( AddOns_Usb_UsbObexAddress_hpp)
#define AddOns_Usb_UsbObexAddress_hpp

#include <Obex/ObexAddress.hpp>


class UsbObexTransport; 

class UsbObexServerAddr : public ObexServerAddr {

    typedef ObexServerAddr Base;

    public:
    
        UsbObexServerAddr(UsbObexTransport *obex_transport, String server_url);

        virtual ObexResult ToString(String &  obex_url) const;

    private:

        String m_server_url;
    
};

#endif  // AddOns_Usb_UsbObexAddress_hpp

