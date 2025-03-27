/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_InformationElement_hpp)
#define Apc_InformationElement_hpp

#include <Kernel/Types.hpp>

/*  ========================================================================
    InformationElement - 3GPP TS 23.040 V5.1.0 [9.2.3.24.1 - 9.2.3.24.12]
    ======================================================================== */

const UINT8 c_large_animation_size = 128;
const UINT8 c_small_animation_size = 32;
const UINT8 c_large_picture_size = 128;
const UINT8 c_small_picture_size = 32;

typedef UINT16 SmsPortNo;
enum { InvalidSmsPortNo = 0x00 };   // define an invalid port number

class InformationElement
{
    public:
        enum Identifier {
            ConcatenatedSm8Bit = 0x00,
            SpecialSms = 0x01,
            ValueNotUsed = 0x03,
            AddressingScheme8Bit = 0x04,
            AddressingScheme16Bit = 0x05,
            SmscControl = 0x06,
            UdhSourceIndicator = 0x07,
            ConcatenatedSm16Bit = 0x08,
            WirelessControlMessageProtocol = 0x09,
            TextFormatting = 0x0a,
            PredefinedSound = 0x0b,
            UserDefinedSound = 0x0c,
            PredefinedAnimation = 0x0d,
            LargeAnimation = 0x0e,
            SmallAnimation = 0x0f,
            LargePicture = 0x10,
            SmallPicture = 0x11,
            VariablePicture = 0x12,
            UserPromptIndicator = 0x13, 
            ExtendedObject = 0x14,
            ReusedExtendedObject = 0x15,
            CompressionControl = 0x16,
            ObjectDistributionIndicator = 0x17,
            Rfc822EmailHeader = 0x20,
            HyperlinkFormatElement = 0x21,

            ReservedIdentifier,

            InvalidIdentifier,

            // Special Handling
            ContinuedExtendedObject = (ExtendedObject | 0x80)
        };

        enum MessageType {
            VoiceMessage = 0,
            FaxMessage = 1,
            ElectronicMail = 2,
            OtherMessage = 3,
        };

        enum PredefinedSoundType {
            ChimesHigh = 0,
            ChimesLow = 1,
            Ding = 2,
            TaDa = 3,
            Notify = 4,
            Drum = 5,
            Claps = 6,
            FanFar = 7,
            ChordHigh = 8,
            ChordLow = 9,
        };

        enum PredefinedAnimationType {
            IAmIronic = 0,
            IAmGlad = 1,
            IAmSceptic = 2,
            IAmSad = 3,
            Wow = 4,
            IAmCrying = 5,
            IAmWinking = 6,
            IAmLaughing = 7,
            IAmIndifferent = 8,
            Kissing = 9,
            IAmConfused = 10,
            TongueHangingOut = 11,
            IAmAngry = 12,
            WearingGlasses = 13,
            Devil = 14,
        };

        enum TextAlignment {
            Left = 0,
            Center = 1,
            Right = 2,
            LanguageDependend = 3,
        };
        enum FontSize {
            Default = 0,
            Large = 1,
            Small = 2,
            Reserved = 3,
        };
        enum TextColour {
            Black = 0,
            DarkGrey = 1,
            DarkRed = 2,
            DarkYellow = 3,
            DarkGreen = 4,
            DarkCyan = 5,
            DarkBlue = 6,
            DarkMagenta = 7,
            Grey = 8,
            White = 9,
            BrightRed = 10,
            BrightYellow = 11,
            BrightGreen = 12,
            BrightCyan = 13,
            BrightBlue = 14,
            BrightMagenta = 15,
        };
        enum ExtendedObjectType {
            EOPredefinedSound           = 0x00,
            EOiMelody                   = 0x01,
            EOBWBitmap                  = 0x02,
            EOTwoBitGrayScale           = 0x03,
            EOSixBitGrayScale           = 0x04,
            EOPredefinedAnimation       = 0x05,
            EOBWBitmapAnimation         = 0x06,
            EOTwoBitGrayScaleAnimation  = 0x07,
            EOSixBitGrayScaleAnimation  = 0x08,
            EOvCard                     = 0x09,
            EOvCalendar                 = 0x0A,
            EOStdWVGObject              = 0x0B,
            EOPolyphonicMelody          = 0x0C,
            EODataFormatDeliveryRequest = 0xFF
        };



        InformationElement();

        InformationElement(UINT8 *anchor);
        ~InformationElement();

        static UINT16 GetSize(Identifier id, UINT16 additional = 0);

        BOOLEAN IsValid() const;

        BOOLEAN SetIdentifier (Identifier id);

        Identifier GetIdentifier() const;

        UINT8 GetLength() const;

        UINT8* GetData() const;

        UINT8* GetData(INT idx) const;

        // Copies the whole information element into destination.
        void CopyTo(UINT8 *destination) const;

        InformationElement& operator =(const InformationElement &ie);

// Access and creation methods for Information elements details


        BOOLEAN SetConcatenatedSmReferenceNumber(UINT16 refno);
        BOOLEAN SetConcatenatedSmMaximumNumber(UINT8 maxno);
        BOOLEAN SetConcatenatedSmSequenceNumber(UINT8 seqno);



        BOOLEAN PutConcatenatedSm8Bit(UINT8 refno, UINT8 maxno, UINT8 seqno);
        UINT8 GetConcatenatedSm8BitReferenceNumber() const;
        UINT8 GetConcatenatedSm8BitMaximumNumber() const;
        UINT8 GetConcatenatedSm8BitSequenceNumber() const;


        BOOLEAN PutConcatenatedSm16Bit(UINT16 refno, UINT8 maxno, UINT8 seqno);
        UINT16 GetConcatenatedSm16BitReferenceNumber() const;
        UINT8 GetConcatenatedSm16BitMaximumNumber() const;
        UINT8 GetConcatenatedSm16BitSequenceNumber() const;


        BOOLEAN PutAddressingScheme8Bit(SmsPortNo destport, SmsPortNo orgport);
        SmsPortNo GetAddressingScheme8BitDestinationPort() const;
        SmsPortNo GetAddressingScheme8BitOriginatorPort() const;


        BOOLEAN PutAddressingScheme16Bit(SmsPortNo destport, SmsPortNo orgport);
        SmsPortNo GetAddressingScheme16BitDestinationPort() const;
        SmsPortNo GetAddressingScheme16BitOriginatorPort() const;


        UINT8 GetSpecialSmsMessageIndicationType() const;
        UINT8 GetSpecialSmsMessageCount() const;
        MessageType GetSpecialSmsMessageType() const;
        BOOLEAN ShallStoreMessage() const;
        

        BOOLEAN PutEmsRelativeStartPosition(UINT8 startpos);


        BOOLEAN PutTextFormatting(UINT8 startpos, UINT8 length, UINT8 mode, UINT8 colour);
        BOOLEAN PutTextFormatting(UINT8 startpos, UINT8 length, 
                                  InformationElement::TextAlignment alignment,
                                  InformationElement::FontSize fontsize,
                                  BOOLEAN bold,
                                  BOOLEAN italic,
                                  BOOLEAN underlined,
                                  BOOLEAN strikethrough,
                                  InformationElement::TextColour foreground,
                                  InformationElement::TextColour background);
        UINT8 GetTextFormattingStartPosition() const;
        UINT8 GetTextFormattingLength() const;
        UINT8 GetTextFormattingMode() const;
        TextAlignment GetTextFormattingTextAlignment() const;
        FontSize GetTextFormattingFontSize() const;
        BOOLEAN IsBold() const;
        BOOLEAN IsItalic() const;
        BOOLEAN IsUnderlined() const;
        BOOLEAN IsStrikethrough() const;
        UINT8 GetTextFormattingColour() const;
        TextColour GetTextFormattingForegroundColour() const;
        TextColour GetTextFormattingBackgroundColour() const;

        BOOLEAN PutPredefinedSound(UINT8 startpos, PredefinedSoundType sound);

        UINT8 GetPredefinedSoundStartPosition() const;
        PredefinedSoundType GetPredefinedSoundType() const;

        BOOLEAN PutUserDefinedSound(UINT8 startpos, UINT8 length, const UINT8 * sound);
        UINT8 GetUserDefinedSoundStartPosition() const;
        UINT8 * GetUserDefinedSoundBuffer() const;
        UINT8 GetUserDefinedSoundLength() const;


        BOOLEAN PutPredefinedAnimation(UINT8 startpos, PredefinedAnimationType animation);
        UINT8 GetPredefinedAnimationStartPosition() const;
        PredefinedAnimationType GetPredefinedAnimationType() const;

        BOOLEAN PutLargeAnimation(UINT8 startpos, const UINT8 * animation);
        UINT8 GetLargeAnimationStartPosition() const;
        UINT8 * GetLargeAnimationBuffer() const;
        UINT8 GetLargeAnimationLength() const;

        BOOLEAN PutSmallAnimation(UINT8 startpos, const UINT8 * animation);
        UINT8 GetSmallAnimationStartPosition() const;
        UINT8 * GetSmallAnimationBuffer() const;
        UINT8 GetSmallAnimationLength() const;

        BOOLEAN PutLargePicture(UINT8 startpos, const UINT8 * picture);
        UINT8 GetLargePictureStartPosition() const;
        UINT8 * GetLargePictureBuffer() const;
        UINT8 GetLargePictureLength() const;

        BOOLEAN PutSmallPicture(UINT8 startpos, const UINT8 * picture);
        UINT8 GetSmallPictureStartPosition() const;
        UINT8 * GetSmallPictureBuffer() const;
        UINT8 GetSmallPictureLength() const;

        BOOLEAN PutVariablePicture(UINT8 startpos, UINT8 horiz, UINT8 vert, UINT8 length, const UINT8 * picture);
        UINT8 GetVariablePictureStartPosition() const;
        UINT8 * GetVariablePictureBuffer() const;
        UINT8 GetVariablePictureLength() const;
        UINT8 GetVariablePictureHorizontalDimension() const;
        UINT8 GetVariablePictureVerticalDimension() const;

        UINT8 GetUserPromptIndicatorNumberCorrespondingObjects() const;

        UINT8 * GetWirelessControlMessageProtocolBuffer() const;
        UINT8 GetWirelessControlMessageProtocolLength() const;

        UINT8 GetRfc822EmailHeaderLength() const;

        UINT16 GetHyperlinkFormatElementAbsolutStartPosition() const;
        UINT8 GetHyperlinkFormatElementTitelLength() const;
        UINT8 GetHyperlinkFormatElementUrlLength() const;

        BOOLEAN PutExtendedObject(UINT16 startpos, 
                                  UINT8 ref_no, 
                                  BOOLEAN may_be_forw, 
                                  BOOLEAN handled_as_user_prompt,
                                  InformationElement::ExtendedObjectType type,
                                  UINT8 length,
                                  UINT16 complete_length,
                                  const UINT8* extended_object_buffer);

        BOOLEAN PutContinuedExtendedObject(UINT8 length,
                                           const UINT8* extended_object_buffer);

        UINT8   GetExtendedObjectReferenceNumber() const;
        UINT16  GetExtendedObjectLength() const;
        BOOLEAN GetExtendedObjectControlDataMayBeForw() const;
        BOOLEAN GetExtendedObjectControlDataUserPrompt() const;
        InformationElement::ExtendedObjectType GetExtendedObjectType() const;
        UINT16  GetExtendedObjectPosition() const;
        UINT8*  GetExtendedObjectBuffer() const;
        BOOLEAN PutReusedExtendedObject(UINT16 startpos, UINT8 ref_no);
        UINT8   GetReusedExtendedObjectReferenceNumber() const;
        UINT16  GetReusedExtendedObjectPosition() const;

    private:
        UINT8   *m_anchor;
};

BOOLEAN InfoElementTestSuite(); 


#endif  // Apc_InformationElement_hpp


