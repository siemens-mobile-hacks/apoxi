/* ------------------------------------------------------------------------
   Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_CallControlDispatcher_hpp)
#define Asc_CallControlDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>

#include <Asc/StackMsgDispatcher.hpp>

class CallControlDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

 public:
    CallControlDispatcher();

    virtual ~CallControlDispatcher();

 protected:

    BOOLEAN OnCallControlSetupInd(const StackMsgArgument &arg);

 private:
    static const StackMsgArgMap<CallControlDispatcher> m_arg_map[];

    StackMsgArgMapContainer<CallControlDispatcher> m_arg_map_container;
};

#endif // Asc_CallControlDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS

