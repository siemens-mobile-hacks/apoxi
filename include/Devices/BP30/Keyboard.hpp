/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_Bp30_Keyboard_hpp)
#define Apoxi_Devices_Bp30_Keyboard_hpp

#include <Devices/AbstractDevice.hpp>

class Keyboard : public AbstractDevice {
    typedef AbstractDevice Base;

    #include <Devices/KeyboardInterface.hpp>

    protected:
        virtual void OnStart();

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

        static void SetIllumination(BOOLEAN illumination);
        static void OnIlluminationTimer(void *arg);
};

/*  ------------------------------------------------------------------------
    IsLocked
    ------------------------------------------------------------------------ */
inline BOOLEAN Keyboard::IsLocked() 
{ 
    return m_bits.locked; 
}

/*  ------------------------------------------------------------------------
    IsMultiKeyMode
    ------------------------------------------------------------------------ */
inline BOOLEAN Keyboard::IsMultiKeyMode() 
{ 
    return (BOOLEAN)m_bits.multi_key_mode; 
}

/*  ------------------------------------------------------------------------
    SetIlluminationTimeout
    ------------------------------------------------------------------------ */
inline void Keyboard::SetIlluminationTimeout(UINT32 timeout) 
{ 
    m_illumination_timeout = timeout; 
}

/*  ------------------------------------------------------------------------
    GetIlluminationMode
    ------------------------------------------------------------------------ */
inline Keyboard::IlluminationMode Keyboard::GetIlluminationMode()
{
    return static_cast<IlluminationMode>(m_bits.illumination_mode);
}

/*  ------------------------------------------------------------------------
    IsIlluminationOn
    ------------------------------------------------------------------------ */
inline BOOLEAN Keyboard::IsIlluminationOn() 
{ 
    return (BOOLEAN)m_bits.illumination_status; 
}

#endif  // Apoxi_Devices_Bp30_Keyboard_hpp

