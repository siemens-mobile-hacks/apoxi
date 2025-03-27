/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(AddOns_VoiceRecognition_TelecaVrEngineParams_hpp)
#define AddOns_VoiceRecognition_TelecaVrEngineParams_hpp

#include <stack/stack.h>
#include <stack/extensions.h>

#include "VrHandler.hpp"
#include "VrEngineParams.hpp"

class TelecaVrEngineParams : public VrEngineParams
{
    public:
        TelecaVrEngineParams();
        
        virtual BOOLEAN SetMaxRecognitionTime(UINT16 time);
        
        virtual BOOLEAN SetMaxSilenceTime(UINT16 time);
        
        virtual BOOLEAN SetRecognitionMode(VrHandler::VrRecognitionMode mode);
        
        virtual void* GetNativeParams() { return (void*)&m_params; };
        
    private:
        ParamData   m_params;
};

#endif // AddOns_VoiceRecognition_TelecaVrEngineParams_hpp

