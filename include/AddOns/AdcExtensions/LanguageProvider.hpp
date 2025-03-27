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

#if ! defined(Apoxi_AdcExtensions_LanguageProvider_hpp)
#define Apoxi_AdcExtensions_LanguageProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <AddOns/AdcExtensions/LanguageCodeRes.hpp>
#include <AddOns/AdcExtensions/ProviderIds.hpp>

class LanguageProvider : public Provider
{
    typedef Provider Base;

    public:
        LanguageProvider();

        virtual ~LanguageProvider();

        virtual INT GetProviderId() const;

        virtual INT RowCount();

        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
};

#endif  // Apoxi_AdcExtensions_LanguageProvider_hpp

