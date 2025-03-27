/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\Common\LcsCommonArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_Common_LcsCommonStackMsgArgs_hpp)
#define AddOns_Lcs_Common_LcsCommonStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/Lcs/Common/LcsCommonArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class LcsCommonStackMsgArgsDestroyTableNode
    ====================================================================== */

class LcsCommonStackMsgArgsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static LcsCommonStackMsgArgsDestroyTableNode* GetInstance();
        
    private:
        LcsCommonStackMsgArgsDestroyTableNode();
        
        
        static LcsCommonStackMsgArgsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // AddOns_Lcs_Common_LcsCommonStackMsgArgs_hpp

