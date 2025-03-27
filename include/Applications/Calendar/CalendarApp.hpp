/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(CalendarApp_hpp)
#define CalendarApp_hpp

#include "CalendarRecord.hpp"
#include "CalendarAddRecordWin.hpp"
#include "CalendarProvider.hpp"
#include "CalendarMonthWin.hpp"

#include <GuiExtensions/MenuAction.hpp>
#include <GuiExtensions/MmiInfoBox.hpp>

#include <GuiExtensions/MmiAlert.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include <GuiExtensions/MmiPasswordPrompt.hpp>

#include <Auxiliary/QuickSortProvider.hpp>
#include <Common/MmiApplication.hpp>


/*  ========================================================================
    App
    ======================================================================== */
class CalendarApp : public MmiApplication
{
    typedef MmiApplication Base;

    public:

        CalendarApp();

        virtual ~CalendarApp();
        
        static CalendarApp* GetInstance();

        BOOLEAN SaveCalendarRecord(CalendarRecord* record);

        void SetCurrentRecordIdx(INT idx) {m_current_record = idx;}

        void AbortCalendarRecordIns();

        void UpdateAlarmList();

        BOOLEAN IsAlarmDay(Date date);

        CalendarProvider* GetCalendarProvider(){return &m_cal_provider;};
        

    protected:

        virtual void OnOpen();
        
        virtual void OnStartup();

        BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

    private:
        
        enum FeatureItemIds {           
            Calendar,
            CalendarAdd,
            CalendarGotoDay,
            CalendarViewDay,
            CalendarViewAll,
            CalendarStore,
            CalendarSetCategory,
            CalendarSetRecurrence,
            CalendarModify,
            CalendarDelete,
            CalendarDeleteAll,
            CalendarFeatureCnt
        };
                
        static CalendarApp          m_instance;
        CalendarMonthWin            m_month_win;
        Protector                   m_protector;
        CalendarProvider            m_cal_provider;
        INT                         m_current_record;
        QuickSortProvider           m_sort_by_date;
        FilterProvider              m_filter_by_date;
        EqualsRule                  m_equal_rule;
        Feature                     m_items[CalendarFeatureCnt];
};      

#endif  // CalendarApp_hpp


