/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_CallControlHandler_hpp)
#define Asc_CallControlHandler_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Asc/BaseHandler.hpp>
#include <Asc/CallControlDispatcher.hpp>

class CallControlHandler : public BaseHandler {
    typedef BaseHandler Base;
 public:
    enum { ID = CallControlHandlerId }; 
        
    CallControlHandler();
    virtual ~CallControlHandler();
    virtual HandlerId GetHandlerId() const;
        
 private:    
    CallControlDispatcher m_cc_dispatcher;

};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // Asc_CallControlHandler_hpp


