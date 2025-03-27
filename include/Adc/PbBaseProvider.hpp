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

#if !defined(Adc_PbBaseProvider_hpp)
#define Adc_PbBaseProvider_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Adc/SimPbEntry.hpp>
#include <Adc/SimPbBaseHandler.hpp>

/*------------------------------------------------------------------
                            PbBaseProvider
 ------------------------------------------------------------------*/

class PbBaseProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        PbBaseProvider();
        virtual ~PbBaseProvider();

        void Init(SimPbBaseHandler * handler, Protector * protector, INT provid);
        virtual INT RowCount();
        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT columnid, INT row, DataItem & item);
        virtual const WString * GetWString(INT columnid, INT row);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT columnid);
        virtual BOOLEAN Update(ProviderListener * listener);
        virtual BOOLEAN CommitRow(INT row);
        virtual BOOLEAN SelectRow(INT row);
        virtual BOOLEAN AppendRow();
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener * listener = 0);
        virtual BOOLEAN IsWStringDataCached() const;
        SimPbEntry * GetEntry(INT row) {
            ASSERT_DEBUG(m_handler!=0);
            return m_handler->GetEntry(row);
        };

        virtual INT GetProviderId() const;
        virtual INT GetSortedColumnId() const;
        virtual INT GetProgress();


    protected:
        SimPbBaseHandler * GetHandler() { return m_handler; }

        INT GetAlphaTagSize();
        INT GetTagSize();

        void ClearBufferVariables();

        BOOLEAN DefaultCommitRow(INT row);
        BOOLEAN DefaultAppendRow();     
        BOOLEAN DefaultDeleteRow(INT row);
        BOOLEAN DefaultDeleteAllRows(ProviderListener * listener = 0);

        WString     m_commit_string;
        PhoneNumber m_commit_phonenumber;
        Number      m_commit_cmi_no;


        SimPbBaseHandler * m_handler;
        INT                m_provid;

};


#endif


