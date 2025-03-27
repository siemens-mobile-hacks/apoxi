/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketSubSystem_hpp)
#define Apoxi_SocketSubSystem_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Kernel/SubSystem.hpp>
#include <Kernel/ServiceThread.hpp>
#include <Socket/SocketData.hpp>
#include <Socket/SocketRxThread.hpp>

class SocketSubSystem : public SubSystem
{
    friend class InetSocket;
    friend class SocketRxThread;
    friend class SocketDataLock;
    friend class TcpServerSocket;
    friend class SysSocket;
    friend class DataConn;
    friend class Os;

    public:
        SocketSubSystem();

        static SocketSubSystem* GetInstance() { return m_instance; }

        virtual const WCHAR* GetName() const { return L"INET"; }
        virtual void OnPowerUp();
        virtual void OnPowerDown();

        virtual BootSequenceState InvokeAt() const;

    private:
        static SocketSubSystem *m_instance;
        static SocketRxThread m_rx;
        static ServiceThread m_dc_srv_thread;
        static Mutex m_mutex_socket;
        static SocketData m_sd[c_max_inet_socket_count];

        static SocketData& GetSocketData(UINT idx) {
            ASSERT(idx < c_max_inet_socket_count);
            return m_sd[idx];
        }

        static SocketData* GetFreeSocketDataEntry();
};

#endif  // Apoxi_SocketSubSystem_hpp


