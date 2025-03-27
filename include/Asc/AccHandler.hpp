/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AccHandler_hpp)
#define Asc_AccHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/AccDispatcher.hpp>

class AccHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = AccHandlerId };

        AccHandler();
        virtual ~AccHandler();
        virtual HandlerId GetHandlerId() const;

    private:
        AccDispatcher m_acc_dispatcher; // main dispatcher for retrieving asynchronous messages
};

#endif // Asc_AccHandler_hpp


