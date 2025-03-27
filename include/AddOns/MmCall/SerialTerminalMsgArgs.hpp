/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "swap\views\hartmanw_mpeu-host-bsy_sv\lnz_apoxi\Apoxi\AddOns\MmCall\SerialTerminalArg.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(AddOns_MmCall_SerialTerminalMsgArgs_hpp)
#define AddOns_MmCall_SerialTerminalMsgArgs_hpp
#include <Apc/StackMsgArgument.hpp>
#include <AddOns/MmCall/SerialTerminalArg.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class SerialTerminalMsgArgsDestroyTableNode
    ====================================================================== */
class SerialTerminalMsgArgsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static SerialTerminalMsgArgsDestroyTableNode* GetInstance();
        
    private:
        SerialTerminalMsgArgsDestroyTableNode();
        
        
        static SerialTerminalMsgArgsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };
#endif // AddOns_MmCall_SerialTerminalMsgArgs_hpp

