/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS 

#if !defined(Asc_CallDispatcher_hpp)
#define Asc_CallDispatcher_hpp

#include <Asc/StackMsgDispatcher.hpp>
#include <Asc/TipdBasedActiveWaitDispatcher.hpp>
#include <Audio/AudioActiveReference.hpp>
#include <Apc/StackMsgArgument.hpp>
#include <Asc/Types.hpp>

class CallDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        CallDispatcher();
        
        virtual ~CallDispatcher();


        CallErrorCause GetDiscCause() const { return m_call_disc_cause; }
        
        
        void ResetDiscCause() { m_call_disc_cause = NoCallError; }


        BOOLEAN GetMtcIsReady() const { return m_mtc_is_ready; }
        

        void SetMtcReady() { m_mtc_is_ready = TRUE; }


        void RegisterActiveWaitDisp(TipdBasedActiveWaitDispatcher * disp) {m_wait_disp = disp;}
        

        void UnregisterActiveWaitDisp() { m_wait_disp = 0; }


        BOOLEAN RemoveDisconnectedCall(Tipd tipd, CallErrorCause cause, BOOLEAN msg_required, DisconnectingMode disconnecting_mode = NetWorkDisconnection);
        
        void AbortWaitDispIfEqualTipd(Tipd tipd, TipdBasedActiveWaitDispatcher::AbortCause cause);
        
        BOOLEAN IsEqualWaitDispTipd(Tipd tipd);


    protected:
        BOOLEAN OnCallDiscInd(const StackMsgArgument &arg);


        BOOLEAN OnCallDiscCnf(const StackMsgArgument &arg);


        BOOLEAN OnCallRelInd(const StackMsgArgument &arg);

        BOOLEAN OnCallRelCnf(const StackMsgArgument &arg);
    
        BOOLEAN OnCallProgressInd(const StackMsgArgument &arg);

#if defined(APOXI_AT_MMI_INTERWORKING_CALL)

        BOOLEAN OnCallInd(const StackMsgArgument &arg);
#endif

        BOOLEAN OnCallNotify(const StackMsgArgument &arg);


        BOOLEAN OnAlertInd(const StackMsgArgument &arg);

        
        BOOLEAN OnMocSetupCnf(const StackMsgArgument &arg);

        BOOLEAN OnMocSetupRej(const StackMsgArgument &arg);
        
#ifdef APOXI_CTM

        BOOLEAN OnCtmInfoIndMsg(const StackMsgArgument &arg);
#endif

        BOOLEAN OnNwDiscStartInd(const StackMsgArgument &arg);
        
        BOOLEAN OnDiagnosticInd(const StackMsgArgument &arg);
        
        BOOLEAN OnRedialStatusInd(const StackMsgArgument &arg);
#if defined(APOXI_AT_MMI_INTERWORKING_REJECT)

        BOOLEAN OnMocSetupRejInd(const StackMsgArgument &arg);
#endif
        
#if defined(APOXI_AT_MMI_INTERWORKING_SIMTK)

        BOOLEAN OnCallIndCallControlInfo(const StackMsgArgument &arg);
#endif
    private:
        void StopInfoTone();
        void StartInfoTone();


        static const StackMsgArgMap<CallDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CallDispatcher> m_arg_map_container;
        
        BOOLEAN                         m_mtc_is_ready;
        CallErrorCause                  m_call_disc_cause;
        TipdBasedActiveWaitDispatcher * m_wait_disp;

        SharedPtr<AudioActiveReference> m_active_ref;
};


#endif // Asc_CallDispatcher_hpp

#endif //DOXYGEN_SHOULD_SKIP_THIS 


