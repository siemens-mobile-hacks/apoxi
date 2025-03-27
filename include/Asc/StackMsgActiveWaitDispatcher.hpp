/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_StackMsgActiveWaitDispatcher_hpp)
#define Asc_StackMsgActiveWaitDispatcher_hpp

#include <Kernel/ActiveWaitDispatcher.hpp>
#include <Kernel/MessageMap.hpp>

class AbstractStackMsgArgMapContainer;

/*  ========================================================================
    StackMsgActiveWaitDispatcher
    ======================================================================== */
class StackMsgActiveWaitDispatcher : public ActiveWaitDispatcher {
    typedef ActiveWaitDispatcher Base;
    public:
        StackMsgActiveWaitDispatcher(const AbstractStackMsgArgMapContainer *arg_map_container = 0);
        virtual ~StackMsgActiveWaitDispatcher() {}

        virtual void Reset();

        virtual BOOLEAN IsAborted() { return m_aborted; }
        

        void Abort() { m_aborted = TRUE; Done(); }

    protected:
        void Init(const AbstractStackMsgArgMapContainer *arg_map_container) { m_arg_map_container = arg_map_container; }

    private:
        static const MessageMap<StackMsgActiveWaitDispatcher> m_msg_map[];
        MessageMapContainer<StackMsgActiveWaitDispatcher> m_msg_map_container;

        const AbstractStackMsgArgMapContainer *m_arg_map_container;

        BOOLEAN m_aborted;

        BOOLEAN OnStackMsg(const Message &msg);
};

#endif // Asc_StackMsgActiveWaitDispatcher_hpp


