/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_AdvPbApp_hpp)
#define Mmi_AdvPbApp_hpp

#include <Gui/Window.hpp>
#include <Gui/ConfirmAction.hpp>

#include <Auxiliary/MainProvider.hpp>

#include <GuiExtensions/MmiInfoBox.hpp>
#include <AddOns/Services/ServiceBroker.hpp>
#include <AdvPhonebook/AdvPbWin.hpp>
#include <AdvPhonebook/PhonebookApp.hpp>
#include <AdvPhonebook/PbAdvDataHandler.hpp>
#include <AdvPhonebook/PbSelectNoType.hpp>
#include <AdvPhonebook/PbSelectGroup.hpp>
#include <AdvPhonebook/PbManualSynchronizer.hpp>
#include <AdvPhonebook/SyncPhoneThreadlet.hpp>

class AdvPbApp : public PhonebookApp {
    typedef PhonebookApp  Base;

    public:
        
        virtual ~AdvPbApp();

        static AdvPbApp* GetInstance();

        virtual ServiceResult SelectEmailAddress(WString &email, const WString &title = WString());

        void SelectNoType();

        void SelectGroup();

        virtual void DisplayMemory();

        BOOLEAN SyncSimAll();

        BOOLEAN SyncPhoneAll();

        BOOLEAN SyncSim();

        BOOLEAN SyncPhone();

        virtual void UpdateEnabledActions();

        Action* GetDelPhonenoAction() { return &m_del_phoneno_action; }
        
        Action* GetSelectGroupAction() { return &m_group_action; }
        
        Action* GetNoTypeAction() { return &m_no_type_action; }

        virtual INT GetMaxPhonenos();

        BOOLEAN IsPbAvailable();

//CN200013749 
        UINT32 GetLastDeletedUniqueId(){
            return m_pb_data_control.GetLastDeletedUniqueId();}
//END CN200013749 
    protected:
        virtual void OnSimReady();
        virtual void OnSimNotPresent();
        virtual void OnSimPresent();
        virtual void OnPbWindowClosed(const PbAbstractWin *win);
        virtual BOOLEAN OnMessage(const Message &msg);

        virtual BOOLEAN ServiceReady();

        virtual PbDataHandler* GetPbDataControl();
        virtual PbSynchronizer* GetSynchronizer();
        virtual PhonebookWin* GetPhonebook();

    private:
        AdvPbApp();

        virtual void OnTriggerNotification (INT16 type);
        virtual void EnableSimActions(BOOLEAN flag);
        void SyncTerminated(BOOLEAN successful);

        static AdvPbWin             m_phonebook;

        static PbAdvDataHandler     m_pb_data_control;
        static PbManualSynchronizer m_sim_synchronizer;
        static SyncPhoneThreadlet   m_sync_threadlet;
    
        ConfirmAction           m_confirm_action;
    
        PbSelectGroupAction     m_group_action;
        PbChangeNoTypeAction    m_no_type_action;
        PbDelPhonenoAction      m_del_phoneno_action;

        SyncSimAllAction        m_sync_sim_all_action;
        SyncPhoneAllAction      m_sync_phone_all_action;
        SyncSimAction           m_sync_sim_action;
        SyncPhoneAction         m_sync_phone_action;
        SyncPhoneAllAction      m_load_from_sim_action;
        OpenWindowAction        m_show_sim_action;

        PbSelectNoType          m_sel_no_type_win;
        PbSelectGroup           m_sel_group_win;

        static BasicPbWin               m_sim_pb;
//      MmiAlert                m_memory_win;
        MmiInfoBox              m_info_box;

        static MmiAdvancedProgressBox   m_sync_listener;
        
        static PbBaseWin        m_select_email;
        BooleanCondition        m_email_selected;

        static AdvPbApp         m_app;
};

#endif  // Mmi_AdvPbApp_hpp
