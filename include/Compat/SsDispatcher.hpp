          /*    ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SsDispatcher_hpp)
#define Asc_SsDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    SimDispatcher
    ======================================================================== */
class SsDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        SsDispatcher();
        virtual ~SsDispatcher();

    protected:
        BOOLEAN OnSsForwardingInd(const StackMsgArgument &arg);
        BOOLEAN OnSsBarringInd(const StackMsgArgument &arg);
        BOOLEAN OnSsDataInd(const StackMsgArgument &arg);
        BOOLEAN OnSsNotifyInd(const StackMsgArgument &arg);
        BOOLEAN OnSsInterrogateInd(const StackMsgArgument &arg);
        BOOLEAN OnSsPasswordInd(const StackMsgArgument &arg);
        BOOLEAN OnSsUnstructInd(const StackMsgArgument &arg);
        BOOLEAN OnSsForwcheckInd(const StackMsgArgument &arg);
        BOOLEAN OnSsRetResInd(const StackMsgArgument &arg);
        BOOLEAN OnSsFacilityRej(const StackMsgArgument &arg);
        
        BOOLEAN OnSsEndInd(const StackMsgArgument &arg);
        BOOLEAN OnSsRej(const StackMsgArgument &arg);
        BOOLEAN OnSsErrInd(const StackMsgArgument &arg);
        BOOLEAN OnSsGetPasswordInd(const StackMsgArgument &arg);
        BOOLEAN OnSsGetPasswordRej(const StackMsgArgument &arg);
    
        BOOLEAN OnSsUssdInd(const StackMsgArgument &arg);

        BOOLEAN OnSsUssdResentInd(const StackMsgArgument &arg);
        BOOLEAN OnSsBeginAcc(const StackMsgArgument &arg);
        BOOLEAN OnSsCauseInd(const StackMsgArgument &arg);
#if defined(APOXI_AT_MMI_INTERWORKING_SS)

        BOOLEAN OnSsFacilityInd(const StackMsgArgument &arg);
#endif
#if defined(APOXI_AT_MMI_INTERWORKING_USSD)

        BOOLEAN OnUssdAnswerInd(const StackMsgArgument &arg);
#endif
    private:
        static const StackMsgArgMap<SsDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SsDispatcher> m_arg_map_container;
        
        void CheckReleaseComplete(BOOLEAN release_complete) const;

};

#endif // Asc_SimDispatcher_hpp


