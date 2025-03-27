/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(AddOns_VoiceRecognition_VrHostController_hpp)
#define AddOns_VoiceRecognition_VrHostController_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <stack/stack.h>
#include <stack/extensions.h>
#include <Kernel/Types.hpp>

class ByteBuffer;

class VrHostController  {
 public:


    static void VrInit();

    static void VrSendEngineParams(void* params);
    
    static void VrSendTemplate(UINT32 id, const UINT16* templ, BOOLEAN trained);

    static void VrStartRecognition(const UINT16* templates);

    static void VrStartRecording();

    static void VrSetRepeatedMode();

    static void VrQuitRepeatedMode();

    static void VrStopRecognition();

    static void VrAbort();

    static void VrStartTraining();

    static void VrCreateG2ATemplate(const WString& text);

    static void VrFinishTraining();
    
    static void VrRequestProperties();
        
 private:    
/*typedef void (*VrCallbackFunc) (SDL_Pid ,         // sender ID
                ax_vr_even_enum ,   // Signal from VR_host to APOXI 
                ubyte ,         // return code (not used)
                UINT32 ,        // parameter 1
                                UINT32 ,        // parameter 2
                                UINT32 ,        // parameter 3
                                UINT32 ,        // parameter 4
                                UINT8 * ,       // pointer to data
                                UINT8 * );      // pointer to PCM data*/


    static void VrHostCallback(SDL_Pid sdl_pid, UINT16 event, char rc, 
                               UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4, 
                               UINT8* ptr1, UINT8* ptr2);

    
    static SDL_Pid m_pid;
    static UINT16* m_ptemplate_ids;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // AddOns_VoiceRecognition_VrHostController_hpp


