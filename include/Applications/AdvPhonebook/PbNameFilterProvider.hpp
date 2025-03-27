/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbNameFilterProvider_hpp)
#define Mmi_PbNameFilterProvider_hpp

#include <Auxiliary/FilterProvider.hpp>
#include <Config/Config.hpp>

class PbNameFilterProvider : public FilterProvider {
    public:
        typedef FilterProvider Base;

        PbNameFilterProvider();
        PbNameFilterProvider(Provider * provider, 
                             FilterRule * rule, 
                             INT columnid = 0, 
                             BOOLEAN negation = FALSE); 
                             
        virtual ~PbNameFilterProvider();

        virtual INT GetProviderId() const;

        virtual Status GetStatus() const;

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

        virtual BOOLEAN SetParameter(const DataItem &item);

        virtual BOOLEAN Update(ProviderListener *listener);

    private:
        PhoneNumber m_phoneno;
        BOOLEAN     m_new_param;
};

#endif
