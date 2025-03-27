/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsSocket_hpp)
#define Asc_SmsSocket_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BlobObject.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>
#include <Apc/InformationElement.hpp>
#include <Apc/Tpdu.hpp>

#include "PortHeaderInformation.hpp"

class ExecutionContext;
class SmsSocketListener;
/*  ========================================================================
    SmsSocket
    ======================================================================== */
class SmsSocket : public Linkable <SmsSocket> {
    friend class SmsSocketListener;
    public:
        SmsSocket(SmsPortNo sms_port_no = InvalidSmsPortNo);
        virtual ~SmsSocket();

        BOOLEAN Init(SmsPortNo sms_port_no, BOOLEAN force = FALSE);

        SmsPortNo GetPortNo() const { return (m_sms_port_no); }

        ExecutionContext* GetExecutionContext() const { return (m_context); }
        
        BOOLEAN IsActive() const { return (m_context != 0); }

        BOOLEAN Read(BlobObject &blob, INT no_of_bytes_to_read = -1);

        BOOLEAN Read(WString &wstr);


    private:
        // class for storing Tpdu data, incl. its PortHeaderInformation
        class PortTpdu : public Linkable<PortTpdu> {
            public:
                PortTpdu(const Tpdu& tpdu) : m_tpdu(tpdu), m_phi(&m_tpdu) {}
                const PortHeaderInformation& GetPortHeaderInformation() const { return (m_phi); } 
                Tpdu * GetTpdu() { return (&m_tpdu); } 

            private: 
                Tpdu m_tpdu;
                PortHeaderInformation m_phi;
        };

        SmsPortNo        m_sms_port_no;

        SmsPortNo        m_last_sms_orig_port_no;
        PhoneNumber      m_last_oa_address;
        PhoneNumber      m_last_sca;
        DateTime         m_last_rev_datetime;
        DataCodingScheme m_last_dcs;

        ExecutionContext *m_context;
        ExecutionContext *m_prev_context;
        BlobObject m_data;
        WString    m_wstr;
        LinkedList<PortTpdu> m_port_tpdu_list;

        // looks for a port tpdu, which matches the given phi and the seq_no
        PortTpdu* FindPortTpdu(const PortHeaderInformation& phi, UINT8 seq_no) const;

        // Stores the tpdu - data in the socket, and returns TRUE, if new data is available to read out
        BOOLEAN PushTpdu(const Tpdu &tpdu, BOOLEAN avoidnotification = FALSE);

        /* Activates the well defined sms socket. The method fails, if it was not initialized, or port is already in use. */
        BOOLEAN Activate();

        // Deactivates the sms socket 
        BOOLEAN Deactivate();

        //
        void ResetData();

};

#endif  // Asc_SmsSocket_hpp


