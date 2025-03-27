/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_ProtocolIdentifier_hpp)
#define Apc_ProtocolIdentifier_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    TP-PID: Transfer Protocol - Protocol Identifier - 3GPP TS 23.040 V5.1.0 [9.2.3.9]
    ========================================================================*/
class ProtocolIdentifier {
    public:
        // marks the invalidity of the protocol-identifier
        enum { 
            InvalidPid = 0x80   // the use of the reserved (0x80) group setting leads to invalid return values.
        };

        enum Usage {
            Normal,
            ReservedUsage,
            ServiceCenterSpecificUsage,
            InvalidUsage
        };

        enum UsageGroup {
            Group00,
            Group01,
            InvalidGroup
        };

        enum Interworking {
            SmeToSme,
            Telematic,
            InvalidInterworking
        };

        enum TelematicDevice {  // do not change oder of enums ! used as index
            Implicit,
            Telex,
            Group3Telefax,
            Group4Telefax,
            VoiceTelephone,
            Ermes,
            NationalPagingSystem,
            Videotex,
            TeletexCarrierUnspecified,
            TeletexPspdn,
            TeletexCspdn,
            TeletexAnalogPstn,
            TeletexDigitalIsdn,
            Uci,
            MessageHandlingFacility,
            X400,
            InternetElectronicMail,


            ServiceCenterSpecificTelematicDevice,
            GsmUmts,
            ReservedTelematicDevice,
            InvalidTelematicDevice
        };

        enum MessageType { // do not change oder of enums ! used as index
            ShortMessageType0 = 0,
            ReplaceShortMessageType1,
            ReplaceShortMessageType2,
            ReplaceShortMessageType3,
            ReplaceShortMessageType4,
            ReplaceShortMessageType5,
            ReplaceShortMessageType6,
            ReplaceShortMessageType7,
            EnhancedMessageType,
            ReturnCallMessage,
            Ansi136,
            MeDataDownload,
            MeDepersonalizationShortMessage,
            USimDataDownload,
            ReservedMessageType,
            InvalidMessageType
        };


        ProtocolIdentifier();
        ProtocolIdentifier(UINT8 incoming_byte);

        UINT8 Get() const { return (m_bit_field.Get()); }

        Usage GetUsage() const;
        void SetUsage(Usage usage);

        Interworking GetInterworking() const;
        void SetInterworking(Interworking interworking);

        TelematicDevice GetTelematicDevice() const;
        void SetTelematicDevice(TelematicDevice telematic_device);

        MessageType GetMessageType() const;
        void SetMessageType(MessageType message_type);

        BOOLEAN IsNormalUsage() const { return (GetUsage() == Normal); }
        BOOLEAN IsTelematicDevice() const { return (GetInterworking() == Telematic); }
        BOOLEAN IsInvalid() const { return (m_bit_field.Get() == InvalidPid); }

        void Clear() { m_bit_field.Set(InvalidPid); }

    private:
        BitField8 m_bit_field;

        UsageGroup GetUsageGroup() const;
        void SetUsageGroup(UsageGroup usage_group);
};


#endif  // Apc_ProtocolIdentifier_hpp


