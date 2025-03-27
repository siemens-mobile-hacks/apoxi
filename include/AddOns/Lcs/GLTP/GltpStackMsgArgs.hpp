/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\GLTP\GltpArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_GLTP_GltpStackMsgArgs_hpp)
#define AddOns_Lcs_GLTP_GltpStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/Lcs/GLTP/GltpArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class GltpStackMsgArgsDestroyTableNode
    ====================================================================== */

class GltpStackMsgArgsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static GltpStackMsgArgsDestroyTableNode* GetInstance();
        
    private:
        GltpStackMsgArgsDestroyTableNode();
        
        
        static GltpStackMsgArgsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // AddOns_Lcs_GLTP_GltpStackMsgArgs_hpp

