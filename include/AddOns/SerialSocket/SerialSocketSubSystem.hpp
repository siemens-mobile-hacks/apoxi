/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SerialSocketSubSystem_hpp)
#define Apoxi_SerialSocketSubSystem_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Kernel/SubSystem.hpp>
#include "SerialSocketData.hpp"
#include "SerialSocketThread.hpp"

class SerialSocketSubSystem : public SubSystem
{
    typedef SubSystem Base;
    friend class SerialSocket;
    friend class SerialSocketThread;
    friend class SerialSocketDataLock;
    friend class SerialClientSocket;
    friend class SerialServerSocket;
    friend class Os;

    public:
        SerialSocketSubSystem();

        static SerialSocketSubSystem* GetInstance() { return m_instance; }

        virtual const WCHAR* GetName() const { return L"SERIALSOCK"; }
        virtual void OnPowerUp();

        virtual BootSequenceState InvokeAt() const;

    private:
        static SerialSocketSubSystem *m_instance;
        static SerialSocketThread m_thread;
        static Mutex m_mutex_socket;
        static SerialSocketData m_sd[c_max_inet_socket_count];

        static SerialSocketData& GetSerialSocketData(UINT idx) {
            ASSERT(idx < c_max_inet_socket_count);
            return m_sd[idx];
        }

        static SerialSocketData* GetFreeSerialSocketDataEntry();
};

#endif  // Apoxi_SocketSubSystem_hpp


