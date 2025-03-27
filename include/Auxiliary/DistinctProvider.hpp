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

#if ! defined(Mmi_DistinctProvider_hpp)
#define Mmi_DistinctProvider_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/DataItem.hpp>
#include <Auxiliary/FilterProvider.hpp>
#include <Auxiliary/FilterRule.hpp>
#include <Auxiliary/QuickSortProvider.hpp>

class Provider;
class ProviderListener;

class DistinctRule : public NotEqualsRule
{
    public:
        typedef NotEqualsRule Base;

        DistinctRule();
        DistinctRule(const DataItem & ruleitem);

        virtual ~DistinctRule();

        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);

};

class DistinctProvider : public FilterProvider
{
    public:
        typedef FilterProvider Base;

        DistinctProvider();

        DistinctProvider(Provider * provider, INT columnid = 0);

        virtual ~DistinctProvider();

        void Init(Provider * provider, INT columnid = 0);

        virtual void SetFilterColumn(INT filtercolumn);

        virtual BOOLEAN GetDataItem(INT column,
                                    INT row,
                                    DataItem & item);

        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);

        virtual BOOLEAN GetChildRow(INT & childrow, INT row);

        virtual BOOLEAN CommitRow(INT row);

        virtual BOOLEAN DeleteRow(INT row);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

    protected:
        virtual BOOLEAN GetMappedRow(INT & mapped_row, INT row);

    private:
        QuickSortProvider   m_sort_prov;
        DistinctRule        m_distinct_rule;
        INT                 m_distinct_column;
        DataItem            m_new_dist_item;

};



#endif


