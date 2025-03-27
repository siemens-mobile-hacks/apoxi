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

#if ! defined(_Adc_SortProvider_hpp)
#define _Adc_SortProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>
#include <Auxiliary/IndexTable.hpp>

class DataItem;
class FilterRule;

class SortProvider : public AbstractDelegationProvider
{
    public:
        typedef AbstractDelegationProvider Base;

        SortProvider();

        SortProvider(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);

        virtual ~SortProvider();

        void Init(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);

        void SetSortOrder(BOOLEAN sortorder) { m_order = sortorder; }

        void SetSortColumn(INT sortcolumn) { m_columnid = sortcolumn; }

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);

        virtual BOOLEAN Update(ProviderListener * listener) = 0;

        virtual void OnExecutingListener(Provider* provider = 0);

        virtual BOOLEAN InsertRow(INT row);

    protected:
        virtual void OnChildProviderModification(Provider* provider, const Provider::Modification& modification);

        virtual BOOLEAN UpdateIndexTable(ModificationType type, INT row);
        
        virtual void ResizeIndexTable();
        virtual INT FindSortedRow(INT row);

        INT             m_columnid;
        BOOLEAN         m_order;

        IndexTable<INT> m_SortedRows;
};

#endif


