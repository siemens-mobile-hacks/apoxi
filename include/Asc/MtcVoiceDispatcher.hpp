/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS 

#if !defined(Asc_MtcVoiceDispatcher_hpp)
#define Asc_MtcVoiceDispatcher_hpp

#include <Asc/StackMsgDispatcher.hpp>

class MtcVoiceDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        
        MtcVoiceDispatcher();
        virtual ~MtcVoiceDispatcher();

        BOOLEAN OnMtcConfInd(const StackMsgArgument &arg);


        BOOLEAN OnMtcSetupInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<MtcVoiceDispatcher> m_arg_map[];
        StackMsgArgMapContainer<MtcVoiceDispatcher> m_arg_map_container;
};

#endif // Asc_MtcVoiceDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS 

