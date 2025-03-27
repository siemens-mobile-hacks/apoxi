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

#if !defined(Adc_SmsUnreadProvider_hpp)
#define Adc_SmsUnreadProvider_hpp

#include <Adc/SmsProvider.hpp>

#if !defined(APOXI_SMS_NEW_PROVIDERS) && !defined(APOXI_DISABLE_FILTERED_SMS_PROVIDERS)

class SmsUnreadProvider : public SmsProvider
{
    typedef SmsProvider Base;

    public:
        SmsUnreadProvider();
        virtual ~SmsUnreadProvider();
        virtual INT GetProviderId() const;
        virtual INT RowCount();

    protected:
        virtual SmsFilterType GetSmsFilterType() const { return UnreadSmsFilterType; }
        virtual Tpdu::Status GetDestinationTpduStatus() const { return Tpdu::Read; }
};

#endif // !(APOXI_SMS_NEW_PROVIDERS)

#endif

