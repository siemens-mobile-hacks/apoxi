/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsTextParser_hpp)
#define Mmi_SmsTextParser_hpp

enum SmsTextItemType {
    SmsTextItemType_PhoneNumber,
    SmsTextItemType_Url,
    SmsTextItemType_Email
};

struct SmsTextEntry {
    INT         idxPos; 
    SmsTextItemType type;
    WString         text;
};

class SmsTextParser {
    struct SmsTextItemAttributes {
        INT phoneNrType;
        INT colonPos;
        INT firstSlashPos;
        INT secondSlashPos;
        INT atPos;
        INT firstPeriodPos;
        INT secondPeriodPos;
        INT lastPeriodPos;
    };

    public:

        virtual ~SmsTextParser();
        void Scan(const WString& text);
        
        INT GetItemCount() const;
        
        const SmsTextEntry& GetItem(const INT index) const;
    private:
        void SkipSpaces();
        
        void ParseWordAndFillTextItemAttributes();
        
        void GenerateTextEntryBasedOnTextItemAttributes();

        const WString* m_pSmsText;
        INT m_textPosition;
        WString m_currentWord;
        INT m_wordPosition;
        SmsTextItemAttributes m_textItemAttrib;
        Vector<SmsTextEntry> m_textEntries;
};

#endif  // Mmi_SmsTextParser_hpp
