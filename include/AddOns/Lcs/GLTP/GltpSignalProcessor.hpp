/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_GltpSignalProcessor_hpp)
#define AddOns_Lcs_GLTP_GltpSignalProcessor_hpp

class GltpSignalProcessor
{
    public:

        static void PostMeasurementData(const ProcessPtr& process_ptr);

}; // GltpSignalProcessor

#endif // AddOns_Lcs_GLTP_GltpSignalProcessor_hpp

