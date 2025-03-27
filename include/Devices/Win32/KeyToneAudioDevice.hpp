/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/
#if !defined(KeyToneAudioDevice_hpp)
#define KeyToneAudioDevice_hpp

#include "GenericAudioDevice.hpp"

class KeyToneAudioDevice : public GenericAudioDevice {
    public:

        enum KeyTone {
            KeyTone1,
            KeyTone2,
            KeyTone3,
            KeyTone4,
            KeyTone5
        };

        struct StartParam {
            StartParam() {
                key_tone = KeyTone1;
                mix_factor = 0x4000;
            };
            KeyTone key_tone;   
            UINT16 mix_factor;  
        };

        KeyToneAudioDevice();
        virtual ~KeyToneAudioDevice();  

        virtual const WCHAR* GetName() const;


        virtual AudioReturnCode Init(Priority prio);

        void SetStartParam(const StartParam* p_start_param);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        

    protected:
        INT ConvertKeyTone2INT(KeyTone key_tone);

    private:
        StartParam m_start_param;
        BOOLEAN m_start_param_set;
};

#endif // KeyToneAudioDevice_hpp


