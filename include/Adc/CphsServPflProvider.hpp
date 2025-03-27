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

#if !defined(Adc_CphsServPflProvider_hpp)
#define Adc_CphsServPflProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimCphsHandler.hpp>

/*------------------------------------------------------------------
                            CphsServPflProvider
 ------------------------------------------------------------------*/

class SimCphsHandler;

class CphsServPflProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        CphsServPflProvider();
        virtual ~CphsServPflProvider();
        virtual INT GetProviderId() const;
        void Init(SimCphsHandler * cphs_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN Update(ProviderListener * listener = 0);
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);

        
    private:
        void ClearBufferVariables();

        SimCphsHandler * m_cphs_handler;

        INT      m_columnid;
        BOOLEAN  m_value;

};

#endif


