 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
 

#if ! defined(UnifiedInbox_UibMsgDisplayTest_hpp)
#define UnifiedInobx_UibMsgDisplayTest_hpp


/*#if defined(_DEBUG)
    #define VERIFY(cond, text)  MmiVerification::Verfiy(cond, __FILE__, __LINE__, text);
#endif
*/


#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>
#include <UnifiedInbox/UibServiceImpl.hpp>
#include <MmiTest/TestChildProvider1.hpp>
#include <MmiTest/TestChildProvider2.hpp>
#include <Kernel/Condition.hpp>

class TestApp;

class UibMsgDisplayTest : public MmiUnitTest {
    
    typedef MmiUnitTest Base;

    public:

        UibMsgDisplayTest();

        UibMsgDisplayTest(MmiUnitTestSuite* suite, BOOLEAN proceed_on_failed = TRUE);

        virtual ~UibMsgDisplayTest();
        
        void Init(MmiUnitTestSuite* suite, BOOLEAN proceed_on_failed = TRUE);

        const WCHAR* GetName() { return L"Message Presentation"; }

        virtual TestResult Run();

    protected:

        void SetPreconditions();

        virtual BOOLEAN OnMessage(const Message &msg); 

    private:
        
        UibServiceImpl      m_service;
        TestChildProvider1  m_provider1;
        TestChildProvider2  m_provider2;
        BooleanCondition    m_cond;
    
};

#endif //#define Mmi_UibMsgDisplayTest_hpp
