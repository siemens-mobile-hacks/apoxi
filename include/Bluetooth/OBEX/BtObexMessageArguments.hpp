/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXITEST_20_10_06-2_SV\lnz_apoxi\Apoxi\Bluetooth\OBEX\BtObexNotificationMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtObexMessageArguments_hpp)
#define Bluetooth_BtObexMessageArguments_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/OBEX/BtObexNotificationMessageArgument.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtObexMessageArgumentsDestroyTableNode
    ====================================================================== */

class BtObexMessageArgumentsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static BtObexMessageArgumentsDestroyTableNode* GetInstance();
        
    private:
        BtObexMessageArgumentsDestroyTableNode();
        
        
        static BtObexMessageArgumentsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // Bluetooth_BtObexMessageArguments_hpp

