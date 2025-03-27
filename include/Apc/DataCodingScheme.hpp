/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_DataCodingScheme_hpp)
#define Apc_DataCodingScheme_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BitField.hpp>


/*  ========================================================================
    Data Coding Scheme - 3GPP TS 23.038 V4.3.0 (2001-09)
    ========================================================================*/
class DataCodingScheme {
    public:
        enum Type {
            Sms,
            Cbs,
            InvalidType,
        };

        enum GroupId {
            GeneralDataCodingGroup,
            AutomaticDeletionGroup,
            ReservedCodingGroup,
            MsgWaitingIndDiscardGroup,
            MsgWaitingIndStoreDefaultGroup,
            MsgWaitingIndStoreUcs2Group,
            DataCodingMsgHandlingGroup,
            LanguageSelectionGroup,
            LanguageSelectionWithinMessageGroup,
            WapGroup,
            InvalidGroup
        };

        enum LanguageGroupId { // do not change order
            LanguageGroup00 = 0,
            LanguageGroup01,
            LanguageGroup10,
            LanguageGroup11,
            InvalidLanguageGroup
        };

        enum Alphabet { // do not change order
            DefaultAlphabet = 0, // PMI_DEFAULT_ALPHABET
            EightBitAlphabet,   // PMI_8_BIT_ALPHABET
            Ucs2Alphabet,       // PMI_UCS2_ALPHABET
            ReservedAlphabet,
            InvalidAlphabet,    // PMI_UNKNOWN_ALPHABET
        };

        // sms class
        // (lookup in pmi_op20.h corresponding enum declaration - t_pmi_class)
        enum MessageClass { // do not change order
            Class0 = 0,     // PMI_CLASS_0
            Class1,         // PMI_CLASS_1
            Class2,         // PMI_CLASS_2
            Class3,         // PMI_CLASS_3
            NoClass,        // PMI_NO_CLASS
            InvalidClass,   // PMI_UNKNOWN_CLASS
        };

        // text compression state
        // (lookup in pmi_op20.h corresponding enum declaration - t_pmi_compr_state)
        enum TextCompression {
            TextUncompressed,       // PMI_TEXT_UNCOMPRESSED
            TextCompressed,         // PMI_TEXT_COMPRESSED
            InvalidTextCompression, // PMI_UNKNOWN_COMPR_STATUS,
        };

        // waiting message
        enum WaitingMessage { // do not change order 
            VoiceMessage = 0,
            FaxMessage,
            EmailMessage,
            OtherMessage,
            InvalidMessage
        };

        enum WaitingMessageIndication {
            MessageWaitingActive,
            MessageWaitingInactive,
            MessageWaitingInvalid
        };

        enum Language   // do not change order !
        {
            German = 0,
            English,
            Italian,
            French,
            Spanish,
            Dutch,
            Swedish,
            Danish,
            Portuguese,
            Finnish,
            Norwegian,
            Greek,
            Turkish,
            Hungarian,
            Polish,
            UnspecifiedLanguage,

            Czech,
            Hebrew,
            Arabic,
            Russian,
            Icelandic,

            ReservedLanguage,
            InvalidLanguage
        };

        
        DataCodingScheme();
        DataCodingScheme(Type type, UINT8 incoming_byte = 0);

        BOOLEAN operator == (const DataCodingScheme &dcs) const;

        UINT8 Get() const { return (m_bit_field.Get()); }

        Type GetType() const { return (Type)(m_type); }
        void SetType(Type type) { m_type = type; }

        GroupId GetGroupId() const;
        void SetGroupId(GroupId group_id);

        MessageClass GetMessageClass() const;
        void SetMessageClass(MessageClass msg_class);

        Alphabet GetAlphabet() const;
        void SetAlphabet(Alphabet alphabet);

        TextCompression GetTextCompression() const;
        void SetTextCompression(TextCompression msg_class);

        WaitingMessage GetWaitingMessage() const;
        void SetWaitingMessage(WaitingMessage waiting_message);

        WaitingMessageIndication GetWaitingMessageIndication() const;
        void SetWaitingMessageIndication(WaitingMessageIndication waiting_message_indication);

        Language GetLanguage() const;
        void SetLanguage(Language language);

        BOOLEAN IsInvalid() const { return (m_type == InvalidType); }

        void Clear();

    private:
        UINT8     m_type;
        BitField8 m_bit_field;

        LanguageGroupId GetLanguageGroupId() const;
        void SetLanguageGroupId(LanguageGroupId language_group_id);
};

/*  ========================================================================
    Data Coding Scheme Range 
    ========================================================================*/
class DataCodingSchemeRange : public Linkable<DataCodingSchemeRange> {
    public:
        DataCodingSchemeRange();
        DataCodingSchemeRange(const DataCodingScheme &begin, const DataCodingScheme &end = DataCodingScheme());

        BOOLEAN operator == (const DataCodingSchemeRange &dcs_range) const;

        const DataCodingScheme& Begin() const { return (m_begin); }
        void Begin(const DataCodingScheme &begin) { m_begin = begin; }
        const DataCodingScheme& End() const { return (m_end); }
        void End(const DataCodingScheme &end) { m_end = end; }
        BOOLEAN IsValid() { return (m_begin.Get() <= m_end.Get());}

    private:
        DataCodingScheme m_begin;
        DataCodingScheme m_end;
};


#endif  // Apc_DataCodingScheme_hpp


