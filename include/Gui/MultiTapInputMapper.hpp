/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MultiTapInputMapper_hpp)
#define Apoxi_MultiTapInputMapper_hpp

#include <Gui/InputMapper.hpp>
#include <Auxiliary/TriggerTimer.hpp>

class MultiTapInputMapper : public InputMapper {
    typedef InputMapper Base;
    
    public:
        enum CapitalizationMode {
            UserTriggeredCapitalization,
            AutoCapitalization,
            NameCapitalization
        };

        explicit MultiTapInputMapper(BOOLEAN show_preview = TRUE,
                                     Alphabet alphabet = InputMapper::Ucs2Alphabet,
                                     CapitalizationMode capitalization_mode = UserTriggeredCapitalization);

        virtual ~MultiTapInputMapper();
        
        virtual void SetEditor(AbstractEditor* editor);

        virtual INT GetId() const;

        virtual Caret* GetCaret();

        virtual Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
        
    private:
        friend class TriggerTimer<MultiTapInputMapper>;
        
        struct {
            UINT uppercase            : 1;
            UINT show_preview         : 1;
            UINT alphabet             : 2;
            UINT tab_index            : 8;
            UINT punctuation_found    : 1;
            UINT switch_to_upper      : 1;
            UINT capitalization_mode  : 3;
        } m_bits;

        TriggerTimer<MultiTapInputMapper> m_timer;
        
        void OnTimer();
        Alphabet GetCharacterAlphabet(WCHAR chr) const;
};

#endif  // Apoxi_MultiTapInputMapper_hpp

