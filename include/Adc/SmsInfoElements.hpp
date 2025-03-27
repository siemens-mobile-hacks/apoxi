/* =============================================================================
** Copyright (C) 2001 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

// =============================================================================
//
//                              includes
//
// =============================================================================
#if !defined(Adc_SmsInfoelements_hpp)
#define Adc_SmsInfoelements_hpp

#ifdef HARRY
/*------------------------------------------------------------------
        Concatenated short messages, 16-bit and 8-bit reference number
 ------------------------------------------------------------------*/
class ConcatInfoElement16Bit
{
    public:
        ConcatInfoElement16Bit(InformationElement * info_element);
        ~ConcatInfoElement16Bit() {};
        inline INT GetReferenceNumber() const {return m_reference_number;};
        inline INT GetMaxNumberOfSms() const {return m_max_number_of_sms;};
        inline INT GetSequenceNumber() const {return m_sequence_number;};

    private:
        INT m_reference_number;
        INT m_max_number_of_sms;
        INT m_sequence_number;

};

class ConcatInfoElement8Bit
{
    public:
        ConcatInfoElement8Bit(InformationElement * info_element);
        ~ConcatInfoElement8Bit() {};
        inline INT GetReferenceNumber() { return m_reference_number;};
        inline INT GetMaxNumberOfSms() {return m_max_number_of_sms;};
        inline INT GetSequenceNumber() {return m_sequence_number;};

    private:
        INT m_reference_number;
        INT m_max_number_of_sms;
        INT m_sequence_number;

};


/*------------------------------------------------------------------
        Text Formatting
 ------------------------------------------------------------------*/

class EmsTextFormatting
{
    public:
        EmsTextFormatting(InformationElement * info_element);
        ~EmsTextFormatting() {};
        inline INT GetStartPos() const {return m_start_pos;};
        inline INT GetFormattingLength() const {return m_formatting_length;};
        inline EmsTextAlignment GetAlignment() const {return (EmsTextAlignment)(m_formatting_mode & 0x3);};
        inline EmsTextFontSize GetFontSize() const {return (EmsTextFontSize)((m_formatting_mode & 0xC) >> 2);};
        inline EmsStyleStatus GetFontStyleBold() const {return (EmsStyleStatus)(m_formatting_mode & 0x10);};
        inline EmsStyleStatus GetFontStyleItalic() const {return (EmsStyleStatus)(m_formatting_mode & 0x20);};
        inline EmsStyleStatus GetFontStyleUnderlined() const {return (EmsStyleStatus)(m_formatting_mode & 0x40);};
        inline EmsStyleStatus GetFontStyleStrikethrough() const {return (EmsStyleStatus)(m_formatting_mode & 0x80);};


    private:
        INT m_start_pos;
        INT m_formatting_length;
        INT m_formatting_mode;

};


/*------------------------------------------------------------------
        Predefined Sound
 ------------------------------------------------------------------*/
class EmsPredefinedSound
{
    public:
        EmsPredefinedSound(InformationElement * info_element);
        ~EmsPredefinedSound() {};
        inline INT GetStartPos() const {return m_start_pos;};
        inline INT GetSoundNumber() const {return m_sound_number;};

    private:
        INT m_start_pos;
        INT m_sound_number;

};


/*------------------------------------------------------------------
        Predefined Animation
 ------------------------------------------------------------------*/
class EmsPredefinedAnimation
{
    public:
        EmsPredefinedAnimation(InformationElement * info_element);
        ~EmsPredefinedAnimation() {};
        inline INT GetStartPos() const {return m_start_pos;};
        inline INT GetAnimationNumber() const {return m_animation_number;};

    private:
        INT m_start_pos;
        INT m_animation_number;
};


/*------------------------------------------------------------------
        Small Picture
 ------------------------------------------------------------------*/
class EmsSmallPicture
{
    public:
        EmsSmallPicture(InformationElement * info_element);
        virtual ~EmsSmallPicture() {};
        inline INT GetStartPos() const {return m_start_pos;};
        inline const UINT8* GetPictureData() const {return m_picture_data;};

    private:
        INT    m_start_pos;
        const UINT8 *m_picture_data;
};

/*------------------------------------------------------------------
        Variable Picture
 ------------------------------------------------------------------*/
class EmsVariablePicture
{
    public:
        EmsVariablePicture(InformationElement * info_element);
        virtual ~EmsVariablePicture() {};

        inline INT GetStartPos() const {return m_start_pos;};
        inline INT GetHorizontalDim() const {return m_horizontal_dim;};
        inline INT GetVerticalDim() const {return m_vertical_dim;};
        inline const UINT8* GetPictureData() const {return m_picture_data;};

    private:
        INT    m_start_pos;
        INT    m_horizontal_dim;
        INT    m_vertical_dim;
        const UINT8 *m_picture_data;

};

/*------------------------------------------------------------------
        InfoElementParser
 ------------------------------------------------------------------*/
class InfoElementParser
{
    public:
        InfoElementParser(UserDataHeader udh);
        ~InfoElementParser() {};

        BOOLEAN FindInfoElement(InformationElementIdentifier info_elment_id);
        InformationElementIdentifier GetInformationElementIdentifier();
        BOOLEAN NextInformationElement();
        InformationElement GetInformationElement();

    private:
        UserDataHeader m_udh;
        INT            m_offset;

};

#endif

#endif;


