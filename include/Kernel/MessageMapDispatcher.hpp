/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MessageMapDispatcher_hpp)
#define Apoxi_MessageMapDispatcher_hpp

#include <Kernel/UserDispatcher.hpp>

class AbstractMessageMapContainer;

class MessageMapDispatcher : public UserDispatcher {
    typedef UserDispatcher Base;

    public:
        MessageMapDispatcher(const AbstractMessageMapContainer *msg_map_container = 0);

        virtual ~MessageMapDispatcher();

        void Init(const AbstractMessageMapContainer *msg_map_container) { m_msg_map_container = msg_map_container; }

    protected:
        virtual void RegisterMessages() const;

        virtual void UnregisterMessages() const;

        virtual BOOLEAN OnMessage(const Message& msg);

    private:
        const AbstractMessageMapContainer *m_msg_map_container;
};

#endif  // Apoxi_MessageMapDispatcher_hpp


