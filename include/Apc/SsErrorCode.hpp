/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights 
    reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SsErrorCode_hpp)
#define Apc_SsErrorCode_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    This type conveys the Error Codes, [GSM 04.80, 4.5]
    Values taken from msap_msg_mn.pr line 1481 ff
    ========================================================================*/
class SsErrorCode {
    public:
        enum Code {
            MsIntSsError                        = 0,
            MsIntSsTimeOut                      = 255,
            UnknownSubscriber                   = 1,
            IllegalSubscriber                   = 9,
            BearerServiceNotProvisioned         = 10,
            TeleserviceNotProvisioned           = 11,
            IllegalEquipment                    = 12,
            CallBarred                          = 13,
            IllegalSsOperation                  = 16,
            SsErrorStatus                       = 17,
            SsNotAvailable                      = 18,
            SsSubscriptionViolation             = 19,
            SsIncompatibility                   = 20,
            FacilityNotSupported                = 21,
            AbsentSubscriber                    = 27,
            SystemFailure                       = 34,
            DataMissing                         = 35,
            UnexpectedDataValue                 = 36,
            PwRegistrationFailure               = 37,
            NegativePwCheck                     = 38,
            NumberOfPwAttemptsViolation         = 43,
            PositionMethodError                 = 54,
            UnknownAlphabet                     = 71,
            UssdBusy                            = 72,
            MaxNumberOfMptyParticipantsExceeded = 126,
            ResourcesNotAvailable               = 127,
            TaggedError                         = 128,
            NoError
        };

        SsErrorCode(UINT8 incoming_byte = 0) : m_code(incoming_byte) {}

        UINT8 GetByte() const { return m_code; }

        Code GetCode() const { return (Code)m_code; }
        void SetCode(Code code) { m_code = (UINT8)m_code; }

    private:
        UINT8 m_code;
};


#endif  // Apc_SsErrorCode_hpp

