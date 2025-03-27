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

#if !defined(Adc_UsimPbProvider_hpp)
#define Adc_UsimPbProvider_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Apc/UsimPbTypes.hpp>
#include <Adc/UsimPbHandler.hpp>
#include <Adc/UsimPbCommit.hpp>

/*------------------------------------------------------------------
                            UsimPbProvider
 ------------------------------------------------------------------*/

class UsimPbProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;
        UsimPbProvider();
        virtual ~UsimPbProvider();

        void Init(UsimPbHandler * handler, Protector * protector);
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
        virtual INT GetProviderId() const;
        virtual INT GetSortedColumnId() const;
        virtual INT GetProgress();
        UsimPbEntry * GetEntry(INT row);


    protected:
        void ClearBufferVariables();
        BOOLEAN CommitAdditionalAttributes(UINT simpos);

        WString                                 m_commit_string;
        PhoneNumber                             m_commit_phonenumber;
        UsimPbGroups                            m_commit_groups;
        PhoneNumberCommitArray                  m_commit_anr;
        WStringCommitArray                      m_commit_sne;
        WStringCommitArray                      m_commit_email;
        Uint8CommitArray                        m_commit_aas_rec;
        UINT8                                   m_commit_hiddeninfo;
        BOOLEAN                                 m_is_set_adn;
        BOOLEAN                                 m_is_set_hiddeninfo;

        UsimPbHandler * m_handler;

};



#endif //#if defined(APOXI_ENABLE_USIM_PHONEBOOK)

#endif


