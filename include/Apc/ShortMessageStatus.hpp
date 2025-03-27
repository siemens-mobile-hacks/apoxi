/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_ShortMessageStatus_hpp)
#define Apc_ShortMessageStatus_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    TP-ST: Transfer Protocol - Status - 3GPP TS 23.040 V5.1.0 [9.2.3.15]
    ========================================================================*/
class ShortMessageStatus {
    public:
        enum Status { // do not change order 
            TransactionCompleted = 0,
            TemporaryErrorStillTrying,
            PermanentError,
            TemporaryError,
            ReservedStatus,
            InvalidStatus,
        };


        enum Reason { // do not change order 
            SmDelivered = 0,
            SmDeliveredButUnableToConfirm,  
            SmReplaced,

            ReservedReason,
            ServiceCenterSpecificReason,
            
            Congestion,
            SmeBusy,
            NoResponseFromSme,
            ServiceRejected,
            QualityOfServiceNotAvailable,
            ErrorInSme,

            RemoteProcedureError,
            IncompatibleDestination,
            ConnectionRejectedBySme,
            NotObtainable,
            NoInterworkingAvailable,
            SmValidityPeriodExpired,
            SmDeletedByOriginatingSme,
            SmDeletedByScAdministration,
            SmDoesNotExist,

            InvalidReason,
        };

        ShortMessageStatus();

        ShortMessageStatus(UINT8 incoming_byte);

        UINT8 Get() const { return (m_bit_field.Get()); }

        Status GetStatus() const;
        void SetStatus(Status status);

        Reason GetReason() const;
        void SetReason(Reason reason);

        void Clear() { m_bit_field.Clear();}

    private:
        BitField8 m_bit_field;
};


#endif  // Apc_ShortMessageStatus_hpp


