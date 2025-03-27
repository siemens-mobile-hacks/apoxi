/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsSendDispatcher_hpp)
#define Asc_SmsSendDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Apc/Sms.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    SmsSendDispatcher
    ======================================================================== */
class SmsSendDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        SmsSendDispatcher();
        virtual ~SmsSendDispatcher();

        const Sms::Result& GetResult() const { return (m_result); }
        BOOLEAN ShortMessageFailureExists() const { return (m_short_message_failure_exists); }
        const ShortMessageFailureCause& GetShortMessageFailureCause() const { return (m_short_message_failure_cause); }
        const SmsReferenceNumber& GetReferenceNumber() const { return (m_reference_number); }

    protected:
        BOOLEAN OnSmsSendCnf(const StackMsgArgument &arg);
        BOOLEAN OnSmsSendRej(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<SmsSendDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SmsSendDispatcher> m_arg_map_container;
        
        Sms::Result m_result;
        BOOLEAN m_short_message_failure_exists;
        ShortMessageFailureCause m_short_message_failure_cause;
        SmsReferenceNumber m_reference_number;
};

#endif  // Asc_SmsSendDispatcher_hpp


