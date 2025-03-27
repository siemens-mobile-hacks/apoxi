// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if !defined(UibNotifyTest_hpp)
#define UibNotifyTest_hpp

#include <Kernel/Timer.hpp>
#include <Kernel/Condition.hpp>

#include <GuiExtensions/ContextMenuAction.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>
#include <MmiTest/TestChildProvider1.hpp>
#include <MmiTest/TestChildProvider2.hpp>
#include <AddOns/AuxExtensions/AppendProvider.hpp>

class UibNotifyTest : public MmiUnitTest {
    typedef MmiUnitTest Base;

    public:
        UibNotifyTest() {};

        virtual ~UibNotifyTest();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

    protected:

        void SetPreconditions();

        virtual BOOLEAN OnMessage(const Message &msg);
    
    private:

        UibServiceImpl  m_uib_service;

//      BooleanCondition m_cond;

        Provider*       m_prov1;
        Provider*       m_prov2;
        AppendProvider  m_append_prov;
};

#endif /* UibInboxTest_hpp */
