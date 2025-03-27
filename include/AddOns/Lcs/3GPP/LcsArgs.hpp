/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\3GPP\LcsArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_3GPP_LcsArgs_hpp)
#define AddOns_Lcs_3GPP_LcsArgs_hpp

#include <Kernel/Message.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class LocationNotifInvokeArg
    ====================================================================== */

class LocationNotifInvokeArg : public StackMsgArgument {
    friend class LcsStackMsgArgsDestroyTableNode;
    public:
        LocationNotifInvokeArg(const TI_PD& ti_pd, const LcsNotificationType& notif_type, const LocationType& location_type, const ClientInfo& client_info);
        LocationNotifInvokeArg();
        ~LocationNotifInvokeArg();
        
        static const LocationNotifInvokeArg& Cast(const StackMsgArgument& arg);
        const TI_PD& GetTiPd() const { return m_ti_pd; }
        const LcsNotificationType& GetNotifType() const { return m_notif_type; }
        const LocationType& GetLocationType() const { return m_location_type; }
        const ClientInfo& GetClientInfo() const { return m_client_info; }
        
        enum  {
            ID = 4215
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LocationNotifInvokeArg*) arg); }
        
        TI_PD m_ti_pd;
        LcsNotificationType m_notif_type;
        LocationType m_location_type;
        ClientInfo m_client_info;
        
    };

// Inline definitions
inline const LocationNotifInvokeArg& LocationNotifInvokeArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LocationNotifInvokeArg!\n");
    return ((LocationNotifInvokeArg &) arg);
}



/*  ======================================================================
    Class LcsMolrResultArg
    ====================================================================== */

class LcsMolrResultArg : public StackMsgArgument {
    friend class LcsStackMsgArgsDestroyTableNode;
    public:
        LcsMolrResultArg(BYTE ti_pd, const LocationEstimate& location_estimate);
        LcsMolrResultArg();
        ~LcsMolrResultArg();
        
        static const LcsMolrResultArg& Cast(const StackMsgArgument& arg);
        BYTE GetTiPd() const { return m_ti_pd; }
        const LocationEstimate& GetLocationEstimate() const { return m_location_estimate; }
        
        enum  {
            ID = 4216
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((LcsMolrResultArg*) arg); }
        
        BYTE m_ti_pd;
        LocationEstimate m_location_estimate;
        
    };

// Inline definitions
inline const LcsMolrResultArg& LcsMolrResultArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to LcsMolrResultArg!\n");
    return ((LcsMolrResultArg &) arg);
}


#endif // AddOns_Lcs_3GPP_LcsArgs_hpp

