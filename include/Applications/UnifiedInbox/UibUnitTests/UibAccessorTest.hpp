 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
 

#if ! defined(UnifiedInobx_UibAccessorTest_hpp)
#define _Mmi_UibAccessorTest_hpp


/*#if defined(_DEBUG)
    #define VERIFY(cond, text)  MmiVerification::Verfiy(cond, __FILE__, __LINE__, text);
#endif
*/


#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>
#include <UnifiedInbox/UibActionAccessor.hpp>

class TestApp;

class UibAccessorTest : public MmiUnitTest {
    
    typedef MmiUnitTest Base;

    public:

        UibAccessorTest();

        UibAccessorTest(MmiUnitTestSuite* suite, BOOLEAN proceed_on_failed = TRUE);

        virtual ~UibAccessorTest();
        
        void Init(MmiUnitTestSuite* suite, BOOLEAN proceed_on_failed = TRUE);

        const WCHAR* GetName() { return L"Message Presentation"; }

        virtual TestResult Run();

    protected:

        void SetPreconditions();

        void TestSetAccessor(ActionAccessor* accessor);

        void TestRemoveAccessor();

        void TestGetActionCount();

        void TestGetAction();

        void TestInsertAction(INT index);

        void TestRemoveAllActions();

        void TestRemoveAction(INT index);

        void TestGetActionIndex(const Action &action);
        
    private:
        
        UibActionAccessor   m_uib_accessor;
        ActionAccessor      m_accessor;

        Action              m_view_action;
        Action              m_delete_action;
        Action              m_reply_action;

        Action              m_forward_action;
        Action              m_details_action;

        Action              m_delete_all_action;
        OpenWindowAction    m_open_settings;

};

#endif //#define Mmi_UibAccessorTest_hpp
