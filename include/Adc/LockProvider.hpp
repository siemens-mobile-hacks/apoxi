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

#if !defined(Adc_LockProvider_hpp)
#define Adc_LockProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>
#include <Apc/LockTypes.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimChvHandler.hpp>


/*------------------------------------------------------------------
                            LockProvider
 ------------------------------------------------------------------*/

class LockProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        LockProvider();
        virtual ~LockProvider();
        virtual INT GetProviderId() const;
        void Init(SimChvHandler * chv_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);

    private:
        SimChvHandler *m_chv_handler;
};

#endif


