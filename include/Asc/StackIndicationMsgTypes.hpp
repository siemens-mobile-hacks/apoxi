/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\grossau_latest_sv\lnz_apoxi\Apoxi\Asc\StackIndicationMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Asc_StackIndicationMsgTypes_hpp)
#define Asc_StackIndicationMsgTypes_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/Accessory.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/LockTypes.hpp>
#include <Apc/AtcTypes.hpp>
#include <Asc/Types.hpp>
#include <Asc/CallHdl.hpp>
#include <Asc/MptyCallHdl.hpp>
#include <Asc/MsgArgs.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/TimeZone.hpp>
#include <Asc/SsMessage.hpp>
#include <Asc/InputParser.hpp>
#include <Auxiliary/Vector.hpp>
#include <Asc/SsBaseHandler.hpp>
#include <Asc/UssdHandler.hpp>
#include <Asc/CallBarringHandler.hpp>
#include <Asc/StackControl.hpp>
#include <Asc/PdpContextManager.hpp>
#include <Asc/PdpContext.hpp>
#include <Apc/SimTkStackMsgArgs.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/PlmnScanList.hpp>
#include <Apc/MiscStackMsgArgs.hpp>
#include <Apc/NetworkStackMsgArgs.hpp>
#include <Apc/SmsStackMsgArgs.hpp>
#include <Apc/CbsStackMsgArgs.hpp>
#include <Apc/CdStackMsgArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SimStateChangedMsg
    ====================================================================== */

class SimStateChangedMsg : public Message {
    public:
        SimStateChangedMsg(const SimIndicator& sim_indicator);
        virtual ~SimStateChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSimIndicator(const SimIndicator& sim_indicator) { m_sim_indicator = sim_indicator; }
        const SimIndicator& GetSimIndicator() const { return m_sim_indicator; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18700
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimIndicator m_sim_indicator;
        
    };


/*  ======================================================================
    Class SimLockStatusMsg
    ====================================================================== */

class SimLockStatusMsg : public Message {
    public:
        SimLockStatusMsg(const SecLockResult& lock_result);
        virtual ~SimLockStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetLockResult(const SecLockResult& lock_result) { m_lock_result = lock_result; }
        const SecLockResult& GetLockResult() const { return m_lock_result; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18701
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SecLockResult m_lock_result;
        
    };


/*  ======================================================================
    Class GprsStatusMsg
    ====================================================================== */

class GprsStatusMsg : public Message {
    public:
        GprsStatusMsg(BOOLEAN attached);
        virtual ~GprsStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAttached(BOOLEAN attached) { m_attached = attached; }
        BOOLEAN IsAttached() const { return m_attached; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18702
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_attached;
        
    };


/*  ======================================================================
    Class CallEventMsg
    ====================================================================== */

class CallEventMsg : public Message {
    public:
        CallEventMsg(const CallEvent& event);
        virtual ~CallEventMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetEvent(const CallEvent& event) { m_event = event; }
        const CallEvent& GetEvent() const { return m_event; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18703
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallEvent m_event;
        
    };


/*  ======================================================================
    Class CallControlIndMsg
    ====================================================================== */

class CallControlIndMsg : public Message {
    public:
        CallControlIndMsg(const CallControlSetupIndArg& arg);
        virtual ~CallControlIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallControlSetupIndArg& arg) { m_arg = arg; }
        const CallControlSetupIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18704
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallControlSetupIndArg m_arg;
        
    };


/*  ======================================================================
    Class SsControlIndMsg
    ====================================================================== */

class SsControlIndMsg : public Message {
    public:
        SsControlIndMsg(const CallControlSsIndArg& arg);
        virtual ~SsControlIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallControlSsIndArg& arg) { m_arg = arg; }
        const CallControlSsIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18705
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallControlSsIndArg m_arg;
        
    };


/*  ======================================================================
    Class UssdControlIndMsg
    ====================================================================== */

class UssdControlIndMsg : public Message {
    public:
        UssdControlIndMsg(const CallControlUssdIndArg& arg);
        virtual ~UssdControlIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallControlUssdIndArg& arg) { m_arg = arg; }
        const CallControlUssdIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18706
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallControlUssdIndArg m_arg;
        
    };


/*  ======================================================================
    Class SmsControlIndMsg
    ====================================================================== */

class SmsControlIndMsg : public Message {
    public:
        SmsControlIndMsg(const SmsControlIndArg& arg);
        virtual ~SmsControlIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SmsControlIndArg& arg) { m_arg = arg; }
        const SmsControlIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18707
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsControlIndArg m_arg;
        
    };


/*  ======================================================================
    Class ChvChangedMsg
    ====================================================================== */

class ChvChangedMsg : public Message {
    public:
        ChvChangedMsg(const ChvAction& chv_action, const ChvNo& chvno, const ChvStatus& status);
        virtual ~ChvChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetChvAction(const ChvAction& chv_action) { m_chv_action = chv_action; }
        const ChvAction& GetChvAction() const { return m_chv_action; }
        void SetChvno(const ChvNo& chvno) { m_chvno = chvno; }
        const ChvNo& GetChvno() const { return m_chvno; }
        void SetStatus(const ChvStatus& status) { m_status = status; }
        const ChvStatus& GetStatus() const { return m_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18708
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ChvAction m_chv_action;
        ChvNo m_chvno;
        ChvStatus m_status;
        
    };


/*  ======================================================================
    Class PdpContextActivationStatusMsg
    ====================================================================== */

class PdpContextActivationStatusMsg : public Message {
    public:
        PdpContextActivationStatusMsg(INT contextId, const PdpContext::ActivationStatus& activationStatus);
        virtual ~PdpContextActivationStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetContextId(INT contextId) { m_contextId = contextId; }
        INT GetContextId() const { return m_contextId; }
        void SetActivationStatus(const PdpContext::ActivationStatus& activationStatus) { m_activationStatus = activationStatus; }
        const PdpContext::ActivationStatus& GetActivationStatus() const { return m_activationStatus; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18709
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_contextId;
        PdpContext::ActivationStatus m_activationStatus;
        
    };


/*  ======================================================================
    Class GprsAttachStatusMsg
    ====================================================================== */

class GprsAttachStatusMsg : public Message {
    public:
        GprsAttachStatusMsg(const PdpContextManager::AttachStatus& attachStatus);
        virtual ~GprsAttachStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAttachStatus(const PdpContextManager::AttachStatus& attachStatus) { m_attachStatus = attachStatus; }
        const PdpContextManager::AttachStatus& GetAttachStatus() const { return m_attachStatus; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18710
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PdpContextManager::AttachStatus m_attachStatus;
        
    };


/*  ======================================================================
    Class ExternalPdpContextInfoMsg
    ====================================================================== */

class ExternalPdpContextInfoMsg : public Message {
    public:
        ExternalPdpContextInfoMsg(const PdpContext::Id& contextId, const PdpContextManager::ExternalContextState& contextState);
        virtual ~ExternalPdpContextInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const PdpContext::Id& GetContextId() const { return m_contextId; }
        const PdpContextManager::ExternalContextState& GetContextState() const { return m_contextState; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18711
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PdpContext::Id m_contextId;
        PdpContextManager::ExternalContextState m_contextState;
        
    };


/*  ======================================================================
    Class CallAcceptMsg
    ====================================================================== */

class CallAcceptMsg : public Message {
    public:
        CallAcceptMsg(const CallHdl& call_hdl);
        virtual ~CallAcceptMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18712
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        
    };


/*  ======================================================================
    Class CallReleaseMsg
    ====================================================================== */

class CallReleaseMsg : public Message {
    public:
        CallReleaseMsg(const CallHdl& call_hdl);
        virtual ~CallReleaseMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18713
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        
    };


/*  ======================================================================
    Class MptyCallReleaseMsg
    ====================================================================== */

class MptyCallReleaseMsg : public Message {
    public:
        MptyCallReleaseMsg(const MptyCallHdl& call_hdl);
        virtual ~MptyCallReleaseMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const MptyCallHdl& GetCallHdl() const { return m_call_hdl; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18714
            };
        
    private:
        static const MsgMetaData m_meta_data;
        MptyCallHdl m_call_hdl;
        
    };


/*  ======================================================================
    Class CfuStatusMsg
    ====================================================================== */

class CfuStatusMsg : public Message {
    public:
        CfuStatusMsg(const CfuServiceArray& cfu_service_array);
        virtual ~CfuStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CfuServiceArray& GetCfuServiceArray() const { return m_cfu_service_array; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18715
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CfuServiceArray m_cfu_service_array;
        
    };


/*  ======================================================================
    Class SimErrorMsg
    ====================================================================== */

class SimErrorMsg : public Message {
    public:
        SimErrorMsg(const SimErrorCode& error_code);
        virtual ~SimErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetErrorCode(const SimErrorCode& error_code) { m_error_code = error_code; }
        const SimErrorCode& GetErrorCode() const { return m_error_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18716
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimErrorCode m_error_code;
        
    };


/*  ======================================================================
    Class NetworkInformationMsg
    ====================================================================== */

class NetworkInformationMsg : public Message {
    public:
        NetworkInformationMsg(const WString& network_name_long, const WString& network_name_short, BOOLEAN network_name_long_add_ci, BOOLEAN network_name_short_add_ci);
        virtual ~NetworkInformationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetNetworkNameLong(const WString& network_name_long) { m_network_name_long = network_name_long; }
        const WString& GetNetworkNameLong() const { return m_network_name_long; }
        void SetNetworkNameShort(const WString& network_name_short) { m_network_name_short = network_name_short; }
        const WString& GetNetworkNameShort() const { return m_network_name_short; }
        void SetNetworkNameLongAddCi(BOOLEAN network_name_long_add_ci) { m_network_name_long_add_ci = network_name_long_add_ci; }
        BOOLEAN IsNetworkNameLongAddCi() const { return m_network_name_long_add_ci; }
        void SetNetworkNameShortAddCi(BOOLEAN network_name_short_add_ci) { m_network_name_short_add_ci = network_name_short_add_ci; }
        BOOLEAN IsNetworkNameShortAddCi() const { return m_network_name_short_add_ci; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18601
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_network_name_long;
        WString m_network_name_short;
        BOOLEAN m_network_name_long_add_ci;
        BOOLEAN m_network_name_short_add_ci;
        
    };


/*  ======================================================================
    Class TimeZoneMsg
    ====================================================================== */

class TimeZoneMsg : public Message {
    public:
        TimeZoneMsg(const DateTime& datetime);
        virtual ~TimeZoneMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDatetime(const DateTime& datetime) { m_datetime = datetime; }
        const DateTime& GetDatetime() const { return m_datetime; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18602
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DateTime m_datetime;
        
    };


/*  ======================================================================
    Class LsaIdentityMsg
    ====================================================================== */

class LsaIdentityMsg : public Message {
    public:
        LsaIdentityMsg(BOOLEAN lsa_identifier_present, const LsaIdentifier& lsa_identifier);
        virtual ~LsaIdentityMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetLsaIdentifierPresent(BOOLEAN lsa_identifier_present) { m_lsa_identifier_present = lsa_identifier_present; }
        BOOLEAN IsLsaIdentifierPresent() const { return m_lsa_identifier_present; }
        void SetLsaIdentifier(const LsaIdentifier& lsa_identifier) { m_lsa_identifier = lsa_identifier; }
        const LsaIdentifier& GetLsaIdentifier() const { return m_lsa_identifier; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18609
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_lsa_identifier_present;
        LsaIdentifier m_lsa_identifier;
        
    };


/*  ======================================================================
    Class SiChannelOpenPromptReqMsg
    ====================================================================== */

class SiChannelOpenPromptReqMsg : public Message {
    public:
        SiChannelOpenPromptReqMsg(const SiChannelOpenPromptReqArg& arg);
        virtual ~SiChannelOpenPromptReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SiChannelOpenPromptReqArg& arg) { m_arg = arg; }
        const SiChannelOpenPromptReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18335
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SiChannelOpenPromptReqArg m_arg;
        
    };


/*  ======================================================================
    Class SiChannelCloseInfoIndMsg
    ====================================================================== */

class SiChannelCloseInfoIndMsg : public Message {
    public:
        SiChannelCloseInfoIndMsg(const SiChannelCloseInfoIndArg& arg);
        virtual ~SiChannelCloseInfoIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SiChannelCloseInfoIndArg& arg) { m_arg = arg; }
        const SiChannelCloseInfoIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18336
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SiChannelCloseInfoIndArg m_arg;
        
    };


/*  ======================================================================
    Class SiChannelSendInfoIndMsg
    ====================================================================== */

class SiChannelSendInfoIndMsg : public Message {
    public:
        SiChannelSendInfoIndMsg(const SiChannelSendInfoIndArg& arg);
        virtual ~SiChannelSendInfoIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SiChannelSendInfoIndArg& arg) { m_arg = arg; }
        const SiChannelSendInfoIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18337
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SiChannelSendInfoIndArg m_arg;
        
    };


/*  ======================================================================
    Class SiChannelReceiveInfoIndMsg
    ====================================================================== */

class SiChannelReceiveInfoIndMsg : public Message {
    public:
        SiChannelReceiveInfoIndMsg(const SiChannelReceiveInfoIndArg& arg);
        virtual ~SiChannelReceiveInfoIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SiChannelReceiveInfoIndArg& arg) { m_arg = arg; }
        const SiChannelReceiveInfoIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18338
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SiChannelReceiveInfoIndArg m_arg;
        
    };


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryChargingMsg
    ====================================================================== */

class BatteryChargingMsg : public Message {
    public:
        BatteryChargingMsg();
        virtual ~BatteryChargingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18011
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryLowMsg
    ====================================================================== */

class BatteryLowMsg : public Message {
    public:
        BatteryLowMsg();
        virtual ~BatteryLowMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18012
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryEmptyMsg
    ====================================================================== */

class BatteryEmptyMsg : public Message {
    public:
        BatteryEmptyMsg();
        virtual ~BatteryEmptyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18013
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryStopChargingMsg
    ====================================================================== */

class BatteryStopChargingMsg : public Message {
    public:
        BatteryStopChargingMsg(const ChargeEndReason& reason);
        virtual ~BatteryStopChargingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetReason(const ChargeEndReason& reason) { m_reason = reason; }
        const ChargeEndReason& GetReason() const { return m_reason; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18014
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ChargeEndReason m_reason;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryChargerRemovedMsg
    ====================================================================== */

class BatteryChargerRemovedMsg : public Message {
    public:
        BatteryChargerRemovedMsg();
        virtual ~BatteryChargerRemovedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18015
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryIdErrorMsg
    ====================================================================== */

class BatteryIdErrorMsg : public Message {
    public:
        BatteryIdErrorMsg();
        virtual ~BatteryIdErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18016
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryChargingPausedMsg
    ====================================================================== */

class BatteryChargingPausedMsg : public Message {
    public:
        BatteryChargingPausedMsg();
        virtual ~BatteryChargingPausedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18017
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


#ifdef APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class BatteryChargingResumedMsg
    ====================================================================== */

class BatteryChargingResumedMsg : public Message {
    public:
        BatteryChargingResumedMsg();
        virtual ~BatteryChargingResumedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18018
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif //APOXI_COMPAT_2_2_0


/*  ======================================================================
    Class AlarmMsg
    ====================================================================== */

class AlarmMsg : public Message {
    public:
        AlarmMsg();
        virtual ~AlarmMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18020
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class MinuteTickMsg
    ====================================================================== */

class MinuteTickMsg : public Message {
    public:
        MinuteTickMsg();
        virtual ~MinuteTickMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18021
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SignalStrengthLevelMsg
    ====================================================================== */

class SignalStrengthLevelMsg : public ContextMsg {
    public:
        SignalStrengthLevelMsg(ExecutionContext* context, const SignalStrengthLevel& signal_strength_level, const SignalStrengthMax& signal_strength_max);
        virtual ~SignalStrengthLevelMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSignalStrengthLevel(const SignalStrengthLevel& signal_strength_level) { m_signal_strength_level = signal_strength_level; }
        const SignalStrengthLevel& GetSignalStrengthLevel() const { return m_signal_strength_level; }
        void SetSignalStrengthMax(const SignalStrengthMax& signal_strength_max) { m_signal_strength_max = signal_strength_max; }
        const SignalStrengthMax& GetSignalStrengthMax() const { return m_signal_strength_max; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SignalStrengthLevel m_signal_strength_level;
        SignalStrengthMax m_signal_strength_max;
        
    };


/*  ======================================================================
    Class SignalQualityLevelMsg
    ====================================================================== */

class SignalQualityLevelMsg : public ContextMsg {
    public:
        SignalQualityLevelMsg(ExecutionContext* context, const SignalQualityLevel& signal_quality_level, const SignalQualityMax& signal_quality_max);
        virtual ~SignalQualityLevelMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSignalQualityLevel(const SignalQualityLevel& signal_quality_level) { m_signal_quality_level = signal_quality_level; }
        const SignalQualityLevel& GetSignalQualityLevel() const { return m_signal_quality_level; }
        void SetSignalQualityMax(const SignalQualityMax& signal_quality_max) { m_signal_quality_max = signal_quality_max; }
        const SignalQualityMax& GetSignalQualityMax() const { return m_signal_quality_max; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SignalQualityLevel m_signal_quality_level;
        SignalQualityMax m_signal_quality_max;
        
    };


/*  ======================================================================
    Class AccessoryIndMsg
    ====================================================================== */

class AccessoryIndMsg : public ContextMsg {
    public:
        AccessoryIndMsg(ExecutionContext* context, const Accessory& accessory);
        virtual ~AccessoryIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAccessory(const Accessory& accessory) { m_accessory = accessory; }
        const Accessory& GetAccessory() const { return m_accessory; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Accessory m_accessory;
        
    };


/*  ======================================================================
    Class RegistrationSuccessMsg
    ====================================================================== */

class RegistrationSuccessMsg : public ContextMsg {
    public:
        RegistrationSuccessMsg(ExecutionContext* context, const Plmn& plmn);
        virtual ~RegistrationSuccessMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18200
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Plmn m_plmn;
        
    };


/*  ======================================================================
    Class RegistrationChangeMsg
    ====================================================================== */

class RegistrationChangeMsg : public ContextMsg {
    public:
        RegistrationChangeMsg(ExecutionContext* context, const RegisterStatus& status, const RegisterRejectCause& reject_cause, BOOLEAN scan_active, const Plmn& plmn, const GsmErrorCause& gsm_error_cause);
        virtual ~RegistrationChangeMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetStatus(const RegisterStatus& status) { m_status = status; }
        const RegisterStatus& GetStatus() const { return m_status; }
        void SetRejectCause(const RegisterRejectCause& reject_cause) { m_reject_cause = reject_cause; }
        const RegisterRejectCause& GetRejectCause() const { return m_reject_cause; }
        void SetScanActive(BOOLEAN scan_active) { m_scan_active = scan_active; }
        BOOLEAN IsScanActive() const { return m_scan_active; }
        void SetPlmn(const Plmn& plmn) { m_plmn = plmn; }
        const Plmn& GetPlmn() const { return m_plmn; }
        void SetGsmErrorCause(const GsmErrorCause& gsm_error_cause) { m_gsm_error_cause = gsm_error_cause; }
        const GsmErrorCause& GetGsmErrorCause() const { return m_gsm_error_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18201
            };
        
    private:
        static const MsgMetaData m_meta_data;
        RegisterStatus m_status;
        RegisterRejectCause m_reject_cause;
        BOOLEAN m_scan_active;
        Plmn m_plmn;
        GsmErrorCause m_gsm_error_cause;
        
    };


/*  ======================================================================
    Class PlmnScanFinishedMsg
    ====================================================================== */

class PlmnScanFinishedMsg : public ContextMsg {
    public:
        PlmnScanFinishedMsg(ExecutionContext* context, BOOLEAN rejected, const PlmnScanList& plmn_scan_list);
        virtual ~PlmnScanFinishedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetRejected(BOOLEAN rejected) { m_rejected = rejected; }
        BOOLEAN IsRejected() const { return m_rejected; }
        void SetPlmnScanList(const PlmnScanList& plmn_scan_list) { m_plmn_scan_list = plmn_scan_list; }
        const PlmnScanList& GetPlmnScanList() const { return m_plmn_scan_list; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18202
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_rejected;
        PlmnScanList m_plmn_scan_list;
        
    };


/*  ======================================================================
    Class RegistrationAllowedMsg
    ====================================================================== */

class RegistrationAllowedMsg : public ContextMsg {
    public:
        RegistrationAllowedMsg(ExecutionContext* context, BOOLEAN allowed);
        virtual ~RegistrationAllowedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAllowed(BOOLEAN allowed) { m_allowed = allowed; }
        BOOLEAN IsAllowed() const { return m_allowed; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18203
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_allowed;
        
    };


/*  ======================================================================
    Class SimCallSetupMsg
    ====================================================================== */

class SimCallSetupMsg : public ContextMsg {
    public:
        SimCallSetupMsg(ExecutionContext* context, const SimTkCallSetupIndArg& arg);
        virtual ~SimCallSetupMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkCallSetupIndArg& arg) { m_arg = arg; }
        const SimTkCallSetupIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18301
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkCallSetupIndArg m_arg;
        
    };


/*  ======================================================================
    Class SimSmsSentMsg
    ====================================================================== */

class SimSmsSentMsg : public ContextMsg {
    public:
        SimSmsSentMsg(ExecutionContext* context, const SimTkSmsPpIndArg& arg);
        virtual ~SimSmsSentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkSmsPpIndArg& arg) { m_arg = arg; }
        const SimTkSmsPpIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18302
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkSmsPpIndArg m_arg;
        
    };


/*  ======================================================================
    Class SimSsSentMsg
    ====================================================================== */

class SimSsSentMsg : public ContextMsg {
    public:
        SimSsSentMsg(ExecutionContext* context, const SimTkSsIndArg& arg);
        virtual ~SimSsSentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkSsIndArg& arg) { m_arg = arg; }
        const SimTkSsIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18303
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkSsIndArg m_arg;
        
    };


/*  ======================================================================
    Class SimRefreshMsg
    ====================================================================== */

class SimRefreshMsg : public ContextMsg {
    public:
        SimRefreshMsg(ExecutionContext* context, const SimTkRefreshReqArg& arg);
        virtual ~SimRefreshMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkRefreshReqArg& arg) { m_arg = arg; }
        const SimTkRefreshReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18304
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkRefreshReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimRefreshResetMsg
    ====================================================================== */

class SimRefreshResetMsg : public ContextMsg {
    public:
        SimRefreshResetMsg(ExecutionContext* context);
        virtual ~SimRefreshResetMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18305
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimResetConfirmationMsg
    ====================================================================== */

class SimResetConfirmationMsg : public ContextMsg {
    public:
        SimResetConfirmationMsg(ExecutionContext* context, const SimTkResetCnfReqArg& arg);
        virtual ~SimResetConfirmationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkResetCnfReqArg& arg) { m_arg = arg; }
        const SimTkResetCnfReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18306
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkResetCnfReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimResetDoneMsg
    ====================================================================== */

class SimResetDoneMsg : public ContextMsg {
    public:
        SimResetDoneMsg(ExecutionContext* context);
        virtual ~SimResetDoneMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18307
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimDisplayTextMsg
    ====================================================================== */

class SimDisplayTextMsg : public ContextMsg {
    public:
        SimDisplayTextMsg(ExecutionContext* context, const DisplayTextReqArg& arg);
        virtual ~SimDisplayTextMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DisplayTextReqArg& arg) { m_arg = arg; }
        const DisplayTextReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18310
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DisplayTextReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimGetInputMsg
    ====================================================================== */

class SimGetInputMsg : public ContextMsg {
    public:
        SimGetInputMsg(ExecutionContext* context, const GetInputReqArg& arg);
        virtual ~SimGetInputMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const GetInputReqArg& arg) { m_arg = arg; }
        const GetInputReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18311
            };
        
    private:
        static const MsgMetaData m_meta_data;
        GetInputReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimGetInkeyMsg
    ====================================================================== */

class SimGetInkeyMsg : public ContextMsg {
    public:
        SimGetInkeyMsg(ExecutionContext* context, const GetInkeyReqArg& arg);
        virtual ~SimGetInkeyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const GetInkeyReqArg& arg) { m_arg = arg; }
        const GetInkeyReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18312
            };
        
    private:
        static const MsgMetaData m_meta_data;
        GetInkeyReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimSelectItemMsg
    ====================================================================== */

class SimSelectItemMsg : public ContextMsg {
    public:
        SimSelectItemMsg(ExecutionContext* context, const SelectItemReqArg& arg);
        virtual ~SimSelectItemMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SelectItemReqArg& arg) { m_arg = arg; }
        const SelectItemReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18313
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SelectItemReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimSetupMenuMsg
    ====================================================================== */

class SimSetupMenuMsg : public ContextMsg {
    public:
        SimSetupMenuMsg(ExecutionContext* context, const SimTkTransactionId& tid);
        virtual ~SimSetupMenuMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18314
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkTransactionId m_tid;
        
    };


/*  ======================================================================
    Class SimMenuItemSelectionFailedMsg
    ====================================================================== */

class SimMenuItemSelectionFailedMsg : public ContextMsg {
    public:
        SimMenuItemSelectionFailedMsg(ExecutionContext* context);
        virtual ~SimMenuItemSelectionFailedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18315
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimPlayToneMsg
    ====================================================================== */

class SimPlayToneMsg : public ContextMsg {
    public:
        SimPlayToneMsg(ExecutionContext* context, const PlayToneReqArg& arg);
        virtual ~SimPlayToneMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const PlayToneReqArg& arg) { m_arg = arg; }
        const PlayToneReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18316
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PlayToneReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimSetupIdleModeTextMsg
    ====================================================================== */

class SimSetupIdleModeTextMsg : public ContextMsg {
    public:
        SimSetupIdleModeTextMsg(ExecutionContext* context, const SetupIdleModeTextReqArg& arg);
        virtual ~SimSetupIdleModeTextMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SetupIdleModeTextReqArg& arg) { m_arg = arg; }
        const SetupIdleModeTextReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18317
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SetupIdleModeTextReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimEndTransactionMsg
    ====================================================================== */

class SimEndTransactionMsg : public ContextMsg {
    public:
        SimEndTransactionMsg(ExecutionContext* context);
        virtual ~SimEndTransactionMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18318
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimCallSetupRejectedMsg
    ====================================================================== */

class SimCallSetupRejectedMsg : public ContextMsg {
    public:
        SimCallSetupRejectedMsg(ExecutionContext* context, const CallErrorCause& cause);
        virtual ~SimCallSetupRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCause(const CallErrorCause& cause) { m_cause = cause; }
        const CallErrorCause& GetCause() const { return m_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18319
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallErrorCause m_cause;
        
    };


/*  ======================================================================
    Class CallOnHoldMsg
    ====================================================================== */

class CallOnHoldMsg : public ContextMsg {
    public:
        CallOnHoldMsg(ExecutionContext* context, const CallHdl& call);
        virtual ~CallOnHoldMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCall(const CallHdl& call) { m_call = call; }
        const CallHdl& GetCall() const { return m_call; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18320
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call;
        
    };


/*  ======================================================================
    Class CallHoldRejectedMsg
    ====================================================================== */

class CallHoldRejectedMsg : public ContextMsg {
    public:
        CallHoldRejectedMsg(ExecutionContext* context, const CallHdl& call, const CallErrorCause& cause);
        virtual ~CallHoldRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCall(const CallHdl& call) { m_call = call; }
        const CallHdl& GetCall() const { return m_call; }
        void SetCause(const CallErrorCause& cause) { m_cause = cause; }
        const CallErrorCause& GetCause() const { return m_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18321
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call;
        CallErrorCause m_cause;
        
    };


/*  ======================================================================
    Class MptyOnHoldMsg
    ====================================================================== */

class MptyOnHoldMsg : public ContextMsg {
    public:
        MptyOnHoldMsg(ExecutionContext* context);
        virtual ~MptyOnHoldMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18322
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class MptyHoldRejectedMsg
    ====================================================================== */

class MptyHoldRejectedMsg : public ContextMsg {
    public:
        MptyHoldRejectedMsg(ExecutionContext* context, const SsErrorCode& error_code);
        virtual ~MptyHoldRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetErrorCode(const SsErrorCode& error_code) { m_error_code = error_code; }
        const SsErrorCode& GetErrorCode() const { return m_error_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18323
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsErrorCode m_error_code;
        
    };


/*  ======================================================================
    Class SimTkLanguageNotificationMsg
    ====================================================================== */

class SimTkLanguageNotificationMsg : public ContextMsg {
    public:
        SimTkLanguageNotificationMsg(ExecutionContext* context, const WString& ext_language);
        virtual ~SimTkLanguageNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetExtLanguage(const WString& ext_language) { m_ext_language = ext_language; }
        const WString& GetExtLanguage() const { return m_ext_language; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18324
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_ext_language;
        
    };


/*  ======================================================================
    Class SimTkSetupEventMsg
    ====================================================================== */

class SimTkSetupEventMsg : public ContextMsg {
    public:
        SimTkSetupEventMsg(ExecutionContext* context);
        virtual ~SimTkSetupEventMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18325
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class TermRspCnfMsg
    ====================================================================== */

class TermRspCnfMsg : public ContextMsg {
    public:
        TermRspCnfMsg(ExecutionContext* context, const TermRspCnfArg& arg);
        virtual ~TermRspCnfMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const TermRspCnfArg& arg) { m_arg = arg; }
        const TermRspCnfArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18326
            };
        
    private:
        static const MsgMetaData m_meta_data;
        TermRspCnfArg m_arg;
        
    };


/*  ======================================================================
    Class SimTkRefreshStartMsg
    ====================================================================== */

class SimTkRefreshStartMsg : public ContextMsg {
    public:
        SimTkRefreshStartMsg(ExecutionContext* context);
        virtual ~SimTkRefreshStartMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18327
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimTkProfileGetCnfMsg
    ====================================================================== */

class SimTkProfileGetCnfMsg : public ContextMsg {
    public:
        SimTkProfileGetCnfMsg(ExecutionContext* context, const SimTkProfile& sim_tk_profile);
        virtual ~SimTkProfileGetCnfMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSimTkProfile(const SimTkProfile& sim_tk_profile) { m_sim_tk_profile = sim_tk_profile; }
        const SimTkProfile& GetSimTkProfile() const { return m_sim_tk_profile; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18328
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkProfile m_sim_tk_profile;
        
    };


/*  ======================================================================
    Class SimTkProfileSetCnfMsg
    ====================================================================== */

class SimTkProfileSetCnfMsg : public ContextMsg {
    public:
        SimTkProfileSetCnfMsg(ExecutionContext* context);
        virtual ~SimTkProfileSetCnfMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18329
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimTkProfileSetRejMsg
    ====================================================================== */

class SimTkProfileSetRejMsg : public ContextMsg {
    public:
        SimTkProfileSetRejMsg(ExecutionContext* context);
        virtual ~SimTkProfileSetRejMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18330
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SimLaunchBrowserReqMsg
    ====================================================================== */

class SimLaunchBrowserReqMsg : public ContextMsg {
    public:
        SimLaunchBrowserReqMsg(ExecutionContext* context, const SimLaunchBrowserReqArg& arg);
        virtual ~SimLaunchBrowserReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimLaunchBrowserReqArg& arg) { m_arg = arg; }
        const SimLaunchBrowserReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18331
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimLaunchBrowserReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimLaunchBrowserPromptReqMsg
    ====================================================================== */

class SimLaunchBrowserPromptReqMsg : public ContextMsg {
    public:
        SimLaunchBrowserPromptReqMsg(ExecutionContext* context, const SimLaunchBrowserPromptReqArg& arg);
        virtual ~SimLaunchBrowserPromptReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimLaunchBrowserPromptReqArg& arg) { m_arg = arg; }
        const SimLaunchBrowserPromptReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18332
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimLaunchBrowserPromptReqArg m_arg;
        
    };


/*  ======================================================================
    Class SimBrowserTermResMsg
    ====================================================================== */

class SimBrowserTermResMsg : public ContextMsg {
    public:
        SimBrowserTermResMsg(ExecutionContext* context, const SimBrowserTermResArg& arg);
        virtual ~SimBrowserTermResMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimBrowserTermResArg& arg) { m_arg = arg; }
        const SimBrowserTermResArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18333
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimBrowserTermResArg m_arg;
        
    };


/*  ======================================================================
    Class OmMultiSlotIndMsg
    ====================================================================== */

class OmMultiSlotIndMsg : public ContextMsg {
    public:
        OmMultiSlotIndMsg(ExecutionContext* context, BOOLEAN success);
        virtual ~OmMultiSlotIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSuccess(BOOLEAN success) { m_success = success; }
        BOOLEAN IsSuccess() const { return m_success; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18334
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_success;
        
    };


/*  ======================================================================
    Class DhChannelOpenReqMsg
    ====================================================================== */

class DhChannelOpenReqMsg : public ContextMsg {
    public:
        DhChannelOpenReqMsg(ExecutionContext* context, const DhChannelOpenReqArg& arg);
        virtual ~DhChannelOpenReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DhChannelOpenReqArg& arg) { m_arg = arg; }
        const DhChannelOpenReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18339
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DhChannelOpenReqArg m_arg;
        
    };


/*  ======================================================================
    Class DhChannelCloseReqMsg
    ====================================================================== */

class DhChannelCloseReqMsg : public ContextMsg {
    public:
        DhChannelCloseReqMsg(ExecutionContext* context, const DhChannelCloseReqArg& arg);
        virtual ~DhChannelCloseReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DhChannelCloseReqArg& arg) { m_arg = arg; }
        const DhChannelCloseReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18340
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DhChannelCloseReqArg m_arg;
        
    };


/*  ======================================================================
    Class DhChannelSendReqMsg
    ====================================================================== */

class DhChannelSendReqMsg : public ContextMsg {
    public:
        DhChannelSendReqMsg(ExecutionContext* context, const DhChannelSendReqArg& arg);
        virtual ~DhChannelSendReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DhChannelSendReqArg& arg) { m_arg = arg; }
        const DhChannelSendReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18341
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DhChannelSendReqArg m_arg;
        
    };


/*  ======================================================================
    Class DhChannelDataAvailableResMsg
    ====================================================================== */

class DhChannelDataAvailableResMsg : public ContextMsg {
    public:
        DhChannelDataAvailableResMsg(ExecutionContext* context, const DhChannelDataAvailableResArg& arg);
        virtual ~DhChannelDataAvailableResMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DhChannelDataAvailableResArg& arg) { m_arg = arg; }
        const DhChannelDataAvailableResArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18342
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DhChannelDataAvailableResArg m_arg;
        
    };


/*  ======================================================================
    Class DhChannelReceiveReqMsg
    ====================================================================== */

class DhChannelReceiveReqMsg : public ContextMsg {
    public:
        DhChannelReceiveReqMsg(ExecutionContext* context, const DhChannelReceiveReqArg& arg);
        virtual ~DhChannelReceiveReqMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DhChannelReceiveReqArg& arg) { m_arg = arg; }
        const DhChannelReceiveReqArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18343
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DhChannelReceiveReqArg m_arg;
        
    };


/*  ======================================================================
    Class DhChannelChangeStatusResMsg
    ====================================================================== */

class DhChannelChangeStatusResMsg : public ContextMsg {
    public:
        DhChannelChangeStatusResMsg(ExecutionContext* context, const DhChannelChangeStatusResArg& arg);
        virtual ~DhChannelChangeStatusResMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DhChannelChangeStatusResArg& arg) { m_arg = arg; }
        const DhChannelChangeStatusResArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18344
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DhChannelChangeStatusResArg m_arg;
        
    };


/*  ======================================================================
    Class SimTkRunAtCmdInfoIndMsg
    ====================================================================== */

class SimTkRunAtCmdInfoIndMsg : public ContextMsg {
    public:
        SimTkRunAtCmdInfoIndMsg(ExecutionContext* context, const SimTkRunAtCmdInfoIndArg& arg);
        virtual ~SimTkRunAtCmdInfoIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkRunAtCmdInfoIndArg& arg) { m_arg = arg; }
        const SimTkRunAtCmdInfoIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18345
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkRunAtCmdInfoIndArg m_arg;
        
    };


/*  ======================================================================
    Class SimTkSendDtmfIndMsg
    ====================================================================== */

class SimTkSendDtmfIndMsg : public ContextMsg {
    public:
        SimTkSendDtmfIndMsg(ExecutionContext* context, const SimTkSendDtmfIndArg& arg);
        virtual ~SimTkSendDtmfIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkSendDtmfIndArg& arg) { m_arg = arg; }
        const SimTkSendDtmfIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18346
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkSendDtmfIndArg m_arg;
        
    };


/*  ======================================================================
    Class SimTkSendDtmfEndIndMsg
    ====================================================================== */

class SimTkSendDtmfEndIndMsg : public ContextMsg {
    public:
        SimTkSendDtmfEndIndMsg(ExecutionContext* context, const SimTkSendDtmfEndIndArg& arg);
        virtual ~SimTkSendDtmfEndIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SimTkSendDtmfEndIndArg& arg) { m_arg = arg; }
        const SimTkSendDtmfEndIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18347
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SimTkSendDtmfEndIndArg m_arg;
        
    };


/*  ======================================================================
    Class PowerModeIndMsg
    ====================================================================== */

class PowerModeIndMsg : public ContextMsg {
    public:
        PowerModeIndMsg(ExecutionContext* context, const PowerMode& power_mode);
        virtual ~PowerModeIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPowerMode(const PowerMode& power_mode) { m_power_mode = power_mode; }
        const PowerMode& GetPowerMode() const { return m_power_mode; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18390
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PowerMode m_power_mode;
        
    };


/*  ======================================================================
    Class MocSetupAcceptMsg
    ====================================================================== */

class MocSetupAcceptMsg : public ContextMsg {
    public:
        MocSetupAcceptMsg(ExecutionContext* context, const CallHdl& arg, BOOLEAN est_cause_changed = FALSE);
        virtual ~MocSetupAcceptMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallHdl& arg) { m_arg = arg; }
        const CallHdl& GetArg() const { return m_arg; }
        void SetEstCauseChanged(BOOLEAN est_cause_changed) { m_est_cause_changed = est_cause_changed; }
        BOOLEAN IsEstCauseChanged() const { return m_est_cause_changed; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18400
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_arg;
        BOOLEAN m_est_cause_changed;
        
    };


/*  ======================================================================
    Class CalledPartyAlertingMsg
    ====================================================================== */

class CalledPartyAlertingMsg : public ContextMsg {
    public:
        CalledPartyAlertingMsg(ExecutionContext* context, const CallHdl& arg);
        virtual ~CalledPartyAlertingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallHdl& arg) { m_arg = arg; }
        const CallHdl& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18401
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_arg;
        
    };


/*  ======================================================================
    Class MtcArrivedMsg
    ====================================================================== */

class MtcArrivedMsg : public ContextMsg {
    public:
        MtcArrivedMsg(ExecutionContext* context, const CallHdl& arg);
        virtual ~MtcArrivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallHdl& arg) { m_arg = arg; }
        const CallHdl& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18402
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_arg;
        
    };


/*  ======================================================================
    Class MtcReadyMsg
    ====================================================================== */

class MtcReadyMsg : public ContextMsg {
    public:
        MtcReadyMsg(ExecutionContext* context, const CallHdl& arg);
        virtual ~MtcReadyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallHdl& arg) { m_arg = arg; }
        const CallHdl& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18403
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_arg;
        
    };


/*  ======================================================================
    Class CallSetupProgressMsg
    ====================================================================== */

class CallSetupProgressMsg : public ContextMsg {
    public:
        CallSetupProgressMsg(ExecutionContext* context, const CallSetupProgressArg& arg);
        virtual ~CallSetupProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallSetupProgressArg& arg) { m_arg = arg; }
        const CallSetupProgressArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18404
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallSetupProgressArg m_arg;
        
    };


/*  ======================================================================
    Class CallDisconnectingMsg
    ====================================================================== */

class CallDisconnectingMsg : public ContextMsg {
    public:
        CallDisconnectingMsg(ExecutionContext* context, const CallDisconnectingArg& arg, const DisconnectingMode& disconnecting_mode);
        virtual ~CallDisconnectingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallDisconnectingArg& arg) { m_arg = arg; }
        const CallDisconnectingArg& GetArg() const { return m_arg; }
        void SetDisconnectingMode(const DisconnectingMode& disconnecting_mode) { m_disconnecting_mode = disconnecting_mode; }
        const DisconnectingMode& GetDisconnectingMode() const { return m_disconnecting_mode; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18405
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallDisconnectingArg m_arg;
        DisconnectingMode m_disconnecting_mode;
        
    };


/*  ======================================================================
    Class CallDisconnectedMsg
    ====================================================================== */

class CallDisconnectedMsg : public ContextMsg {
    public:
        CallDisconnectedMsg(ExecutionContext* context, const CallHdl& arg, const DisconnectingMode& disconnecting_mode);
        virtual ~CallDisconnectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallHdl& arg) { m_arg = arg; }
        const CallHdl& GetArg() const { return m_arg; }
        void SetDisconnectingMode(const DisconnectingMode& disconnecting_mode) { m_disconnecting_mode = disconnecting_mode; }
        const DisconnectingMode& GetDisconnectingMode() const { return m_disconnecting_mode; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18406
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_arg;
        DisconnectingMode m_disconnecting_mode;
        
    };


/*  ======================================================================
    Class CallInfoMsg
    ====================================================================== */

class CallInfoMsg : public ContextMsg {
    public:
        CallInfoMsg(ExecutionContext* context, const CallInfoArg& arg);
        virtual ~CallInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallInfoArg& arg) { m_arg = arg; }
        const CallInfoArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18407
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallInfoArg m_arg;
        
    };


/*  ======================================================================
    Class DtmfStartCnfMsg
    ====================================================================== */

class DtmfStartCnfMsg : public ContextMsg {
    public:
        DtmfStartCnfMsg(ExecutionContext* context, const DtmfStartCnfArg& arg);
        virtual ~DtmfStartCnfMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DtmfStartCnfArg& arg) { m_arg = arg; }
        const DtmfStartCnfArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18408
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DtmfStartCnfArg m_arg;
        
    };


/*  ======================================================================
    Class DtmfStopCnfMsg
    ====================================================================== */

class DtmfStopCnfMsg : public ContextMsg {
    public:
        DtmfStopCnfMsg(ExecutionContext* context, const CallHdl& arg);
        virtual ~DtmfStopCnfMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallHdl& arg) { m_arg = arg; }
        const CallHdl& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18409
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_arg;
        
    };


/*  ======================================================================
    Class DtmfRejectMsg
    ====================================================================== */

class DtmfRejectMsg : public ContextMsg {
    public:
        DtmfRejectMsg(ExecutionContext* context, const DtmfRejectArg& arg);
        virtual ~DtmfRejectMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const DtmfRejectArg& arg) { m_arg = arg; }
        const DtmfRejectArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18410
            };
        
    private:
        static const MsgMetaData m_meta_data;
        DtmfRejectArg m_arg;
        
    };


/*  ======================================================================
    Class DtmfBufferCleanedMsg
    ====================================================================== */

class DtmfBufferCleanedMsg : public ContextMsg {
    public:
        DtmfBufferCleanedMsg(ExecutionContext* context);
        virtual ~DtmfBufferCleanedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18411
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class RemotePartyActionMsg
    ====================================================================== */

class RemotePartyActionMsg : public ContextMsg {
    public:
        RemotePartyActionMsg(ExecutionContext* context, const RemotePartyActionArg& arg);
        virtual ~RemotePartyActionMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const RemotePartyActionArg& arg) { m_arg = arg; }
        const RemotePartyActionArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18412
            };
        
    private:
        static const MsgMetaData m_meta_data;
        RemotePartyActionArg m_arg;
        
    };


/*  ======================================================================
    Class ConnectionStatusMsg
    ====================================================================== */

class ConnectionStatusMsg : public ContextMsg {
    public:
        ConnectionStatusMsg(ExecutionContext* context, const ConnectionIndArg& arg);
        virtual ~ConnectionStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const ConnectionIndArg& arg) { m_arg = arg; }
        const ConnectionIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18413
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ConnectionIndArg m_arg;
        
    };


/*  ======================================================================
    Class CallNotifyMsg
    ====================================================================== */

class CallNotifyMsg : public ContextMsg {
    public:
        CallNotifyMsg(ExecutionContext* context, const CallHdl& call_hdl, const NotificationDescription& description);
        virtual ~CallNotifyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetDescription(const NotificationDescription& description) { m_description = description; }
        const NotificationDescription& GetDescription() const { return m_description; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18414
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        NotificationDescription m_description;
        
    };


/*  ======================================================================
    Class RedialStartedMsg
    ====================================================================== */

class RedialStartedMsg : public ContextMsg {
    public:
        RedialStartedMsg(ExecutionContext* context);
        virtual ~RedialStartedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18415
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class RedialStoppedMsg
    ====================================================================== */

class RedialStoppedMsg : public ContextMsg {
    public:
        RedialStoppedMsg(ExecutionContext* context);
        virtual ~RedialStoppedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18416
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class RedialSetupMsg
    ====================================================================== */

class RedialSetupMsg : public ContextMsg {
    public:
        RedialSetupMsg(ExecutionContext* context, const CallHdl& call_hdl, const PhoneNumber& phone_no, const ServedCallApplication& served_call_application);
        virtual ~RedialSetupMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetPhoneNo(const PhoneNumber& phone_no) { m_phone_no = phone_no; }
        const PhoneNumber& GetPhoneNo() const { return m_phone_no; }
        void SetServedCallApplication(const ServedCallApplication& served_call_application) { m_served_call_application = served_call_application; }
        const ServedCallApplication& GetServedCallApplication() const { return m_served_call_application; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18417
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        PhoneNumber m_phone_no;
        ServedCallApplication m_served_call_application;
        
    };


/*  ======================================================================
    Class RedialSuccessMsg
    ====================================================================== */

class RedialSuccessMsg : public ContextMsg {
    public:
        RedialSuccessMsg(ExecutionContext* context, const CallHdl& call_hdl);
        virtual ~RedialSuccessMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18418
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        
    };


/*  ======================================================================
    Class AocChargingStatusMsg
    ====================================================================== */

class AocChargingStatusMsg : public ContextMsg {
    public:
        AocChargingStatusMsg(ExecutionContext* context, const CallHdl& call_hdl, const AocChargingStatus& status);
        virtual ~AocChargingStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetStatus(const AocChargingStatus& status) { m_status = status; }
        const AocChargingStatus& GetStatus() const { return m_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18419
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        AocChargingStatus m_status;
        
    };


/*  ======================================================================
    Class CurrentCallMeterMsg
    ====================================================================== */

class CurrentCallMeterMsg : public ContextMsg {
    public:
        CurrentCallMeterMsg(ExecutionContext* context, const CallHdl& call_hdl, ULONG this_call_ccm, ULONG all_calls_ccm);
        virtual ~CurrentCallMeterMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetThisCallCcm(ULONG this_call_ccm) { m_this_call_ccm = this_call_ccm; }
        ULONG GetThisCallCcm() const { return m_this_call_ccm; }
        void SetAllCallsCcm(ULONG all_calls_ccm) { m_all_calls_ccm = all_calls_ccm; }
        ULONG GetAllCallsCcm() const { return m_all_calls_ccm; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18420
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        ULONG m_this_call_ccm;
        ULONG m_all_calls_ccm;
        
    };


/*  ======================================================================
    Class CurrentChargeDataMsg
    ====================================================================== */

class CurrentChargeDataMsg : public ContextMsg {
    public:
        CurrentChargeDataMsg(ExecutionContext* context, const CallHdl& call_hdl, const AocChargeData& this_call_charge, const AocChargeData& all_calls_charge);
        virtual ~CurrentChargeDataMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetThisCallCharge(const AocChargeData& this_call_charge) { m_this_call_charge = this_call_charge; }
        const AocChargeData& GetThisCallCharge() const { return m_this_call_charge; }
        void SetAllCallsCharge(const AocChargeData& all_calls_charge) { m_all_calls_charge = all_calls_charge; }
        const AocChargeData& GetAllCallsCharge() const { return m_all_calls_charge; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18421
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        AocChargeData m_this_call_charge;
        AocChargeData m_all_calls_charge;
        
    };


/*  ======================================================================
    Class DiagnosticIndMsg
    ====================================================================== */

class DiagnosticIndMsg : public ContextMsg {
    public:
        DiagnosticIndMsg(ExecutionContext* context, const Tipd& tipd, const DiagnosticCause& diagnostic_cause);
        virtual ~DiagnosticIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const DiagnosticCause& GetDiagnosticCause() const { return m_diagnostic_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18422
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        DiagnosticCause m_diagnostic_cause;
        
    };


/*  ======================================================================
    Class RedialStatusMsg
    ====================================================================== */

class RedialStatusMsg : public ContextMsg {
    public:
        RedialStatusMsg(ExecutionContext* context, BOOLEAN redial_status);
        virtual ~RedialStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        BOOLEAN IsRedialStatus() const { return m_redial_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18423
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_redial_status;
        
    };


/*  ======================================================================
    Class CallControlInfoMsg
    ====================================================================== */

class CallControlInfoMsg : public ContextMsg {
    public:
        CallControlInfoMsg(ExecutionContext* context, const CallHdl& call_hdl);
        virtual ~CallControlInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18424
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        
    };


/*  ======================================================================
    Class MocSetupRejectIndMsg
    ====================================================================== */

class MocSetupRejectIndMsg : public ContextMsg {
    public:
        MocSetupRejectIndMsg(ExecutionContext* context, const PhoneNumber& phone_number, const CallErrorCause& cause);
        virtual ~MocSetupRejectIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        const CallErrorCause& GetCause() const { return m_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18425
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PhoneNumber m_phone_number;
        CallErrorCause m_cause;
        
    };


/*  ======================================================================
    Class ForwardingInfoReceivedMsg
    ====================================================================== */

class ForwardingInfoReceivedMsg : public ContextMsg {
    public:
        ForwardingInfoReceivedMsg(ExecutionContext* context, const ForwardingInfoReceivedArg& arg);
        virtual ~ForwardingInfoReceivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const ForwardingInfoReceivedArg& arg) { m_arg = arg; }
        const ForwardingInfoReceivedArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18500
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ForwardingInfoReceivedArg m_arg;
        
    };


/*  ======================================================================
    Class BarringInfoReceivedMsg
    ====================================================================== */

class BarringInfoReceivedMsg : public ContextMsg {
    public:
        BarringInfoReceivedMsg(ExecutionContext* context, const BarringInfoReceivedArg& arg);
        virtual ~BarringInfoReceivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const BarringInfoReceivedArg& arg) { m_arg = arg; }
        const BarringInfoReceivedArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18501
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BarringInfoReceivedArg m_arg;
        
    };


/*  ======================================================================
    Class SsDataReceivedMsg
    ====================================================================== */

class SsDataReceivedMsg : public ContextMsg {
    public:
        SsDataReceivedMsg(ExecutionContext* context, const SsDataReceivedArg& arg);
        virtual ~SsDataReceivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SsDataReceivedArg& arg) { m_arg = arg; }
        const SsDataReceivedArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18502
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsDataReceivedArg m_arg;
        
    };


/*  ======================================================================
    Class SsNotificationMsg
    ====================================================================== */

class SsNotificationMsg : public ContextMsg {
    public:
        SsNotificationMsg(ExecutionContext* context, const SsNotificationArg& arg);
        virtual ~SsNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SsNotificationArg& arg) { m_arg = arg; }
        const SsNotificationArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18503
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsNotificationArg m_arg;
        
    };


/*  ======================================================================
    Class InterrogationResultMsg
    ====================================================================== */

class InterrogationResultMsg : public ContextMsg {
    public:
        InterrogationResultMsg(ExecutionContext* context, const InterrogationResultArg& arg);
        virtual ~InterrogationResultMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const InterrogationResultArg& arg) { m_arg = arg; }
        const InterrogationResultArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18504
            };
        
    private:
        static const MsgMetaData m_meta_data;
        InterrogationResultArg m_arg;
        
    };


/*  ======================================================================
    Class PasswordReceivedMsg
    ====================================================================== */

class PasswordReceivedMsg : public ContextMsg {
    public:
        PasswordReceivedMsg(ExecutionContext* context, const PasswordReceivedArg& arg);
        virtual ~PasswordReceivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const PasswordReceivedArg& arg) { m_arg = arg; }
        const PasswordReceivedArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18505
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PasswordReceivedArg m_arg;
        
    };


/*  ======================================================================
    Class UssDataReceivedMsg
    ====================================================================== */

class UssDataReceivedMsg : public ContextMsg {
    public:
        UssDataReceivedMsg(ExecutionContext* context, const UssDataArg& arg);
        virtual ~UssDataReceivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const UssDataArg& arg) { m_arg = arg; }
        const UssDataArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18506
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UssDataArg m_arg;
        
    };


/*  ======================================================================
    Class HlrSsDataCorruptMsg
    ====================================================================== */

class HlrSsDataCorruptMsg : public ContextMsg {
    public:
        HlrSsDataCorruptMsg(ExecutionContext* context, const SsOperationCode& arg);
        virtual ~HlrSsDataCorruptMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SsOperationCode& arg) { m_arg = arg; }
        const SsOperationCode& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18507
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsOperationCode m_arg;
        
    };


/*  ======================================================================
    Class SsSuccessMsg
    ====================================================================== */

class SsSuccessMsg : public ContextMsg {
    public:
        SsSuccessMsg(ExecutionContext* context, BOOLEAN arg);
        virtual ~SsSuccessMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(BOOLEAN arg) { m_arg = arg; }
        BOOLEAN IsArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18508
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_arg;
        
    };


/*  ======================================================================
    Class SsEndMsg
    ====================================================================== */

class SsEndMsg : public ContextMsg {
    public:
        SsEndMsg(ExecutionContext* context);
        virtual ~SsEndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18509
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SsRejectedMsg
    ====================================================================== */

class SsRejectedMsg : public ContextMsg {
    public:
        SsRejectedMsg(ExecutionContext* context, const TaggedProblemCode& arg);
        virtual ~SsRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const TaggedProblemCode& arg) { m_arg = arg; }
        const TaggedProblemCode& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18510
            };
        
    private:
        static const MsgMetaData m_meta_data;
        TaggedProblemCode m_arg;
        
    };


/*  ======================================================================
    Class SsErrIndicationMsg
    ====================================================================== */

class SsErrIndicationMsg : public ContextMsg {
    public:
        SsErrIndicationMsg(ExecutionContext* context, const SsErrorCode& arg);
        virtual ~SsErrIndicationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SsErrorCode& arg) { m_arg = arg; }
        const SsErrorCode& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18511
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsErrorCode m_arg;
        
    };


/*  ======================================================================
    Class PasswordInquiryMsg
    ====================================================================== */

class PasswordInquiryMsg : public ContextMsg {
    public:
        PasswordInquiryMsg(ExecutionContext* context);
        virtual ~PasswordInquiryMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18512
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class PasswordRejectedMsg
    ====================================================================== */

class PasswordRejectedMsg : public ContextMsg {
    public:
        PasswordRejectedMsg(ExecutionContext* context);
        virtual ~PasswordRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18513
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class UssdIndicationMsg
    ====================================================================== */

class UssdIndicationMsg : public ContextMsg {
    public:
        UssdIndicationMsg(ExecutionContext* context, const UssDataArg& arg);
        virtual ~UssdIndicationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const UssDataArg& arg) { m_arg = arg; }
        const UssDataArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18514
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UssDataArg m_arg;
        
    };


/*  ======================================================================
    Class UssdResentMsg
    ====================================================================== */

class UssdResentMsg : public ContextMsg {
    public:
        UssdResentMsg(ExecutionContext* context);
        virtual ~UssdResentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18515
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class SsFacilityRejectedMsg
    ====================================================================== */

class SsFacilityRejectedMsg : public ContextMsg {
    public:
        SsFacilityRejectedMsg(ExecutionContext* context, const MnCause& cause);
        virtual ~SsFacilityRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCause(const MnCause& cause) { m_cause = cause; }
        const MnCause& GetCause() const { return m_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18516
            };
        
    private:
        static const MsgMetaData m_meta_data;
        MnCause m_cause;
        
    };


/*  ======================================================================
    Class SsInfoMsg
    ====================================================================== */

class SsInfoMsg : public ContextMsg {
    public:
        SsInfoMsg(ExecutionContext* context, const Tipd& tipd, const WString& ss_sequence, BOOLEAN call_control_performed, const SimCallControlResult& call_control_result, const SimAlphaIdentifier& alpha_identifier);
        virtual ~SsInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetSsSequence(const WString& ss_sequence) { m_ss_sequence = ss_sequence; }
        const WString& GetSsSequence() const { return m_ss_sequence; }
        void SetCallControlPerformed(BOOLEAN call_control_performed) { m_call_control_performed = call_control_performed; }
        BOOLEAN IsCallControlPerformed() const { return m_call_control_performed; }
        void SetCallControlResult(const SimCallControlResult& call_control_result) { m_call_control_result = call_control_result; }
        const SimCallControlResult& GetCallControlResult() const { return m_call_control_result; }
        void SetAlphaIdentifier(const SimAlphaIdentifier& alpha_identifier) { m_alpha_identifier = alpha_identifier; }
        const SimAlphaIdentifier& GetAlphaIdentifier() const { return m_alpha_identifier; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18573
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        WString m_ss_sequence;
        BOOLEAN m_call_control_performed;
        SimCallControlResult m_call_control_result;
        SimAlphaIdentifier m_alpha_identifier;
        
    };


/*  ======================================================================
    Class CcbsRecallMsg
    ====================================================================== */

class CcbsRecallMsg : public ContextMsg {
    public:
        CcbsRecallMsg(ExecutionContext* context, const PhoneNumber& phone_number);
        virtual ~CcbsRecallMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18570
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PhoneNumber m_phone_number;
        
    };


/*  ======================================================================
    Class CcbsStatusMsg
    ====================================================================== */

class CcbsStatusMsg : public ContextMsg {
    public:
        CcbsStatusMsg(ExecutionContext* context, const CcbsStatus& ccbs_status);
        virtual ~CcbsStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCcbsStatus(const CcbsStatus& ccbs_status) { m_ccbs_status = ccbs_status; }
        const CcbsStatus& GetCcbsStatus() const { return m_ccbs_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18561
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CcbsStatus m_ccbs_status;
        
    };


/*  ======================================================================
    Class CcbsResultMsg
    ====================================================================== */

class CcbsResultMsg : public ContextMsg {
    public:
        CcbsResultMsg(ExecutionContext* context, const InterrogateCcbsResult& interrogate_ccbs_result);
        virtual ~CcbsResultMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetInterrogateCcbsResult(const InterrogateCcbsResult& interrogate_ccbs_result) { m_interrogate_ccbs_result = interrogate_ccbs_result; }
        const InterrogateCcbsResult& GetInterrogateCcbsResult() const { return m_interrogate_ccbs_result; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18562
            };
        
    private:
        static const MsgMetaData m_meta_data;
        InterrogateCcbsResult m_interrogate_ccbs_result;
        
    };


/*  ======================================================================
    Class UssdAnswerMsg
    ====================================================================== */

class UssdAnswerMsg : public ContextMsg {
    public:
        UssdAnswerMsg(ExecutionContext* context, const Tipd& tipd, const SsOperationCode& ss_opeartion_code, const WString& control_info_string);
        virtual ~UssdAnswerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetTipd(const Tipd& tipd) { m_tipd = tipd; }
        const Tipd& GetTipd() const { return m_tipd; }
        void SetSsOpeartionCode(const SsOperationCode& ss_opeartion_code) { m_ss_opeartion_code = ss_opeartion_code; }
        const SsOperationCode& GetSsOpeartionCode() const { return m_ss_opeartion_code; }
        void SetControlInfoString(const WString& control_info_string) { m_control_info_string = control_info_string; }
        const WString& GetControlInfoString() const { return m_control_info_string; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18574
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsOperationCode m_ss_opeartion_code;
        WString m_control_info_string;
        
    };


/*  ======================================================================
    Class EngineeringReportMsg
    ====================================================================== */

class EngineeringReportMsg : public ContextMsg {
    public:
        EngineeringReportMsg(ExecutionContext* context, const TestparamReportArg& report_arg);
        virtual ~EngineeringReportMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetReportArg(const TestparamReportArg& report_arg) { m_report_arg = report_arg; }
        const TestparamReportArg& GetReportArg() const { return m_report_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18603
            };
        
    private:
        static const MsgMetaData m_meta_data;
        TestparamReportArg m_report_arg;
        
    };


/*  ======================================================================
    Class BandSelectionMsg
    ====================================================================== */

class BandSelectionMsg : public ContextMsg {
    public:
        BandSelectionMsg(ExecutionContext* context, BOOLEAN confirmed);
        virtual ~BandSelectionMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetConfirmed(BOOLEAN confirmed) { m_confirmed = confirmed; }
        BOOLEAN IsConfirmed() const { return m_confirmed; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18604
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_confirmed;
        
    };


/*  ======================================================================
    Class HomezoneMsg
    ====================================================================== */

class HomezoneMsg : public ContextMsg {
    public:
        HomezoneMsg(ExecutionContext* context, const LineSelector& line_selector, const HomezoneIndicator& indicator, const WString& text);
        virtual ~HomezoneMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetLineSelector(const LineSelector& line_selector) { m_line_selector = line_selector; }
        const LineSelector& GetLineSelector() const { return m_line_selector; }
        void SetIndicator(const HomezoneIndicator& indicator) { m_indicator = indicator; }
        const HomezoneIndicator& GetIndicator() const { return m_indicator; }
        void SetText(const WString& text) { m_text = text; }
        const WString& GetText() const { return m_text; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18605
            };
        
    private:
        static const MsgMetaData m_meta_data;
        LineSelector m_line_selector;
        HomezoneIndicator m_indicator;
        WString m_text;
        
    };


/*  ======================================================================
    Class NwDiscStartIndMsg
    ====================================================================== */

class NwDiscStartIndMsg : public ContextMsg {
    public:
        NwDiscStartIndMsg(ExecutionContext* context, const CallHdl& call_hdl, const MnCause& call_clearing_cause);
        virtual ~NwDiscStartIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetCallClearingCause(const MnCause& call_clearing_cause) { m_call_clearing_cause = call_clearing_cause; }
        const MnCause& GetCallClearingCause() const { return m_call_clearing_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18606
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        MnCause m_call_clearing_cause;
        
    };


/*  ======================================================================
    Class RatStateMsg
    ====================================================================== */

class RatStateMsg : public ContextMsg {
    public:
        RatStateMsg(ExecutionContext* context, const RadioAccessTechnology& radio_access_technology);
        virtual ~RatStateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetRadioAccessTechnology(const RadioAccessTechnology& radio_access_technology) { m_radio_access_technology = radio_access_technology; }
        const RadioAccessTechnology& GetRadioAccessTechnology() const { return m_radio_access_technology; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18607
            };
        
    private:
        static const MsgMetaData m_meta_data;
        RadioAccessTechnology m_radio_access_technology;
        
    };


/*  ======================================================================
    Class GsmBandStateMsg
    ====================================================================== */

class GsmBandStateMsg : public ContextMsg {
    public:
        GsmBandStateMsg(ExecutionContext* context, const GsmBand& gsm_band);
        virtual ~GsmBandStateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetGsmBand(const GsmBand& gsm_band) { m_gsm_band = gsm_band; }
        const GsmBand& GetGsmBand() const { return m_gsm_band; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18608
            };
        
    private:
        static const MsgMetaData m_meta_data;
        GsmBand m_gsm_band;
        
    };


/*  ======================================================================
    Class BandStatusMsg
    ====================================================================== */

class BandStatusMsg : public ContextMsg {
    public:
        BandStatusMsg(ExecutionContext* context, const GsmBandList& supported_band_list, const GsmBandList& used_band_list);
        virtual ~BandStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSupportedBandList(const GsmBandList& supported_band_list) { m_supported_band_list = supported_band_list; }
        const GsmBandList& GetSupportedBandList() const { return m_supported_band_list; }
        void SetUsedBandList(const GsmBandList& used_band_list) { m_used_band_list = used_band_list; }
        const GsmBandList& GetUsedBandList() const { return m_used_band_list; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18610
            };
        
    private:
        static const MsgMetaData m_meta_data;
        GsmBandList m_supported_band_list;
        GsmBandList m_used_band_list;
        
    };


/*  ======================================================================
    Class EngineeringModeControlResponseMsg
    ====================================================================== */

class EngineeringModeControlResponseMsg : public ContextMsg {
    public:
        EngineeringModeControlResponseMsg(ExecutionContext* context, const EngineeringModeControlResponseArg& cnf_arg);
        virtual ~EngineeringModeControlResponseMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCnfArg(const EngineeringModeControlResponseArg& cnf_arg) { m_cnf_arg = cnf_arg; }
        const EngineeringModeControlResponseArg& GetCnfArg() const { return m_cnf_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18611
            };
        
    private:
        static const MsgMetaData m_meta_data;
        EngineeringModeControlResponseArg m_cnf_arg;
        
    };


/*  ======================================================================
    Class RatChangeModeChangedMsg
    ====================================================================== */

class RatChangeModeChangedMsg : public ContextMsg {
    public:
        RatChangeModeChangedMsg(ExecutionContext* context, const RatChangeMode& rat_change_mode);
        virtual ~RatChangeModeChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetRatChangeMode(const RatChangeMode& rat_change_mode) { m_rat_change_mode = rat_change_mode; }
        const RatChangeMode& GetRatChangeMode() const { return m_rat_change_mode; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18612
            };
        
    private:
        static const MsgMetaData m_meta_data;
        RatChangeMode m_rat_change_mode;
        
    };


/*  ======================================================================
    Class CellInfoMsg
    ====================================================================== */

class CellInfoMsg : public ContextMsg {
    public:
        CellInfoMsg(ExecutionContext* context, const CellInfoIndArg& arg);
        virtual ~CellInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CellInfoIndArg& arg) { m_arg = arg; }
        const CellInfoIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18801
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CellInfoIndArg m_arg;
        
    };


/*  ======================================================================
    Class SmsNewMessageMsg
    ====================================================================== */

class SmsNewMessageMsg : public ContextMsg {
    public:
        SmsNewMessageMsg(ExecutionContext* context, const SmsNewMessageIndArg& arg);
        virtual ~SmsNewMessageMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SmsNewMessageIndArg& arg) { m_arg = arg; }
        const SmsNewMessageIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18900
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsNewMessageIndArg m_arg;
        
    };


/*  ======================================================================
    Class SmsNewStatusReportMsg
    ====================================================================== */

class SmsNewStatusReportMsg : public ContextMsg {
    public:
        SmsNewStatusReportMsg(ExecutionContext* context, const SmsNewStatusReportIndArg& arg);
        virtual ~SmsNewStatusReportMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SmsNewStatusReportIndArg& arg) { m_arg = arg; }
        const SmsNewStatusReportIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18901
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsNewStatusReportIndArg m_arg;
        
    };


/*  ======================================================================
    Class SmsNewSocketDataMsg
    ====================================================================== */

class SmsNewSocketDataMsg : public ContextMsg {
    public:
        SmsNewSocketDataMsg(ExecutionContext* context, const SmsPortNo& sms_port_no, const PhoneNumber& sender_phonenumber, const DateTime& date_time, const DataCodingScheme& dcs, const SmsPortNo& sender_port_no, const PhoneNumber& sca);
        virtual ~SmsNewSocketDataMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSmsPortNo(const SmsPortNo& sms_port_no) { m_sms_port_no = sms_port_no; }
        const SmsPortNo& GetSmsPortNo() const { return m_sms_port_no; }
        void SetSenderPhonenumber(const PhoneNumber& sender_phonenumber) { m_sender_phonenumber = sender_phonenumber; }
        const PhoneNumber& GetSenderPhonenumber() const { return m_sender_phonenumber; }
        void SetDateTime(const DateTime& date_time) { m_date_time = date_time; }
        const DateTime& GetDateTime() const { return m_date_time; }
        void SetDcs(const DataCodingScheme& dcs) { m_dcs = dcs; }
        const DataCodingScheme& GetDcs() const { return m_dcs; }
        void SetSenderPortNo(const SmsPortNo& sender_port_no) { m_sender_port_no = sender_port_no; }
        const SmsPortNo& GetSenderPortNo() const { return m_sender_port_no; }
        void SetSca(const PhoneNumber& sca) { m_sca = sca; }
        const PhoneNumber& GetSca() const { return m_sca; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18902
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsPortNo m_sms_port_no;
        PhoneNumber m_sender_phonenumber;
        DateTime m_date_time;
        DataCodingScheme m_dcs;
        SmsPortNo m_sender_port_no;
        PhoneNumber m_sca;
        
    };


/*  ======================================================================
    Class SmsPortDataRecvMsg
    ====================================================================== */

class SmsPortDataRecvMsg : public ContextMsg {
    public:
        SmsPortDataRecvMsg(ExecutionContext* context, const SmsPortNo& sms_port_no, const PhoneNumber& sender_phonenumber);
        virtual ~SmsPortDataRecvMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetSmsPortNo(const SmsPortNo& sms_port_no) { m_sms_port_no = sms_port_no; }
        const SmsPortNo& GetSmsPortNo() const { return m_sms_port_no; }
        void SetSenderPhonenumber(const PhoneNumber& sender_phonenumber) { m_sender_phonenumber = sender_phonenumber; }
        const PhoneNumber& GetSenderPhonenumber() const { return m_sender_phonenumber; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18903
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsPortNo m_sms_port_no;
        PhoneNumber m_sender_phonenumber;
        
    };


/*  ======================================================================
    Class SmsSendConfirmMsg
    ====================================================================== */

class SmsSendConfirmMsg : public ContextMsg {
    public:
        SmsSendConfirmMsg(ExecutionContext* context, const SmsSendCnfArg& arg);
        virtual ~SmsSendConfirmMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SmsSendCnfArg& arg) { m_arg = arg; }
        const SmsSendCnfArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18910
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsSendCnfArg m_arg;
        
    };


/*  ======================================================================
    Class SmsSendRejectMsg
    ====================================================================== */

class SmsSendRejectMsg : public ContextMsg {
    public:
        SmsSendRejectMsg(ExecutionContext* context, const SmsSendRejArg& arg);
        virtual ~SmsSendRejectMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SmsSendRejArg& arg) { m_arg = arg; }
        const SmsSendRejArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18911
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SmsSendRejArg m_arg;
        
    };


/*  ======================================================================
    Class SmsSpaceExceededMsg
    ====================================================================== */

class SmsSpaceExceededMsg : public ContextMsg {
    public:
        SmsSpaceExceededMsg(ExecutionContext* context, const Sms::WarningLevel& arg);
        virtual ~SmsSpaceExceededMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const Sms::WarningLevel& arg) { m_arg = arg; }
        const Sms::WarningLevel& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18920
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Sms::WarningLevel m_arg;
        
    };


/*  ======================================================================
    Class SmsSpaceAvailableMsg
    ====================================================================== */

class SmsSpaceAvailableMsg : public ContextMsg {
    public:
        SmsSpaceAvailableMsg(ExecutionContext* context);
        virtual ~SmsSpaceAvailableMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18921
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class CbsNewDataMsg
    ====================================================================== */

class CbsNewDataMsg : public ContextMsg {
    public:
        CbsNewDataMsg(ExecutionContext* context, const CbsNewDataIndArg& arg);
        virtual ~CbsNewDataMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CbsNewDataIndArg& arg) { m_arg = arg; }
        const CbsNewDataIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18922
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CbsNewDataIndArg m_arg;
        
    };


/*  ======================================================================
    Class SmsPrefStorageMediaChangedMsg
    ====================================================================== */

class SmsPrefStorageMediaChangedMsg : public ContextMsg {
    public:
        SmsPrefStorageMediaChangedMsg(ExecutionContext* context, const Sms::StorageType& arg);
        virtual ~SmsPrefStorageMediaChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const Sms::StorageType& arg) { m_arg = arg; }
        const Sms::StorageType& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18923
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Sms::StorageType m_arg;
        
    };


/*  ======================================================================
    Class SmsMessageWaitingChangedMsg
    ====================================================================== */

class SmsMessageWaitingChangedMsg : public ContextMsg {
    public:
        SmsMessageWaitingChangedMsg(ExecutionContext* context);
        virtual ~SmsMessageWaitingChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18924
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class CbsLimitMsg
    ====================================================================== */

class CbsLimitMsg : public ContextMsg {
    public:
        CbsLimitMsg(ExecutionContext* context, UINT16 max_message_id);
        virtual ~CbsLimitMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMaxMessageId(UINT16 max_message_id) { m_max_message_id = max_message_id; }
        UINT16 GetMaxMessageId() const { return m_max_message_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18925
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT16 m_max_message_id;
        
    };


/*  ======================================================================
    Class PbSizeRequestMsg
    ====================================================================== */

class PbSizeRequestMsg : public ContextMsg {
    public:
        PbSizeRequestMsg(ExecutionContext* context, const MePhoneBookType& me_phone_book_type);
        virtual ~PbSizeRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMePhoneBookType(const MePhoneBookType& me_phone_book_type) { m_me_phone_book_type = me_phone_book_type; }
        const MePhoneBookType& GetMePhoneBookType() const { return m_me_phone_book_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18926
            };
        
    private:
        static const MsgMetaData m_meta_data;
        MePhoneBookType m_me_phone_book_type;
        
    };


/*  ======================================================================
    Class PbEntryRequestMsg
    ====================================================================== */

class PbEntryRequestMsg : public ContextMsg {
    public:
        PbEntryRequestMsg(ExecutionContext* context, const MePhoneBookType& me_phone_book_type, INT record_number);
        virtual ~PbEntryRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMePhoneBookType(const MePhoneBookType& me_phone_book_type) { m_me_phone_book_type = me_phone_book_type; }
        const MePhoneBookType& GetMePhoneBookType() const { return m_me_phone_book_type; }
        void SetRecordNumber(INT record_number) { m_record_number = record_number; }
        INT GetRecordNumber() const { return m_record_number; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18927
            };
        
    private:
        static const MsgMetaData m_meta_data;
        MePhoneBookType m_me_phone_book_type;
        INT m_record_number;
        
    };


/*  ======================================================================
    Class PbAlphaTagRequestMsg
    ====================================================================== */

class PbAlphaTagRequestMsg : public ContextMsg {
    public:
        PbAlphaTagRequestMsg(ExecutionContext* context, const PhoneNumber& phone_number);
        virtual ~PbAlphaTagRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPhoneNumber(const PhoneNumber& phone_number) { m_phone_number = phone_number; }
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18928
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PhoneNumber m_phone_number;
        
    };


/*  ======================================================================
    Class CallDeflectionIndMsg
    ====================================================================== */

class CallDeflectionIndMsg : public ContextMsg {
    public:
        CallDeflectionIndMsg(ExecutionContext* context, const CallDeflectionIndArg& arg);
        virtual ~CallDeflectionIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const CallDeflectionIndArg& arg) { m_arg = arg; }
        const CallDeflectionIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18953
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallDeflectionIndArg m_arg;
        
    };


/*  ======================================================================
    Class CallDeflectionErrIndicationMsg
    ====================================================================== */

class CallDeflectionErrIndicationMsg : public ContextMsg {
    public:
        CallDeflectionErrIndicationMsg(ExecutionContext* context, const SsErrIndArg& arg);
        virtual ~CallDeflectionErrIndicationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SsErrIndArg& arg) { m_arg = arg; }
        const SsErrIndArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18954
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsErrIndArg m_arg;
        
    };


/*  ======================================================================
    Class CallDeflectionRejectedMsg
    ====================================================================== */

class CallDeflectionRejectedMsg : public ContextMsg {
    public:
        CallDeflectionRejectedMsg(ExecutionContext* context, const SsRejArg& arg);
        virtual ~CallDeflectionRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const SsRejArg& arg) { m_arg = arg; }
        const SsRejArg& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18955
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsRejArg m_arg;
        
    };


/*  ======================================================================
    Class CtmInfoIndMsg
    ====================================================================== */

class CtmInfoIndMsg : public ContextMsg {
    public:
        CtmInfoIndMsg(ExecutionContext* context, const CallHdl& call_hdl, BOOLEAN ctm);
        virtual ~CtmInfoIndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetCallHdl(const CallHdl& call_hdl) { m_call_hdl = call_hdl; }
        const CallHdl& GetCallHdl() const { return m_call_hdl; }
        void SetCtm(BOOLEAN ctm) { m_ctm = ctm; }
        BOOLEAN IsCtm() const { return m_ctm; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18956
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallHdl m_call_hdl;
        BOOLEAN m_ctm;
        
    };


/*  ======================================================================
    Class SsRequestSentMsg
    ====================================================================== */

class SsRequestSentMsg : public SsMessage {
    public:
        SsRequestSentMsg(ExecutionContext* context, const WString& ss_control_seq, const SsCode& ss_code, const ServiceGroup& basic_service, const SsOperationCode& operation_code, const WString& parameter1, const WString& parameter2, const WString& parameter3);
        virtual ~SsRequestSentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const WString& GetSsControlSeq() const { return m_ss_control_seq; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const ServiceGroup& GetBasicService() const { return m_basic_service; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        const WString& GetParameter1() const { return m_parameter1; }
        const WString& GetParameter2() const { return m_parameter2; }
        const WString& GetParameter3() const { return m_parameter3; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18557
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_ss_control_seq;
        SsCode m_ss_code;
        ServiceGroup m_basic_service;
        SsOperationCode m_operation_code;
        WString m_parameter1;
        WString m_parameter2;
        WString m_parameter3;
        
    };


/*  ======================================================================
    Class SsRequestAcceptedMsg
    ====================================================================== */

class SsRequestAcceptedMsg : public SsMessage {
    public:
        SsRequestAcceptedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const ServiceGroup& basic_service, const SsOperationCode& operation_code, const WString& parameter1, const WString& parameter2, const WString& parameter3, const WString& ss_control_seq);
        virtual ~SsRequestAcceptedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const ServiceGroup& GetBasicService() const { return m_basic_service; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        const WString& GetParameter1() const { return m_parameter1; }
        const WString& GetParameter2() const { return m_parameter2; }
        const WString& GetParameter3() const { return m_parameter3; }
        const WString& GetSsControlSeq() const { return m_ss_control_seq; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18517
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        ServiceGroup m_basic_service;
        SsOperationCode m_operation_code;
        WString m_parameter1;
        WString m_parameter2;
        WString m_parameter3;
        WString m_ss_control_seq;
        
    };


/*  ======================================================================
    Class SsRequestRejectedMsg
    ====================================================================== */

class SsRequestRejectedMsg : public SsMessage {
    public:
        SsRequestRejectedMsg(ExecutionContext* context, const SsApiRc& error_code, const SsCode& ss_code, const ServiceGroup& basic_service, const SsOperationCode& operation_code, const WString& parameter1, const WString& parameter2, const WString& parameter3, const CallErrorCause& cause);
        virtual ~SsRequestRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const SsApiRc& GetErrorCode() const { return m_error_code; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const ServiceGroup& GetBasicService() const { return m_basic_service; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        const WString& GetParameter1() const { return m_parameter1; }
        const WString& GetParameter2() const { return m_parameter2; }
        const WString& GetParameter3() const { return m_parameter3; }
        const CallErrorCause& GetCause() const { return m_cause; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18518
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsApiRc m_error_code;
        SsCode m_ss_code;
        ServiceGroup m_basic_service;
        SsOperationCode m_operation_code;
        WString m_parameter1;
        WString m_parameter2;
        WString m_parameter3;
        CallErrorCause m_cause;
        
    };


/*  ======================================================================
    Class CallWaitingActivatedMsg
    ====================================================================== */

class CallWaitingActivatedMsg : public SsMessage {
    public:
        CallWaitingActivatedMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const Vector<SsGroup>& basic_service_list, const ServiceGroup& param_basic_service);
        virtual ~CallWaitingActivatedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const Vector<SsGroup>& GetBasicServiceList() const { return m_basic_service_list; }
        const ServiceGroup& GetParamBasicService() const { return m_param_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18519
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        Vector<SsGroup> m_basic_service_list;
        ServiceGroup m_param_basic_service;
        
    };


/*  ======================================================================
    Class CallWaitingDeactivatedMsg
    ====================================================================== */

class CallWaitingDeactivatedMsg : public SsMessage {
    public:
        CallWaitingDeactivatedMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const Vector<SsGroup>& basic_service_list, const ServiceGroup& param_basic_service);
        virtual ~CallWaitingDeactivatedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const Vector<SsGroup>& GetBasicServiceList() const { return m_basic_service_list; }
        const ServiceGroup& GetParamBasicService() const { return m_param_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18520
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        Vector<SsGroup> m_basic_service_list;
        ServiceGroup m_param_basic_service;
        
    };


/*  ======================================================================
    Class CallWaitingStatusMsg
    ====================================================================== */

class CallWaitingStatusMsg : public SsMessage {
    public:
        CallWaitingStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const Vector<SsGroup>& basic_service_list);
        virtual ~CallWaitingStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const Vector<SsGroup>& GetBasicServiceList() const { return m_basic_service_list; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18521
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        Vector<SsGroup> m_basic_service_list;
        
    };


/*  ======================================================================
    Class EmlppRegisteredMsg
    ====================================================================== */

class EmlppRegisteredMsg : public SsMessage {
    public:
        EmlppRegisteredMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const EmlppPriorityLevel& default_priority);
        virtual ~EmlppRegisteredMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const EmlppPriorityLevel& GetDefaultPriority() const { return m_default_priority; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18565
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        EmlppPriorityLevel m_default_priority;
        
    };


/*  ======================================================================
    Class EmlppStatusMsg
    ====================================================================== */

class EmlppStatusMsg : public SsMessage {
    public:
        EmlppStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const EmlppPriorityLevel& default_priority, const EmlppPriorityLevel& max_entitled_priority);
        virtual ~EmlppStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const EmlppPriorityLevel& GetDefaultPriority() const { return m_default_priority; }
        const EmlppPriorityLevel& GetMaxEntitledPriority() const { return m_max_entitled_priority; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18566
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        EmlppPriorityLevel m_default_priority;
        EmlppPriorityLevel m_max_entitled_priority;
        
    };


/*  ======================================================================
    Class NetworkSsErrorMsg
    ====================================================================== */

class NetworkSsErrorMsg : public SsMessage {
    public:
        NetworkSsErrorMsg(ExecutionContext* context, const Tipd& tipd, const SsErrorCode& error_code, const SsCode& ss_code, const ServiceGroup& basic_service, const SsOperationCode& operation_code);
        virtual ~NetworkSsErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsErrorCode& GetErrorCode() const { return m_error_code; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const ServiceGroup& GetBasicService() const { return m_basic_service; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18522
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsErrorCode m_error_code;
        SsCode m_ss_code;
        ServiceGroup m_basic_service;
        SsOperationCode m_operation_code;
        
    };


/*  ======================================================================
    Class NetworkSsRejectedMsg
    ====================================================================== */

class NetworkSsRejectedMsg : public SsMessage {
    public:
        NetworkSsRejectedMsg(ExecutionContext* context, const Tipd& tipd, const TaggedProblemCode& tagged_problem_code, const SsCode& ss_code, const ServiceGroup& basic_service, const SsOperationCode& operation_code);
        virtual ~NetworkSsRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const TaggedProblemCode& GetTaggedProblemCode() const { return m_tagged_problem_code; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const ServiceGroup& GetBasicService() const { return m_basic_service; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18523
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        TaggedProblemCode m_tagged_problem_code;
        SsCode m_ss_code;
        ServiceGroup m_basic_service;
        SsOperationCode m_operation_code;
        
    };


/*  ======================================================================
    Class StackSsRejectedMsg
    ====================================================================== */

class StackSsRejectedMsg : public SsMessage {
    public:
        StackSsRejectedMsg(ExecutionContext* context, const Tipd& tipd, const CallErrorCause& cause, const SsCode& ss_code, const ServiceGroup& basic_service, const SsOperationCode& operation_code);
        virtual ~StackSsRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const CallErrorCause& GetCause() const { return m_cause; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const ServiceGroup& GetBasicService() const { return m_basic_service; }
        const SsOperationCode& GetOperationCode() const { return m_operation_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18558
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        CallErrorCause m_cause;
        SsCode m_ss_code;
        ServiceGroup m_basic_service;
        SsOperationCode m_operation_code;
        
    };


/*  ======================================================================
    Class ClirNotSurpressedMsg
    ====================================================================== */

class ClirNotSurpressedMsg : public SsMessage {
    public:
        ClirNotSurpressedMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~ClirNotSurpressedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18524
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class CallForwardingActiveMsg
    ====================================================================== */

class CallForwardingActiveMsg : public SsMessage {
    public:
        CallForwardingActiveMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code);
        virtual ~CallForwardingActiveMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18525
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        
    };


/*  ======================================================================
    Class CallHeldMsg
    ====================================================================== */

class CallHeldMsg : public SsMessage {
    public:
        CallHeldMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~CallHeldMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18526
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class CallRetrievedMsg
    ====================================================================== */

class CallRetrievedMsg : public SsMessage {
    public:
        CallRetrievedMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~CallRetrievedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18527
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class CallIsWaitingMsg
    ====================================================================== */

class CallIsWaitingMsg : public SsMessage {
    public:
        CallIsWaitingMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~CallIsWaitingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18528
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class CallBarredMsg
    ====================================================================== */

class CallBarredMsg : public SsMessage {
    public:
        CallBarredMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const SsStatus& ss_status);
        virtual ~CallBarredMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18560
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        SsStatus m_ss_status;
        
    };


/*  ======================================================================
    Class ForwardedCallIncomingMsg
    ====================================================================== */

class ForwardedCallIncomingMsg : public SsMessage {
    public:
        ForwardedCallIncomingMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code);
        virtual ~ForwardedCallIncomingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18529
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        
    };


/*  ======================================================================
    Class HlrDataCorruptedMsg
    ====================================================================== */

class HlrDataCorruptedMsg : public SsMessage {
    public:
        HlrDataCorruptedMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~HlrDataCorruptedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18530
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class CugCallMsg
    ====================================================================== */

class CugCallMsg : public SsMessage {
    public:
        CugCallMsg(ExecutionContext* context, const Tipd& tipd, INT cug_index);
        virtual ~CugCallMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        INT GetCugIndex() const { return m_cug_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18531
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        INT m_cug_index;
        
    };


/*  ======================================================================
    Class OutgoingCallForwardedMsg
    ====================================================================== */

class OutgoingCallForwardedMsg : public SsMessage {
    public:
        OutgoingCallForwardedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code);
        virtual ~OutgoingCallForwardedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18532
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        
    };


/*  ======================================================================
    Class IncomingCallForwardedMsg
    ====================================================================== */

class IncomingCallForwardedMsg : public SsMessage {
    public:
        IncomingCallForwardedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code);
        virtual ~IncomingCallForwardedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18533
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        
    };


/*  ======================================================================
    Class MultiPartyCallInvokedMsg
    ====================================================================== */

class MultiPartyCallInvokedMsg : public SsMessage {
    public:
        MultiPartyCallInvokedMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~MultiPartyCallInvokedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18534
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class EctActiveMsg
    ====================================================================== */

class EctActiveMsg : public SsMessage {
    public:
        EctActiveMsg(ExecutionContext* context, const Tipd& tipd, const RdnChoice& rdn_selector, const PhoneNumber& address, const PhoneNumber& sub_address);
        virtual ~EctActiveMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const RdnChoice& GetRdnSelector() const { return m_rdn_selector; }
        const PhoneNumber& GetAddress() const { return m_address; }
        const PhoneNumber& GetSubAddress() const { return m_sub_address; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18535
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        RdnChoice m_rdn_selector;
        PhoneNumber m_address;
        PhoneNumber m_sub_address;
        
    };


/*  ======================================================================
    Class EctAlertingMsg
    ====================================================================== */

class EctAlertingMsg : public SsMessage {
    public:
        EctAlertingMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~EctAlertingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18536
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class CnapInfoReceivedMsg
    ====================================================================== */

class CnapInfoReceivedMsg : public SsMessage {
    public:
        CnapInfoReceivedMsg(ExecutionContext* context, const Tipd& tipd, const WString& cnap_name, const CnameChoice& presentation_indicator, const DataCodingScheme& data_coding_scheme);
        virtual ~CnapInfoReceivedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const WString& GetCnapName() const { return m_cnap_name; }
        const CnameChoice& GetPresentationIndicator() const { return m_presentation_indicator; }
        const DataCodingScheme& GetDataCodingScheme() const { return m_data_coding_scheme; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18564
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        WString m_cnap_name;
        CnameChoice m_presentation_indicator;
        DataCodingScheme m_data_coding_scheme;
        
    };


/*  ======================================================================
    Class CallForwardingActivatedMsg
    ====================================================================== */

class CallForwardingActivatedMsg : public SsMessage {
    public:
        CallForwardingActivatedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const Vector<ForwardingFeature>& forwarding_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service, const PhoneNumber& parameter_phonenumber, UINT parameter_time_out);
        virtual ~CallForwardingActivatedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<ForwardingFeature>& GetForwardingFeatures() const { return m_forwarding_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        const PhoneNumber& GetParameterPhonenumber() const { return m_parameter_phonenumber; }
        UINT GetParameterTimeOut() const { return m_parameter_time_out; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18537
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        Vector<ForwardingFeature> m_forwarding_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        PhoneNumber m_parameter_phonenumber;
        UINT m_parameter_time_out;
        
    };


/*  ======================================================================
    Class CallForwardingDeactivatedMsg
    ====================================================================== */

class CallForwardingDeactivatedMsg : public SsMessage {
    public:
        CallForwardingDeactivatedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const Vector<ForwardingFeature>& forwarding_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service);
        virtual ~CallForwardingDeactivatedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<ForwardingFeature>& GetForwardingFeatures() const { return m_forwarding_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18538
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        Vector<ForwardingFeature> m_forwarding_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        
    };


/*  ======================================================================
    Class CallForwardingStatusMsg
    ====================================================================== */

class CallForwardingStatusMsg : public SsMessage {
    public:
        CallForwardingStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const Vector<ForwardingFeature>& forwarding_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service);
        virtual ~CallForwardingStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const Vector<ForwardingFeature>& GetForwardingFeatures() const { return m_forwarding_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18539
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        Vector<ForwardingFeature> m_forwarding_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        
    };


/*  ======================================================================
    Class CallForwardingRegisteredMsg
    ====================================================================== */

class CallForwardingRegisteredMsg : public SsMessage {
    public:
        CallForwardingRegisteredMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const Vector<ForwardingFeature>& forwarding_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service, const PhoneNumber& parameter_phonenumber, UINT parameter_time_out);
        virtual ~CallForwardingRegisteredMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<ForwardingFeature>& GetForwardingFeatures() const { return m_forwarding_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        const PhoneNumber& GetParameterPhonenumber() const { return m_parameter_phonenumber; }
        UINT GetParameterTimeOut() const { return m_parameter_time_out; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18540
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        Vector<ForwardingFeature> m_forwarding_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        PhoneNumber m_parameter_phonenumber;
        UINT m_parameter_time_out;
        
    };


/*  ======================================================================
    Class CallForwardingErasedMsg
    ====================================================================== */

class CallForwardingErasedMsg : public SsMessage {
    public:
        CallForwardingErasedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const Vector<ForwardingFeature>& forwarding_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service);
        virtual ~CallForwardingErasedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<ForwardingFeature>& GetForwardingFeatures() const { return m_forwarding_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18541
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        Vector<ForwardingFeature> m_forwarding_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        
    };


/*  ======================================================================
    Class CallBarringActivatedMsg
    ====================================================================== */

class CallBarringActivatedMsg : public SsMessage {
    public:
        CallBarringActivatedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const Vector<CallBarringFeature>& call_barring_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service);
        virtual ~CallBarringActivatedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<CallBarringFeature>& GetCallBarringFeatures() const { return m_call_barring_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18542
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        Vector<CallBarringFeature> m_call_barring_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        
    };


/*  ======================================================================
    Class CallBarringDeactivatedMsg
    ====================================================================== */

class CallBarringDeactivatedMsg : public SsMessage {
    public:
        CallBarringDeactivatedMsg(ExecutionContext* context, const Tipd& tipd, const SsCode& ss_code, const Vector<CallBarringFeature>& call_barring_features, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service);
        virtual ~CallBarringDeactivatedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<CallBarringFeature>& GetCallBarringFeatures() const { return m_call_barring_features; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18543
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsCode m_ss_code;
        Vector<CallBarringFeature> m_call_barring_features;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        
    };


/*  ======================================================================
    Class CallBarringStatusMsg
    ====================================================================== */

class CallBarringStatusMsg : public SsMessage {
    public:
        CallBarringStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const Vector<SsGroup>& basic_service_list, const SsCode& parameter_ss_code, const ServiceGroup& parameter_basic_service);
        virtual ~CallBarringStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const Vector<SsGroup>& GetBasicServiceList() const { return m_basic_service_list; }
        const SsCode& GetParameterSsCode() const { return m_parameter_ss_code; }
        const ServiceGroup& GetParameterBasicService() const { return m_parameter_basic_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18544
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        Vector<SsGroup> m_basic_service_list;
        SsCode m_parameter_ss_code;
        ServiceGroup m_parameter_basic_service;
        
    };


/*  ======================================================================
    Class ClipStatusMsg
    ====================================================================== */

class ClipStatusMsg : public SsMessage {
    public:
        ClipStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status);
        virtual ~ClipStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18545
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        
    };


/*  ======================================================================
    Class ColpStatusMsg
    ====================================================================== */

class ColpStatusMsg : public SsMessage {
    public:
        ColpStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status);
        virtual ~ColpStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18546
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        
    };


/*  ======================================================================
    Class ColrStatusMsg
    ====================================================================== */

class ColrStatusMsg : public SsMessage {
    public:
        ColrStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status);
        virtual ~ColrStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18547
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        
    };


/*  ======================================================================
    Class CnapStatusMsg
    ====================================================================== */

class CnapStatusMsg : public SsMessage {
    public:
        CnapStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status);
        virtual ~CnapStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18563
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        
    };


/*  ======================================================================
    Class ClirStatusMsg
    ====================================================================== */

class ClirStatusMsg : public SsMessage {
    public:
        ClirStatusMsg(ExecutionContext* context, const Tipd& tipd, const SsStatus& ss_status, const CliRestrictionOption& cli_restriction_option);
        virtual ~ClirStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsStatus& GetSsStatus() const { return m_ss_status; }
        const CliRestrictionOption& GetCliRestrictionOption() const { return m_cli_restriction_option; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18548
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStatus m_ss_status;
        CliRestrictionOption m_cli_restriction_option;
        
    };


/*  ======================================================================
    Class CallBarringPasswordChangedMsg
    ====================================================================== */

class CallBarringPasswordChangedMsg : public SsMessage {
    public:
        CallBarringPasswordChangedMsg(ExecutionContext* context, const Tipd& tipd, const WString& new_password, const SsCode& param_ss_code, const WString& param_old_password, const WString& param_new_password, const WString& param_conf_password);
        virtual ~CallBarringPasswordChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const WString& GetNewPassword() const { return m_new_password; }
        const SsCode& GetParamSsCode() const { return m_param_ss_code; }
        const WString& GetParamOldPassword() const { return m_param_old_password; }
        const WString& GetParamNewPassword() const { return m_param_new_password; }
        const WString& GetParamConfPassword() const { return m_param_conf_password; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18549
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        WString m_new_password;
        SsCode m_param_ss_code;
        WString m_param_old_password;
        WString m_param_new_password;
        WString m_param_conf_password;
        
    };


/*  ======================================================================
    Class SsErrorMsg
    ====================================================================== */

class SsErrorMsg : public SsMessage {
    public:
        SsErrorMsg(ExecutionContext* context, const Tipd& tipd, const SsBaseHandler::ReturnCode& error_code, const WString& error_text);
        virtual ~SsErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const SsBaseHandler::ReturnCode& GetErrorCode() const { return m_error_code; }
        const WString& GetErrorText() const { return m_error_text; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18550
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsBaseHandler::ReturnCode m_error_code;
        WString m_error_text;
        
    };


/*  ======================================================================
    Class UssdRequestMsg
    ====================================================================== */

class UssdRequestMsg : public SsMessage {
    public:
        UssdRequestMsg(ExecutionContext* context, const Tipd& tipd, const WString& control_info, const DataCodingScheme& data_coding_scheme);
        virtual ~UssdRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const WString& GetControlInfo() const { return m_control_info; }
        const DataCodingScheme& GetDataCodingScheme() const { return m_data_coding_scheme; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18551
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        WString m_control_info;
        DataCodingScheme m_data_coding_scheme;
        
    };


/*  ======================================================================
    Class UssdNotifyMsg
    ====================================================================== */

class UssdNotifyMsg : public SsMessage {
    public:
        UssdNotifyMsg(ExecutionContext* context, const Tipd& tipd, const WString& control_info, const DataCodingScheme& data_coding_scheme);
        virtual ~UssdNotifyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const WString& GetControlInfo() const { return m_control_info; }
        const DataCodingScheme& GetDataCodingScheme() const { return m_data_coding_scheme; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18552
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        WString m_control_info;
        DataCodingScheme m_data_coding_scheme;
        
    };


/*  ======================================================================
    Class UssdEndMsg
    ====================================================================== */

class UssdEndMsg : public SsMessage {
    public:
        UssdEndMsg(ExecutionContext* context, const Tipd& tipd);
        virtual ~UssdEndMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18553
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        
    };


/*  ======================================================================
    Class UssdDataMsg
    ====================================================================== */

class UssdDataMsg : public SsMessage {
    public:
        UssdDataMsg(ExecutionContext* context, const Tipd& tipd, const WString& data, const DataCodingScheme& data_coding_scheme);
        virtual ~UssdDataMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        const WString& GetData() const { return m_data; }
        const DataCodingScheme& GetDataCodingScheme() const { return m_data_coding_scheme; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18555
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        WString m_data;
        DataCodingScheme m_data_coding_scheme;
        
    };


/*  ======================================================================
    Class UssdRequestResentMsg
    ====================================================================== */

class UssdRequestResentMsg : public SsMessage {
    public:
        UssdRequestResentMsg(ExecutionContext* context, const Tipd& new_tipd, const Tipd& old_tipd);
        virtual ~UssdRequestResentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetNewTipd() const { return m_new_tipd; }
        const Tipd& GetOldTipd() const { return m_old_tipd; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18556
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_new_tipd;
        Tipd m_old_tipd;
        
    };


/*  ======================================================================
    Class GetPasswordMsg
    ====================================================================== */

class GetPasswordMsg : public SsMessage {
    public:
        GetPasswordMsg(ExecutionContext* context, const Tipd& tipd, CallBarringHandler* handler);
        virtual ~GetPasswordMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        CallBarringHandler* GetHandler() const { return m_handler; }
        void SendPassword(const WString& password) { GetHandler()->SendPassword(GetTipd(), password); }
        void Abort() { GetHandler()->AbortPasswordRequest(GetTipd()); }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18559
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        CallBarringHandler* m_handler;
        
    };


/*  ======================================================================
    Class UusStatusMsg
    ====================================================================== */

class UusStatusMsg : public SsMessage {
    public:
        UusStatusMsg(ExecutionContext* context, const SsCode& ss_code, const Vector<UusText>& text_list);
        virtual ~UusStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const SsCode& GetSsCode() const { return m_ss_code; }
        const Vector<UusText>& GetTextList() const { return m_text_list; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18567
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsCode m_ss_code;
        Vector<UusText> m_text_list;
        
    };


/*  ======================================================================
    Class UusQueryRejectedMsg
    ====================================================================== */

class UusQueryRejectedMsg : public SsMessage {
    public:
        UusQueryRejectedMsg(ExecutionContext* context);
        virtual ~UusQueryRejectedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 18569
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class UusNotificationMsg
    ====================================================================== */

class UusNotificationMsg : public SsMessage {
    public:
        UusNotificationMsg(ExecutionContext* context, const SsCode& ss_code, const WString& text, const UusInTextType& type);
        virtual ~UusNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const SsCode& GetSsCode() const { return m_ss_code; }
        const WString& GetText() const { return m_text; }
        const UusInTextType& GetType() const { return m_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18568
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsCode m_ss_code;
        WString m_text;
        UusInTextType m_type;
        
    };


/*  ======================================================================
    Class UusRegisteredMsg
    ====================================================================== */

class UusRegisteredMsg : public SsMessage {
    public:
        UusRegisteredMsg(ExecutionContext* context, const SsCode& ss_code, const WString& text, const UusOutTextType& type);
        virtual ~UusRegisteredMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const SsCode& GetSsCode() const { return m_ss_code; }
        const WString& GetText() const { return m_text; }
        const UusOutTextType& GetType() const { return m_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18571
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsCode m_ss_code;
        WString m_text;
        UusOutTextType m_type;
        
    };


/*  ======================================================================
    Class UusErasedMsg
    ====================================================================== */

class UusErasedMsg : public SsMessage {
    public:
        UusErasedMsg(ExecutionContext* context, const SsCode& ss_code, const UusOutTextType& type);
        virtual ~UusErasedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const SsCode& GetSsCode() const { return m_ss_code; }
        const UusOutTextType& GetType() const { return m_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 18572
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SsCode m_ss_code;
        UusOutTextType m_type;
        
    };


/*  ======================================================================
    Class UssdBeginMsg
    ====================================================================== */

class UssdBeginMsg : public Message {
    public:
        UssdBeginMsg(const Tipd& tipd, const SsStackMsgArgument& argument);
        virtual ~UssdBeginMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Tipd& GetTipd() const { return m_tipd; }
        SsApiRc BeginTransaction();
        virtual Message* Clone() const;
        
        enum  {
            ID = 18554
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Tipd m_tipd;
        SsStackMsgArgument m_argument;
        
    };

#endif // Asc_StackIndicationMsgTypes_hpp

