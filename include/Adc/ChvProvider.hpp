/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_ChvProvider_hpp)
#define Adc_ChvProvider_hpp

#include <Adc/ProvIds.hpp>
#include <Auxiliary/ThreadSafeProvider.hpp>
#include <Adc/SimChvHandler.hpp>

/*------------------------------------------------------------------
                            ChvProvider
 ------------------------------------------------------------------*/

class ChvProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        ChvProvider();
        virtual ~ChvProvider();
        virtual INT GetProviderId() const;
        void Init(SimChvHandler * chv_handler, Protector * protector);
        virtual Provider::Status GetStatus() const;
        virtual BOOLEAN Update(ProviderListener * listener = 0);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

    private:
        SimChvHandler *m_chv_handler;

};

#endif


