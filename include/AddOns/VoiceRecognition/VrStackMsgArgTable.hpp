/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "hauth_voicerec_dv\lnz_apoxi\Apoxi\AddOns\VoiceRecognition\VrArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_VoiceRecognition_VrStackMsgArgTable_hpp)
#define AddOns_VoiceRecognition_VrStackMsgArgTable_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/VoiceRecognition/VrStackMsgArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class VrStackMsgArgTableDestroyTableNode
    ====================================================================== */

class VrStackMsgArgTableDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static VrStackMsgArgTableDestroyTableNode* GetInstance();
        
    private:
        VrStackMsgArgTableDestroyTableNode();
        
        
        static VrStackMsgArgTableDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // AddOns_VoiceRecognition_VrStackMsgArgTable_hpp

