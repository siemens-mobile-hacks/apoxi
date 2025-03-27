/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class Charger {
#endif
    public:
        enum ChargerMsgType {
            ChargerRemoved, 
            ChargeBattery, 
            ChargingPaused, 
            ChargingResumed, 
            LowBattery, 
            BatteryIdError, 
            BatteryEmpty, 
            ChargeEndChargerIsDisconnected, 
            ChargeEndBatteryIsFull 
        };
    
        enum ChargerStatus {
            Disabled,                          
            WaitingForConnection,              
            ConnectedAndCharging,              
            ConnectedAndTemperatureProtection, 
            ConnectedAndBatteryFull,           
            DisconnectedAndBatteryFull,        
            DisconnectedAndBatteryNotFull,     
            ChargerDisabledBatteryIdError,     
            ChargerDisabledVoltageError        
        };

        virtual ~Charger();

        virtual const WCHAR* GetName() const;

        static ControlArg Control(INT command, ControlArg arg);

        static void Charge(BOOLEAN charge);

        static ChargerStatus GetStatus();

        static UINT8 GetCapacityStatus();

        static BOOLEAN IsChargerInserted(); 

        static INT16 GetBatteryVoltage();

        static void StartBatteryLoadListening();

        static void StopBatteryLoadListening();

        static BOOLEAN IsBatteryLow();

        static void SetUsbCharging(BOOLEAN enable);

        static BOOLEAN IsUsbChargingEnabled();

    private:
        static Charger m_charger;

        Charger();

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

