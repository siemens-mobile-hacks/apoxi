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

#if !defined(Adc_CbmiProvider_hpp)
#define Adc_CbmiProvider_hpp

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>
#include <Auxiliary/ThreadSafeProvider.hpp>

/*------------------------------------------------------------------
                            CbmiProvider
 ------------------------------------------------------------------*/

class CbmiProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        CbmiProvider();
        virtual ~CbmiProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        void ClearBufferVariables() {
            m_commit_cbmi = 0xFFFF;
        }

        SimAuxHandler * m_aux_handler;
        UINT16          m_commit_cbmi;
};

#endif


