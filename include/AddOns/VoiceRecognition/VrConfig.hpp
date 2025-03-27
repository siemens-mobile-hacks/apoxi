/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(AddOns_VoiceRecognition_VrConfig_hpp)
#define AddOns_VoiceRecognition_VrConfig_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <stack/stack.h>
#include <stack/extensions.h>
#include <Kernel/Types.hpp>

class VrEngineParams;

class VrConfig  {

 public:
    static VrEngineParams* GetVrEngineParams();
    static WString GetStoragePath();
    
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // AddOns_VoiceRecognition_VrConfig_hpp


