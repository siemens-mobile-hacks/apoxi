/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_MmCallDispatcher_hpp)
#define Apoxi_MmCallDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>
#include <Apc/StackMsgArgument.hpp>
#include <Asc/StackMsgDispatcher.hpp>

class MmCallHandler;

class MmCallDispatcher : public StackMsgDispatcher {
    
    typedef StackMsgDispatcher Base;
    public:
        
        MmCallDispatcher(MmCallHandler* call_handler);

        virtual ~MmCallDispatcher();
        
    protected:

        BOOLEAN OnTerminalEvent(const StackMsgArgument &arg);
    
    private:
        MmCallHandler* m_call_handler;

        static const StackMsgArgMap<MmCallDispatcher> m_arg_map[];

        StackMsgArgMapContainer<MmCallDispatcher> m_arg_map_container;

};

#endif // Apoxi_MmCallDispatcher_hpp


