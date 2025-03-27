/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Mp3AudioDevice_hpp)
#define Mp3AudioDevice_hpp

#include "GenericAudioDevice.hpp"

class Mp3AudioDevice : public GenericAudioDevice {
    public:
        struct StartParam {
        };

        Mp3AudioDevice();
        virtual ~Mp3AudioDevice();  

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio);

        void SetStartParam(const StartParam* p_start_param);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        

        void AudioReturnSuspend();

        AudioReturnCode Resume();

        AudioReturnCode Seek();

        AudioReturnCode Set(UINT16 seconds);

    private:
        StartParam m_start_param;
        BOOLEAN m_start_param_set;
};
#endif // Mp3AudioDevice_hpp


