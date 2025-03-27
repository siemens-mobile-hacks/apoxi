/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketHandler_hpp)
#define Apoxi_SocketHandler_hpp

#include <Kernel/UserDispatcher.hpp>

class SocketHandler : private UserDispatcher
{
    public:
        SocketHandler();
        virtual ~SocketHandler();

        void Init();

        void Release();
        
    private:
        virtual BOOLEAN OnMessage(const Message &msg);
};

#endif  // Apoxi_SocketHandler_hpp


