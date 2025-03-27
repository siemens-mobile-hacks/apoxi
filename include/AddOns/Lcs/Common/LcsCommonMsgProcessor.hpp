/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsCommonMsgProcessor_hpp)
#define AddOns_Lcs_Common_LcsCommonMsgProcessor_hpp

#include <Apc/SignalHandler/StackMsgProcessor.hpp>

class LcsCommonMsgProcessor : public StackMsgProcessor
{
    public:

        static void ProcessAbortReq();
};

#endif // AddOns_Lcs_Common_LcsCommonMsgProcessor_hpp

