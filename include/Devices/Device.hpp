/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Device_hpp)
#define Apoxi_Device_hpp

#if defined(APOXI_RTOS_WIN32)
    #include <Devices/Win32/AmplifierAudioDevice.hpp>
    #include <Devices/Win32/KeyToneAudioDevice.hpp>
    #include <Devices/Win32/MiscAudioDevice.hpp>
    #include <Devices/Win32/Mp3AudioDevice.hpp>
    #include <Devices/Win32/RingerAudioDevice.hpp>
    #include <Devices/Win32/SpeechAudioDevice.hpp>
    #include <Devices/Win32/ToneAudioDevice.hpp>
    #include <Devices/Win32/VoiceMemoAudioDevice.hpp>
    #include <Devices/Win32/GenericAudioDevice.hpp>
    #if defined(APOXI_COMPAT_2_6_0) 
    #include <Devices/Win32/Audio.hpp>
    #endif
    #include <Devices/Win32/VideoChannel.hpp>
    #if defined(APOXI_CAMERA_SUPPORT)
        #include <Devices/Win32/StillCamera.hpp>
        #include <Devices/Win32/VideoCamera.hpp>
    #endif

#elif defined(APOXI_PLATFORM_BP30)
    #if defined(APOXI_COMPAT_2_6_0) 
    #include <Devices/BP30/Audio.hpp>
    #endif
    #include <Devices/BP30/VideoChannel.hpp>
    #if defined(APOXI_CAMERA_SUPPORT)   
        #include <Devices/BP30/Camera.hpp>
        //#include <Devices/Bp30/VideoCamera.hpp>
    #endif
    
#elif defined(APOXI_PLATFORM_MPE)
    #if defined(APOXI_COMPAT_2_6_0) 
    #include <Devices/MPE/Audio.hpp>
    #endif
    #include <Devices/MPE/VideoChannel.hpp>
    #if defined(APOXI_CAMERA_SUPPORT)   
        #include <Devices/MPE/StillCamera.hpp>
        #include <Devices/MPE/VideoCamera.hpp>
    #endif

#elif defined(APOXI_PLATFORM_MPEU)
    #if defined(APOXI_COMPAT_2_6_0) 
    #include <Devices/MPEU/Audio.hpp>
    #endif
    #include <Devices/MPEU/VideoChannel.hpp>
    #if defined(APOXI_CAMERA_SUPPORT)   
        #include <Devices/MPEU/StillCamera.hpp>
        #include <Devices/MPEU/VideoCamera.hpp>
    #endif

#elif defined(APOXI_PLATFORM_MP1U)
    #if defined(APOXI_COMPAT_2_6_0) 
    #include <Devices/SGold/Audio.hpp>
    #endif
    #include <Devices/SGold/VideoChannel.hpp>
    #if defined(APOXI_CAMERA_SUPPORT)   
        #include <Devices/SGold/Camera.hpp>
        #include <Devices/SGold/VideoCamera.hpp>
    #endif
    
#else
    #error UNDEFINED PLATFORM
#endif

    #include <Devices/Charger.hpp>
    #include <Devices/Display.hpp>
#include <Devices/Keyboard.hpp>
    #include <Devices/Led.hpp>
    #include <Devices/RealTimeClock.hpp>

    #include <Devices/ChargerMsgTypes.hpp>

    // ToDo: check if all are necessary
    #include <Devices/AudioDeviceManager.hpp>
    #include <Devices/AudioActiveReference.hpp>
    #include <Devices/AudioReference.hpp>
    #include <Devices/CustomRingerAudioReference.hpp>
    #include <Devices/CustomSmafPhraseAudioReference.hpp>
    #include <Devices/CustomToneAudioReference.hpp>
    #include <Devices/PresetAudioReference.hpp>
    #include <Devices/RingerAudioReference.hpp>
    #include <Devices/ToneAudioReference.hpp>
    #include <Devices/VoiceMemoAudioReference.hpp>
    #include <Devices/AudioPresetStore.hpp>

#endif // Apoxi_Device_hpp

