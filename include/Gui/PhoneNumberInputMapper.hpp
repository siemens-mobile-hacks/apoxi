/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PhoneNumberInputMapper_hpp)
#define Apoxi_PhoneNumberInputMapper_hpp

#include <Gui/NumericInputMapper.hpp>

class PhoneNumberInputMapper : public NumericInputMapper {
    typedef NumericInputMapper Base;

    public:
        explicit PhoneNumberInputMapper();
        virtual ~PhoneNumberInputMapper();

        virtual INT GetId() const;

        virtual Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual BOOLEAN OnLongKeyPress(KeyCode key_code);
        
    private:        
        void InsertChar(WCHAR chr);
        void ReplaceChar(WCHAR chr);
};

#endif  // Apoxi_PhoneNumberInputMapper_hpp


