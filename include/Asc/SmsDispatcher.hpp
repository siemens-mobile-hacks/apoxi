/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsDispatcher_hpp)
#define Asc_SmsDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>
#include <Adc/DataHandler.hpp>          // include this header for MDH - check
#include <Kernel/Os/SystemTimer.hpp>    // include this header for MDH - check

#include "SmsSendProtector.hpp"


/*  ========================================================================
    SmsDispatcher
    ======================================================================== */
class SmsDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        SmsDispatcher();
        virtual ~SmsDispatcher();

        void SetBlockingSend(BOOLEAN blocking_send) { m_blocking_send = blocking_send; }

        static SmsSendProtector& GetProtector() { return (m_protector); } 

    protected:
        BOOLEAN OnMdhSmsNewMessageInd(const StackMsgArgument &arg);
        BOOLEAN OnMdhNewStatusReportInd(const StackMsgArgument &arg);
        BOOLEAN OnMdhSmsRefreshInd(const StackMsgArgument &arg);
        BOOLEAN OnMdhSmsStorageRefreshInd(const StackMsgArgument &arg);
        BOOLEAN OnMdhSmsUpdStatusRefreshInd(const StackMsgArgument &arg);
        BOOLEAN OnMdhSmsWaitingInd(const StackMsgArgument &arg);
        BOOLEAN OnSmsCapacityExceeded(const StackMsgArgument &arg);
        BOOLEAN OnSmsCapacityAvailable(const StackMsgArgument &arg);
        BOOLEAN OnSmsSendCnf(const StackMsgArgument &arg);
        BOOLEAN OnSmsSendRej(const StackMsgArgument &arg);
        BOOLEAN OnMdhSmsDeletionInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<SmsDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SmsDispatcher> m_arg_map_container;

        static SmsSendProtector m_protector;    // protector for multiple sender protection
        
        BOOLEAN m_blocking_send;

};

#endif // Asc_SmsDispatcher_hpp


