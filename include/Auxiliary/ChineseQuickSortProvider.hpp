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

#if ! defined(Auxiliary_ChineseQuickSortProvider_hpp)
#define Auxiliary_ChineseQuickSortProvider_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/QuickSortProvider.hpp>

class Provider;
class ProviderListener;

class ChineseQuickSortProvider : public QuickSortProvider
{
    public:
        typedef QuickSortProvider Base;

        enum SortMode {
            normal = 0,
            pinyin,
            stroke,
            bopomofo
        };

        ChineseQuickSortProvider();
        ChineseQuickSortProvider(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);
        virtual ~ChineseQuickSortProvider();

        virtual BOOLEAN Update(ProviderListener * listener = 0);        

        SortMode GetSortMode();
        void    SetSortMode(SortMode sort_mode);
        INT  SortCompare(WString* x1, WString* x2);

    protected:
        virtual void QuickSort(INT left, INT right, INT & depth);

    private:
        SortMode m_sort_mode;
        SortMode m_sorted_mode;
};

#endif


