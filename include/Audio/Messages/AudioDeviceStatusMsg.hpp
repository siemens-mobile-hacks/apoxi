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


#if !defined(Apoxi_Audio_AudioDeviceStatusMsg_hpp)
#define Apoxi_Audio_AudioDeviceStatusMsg_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Audio/AudioDeviceManager.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AudioDeviceStatusMsg
    ====================================================================== */

class AudioDeviceStatusMsg : public Message {
    public:
        AudioDeviceStatusMsg(const AudioDeviceManager::AudioDeviceID& device_id, const AudioDeviceBase::AudioDeviceStatus& device_status);
        virtual ~AudioDeviceStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDeviceId(const AudioDeviceManager::AudioDeviceID& device_id) { m_device_id = device_id; }
        const AudioDeviceManager::AudioDeviceID& GetDeviceId() const { return m_device_id; }
        void SetDeviceStatus(const AudioDeviceBase::AudioDeviceStatus& device_status) { m_device_status = device_status; }
        const AudioDeviceBase::AudioDeviceStatus& GetDeviceStatus() const { return m_device_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        AudioDeviceManager::AudioDeviceID m_device_id;
        AudioDeviceBase::AudioDeviceStatus m_device_status;
        
    };

#endif // Apoxi_Audio_AudioDeviceStatusMsg_hpp

