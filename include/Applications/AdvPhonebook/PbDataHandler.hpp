/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbDataHandler_hpp)
#define Mmi_PbDataHandler_hpp

#include <Auxiliary/QuickSortProvider.hpp>
#include <AdvPhonebook/PbSimProvider.hpp>

class PbDataHandler {

    public:

        PbDataHandler();
        virtual ~PbDataHandler();

        void Init();
        virtual Provider * GetPbProvider();
        virtual Provider * GetDistinctNameProvider();

        Provider * GetAdnProvider() { return &m_adn_provider; }
        Provider * GetFdnProvider() { return &m_fdn_provider; }
        Provider * GetMsIsdnProvider() { return &m_msisdn_provider; }
        Provider * GetBdnProvider() { return &m_bdn_provider; }
        Provider * GetSdnProvider() { return &m_sdn_provider; }

        virtual SortProvider * GetSortedNumberProvider();

        virtual void UpdateProvider(ProviderListener *listener = 0);
        virtual void UpdateSortedProvider(ProviderListener *listener = 0);

    private:
        void Update(Provider* provider, ProviderListener *listener = 0);

        PbSimProvider           m_adn_provider;
        PbSimProvider           m_fdn_provider;
        PbSimProvider           m_msisdn_provider;
        PbSimProvider           m_bdn_provider;
        PbSimProvider           m_sdn_provider;

        QuickSortProvider       m_sorted_no_prov;

    
};

#endif
