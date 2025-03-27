/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_CalendarListWin_hpp)
#define Mmi_CalendarListWin_hpp

#include <GuiExtensions/MmiItemListWindow.hpp>
#include <Gui/ItemContainer.hpp>

#include <Auxiliary/MainProvider.hpp>
#include <Auxiliary/QuickSortProvider.hpp>
#include <Auxiliary/FilterProvider.hpp>
#include <Auxiliary/FilterRule.hpp>

#include "CalendarAddRecordWin.hpp"
#include <Common/Items/ProviderProxyContainer.hpp>

class CalendarListWin : public MmiItemListWindow {

    typedef MmiItemListWindow Base;

    public:
        
        CalendarListWin();

        virtual ~CalendarListWin();
        
        void Init(Provider* provider);

        void SetType(Date date);

        BOOLEAN ModifySelectedItem();

        void SetWindow(CalendarAddRecordWin& win);

        BOOLEAN DeleteAllItems();

        BOOLEAN DeleteSelectedItem();

                
    protected:
        virtual void OnOpen();

        virtual void OnClose();

        virtual void OnGetFocus();

    private:        

        void Update(Date date);

        ProviderProxyContainer      m_provider_cont;
        INT                         m_selected_index;
        Provider                    *m_provider;
        AbstractDelegationProvider  *m_current_provider;
        Date                        m_date;
        INT                         m_updated_row;
        MainProvider                m_main_provider;
        QuickSortProvider           m_sort_date_provider;
        QuickSortProvider           m_sort_time_provider;
        FilterProvider              m_filter_by_day_provider;
        EqualsRule                  m_rule;
        CalendarAddRecordWin*       m_modify_record_win;
};

#endif


