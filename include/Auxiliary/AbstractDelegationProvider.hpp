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

#if ! defined(_Auxiliary_AbstractDelegationProvider_hpp)
#define _Auxiliary_AbstractDelegationProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <Auxiliary/Observer.hpp>
#include <Auxiliary/IndexTable.hpp>

class DataItem;

class AbstractDelegationProvider : public Provider, public Observer
{
    public:
        typedef Provider Base;

        AbstractDelegationProvider();

        AbstractDelegationProvider(Provider * child_provider);
        virtual ~AbstractDelegationProvider();

        Provider* GetChildProvider() const { return m_child_provider; }

        virtual INT GetProviderId() const;

        void Init(Provider * child_provider);

        virtual INT RowCount();

        virtual INT MaxRowCount();

        virtual INT ColumnCount() const;

        virtual const ColumnInfo * GetColumnInfo(INT id);

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item) = 0;

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

        virtual BOOLEAN GetChildRow(INT & childrow, INT row) = 0;

        virtual INT GetBaseRow(INT row);

//      virtual INT GetColumnId(INT column);

//      virtual const ColumnInfo * GetColumnInfoPerId(INT id);

        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

        virtual void OnExecutingListener(Provider* provider = 0);

        virtual BOOLEAN IsWStringDataCached() const;
        
        virtual INT GetSortedColumnId() const;

        INT GetNewChildRow() const { return (m_child_provider != 0) ? m_child_provider->GetModifiedRow() : c_no_row; }
        
    protected:
        virtual void SetProgress (INT progress);

        virtual BOOLEAN GetMappedRow(INT & mappedrow, INT row);

        void SetChildProvider(Provider* child_provider);

        virtual void OnUpdate(ObservableObject *obs_obj);
        
        virtual void OnChildProviderModification(Provider* provider, const Provider::Modification& modification);

        void ShiftIndexTableUp(IndexTable<INT>* idx_table, INT start, INT end);
        void ShiftIndexTableDown(IndexTable<INT>* idx_table, INT start, INT end);
        void ShiftIndexTableValues(IndexTable<INT>* idx_table, INT threshold, BOOLEAN up);

        INT GetIndexTableIndex(IndexTable<INT>* table, INT child_row);
        
        BOOLEAN UpdateChildProvider();

    private:
        Provider *   m_child_provider;
        INT          m_progress;
};

class DelegationProviderListener : public ProviderListener {
    public:
        DelegationProviderListener(AbstractDelegationProvider * provider, ProviderListener * child_listener);

        virtual ~DelegationProviderListener();

        virtual void OnExecuting();

    private:
        AbstractDelegationProvider * m_provider;
        ProviderListener * m_child_listener;

};

#endif  // _Auxiliary_AbstractDelegationProvider_hpp

