/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MenuTextPtrArrayIterator_hpp)
#define Apoxi_MenuTextPtrArrayIterator_hpp

#include "MenuTextIterator.hpp"

class MenuTextPtrArrayIterator : public MenuTextIterator {
    public:
        MenuTextPtrArrayIterator(INT item_count = 0, const WCHAR* *menu_text = 0);

        void Init(INT item_count, const WCHAR* *menu_text);

        virtual INT ItemCount() const;

        virtual const WCHAR* operator()(INT idx) const;

    private:
        INT m_item_count;
        const WCHAR* *m_menu_text;      
};

#endif  // Apoxi_MenuTextPtrArrayIterator_hpp


