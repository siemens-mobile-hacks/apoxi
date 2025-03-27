/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "hartmanw_mpeutest_sv\lnz_apoxi\Apoxi\AddOns\MmCall\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(MmCallMessages_hpp__ST_1136454671281)
#define MmCallMessages_hpp__ST_1136454671281
#include <Kernel/Message.hpp>
#include <Asc/Types.hpp>
#include <Apc/SignalTypes.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <AddOns/MmCall/MmTypes.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class MmCallStatusMsg
    ====================================================================== */
class MmCallStatusMsg : public ContextMsg {
    public:
        MmCallStatusMsg(ExecutionContext* context, const MmCallState& state, const CallIndex& call_index);
        virtual ~MmCallStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const MmCallState& GetState() const { return m_state; }
        const CallIndex& GetCallIndex() const { return m_call_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19110
            };
        
    private:
        static const MsgMetaData m_meta_data;
        MmCallState m_state;
        CallIndex m_call_index;
        
    };
/*  ======================================================================
    Class MmCallDisconnectingMsg
    ====================================================================== */
class MmCallDisconnectingMsg : public MmCallStatusMsg {
    public:
        MmCallDisconnectingMsg(ExecutionContext* context, const MmCallState& state, const CallIndex& call_index, const PhoneNumber& phone_number, const CallErrorCause& error_cause, UINT32 call_duration_in_secs);
        virtual ~MmCallDisconnectingMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const PhoneNumber& GetPhoneNumber() const { return m_phone_number; }
        const CallErrorCause& GetErrorCause() const { return m_error_cause; }
        UINT32 GetCallDurationInSecs() const { return m_call_duration_in_secs; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19111
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PhoneNumber m_phone_number;
        CallErrorCause m_error_cause;
        UINT32 m_call_duration_in_secs;
        
    };
/*  ======================================================================
    Class MmMocSetupAcceptMsg
    ====================================================================== */
class MmMocSetupAcceptMsg : public MmCallStatusMsg {
    public:
        MmMocSetupAcceptMsg(ExecutionContext* context, const MmCallState& state, const CallIndex& call_index, BOOLEAN est_cause_changed);
        virtual ~MmMocSetupAcceptMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        BOOLEAN IsEstCauseChanged() const { return m_est_cause_changed; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19112
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_est_cause_changed;
        
    };
/*  ======================================================================
    Class MmCallSetupProgressMsg
    ====================================================================== */
class MmCallSetupProgressMsg : public MmCallStatusMsg {
    public:
        MmCallSetupProgressMsg(ExecutionContext* context, const MmCallState& state, const CallIndex& call_index, const CallProgressInd& progress_indication);
        virtual ~MmCallSetupProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallProgressInd& GetProgressIndication() const { return m_progress_indication; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19113
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallProgressInd m_progress_indication;
        
    };
/*  ======================================================================
    Class MmCallInfoMsg
    ====================================================================== */
class MmCallInfoMsg : public ContextMsg {
    public:
        MmCallInfoMsg(ExecutionContext* context, const CallIndex& call_index, const CallState& call_state, const CallType& call_type);
        virtual ~MmCallInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        const CallState& GetCallState() const { return m_call_state; }
        const CallType& GetCallType() const { return m_call_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19114
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        CallState m_call_state;
        CallType m_call_type;
        
    };
/*  ======================================================================
    Class MmCallNotifyMsg
    ====================================================================== */
class MmCallNotifyMsg : public ContextMsg {
    public:
        MmCallNotifyMsg(ExecutionContext* context, const CallIndex& call_index, const NotificationDescription& notification_description);
        virtual ~MmCallNotifyMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        const NotificationDescription& GetNotificationDescription() const { return m_notification_description; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19115
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        NotificationDescription m_notification_description;
        
    };
/*  ======================================================================
    Class MmCurrentChargeDataMsg
    ====================================================================== */
class MmCurrentChargeDataMsg : public ContextMsg {
    public:
        MmCurrentChargeDataMsg(ExecutionContext* context, const CallIndex& call_index, const AocChargeData& current_call_charge, const AocChargeData& accumulated_call_charge);
        virtual ~MmCurrentChargeDataMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        const AocChargeData& GetCurrentCallCharge() const { return m_current_call_charge; }
        const AocChargeData& GetAccumulatedCallCharge() const { return m_accumulated_call_charge; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19116
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        AocChargeData m_current_call_charge;
        AocChargeData m_accumulated_call_charge;
        
    };
/*  ======================================================================
    Class MmCurrentCallMeterMsg
    ====================================================================== */
class MmCurrentCallMeterMsg : public ContextMsg {
    public:
        MmCurrentCallMeterMsg(ExecutionContext* context, const CallIndex& call_index, ULONG current_call_ccm, ULONG accumulated_call_ccm);
        virtual ~MmCurrentCallMeterMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        ULONG GetCurrentCallCcm() const { return m_current_call_ccm; }
        ULONG GetAccumulatedCallCcm() const { return m_accumulated_call_ccm; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19117
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        ULONG m_current_call_ccm;
        ULONG m_accumulated_call_ccm;
        
    };
/*  ======================================================================
    Class MmAocChargingStatusMsg
    ====================================================================== */
class MmAocChargingStatusMsg : public ContextMsg {
    public:
        MmAocChargingStatusMsg(ExecutionContext* context, const CallIndex& call_index, const AocChargingStatus& aoc_charging_status);
        virtual ~MmAocChargingStatusMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        const AocChargingStatus& GetAocChargingStatus() const { return m_aoc_charging_status; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19118
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        AocChargingStatus m_aoc_charging_status;
        
    };
/*  ======================================================================
    Class MmCallAcceptMsg
    ====================================================================== */
class MmCallAcceptMsg : public Message {
    public:
        MmCallAcceptMsg(const CallIndex& call_index);
        virtual ~MmCallAcceptMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19119
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        
    };
/*  ======================================================================
    Class MmCallReleaseMsg
    ====================================================================== */
class MmCallReleaseMsg : public Message {
    public:
        MmCallReleaseMsg(const CallIndex& call_index);
        virtual ~MmCallReleaseMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const CallIndex& GetCallIndex() const { return m_call_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 19120
            };
        
    private:
        static const MsgMetaData m_meta_data;
        CallIndex m_call_index;
        
    };
#endif // MmCallMessages_hpp__ST_1136454671281

