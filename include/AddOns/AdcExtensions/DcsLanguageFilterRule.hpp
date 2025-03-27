/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AdcExtensions_DcsLanguageFilterRule_hpp)
#define Apoxi_AdcExtensions_DcsLanguageFilterRule_hpp

#include <Auxiliary/FilterRule.hpp>

class DcsLanguageFilterRule : public FilterRule {
    typedef FilterRule Base;

    public:
        DcsLanguageFilterRule ();

        virtual ~DcsLanguageFilterRule ();

        virtual BOOLEAN ExecuteRule(const DataItem& dataitem);
};

#endif // Apoxi_AdcExtensions_DcsLanguageFilterRule_hpp

