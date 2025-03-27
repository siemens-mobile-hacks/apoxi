/*  ------------------------------------------------------------------------
Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved. 
------------------------------------------------------------------------ 
This document
contains proprietary information belonging to COMNEON. Passing on and copying of
this document, use and communication of its contents is not permitted without
prior written authorisation. 
------------------------------------------------------------------------ */
#if !defined(Auxiliary_TypeOfAddress_hpp) 
#define Auxiliary_TypeOfAddress_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    Type-of-Address (TON/NPI) - 3GPP TS 23.040 V5.1.0 [9.2.3.9]
    ========================================================================*/
class TypeOfAddress {
    public:
        // marks the invalidity of the protocol-identifier
        enum {
            InvalidTypeOfAddress = 0x00
        };

        enum TypeOfNumber { // do not change order
            UnknownTypeOfNumber = 0,
            InternationalNumber,
            NationalNumber,
            NetworkSpecificNumber,
            SubscriberNumber,
            Alphanumeric,
            AbbreviatedNumber,
            ReservedTypeOfNumber,
            InvalidTypeOfNumber
        };

        enum NumberingPlanIdentification {
            UnknownNumberingPlan,
            TelephoneNumberingPlan,
            DataNumberingPlan,
            TelexNumberingPlan,
            ServiceCentreSpecificPlan,
            NationalNumberingPlan,
            PrivateNumberingPlan,
            ErmesNumberingPlan,
            ReservedNumberingPlan,
            InvalidNumberingPlan,
        };

        TypeOfAddress();
        TypeOfAddress(UINT8 incoming_byte);

        UINT8 Get() const { return (m_bit_field.Get()); }

        TypeOfNumber GetTypeOfNumber() const;
        void SetTypeOfNumber(TypeOfNumber type_of_number);

        NumberingPlanIdentification GetNumberingPlanIdentification() const;
        void SetNumberingPlanIdentification(NumberingPlanIdentification numbering_plan_identification);

        BOOLEAN Is3aExisting() const {          
            return (! m_bit_field.GetBit(7));
        }   
        void Set3aNotExists() {
            m_bit_field.SetTrue(7);
        }
        void Set3aExists() {
            m_bit_field.SetFalse(7);
        }

        void Clear() { m_bit_field.Set(InvalidTypeOfAddress); }

    private:
        BitField8 m_bit_field;
};


#endif  // Auxiliary_TypeOfAddress_hpp


