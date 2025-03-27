/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketDataLock_hpp)
#define Apoxi_SocketDataLock_hpp

#include <Socket/SocketSubSystem.hpp>
#include <Kernel/Os/MutexObtainer.hpp>

class SocketDataLock : public MutexObtainer
{
    public:
        SocketDataLock() : MutexObtainer(&SocketSubSystem::m_mutex_socket) 
            {}
};

#endif  // Apoxi_SocketDataLock_hpp


