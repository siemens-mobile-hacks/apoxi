/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\StandAlone\SaArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_StandAlone_SaStackMsgArgs_hpp)
#define AddOns_Lcs_StandAlone_SaStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/Lcs/StandAlone/SaArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SaStackMsgArgsDestroyTableNode
    ====================================================================== */

class SaStackMsgArgsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static SaStackMsgArgsDestroyTableNode* GetInstance();
        
    private:
        SaStackMsgArgsDestroyTableNode();
        
        
        static SaStackMsgArgsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // AddOns_Lcs_StandAlone_SaStackMsgArgs_hpp

