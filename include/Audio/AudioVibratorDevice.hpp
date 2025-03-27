/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioVibratorDevice_hpp)
#define Apoxi_AudioNewAPI_AudioVibratorDevice_hpp

#include <Kernel/Types.hpp>
//#include <Apoxi/Auxiliary/NonCloneable.hpp>
#include <Auxiliary/SharedPtr.hpp>
#include <Audio/AudioDeviceBase.hpp>
#include <Audio/DwdDevice.hpp>

/*** AudioVibratorDevice class is used to control Vibrator only for E-Gold based platforms
 * On all other platforms use the VibratorDevice class. 
 * VibratorDevice class unlike the AudioVibratorDevice class is not part of ApoxiAudio.
 * Refer to Vibrator device reference manual
 */
class AudioVibratorDevice : public AudioDeviceBase, public DwdDevice
{
    public:

        enum VibratorMode
        {
            VibratorModeAsync1,
            VibratorModeAsync2,
            VibratorModeSync1,
            VibratorModeSync2
        };

        //TODO: Are these sensible default values? Murray.
        BOOLEAN StartVibrator(VibratorMode mode = VibratorModeAsync2,  INT16 on = -1, INT16 off = 0);

        void StopVibrator();          
        
        BOOLEAN IsVibratorOn();
        
        virtual AudioSourceType GetSource() const; //override

        virtual BOOLEAN Play_Allocate(AudioActiveReference &active_reference);

    protected:

        typedef INT8 AudReturnCode;

        SharedPtr<AudioActiveReference> m_active_ref;

        virtual UINT16 GetDeviceID() const; //overwrite
};


#endif  // Apoxi_AudioNewAPI_VibratorDevice_hpp


