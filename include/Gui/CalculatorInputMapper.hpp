/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CalculatorInputMapper_hpp)
#define Apoxi_CalculatorInputMapper_hpp

#include <Gui/NumericInputMapper.hpp>

class CalculatorInputMapper : public NumericInputMapper {
    typedef NumericInputMapper Base;

    public:
        explicit CalculatorInputMapper();
        virtual ~CalculatorInputMapper();

        virtual INT GetId() const;

        virtual Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
};

#endif  // Apoxi_CalculatorInputMapper_hpp


