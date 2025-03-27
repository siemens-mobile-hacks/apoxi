/*  ------------------------------------------------------------------------
  Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
  ------------------------------------------------------------------------
  This document contains proprietary information belonging to COMNEON.
  Passing on and copying of this document, use and communication of its
  contents is not permitted without prior written authorisation.
  ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(AddOns_VoiceRecognition_VrWaitDispatcher_hpp)
#define AddOns_VoiceRecognition_VrWaitDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/* ========================================================================
   VrWaitDispatcher
   ======================================================================== */
class VrWaitDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
 public:
    VrWaitDispatcher();
    virtual ~VrWaitDispatcher();
    
    virtual void Reset();
    BOOLEAN IsTimedOut() { return m_timed_out; }
    
        
    const StackMsgArgument& GetLastArgument() { return m_last_arg; }

 protected:
    BOOLEAN OnVrResultReceived(const StackMsgArgument &arg);
    BOOLEAN OnVrPropertyResultInd(const StackMsgArgument &arg);

 private:
    StackMsgArgument m_last_arg;
    static const StackMsgArgMap<VrWaitDispatcher> m_arg_map[];
    
    StackMsgArgMapContainer<VrWaitDispatcher> m_arg_map_container;
    BOOLEAN m_timed_out;
};

#endif  // AddOns_VoiceRecognition_VrWaitDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS

