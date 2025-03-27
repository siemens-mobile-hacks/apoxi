/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Bluetooth\AVRCP\BtAvrcpNotificationMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Bluetooth_BtAvrcpMessageArguments_hpp)
#define Bluetooth_BtAvrcpMessageArguments_hpp
#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/AVRCP/BtAvrcpNotificationMessageArgument.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class BtAvrcpMessageArgumentsDestroyTableNode
    ====================================================================== */
class BtAvrcpMessageArgumentsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static BtAvrcpMessageArgumentsDestroyTableNode* GetInstance();
        
    private:
        BtAvrcpMessageArgumentsDestroyTableNode();
        
        
        static BtAvrcpMessageArgumentsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };
#endif // Bluetooth_BtAvrcpMessageArguments_hpp

