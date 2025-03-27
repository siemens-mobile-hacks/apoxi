/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbAbstractWin_hpp)
#define Mmi_PbAbstractWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <AdvPhonebook/PbProvListBox.hpp>

class PhonebookApp;
class PbAbstractWin : public MmiWindow {

    typedef MmiWindow Base;

    public:
        enum MenuIndex {
            MainMenu    = 1,
            SubMenu     = 2
        };

        PbAbstractWin();
        virtual ~PbAbstractWin();

        void Init();

        PhonebookApp* GetPbApplication() const { return (PhonebookApp*) GetApplication(); };
        
        virtual Provider* GetMyPbProvider();
        
        virtual void SetSelectedRow(INT );

        virtual INT GetSelectedRow() = 0;
        virtual void GetSelectedItem(INT colid, DataItem &item) = 0;

        virtual void UpdateWin(BOOLEAN win_only = FALSE);

        void AddMenuAction(INT idx, Action *action, BOOLEAN separate = FALSE);

        void ChangeMenuAction(INT idx, Action *old_action, Action *new_action);

        void SetDisplaySimPos(BOOLEAN display_simpos) { m_display_simpos = display_simpos; }
        BOOLEAN GetDisplaySimPos() { return m_display_simpos; }

        void SetPbTitle(const WString &title);
        const WString& GetPbTitle() { return m_title; }

        BOOLEAN IsConfirmed() { return m_confirmed; }
        
        virtual BOOLEAN IsReadOnly() { return FALSE; }
        
        void SetPbProvider(Provider* provider) { m_pb_provider = provider; }

        Provider* GetPbProvider() { return m_pb_provider; }
        
    protected:
        virtual void OnOpen();
        virtual void OnGetFocus();
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
        virtual BOOLEAN OnConfirm();
        virtual BOOLEAN OnCancel();
        virtual void OnClose();
        virtual void OnLanguageChanged();
        virtual BOOLEAN OnSoftkeyPressed(INT idx);

        virtual void UpdateEnabledActions();
        virtual void DisplaySimPos();

        void RestoreSoftkeys();

        ActionAccessor* GetAccessor(INT idx);

    private:
        INT GetAffectedRow();

        ActionAccessor          m_main_accessor;
        ActionAccessor          m_sub_accessor;

        MenuAction              m_popup_action;
        CancelAction            m_cancel_action;

        BOOLEAN                 m_confirmed;
        BOOLEAN                 m_display_simpos;
        WString                 m_title;

        INT                     m_popup_sep_idx;
        INT                     m_close_sep_idx;

        Provider*               m_pb_provider;
};

#endif  // Mmi_PbAbstractWin_hpp
