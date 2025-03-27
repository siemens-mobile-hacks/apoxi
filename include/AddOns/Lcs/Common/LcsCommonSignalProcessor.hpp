/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsCommonSignalProcessor_hpp)
#define AddOns_Lcs_Common_LcsCommonSignalProcessor_hpp

class LcsCommonSignalProcessor
{
    public:

        static void PostAbortResponse(const ProcessPtr& process_ptr);
};

#endif // AddOns_Lcs_Common_LcsCommonSignalProcessor_hpp

