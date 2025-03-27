/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined(APOXI_RTOS_WIN32)
    #include <Kernel/Os/Win32/Win32.hpp>
#endif

#include <Kernel/Types.hpp>
#include <Kernel/Allocator.hpp>
#include <Kernel/Condition.hpp>
#include <Kernel/ExecutionContext.hpp>
#include <Kernel/Message.hpp>
#include <Kernel/MessageRouter.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Kernel/Os/MutexObtainer.hpp>
#include <Kernel/Os/SemObtainer.hpp>
#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/SubSystem.hpp>
#include <Kernel/System.hpp>
#include <Kernel/Timer.hpp>
#include <Kernel/UserDispatcher.hpp>

#include <Auxiliary/EventData.hpp>
#include <Auxiliary/IpAddr.hpp>
#include <Auxiliary/IpPortNo.hpp>
#include <Auxiliary/Macros.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/StateMachine.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/TriggerTimer.hpp>
#include <Auxiliary/WString.hpp>

#include <Adc/DataHandler.hpp>
#include <Asc/DataCallContext.hpp>
#include <Asc/DataCallControl.hpp>
#include <Asc/DataCallHdl.hpp>
#include <Asc/PdpContext.hpp>
#include <Asc/PdpContextControl.hpp>
#include <Asc/PdpContextManager.hpp>
#include <Asc/Types.hpp>
#include <Socket/CsdDataConnProfile.hpp>
#include <Socket/DataConn.hpp>
#include <Socket/DataConnManager.hpp>
#include <Socket/DataConnProfile.hpp>
#include <Socket/DataConnProfileManager.hpp>
#include <Socket/DataConnProfileStorage.hpp>
#include <Socket/DnsClient.hpp>
#include <Socket/InetSocket.hpp>
#include <Socket/PersistDataConnProfile.hpp>
#include <Socket/PppDataConn.hpp>
#include <Socket/PsdDataConnProfile.hpp>
#include <Socket/SerDataConnProfile.hpp>
#include <Socket/SocketData.hpp>
#include <Socket/SocketRxThread.hpp>
#include <Socket/SocketSubSystem.hpp>
#include <Socket/SocketTypes.hpp>
#include <Socket/Sys/SysSocket.hpp>
#include <Socket/Sys/SysSocketBase.hpp>
#include <Socket/TcpSocketBase.hpp>
#include <Socket/UdpSocket.hpp>

