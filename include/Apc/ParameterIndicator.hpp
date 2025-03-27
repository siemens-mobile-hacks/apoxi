/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_ParameterIndicator_hpp)
#define Apc_ParameterIndicator_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    TP-PI: Transfer Protocol - Parameter Indicator - 3GPP TS 23.040 V5.1.0 [9.2.3.27]
    ========================================================================*/
class ParameterIndicator {
    public:
        ParameterIndicator();
        ParameterIndicator(UINT8 incoming_byte, BOOLEAN valid = FALSE);
        BOOLEAN IsValid() const { return (m_valid); }
        void SetValid(BOOLEAN valid = TRUE) { m_valid = valid; }
        UINT8 Get() const;
        BOOLEAN ExtensionExists() const;
        void SetExtension();
        BOOLEAN ProtocolIdentifierExists() const;
        void SetProtocolIdentifierExists();
        BOOLEAN DataCodingSchemeExists() const;
        void SetDataCodingSchemeExists();
        BOOLEAN UserDataExists() const;
        void SetUserDataExists();
        void Clear();

    private:
        BitField8 m_bit_field;
        BOOLEAN m_valid;
};


#endif  // Apc_ParameterIndicator_hpp


