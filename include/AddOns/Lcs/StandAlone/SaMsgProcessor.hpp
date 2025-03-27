/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_StandAlone_SaMsgProcessor_hpp)
#define AddOns_Lcs_StandAlone_SaMsgProcessor_hpp

#include <Apc/SignalHandler/StackMsgProcessor.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>
#include <AddOns/Lcs/Common/LcsDecls.hpp>

class SaMsgProcessor : public StackMsgProcessor
{
    public:

        static void ProcessMolrReq( TI_PD ti_pd,
                                    MolrType molr_type,
                                    LocationMethod location_method,
                                    const LcsQos& lcs_qos,
                                    const ClientId& client_id,
                                    const MlcNumber& mlc_number);


}; // SaMsgProcessor

#endif // AddOns_Lcs_StandAlone_SaMsgProcessor_hpp

