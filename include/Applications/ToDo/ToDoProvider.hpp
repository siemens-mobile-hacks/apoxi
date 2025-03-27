/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_ToDoProvider_hpp)
#define Mmi_ToDoProvider_hpp

#include "ToDoRecord.hpp"
#include <Config/Config.hpp>
#include <Mmi/Common/SettingsProvider.hpp>
#include <Auxiliary/Protector.hpp>
#include <Auxiliary/IndexTable.hpp>
#include <AddOns/AdcExtensions/RecordHandler.hpp>

const INT c_max_char_visible_in_listbox_todolist = 30;

class ToDoProvider : public SettingsProvider {
    typedef SettingsProvider Base;
    public:
        ToDoProvider();

        ~ToDoProvider();

        void Init();

        INT GetProviderId() const {return c_todo_provider_id;} 

        INT RowCount();   

        INT MaxRowCount() {return c_max_todo_records;};   

        BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

        BOOLEAN SetDataItem(const DataItem &item, INT column_id);

        BOOLEAN SelectRow(INT row);

        BOOLEAN CommitRow(INT row);

        BOOLEAN AppendRow();

        void RestoreFactorySettings();

        BOOLEAN DeleteEntry(INT recno);

        BOOLEAN DeleteAllRows();

        BOOLEAN GetDataRecord(INT row, ToDoRecord *record);

        BOOLEAN DeleteRow(INT row);

        BOOLEAN ExistsRecord(INT row);

    private:

        const BitmapRes* GetMarkUnmarkIcon(INT idx);
            
        ToDoRecord          m_record;
        ToDoRecord          m_commit_record;
        RecordHandler       m_handler;      
};
#endif  // Mmi_MmiSettingsProvider_hpp
