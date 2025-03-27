/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DataConnWin_hpp)
#define Apoxi_DataConnWin_hpp

#include <Socket/DataConnProfileManager.hpp>

#include <Common/MmiWindow.hpp>
#include <MmiCompat/DrawableObjectListBox.hpp>
#include <MmiCompat/LabelListBoxModel.hpp>
#include <MmiCompat/ActionMenuAccessor.hpp>

class DataConnWin;
class DataConnLbModel : public LabelListBoxModel {
    typedef LabelListBoxModel Base;

    public:
        DataConnLbModel();
        explicit DataConnLbModel(DrawableObjectListBox *parent);
        virtual ~DataConnLbModel();

        void Init(DataConnWin *win, DrawableObjectListBox *parent);

        virtual const WCHAR* GetCellText(INT index, BOOLEAN highlighted);
        virtual const BitmapRes* GetCellIcon(INT index, BOOLEAN highlighted);
    
        void Update();

        DataConnProfileId GetSelectedProfileId() { return m_pis[GetSelectedIndex()]; }
        DataConnProfileManager::ProfileInfo GetSelectedProfileInfo() { return m_pinfo[GetSelectedIndex()]; }

        INT GetProfileCount() { return m_count; }

    protected:
        virtual void OnSelectionChanged(INT selected_index);

    private:
        DataConnProfileIdSet    m_pis;
        DataConnProfileManager::ProfileInfo m_pinfo[c_data_conn_profile_count];
        WString                         m_data_conn_names[c_data_conn_profile_count];
        DataConnWin*                    m_win;
        DrawableObjectListBox*          m_parent;

        INT                             m_count;
};

class DataConnApp;
class DataConnWin : public MmiWindow {
    public:
        typedef MmiWindow Base;

        DataConnWin();
        virtual ~DataConnWin();

        void Init(DataConnApp *app);

        DataConnApp* GetConnApplication() { return m_app; }

        DataConnProfileId GetSelectedProfileId() { return m_lb_model.GetSelectedProfileId(); }
        
        void Update();
        void UpdateEnabledActions();

    protected:
        virtual void OnOpen();

    private:
        enum {
            Edit = 0,
            New = 1,
            Delete = 2,
            SetAsDefault = 3,
            action_cnt = 4
        };

        DataConnApp *           m_app;              
        DrawableObjectListBox   m_listbox;
        DataConnLbModel         m_lb_model;

        //Actions
        CloseWindowAction       m_close_action;
        ActionAccessor          m_menu;
        MenuAction              m_menu_actions[action_cnt];
};

#endif  // Apoxi_DataConnWin_hpp
