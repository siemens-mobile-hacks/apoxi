/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(AddOns_Usb_UsbSubSystem_hpp)
#define AddOns_Usb_UsbSubSystem_hpp


#include <Kernel/SubSystem.hpp>
#include <Kernel/Os/Mutex.hpp>
#include "UsbTransport.hpp"

class UsbObexTransport;


class UsbSubSystem : public SubSystem
{
    typedef SubSystem Base;

    public:

        static UsbSubSystem* GetInstance() { return &m_instance; }

        virtual ~UsbSubSystem();

        virtual const WCHAR* GetName() const { return L"USB"; }

        virtual BootSequenceState InvokeAt() const;

        virtual void OnPowerUp();

        
        virtual void OnPowerDown();

        UsbTransport* GetUsbTransport() {
            return m_usb_transport;
        }

        
    private:

        UsbSubSystem();
        
        
    private:

        static UsbSubSystem m_instance;

        UsbTransport* m_usb_transport;
        UsbObexTransport* m_usb_obex_transport;

        Mutex m_mutex;
};

#endif  // AddOns_Usb_UsbSubSystem_hpp

