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

#if !defined(Adc_PrefLangProvider_hpp)
#define Adc_PrefLangProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>

/*------------------------------------------------------------------
                            PrefLangProvider
 ------------------------------------------------------------------*/

class PrefLangProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        PrefLangProvider();
        virtual ~PrefLangProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN AppendRow();
        virtual BOOLEAN InsertRow(INT row);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);
        virtual BOOLEAN Update(ProviderListener * listener = 0);

    private:
        void ClearBufferVariables() {
            m_commit_lang = 0xFF;
        }

        SimAuxHandler * m_aux_handler;
        UINT8           m_commit_lang;
};

#endif


