/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights 
    reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SsStatus_hpp)
#define Apc_SsStatus_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    Supplementary Service Status  [GSM 09.02, 14.7.4], (msap_msg_mn.pr: 966)
    SS-Status, containing the following information:
    bits 8765: 0000 unused
    bit 4 : quiescent/operative indicator
    bit 3 : provision indicator
    bit 2 : registration indicator
    bit 1 : activation indicator 

    ========================================================================*/
class SsStatus {
    public:
        SsStatus(UINT8 incoming_byte = 0) : m_ss_status(incoming_byte) {}

        UINT8 GetByte() const { return m_ss_status; }

        BOOLEAN IsQuiescentBitSet() const { return m_ss_status & 0x08; }        // bit 4
        BOOLEAN IsProvisionBitSet() const { return m_ss_status & 0x04; }        // bit 3
        BOOLEAN IsRegistrationBitSet() const { return m_ss_status & 0x02; } // bit 2
        BOOLEAN IsActivationBitSet() const { return m_ss_status & 0x01; }       // bit 1

    private:
        UINT8 m_ss_status;
};


#endif  // Apc_SsStatus_hpp


