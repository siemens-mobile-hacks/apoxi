/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(AddOns_Usb_UsbTransport_hpp)
#define AddOns_Usb_UsbTransport_hpp

#include <Devices/AbstractTransport.hpp>

class UsbTransport : public AbstractTransport, public UserDispatcher {

    typedef AbstractTransport BaseTransport;
    typedef UserDispatcher Base2;

    public:

        static struct UsbConnectionInfo {
            
            enum ConnectionState {
                Connected,
                Usable,
                UnknownDevice,
                Disconnected
            } m_conn_state;

            WString m_device_descr;

        } m_usb_conn_info;

        UsbTransport();
        
        static UsbTransport*  GetInstance();
    
        UsbConnectionInfo& GetConnectionInfo();

        virtual void Enable();

        virtual BaseTransport::AvState GetAvState() const;
    
        static void TransportEvent(INT event);

    protected:
                
        virtual BOOLEAN OnMessage(const Message &msg);

};

#endif  // AddOns_Usb_UsbTransport_hpp

