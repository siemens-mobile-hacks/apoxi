/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if ! defined(UnifiedInbox_UibSettingsWin_hpp)
#define UnifiedInbox_UibSettingsWin_hpp

#include <Gui/ItemMenu.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <Gui/CheckBoxAction.hpp>
#include <Gui/RadioButtonGroup.hpp>
//#include <GuiExtensions/MmiMenuWindow.hpp>
#include <Common/MmiWindow.hpp>
//#include <MmiCompat/MmiMenuWindow.hpp>
//#include <MmiCompat/ActionAccessor.hpp>

#include <Config/UibConfig.hpp>

#include <UnifiedInbox/UibSettingsProvider.hpp>

class UibApp;

class UibSettingsWin : public MmiWindow {

    typedef MmiWindow Base;

    public:

        UibSettingsWin(Provider* settings_provider = 0);

        virtual ~UibSettingsWin();

        void Init(Provider* settings_provider);

        void SetFolderType(UibConfig::UibFolderTypes folder_type) { m_folder_type = folder_type; }

    protected:
        virtual void OnOpen();
        virtual void OnClose();
        virtual BOOLEAN OnConfirm();

    private:
        RadioButtonAction   m_rb_sort_key[UibConfig::UibInvalidSortKey];

        CheckBoxAction      m_cb_sort_order;

        ItemMenu m_item_menu;

        RadioButtonGroup    m_rb_group;

        Provider*           m_settings_provider;
        UibConfig::UibFolderTypes m_folder_type;

        UINT8               m_old_sort_key;
        BOOLEAN             m_old_asc;
};

#endif // UnifiedInbox_UibSettingsWin_hpp/
