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

#if !defined(Adc_SmsBaseUnreadProvider_hpp)
#define Adc_SmsBaseUnreadProvider_hpp

#include <Adc/SmsProvider.hpp>

#if defined(APOXI_SMS_NEW_PROVIDERS)

class SmsBaseUnreadProvider : public SmsProvider
{
    typedef SmsProvider Base;

    public:
        SmsBaseUnreadProvider();
        virtual ~SmsBaseUnreadProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();

    protected:
        virtual SmsFilterType GetSmsFilterType() const { return UnreadSmsFilterType; }
};

#endif // (APOXI_SMS_NEW_PROVIDERS)

#endif

