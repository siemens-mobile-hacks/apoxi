/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_Devices_Win32_Led_hpp)
#define Apoxi_Devices_Win32_Led_hpp

#include <Devices/AbstractDevice.hpp>

class Led : public AbstractDevice {
    typedef AbstractDevice Base;
    
    public:
        #if !defined(APOXI_LED_NEW_INTERFACE)
            enum Event {
                Call,
                ReceivingCall,
                CallUnanswered,
                Mail,
                Service,
                NoService,
                LimitedService,
                PowerOn,
                PowerOff,
                ReceivedCallConnected,
                SmsReceiving,
                SmsSending,
                AlarmOngoing,
                AlarmStopped,
                BatteryLow,
                ChargerDisconnected,
                ChargerConnected,
                ChargeComplete,
            };

            enum Color {
                Blue,
                Red,
                Green,
                Magenta,
                Cyan,
                Yellow,
                White,
                NoOfColors,
                InvalidColor,
            };

            enum Action {
                On,
                Off,
                Flash,
                ColorStream,
            };

            enum Intensity {
                NoCurrent,
                Minimum,
                Low,
                LessThanNormal,
                Normal,
                MoreThanNormal,
                High,
                Maximum,
            };
        #endif

    #include <Devices/LedInterface.hpp>

    protected:
        #if defined(APOXI_LED_NEW_INTERFACE)
            virtual void OnStart();
        #endif
        
    private: 
        static const INT c_max_colorstream_length;
};

#endif  // Apoxi_Devices_Win32_Led_hpp

