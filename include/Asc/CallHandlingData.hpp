/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CallHandlingData_hpp)
#define Asc_CallHandlingData_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Asc/Types.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/SimDataTypes.hpp>

enum ChannelState {
    NoCall ,
    ActiveCall,
    HeldCall,
    SetupCall
    } ;


class CallInstance {
    public:
        CallInstance();

        ~CallInstance();

        Tipd GetTipd() const { return m_tipd; }

        void SetTipd(Tipd tipd) { m_tipd = tipd; }

        CallType GetType() const { return m_type; }

        void SetType(CallType type) { m_type = type; }

        UINT32 GetStartTime() const { return m_start_time_in_sec; }

        void SetStartTime(UINT32 abs_sec) { m_start_time_in_sec = abs_sec; }

        void SetStartTic(Ticks start_tic) { m_start_tic = start_tic; }

        const Ticks & GetStartTic() const { return m_start_tic; }

        PhoneNumber & GetPhoneNo() { return m_dialled_phone_no; }

        void SetPhoneNo(const PhoneNumber & phone_no) { m_dialled_phone_no = phone_no; }

        // Author: rre (17.03.2003)
        LineSelector GetCallLine() const { return m_call_line; }

        // Author: rre (17.03.2003)
        void SetCallLine(LineSelector call_line) { m_call_line = call_line; }

        // Author: rre (12.09.2003)
        Application* GetRelatedApp() const { return m_related_app; }

        // Author: rre (12.09.2003)
        void SetRelatedApp(Application* app) { m_related_app = app; }
        
        CallRelatedSsCode GetSsCode() const { return m_ss_code; }
        
        void SetSsCode (CallRelatedSsCode code) { m_ss_code = code; }
        
        GsmSignal GetGsmSignal() const { return m_gsm_signal; }

        void SetGsmSignal(GsmSignal signal) { m_gsm_signal = signal; }
        
        const PhoneNumber * GetConnectedToNo() const { return m_connected_to_no_p; }
        void SetConnectedToNo(PhoneNumber * no_p) { m_connected_to_no_p = no_p; }

#ifdef APOXI_CTM
        void SetCtm(BOOLEAN ctm){ m_ctm = ctm;}
        BOOLEAN GetCtm(){return m_ctm;}
#endif

        void SetEstablishCause(CallEstCause est_cause){m_est_cause = est_cause;}
        CallEstCause GetEstablishCause(){ return m_est_cause;}

        BOOLEAN GetDisconnectingSent() const {return m_disconnecting_sent; }

        void SetDisconnectingSent(BOOLEAN disconnecting_sent) { m_disconnecting_sent = disconnecting_sent; }
        
        void SetActiveRelease(BOOLEAN active_release) { m_active_release = active_release; }

        BOOLEAN IsActiveRelease(){ return m_active_release; }

        BOOLEAN GetSetupIndArrived(){ return m_setup_ind_arrived; }

        void SetSetupIndArrived(BOOLEAN setup_ind_arrived = TRUE){ m_setup_ind_arrived = setup_ind_arrived; }

        ClirMode GetClirMode() { return m_clir_mode; }

        void SetClirMode(ClirMode clir_mode) { m_clir_mode = clir_mode; }

        void SetEccCategory(EccCategory ecc_category) { m_ecc_category = ecc_category; }

        EccCategory GetEccCategory() { return m_ecc_category; }
        
        void SetCallControlPerformed(BOOLEAN call_control_performed) {m_call_control_performed = call_control_performed; }

        BOOLEAN IsCallControlPerformed() { return m_call_control_performed; }

        void SetCallControlResult(SimCallControlResult call_control_result) {m_call_control_result = call_control_result; }

        SimCallControlResult GetCallControlResult() {return m_call_control_result; }

        void SetAlphaIdentifier(SimAlphaIdentifier alpha_identifier) {m_alpha_identifier = alpha_identifier; }

        SimAlphaIdentifier GetAlphaIdentifier() {return m_alpha_identifier; }


    private:
        Tipd                m_tipd;
        CallType            m_type;
        UINT32              m_start_time_in_sec;
        Ticks               m_start_tic;
        CallRelatedSsCode   m_ss_code;
        GsmSignal           m_gsm_signal;
        PhoneNumber         m_dialled_phone_no;
        PhoneNumber *       m_connected_to_no_p;
        // Author: rre (17.03.2003) value for speech line or auxiliary speech line
        LineSelector        m_call_line; 
#ifdef APOXI_CTM
        BOOLEAN         m_ctm;
#endif
        Application *       m_related_app;
        BOOLEAN             m_disconnecting_sent;

        CallEstCause        m_est_cause;

        BOOLEAN             m_setup_ind_arrived;
        BOOLEAN             m_active_release;

        ClirMode            m_clir_mode;

        EccCategory         m_ecc_category;

        BOOLEAN                 m_call_control_performed;
        SimCallControlResult    m_call_control_result;
        SimAlphaIdentifier      m_alpha_identifier;
};


class ChannelInstance {
    public:
        ChannelInstance();

        ~ChannelInstance();

        CallIndex GetCallIndex(INT pos) const { return m_call_indices[pos]; }

        void SetCallIndex(INT pos, CallIndex call_index) { m_call_indices[pos] = call_index; }

        ChannelState GetState() const { return m_state; }

        void SetState(ChannelState state) { m_state = state; }
        
        BOOLEAN GetMptyFlag() const { return m_is_mpty; }
        
        void SetMptyFlag(BOOLEAN mpty) { m_is_mpty = mpty; }
        

        INT GetCallIndexPos(CallIndex call_index) const;

        CallIndex const * GetCallIndices() const { return m_call_indices; }

        CallIndex GetFirstCallIndex() const;

    private:
        CallIndex       m_call_indices[c_max_mpty_members];
        ChannelState    m_state;
        BOOLEAN         m_is_mpty;

};
        
#endif // DOXYGEN_SHOULD_SKIP_THIS

class CallHandlingData {
    public:
            
#ifndef DOXYGEN_SHOULD_SKIP_THIS

        CallHandlingData(); 

        virtual  ~CallHandlingData();



        UINT32 GetMptyCallStartTime() { return m_mpty_call_start_time; }


        void SetMptyCallStartTime(UINT32 sec) { m_mpty_call_start_time = sec; }

        void SetRequestedMocIndex(CallIndex idx) { m_requested_moc_index = idx; }


        CallIndex RequestNextMocIndex();
    
        void InsertRequestedMoc(CallIndex call_index, Tipd tipd);


        void InsertWaitingMtc(Tipd tipd);
    

        void SetMtcWaiting(Tipd tipd);
        

        void SetCallActive(CallIndex call_index);
        

        void SetCallHold(CallIndex call_index);

#endif // DOXYGEN_SHOULD_SKIP_THIS
        
        BOOLEAN IsActiveCall(CallIndex call_index) const;


        BOOLEAN IsHeldCall(CallIndex call_index) const;

        
        BOOLEAN IsInSetupCallIndex(CallIndex call_index) const;
        

        BOOLEAN IsMtc(CallIndex call_index) const;
        
#ifndef DOXYGEN_SHOULD_SKIP_THIS

        UINT32 CleanUpCallData(CallIndex call_index);

        Tipd GetTipd(CallIndex call_index) const;

        CallIndex GetCallIndexByTipd(Tipd tipd) const;

        CallIndex GetActiveCallIndex() const;

        CallIndex GetHeldCallIndex() const;

        CallIndex GetSetupCallIndex() const;

        CallIndex GetRequestedCallIndex() const { return m_requested_moc_index; };

        ChannelNo GetMptyChannelNo() const;

        CallIndex GetMptyCallIndex() const;

#endif // DOXYGEN_SHOULD_SKIP_THIS

        BOOLEAN IsSpeechCall(CallIndex call_index) const;


        BOOLEAN IsMptyCall(CallIndex call_index) const;

        
        BOOLEAN IsActiveMpty(ChannelNo channel_no) const; 

        BOOLEAN IsHeldMpty(ChannelNo channel_no) const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        INT CountMptyMembers(ChannelNo channel_no) const;

        
        const CallIndex* GetMptyMembers() const;
    
        void SaveStartTime(CallIndex call_index);
        

        UINT32 GetCallConnectionTime(CallIndex call_index) const;


        CallInstance & GetCallInstance(CallIndex call_index) { return m_call_instances[call_index]; }


        void JoinCalls();

        void SplitMpty(CallIndex call_index);


        // --------------------------------------------------------------------
        // PreAction checks
        // --------------------------------------------------------------------

        CallApiRc CheckMocRestrictions() const;

        CallApiRc CheckAcceptRestrictions(CallIndex call_index) const;
        
        CallApiRc CheckHoldRestrictions(CallIndex call_index) const;

        CallApiRc CheckRetrieveRestrictions(CallIndex call_index) const;
        
        CallApiRc CheckSwapCallsRestrictions() const;

        CallApiRc CheckJoinCallsRestrictions() const;
    
        CallApiRc CheckSplitMptyRestrictions(CallIndex call_index) const;

        CallApiRc CheckDtmfRestrictions(CallIndex call_index) const;

        CallApiRc CheckEctRestrictions(CallIndex call_index) const;

        CallApiRc CheckDataCallRestrictions() const;
#endif // DOXYGEN_SHOULD_SKIP_THIS
        
        BOOLEAN ActiveCallExists() const;
        
        BOOLEAN HeldCallExists() const;
        
        BOOLEAN CallInSetupExists() const;

        Tipd GetSsTipd() const { return m_ss_tipd; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        void SetSsTipd(Tipd tipd) { m_ss_tipd = tipd; }
        
        BOOLEAN IsSsPending() { return m_ss_pending; }
        void SetSsPending(BOOLEAN pending) { m_ss_pending = pending; }

        // 
        BOOLEAN IsSimSsPending() { return m_sim_ss_pending; }
        void SetSimSsPending(BOOLEAN pending) { m_sim_ss_pending = pending; }

        BOOLEAN IsDataCallActive() const { return m_data_call_active; }
        void SetDataCallActive(BOOLEAN active) { m_data_call_active = active; }

        INT GetCallCount() const;

        BOOLEAN IsDisconnectingSent(CallIndex call_index) { return m_call_instances[call_index].GetDisconnectingSent(); }

        void SetDisconnectingSent(CallIndex call_index) { m_call_instances[call_index].SetDisconnectingSent(TRUE); }

        void SetActiveRelease(CallIndex call_index) { m_call_instances[call_index].SetActiveRelease(TRUE); }

        BOOLEAN IsActiveRelease(CallIndex call_index) { return m_call_instances[call_index].IsActiveRelease(); }


#endif // DOXYGEN_SHOULD_SKIP_THIS

        static CallErrorCause GetLastMnError() {return m_last_mn_error; }
#ifndef DOXYGEN_SHOULD_SKIP_THIS

        static void SetLastMnError(CallErrorCause code) { m_last_mn_error = code; }

#if !defined(NO_CALL_DEBUG) 

        const ChannelInstance * GetChannels() const {return &m_channels[0]; }
#endif // NO_CALL_DEBUG

        void SetMptyStartTic(Ticks start_tic) { m_mpty_call_start_tic = start_tic; }

        const Ticks & GetMptyStartTic() const { return m_mpty_call_start_tic; }

    private:
        ChannelNo GetChannelNo(CallIndex call_index) const;
        ChannelNo GetActiveChannelNo() const;
        CallIndex GetNextFreeCallIndex(BOOLEAN mtc_call_index) const;
        CallIndex RequestNextMtcIndex();
        void InsertNewCall(CallIndex call_index, Tipd tipd);
        void CleanUpCallInstance(CallIndex call_index);
        void ClearChannel(ChannelNo channel_no);
        void RemoveCall(CallIndex call_index);
        
        UINT32          m_mpty_call_start_time; // in absolute seconds
        CallIndex       m_requested_moc_index;
        CallIndex       m_waiting_mtc_index;
        CallInstance    m_call_instances[c_max_calls];
        ChannelInstance m_channels[c_max_channels];
        Tipd            m_ss_tipd;
        BOOLEAN         m_ss_pending;
        BOOLEAN         m_sim_ss_pending;  
        BOOLEAN         m_data_call_active;
        static CallErrorCause   m_last_mn_error;

        Ticks           m_mpty_call_start_tic;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif  // Asc_CallHandlingData_hpp

