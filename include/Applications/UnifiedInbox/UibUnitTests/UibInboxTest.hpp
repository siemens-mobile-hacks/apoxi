// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if !defined(UibInboxTest_hpp)
#define UibInboxTest_hpp

#include <Kernel/Timer.hpp>
#include <Kernel/Condition.hpp>

#include <GuiExtensions/ContextMenuAction.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>
#include <MmiTest/TestChildProvider1.hpp>
#include <MmiTest/TestChildProvider2.hpp>
#include <AddOns/AuxExtensions/AppendProvider.hpp>

#include <UnifiedInbox/UibFolderWin.hpp>

class UibInboxTest : public MmiUnitTest, public Observer {
    typedef MmiUnitTest Base;

    public:
        enum ContextActions {
            Action1,
            Action2,
            Action3,
            ActionCnt
        };

        UibInboxTest() {};

        virtual ~UibInboxTest();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);
        
        virtual void OnUpdate(ObservableObject* obs_obj);

    private:
        enum TriggeredAction {
            TrDeleteOneEntry = 10,
            TrAddEntry = 11,
        };

        void TestDisplay();
        void TestContextMenu(INT index);
        void TestContextActionExecution(UibConfig::UibMessageTypes msg_type, UibInboxTest::ContextActions context_action);
        void TestUpdate(TriggeredAction prov_action);

        void DeleteEntry(INT index);
        void AddEntry();

        void TestDeleteAllMsg(UibConfig::UibFolderTypes folder_type);

        const WCHAR* GetTextForMsgType(UibConfig::UibMessageTypes msg_type) const;

        UibFolderWin m_inbox_win;
        UibServiceImpl m_uib_service;

        ContextMenuAction m_context_actions[ActionCnt];
        ActionAccessor  m_acc_prov1;
        ActionAccessor m_acc_prov2;

        Timer m_timeout_timer;

        UibInboxTest::ContextActions m_triggered_action;

        BooleanCondition m_cond;
        BOOLEAN m_flag;

        Provider* m_prov1;
        Provider* m_prov2;
        UibApp* m_uib_app;
};

#endif /* UibInboxTest_hpp */
