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
#if ! defined(_Adc_Provider_hpp)
#define _Adc_Provider_hpp

#include <Auxiliary/DataItem.hpp>
#include <Auxiliary/ProviderListener.hpp>
#include <Auxiliary/ObservableObject.hpp>

/*------------------------------------------------------------------
                            ColumnInfo
 ------------------------------------------------------------------*/

struct ColumnInfo {
    INT       colid;
    DataType  type;
};

/*------------------------------------------------------------------
                        Provider constants
 ------------------------------------------------------------------*/

const INT  c_append_row         = -1;
const INT  c_no_row             = -2;
const INT  c_invalid_colid      = -3;

// class ProviderListener;

class Provider : public ObservableObject
{
    public:
        enum Status {
            undefined,
            updated,
            updating,
            changed
        };

        enum ModificationType {
            Append,
            Insert,
            Commit,
            Delete,
            DeleteAll,
            Toggle,
            UndefinedModification
        };

        class Modification {
            public:
                Modification(ModificationType type = UndefinedModification, INT row = c_no_row) 
                    : m_type(type), m_row(row), m_original_row_set(FALSE), m_original_row(c_no_row) {}

                Modification(ModificationType type, INT row, INT original_row) 
                    : m_type(type), m_row(row), m_original_row_set(TRUE), m_original_row(original_row) {}

                void SetType(ModificationType type) { m_type = type; }

                void SetRow(INT row) { m_row = row; }

                void SetOriginalRow(INT original_row) { m_original_row_set = TRUE; m_original_row = original_row; }

                ModificationType GetType() const { return m_type; }

                INT GetRow() const { return m_row; }

                INT GetOriginalRow() const { return m_original_row_set ? m_original_row : m_row; }

        private:
                ModificationType m_type;
                INT m_row;
                BOOLEAN m_original_row_set;
                INT m_original_row;
        };

    public:
        Provider();
        
        virtual ~Provider();

        virtual INT GetProviderId() const = 0;

        virtual Status GetStatus() const;

        virtual INT RowCount() = 0;

        virtual INT MaxRowCount();   // to be overwritten if differs

        virtual INT ColumnCount() const;

        virtual const ColumnInfo * GetColumnInfo(INT column);

        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item) = 0;

        virtual const WString * GetWString(INT columnid, INT row);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        virtual BOOLEAN SelectRow(INT row);

        virtual BOOLEAN CommitRow(INT row);
        
        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN AppendRow();

        virtual BOOLEAN InsertRow(INT row);

        virtual BOOLEAN ToggleRow(INT row);

        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

        virtual INT GetProgress();

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual INT GetBaseRow(INT row);

        virtual BOOLEAN ExistColumn(INT colid);
        
        virtual INT GetColumnId(INT column);

        virtual const ColumnInfo * GetColumnInfoPerId(INT id);

        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

        BOOLEAN IsUpdating() const;
        
        virtual BOOLEAN IsWStringDataCached() const;

        virtual INT GetSortedColumnId() const;

        const Provider::Modification& GetLastModification() const { return m_last_modification; }

        INT GetModifiedRow() const { return m_last_modification.GetRow(); }

        Provider::ModificationType GetModificationType() const { return m_last_modification.GetType(); }

        void SetLastModification(const Provider::Modification& modification) { m_last_modification = modification; }

        void SetModifiedRow(INT row) { m_last_modification.SetRow(row); }

        void SetModificationType(Provider::ModificationType type) { m_last_modification.SetType(type); }

        void ResetModification();       

        void SetStatus(Status status) { m_status = status; }

    protected:

        void SetColumnInfoTable(const ColumnInfo * table) { m_columninfo = table; }

        BOOLEAN IsInRange(INT row);

        void UpdateModification(ModificationType mod_type, INT row);

        Status              m_status;
        const ColumnInfo *  m_columninfo;

    private:
        
        Provider::Modification m_last_modification;
};


#endif


