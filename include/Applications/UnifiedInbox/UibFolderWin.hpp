// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */


#if ! defined(UnifiedInbox_UibFolderWin_hpp)
#define UnifiedInbox_UibFolderWin_hpp

#include <Auxiliary/WString.hpp>
#include <Atl/Gui/AtlItemListWindow.hpp>
#include <Config/UibConfig.hpp>

class UibApp;

class UibFolderWin : public AtlItemListWindow {

    typedef AtlItemListWindow Base;

    public:
        UibFolderWin();

        virtual ~UibFolderWin();

        void Init(UibApp* uib_app, UibConfig::UibFolderTypes folder_type, AbstractItemContainer* item_cont);

        INT GetSelectedMsg();

        void SetFolderType(UibConfig::UibFolderTypes folder_type);

        UibConfig::UibFolderTypes GetFolderType() const { return m_folder_type; }

    //  DrawableObjectListBox* GetListboxModel() { return &m_listbox; }

        void Update();

        void SetUibContextId();

    protected:

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnOpen();

        // virtual BOOLEAN OnSoftkeyPressed(INT index);

        virtual void OnUpdate(ObservableObject* obs_obj);

        virtual void OnSelectionChanged();

        virtual void OnGetFocus();

    private:
        void UpdateTitle();
        INT GetMsgCount(UibConfig::UibFolderTypes folder_type);
        INT GetUnreadMsgCount(UibConfig::UibFolderTypes folder_type);


        UibApp*                 m_uib_app;
        //UibListBoxModel           m_listbox_model;
        //DrawableObjectListBox m_listbox;
        //CloseWindowAction     m_close_action;

        UibConfig::UibFolderTypes m_folder_type;
        WString                 m_title;

};

#endif // UnifiedInbox_UibFolderWin_hpp
