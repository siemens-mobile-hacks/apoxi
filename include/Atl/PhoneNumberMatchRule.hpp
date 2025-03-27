/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PhoneNumberMatchRule_hpp)
#define Mmi_PhoneNumberMatchRule_hpp

#include <Auxiliary/FilterRule.hpp>
#include <Auxiliary/DataItem.hpp>
#include <Auxiliary/PhoneNumber.hpp>

class PhoneNumberMatchRule : public FilterRule {
    typedef FilterRule Base;

    public:
        PhoneNumberMatchRule();

        PhoneNumberMatchRule(const DataItem & ruleitem);

        virtual ~PhoneNumberMatchRule();

        void Init(const DataItem & ruleitem);

        virtual BOOLEAN ExecuteRule(const DataItem & dataitem);
    private:
        CHAR m_phoneno[c_max_bcd_number_size*2+1];

};

#endif  // Mmi_PhoneNumberMatchRule_hpp


