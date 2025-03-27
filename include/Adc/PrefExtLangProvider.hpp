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

#if !defined(Adc_PrefExtLangProvider_hpp)
#define Adc_PrefExtLangProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>


/*------------------------------------------------------------------
                            PrefExtLangProvider
 ------------------------------------------------------------------*/

class PrefExtLangProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        PrefExtLangProvider();
        virtual ~PrefExtLangProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector, INT instance_nr = 0);
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
            m_commit_lang.Clear();
        }

        SimAuxHandler * m_aux_handler;
        WString         m_commit_lang;
        INT             m_instance_nr;
};

#endif

