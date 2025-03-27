/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_CalendarRecordsList_hpp)
#define Mmi_CalendarRecordsList_hpp

#include <Gui/Lib.hpp>
#include "CalendarRecordsListBox.hpp"
#include "CalendarAddRecordWin.hpp"
#include "CalendarRecord.hpp"
#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

class CalendarRecordsList;

class CalendarRecordsList : public MmiWindow {
    typedef MmiWindow Base;

    public:
        CalendarRecordsList();
        void Init();

        void SetType(Date date);
        
        INT GetEntryCount(Date date) {  
            return m_listbox_model.GetEntryCount(date);
        }

        BOOLEAN DeleteSelectedItem();
        BOOLEAN DeleteAllItems();
        //
        BOOLEAN ModifySelectedItem();

        void UpdateView();

        void SetWindow(CalendarAddRecordWin& win);

    protected:
        virtual void OnOpen();

        virtual BOOLEAN OnMessage(const Message &msg);

    private:
        DrawableObjectListBox       m_listbox;
        CalendarRecordsListBoxModel m_listbox_model;        
        CalendarAddRecordWin*       m_modify_record_win;
        CalendarRecord              m_record_to_modify;
        WString                     m_title;
};

#endif  // Mmi_CalendarRecordsList_hpp
