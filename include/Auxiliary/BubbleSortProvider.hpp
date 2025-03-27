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

#if ! defined(_Adc_BubbleSortProvider_hpp)
#define _Adc_BubbleSortProvider_hpp

#include <Auxiliary/SortProvider.hpp>

class DataItem;
class FilterRule;

class BubbleSortProvider : public SortProvider
{
    public:
        typedef SortProvider Base;

        BubbleSortProvider();

        BubbleSortProvider(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);

        virtual ~BubbleSortProvider();

        void Init(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);

        virtual BOOLEAN Update(ProviderListener * listener = 0);
};

#endif


