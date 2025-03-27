/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(CalendarMonthWin_hpp)
#define CalendarMonthWin_hpp

#include "CalendarGrid.hpp"
#include "CalendarMonthSelector.hpp"
#include "CalendarAddRecordWin.hpp"
#include "CalendarGotoDateWin.hpp"
#include "CalendarRecordsList.hpp"
#include "CalendarListWin.hpp"


#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/MmiPrompt.hpp>
#include <GuiExtensions/LabelListBoxModel.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

class CalendarMonthWin : public MmiWindow {
    typedef MmiWindow Base;

    public:

        CalendarMonthWin();

        virtual ~CalendarMonthWin();

        void Init();

        void OnOpen();

        BOOLEAN Update();

        void OnLayoutClient();

        void SetCurrentDate(Date date);

        Date GetCurrentDate() const {return m_current_date;}

        void AddRecord();

        void GotoDay();

        void ViewSelectedDay();

        void ViewAll();

        CalendarAddRecordWin* GetCalendarAddWin() {return &m_add_record_win;}

        CalendarListWin* GetCalendarListWin(){return &m_calendar_rec_list_win;}


    protected:

        virtual BOOLEAN OnCancel();

    private:

        Date                    m_current_date; // to choose the month to show
        CalendarGrid            m_month_grid;
        CalendarMonthSelector   m_select_month_control;
        CalendarAddRecordWin    m_add_record_win;
        CalendarListWin         m_calendar_rec_list_win;        
};

#endif 

