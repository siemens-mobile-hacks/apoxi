/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_HandlerData_hpp)
#define Asc_HandlerData_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>

#include <Asc/HandlerId.hpp>

class MainHandler;
class BaseHandler;
/*  ========================================================================
    HandlerData
    ======================================================================== */
struct HandlerData {
    HandlerId m_id;
    BaseHandler* (*CreateHandler)();
    BOOLEAN m_is_exclusive;
    MainHandler *m_locked_by;

    HandlerId Id() const { return (m_id); } 
    BOOLEAN IsExclusive() const { return (m_is_exclusive); } 

    BOOLEAN Lock(MainHandler *main_handler);
    BOOLEAN Unlock(MainHandler *main_handler);
    BOOLEAN IsLocked() const;
};

#endif  // Asc_HandlerData_hpp


