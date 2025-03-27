/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_CmiProvider_hpp)
#define Adc_CmiProvider_hpp

#include <Adc/ProvIds.hpp>
#include <Auxiliary/ThreadSafeProvider.hpp>
#include <Adc/SimAuxHandler.hpp>

/*------------------------------------------------------------------
                            CmiProvider
 ------------------------------------------------------------------*/

class CmiProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        CmiProvider();
        virtual ~CmiProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * chv_handler, Protector * protector);
        virtual Provider::Status GetStatus() const;
        virtual BOOLEAN Update(ProviderListener * listener = 0);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

    private:
        SimAuxHandler *m_aux_handler;

};

#endif


