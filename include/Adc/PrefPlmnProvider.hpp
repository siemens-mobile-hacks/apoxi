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

#if !defined(Adc_PrefPlmnProvider_hpp)
#define Adc_PrefPlmnProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/ProvIds.hpp>
#include <Adc/SimAuxHandler.hpp>

/*------------------------------------------------------------------
                            PrefPlmnProvider
 ------------------------------------------------------------------*/

class PrefPlmnProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        PrefPlmnProvider();
        virtual ~PrefPlmnProvider();
        virtual INT GetProviderId() const;
        void Init(SimAuxHandler * aux_handler, Protector * protector);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN AppendRow();
        virtual BOOLEAN InsertRow(INT row);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN SelectRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);
        virtual BOOLEAN Update(ProviderListener * listener = 0);


    private:
        void ClearBufferVariables() {
            m_commit_mnc = InvalidMnc;
            m_commit_mcc = InvalidMcc;
            m_commit_ati = 0x0000;
        }

        BcdPlmn GetBcdPlmn() const;

        SimAuxHandler * m_aux_handler;
        Mnc             m_commit_mnc;
        Mcc             m_commit_mcc;
        UINT16          m_commit_ati;
};

#endif


