/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_SimpleAudioDevice_hpp)
#define Apoxi_AudioNewAPI_SimpleAudioDevice_hpp

#include <Audio/AudioDeviceBase.hpp>
#include <Audio/AudioActiveReference.hpp>

class AudioManager;

class SimpleAudioDevice : public AudioDeviceBase
{
    public:
        SimpleAudioDevice();
        virtual ~SimpleAudioDevice();

        virtual BOOLEAN Enable(BOOLEAN suspend_all_others = FALSE) = 0;

        virtual BOOLEAN Disable() = 0;

        BOOLEAN IsEnabled() const;
 
    protected:
        //Only one of these devices can be active at once.
        //so we store an AudioActiveReference here, to keep the resources allocated.
        //TODO: Maybe only one of the SimpleAudioDevices can be active at once
        // if so then we need to remember which one is active and prevent another one becoming active.
        void SetStatus(BOOLEAN enable);

        SharedPtr<AudioActiveReference> m_active_reference;
        BOOLEAN m_enabled;
};

#endif  // Apoxi_AudioNewAPI_SimpleAudioDevice_hpp


