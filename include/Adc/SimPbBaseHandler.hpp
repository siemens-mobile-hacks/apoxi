/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimPbBaseHandler_hpp)
#define Adc_SimPbBaseHandler_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>

#include <Apc/SignalTypes.hpp>

#include <Adc/BaseDataHandler.hpp>
#include <Adc/SimPbEntryCont.hpp>


class SimAccessor;
class SimPbEntry;
class Provider;
class ProviderListener;

class SimPbBaseHandler : public BaseDataHandler
{
    typedef BaseDataHandler Base;

    public:
        SimPbBaseHandler();
        virtual ~SimPbBaseHandler();
        void Init(SimAccessor * handler,PhoneBookType pbtype, DataControlType dctype);

        BOOLEAN Initialize();
        void Reset();

        INT GetMaxCount();
        INT GetTagSize();
        PhoneBookType GetPhoneBookType() const { return m_pbtype; }
        DataControlType GetNotificationType() const { return m_dctype; }

        BOOLEAN LoadAllEntries(Provider * parentprov, ProviderListener * listener = 0);
        BOOLEAN IsSimAccessAllowed() const;
        BOOLEAN RefreshData(INT recno);
        void Refresh();

        BOOLEAN DeleteEntries(ProviderListener * listener = 0);

        INT GetAlphaTagSize();
        INT GetProgress() const { return m_progress; }
        INT GetExistingCount();

        INT GetNextFreePosition();

        SimPbEntry * GetEntry(INT recno);
        BOOLEAN UpdateEntry(INT recno, const WString & name, const PhoneNumber & bcdnr, 
                            UINT8 cmi_no, INT & newrow);
        BOOLEAN DeleteEntry(INT recno);
        BOOLEAN DeleteLndEntry(INT recno);

        BOOLEAN LookupAlphaId(const PhoneNumber & phno, WString & alphaid);
        INT GetFreeExtRecords();

    protected:
        INT GetMaxAdnCount() { return m_adn_maxrecs; }
        INT GetMaxFdnCount() { return m_fdn_maxrecs; }
        INT GetMaxLndCount() { return m_lnd_maxrecs; }
        INT GetMaxMsisdnCount() { return m_msisdn_maxrecs; }
        INT GetMaxCphsMBoxCount() { return m_cphs_mbox_maxrecs; }
        INT GetMaxCphsInfoNoCount() { return m_cphs_infono_maxrecs; }
        INT GetMaxSdnCount() { return m_sdn_maxrecs; }  
        INT GetMaxBdnCount() { return m_bdn_maxrecs; } 
        INT GetMaxMbdnCount() { return m_mbdn_maxrecs; } 

        INT GetAdnTagSize() { return m_adn_tagsize; }
        INT GetFdnTagSize() { return m_fdn_tagsize; }
        INT GetLndTagSize() { return m_lnd_tagsize; }
        INT GetMsisdnTagSize() { return m_msisdn_tagsize; }
        INT GetCphsMBoxTagSize() { return m_cphs_mbox_tagsize; }
        INT GetCphsInfoNoTagSize() { return m_cphs_infono_tagsize; }
        INT GetSdnTagSize() { return m_sdn_tagsize; }   
        INT GetBdnTagSize() { return m_bdn_tagsize; }   
        INT GetMbdnTagSize() { return m_mbdn_tagsize; }   

        static BOOLEAN  m_pbinfo_initialized;
        static UINT8 *  m_readwritebuffer; 
        static INT      m_readwritebuffersize; 

        static INT      m_adn_tagsize;
        static INT      m_fdn_tagsize;
        static INT      m_lnd_tagsize;
        static INT      m_msisdn_tagsize;
        static INT      m_cphs_mbox_tagsize;
        static INT      m_cphs_infono_tagsize;
        static INT      m_sdn_tagsize;
        static INT      m_bdn_tagsize;
        static INT      m_mbdn_tagsize;

        static INT      m_adn_maxrecs; 
        static INT      m_fdn_maxrecs;
        static INT      m_lnd_maxrecs;
        static INT      m_msisdn_maxrecs; 
        static INT      m_cphs_mbox_maxrecs; 
        static INT      m_cphs_infono_maxrecs; 
        static INT      m_sdn_maxrecs; 
        static INT      m_bdn_maxrecs; 
        static INT      m_mbdn_maxrecs; 

        static INT      m_prefered_alloc_wstring_size;

        INT FillRWBuffer(const WString & name, INT txtlen, const PhoneNumber & bcdnr);
        void EmptyRWBuffer() { 
            if(m_readwritebuffer!=0 && m_readwritebuffersize>0) {
                memset(m_readwritebuffer,0xff,m_readwritebuffersize);   
            }
        }

        SimUpdateStatus LoadContainerEntry(INT recno);

    protected:
        SimPbEntryCont * GetEntryContainer() { return m_container; }
        void SetEntryContainer(SimPbEntryCont * cont) { m_container = cont; }

    private:
        INT                 m_progress;
        INT                 m_lastprogress;
        SimPbEntryCont *    m_container;
        DataControlType     m_dctype;
        PhoneBookType       m_pbtype;

};

#endif


