/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbDetails_hpp)
#define Mmi_PbDetails_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <AdvPhonebook/PbNameEditBox.hpp>
#include <AdvPhonebook/PbDetailListBox.hpp>
#include <AdvPhonebook/ProvListBoxWin.hpp>
#include <AdvPhonebook/PbAction.hpp>

class PbDetails;
class PbDetailEditBox : public PbNameEditBox {
    typedef PbNameEditBox Base;

    public:
        PbDetailEditBox();
        virtual ~PbDetailEditBox();

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
};

class PbDetails : public ProvDetailListBoxWin {
    typedef ProvDetailListBoxWin Base;

    public:

        PbDetails();
        virtual ~PbDetails();
        
        void Init(ProvListBoxWin *parent, const INT* detail_columns);

        virtual void EditDetail();
        virtual void SaveEdit();
        virtual void CancelEdit() { CloseEditbox(); }
        
        virtual Provider* GetMyPbProvider();

    protected:
        // *************************************************
        // CN200006158 and CN200009448
        // Edited/Fixed by Christoph Minkwitz
        // virtual void Refresh(const Rect &rect);
        virtual void OnGetFocus();

        virtual PbDetailProvider * GetDetailProvider() { return &m_detail_provider; }

        virtual void GetUpdatedItem(INT colid, DataItem &item);
        virtual void DisplaySimPos();
        
        void SwitchToEditboxMenu();
        void OpenEditBox();
        void CloseEditbox();
    
        PbEditDetailAction      m_edit_detail_action;

        PbDetailListBox *       m_detail_listbox;
        PbDetailEditBox         m_editbox;

        PbConfirmEditAction     m_confirm_edit_action;
        PbCancelEditAction      m_cancel_editbox_action;
        virtual const WString       GetSavedText(INT colid);


    private:        
        PbDetailProvider        m_detail_provider;
        
        WString                 m_simpos_title;
        BOOLEAN                 m_is_open;
};
 
#endif  // Mmi_PbDetails_hpp
