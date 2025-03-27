/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\AddOns\Lcs\GLTP\GltpArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Lcs_GLTP_GltpArgs_hpp)
#define AddOns_Lcs_GLTP_GltpArgs_hpp

#include <Kernel/Message.hpp>
#include <AddOns/Lcs/GLTP/GltpTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class MeasurementDataArg
    ====================================================================== */

class MeasurementDataArg : public StackMsgArgument {
    friend class GltpStackMsgArgsDestroyTableNode;
    public:
        MeasurementDataArg(const MeasurementData& msr_data);
        MeasurementDataArg();
        ~MeasurementDataArg();
        
        static const MeasurementDataArg& Cast(const StackMsgArgument& arg);
        const MeasurementData& GetMsrData() const { return m_msr_data; }
        
        enum  {
            ID = 4225
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((MeasurementDataArg*) arg); }
        
        MeasurementData m_msr_data;
        
    };

// Inline definitions
inline const MeasurementDataArg& MeasurementDataArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to MeasurementDataArg!\n");
    return ((MeasurementDataArg &) arg);
}


#endif // AddOns_Lcs_GLTP_GltpArgs_hpp

