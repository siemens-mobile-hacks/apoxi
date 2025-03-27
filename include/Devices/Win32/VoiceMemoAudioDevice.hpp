/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/
#if !defined(VoiceMemoAudioDevice_hpp)
#define VoiceMemoAudioDevice_hpp

#include "GenericAudioDevice.hpp"

//This class is deprecated. Murray.

class VoiceMemoAudioDevice : public GenericAudioDevice {
    public:
        
        enum VmPlayMode {
            VmModePlayback,
            VmModeRec
        };

        enum AudioVmMode {
            VmModeStandby,  
            VmModeTch       
        };

        enum MediaType  {
            MediaTypeFfs, 
            MediaRam,   
            MediaMmc
        };

        enum DspFormat {
            DspFormatFullRate,
            DspFormatAmr
        };

        enum Rate {
            Rate0,  
            Rate1,  
            Rate2,  
            Rate3,  
            Rate4,  
            Rate5,  
            Rate6,  
            Rate7   
        };

        struct StartParam {
            union {
                Rate rate;              
                DspFormat dsp_format;
            };
            AudioVmMode audio_vm_mode;  
            MediaType media_type;
            UINT16* file_handle;
            UINT16 file_handle_size;
        };

        VoiceMemoAudioDevice(VmPlayMode vm_play_mode = VmModePlayback);

        virtual ~VoiceMemoAudioDevice();    

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio);

        void SetStartParam(const StartParam* p_start_param);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);

    private:
        VmPlayMode m_vm_play_mode;

        StartParam m_start_param;
        BOOLEAN m_start_param_set;
};

#endif // VoiceMemoAudioDevice_hpp


