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

#if !defined(Adc_SmsProvider_hpp)
#define Adc_SmsProvider_hpp

#include <Auxiliary/ThreadSafeProvider.hpp>

#include <Apc/Sms.hpp>

#include <Adc/ProvIds.hpp>


class SimPduHandler;

class SmsProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        SmsProvider();
        virtual ~SmsProvider();
        virtual INT GetProviderId() const;
        void Init(SimPduHandler * sim_pdu_handler, Protector * protector);
        virtual INT RowCount();

        virtual INT MaxRowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);

        virtual BOOLEAN ToggleRow(INT row);
        virtual BOOLEAN DeleteRow(INT row);
        virtual BOOLEAN DeleteAllRows(ProviderListener *listener = 0);
        virtual BOOLEAN Update(ProviderListener *listener = 0);
        virtual BOOLEAN SetDataItem(const DataItem & item, INT column_id);
        virtual BOOLEAN CommitRow(INT row);
        virtual INT GetProgress();
        BOOLEAN DeleteAllSms(SmsDeleteStatus criteriamask, BOOLEAN smsreports = FALSE) {
            ASSERT_DEBUG(m_sim_pdu_handler!=0);
            return m_sim_pdu_handler->DeleteAllSms(criteriamask, smsreports);
        }
        BOOLEAN NotifyAsyncChange();

        static void SetEmptyNumberText(const WCHAR* text) { SimPduHandler::SetEmptyNumberText(text); }

        // is called if SmsDispatcher::OnMdhSmsTransmitStopInd times out
        void ForceNormalUpdateOnStartup() { m_forcenormalupdateonstartup = TRUE; }

        BOOLEAN CopyTo(INT row, const Sms::StorageType type, INT & src_row, INT & dst_row);
        BOOLEAN CopyTo(INT row, const Sms::StorageType type, ProtocolIdentifier pid, INT & src_row, INT & dst_row);
        
        INT FindRowByTpduNumber(INT tpdu_no);

    protected:
        SimPduHandler * m_sim_pdu_handler;

        BOOLEAN GetDataItem(INT column_id, DataItem &item, TpduHeaderInformation * headerinformation);

        virtual SmsFilterType GetSmsFilterType() const { return AllSmsFilterType; }
        virtual Tpdu::Status GetDestinationTpduStatus() const { return Tpdu::UndefinedStatus; }

    private:
        Tpdu::Status    CalcDestinationTpduStatus(INT row) const;
        void            ClearBufferVariables();
        
        BOOLEAN         m_forcenormalupdateonstartup;
        INT             m_column_id;
        UINT32          m_commit_ext_data;
};


class SmsCountProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        SmsCountProvider();
        virtual ~SmsCountProvider();
        virtual INT GetProviderId() const;
        void Init(SimPduHandler * sim_pdu_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);
        virtual BOOLEAN Update(ProviderListener *listener = 0);

    protected:
        SimPduHandler * m_sim_pdu_handler;

};

class SmsMsgWaitingProvider : public ThreadSafeProvider
{
    public:
        typedef ThreadSafeProvider Base;

        SmsMsgWaitingProvider();
        virtual ~SmsMsgWaitingProvider();
        virtual INT GetProviderId() const;
        void Init(SimPduHandler * sim_pdu_handler, Protector * protector);
        virtual INT RowCount();
        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem &item);
        virtual BOOLEAN Update(ProviderListener *listener = 0);

        void SetMdhWaitingIndicatorArray(const MdhWaitIndicatorArray & wia);

    protected:
        SimPduHandler * m_sim_pdu_handler;

    private:
        MdhWaitIndicatorArray m_wia;
        BOOLEAN               m_initialized;
};


#endif

