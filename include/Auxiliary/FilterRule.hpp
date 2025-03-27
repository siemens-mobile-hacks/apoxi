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

#if ! defined(_Adc_FilterRule_hpp)
#define _Adc_FilterRule_hpp

#include <Auxiliary/DataItem.hpp>



class DataItem;

class FilterRule
{
    public:
        FilterRule();
        FilterRule(const DataItem & ruleitem);
        FilterRule(const DataItem & ruleitem, const DataItem & rule2item);
        virtual ~FilterRule();
        void Init(const DataItem & ruleitem) { m_ruleitem = ruleitem; }
        void Init(const DataItem & ruleitem, const DataItem & rule2item);

        virtual BOOLEAN ExecuteRule(const DataItem & dataitem) = 0;

    protected:
        DataItem m_ruleitem;
        DataItem m_rule2item;
};


class EqualsRule : public FilterRule
{
    public:
        typedef FilterRule Base;
        EqualsRule();
        EqualsRule(const DataItem & ruleitem);
        virtual ~EqualsRule();
        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);

};

class NotEqualsRule : public FilterRule
{
    public:
        typedef FilterRule Base;
        NotEqualsRule();
        NotEqualsRule(const DataItem & ruleitem);
        virtual ~NotEqualsRule();
        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);

};

class RangeRule : public FilterRule
{
    public:
        typedef FilterRule Base;
        RangeRule();
        RangeRule(const DataItem & ruleitem, const DataItem & rule2item);
        virtual ~RangeRule();
        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);
};

class LessRule : public FilterRule
{
    public:
        typedef FilterRule Base;
        LessRule();
        LessRule(const DataItem & ruleitem);
        virtual ~LessRule();
        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);

};

class GreaterRule : public FilterRule
{
    public:
        typedef FilterRule Base;

        GreaterRule();
        GreaterRule(const DataItem & ruleitem);
        virtual ~GreaterRule();
        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);

};


#endif


