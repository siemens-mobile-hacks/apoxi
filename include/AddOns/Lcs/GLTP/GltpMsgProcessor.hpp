/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_MsgProcessor_hpp)
#define AddOns_Lcs_GLTP_MsgProcessor_hpp

#include <Apc/SignalHandler/StackMsgProcessor.hpp>

struct ReferenceLocation;
struct ReferenceTime;

class GltpMsgProcessor : public StackMsgProcessor
{
    public:

        static void ProcessMeasurementDataReq(  const BYTE* ad_buf,
                                                INT size,
                                                BOOLEAN forced_fix = FALSE);

        static void ProcessReferenceTimeReq(const ReferenceTime& ref_time);

        static void ProcessRefLocReq(const ReferenceLocation& ref_loc);

};

#endif // AddOns_Lcs_GLTP_MsgProcessor_hpp

