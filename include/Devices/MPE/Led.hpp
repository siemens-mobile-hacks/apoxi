/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_Mpe_Led_hpp)
#define Apoxi_Devices_Mpe_Led_hpp

#include <Devices/AbstractDevice.hpp>
#include <stack/driver.h>

class Led : public AbstractDevice {
    typedef AbstractDevice Base;
    
    public:
        #if !defined(APOXI_LED_NEW_INTERFACE)
            enum Event {
                Call = led_call,                /* stored in eep  */
                ReceivingCall = led_receiving_call,     /* stored in eep  */
                CallUnanswered = led_call_unanswered,       /* stored in eep  */
                Mail = led_mail,                /* stored in eep  */
                Service = led_service,          /* stored in eep  */
                NoService = led_no_service,         /* stored in eep  */
                LimitedService = led_limited_service,
                PowerOn = led_power_on,
                PowerOff = led_power_off,
                ReceivedCallConnected = led_received_call_connected,
                SmsReceiving = led_sms_receiving,
                SmsSending = led_sms_sending,
                AlarmOngoing = led_alarm_ongoing,
                AlarmStopped = led_alarm_stopped,
                BatteryLow = led_battery_low,
                ChargerDisconnected = led_charger_disconnected,
                ChargerConnected = led_charger_connected,
                ChargeComplete = led_charge_complete
            };

            enum Color {
                Blue = led_blue,           
                Red = led_red,            
                Green = led_green,          
                Magenta = led_blue_red,        /* magenta */
                Cyan = led_blue_green,      /* cyan    */
                Yellow = led_red_green,       /* yellow  */
                White = led_red_blue_green,  /* white   */
                NoOfColors = led_nof_colors,     
                InvalidColor,
            };


            enum Action {
                On = LED_ON,
                Off = LED_OFF,
                Flash = LED_FLASH,
                ColorStream = LED_COLORSTREAM,
            };

            #if defined (USE_SMPOWER)
                enum Intensity {
                    NoCurrent = led_no_current, /*   0 mA */
                    Minimum = led_20_ma,        /*  20 mA */
                    Low = led_40_ma,            /*  40 mA */
                    LessThanNormal = led_60_ma, /*  60 mA */
                    Normal = led_80_ma,         /*  80 mA */
                    MoreThanNormal = led_100_ma,/* 100 mA */
                    High = led_120_ma,          /* 120 mA */
                    Maximum = led_140_ma        /* 140 mA */
                };
            #else
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
        #endif

    #include <Devices/LedInterface.hpp>

    protected:
        #if defined(APOXI_LED_NEW_INTERFACE)
            virtual void OnStart();
        #endif
        
    private: 
        static const INT c_max_colorstream_length;
};

#endif  // Apoxi_Devices_Mpe_Led_hpp

