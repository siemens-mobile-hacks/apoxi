/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(CalendarAddRecordWin_hpp)
#define CalendarAddRecordWin_hpp

#include "CalendarRecord.hpp"
#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/LabelListBoxModel.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include "CalendarDialogWin.hpp"



class CalendarAddRecordWin : public MmiWindow {
    typedef MmiWindow Base;

    public:

        CalendarAddRecordWin();

        virtual ~CalendarAddRecordWin();

        void Init();

        void SetDate(Date day);

        void SetData(CalendarRecord rec);

        void OnLayoutClient();

        void StoreAppointment();

        void SetCategory();

        void SetRecurrence();

    protected:

        virtual void OnClose();

    private:
        
        CalendarRecord  m_new_calendar_record;

        TextLine            m_date_text;
        TextLine            m_time_text;
        TextLine            m_category_text;
        TextLine            m_recurrence_text;
        
        DateEditor          m_date_editor;
        TimeEditor          m_time_editor;
        MultiLineEditor     m_main_record_editor;       
};

#endif 

