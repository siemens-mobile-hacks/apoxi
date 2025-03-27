/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_CommandType_hpp)
#define Apc_CommandType_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    TP-CT: Transfer Protocol - Command Type - 3GPP TS 23.040 V5.1.0 [9.2.3.19]
    ========================================================================*/
class CommandType {
    public:
        enum Type { // please do not change order
            Enquiry = 0,
            CancelStatusReportRequest,
            Delete,
            EnableStatusReportRequest,
            ReservedType,
            ServiceCenterSpecificType,
            InvalidType,
        };

        CommandType();
        CommandType(UINT8 incoming_byte);

        UINT8 Get() const { return (m_bit_field.Get()); }

        Type GetType() const;
        void SetType(Type type);

        void Clear() { m_bit_field.Clear();}

    private:
        BitField8 m_bit_field;
};


#endif  // Apc_CommandType_hpp


