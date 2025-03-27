/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextMenuAccessor_hpp)
#define Apoxi_TextMenuAccessor_hpp

#include <Gui/AbstractMenuAccessor.hpp>
#include <Gui/MenuTextPtrArrayIterator.hpp>     // included for backward-compatibility for APOXI-versions < 1.6 

class Dispatcher;

class TextMenuAccessor : public AbstractMenuAccessor {
    typedef AbstractMenuAccessor Base;

    public:
        TextMenuAccessor();

        TextMenuAccessor(Dispatcher* dispatcher, const MenuTextIterator* iterator);

        virtual ~TextMenuAccessor();

        void Init(Dispatcher* dispatcher, const MenuTextIterator* iterator);

        virtual BOOLEAN First();

        virtual BOOLEAN Next();

        virtual XYDIM GetItemHeight() const;

        virtual void Draw(DeviceContext* dc, const Rect& draw_rect, BOOLEAN highlighted);

        virtual void Trigger(Menu* menu);

        virtual void Back(Menu* menu);

        TextMenuAccessor(const MenuTextIterator* iterator);

        void Init(const MenuTextIterator* iterator);

    private:
        INT m_idx;
        Dispatcher* m_dispatcher;
        const MenuTextIterator* m_iterator;
};

#endif  // Apoxi_TextMenuAccessor_hpp


