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

#if !defined(Adc_CountryProvider_hpp)
#define Adc_CountryProvider_hpp

#include <Adc/ProvIds.hpp>
#include <Auxiliary/Provider.hpp>

/*------------------------------------------------------------------
                            CountryProvider
 ------------------------------------------------------------------*/
class CountryProvider : public Provider
{
    public:
        typedef Provider Base;
        CountryProvider();
        virtual ~CountryProvider();
        virtual INT GetProviderId() const;

        virtual Provider::Status GetStatus() const;
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

};

#endif


