     /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestCaseAsync_hpp)
#define Apoxi_UnitTestCaseAsync_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

#include "UnitTest.hpp"
#include "UnitTestCase.hpp"
#include "MsgTypes.hpp"

#include <Kernel/UserDispatcher.hpp>
#include <Auxiliary/TriggerTimer.hpp>

/*  ------------------------------------------------------------------------
    BEGIN_ASYNC_UNIT_TEST_CASE
    ------------------------------------------------------------------------ */

#ifdef APOXI_UNITTEST_NO_TESTNAMES
    #define BEGIN_ASYNC_UNITTEST_CLASS(TestClass) \
        public: \
            static UnitTest* CreateInstance() { return new TestClass(); } \
            static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return 0;}; \
        protected:\
            APOXI_UNITTEST_INSTANCE_PER_TEST_METHODS(TestClass) \
        private: \
            BOOLEAN _Execute(UnitTestResult& test_result) \
            {\
                \
                BOOLEAN success = TRUE;\
                Init(); \
                m_test_result = &test_result
#else
    #define BEGIN_ASYNC_UNITTEST_CLASS(TestClass) \
        public: \
            static UnitTest* CreateInstance() { return new TestClass(); } \
            static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return 0;}; \
            static const CHAR* const GetName() { return #TestClass; } \
        protected:\
            APOXI_UNITTEST_INSTANCE_PER_TEST_METHODS(TestClass) \
        private: \
            BOOLEAN _Execute(UnitTestResult& test_result) \
            {\
                \
                BOOLEAN success = TRUE;\
                Init(); \
                m_test_result = &test_result
#endif
// BEGIN_ASYNC_UNITTEST_CASE


/*  ------------------------------------------------------------------------
    END_ASYNC_UNITTEST_CLASS
    ------------------------------------------------------------------------ */


#define END_ASYNC_UNITTEST_CLASS \
        ClearStatusText();\
        return success;\
        };


// END_ASYNC_UNITTEST_CLASS






class AsyncUnitTestCase : public UnitTestCase, public UserDispatcher {

    public:     
        AsyncUnitTestCase();
        virtual ~AsyncUnitTestCase();

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);

        const Message* WaitForMessage(UINT16 message_id, UINT32 timeout);


        const Message* WaitForFirstCaughtMessage(const UINT16 message_ids[], UINT16 nr_of_messages, UINT32 timeout);

        const Message* WaitForAllMessages(const UINT16 message_ids[], UINT16 nr_of_messages, UINT32 timeout);

    
    protected:
        void ClearStatusText();
    private:

        void SetTimeoutStatusText(UINT32 m_timeout);
        
        BOOLEAN CatchOneMessage(const Message &msg);
        
        BOOLEAN CatchOneOfNMessage(const Message &msg);
        
        BOOLEAN CatchAllOfNMessage(const Message &msg);

        UINT16 m_wait_for_message_id;

        const Message* m_received_message;

        BooleanCondition m_resume;

        friend class TriggerTimer<AsyncUnitTestCase>;
        TriggerTimer<AsyncUnitTestCase> m_timer;

        void OnTimer();
        
        // starts timer and waits for timeout
        const Message* Wait(UINT32 timeout);

        // checks if the current message is within the messages we are waiting for
        void UpdateCaughtMessagesIndicator(const Message &msg);

        // checks if all required messages are received
        BOOLEAN CaughtAllMessages();
        
        UINT32  m_timeout;

        Application* m_application;
        
        AsyncUnitTestMsg m_waiting_for_timeout_msg;     
        
        UINT16 const * m_message_ids;
        UINT16 m_nr_of_messages;
        BOOLEAN m_multimessage_wait;
        BOOLEAN m_wait_for_all;
        
        WString  m_waiting_for_timeout_msg_text;

        BOOLEAN * m_caught_messages_indicator;
};
#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestCaseAsyn_hpp

