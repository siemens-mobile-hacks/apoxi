/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(MiscAudioDevice_hpp)
#define MiscAudioDevice_hpp

#include <Devices/AbstractDevice.hpp>         
#include <Auxiliary/Lib.hpp>

class MiscAudioDevice : public AbstractDevice {
    public:
        virtual const WCHAR* GetName() const;

        enum Accessory {
            AccessoryNormal,
            AccessoryHeadset,
            AccessoryStereoPhones,
            AccessoryBtHeadset,
            AccessoryCarKit
        };
        
        struct PowerStatus {
            BOOLEAN speech          : 1; 
            BOOLEAN amplifier       : 1; 
            BOOLEAN ringer          : 1; 
            BOOLEAN vibrator        : 1; 
            BOOLEAN radio           : 1; 
            BOOLEAN mp3_player      : 1; 
            BOOLEAN vm_play         : 1; 
            BOOLEAN vm_rec          : 1; 
        };

        struct AvailableHW {
            BOOLEAN speech          : 1; 
            BOOLEAN amplifier       : 1; 
            BOOLEAN ringer          : 1; 
            BOOLEAN tone_generator  : 1; 
            BOOLEAN radio           : 1; 
            BOOLEAN mp3_player      : 1; 
            BOOLEAN vm_play         : 1; 
            BOOLEAN vm_rec          : 1; 
        };

        static PowerStatus GetPowerStatus();

        static AvailableHW GetAvailableHW();

        static void SetVmic(UINT8 status);

        static void SetAccessory(Accessory accessory);

        static void RestartHf();

        static void CheckTime();
};  

#endif // MiscAudioDevice_hpp


