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

#if ! defined(CalendarProvider_hpp)
#define CalendarProvider_hpp

#include "CalendarAppPreComp.hpp"

#include "CalendarRecord.hpp"

#include <Auxiliary/IndexTable.hpp>
#include <AddOns/AdcExtensions/RecordHandler.hpp>
#include <Auxiliary/Protector.hpp>
#include <Auxiliary/ThreadSafeProvider.hpp>
#include <Config/Config.hpp>

/*------------------------------------------------------------------
                        Calendar provider
------------------------------------------------------------------*/

enum CalendarRecordColumnId{
    c_cal_category_id,
    c_cal_date_id,
    c_cal_time_id,
    c_cal_recurrence_id,
    c_cal_description_id,
    c_cal_text_for_list_item_id
};

class CalendarProvider : public ThreadSafeProvider {
    public:
        typedef ThreadSafeProvider Base;

        CalendarProvider();

        virtual ~CalendarProvider();

        void Init(Protector *protector);

        INT GetProviderId() const { return c_calendar_provider_id; }

        INT RowCount();

        INT MaxRowCount() { return c_max_calendar_records; }

        BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);

        BOOLEAN GetRecordData(INT row, CalendarRecord *dst);

        BOOLEAN SelectRow(INT row);

        BOOLEAN CommitRow(INT row);

        BOOLEAN DeleteRow(INT row);

        BOOLEAN DeleteAllRows();

        BOOLEAN AppendRow();

        void SetDateIsValid(BOOLEAN valid);

    protected:

        INT             m_row_count;
        CalendarRecord  m_current_calendar_record;
        CalendarRecord  m_delete_record;
        RecordHandler   m_handler;
        BOOLEAN         m_date_is_valid;
};

#endif  //CalendarProvider_hpp
