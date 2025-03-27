/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SimDispatcher_hpp)
#define Asc_SimDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    SimDispatcher
    ======================================================================== */
class SimDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

    friend class SimHandler;

    public:
        SimDispatcher();
        virtual ~SimDispatcher();

    protected:
        BOOLEAN OnSimInfoInd(const StackMsgArgument &arg);
        BOOLEAN OnSimInitInd(const StackMsgArgument &arg);
        BOOLEAN OnSimFullAccessInd(const StackMsgArgument &arg);
        BOOLEAN OnSimLockStatusInd(const StackMsgArgument &arg);
        BOOLEAN OnSimErrorInd(const StackMsgArgument &arg);
        BOOLEAN OnSimRefreshInd(const StackMsgArgument &arg);
        BOOLEAN OnSimChvRefreshInd(const StackMsgArgument &arg);
        BOOLEAN OnMdhSmsInitFinishedInd(const StackMsgArgument & arg);
        BOOLEAN OnSimMccMncInd(const StackMsgArgument & arg);
        BOOLEAN OnFdnInd(const StackMsgArgument & arg);
        BOOLEAN OnBdnInd(const StackMsgArgument & arg);
        BOOLEAN OnCfuDataInd(const StackMsgArgument & arg);
        BOOLEAN OnEccListInd(const StackMsgArgument & arg);
        BOOLEAN OnSimMruPropertyRefreshInd(const StackMsgArgument &arg);

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)

        BOOLEAN OnUsimPbReadyInd(const StackMsgArgument & arg);
        BOOLEAN OnUsimPbReadAsyncInd(const StackMsgArgument & arg);
        BOOLEAN OnUsimPbReadDataAsyncInd(const StackMsgArgument & arg);
        BOOLEAN OnUsimPbReadRefAsyncInd(const StackMsgArgument & arg);
#endif

    private:
        static const StackMsgArgMap<SimDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SimDispatcher> m_arg_map_container;

        static BOOLEAN m_init_ind_running;
        static BOOLEAN m_full_access_recv;  
        static BOOLEAN m_alphatag_req_pending;  
        static PbRequestBehaviour m_pbrequesttype;  
        static BOOLEAN m_info_ind_running;
        static BOOLEAN m_init_ind_recv;
        static BOOLEAN m_dr_init_ind_recv;
        static SimInitIndArg m_sim_init_arg;



};

#endif // Asc_SimDispatcher_hpp

