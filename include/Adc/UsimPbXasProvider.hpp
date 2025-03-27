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

#if !defined(Adc_UsimPbXasProvider_hpp)
#define Adc_UsimPbXasProvider_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/UsimPbHandler.hpp>

/*------------------------------------------------------------------
                            UsimPbXasProvider
 ------------------------------------------------------------------*/

class UsimPbXasProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        UsimPbXasProvider();
        virtual ~UsimPbXasProvider();
        virtual INT GetProviderId() const;
        void Init(UsimPbHandler * handler, Protector * protector, UsimPbAddType type);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN Update(ProviderListener * listener = 0);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);


    private:
        UsimPbHandler *      m_usimpb_handler;
        WString              m_commitstring;
        UsimPbAddType m_type;
};


#endif // APOXI_ENABLE_USIM_PHONEBOOK

#endif


