/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_UsbApp_hpp)
#define Mmi_UsbApp_hpp

#include <Common/MmiApplication.hpp>
#include <AddOns/Usb/UsbTransport.hpp>


class UsbApp : public MmiApplication {
    typedef MmiApplication Base;

    public:
        static UsbApp* GetInstance();

        void Init();
        virtual ~UsbApp();


    protected:

        virtual BOOLEAN OnMessage(const Message &msg);

        virtual void OnOpen();

    private:

        static UsbApp m_usb_app;
        Property m_usb_connection;
        UsbApp();
        void HandleUsbNotification(UsbTransport::UsbConnectionInfo &con_info);
        void DisplayAlert(WString &message);

};
#endif  // Mmi_UsbApp_hpp

