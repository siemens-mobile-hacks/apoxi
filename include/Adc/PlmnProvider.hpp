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

#if !defined(Adc_PlmnProvider_hpp)
#define Adc_PlmnProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <Apc/SignalTypes.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/CountryProvider.hpp>


/*------------------------------------------------------------------
                            PlmnProvider
 ------------------------------------------------------------------*/

class PlmnProvider : public Provider
{
    public:
        typedef Provider Base;
        PlmnProvider();
        virtual INT GetProviderId() const;
        virtual ~PlmnProvider();

        virtual Status GetStatus() const;
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);
        BOOLEAN LookupPlmnRow(INT & row, Mcc mcc, Mnc mnc);

};

#endif


