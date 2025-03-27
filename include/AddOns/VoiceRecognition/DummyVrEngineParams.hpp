/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(AddOns_VoiceRecognition_DummyVrEngineParams_hpp)
#define AddOns_VoiceRecognition_DummyVrEngineParams_hpp

#include <stack/stack.h>
#include <stack/extensions.h>

#include "VrHandler.hpp"
#include "VrEngineParams.hpp"

class DummyVrEngineParams : public VrEngineParams
{
    public:
        DummyVrEngineParams();
        
        virtual BOOLEAN SetMaxRecognitionTime(UINT16 time);
        
        virtual BOOLEAN SetMaxSilenceTime(UINT16 time);
        
        virtual BOOLEAN SetRecognitionMode(VrHandler::VrRecognitionMode mode);
        
        virtual void* GetNativeParams() { return 0; };
        
    private:
};

#endif // AddOns_VoiceRecognition_DummyVrEngineParams_hpp

