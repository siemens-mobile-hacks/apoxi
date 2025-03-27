/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_CachingSortProvider_hpp)
#define Auxiliary_CachingSortProvider_hpp

#include <Auxiliary/QuickSortProvider.hpp>

class CachingSortProvider : public QuickSortProvider
{
    public:
        typedef QuickSortProvider Base;

        CachingSortProvider();

        CachingSortProvider(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);

        virtual ~CachingSortProvider();

        void Init(Provider * provider, INT columnid = 0, BOOLEAN order = TRUE);

        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        BOOLEAN CachedQuickSort(INT row_count);
        void MergeSortCacheIndizes(DataItem* cache, INT low, INT high, INT cache_offset);
};

#endif  // Auxiliary_CachingSortProvider_hpp

