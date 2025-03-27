/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_3GPP_LcsSignalProcessor_hpp)
#define AddOns_Lcs_3GPP_LcsSignalProcessor_hpp

class LcsSignalProcessor
{
    public:

        static void PostMtlrIndReceived(const ProcessPtr& process_ptr);

        static void PostMolrResult(const ProcessPtr& process_ptr);

}; // LcsSignalProcessor

#endif // AddOns_Lcs_3GPP_LcsSignalProcessor_hpp

