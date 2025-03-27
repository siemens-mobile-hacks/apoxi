/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Dispatcher_hpp)
#define Apoxi_Dispatcher_hpp

#include <Kernel/Types.hpp>

class Message;

class Dispatcher {
    public:
        Dispatcher();

        virtual ~Dispatcher();

        void SendSelf(const Message& msg) {
            RouteMessage(msg);
        }

    protected:
        virtual BOOLEAN RouteMessage(const Message& msg);

        virtual BOOLEAN OnMessage(const Message& msg) = 0;

    private:
        Dispatcher(const Dispatcher& dispatcher);

        Dispatcher& operator=(const Dispatcher& dispatcher);
};

#endif  // Apoxi_Dispatcher_hpp


