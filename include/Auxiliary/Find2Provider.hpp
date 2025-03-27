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

#if ! defined(_Adc_Find2Provider_hpp)
#define _Adc_Find2Provider_hpp

#include <Auxiliary/FindProvider.hpp>



class DataItem;
class FilterRule;

class Find2Provider : public FindProvider
{
    public:
        typedef FindProvider Base;
        Find2Provider();
        Find2Provider(Provider * provider, FilterRule * rule, INT column, FilterRule * rule2, INT column2);
        virtual ~Find2Provider();

        void Init(Provider * provider, FilterRule * rule, INT column, FilterRule * rule2, INT column2);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        INT          m_column2;
        FilterRule * m_rule2;
};

#endif


