/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_ShortMessageFailureCause_hpp)
#define Apc_ShortMessageFailureCause_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>

/*  ========================================================================
    TP-FCS: Transfer Protocol - Failure Cause - 3GPP TS 23.040 V5.1.0 [9.2.3.22]
    ========================================================================*/
class ShortMessageFailureCause {
    public:
        enum Usage {
            MobileOriginated,
            MobileTerminated,
            UndefinedUsage,
        };

        enum Error {
            ReservedGeneralErrorBegin = 0x00,
            ReservedGeneralErrorEnd = 0x0f,

            TelematicInterworkingNotSupported = 0x80,
            SmType0NotSupported = 0x81,
            CannotReplaceSm = 0x82,
            ReservedPidErrorBegin,
            ReservedPidErrorEnd = 0x8e,
            UnspecifiedPidError = 0x8f,

            AlphabetNotSupported = 0x90,
            MessageClassNotSupported = 0x91,
            ReservedDcsErrorBegin,
            ReservedDcsErrorEnd = 0x9e,
            UnspecifiedDcsError = 0x9f,

            CommandCannotBePerformed = 0xa0,
            CommandUnsupported = 0xa1,
            ReservedCommandErrorBegin,
            ReservedCommandErrorEnd = 0xae,
            UnspecifiedCommandError = 0xaf,

            TpduNotSupported = 0xb0,
            ReservedTpduErrorBegin,
            ReservedTpduErrorEnd = 0xbf,

            ScBusy = 0xc0,
            NoScSubscription = 0xc1,
            ScSystemFailure = 0xc2,
            InvalidSmeAddress = 0xc3,
            DestinationSmeBarred = 0xc4,
            SmRejectedDuplicateSm = 0xc5,
            VpfNotSupported = 0xc6,
            VpNotSupported = 0xc7,
            ReservedScErrorBegin,
            ReservedScErrorEnd = 0xcf,

            USimSmsStorageFull = 0xd0,
            NoSmsStorageCapabilityInUSim = 0xd1,
            ErrorInMs = 0xd2,
            MemoryCapacityExceeded = 0xd3,
            USimApplicationToolkitBusy = 0xd4,
            USimDataDownloadError = 0xd5,
            ReservedUSimErrorBegin,
            ReservedUSimErrorEnd = 0xdf,

            ReservedApplicationErrorBegin,
            ReservedApplicationErrorEnd = 0xfe,

            UnspecifiedError = 0xff,

            ReservedErrorValue,

            InvalidErrorValue
        };

        ShortMessageFailureCause();
        ShortMessageFailureCause(UINT8 incoming_byte);

        UINT8 Get() const { return (m_bit_field.Get()); }

        Error GetError() const;
        void SetError(Error error);

        void Clear() { m_bit_field.Clear();}

    private:
        BitField8 m_bit_field;
};


#endif  // Apc_ShortMessageFailureCause_hpp


