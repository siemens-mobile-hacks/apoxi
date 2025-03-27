/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UserDispatcher_hpp)
#define Apoxi_UserDispatcher_hpp

#include <Kernel/Dispatcher.hpp>

class UserDispatcher : public Dispatcher {
    typedef Dispatcher Base;

    public:
        UserDispatcher();
        virtual ~UserDispatcher();

        void SetNext(UserDispatcher* next) { m_next = next; }

        UserDispatcher* GetNext() const { return m_next; }

    protected:
        virtual void RegisterMessages() const;

        virtual void UnregisterMessages() const;

    private:
        friend class ExecutionContext;

        UserDispatcher* m_next;
};

#endif  // Apoxi_UserDispatcher_hpp


