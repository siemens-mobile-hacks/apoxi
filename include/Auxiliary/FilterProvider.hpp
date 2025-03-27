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

#if ! defined(_Adc_FilterProvider_hpp)
#define _Adc_FilterProvider_hpp

#include <Auxiliary/AbstractDelegationProvider.hpp>
#include <Auxiliary/IndexTable.hpp>


class DataItem;
class FilterRule;

/* NOTE: No writing is possible on a FilterProvider. Use <em>GetChildRow</em> to get
the row of the child provider and update the child provider directly.
See also: <em>Provider, DataItem, FilterRule</em>.*/
class FilterProvider : public AbstractDelegationProvider
{
    public:
        typedef AbstractDelegationProvider Base;

        FilterProvider();

        FilterProvider(Provider * provider, FilterRule * rule, INT columnid = 0, BOOLEAN negation = FALSE);

        virtual ~FilterProvider();

        void Init(Provider * provider, FilterRule * rule, INT columnid = 0, BOOLEAN negation = FALSE);

        void SetNegation(BOOLEAN negation) { m_negation = negation; }

        void SetFilterColumn(INT filtercolumn) { m_column = filtercolumn; }

        void SetFilterRule(FilterRule * rule) { m_rule = rule; }

        virtual INT RowCount();

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);

        virtual BOOLEAN InsertRow(INT row);

        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual void OnExecutingListener(Provider* provider = 0);
        
    protected:
        virtual BOOLEAN IsRowFiltered(Provider* base_provider, INT row, BOOLEAN negate);

        virtual void OnChildProviderModification(Provider* provider, const Provider::Modification &modification);

    private:
        virtual BOOLEAN UpdateIndexTable(ModificationType type, INT row);

        virtual INT FindFilteredRow(INT child_row);

        BOOLEAN      m_negation;
        INT          m_FilteredCnt;
        INT          m_column;
        FilterRule * m_rule;

        IndexTable<INT> m_FilteredRows;
};

#endif


