/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights 
    reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SsNotification_hpp)
#define Apc_SsNotification_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    Supplementary Service Status  [GSM 09.02, 14.7.4], (msap_msg_mn.pr: 966)
    SS-Notification containing the following information:
    bits 87654: 00000 unused
    bit 3: Call is forwarded indication to calling subscriber
    bit 2: Call is forwarded indication to forwarding subscriber
    bit 1: Call is forwarded indication to forwarded-to subscriber
    coding defined in [GSM 04.80, 4.4.2]
    ========================================================================*/
class SsNotification {
    public:
        SsNotification(UINT8 incoming_byte = 0) : m_ss_notification(incoming_byte) {};

        UINT8 GetByte() const { return m_ss_notification; }
        BOOLEAN IsForwardedToCallingSubscriber() const { return m_ss_notification & 0x04; }
        BOOLEAN IsForwardedToForwardingSubscriber() const { return m_ss_notification & 0x02; }
        BOOLEAN IsForwardedToForwardedToSubscriber() const { return m_ss_notification & 0x01; }

    private:
        UINT8 m_ss_notification;
};


#endif  // Apc_SsNotification_hpp


