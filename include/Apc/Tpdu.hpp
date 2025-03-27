/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Tpdu_hpp)
#define Apc_Tpdu_hpp

#include <Kernel/Os/Os.hpp>
#include <Auxiliary/PhoneNumber.hpp>

#include <Apc/MessageTypeIndicator.hpp>

#include <Apc/SignalTypes.hpp>



inline BOOLEAN IsTpduSentStatus(UINT8 status)
{
    return (status & 0x07) == 0x05;
}   


inline UINT8 GetRawTpduStatus(UINT8 status)
{
    return (status & 0x07);
}   

/*  ========================================================================
    TPDU: Transfer Protocol Data Unit - 3GPP TS 23.040 V5.1.0 [9]
    ======================================================================== */
class Tpdu : public Linkable<Tpdu> {
    typedef Linkable<Tpdu> Base;
    public:
        enum Status {
            Empty           = SI_SM_STATUS_FREE,            // = 0000 0000
            Read            = SI_SM_STATUS_READ,            // = 0000 0001
            Unread          = SI_SM_STATUS_TO_BE_READ,      // = 0000 0011
            Sent            = SI_SM_STATUS_SENT,            // = 0000 0101 SMS sent
            SentSmsrReq     = 0x0d,                         // = 0000 1101 SMS sent and report requested
            SentSmsrNoSmsr  = 0x15,                         // = 0001 0101 SMS sent, report not stored in SMSR
            SentSmsrInSmsr  = 0x1d,                         // = 0001 1101 SMS sent, report stored in SMSR
            Unsent          = SI_SM_STATUS_TO_BE_SENT,      // = 0000 0111
            UndefinedStatus = SI_SM_STATUS_UNKNOWN          // = 1111 1111
        };

        Tpdu();
        Tpdu(Status status, INT length = 0, const UINT8 *data = 0);
        Tpdu(const T_PDU &sdl_pdu);
        virtual ~Tpdu();
        Tpdu(const Tpdu &tpdu);
        Tpdu& operator =(const Tpdu &tpdu);
        BOOLEAN operator == (const Tpdu &tpdu) const;

        void Convert2Pdu(T_PDU &sdl_pdu) const;

        BOOLEAN IsValid() const;

        void SetStatus(Status status) { m_status = status; }
        void SetDataBuffer(INT length, const UINT8 *data);
        
        Status GetStatus() const { return (m_status); }
        INT GetLength() const { return (m_length); }
        UINT8* GetData() const { return (m_data); }

        PhoneNumber GetServiceCentreAddress() const;
        void SetServiceCentreAddress(const PhoneNumber &phone_number);

        MessageTypeIndicator GetMessageTypeIndicator() const;

        BOOLEAN IsMobileTerminated() const { return (m_status == Read || m_status == Unread); }
        BOOLEAN IsMobileOriginated() const { return (IsTpduSentStatus(m_status) || m_status == Unsent); }


        static INT GetMaxDataSize();

        INT GetTpOffset() const;

        // returns the anchor of the real TPDU-data (starting with message type indicator). 
        INT GetTpLength() const;

        // returns the anchor of the real TPDU-data (starting with message type indicator). 
        UINT8* GetTpData() const;


        INT ReallocateData(INT length);

        INT ResizeData(INT length);

        void CopyData(const UINT8 *data);

        void ClearData();

        void Clear();

        void InitData(UINT8 fill_byte = 0x00);

    private:
        Status m_status;
        INT m_length;
        UINT8 *m_data;
};

#endif  // Apc_Tpdu_hpp


