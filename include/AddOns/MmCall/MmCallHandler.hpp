/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_MmCallHandler_hpp)
#define Apoxi_MmCallHandler_hpp

#include <Kernel/Types.hpp>
#include <Asc/Types.hpp>
#include <Asc/BaseHandler.hpp>
#include <AddOns/MmCall/SerialTerminal.hpp>
#include <AddOns/MmCall/AtResponseIterator.hpp>
#include <AddOns/MmCall/MmTypes.hpp>
#include <AddOns/MmCall/MmCallInfo.hpp>
#include <AddOns/MmCall/MmCallDispatcher.hpp>
#include <AddOns/MmCall/MmCallSerialTerminalListener.hpp>


#ifndef APOXI_CONFIG_MAX_MM_CALLS
    #define APOXI_CONFIG_MAX_MM_CALLS 2
#endif


const UINT  c_mm_call_terminal_speed = 64000;

const UINT8  c_mm_call_terminal_stop_bits = 1;

const UINT8  c_mm_call_terminal_data_bits = 8;

class MmCallHandler : public BaseHandler {
    
    typedef BaseHandler Base;
    friend MmCallDispatcher;
    public:
        
        MmCallHandler();
        virtual ~MmCallHandler();

        virtual HandlerId GetHandlerId() const { return MmCallHandlerId; };

        CallApiRc Setup(const CallIndex call_index, const PhoneNumber &phone_no, ClirMode clir_mode = DontCare);

        CallApiRc Accept(const CallIndex call_index);  

        #if defined(APOXI_SYNC_RELEASE)
            CallApiRc Reject(const CallIndex call_index, ClearCause cause = SubscriberBusy, BOOLEAN wait_condition = TRUE);
        #else
            CallApiRc Reject(const CallIndex call_index, ClearCause cause = SubscriberBusy, BOOLEAN wait_condition = FALSE);
        #endif

        CallApiRc RejectAllMtc(BOOLEAN activate);       

        #if defined(APOXI_SYNC_RELEASE)
            virtual CallApiRc Release(const CallIndex call_index, TimeSpan *calling_time = 0, BOOLEAN wait_condition = TRUE);
        #else
            virtual CallApiRc Release(const CallIndex call_index, TimeSpan *calling_time = 0, BOOLEAN wait_condition = FALSE);
        #endif

        
        void ReportCurrentCallMeter(BOOLEAN activate);


        void ReportCurrentCharge(BOOLEAN activate);

        CallApiRc GetCurrentChargeData(const CallIndex call_index);
                    

        CallApiRc GetCurrentCallMeter(const CallIndex call_index);

        Socket *GetSocket(CallIndex call_index);

        BOOLEAN IsMmCall(CallIndex call_index) const;

        BOOLEAN IsMobileOriginated(CallIndex call_index) const;


        BOOLEAN IsMobileTerminated(CallIndex call_index) const;

        BOOLEAN IsInOnlineMode(SerialTerminal *terminal);

        void OnTerminalResponse(SerialTerminal *terminal, const AtResponse &response);

        BOOLEAN IsPsdCallActive();
        
        void DisconnectActivePsdCalls();

    private:
        void OnXCallStat(UINT8 call_id, XCallStat call_stat_value);
        
        void OnXCallInfo(const AtResponse &response);

        
        void OnXProgress(INT call_id, INT tones_available);

        void OnCRing();

        void OnColp(const CHAR *phonenumber);
        
        void OnConnect(SerialTerminal *terminal);

        void OnXcaoc(const String& accumulated_call_meter, const String& current_call_meter);

        void OnXcharge(const String& accumulated_charge_data, const INT exponent_accumulated_charge_data, 
                    const String& current_charge_data, const INT exponent_current_charge_data);


        void OnXcccm(const String& accumulated_call_meter, const String& current_call_meter);

        void OnXccharge(const String& accumulated_charge_data, const INT exponent_accumulated_charge_data, 
                    const String& current_charge_data, const INT exponent_current_charge_data);

        void OnXaocService(const Tipd tipd, const INT service_state);


        void OnCgact();

        void SendMmCurrentCallMeterMsg(const CallIndex call_index);

        void SendMmCurrentChargeDataMsg(const CallIndex call_index);

        virtual BOOLEAN Init(MainHandler *main_handler);

        void SendCallEventMsg(CallEvent::Action action, CallIndex call_index);

        CallApiRc CloseCall(CallIndex call_index, 
                            UINT32 &call_duration, 
                            CallErrorCause cause, 
                            BOOLEAN wait_condition);

        BOOLEAN InitControlTerminal();

        BOOLEAN AddCallInfo(CallIndex call_index);

        BOOLEAN InvalidateCallInfo(CallIndex call_index);

        const MmCallInfo *GetCallInfo(CallIndex call_index) const;

        MmCallInfo *GetCallInfo(CallIndex call_index);

        INT16 GetCallIdForIndex(CallIndex call_index) const;

        CallIndex GetCallIndexForId(UINT8 call_id) const;

        CallIndex GetIndexForTerminal(SerialTerminal *terminal) const;

        AtResponse WriteAtCmd(const AtCommand &command, SerialTerminal *terminal);

        AtResponse WaitForAtResponse(SerialTerminal *terminal);

        static UINT32 ConvertCccmValue(const String& hex_string);

        AtResponse                          m_received_response;

        SerialTerminal*                     m_control_terminal;
        
        MmCallInfo                          m_call_info[APOXI_CONFIG_MAX_MM_CALLS];

        // Hack to simulate missing "CONNECT" from stack
        BooleanCondition                    m_wait_for_data;
        
        BOOLEAN                             m_waiting_for_data_term_resp;
        
        BooleanCondition                    m_wait_for_control_data;

        BooleanCondition                    m_wait_for_disconnect_conf;

        BOOLEAN                             m_wait_for_disconnect;

        MmCallDispatcher                    m_mm_call_dispatcher;

        AtResponse                          m_last_call_setup_xcallinfo_response;
        
        MmCallSerialTerminalListener        m_mm_call_st_listener;

        UINT32                              m_current_call_meter;

        UINT32                              m_accumulated_call_meter;

        UINT32                              m_current_call_charge;
        
        UINT32                              m_accumulated_charge;

        INT                                 m_current_call_charge_exponent;
        
        INT                                 m_accumulated_charge_exponent;

        // TODO: Check number of PSD calls
        BOOLEAN                             m_is_psd_call_active;

        static const AtCommandData          c_init_sequence[];

        static const INT                    c_no_of_init_params;

        static const INT                    c_no_of_response_checks;
};      


#endif // Apoxi_MmCallDispatcher_hpp


