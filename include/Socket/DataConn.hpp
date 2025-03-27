/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DataConn_hpp)
#define Apoxi_DataConn_hpp

#include <Auxiliary/StateMachine.hpp>
#include <Auxiliary/EventData.hpp>
#include <Kernel/Condition.hpp>
#include <Kernel/MsgTypes.hpp>
#include <Socket/DataConnProfile.hpp>

#if defined(APOXI_COMPAT_1_13_0)
    #include <Socket/DataConnManager.hpp>
#endif

class SocketData;

class DataConn : public StateMachine
{
    typedef StateMachine Base;

    friend class NiSharedPtr<DataConn>;
    friend class DataConnManager;
    friend class DataConnProfile;

    private:
        struct SocketEventData : public EventData
        {
            SocketData &m_sd;
            SocketEventData(SocketData &sd);
        };

        struct ReleaseEventData : public EventData
        {
            BOOLEAN &m_do_release;
            BOOLEAN &m_do_block;
            ReleaseEventData(BOOLEAN &do_release, BOOLEAN &do_block);
        };

    protected:
        enum DataConnState {
            st_inactive = 0,

            st_start_setup,
            st_in_setup,
            st_set_on_wait_for_setup,
            st_check_cancel,
            st_set_on_cancel,
            st_setup_success,
            st_setup_failure,

            st_active,
            st_idle_timeout,
            st_in_hold,
            st_reactivate,
            st_deactivate,

            st_in_trigger_release,
            st_start_release,
            st_in_release,
            st_ignore_setup_req,
            st_released,

            st_max_states
        };

    private:
        /* State machine state functions for all phases. */

        void ST_inactive(EventData *);

        void ST_start_setup(EventData /*SocketEventData*/ *);
        void ST_in_setup(EventData *);
        void ST_set_on_wait_for_setup(EventData /*SocketEventData*/ *);
        void ST_check_cancel(EventData /*SocketEventData*/ *);
        void ST_set_on_cancel(EventData *);
        void ST_setup_success(EventData *);
        void ST_setup_failure(EventData *);

        void ST_active(EventData *);
        void ST_idle_timeout(EventData *);
        void ST_in_hold(EventData *);
        void ST_reactivate(EventData /*SocketEventData*/ *);
        void ST_deactivate(EventData /*SocketEventData*/ *);

        // Release phase.
        void ST_in_trigger_release(EventData *);
        void ST_start_release(EventData /*ReleaseEventData*/ *);
        void ST_in_release(EventData *);
        void ST_ignore_setup_req(EventData /*SocketEventData*/ *);
        void ST_released(EventData *);

        BEGIN_STATE_MAP
            STATE_MAP_ENTRY(&DataConn::ST_inactive)

            STATE_MAP_ENTRY(&DataConn::ST_start_setup)
            STATE_MAP_ENTRY(&DataConn::ST_in_setup)
            STATE_MAP_ENTRY(&DataConn::ST_set_on_wait_for_setup)
            STATE_MAP_ENTRY(&DataConn::ST_check_cancel)
            STATE_MAP_ENTRY(&DataConn::ST_set_on_cancel)
            STATE_MAP_ENTRY(&DataConn::ST_setup_success)
            STATE_MAP_ENTRY(&DataConn::ST_setup_failure)

            STATE_MAP_ENTRY(&DataConn::ST_active)
            STATE_MAP_ENTRY(&DataConn::ST_idle_timeout)
            STATE_MAP_ENTRY(&DataConn::ST_in_hold)
            STATE_MAP_ENTRY(&DataConn::ST_reactivate)
            STATE_MAP_ENTRY(&DataConn::ST_deactivate)

            STATE_MAP_ENTRY(&DataConn::ST_in_trigger_release)
            STATE_MAP_ENTRY(&DataConn::ST_start_release)
            STATE_MAP_ENTRY(&DataConn::ST_in_release)
            STATE_MAP_ENTRY(&DataConn::ST_ignore_setup_req)
            STATE_MAP_ENTRY(&DataConn::ST_released)
        END_STATE_MAP

        enum TimerFlag {
            IdleTimeoutFlag     = 1,
            TriggerReleaseFlag  = 2
        };

    private:
        const DataConnProfilePtr m_profile;

    protected:
        DataConn(const DataConnProfilePtr &profile);

        virtual ~DataConn();

    public:
        BOOLEAN Setup(SocketData &sd);

        BOOLEAN Release(SocketData &sd);

        BOOLEAN Setup();

        BOOLEAN Release(BOOLEAN block = FALSE);

        DataConnProfilePtr GetProfile() const
            { return m_profile; }

        DataConnProfile::ProfileType GetProfileType() const
            { return m_profile->GetType(); }

        void ResetIdleTimer();

        BOOLEAN IsConnected() const
            { const DataConnState dcs = GetState();
              return dcs == st_active || dcs == st_in_hold; }

        BOOLEAN IsDisconnected() const
            { return !IsConnected(); }

        BOOLEAN IsInactive() const
            { return GetState() == st_inactive; }

        BOOLEAN IsInSetup() const
            { return GetState() == st_in_setup; }

        BOOLEAN IsActive() const
           { return GetState() == st_active; }

        BOOLEAN IsInHold() const
            { return GetState() == st_in_hold; }

        BOOLEAN IsInRelease() const
            { const DataConnState dcs = GetState();
              return dcs == st_in_trigger_release || dcs == st_in_release; }

        BOOLEAN IsCancelled() const;

        virtual UINT8 GetNsapi() const;

        virtual BOOLEAN GetIpAddress(IpAddr &addr) const = 0;

        const IpAddr& GetPrimaryDnsServerAddress() const
            { return m_primary_dns_server_address; }

        const IpAddr& GetSecondaryDnsServerAddress() const
            { return m_secondary_dns_server_address; }

#if defined(APOXI_COMPAT_2_2_0)

        const IpAddr& GetDnsServerAddress() const
            { return GetPrimaryDnsServerAddress(); }
#endif

#if defined(APOXI_COMPAT_1_13_0)

        DataConnManager::DataConnState GetCompatState() const;
#endif

    protected:

        DataConnState GetState() const;

        void SetPrimaryDnsServerAddress(const IpAddr& primary_dns_addr)
            { m_primary_dns_server_address = primary_dns_addr; }

        void SetSecondaryDnsServerAddress(const IpAddr& secondary_dns_addr)
            { m_secondary_dns_server_address = secondary_dns_addr; }

        void CheckTimers();

        void SetupSucceededEvent();

        void SetupFailedEvent(SocketControlMsgType error_msg);

        void ReleasedEvent();

        void BearerDisconnectedEvent(SocketControlMsgType error_msg);

        BOOLEAN WaitForSetup(SocketData &sd);

    private:
        void IdleTimeoutEvent();

    private:
        BooleanCondition m_setup_cond;
        BooleanCondition m_release_cond;

    private:
        void SetTimerFlag(TimerFlag flag)
            { m_timer_flag |= flag; }

        void ClearTimerFlag(TimerFlag flag)
            { m_timer_flag &= ~flag; }

        BOOLEAN IsTimerFlag(TimerFlag flag)
            { return (m_timer_flag & flag) != 0; }

    private:
        SystemTimer m_idle_timer;
        SystemTimer m_linger_timer;

        SystemTimer m_release_trigger_timer;

        INT m_timer_flag;

        IpAddr m_primary_dns_server_address;
        IpAddr m_secondary_dns_server_address;

        BOOLEAN m_cancel_requested;

        SocketData *m_dc_sd;

    private:
        BOOLEAN EnableIdleTimer();

        inline void DisableIdleTimer();

        BOOLEAN EnableLingerTimer();

        inline void DisableLingerTimer();

#if defined(APOXI_COMPAT_1_13_0)

        void ResetLingerTimer(UINT32 value);
#endif

        static void IdleTimeoutCallback(void *pDataConn);
        static void TriggerReleaseCallback(void *pDataConn);

    protected:
        virtual BOOLEAN DataConnIsBlocked() const
            { return FALSE; }

        BOOLEAN CheckCancelRequest(BOOLEAN internal = FALSE);

        void InvalidateSockets() const;

    protected:
        enum MessageType {
            mt_data_conn_init = 0,
            mt_data_conn_established,
            mt_data_conn_setup_failed,
            mt_data_conn_init_release,
            mt_data_conn_released,
            mt_data_conn_setup_blocked
        };

    protected:
        virtual void PostInfoMsg(MessageType type) const = 0;

        static void PostSocketControlMsg(SocketData &sd,
            SocketControlMsgType control_type);

        void PostSocketControlMsg(SocketControlMsgType control_type);

        void Init()
            { Cleanup(); }

        virtual BOOLEAN SetupContext();

        virtual BOOLEAN TeardownContext();

        virtual void DoSetup() = 0;

        virtual void DoRelease() = 0;

        virtual BOOLEAN CancelSetup() { return FALSE; }

        virtual void Cleanup();

        SocketData &GetSocketData() const
            { ASSERT_DEBUG(m_dc_sd != 0); return *m_dc_sd; }

    private:
        void SetSocketData(SocketData *sd);

        BOOLEAN IsReferenced(BOOLEAN by_listener = FALSE) const;

    protected:
        const DataConnProfile& MyProfile() const {
            return *m_profile;
        }

    private:
        SocketError m_socket_err;
        SocketControlMsgType m_ctrl_err_msg;

#if defined(APOXI_COMPAT_1_13_0)
        BOOLEAN m_forced_release;
#endif

    private:
        friend class DataConnCtrlCbs;

    protected:
        typedef ContextExecuteMsg::CallbackFn DataConnCtrlCb;
        void PostDataConnControlMsg(const DataConnCtrlCb cb);
};

#endif  // Apoxi_DataConn_hpp

