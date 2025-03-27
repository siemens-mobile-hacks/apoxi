/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_StandAlone_SaSignalProcessor_hpp)
#define AddOns_Lcs_StandAlone_SaSignalProcessor_hpp

class SaSignalProcessor
{
    public:

        static void PostMolrResult(const ProcessPtr& process_ptr);

        static void PostLocationError(const ProcessPtr& process_ptr);

}; // SaSignalProcessor

#endif // AddOns_Lcs_StandAlone_SaSignalProcessor_hpp

