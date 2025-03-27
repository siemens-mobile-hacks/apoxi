/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "neudorfe_mmfr_pu_dv\lnz_apoxi\Apoxi\Audio\Messages\AudioTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Apoxi_Audio_AudioMessages_hpp)
#define Apoxi_Audio_AudioMessages_hpp
#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Audio/AudioAccessoryDetails.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class AudioUserDefinedMsg
    ====================================================================== */
class AudioUserDefinedMsg : public Message {
    public:
        AudioUserDefinedMsg(UINT8 messageID, UINT16 senderID, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
        virtual ~AudioUserDefinedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMessageID(UINT8 messageID) { m_messageID = messageID; }
        UINT8 GetMessageID() const { return m_messageID; }
        void SetSenderID(UINT16 senderID) { m_senderID = senderID; }
        UINT16 GetSenderID() const { return m_senderID; }
        void SetParam1(UINT32 param1) { m_param1 = param1; }
        UINT32 GetParam1() const { return m_param1; }
        void SetParam2(UINT32 param2) { m_param2 = param2; }
        UINT32 GetParam2() const { return m_param2; }
        void SetParam3(UINT32 param3) { m_param3 = param3; }
        UINT32 GetParam3() const { return m_param3; }
        void SetParam4(UINT32 param4) { m_param4 = param4; }
        UINT32 GetParam4() const { return m_param4; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9012
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT8 m_messageID;
        UINT16 m_senderID;
        UINT32 m_param1;
        UINT32 m_param2;
        UINT32 m_param3;
        UINT32 m_param4;
        
    };
/*  ======================================================================
    Class AudioRecordingStoppedMsg
    ====================================================================== */
class AudioRecordingStoppedMsg : public Message {
    public:
        AudioRecordingStoppedMsg(const SharedPtr<AudioActiveReference>& active_reference);
        virtual ~AudioRecordingStoppedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveReference(const SharedPtr<AudioActiveReference>& active_reference) { m_active_reference = active_reference; }
        const SharedPtr<AudioActiveReference>& GetActiveReference() const { return m_active_reference; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9013
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioActiveReference> m_active_reference;
        
    };
/*  ======================================================================
    Class AudioAccessoryConnectedMsg
    ====================================================================== */
class AudioAccessoryConnectedMsg : public Message {
    public:
        AudioAccessoryConnectedMsg(const AudioAccessoryDetails::AudioAccessoryConfigurationType& accessory_configuration_type, BOOLEAN connected);
        virtual ~AudioAccessoryConnectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAccessoryConfigurationType(const AudioAccessoryDetails::AudioAccessoryConfigurationType& accessory_configuration_type) { m_accessory_configuration_type = accessory_configuration_type; }
        const AudioAccessoryDetails::AudioAccessoryConfigurationType& GetAccessoryConfigurationType() const { return m_accessory_configuration_type; }
        void SetConnected(BOOLEAN connected) { m_connected = connected; }
        BOOLEAN IsConnected() const { return m_connected; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9014
            };
        
    private:
        static const MsgMetaData m_meta_data;
        AudioAccessoryDetails::AudioAccessoryConfigurationType m_accessory_configuration_type;
        BOOLEAN m_connected;
        
    };
/*  ======================================================================
    Class AudioFmRadioSeekMsg
    ====================================================================== */
class AudioFmRadioSeekMsg : public Message {
    public:
        AudioFmRadioSeekMsg(BOOLEAN success, UINT32 frequency);
        virtual ~AudioFmRadioSeekMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        BOOLEAN IsSuccess() const { return m_success; }
        UINT32 GetFrequency() const { return m_frequency; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9015
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_success;
        UINT32 m_frequency;
        
    };
/*  ======================================================================
    Class AudioFmRadioRssiMsg
    ====================================================================== */
class AudioFmRadioRssiMsg : public Message {
    public:
        AudioFmRadioRssiMsg(UINT8 signalLevel, BOOLEAN stereo);
        virtual ~AudioFmRadioRssiMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT8 GetSignalLevel() const { return m_signalLevel; }
        BOOLEAN IsStereo() const { return m_stereo; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9016
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT8 m_signalLevel;
        BOOLEAN m_stereo;
        
    };
/*  ======================================================================
    Class AudioFmRadioRdsRawDataMsg
    ====================================================================== */
class AudioFmRadioRdsRawDataMsg : public Message {
    public:
        AudioFmRadioRdsRawDataMsg(UINT8* buffer, UINT16 buffer_size);
        virtual ~AudioFmRadioRdsRawDataMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT8* GetBuffer() const { return m_buffer; }
        UINT16 GetBufferSize() const { return m_buffer_size; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9017
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT8* m_buffer;
        UINT16 m_buffer_size;
        
    };
/*  ======================================================================
    Class AudioFmRadioRdsStationNameMsg
    ====================================================================== */
class AudioFmRadioRdsStationNameMsg : public Message {
    public:
        AudioFmRadioRdsStationNameMsg(const WString& stationName, BOOLEAN trafficAnnouncementSet);
        virtual ~AudioFmRadioRdsStationNameMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetStationName() const { return m_stationName; }
        BOOLEAN IsTrafficAnnouncementSet() const { return m_trafficAnnouncementSet; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9018
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_stationName;
        BOOLEAN m_trafficAnnouncementSet;
        
    };
/*  ======================================================================
    Class AudioFmRadioRdsRadioTextMsg
    ====================================================================== */
class AudioFmRadioRdsRadioTextMsg : public Message {
    public:
        AudioFmRadioRdsRadioTextMsg(const WString& radioText);
        virtual ~AudioFmRadioRdsRadioTextMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetRadioText() const { return m_radioText; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9019
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_radioText;
        
    };
/*  ======================================================================
    Class AudioFmRadioRdsInfoMsg
    ====================================================================== */
class AudioFmRadioRdsInfoMsg : public Message {
    public:
        AudioFmRadioRdsInfoMsg(UINT16 programIdentifier, UINT8 programType, BOOLEAN trafficProgramSet);
        virtual ~AudioFmRadioRdsInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT16 GetProgramIdentifier() const { return m_programIdentifier; }
        UINT8 GetProgramType() const { return m_programType; }
        BOOLEAN IsTrafficProgramSet() const { return m_trafficProgramSet; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9020
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT16 m_programIdentifier;
        UINT8 m_programType;
        BOOLEAN m_trafficProgramSet;
        
    };
/*  ======================================================================
    Class AudioFmRadioRdsAlternativeFrequenciesMsg
    ====================================================================== */
class AudioFmRadioRdsAlternativeFrequenciesMsg : public Message {
    public:
        AudioFmRadioRdsAlternativeFrequenciesMsg(UINT8 numberOfFrequencies, UINT32* frequencies);
        virtual ~AudioFmRadioRdsAlternativeFrequenciesMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT8 GetNumberOfFrequencies() const { return m_numberOfFrequencies; }
        UINT32* GetFrequencies() const { return m_frequencies; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9021
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT8 m_numberOfFrequencies;
        UINT32* m_frequencies;
        
    };
/*  ======================================================================
    Class AudioFastForwardStartedMsg
    ====================================================================== */
class AudioFastForwardStartedMsg : public Message {
    public:
        AudioFastForwardStartedMsg(const SharedPtr<AudioActiveReference>& active_reference);
        virtual ~AudioFastForwardStartedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveReference(const SharedPtr<AudioActiveReference>& active_reference) { m_active_reference = active_reference; }
        const SharedPtr<AudioActiveReference>& GetActiveReference() const { return m_active_reference; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9022
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioActiveReference> m_active_reference;
        
    };
/*  ======================================================================
    Class AudioRewindStartedMsg
    ====================================================================== */
class AudioRewindStartedMsg : public Message {
    public:
        AudioRewindStartedMsg(const SharedPtr<AudioActiveReference>& active_reference);
        virtual ~AudioRewindStartedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveReference(const SharedPtr<AudioActiveReference>& active_reference) { m_active_reference = active_reference; }
        const SharedPtr<AudioActiveReference>& GetActiveReference() const { return m_active_reference; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9023
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioActiveReference> m_active_reference;
        
    };
#endif // Apoxi_Audio_AudioMessages_hpp

