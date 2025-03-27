/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_PdpContextManager_hpp)
#define Asc_PdpContextManager_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/Condition.hpp>
#include <Auxiliary/Vector.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <Asc/PdpContext.hpp>

class PdpContextManagerControl;
class PdpContextControl;

#if defined(APOXI_EXTERNAL_PCH_CONTROL_SUPPORT)

class ExtPsdContextListenerImpl_SerialTerminalListener;
    
#endif // APOXI_EXTERNAL_PCH_CONTROL_SUPPORT

#define LOCK_PDP_CONTEXT_HANDLER PdpContextManager::GetSemaphore().Obtain();
#define UNLOCK_PDP_CONTEXT_HANDLER PdpContextManager::GetSemaphore().Release();

class PdpContextManager {
    friend class PdpContext;
    friend class PdpContextSignalProcessor;

    public:
        enum {
            ApoxiDefineScopeEntity(c_max_cid_array_len, PdpContextManager)
        };

        enum State {
            Idle,
            AttachPending,
            DetachPending,
            ResetCountersPending,
            ReadCountersPending,
            PrimaryDefinePending,
            PrimaryUndefinePending,
            SecondaryDefinePending,
            SecondaryUndefinePending,
            AuthenticatePending,
            SetQualityOfServicePending,
            SetMinimumQualityOfServicePending,
            ActivatePending,
            NetworkRequestPending,
            DeactivatePending,
            ConnectPending,
            SetCounterPending,
            ReadCounterPending,
            SetPacketFilterPending,
            UnsetPacketFilterPending,
            SetAutomaticDnsServerNegotiationPending,
            ReadNegotiatedDnsServerAddressPending,
        };

        enum ExternalContextState {            
            c_ext_ctx_state_invalid = 0,            
            c_ext_ctx_state_connecting = 1,
            c_ext_ctx_state_connected = 2,
            c_ext_ctx_state_disconnecting = 3,
            c_ext_ctx_state_disconnected = 4
        };

        struct DataCounters {
            UINT32 m_session_sent;
            UINT32 m_session_received;
            UINT32 m_total_sent;
            UINT32 m_total_received;

            void Reset() { m_session_sent = m_session_received = m_total_sent = m_total_received = 0; }
        };

        class AttachStatus {

            public:

                enum State {
                    ApoxiDefineScopeEntity(StateAccepted, PdpContextManager_AttachStatus),
                    ApoxiDefineScopeEntity(StateRejected, PdpContextManager_AttachStatus),
                    ApoxiDefineScopeEntity(StateFiveTimeT3310Expiry, PdpContextManager_AttachStatus),
                    ApoxiDefineScopeEntity(StateUserInteruption, PdpContextManager_AttachStatus),
                    ApoxiDefineScopeEntity(StateUnknownCause, PdpContextManager_AttachStatus),
                };

                AttachStatus(State state = StateUnknownCause,
                             UINT8 ready_timer = 0,
                             UINT8 reject_cause = 0,
                             INT t3310_expiries = 0);

                ~AttachStatus();

                void Reset();

                State GetState() const { return (m_state); }
                void SetState(State state) { m_state = state; }

                UINT8 GetReadyTimer() const { return (m_ready_timer); }
                void SetReadyTimer(UINT8 ready_timer) { m_ready_timer = ready_timer; }

                UINT8 GetRejectCause() const { return (m_reject_cause); }
                void SetRejectCause(UINT8 reject_cause) { m_reject_cause = reject_cause; }

                INT GetT3310Expiries() const { return m_t3310_expiries; }
                void SetT3310Expiries(INT t3310_expiries) { m_t3310_expiries = t3310_expiries; }

            private:

                State m_state;
                UINT8 m_ready_timer;
                UINT8 m_reject_cause;
                INT m_t3310_expiries;
        };

        static void Init();

        static BOOLEAN AttachManagerControl(
            PdpContextManagerControl *context_manager_control = 0);

        static PdpContextControl* GetContextControl(PdpContext *context) {
            ASSERT_DEBUG_INFO(s_pdp_contexts.Exists(context),
                L"\nInvalid PDP context!\n");
            return s_pdp_contexts[context]->m_pdp_context_control;
        }

        static PdpContextManagerControl* GetContextManagerControl() { return (m_context_manager_control); }

        static void Register();

        static void Attach();

        static void Detach();

        static BOOLEAN IsAttached() { return (m_attached); }

        static const AttachStatus& GetAttachStatus() { return m_attach_status; }

        static PdpContext* FindContext(PdpContext::Id id);

        static PdpContext* CreateContext(PdpContextControl &context_control,
            PdpContext* primary_context = 0);

        static State GetState() { return (m_state); }

        static BOOLEAN GetDataCounters(UINT32 &sent, UINT32 &received);

        static BOOLEAN ResetDataCounters();

        static const DataCounters& GetLastStackDataCounters() { return (m_stack_data_counters); }

        static void GetLastNegotiatedDnsServerAddresses(IpAddr &primary_dns, IpAddr &secondary_dns)
            { primary_dns = m_primary_dns_server; secondary_dns = m_secondary_dns_server; }

#if defined(APOXI_EXTERNAL_PCH_CONTROL_SUPPORT)

        static void TerminateExternalContext();
        
#endif  // APOXI_EXTERNAL_PCH_CONTROL_SUPPORT

    protected:
        static Semaphore& GetSemaphore() { return m_semaphore; }

    private:
        static BOOLEAN m_initialized;
        static Mutex m_mutex;
        static PdpContextManagerControl *m_context_manager_control;

        static State m_state;
        static PdpContext *m_pending_context;
        static BOOLEAN m_attached;
        static AttachStatus m_attach_status;

        static PdpContext::ErrorCause m_last_error;

        static IpAddr m_primary_dns_server, m_secondary_dns_server;

        static UINT32 m_received_data_counter, m_sent_data_counter;

        static DataCounters m_stack_data_counters;

        static BooleanCondition m_data_counters_condition;

        static PdpContext* GetPendingContext(State state);

        static State GetPendingState();

        static BOOLEAN SetPendingContext(State state, PdpContext *pending_context);

        static void SetAttached(BOOLEAN attached);

        static void SetAttachStatus(const AttachStatus &attach_status);

        static void ResetState();

        static BOOLEAN DeleteContext(PdpContext *context);

        static void Reset();

    private:
        struct PdpContextInfo {
            PdpContext::Id m_id;
            PdpContextControl* m_pdp_context_control;

            PdpContextInfo() : m_id(-1), m_pdp_context_control(0) {}

            PdpContextInfo(PdpContext::Id id,
                PdpContextControl* pdp_context_control) :
                    m_id(id),
                    m_pdp_context_control(pdp_context_control) {}
        };

        static Vector<PdpContextInfo> s_pdp_context_infos;

        typedef SimpleMap<PdpContext*, PdpContextInfo*> PdpContextInfoMap;

        static PdpContextInfoMap s_pdp_contexts;

        static PdpContextInfo* FindUnusedContext();

        static Semaphore m_semaphore;
        
#if defined(APOXI_EXTERNAL_PCH_CONTROL_SUPPORT)

    private:
        static ExtPsdContextListenerImpl_SerialTerminalListener* m_extpsdcontext_listener;

#endif  // APOXI_EXTERNAL_PCH_CONTROL_SUPPORT
};

#endif  // Asc_PdpContextManager_hpp

