/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NumericInputMapper_hpp)
#define Apoxi_NumericInputMapper_hpp

#include <Gui/InputMapper.hpp>

class NumericInputMapper : public InputMapper {
    typedef InputMapper Base;

    public:
        explicit NumericInputMapper();
        virtual ~NumericInputMapper();

        virtual INT GetId() const;

        virtual Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
};

#endif  // Apoxi_NumericInputMapper_hpp


