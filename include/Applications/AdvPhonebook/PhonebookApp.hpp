/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PhonebookApp_hpp)
#define Mmi_PhonebookApp_hpp

#include <Gui/Window.hpp>

#include <Gui/CheckBoxAction.hpp>
#include <AddOns/Services/ServiceBroker.hpp>
#include <Common/MmiApplication.hpp>
#include <GuiExtensions/MenuAction.hpp>
#include <GuiExtensions/MmiProviderProgressBox.hpp>
#include <GuiExtensions/MmiAdvancedProgressBox.hpp>
#include <GuiExtensions/MmiWaitingBox.hpp>
#include <AdvPhonebook/PhonebookWin.hpp>
#include <AdvPhonebook/PbAdvAddEditEntry.hpp>
#include <AdvPhonebook/PbSelectNumberWin.hpp>
#include <AdvPhonebook/PbDataHandler.hpp>
#include <AdvPhonebook/PbAction.hpp>
#include <AdvPhonebook/BasicPbWin.hpp>
#include <AdvPhonebook/CopyHandler.hpp>
#include <Common/MmiServices.hpp>
#include <AdvPhonebook/UpdatePbThreadlet.hpp>

class PbSynchronizer;
class PhonebookApp : public MmiApplication, public PhonebookService {
    typedef MmiApplication Base;

    public:
        
        PhonebookApp(UINT stacksize = 0);
        virtual ~PhonebookApp();

        enum AffectedProvider {
            NameProv,
            NumberProv,
            Both
        };

        // Services
        virtual ServiceResult InvokePhonebook();
        virtual ServiceResult SelectPhoneNumber(PhoneNumber &phoneno, const WString &title = WString());
        virtual ServiceResult SelectEmailAddress(WString &email, const WString &title = WString());
        virtual ServiceResult SaveNumberInPhonebook(const PhoneNumber &phoneno);
        virtual ServiceResult SaveEntryInPhonebook(const WString &name, const PhoneNumber &phoneno);
        virtual ServiceResult SaveEntryInPhonebook(const WString &name, const WString& email_address);
        virtual ServiceResult SelectSimPos(INT sim_pos);
        virtual ServiceResult GetName(const PhoneNumber &phoneno, WString &name);

        BOOLEAN Synchronize();

        BOOLEAN AddPbEntry(const WString &name, const PhoneNumber &phoneno, const WString &email); // CN200009289 G.Ragavan
        BOOLEAN AddNumber(INT name_row, const PhoneNumber &phoneno, INT no_id);
        BOOLEAN UpdatePbEntry(INT colid, const DataItem &item);
        BOOLEAN DeleteSelectedNumber(BOOLEAN feedback = TRUE);
        BOOLEAN DeleteSelectedPbEntry(BOOLEAN feedback = TRUE);
        void CallSelectedNumber();
        BOOLEAN DeleteAllEntries();
        virtual void DisplayMemory();
        void SwitchDisplaySimPos();
        BOOLEAN AddAllToFdn();
        BOOLEAN AddEntryToFdn();
        BOOLEAN AddNumberToFdn();
        BOOLEAN CopyToPb();

        void EnterNewEntry(const WString &default_name, const PhoneNumber &default_phoneno, const WString &default_mail); // CN200009289 G.Ragavan

//      PbProvider* GetPbProvider() { ASSERT(m_pb_data_control != 0); return m_pb_data_control->GetPbProvider(); }
//      PbProvider* GetWindowProvider();
        
        Provider* GetPbProvider() { return GetPbDataControl()->GetPbProvider(); }
        Provider* GetWindowProvider();
        INT GetSelectedRow() { ASSERT(m_active_win != 0); return m_active_win->GetSelectedRow(); }

        INT GetSelectedPbRow() { ASSERT(m_phonebook != 0); return m_phonebook->GetSelectedRow(); };

        //
        void GetSelectedItem(INT colid, DataItem &item) { m_active_win->GetSelectedItem(colid, item); };
        
        void SetActiveWin(PbAbstractWin* win) { m_active_win = win; }
        PbAbstractWin* GetActiveWin() { return m_active_win; }

        virtual void UpdateEnabledActions();

        Action* GetCallAction() { return &m_call_action; }
        Action* GetAddAction() { return &m_add_action; }
        Action* GetDeleteAction() { return &m_delete_action; }
        Action* GetDelAllAction() { return &m_del_all_action; }
        
        BOOLEAN IsEmptyRow(Provider *prov, INT row);

        virtual INT GetMaxPhonenos() = 0;
        INT NumberCount(INT name_row);

        virtual PhonebookWin* GetPhonebook() = 0;

        INT SearchRow(SortProvider *prov, const DataItem &item, INT col_id);

        void StartWaitingAnimation();
        void StopWaitingAnimation();

        virtual BOOLEAN IsPbAvailable() { return TRUE; }

        enum ProviderUpdateState{
            Started,
            Finished
        };
    protected:
        virtual void OnStartup();
        virtual void OnOpen();
        virtual void OnClose();
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnSimChanged(SimChangeType chg_type);
        virtual void OnSimStateChanged(SimIndicator sim_ind);
        virtual void OnSimReady();
        virtual void OnSimPresent() {};
        virtual void OnSimNotPresent() {};
        virtual void OnPbWindowClosed(const PbAbstractWin *win);

        virtual void OnTriggerNotification (INT16 type);

        virtual BOOLEAN ServiceReady();

        BOOLEAN NewSim() { return m_new_sim; }

        virtual void UpdatePbs(DataControlType data_type);

        void OpenPhonebook();
        void EnablePhonebook(BOOLEAN flag) { m_open_pb_action.SetEnabled(flag); }

        virtual void EnableSimActions(BOOLEAN flag);

        BOOLEAN NoEntrySelected();
                
        virtual PbDataHandler* GetPbDataControl() = 0;
        virtual PbSynchronizer* GetSynchronizer() = 0;

        MmiProviderProgressBox* GetProgressBox() { return &m_prov_listener; }

        BOOLEAN ProvShowsEmptyRows(Provider *prov);

        OpenWindowAction* GetOpenPbWinAction() { return &m_open_pb_win_action; }

        static UpdatePbThreadlet    m_update_threadlet;

    private:
        INT FindPbNameRow(const WString &name);
        BOOLEAN IsPhonebookEmpty();

        // Phonebook data handling
        PbDataHandler *         m_pb_data_control;
        PhonebookWin *          m_phonebook;
        PbSynchronizer *        m_sim_synchronizer;

        PbAbstractWin *         m_active_win;

        Provider *              m_pb_provider;

        MmiProviderProgressBox  m_provider_listener;

        // Actions
        PbCallAction            m_call_action;
        PbAddAction             m_add_action;
        PbDeleteAction          m_delete_action;
        PbDelAllAction          m_del_all_action;
        DisplayMemoryAction     m_display_mem_action;

        AddAllToFdnAction       m_all_to_fdn_action;
        AddEntryToFdnAction     m_entry_to_fdn_action;
        AddNumberToFdnAction    m_no_to_fdn_action;
        OpenWindowAction        m_show_fdn_action;
        CopyToPbAction          m_fdn_to_pb_action;
        OpenWindowAction        m_show_bdn_action;

        MenuAction              m_open_pb_action;
        OpenWindowAction        m_open_pb_win_action;
        OpenWindowAction        m_show_msisdn_action;
        OpenWindowAction        m_show_sdn_action;

        // Windows
        BasicPbWin              m_msisdn_pb;
        BasicPbWin              m_fdn_pb;
        PbBaseWin               m_sim_win;
        BasicPbWin              m_bdn_pb;
        BasicPbWin              m_sdn_pb;
        PbSelectNumberWin       m_select_no_win;
        PbAdvAddEditEntry           m_add_entry_win;

        BOOLEAN                 m_sync_sim;

        SyncAction              m_sync_action;

        PbCopyHandler           m_copy_to_fdn_handler;

        MmiProviderProgressBox  m_prov_listener;
        MmiAdvancedProgressBox  m_sync_listener;

        BooleanCondition        m_number_selected_cond;
        BooleanCondition        m_pb_prov_updated_cond;

        MmiWaitingBox           m_wait_box;

        BOOLEAN                 m_new_sim;

        BOOLEAN                 m_fdnEnabled;

        friend class PbAbstractWin;
};

#endif  // Mmi_PhonebookApp_hpp
