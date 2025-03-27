/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AtomItem_hpp)
#define Apoxi_AtomItem_hpp

#include <Gui/AbstractEditorItem.hpp>

class DeviceContext;

class AtomItem : public AbstractEditorItem {
    typedef AbstractEditorItem Base;

    public:
        enum {
            ID = 0
        };

        AtomItem();

        virtual ~AtomItem();

        virtual INT GetId() const;

        virtual void Draw(DeviceContext* dc, const Rect& bounds) const = 0;

        virtual AtomItem* Clone() const = 0;

        virtual BOOLEAN IsInstanceOf(INT id) const;
};

#endif  // Apoxi_AtomItem_hpp


