/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ServiceThreadExtn_hpp)
#define ServiceThreadExtn_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/
#include <Kernel/ServiceThread.hpp>
#include <Socket/SocketHandler.hpp>
#include "EmApoxiInterface.hpp"


class ExtndServiceThreadForNetwork: public ServiceThread
{

public:
    static ExtndServiceThreadForNetwork& GetInstance();
    void OnPowerUp();
    void OnPowerDown();
    BOOLEAN OnMessage(const Message &msg);




    
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // ServiceThreadExtn_hpp

