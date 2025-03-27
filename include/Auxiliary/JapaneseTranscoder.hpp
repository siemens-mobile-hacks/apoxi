/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_JapaneseTranscoder_hpp)
#define Apoxi_JapaneseTranscoder_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/WString.hpp>

class JapaneseTranscoder {
    public:
        enum EncodingType {
            Auto = 0,
            Sjis = 1,
            Jis = 2,
            Euc = 3,
            Ucs2 = 4
        };

        static const JapaneseTranscoder& GetInstance();
        
        ~JapaneseTranscoder();  // non-virtual
        
        Vector<UINT8> Convert(const UINT8* text,
                              INT text_len,
                              EncodingType to_encoding,
                              BOOLEAN* success = 0,
                              EncodingType from_encoding = Auto) const;
        
        EncodingType DetectEncoding(const UINT8* text, INT text_len) const;
        
    private:
        JapaneseTranscoder();

#if defined(APOXI_ENABLE_JAPANESE_TRANSCODER)
        // Internal enum used for converting and escape sequence detection
        enum JisEncodingMode {
            None,
            Ascii,          // ASCII (1 byte/char)
            JisRoman,       // JIS-Roman (1 byte/char)
            JisC6226_1978,  // JIS C 6226-1978 (2 bytes/char)
            JisX0208_1983,  // JIS X 0208-1983 (2 bytes/char)
            JisX0212_1990,  // JIS X 0212-1990 (2 bytes/char)
            JisX0208_1997,  // JIS X 0208-1997 (2 bytes/char)
            Jis7Katakana    // RCR STD Katakana 7bit code for halfwidth katakanas in JIS
        };

        Vector<UINT8> SjisToJis(const Vector<UINT8>& text) const;
        Vector<UINT8> SjisToEuc(const Vector<UINT8>& text) const;
        Vector<UINT8> SjisToUcs2(const Vector<UINT8>& text) const;
        
        Vector<UINT8> EucToSjis(const Vector<UINT8>& text) const;
        Vector<UINT8> EucToJis(const Vector<UINT8>& text) const;
        
        Vector<UINT8> JisToSjis(const Vector<UINT8>& text) const;
        Vector<UINT8> JisToEuc(const Vector<UINT8>& text) const;
        
        Vector<UINT8> Ucs2ToSjis(const Vector<UINT8>& text) const;
        
        BOOLEAN IsSjisMultiByteChar(UINT16 sjis_char) const;
        void ConvertSingleByteSjisCharToUcs2Char(UINT8 sjis_char, UINT16* ucs2_char_p) const;
        void ConvertMultiByteSjisCharToUcs2Char(UINT16 sjis_char, UINT16* ucs2_char_p) const;
        void ConvertUcs2CharToSjisChar(UINT16 unicode_char, UINT16* sjis_char_p) const;

        INT GetJisEscapeSequenceLength(const Vector<UINT8>& text, 
                                       INT start_pos, 
                                       JisEncodingMode* detected_sequence) const;
#endif      
};

#endif

