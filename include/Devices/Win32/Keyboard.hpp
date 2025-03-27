/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_Devices_Win32_Keyboard_hpp)
#define Apoxi_Devices_Win32_Keyboard_hpp

#include <Devices/AbstractDevice.hpp>

class Keyboard : public AbstractDevice {
    typedef AbstractDevice Base;

    #include <Devices/KeyboardInterface.hpp>

    private:
        struct BitStruct {
            UINT locked                 : 1;
            UINT multi_key_mode         : 1;
            UINT illumination_status    : 1;
            UINT illumination_mode      : 2;
        };
        
        static BitStruct m_bits;
        static UINT32 m_illumination_timeout;
        static SystemTimer m_illumination_timer;
        static KeyCode m_key_state;

        static void SetIllumination(BOOLEAN illumination);
        static void OnIlluminationTimer(void *arg);
};

inline BOOLEAN Keyboard::IsLocked() 
{ 
    return m_bits.locked; 
}

inline void Keyboard::SetMultiKeyMode(BOOLEAN /* enable */) 
{
}

inline BOOLEAN Keyboard::IsMultiKeyMode() 
{ 
    return FALSE; 
}

inline void Keyboard::SetIlluminationTimeout(UINT32 timeout) 
{ 
    m_illumination_timeout = timeout; 
}

inline Keyboard::IlluminationMode Keyboard::GetIlluminationMode() 
{ 
    return static_cast<IlluminationMode>(m_bits.illumination_mode);
}

inline BOOLEAN Keyboard::IsIlluminationOn() 
{ 
    return m_bits.illumination_status; 
}

#endif  // Apoxi_Devices_Win32_Keyboard_hpp

