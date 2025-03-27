/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiServiceThread_hpp)
#define EmApoxiServiceThread_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/ServiceThread.hpp>

#include "EmServThreadMsg.hpp"

class EmApoxiServiceThread  : public ServiceThread {

    typedef ServiceThread Base;
public:
    static EmApoxiServiceThread& GetInstance();
    void OnPowerUp();
    void OnPowerDown();
    BOOLEAN OnMessage(const Message &msg);

    void PostSelfMessage (EmServThreadMsg&);

};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif //EmApoxiServiceThread_hpp

