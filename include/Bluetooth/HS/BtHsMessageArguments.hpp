/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "pointner_leopard_development_pu_dv\lnz_apoxi\Apoxi\Bluetooth\HS\BtHsControllerMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtHsMessageArguments_hpp)
#define Bluetooth_BtHsMessageArguments_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/HS/BtHsControllerMessageArgument.hpp>
#include <Bluetooth/HS/BtHsNotificationMessageArgument.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHsMessageArgumentsDestroyTableNode
    ====================================================================== */

class BtHsMessageArgumentsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static BtHsMessageArgumentsDestroyTableNode* GetInstance();
        
    private:
        BtHsMessageArgumentsDestroyTableNode();
        
        
        static BtHsMessageArgumentsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // Bluetooth_BtHsMessageArguments_hpp

