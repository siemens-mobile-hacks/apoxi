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

#if !defined(Adc_SmsClass0Provider_hpp)
#define Adc_SmsClass0Provider_hpp

#include <Adc/SmsProvider.hpp>

class SmsClass0Provider : public SmsProvider
{
    typedef SmsProvider Base;

    public:

        SmsClass0Provider();
        virtual ~SmsClass0Provider();
        virtual Status GetStatus() const;
        virtual INT GetProviderId() const;
//      void Init();
        virtual INT RowCount();
        virtual BOOLEAN Update(ProviderListener *listener = 0);

        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

        virtual BOOLEAN ToggleRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener *listener = 0);
        virtual INT GetProgress();

    private:
        Tpdu m_tpdu;
};

#endif


