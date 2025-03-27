/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbSortedProvider_hpp)
#define Mmi_PbSortedProvider_hpp

#include <Auxiliary/QuickSortProvider.hpp>

class PbSortedProvider : public QuickSortProvider {
    public:
        typedef QuickSortProvider Base;

        PbSortedProvider();
        virtual ~PbSortedProvider();

        virtual BOOLEAN DeleteAllRows(ProviderListener *listener);

        virtual Status GetStatus() const;

        virtual BOOLEAN Update(ProviderListener *listener);
        
};

#endif
