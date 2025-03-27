/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "pointner_leopard_development_pu_dv\lnz_apoxi\Apoxi\Bluetooth\HF\BtHfControllerMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtHfMessageArguments_hpp)
#define Bluetooth_BtHfMessageArguments_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/HF/BtHfControllerMessageArgument.hpp>
#include <Bluetooth/HF/BtHfNotificationMessageArgument.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHfMessageArgumentsDestroyTableNode
    ====================================================================== */

class BtHfMessageArgumentsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static BtHfMessageArgumentsDestroyTableNode* GetInstance();
        
    private:
        BtHfMessageArgumentsDestroyTableNode();
        
        
        static BtHfMessageArgumentsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // Bluetooth_BtHfMessageArguments_hpp

