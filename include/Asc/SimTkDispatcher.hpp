/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_SimTkDispatcher_hpp)
#define Asc_SimTkDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    SimTkDispatcher
    ======================================================================== */
class SimTkDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

    friend class SimTkHandler;
    public:
        SimTkDispatcher();
        virtual ~SimTkDispatcher();

        UINT8 GetSimCallSetupOption() const { return m_sim_command_qualifier; }
        const PhoneNumber & GetStkCallSetupNo() const { return m_stk_phone_no; }


    protected:
        BOOLEAN OnSimTkSmsPpInd(const StackMsgArgument &arg);
        BOOLEAN OnSimTkSsInd(const StackMsgArgument &arg);

        BOOLEAN OnSimTkRefreshQueryReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkRefreshCnfReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkRefreshReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkRefreshNewReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkRefreshResetReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkResetCnfReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkResetCnf(const StackMsgArgument &arg);

        BOOLEAN OnDisplayTextReq(const StackMsgArgument &arg);
        BOOLEAN OnGetInputReq(const StackMsgArgument &arg);
        BOOLEAN OnGetInkeyReq(const StackMsgArgument &arg);
        BOOLEAN OnSelectItemReq(const StackMsgArgument &arg);
        BOOLEAN OnSetupMenuReq(const StackMsgArgument &arg);            // menu is stored in ADC
        BOOLEAN OnMenuSelectionRej(const StackMsgArgument &arg);
        BOOLEAN OnPlayToneReq(const StackMsgArgument &arg);
        BOOLEAN OnSetupIdleModeTextReq(const StackMsgArgument &arg);
        BOOLEAN OnEndSimToolkitInd(const StackMsgArgument &arg);
        BOOLEAN OnSimTkCallSetupInd(const StackMsgArgument &arg);
        BOOLEAN OnSimTkSetupEventReq(const StackMsgArgument &arg);
        BOOLEAN OnSimTkLanguageNotificationInd(const StackMsgArgument &arg);
        BOOLEAN OnLanguageSettingReq(const StackMsgArgument &arg);
        BOOLEAN OnCallControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnSsControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnUssdControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnSmsControlIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnTermRspCnfMsg(const StackMsgArgument &arg);
        BOOLEAN OnSimLaunchBrowserReqMsg(const StackMsgArgument &arg);
        BOOLEAN OnSimLaunchBrowserPromptReqMsg(const StackMsgArgument &arg);
        BOOLEAN OnSimBrowserTermResMsg(const StackMsgArgument &arg);
        BOOLEAN OnSimTkRunAtCmdInfoIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnSimTkSendDtmfIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnSimTkSendDtmfEndIndMsg(const StackMsgArgument &arg);
        BOOLEAN OnGetTermProfileCnf(const StackMsgArgument &arg);
        BOOLEAN OnSetTermProfileCnf(const StackMsgArgument &arg);
        BOOLEAN OnSetTermProfileRej(const StackMsgArgument &arg);


    private:
        static const StackMsgArgMap<SimTkDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SimTkDispatcher> m_arg_map_container;
        UINT8        m_sim_command_qualifier;
        BOOLEAN      m_events_present;
        PhoneNumber  m_stk_phone_no;
        SimEventList m_event_list;

        BOOLEAN SendSimTkRefreshRsp();
        BOOLEAN IsAllowedPostSendingRefreshRsp(const SimEfRefresh & efrefresh);

        SimTkTransactionId m_tid;
        ProactiveCause     m_cause;
        BOOLEAN            m_allow_post_sending_refresh_rsp;
};

#endif // Asc_SimTkDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


