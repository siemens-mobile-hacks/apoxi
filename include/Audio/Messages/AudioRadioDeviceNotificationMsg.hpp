/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\wickhara_apoxitest_host\lnz_apoxi\Apoxi\Audio\Messages\AudioTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apoxi_Audio_AudioRadioDeviceNotificationMsg_hpp)
#define Apoxi_Audio_AudioRadioDeviceNotificationMsg_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Audio/RadioAudioDevice.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AudioRadioDeviceNotificationMsg
    ====================================================================== */

class AudioRadioDeviceNotificationMsg : public Message {
    public:
        AudioRadioDeviceNotificationMsg(const RadioAudioDevice::NotificationType& type);
        virtual ~AudioRadioDeviceNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const RadioAudioDevice::NotificationType& GetType() const { return m_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9007
            };
        
    private:
        static const MsgMetaData m_meta_data;
        RadioAudioDevice::NotificationType m_type;
        
    };

#endif // Apoxi_Audio_AudioRadioDeviceNotificationMsg_hpp

