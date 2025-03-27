/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketData_hpp)
#define Apoxi_SocketData_hpp

#include <Socket/Sys/SysSocket.hpp>
#include <Socket/DataConnProfile.hpp>
#include <Kernel/Condition.hpp>

class InetSocket;
class ExecutionContext;

class SocketData : public SysSocket
{
    typedef SysSocket Base;

    friend class InetSocket;
    friend class UdpSocket;
    friend class TcpSocket;
    friend class TcpServerSocket;
    friend class SocketSubSystem;
    friend class DataConn;
    friend class SerialSocketData;

    public:
        InetSocket* GetAttachedSocket() const { return m_socket; }
        ExecutionContext* GetContext() const { return m_context; }

        BOOLEAN IsInUse() const { return m_socket != 0; }

        DataConnProfileId GetDataConnProfileId() const { return m_daco_id; }
        void SetDataConnProfileId(DataConnProfileId id) { m_daco_id = id; }

        SocketError GetError() const { return m_err; }
        BOOLEAN SetError(SocketError err) {
            m_err = err;
            return err == c_socket_no_error;
        }

        BOOLEAN SetError(BOOLEAN ok) {
            m_err = ok ? c_socket_no_error : GetSysError();
            return ok;
        }

        BOOLEAN SetupDataConn();

        BOOLEAN ReleaseDataConn();

        void ResetDataConnIdleTimer() const;

        DataConn& GetDataConn() const;

        BOOLEAN Listen(INT backlog);

        BOOLEAN Close();

    private:
        class SdCond : public BooleanCondition {
            typedef BooleanCondition Base;
            public:
                SdCond() : m_in_use(FALSE) { }
                void Init() { Base::Init(); m_in_use = TRUE; }
                BOOLEAN IsInUse() const { return m_in_use; }
                void SetUnused() { m_in_use = FALSE; }
            private:
                BOOLEAN m_in_use;
        };

        DataConnProfileId m_active_daco_id;
        DataConnProfileId m_daco_id;
        SocketError m_err;
        InetSocket *m_socket;
        ExecutionContext *m_context;
        BOOLEAN m_is_listening;

        SdCond m_recv_cond;
        SdCond m_send_cond;

        SocketData();

        void Attach(InetSocket *s);
        void Detach(InetSocket *s);
        void HandOver(InetSocket &to_socket);

        BOOLEAN IsDaCoActive() const
            { return m_active_daco_id != c_invalid_data_conn_profile_id; }

        DataConnProfileId GetActiveDaCoProfileId() const
            { return m_active_daco_id; }
        void SetActiveDaCoProfileId(DataConnProfileId id)
            { m_active_daco_id = id; }

        BOOLEAN IsWaitingForDataRecv() const { return m_recv_cond.IsInUse(); }
        BOOLEAN WaitForDataRecv();
        void UnblockDataRecv();

        void OnDataRecv() {
            if (m_recv_cond.IsInUse()) {
                m_recv_cond.SetTrue();
            }
        }
        
        BOOLEAN IsWaitingForDataSent() const { return m_send_cond.IsInUse(); }
        BOOLEAN WaitForDataSent();
        void UnblockDataSend();

        void OnDataSent() {
            if (m_send_cond.IsInUse()) {
                m_send_cond.SetTrue();
            }
        }

};

#endif  // Apoxi_SocketData_hpp

