/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DateTimeInputMapper_hpp)
#define Apoxi_DateTimeInputMapper_hpp

#include <Gui/NumericInputMapper.hpp>

class DateTimeInputMapper : public NumericInputMapper {
    typedef NumericInputMapper Base;

    public:
        explicit DateTimeInputMapper(BOOLEAN date_mode = TRUE,
                                     BOOLEAN highlight_field = FALSE);

        virtual ~DateTimeInputMapper();

        virtual void SetEditor(AbstractEditor* editor);

        virtual INT GetId() const;

        virtual Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnGetFocus();
        
        virtual void OnLoseFocus();

    private:
        BOOLEAN m_date_mode;
        BOOLEAN m_highlight_field;

        void UpdateFieldHighlight();
};

#endif  // Apoxi_DateTimeInputMapper_hpp


