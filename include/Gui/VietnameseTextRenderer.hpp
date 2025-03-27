/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_VietnameseTextRenderer_hpp)
#define Apoxi_VietnameseTextRenderer_hpp

#include <Gui/AbstractTextRenderer.hpp>

class VietnameseTextRenderer : public AbstractTextRenderer {
    typedef AbstractTextRenderer Base;

    public:
        virtual ~VietnameseTextRenderer();

        static VietnameseTextRenderer& GetInstance();

        virtual BOOLEAN IsStandaloneCharacter(const WCHAR* text,
                                              INT index);
        
    protected:
        VietnameseTextRenderer();

        virtual Size GetGlyph(const WCHAR* cur_text_pos,
                              const WCHAR* substitution_char,
                              INT n_chars,
                              GlyphPtr glyph,
                              INT& parsed_glyphs,
                              BOOLEAN& is_diacritic);

    private:
        enum VietnameseCharacterType {
            Diacritic,              
            DiacriticBreve,         // can only be combined with a
            DiacriticCircumflex,    // can only be combined with a, e, and o
            DiacriticHorn,          // can only be combined with o and u

            ToneMark,
            ToneMarkGrave,
            ToneMarkAcute,
            ToneMarkTilde,
            ToneMarkHookAbove,
            ToneMarkDotBelow,

            Vowel,
            VowelA,
            VowelE,
            VowelI,
            VowelO,
            VowelU,
            VowelY,

            TonemarkCombinableVowel,    // vowels already combined with diacritic, as well as y and i (which cannot be combined with diacritics)
            TonemarkCombinableVowelA,
            TonemarkCombinableVowelE,
            TonemarkCombinableVowelO,
            TonemarkCombinableVowelU,

            DiacriticCombinableVowel,   // vowels a, e, o, u already combined with tonemark (another tone mark is not possible, only a (specific, depending on the vowel) diacritic)
            DiacriticCombinableVowelA,
            DiacriticCombinableVowelE,
            DiacriticCombinableVowelO,
            DiacriticCombinableVowelU,
            
            None                        // used for non-vowels and vowels with both diacritic and tone mark, as well as i and y with tonemark, and non-combinable characters
        };
        
        BOOLEAN GetCombinedCharacter(const WCHAR* cur_char, const WCHAR* next_char, WCHAR& combined_char, BOOLEAN& syntax_valid);

        VietnameseCharacterType GetCharacterType(const WCHAR* ch,
                                                 VietnameseCharacterType& specific_type, 
                                                 VietnameseCharacterType& modifier_type,
                                                 BOOLEAN& is_capital_letter) const;
};


#endif // Apoxi_VietnameseTextRenderer_hpp

