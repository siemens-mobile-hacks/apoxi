/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\StandAlone\SaArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_StandAlone_SaArgs_hpp)
#define AddOns_Lcs_StandAlone_SaArgs_hpp

#include <Kernel/Message.hpp>
#include <AddOns/Lcs/Common/LcsTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SaMolrResultArg
    ====================================================================== */

class SaMolrResultArg : public StackMsgArgument {
    friend class SaStackMsgArgsDestroyTableNode;
    public:
        SaMolrResultArg(BYTE ti_pd, const LocationEstimate& location_estimate);
        SaMolrResultArg();
        ~SaMolrResultArg();
        
        static const SaMolrResultArg& Cast(const StackMsgArgument& arg);
        BYTE GetTiPd() const { return m_ti_pd; }
        const LocationEstimate& GetLocationEstimate() const { return m_location_estimate; }
        
        enum  {
            ID = 4235
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SaMolrResultArg*) arg); }
        
        BYTE m_ti_pd;
        LocationEstimate m_location_estimate;
        
    };

// Inline definitions
inline const SaMolrResultArg& SaMolrResultArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SaMolrResultArg!\n");
    return ((SaMolrResultArg &) arg);
}



/*  ======================================================================
    Class SaLocationErrArg
    ====================================================================== */

class SaLocationErrArg : public StackMsgArgument {
    friend class SaStackMsgArgsDestroyTableNode;
    public:
        SaLocationErrArg(BYTE err_cause);
        SaLocationErrArg();
        ~SaLocationErrArg();
        
        static const SaLocationErrArg& Cast(const StackMsgArgument& arg);
        BYTE GetErrCause() const { return m_err_cause; }
        
        enum  {
            ID = 4236
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SaLocationErrArg*) arg); }
        
        BYTE m_err_cause;
        
    };

// Inline definitions
inline const SaLocationErrArg& SaLocationErrArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SaLocationErrArg!\n");
    return ((SaLocationErrArg &) arg);
}


#endif // AddOns_Lcs_StandAlone_SaArgs_hpp

