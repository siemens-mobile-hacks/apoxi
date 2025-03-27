// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
//

#if ! defined(UnifiedInbox_UibApp_hpp)
#define UnifiedInbox_UibApp_hpp

#include <AddOns/AuxExtensions/AppendProvider.hpp>
#include <Auxiliary/QuickSortProvider.hpp>
#include <Gui/Action.hpp>

#include <Common/MmiApplication.hpp>
// start
#include <Common/Items/ProviderProxyContainer.hpp>
#include <Common/Items/FeatureItem.hpp>
#include <Common/Items/ContextFeatureItem.hpp>
#include <Common/FeatureBroker/FeatureBroker.hpp>
#include <Atl/Gui/AtlItemListWindow.hpp>
// end

#if defined(MMI_COMPAT_2_10_0)
#include <MmiCompat/ContextMenuActionFeature.hpp>
#include <MmiCompat/ContextMenuAction.hpp>
#include <MmiCompat/BitmapResPtr.hpp>
#endif //MMI_COMPAT_2_10_0

#include <Common/MmiWaitingBox.hpp>
#include <Common/MmiAlert.hpp>
#include <Common/FireMsgAction.hpp>
#include <Common/CommonMsgTypes.hpp>

#include <Config/UibConfig.hpp>
#include "UibInboxProvider.hpp"

// start
#include <Config/ContextConfig.hpp>
// end
#if defined(MMI_COMPAT_2_10_0)
#include <MmiCompat/MenuAction.hpp>
#include <UnifiedInbox/UibActionAccessor.hpp>
#endif //MMI_COMPAT_2_10_0
#include <UnifiedInbox/UibServiceImpl.hpp>
#include <UnifiedInbox/UibSettingsWin.hpp>
#include <UnifiedInbox/UibFolderWin.hpp>
#include <UnifiedInbox/UibSettingsProvider.hpp>
#include <Atl/Gui/ImgObtObj.hpp>


#ifdef MMI_UNIT_TEST_ENABLED
#include <UnifiedInbox/UibUnitTests/UibAccessorTest.hpp>
#include <UnifiedInbox/UibUnitTests/UibInboxTest.hpp>
#include <UnifiedInbox/UibUnitTests/UibMsgDisplayTest.hpp>
#include <UnifiedInbox/UibUnitTests/UibNotifyTest.hpp>
#include <UnifiedInbox/UibUnitTests/UibPerformanceTest.hpp>
#include <UnifiedInbox/UibUnitTests/UibSettingsTest.hpp>
#include <UnifiedInbox/UibUnitTests/UibSortingTest.hpp>
#include <MmiTest/MmiUnitTest/MmiUnitTestSuite.hpp>
#endif

class UibInboxProvider;

class UibApp : public MmiApplication {

    typedef MmiApplication Base;

    public:

        enum UibServiceType {
            RegisterType,
            NotifyType
        };

        static UibApp* GetInstance();

        virtual ~UibApp();

        void DeleteAllMsg(UibConfig::UibFolderTypes folder_type);

//      void OnIndicateIncoming(UibMessageTypes msg_type);

        SortProvider* GetSortedFolderProvider(UibConfig::UibFolderTypes folder_type);

        INT GetSortColid(UibConfig::UibFolderTypes folder_type);

        void UpdateFolderProvider(UibConfig::UibFolderTypes folder_type);

        #if defined(MMI_COMPAT_2_10_0)

        ActionAccessor* GetContextMenu() { return &m_context_menu_acc; }
        BOOLEAN UpdateContextMenu(INT index);
        #endif //MMI_COMPAT_2_10_0

        Provider* GetSettingsProvider() { return &m_settings_provider; }

        void OnSortingChanged(UibConfig::UibFolderTypes folder_type);

        void ShowWaitingBox(BOOLEAN flag);

        INT GetMessageType(INT index);

        virtual DataItem GetContextDataItem(ContextFeature* feature);




    protected:

        //handles the message request from the service interface
        virtual BOOLEAN OnMessage(const Message &msg);

        virtual void OnStartup();

        virtual void OnOpen();

        virtual void OnClose();

        virtual void OnUibRegisterService(UINT8 box_type, Provider* provider);

        virtual void OnUibNotifyService();

        //const WCHAR* GetTextForMsgType(UibConfig::UibMessageTypes msg_type) const;

        // start
        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

        virtual BOOLEAN OnContextFeatureTriggered (const FeatureID& feature_id, const DataItem& context_item);

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification,
                            const Property* property,
                            const DataItem& value);


        virtual void OnGetFocus();
        virtual void OnLoseFocus();



        // end

    private:
        enum TriggerNotification {
            TrOpenInbox,
            TrDeleteAll,
            TrOpenSettings,
            TriggerArrivedMsg,
            TrCnt
        };

        // start
        enum FeatureItemIds {
                UibOpenInbox,
                UibSortByTimeStamp,
                UibSortByMsgType,
                UibSortAscending,
                UibFeatureCnt
        };

        enum ContextFeatureItemIds {
            UibDeleteInbox,
            UibSettings,
            UibContextFeatureCnt
        };

        // end

        INT GetFirstUnreadMsg();
        INT GetAllUnreadMessages();
        void GetMsgTone(INT msg_type);

        //void UpdateContextMenuActions(INT index);
        BOOLEAN FolderWindowOpen(UibConfig::UibFolderTypes folder_type);

        static UibApp           m_uib_app;
        MmiAlert                m_alert;

        //static FireMsgAction  m_msg_indication_action;
        //TriggerNotificationMsg    m_indication_msg;
#if defined(MMI_COMPAT_2_10_0)
        MenuAction              m_uib_actions[TrCnt];
        UibActionAccessor       m_context_menu_acc;
#endif //MMI_COMPAT_2_10_0
        // start
        Feature                 m_items[UibFeatureCnt];
        ContextFeature          m_context_items[UibContextFeatureCnt];

        ProviderProxyContainer  m_proxy_cont;
        //AtlItemListWindow     m_folder_win;
        UibFolderWin            m_folder_win;
        INT                     m_sel_row;
        // end

        UibApp();

        UibServiceImpl          m_service;
        //static AppendProvider m_inbox_provider;
        static UibInboxProvider m_inbox_provider;

        //UibFolderWin          m_folder_win;
        UibConfig::UibFolderTypes   m_folder_type;
        UibSettingsWin          m_settings_win;

        WString                 m_menu_text;
        WString                 m_inbox_text;

        UibSettingsProvider     m_settings_provider;

        QuickSortProvider       m_sorted_inbox_provider;

        MmiWaitingBox           m_waiting_box;
        WString                 m_action_text;

        DataItem                m_item;
        EqualsRule              m_rule;

        BOOLEAN                 m_waiting_cnt;

        BOOLEAN                 m_sort_asc;

        #if defined(MMI_COMPAT_2_10_0)
        ContextMenuActionFeature        *m_context_menu_action_feat;
        INT                     m_menu_count;
        Vector<ContextMenuActionFeature*>   m_contxt_menu;

        void BuildFeatureTable(Provider* provider);
        AbstractActionAccessor* GetActionAccessor(INT index, DataItem &data_item);
        BOOLEAN IsMenuExist(FeatureItemContainer* feat_item_cont, INT index);
        ContextMenuActionFeature* GetFeatureItem(Action* action);
        #endif //MMI_COMPAT_2_10_0

        #ifdef MMI_UNIT_TEST_ENABLED
            MmiUnitTestSuite        m_uib_suite;
            UibMsgDisplayTest       m_test_msg_display;
            UibAccessorTest         m_test_accessor;
            UibSettingsTest         m_uib_settings_test;
            UibInboxTest            m_uib_inbox_test;
            UibSortingTest          m_uib_sorting_test;
            UibNotifyTest           m_uib_notify_test;
            UibPerformanceTest      m_uib_performance_test;
            void InitUnitTests();
        #endif

};





#endif // UnifiedInbox_UibApp_hpp

