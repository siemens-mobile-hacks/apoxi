/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS 

#if !defined(Asc_MtcVoiceAcceptDispatcher_hpp)
#define Asc_MtcVoiceAcceptDispatcher_hpp

#include <Asc/TipdBasedActiveWaitDispatcher.hpp>

//lint -esym(1712,MtcVoiceAcceptDispatcher) 
class MtcVoiceAcceptDispatcher : public TipdBasedActiveWaitDispatcher {
    public:
        typedef TipdBasedActiveWaitDispatcher Base;

        explicit MtcVoiceAcceptDispatcher(Tipd tipd);
        virtual ~MtcVoiceAcceptDispatcher();

        BOOLEAN OnMtcSetupCompl(const StackMsgArgument &arg);

        BOOLEAN OnMtcAcceptRej(const StackMsgArgument &arg) ;

        BOOLEAN IsRejected(){return m_rejected;}

    private:
        static const StackMsgArgMap<MtcVoiceAcceptDispatcher> m_arg_map[];
        StackMsgArgMapContainer<MtcVoiceAcceptDispatcher> m_arg_map_container;

//      Tipd                m_tipd;
        BOOLEAN             m_disconnected;
        BOOLEAN             m_rejected;
};

#endif  // Asc_MtcVoiceAcceptDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS 


