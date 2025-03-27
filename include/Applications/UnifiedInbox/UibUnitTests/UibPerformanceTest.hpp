// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if !defined(UibPerformanceTest_hpp)
#define UibPerformanceTest_hpp

#include <Auxiliary/QuickSortProvider.hpp>
#include <Kernel/Condition.hpp>

#include <AddOns/AuxExtensions/AppendProvider.hpp>

#include <GuiExtensions/ContextMenuAction.hpp>
#include <GuiExtensions/MmiAlert.hpp>

#include <MmiTest/TestChildProvider1.hpp>
#include <MmiTest/TestChildProvider2.hpp>

#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>

class UibPerformanceTest : public MmiUnitTest, public Observer {
    typedef MmiUnitTest Base;
    public:
        UibPerformanceTest() {};

        virtual ~UibPerformanceTest();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

        void TestUpdateTime(INT sort_colid);
        
        void TestAddEntryPerf();

        void TestDeleteEntryPerf(INT id);

//      void TestViewMsgPerf(INT id);

    protected:
        BOOLEAN OnMessage(const Message &msg);
        
        virtual void OnUpdate(ObservableObject* obs_obj);

        const WCHAR* GetTextForMsgType(UibConfig::UibMessageTypes msg_type) const;

    private:
        enum ContextActionTypes {
            CaView,
            CaAdd,
            CaDelete
        };
        
        const WCHAR* GetSortKeyText(INT sort_colid);

        void OnContextTriggerNotification(INT type, INT id, INT provider_id);
        void ViewMsg(Provider* prov, INT id);
        void AddEntry(Provider* prov);
        void DeleteEntry(Provider* prov, INT id);

        QuickSortProvider m_sort_prov;
        AppendProvider m_append_prov;
        TestChildProvider1* m_prov1;
        TestChildProvider2* m_prov2;
        
        ContextMenuAction   m_context_actions1[3];
        ContextMenuAction   m_context_actions2[3];

        ActionAccessor      m_accessor1;
        ActionAccessor      m_accessor2;

        BooleanCondition    m_cond;
        BOOLEAN             m_flag;
        BOOLEAN             m_testing;
        
        Timer               m_timeout_timer;
        MmiAlert            m_alert;
};

#endif /* UibPerformanceTest_hpp */
