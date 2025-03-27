/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(CalendarRecord_hpp)
#define CalendarRecord_hpp
#include "CalendarAppPreComp.hpp"

#include <AddOns/AdcExtensions/Record.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

const INT max_calendar_description_len = 25;


class CalendarRecord: public Record {

    typedef Record Base;
    
    public: 
        enum CalendarCategory{
            Memo,
            Meeting,
            Birthday,
            CallRemind,
            Anniversary,
            Other,
            CategoryCounts
        };

        enum CalendarRecurrence{
            NoRepeat,
            Daily,
            Weekly,
            Monthly,
            Yearly,
            RecurrenceCounts
        };

        // constructors
        CalendarRecord();

        CalendarRecord(Date date, Time time, WString txt, CalendarCategory cat = Memo, CalendarRecurrence recurr = NoRepeat);

        //descrturctor
        virtual ~CalendarRecord();

        void Init();

        void SetCategory(CalendarCategory cat){m_data.category = cat;}

        CalendarCategory GetCategory(){return m_data.category;}

        void SetDate(Date date){m_data.date = date;}

        Date GetDate(){return m_data.date;}

        void SetTime(Time time){m_data.time = time;}

        Time GetTime(){return m_data.time;}

        void SetRecurrence(CalendarRecurrence recurr){m_data.recurrence = recurr;}

        CalendarRecurrence GetRecurrence(){return m_data.recurrence;}
        
        void SetDescription(const WString &txt){WStrCpy(m_data.description, txt);}

        const WCHAR *  GetDescription() const {return m_data.description;}

        virtual const UINT8* GetData();

        virtual void SetData(const UINT8* data);

        virtual INT GetPersistentSize();

        virtual void MarkDeleted();

        virtual BOOLEAN IsRecordDeleted();


    protected:
        struct Persist {
            CalendarCategory    category;
            Date                date;
            Time                time;
            CalendarRecurrence  recurrence;
            WCHAR               description[max_calendar_description_len+1];
        } m_data;

};

#endif  //CalendarRecord_hpp
