/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PsdDataConn_hpp)
#define Apoxi_PsdDataConn_hpp

#include <Socket/DataConn.hpp>
#include <Asc/PdpContextControl.hpp>
#include <Asc/PdpContextManager.hpp>

class PsdDataConnProfile;
class IpAddr;

class PsdDataConn : public DataConn, public PdpContextControl
{
    typedef DataConn Base;

    friend class NiSharedPtr<DataConn>;
    friend class DataConnProfile;

    public:
        virtual void OnDefineCompleted(PdpContext::ErrorCause cause);
        virtual void OnUndefineCompleted(PdpContext::ErrorCause cause);
        virtual void OnAuthenticateCompleted(PdpContext::ErrorCause cause);
        virtual void OnSetQualityOfServiceCompleted(
            PdpContext::ErrorCause cause);
        virtual void OnDeactivateCompleted(PdpContext::ErrorCause cause);
        virtual void OnConnectCompleted(PdpContext::ErrorCause cause);

        virtual void OnDeactivateIndication(PdpContext::ErrorCause cause,
            PdpContext::Origin origin = PdpContext::UnknownOrigin);

        virtual void OnSetPacketFilterCompleted(PdpContext::ErrorCause cause);

        virtual void OnSetCounterCompleted(PdpContext::ErrorCause cause);
        virtual void OnReadCounterCompleted(PdpContext::ErrorCause cause);

        virtual void OnSetAutomaticDnsServerNegotiationCompleted(
            PdpContext::ErrorCause cause);
        virtual void OnReadNegotiatedDnsServerAddressCompleted(
            PdpContext::ErrorCause cause);

        virtual void OnPsdLinkUpCompleted(INT error);
        virtual void OnPsdLinkDownCompleted(INT error);

        BOOLEAN GetDataCounters(UINT32 &session_sent, UINT32 &session_received,
            UINT32 &total_sent, UINT32 &total_received) const;

        BOOLEAN SetDataCounters(UINT32 total_sent = 0, UINT32 total_received = 0);

        virtual UINT8 GetNsapi() const;

        virtual BOOLEAN GetIpAddress(IpAddr &addr) const;

#if defined(APOXI_COMPAT_2_2_0)

        BOOLEAN GetIpAddr(IpAddr &addr) const {
            return GetIpAddress(addr);
        }
#endif

    protected:
        PdpContext *m_pdp_context;          
        PdpContext::ErrorCause m_pdp_error; 

        BOOLEAN m_context_defined;      
        BOOLEAN m_context_active;       
        BOOLEAN m_psd_linked_up;        

    protected:
        PsdDataConn(const DataConnProfilePtr &profile);

        virtual ~PsdDataConn();

    protected:
        virtual BOOLEAN DataConnIsBlocked() const;

        virtual void PostInfoMsg(MessageType type) const;

        virtual void DoSetup()
            { CreatePdpContext(); }

        void OnSetupResponse(PdpContext::ErrorCause cause,
            SocketControlMsgType success_scmt,
            DataConnCtrlCb on_success_callback);

        void OnReleaseResponse(PdpContext::ErrorCause cause,
            SocketControlMsgType success_scmt,
            DataConnCtrlCb on_release_callback);

        void CreatePdpContext();
        void DefinePdpContext();
        void SetAutomaticDnsServerNegotiation();
        void SetPacketFilter();
        void SetQualityOfService();
        void Authenticate();
        void Connect();
        void ReadNegotiatedDnsServerAddress();
        void LinkUp();
        void DeactivateContext();
        void LinkDown();
        void UndefineContext();

        virtual void DoRelease();

        virtual void Cleanup();

    protected:
        const PsdDataConnProfile& MyProfile() const {
            return (const PsdDataConnProfile &)Base::MyProfile();
        }

    private:
        friend class PsdDataConnCtrlCbs;

        void PostDataConnInfoMsg(DataConnInfoMsgType msg,
            PdpContext::ErrorCause pdp_err) const;

        mutable Semaphore m_data_counters_sem;
        mutable BooleanCondition m_data_counters_condition;
        PdpContextManager::DataCounters m_data_counters;
        UINT8 m_nsapi_linked_up;

        UINT8 m_cur_packet_filter_id;

     private:
        static void PsdIfStartCallbackHandler(INT error, void *client_arg);
        static void PsdIfStopCallbackHandler(INT error, void *client_arg);
};

#endif  // Apoxi_PsdDataConn_hpp


