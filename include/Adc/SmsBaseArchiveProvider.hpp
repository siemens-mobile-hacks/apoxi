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

#if !defined(Adc_SmsArchiveProvider_hpp)
#define Adc_SmsArchiveProvider_hpp

#include <Adc/SmsProvider.hpp>

#if defined(APOXI_SMS_NEW_PROVIDERS)

class SmsBaseArchiveProvider : public SmsProvider
{
    typedef SmsProvider Base;

    public:
        SmsBaseArchiveProvider();
        virtual ~SmsBaseArchiveProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();

    protected:
        virtual SmsFilterType GetSmsFilterType() const { return ArchiveSmsFilterType; }
};

#endif // (APOXI_SMS_NEW_PROVIDERS)

#endif

