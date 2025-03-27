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

#if !defined(Adc_UsimPbPropertyProvider_hpp)
#define Adc_UsimPbPropertyProvider_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/UsimPbHandler.hpp>

/*------------------------------------------------------------------
                            UsimPbPropertyProvider
 ------------------------------------------------------------------*/

class UsimPbPropertyProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        UsimPbPropertyProvider();
        virtual ~UsimPbPropertyProvider();
        virtual INT GetProviderId() const;
        void Init(UsimPbHandler * handler, Protector * protector);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        UsimPbHandler *      m_usimpb_handler;
};


#endif // APOXI_ENABLE_USIM_PHONEBOOK

#endif


