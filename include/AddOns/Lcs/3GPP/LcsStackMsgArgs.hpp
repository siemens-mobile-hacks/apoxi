/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "APOXI_1.6.7-PRE\src\Apoxi\AddOns\Lcs\3GPP\LcsArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_3GPP_LcsStackMsgArgs_hpp)
#define AddOns_Lcs_3GPP_LcsStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/Lcs/3GPP/LcsArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class LcsStackMsgArgsDestroyTableNode
    ====================================================================== */

class LcsStackMsgArgsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static LcsStackMsgArgsDestroyTableNode* GetInstance();
        
    private:
        LcsStackMsgArgsDestroyTableNode();
        
        
        static LcsStackMsgArgsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // AddOns_Lcs_3GPP_LcsStackMsgArgs_hpp

