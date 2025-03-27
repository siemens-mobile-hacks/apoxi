/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MtcVoiceHandler_hpp)
#define Asc_MtcVoiceHandler_hpp

#include <Asc/BaseHandler.hpp>
#include <Asc/MtcVoiceDispatcher.hpp>

class MainHandler;
class CallHandlingData;

enum CallApiRc;

class MtcVoiceHandler : public BaseHandler {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef BaseHandler Base;           // typedef if base class's name changes
    public:
        enum { ID = MtcVoiceHandlerId };

        MtcVoiceHandler();
        virtual ~MtcVoiceHandler();
        
        virtual HandlerId GetHandlerId() const;

        CallApiRc Accept(CallIndex call_index) const;   

        CallApiRc SendAlertMessage(CallIndex call_index) const;
        
    private:
        MtcVoiceDispatcher  m_mtc_voice_disp;

};
#endif // DOXYGEN_SHOULD_SKIP_THIS 

#endif // Asc_MtcVoiceHandler_hpp


