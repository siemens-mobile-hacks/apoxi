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

#if !defined(Adc_SmsOutboxProvider_hpp)
#define Adc_SmsOutboxProvider_hpp

#include <Adc/SmsProvider.hpp>

#if defined(APOXI_SMS_NEW_PROVIDERS)

class SmsBaseOutboxProvider : public SmsProvider
{
    typedef SmsProvider Base;

    public:
        SmsBaseOutboxProvider();
        virtual ~SmsBaseOutboxProvider();
        virtual INT GetProviderId() const;

        virtual INT RowCount();

    protected:
        virtual SmsFilterType GetSmsFilterType() const { return OutboxSmsFilterType; }
};

#endif // (APOXI_SMS_NEW_PROVIDERS)

#endif

