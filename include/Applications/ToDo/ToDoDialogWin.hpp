/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(ToDoDialogWin_hpp)
#define ToDoDialogWin_hpp


#include <Common/MmiDialog.hpp>
#include "ToDoRecord.hpp"


class ToDoDateDialogWin: public MmiDialog {
    typedef MmiDialog   Base;

    public:
                
        ToDoDateDialogWin();

        virtual ~ToDoDateDialogWin();

        void Init();

        void OnOpen();

        BOOLEAN OnConfirm();

        void OnLayoutClient();

        DateEditor* GetDate();

        virtual BOOLEAN OnCancel();

        void Clean();

        void SetDate (Date date);

    private:
        DateEditor                  m_date_editor;      
};

class ToDoPriorityDialogWin: public MmiDialog {
    typedef MmiDialog   Base;

    public:
        void Init();
        BOOLEAN OnConfirm();
        INT GetPriority() {return m_priority;};
        void SetPriority(ToDoRecord::ToDoRecProrityLevel priority);
        void OnOpen();
        
    private:
        RadioButtonAction           m_low_action;
        RadioButtonAction           m_medium_action;
        RadioButtonAction           m_high_action;
        RadioButtonGroup            m_priority_group;
        ItemMenu                    m_item_menu;
        INT                         m_priority;
};


#endif 
