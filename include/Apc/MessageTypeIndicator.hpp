/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_MessageTypeIndicator_hpp)
#define Apc_MessageTypeIndicator_hpp

#include <Kernel/Types.hpp>


/*  ========================================================================
    MessageTypeIndicator - 3GPP 23.040 V5.1.0 [9.2.3.1]
    ======================================================================== */
class MessageTypeIndicator {
    public:
        enum Usage {
            MobileOriginated,
            MobileTerminated,
            InvalidUsage,
        };
        
        enum Type { // do not change oder of enums ! used as index
            DeliverReport = 0,
            Submit,
            Command,

            Deliver,
            SubmitReport,
            StatusReport,

            ReservedType,
            InvalidType,
        };

        MessageTypeIndicator();
        MessageTypeIndicator(Usage usage, UINT8 *data = 0);

        Type GetType() const;

        void SetType(Type format);

        Usage GetUsage() const { return (m_usage); }
        void SetUsage(Usage usage) { m_usage = usage; }

        BOOLEAN IsInvalid() const;

        void Clear();

        Type GetOriginType() const;

    private:
        Usage m_usage;
        // the format is stored within the bits 3 and 4 of one byte
        UINT8 *m_data;
};


#endif  // Apc_MessageTypeIndicator_hpp


