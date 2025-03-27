/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Apc\SimMiscArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_CommonStackMsgArgs_hpp)
#define Apc_CommonStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/CallMiscStackMsgArgs.hpp>
#include <Apc/CbsStackMsgArgs.hpp>
#include <Apc/ChvStackMsgArgs.hpp>
#include <Apc/CrssStackMsgArgs.hpp>
#include <Apc/ImageStackMsgArgs.hpp>
#include <Apc/MiscStackMsgArgs.hpp>
#include <Apc/MocStackMsgArgs.hpp>
#include <Apc/MtcStackMsgArgs.hpp>
#include <Apc/NetworkStackMsgArgs.hpp>
#include <Apc/PhoneBookStackMsgArgs.hpp>
#include <Apc/PowerStackMsgArgs.hpp>
#include <Apc/SimMiscStackMsgArgs.hpp>
#include <Apc/SimTkStackMsgArgs.hpp>
#include <Apc/SmsStackMsgArgs.hpp>
#include <Apc/SsStackMsgArgs.hpp>
#include <Apc/PlmnStackMsgArgs.hpp>
#include <Apc/CdStackMsgArgs.hpp>
#include <Apc/OmStackMsgArgs.hpp>
#include <Apc/MdhSmsStackMsgArgs.hpp>
#include <Apc/AtcStackMsgArgs.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class CommonStackMsgArgsDestroyTableNode
    ====================================================================== */

class CommonStackMsgArgsDestroyTableNode : public StackMsgArgDestroyTableNode {
    public:
        
        static CommonStackMsgArgsDestroyTableNode* GetInstance();
        
    private:
        CommonStackMsgArgsDestroyTableNode();
        
        
        static CommonStackMsgArgsDestroyTableNode* m_node;
        static const ArgumentDestroyEntry m_destroy_table[];
        
    };

#endif // Apc_CommonStackMsgArgs_hpp

