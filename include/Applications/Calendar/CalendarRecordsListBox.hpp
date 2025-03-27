/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_CalendarRecordsListBox_hpp)
#define Mmi_CalendarRecordsListBox_hpp

#include "CalendarRecord.hpp"
#include <GuiExtensions/LabelListBoxModel.hpp>
#include <Auxiliary/MainProvider.hpp>
#include <Auxiliary/QuickSortProvider.hpp>
#include <Auxiliary/FilterProvider.hpp>
#include <Auxiliary/FilterRule.hpp>

class CalendarRecordsListBoxModel : public LabelListBoxModel {
    typedef LabelListBoxModel Base;

    public:
        CalendarRecordsListBoxModel();
        
        explicit CalendarRecordsListBoxModel(DrawableObjectListBox *listbox);

        void Init(DrawableObjectListBox *listbox);

        virtual const WCHAR* GetCellText(INT index, BOOLEAN highlighted);

        virtual const BitmapRes* GetCellIcon(INT index, BOOLEAN highlighted);

        void SetType(Date date);

        INT GetEntryCount(Date date);

        void UpdateRow(INT row);

        WString GetNote();  

        void DeleteItem(INT index);

        void DeleteAllItems();

        BOOLEAN GetCalendarRecord(INT index, CalendarRecord *rec);

    private:
        Provider            *m_provider;
        AbstractDelegationProvider *m_current_provider;
        Date                m_date;
        INT                 m_updated_row;
        MainProvider        m_main_provider;
        QuickSortProvider   m_sort_date_provider;
        QuickSortProvider   m_sort_time_provider;
        FilterProvider      m_filter_by_day_provider;
        EqualsRule          m_rule;

        Vector<WString>     m_name_buf;

        void                Update(Date);
};

#endif  // Mmi_CalendarRecordsListBox_hpp
