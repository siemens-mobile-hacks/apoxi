/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtActiveDeviceWindow_hpp)
#define BtActiveDeviceWindow_hpp

#include <Gui/Action.hpp>
#include <GuiExtensions/MmiWindow.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include <BtApp/BtApplicationRequests.hpp>

class BtActiveDeviceWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:
        BtActiveDeviceWindow();

        virtual ~BtActiveDeviceWindow();


        void Init();


        void SetActiveDevice(const BtDevice& active_device); 


        BtDevice& GetActiveDevice() { return m_active_device;}

    
    protected:

        virtual void OnOpen();


    private:


        BtDevice                m_active_device;

        TextBox                 m_text_box;

        WString                 m_device_name;
        
};


#endif /* BtActiveDeviceWindow_hpp */
