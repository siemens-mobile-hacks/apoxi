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

#if ! defined(_Adc_QuickSortProvider_hpp)
#define _Adc_QuickSortProvider_hpp

#include <Auxiliary/SortProvider.hpp>
#if defined(APOXI_DISABLE_RECURSIVE_PROVIDER_SORTING)
#include <Auxiliary/Vector.hpp>
#endif
class DataItem;
class FilterRule;

#if defined(APOXI_DISABLE_RECURSIVE_PROVIDER_SORTING)

#endif
class QuickSortProvider : public SortProvider
{
    public:
        typedef SortProvider Base;
#if defined(APOXI_DISABLE_RECURSIVE_PROVIDER_SORTING)
        typedef Vector<INT> VectorStackType;
#endif

        QuickSortProvider();

        QuickSortProvider(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);
        
        virtual ~QuickSortProvider();

        void Init(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);     

        virtual BOOLEAN Update(ProviderListener * listener = 0);
        
    protected:              
        IndexTable<INT>  m_sortbuffer;
#if defined(APOXI_DISABLE_RECURSIVE_PROVIDER_SORTING)       
        VectorStackType * m_stackbuffer;
#endif

        void QuickSortWString(INT left, INT right, INT & depth);
        void QuickSortNumber(INT left, INT right, INT & depth);
        virtual void QuickSort(INT left, INT right, INT & depth);

};

#endif


