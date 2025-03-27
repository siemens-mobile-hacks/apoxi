/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(AddOns_VoiceRecognition_VrEngineParams_hpp)
#define AddOns_VoiceRecognition_VrEngineParams_hpp

#include "VrHandler.hpp"

class VrEngineParams
{
    public:
        virtual BOOLEAN SetMaxRecognitionTime(UINT16 time) = 0;
        
        virtual BOOLEAN SetMaxSilenceTime(UINT16 time) = 0;
        
        virtual BOOLEAN SetRecognitionMode(VrHandler::VrRecognitionMode mode) = 0;
        
        virtual void* GetNativeParams() = 0;
        
};

#endif // AddOns_VoiceRecognition_VrEngineParams_hpp

