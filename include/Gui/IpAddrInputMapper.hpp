/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IpAddrInputMapper_hpp)
#define Apoxi_IpAddrInputMapper_hpp

#include <Gui/NumericInputMapper.hpp>

class IpAddrEditor;

class IpAddrInputMapper : public NumericInputMapper {
    typedef NumericInputMapper Base;

    public:
        explicit IpAddrInputMapper(BOOLEAN highlight_field = FALSE);

        virtual ~IpAddrInputMapper();

        virtual void SetEditor(AbstractEditor* editor);

        virtual INT GetId() const;

        virtual Alphabet GetAlphabet() const;

    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        virtual void OnGetFocus();
        
        virtual void OnLoseFocus();


    private:
        void DeleteItem(INT index);
        void UpdateFieldHighlight();

        BOOLEAN m_highlight_field;
};

#endif  // Apoxi_IpAddrInputMapper_hpp


