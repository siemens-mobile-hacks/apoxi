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

#if !defined(Adc_SmsSentProvider_hpp)
#define Adc_SmsSentProvider_hpp

#include <Adc/SmsProvider.hpp>

#if !defined(APOXI_SMS_NEW_PROVIDERS) && !defined(APOXI_DISABLE_FILTERED_SMS_PROVIDERS)

class SmsSentProvider : public SmsProvider
{
    typedef SmsProvider Base;

    public:
        SmsSentProvider();
        virtual ~SmsSentProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();

    protected:
        virtual SmsFilterType GetSmsFilterType() const { return SentSmsFilterType; }
        virtual Tpdu::Status GetDestinationTpduStatus() const { return Tpdu::Unsent; }

};

#endif // !(APOXI_SMS_NEW_PROVIDERS)

#endif

