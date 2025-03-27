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


#if !defined(AddOns_Lcs_Common_LcsCommonArgs_hpp)
#define AddOns_Lcs_Common_LcsCommonArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AbortResArg
    ====================================================================== */

class AbortResArg : public StackMsgArgument {
    friend class LcsCommonStackMsgArgsDestroyTableNode;
    public:
        AbortResArg();
        ~AbortResArg();
        
        static const AbortResArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 4200
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((AbortResArg*) arg); }
        
    };

// Inline definitions
inline const AbortResArg& AbortResArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to AbortResArg!\n");
    return ((AbortResArg &) arg);
}


#endif // AddOns_Lcs_Common_LcsCommonArgs_hpp

