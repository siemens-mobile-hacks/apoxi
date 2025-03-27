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

#if ! defined(_Apoxi_AuxExtensions_DualFilterProvider_hpp)
#define _Apoxi_AuxExtensions_DualFilterProvider_hpp

#include <Auxiliary/FilterProvider.hpp>

class DataItem;
class FilterRule;

/* NOTE: No writing is possible on a DualFilterProvider. Use <em>GetChildRow</em> to get
the row of the child provider and update the child provider directly.
See also: <em>Provider, DataItem, FilterRule</em>.*/
class DualFilterProvider : public FilterProvider
{
    typedef FilterProvider Base;
    public:

        enum FilterOperator {
            AndFilterOp,                // includes rows, where both rules matches
            OrFilterOp,                 // includes rows, where at least one rule match
            XorFilterOp,                // includes rows, where the first or the second, but not both rules matches
            FirstAndNotSecondFilterOp,  // includes rows, where the first but not the second rule match
            NotFirstAndSecondFilterOp,  // includes rows, where the not the first but the second rule match
            FirstOrNotSecondFilterOp,   // includes rows, where the first or not the second rule match
            NotFirstOrSecondFilterOp    // includes rows, where the not the first or the second rule match
        };

        DualFilterProvider();

        DualFilterProvider(Provider * provider, FilterRule * fst_rule, FilterRule* snd_rule,
                            INT fst_columnid = 0, INT snd_columnid = 0, FilterOperator op = AndFilterOp, 
                            BOOLEAN negation = FALSE);
        virtual ~DualFilterProvider();

        void Init(Provider * provider, FilterRule * fst_rule, FilterRule* snd_rule,
                    INT fst_columnid = 0, INT snd_columnid = 0, FilterOperator op = AndFilterOp, 
                    BOOLEAN negation = FALSE);

        void SetSecondFilterColumn(INT filtercolumn) { m_snd_column = filtercolumn; }

        void SetSecondFilterRule(FilterRule * rule) { m_snd_rule = rule; }

        virtual BOOLEAN SetParameter(const DataItem &item);

    protected:
        virtual BOOLEAN IsRowFiltered(Provider* base_provider, INT row, BOOLEAN negate);

    private:
        INT             m_snd_column;
        FilterOperator  m_filter_op;
        FilterRule*     m_snd_rule;

};

#endif  // _Apoxi_AuxExtensions_DualFilterProvider_hpp


