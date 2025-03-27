/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS 

#if !defined(Asc_BaseHandler_hpp)
#define Asc_BaseHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/HandlerId.hpp>
#include <Asc/HandlerList.hpp>


class StackMsgDispatcher;
/*  ========================================================================
    BaseHandler
    ======================================================================== */
class BaseHandler {
    friend class HandlerListEntry;
    public:
        BaseHandler(StackMsgDispatcher *dispatcher = 0);
        virtual ~BaseHandler();
        
        virtual HandlerId GetHandlerId() const = 0;

    protected:
        virtual BOOLEAN Init(MainHandler *main_handler);

    private:
        BOOLEAN m_initialized;
        StackMsgDispatcher *m_dispatcher;       // main dispatcher for retrieving asynchronous messages

        BOOLEAN Cleanup();
};


/*  ------------------------------------------------------------------------
    CastHandler
    ------------------------------------------------------------------------ */
template<class DestHandler> inline void CastHandler(DestHandler &p_handler_to, const BaseHandler *p_handler_from)
{
    ASSERT (p_handler_from != 0);

    // reset destination handler
    p_handler_to = 0;

    ASSERT(p_handler_from->GetHandlerId() == DestHandler()->ID);
    p_handler_to = (DestHandler) p_handler_from;
}// CastHandler




#endif // Asc_BaseHandler_hpp

#endif //DOXYGEN_SHOULD_SKIP_THIS 


