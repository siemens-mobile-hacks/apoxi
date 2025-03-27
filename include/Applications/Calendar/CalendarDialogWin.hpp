/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(CalendarDialogWin_hpp)
#define CalendarDialogWin_hpp


#include <Common/MmiDialog.hpp>
#include "CalendarRecord.hpp"
#include <Auxiliary/Vector.hpp>

/* must to be alligned with CategoryEnum */
static const WCHAR* CategoryInfo[CalendarRecord::CategoryCounts] = {Tr(L"Memo"), Tr(L"Meeting"), Tr(L"Birthday"), Tr(L"Call"), Tr(L"Anniversary"), Tr(L"Other")};

/* must to be alligned with RecurrenceEnum */
static const WCHAR* RecurrenceInfo[CalendarRecord::RecurrenceCounts] = {Tr(L"No repeat"), Tr(L"Daily"), Tr(L"Weekly"), Tr(L"Monthly"), Tr(L"Yearly")};

const INT c_max_rb_size = ((CalendarRecord::CategoryCounts >= CalendarRecord::RecurrenceCounts) ? CalendarRecord::CategoryCounts : CalendarRecord::RecurrenceCounts);
    
class CalendarDialogWin: public MmiDialog {
    typedef MmiDialog   Base;

    public:

        void Init();

        BOOLEAN OnConfirm();

        INT GetData();

        void SetData(INT value);

        void OnOpen();
        
    private:        
        RadioButtonAction           m_rb_action[c_max_rb_size];
        RadioButtonGroup            m_rb_group;
        ItemMenu                    m_rb_menu;
        INT                         m_value;
};


#endif 
