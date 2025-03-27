/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_RedialDispatcher_hpp)
#define Asc_RedialDispatcher_hpp

#include <Asc/StackMsgDispatcher.hpp>

class StackMsgActiveWaitDispatcher;

class RedialDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        RedialDispatcher();
        
        virtual ~RedialDispatcher();

    protected:
        BOOLEAN OnRedialInd(const StackMsgArgument &arg);
        

        BOOLEAN OnRedialStopInd(const StackMsgArgument &arg);


        BOOLEAN OnRedialSetupInd(const StackMsgArgument &arg);


    private:
        static const StackMsgArgMap<RedialDispatcher> m_arg_map[];
        StackMsgArgMapContainer<RedialDispatcher> m_arg_map_container;
        
};

#endif // Asc_RedialDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


