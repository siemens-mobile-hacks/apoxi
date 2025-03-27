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

#if !defined(Adc_SmsInboxProvider_hpp)
#define Adc_SmsInboxProvider_hpp

#include <Adc/SmsProvider.hpp>

#if defined(APOXI_SMS_NEW_PROVIDERS)

class SmsBaseInboxProvider : public SmsProvider
{
    typedef SmsProvider Base;

    public:
        SmsBaseInboxProvider();
        virtual ~SmsBaseInboxProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();

    protected:
        virtual SmsFilterType GetSmsFilterType() const { return InboxSmsFilterType; }
};

#endif // APOXI_SMS_NEW_PROVIDERS)

#endif

