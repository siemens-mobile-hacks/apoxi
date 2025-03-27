/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS 

#if !defined(Asc_CrssDispatcher_hpp)
#define Asc_CrssDispatcher_hpp

// #include <Asc/StackMsgActiveWaitDispatcher.hpp>
#include <Asc/TipdBasedActiveWaitDispatcher.hpp>

//lint -esym(1712,CrssDispatcher)
class CrssDispatcher : public TipdBasedActiveWaitDispatcher {
    public:
        typedef TipdBasedActiveWaitDispatcher Base;

        explicit CrssDispatcher(Tipd tipd, Tipd swap_held_tipd = c_null_tipd);

        virtual ~CrssDispatcher();


        BOOLEAN CrssRejReceived() const { return m_crss_rej_received; }
        

        SsErrorCode GetSsErrorCode() const { return m_error_code; }
        

        CallRelatedSsState GetStatus() const { return m_status; }
        
        
        CallErrorCause GetHoldRejCause() const { return m_hold_rej_cause; }


        CallApiRc GetSwapResult() const { return m_swap_result; }

        
        BOOLEAN OnCrssRej(const StackMsgArgument &arg);


        BOOLEAN OnHoldRej(const StackMsgArgument &arg);


        BOOLEAN OnHoldCnf(const StackMsgArgument &arg);

        
        BOOLEAN OnMptyCnf(const StackMsgArgument &arg);


        BOOLEAN OnSsErrInd(const StackMsgArgument &arg);


        BOOLEAN OnEctCnf(const StackMsgArgument &arg);

        BOOLEAN OnSsRej(const StackMsgArgument &arg);

        virtual void AbortIfEqualTipd(Tipd tipd, AbortCause cause = NotSpecified);

        virtual BOOLEAN IsAborted();

    private:
        static const StackMsgArgMap<CrssDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CrssDispatcher> m_arg_map_container;
        Tipd                m_swap_held_tipd;
        BOOLEAN             m_execute_done; // signals the first part of m/swap already done
        BOOLEAN             m_crss_rej_received;
        BOOLEAN             m_disc_ind_received;
        SsErrorCode         m_error_code;
        
        CallRelatedSsState  m_status;
        CallErrorCause      m_hold_rej_cause;
        CallRelatedSs       m_call_related_ss;
        CallApiRc           m_swap_result;

        /*  Internal methods for checking if there is still an open response for an operation.
            In the moment it is just checking if there is a swap funciton where the current
            response is not the second response. Then it will return FALSE. In all other cases 
            it will return TRUE. */ 
        BOOLEAN CheckDonePermission();

        /*  This internal method must be called whenever there is a negativ response to a swap request.
            E.g.: from OnHoldRej, OnSsRej, OnCrssRej, OnSsErrInd, ..?
            If the request was a swap then this will be considered for the return value of swap.
            Return value will be TRUE if there is a swap in progress else FALSE */ 
        BOOLEAN SetSwapRejectResultForTipd(Tipd in_tipd);
};


// No action required for this method. Just a confirmation.
//      BOOLEAN OnCrssCnf(const StackMsgArgument &arg) { return FALSE; };

#endif  // Asc_CrssCnfRejDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS 


