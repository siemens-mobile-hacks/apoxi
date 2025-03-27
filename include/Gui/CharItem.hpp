/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CharItem_hpp)
#define Apoxi_CharItem_hpp

#include <Gui/AtomItem.hpp>

class CharItem : public AtomItem {
    typedef AtomItem Base;

    public:
        enum {
            ID = 2
        };

        CharItem();

        explicit CharItem(WCHAR c) : m_char(c) {}

        virtual ~CharItem();

        virtual INT GetId() const;

        WCHAR GetChar() const { return m_char; }

        CharItem& operator=(WCHAR c) { m_char = c; return* this; }

        operator WCHAR () const { return m_char; }  //lint !e1930

        virtual void Draw(DeviceContext* dc, const Rect& bounds) const;

        virtual AtomItem* Clone() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

    private:
        WCHAR m_char;
};  //lint !e1721

#endif  // Apoxi_CharItem_hpp


