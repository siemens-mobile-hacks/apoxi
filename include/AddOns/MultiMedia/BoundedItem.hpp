/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BoundedItem_hpp)
#define Apoxi_BoundedItem_hpp

#include <Gui/AtomItem.hpp>

class BoundedItem : public AtomItem {
    typedef AtomItem Base;

    public:
        enum {
            ID = 3
        };

        BoundedItem();

        virtual ~BoundedItem();

        virtual INT GetId() const;

        virtual XYDIM GetWidth() const = 0;

        virtual XYDIM GetHeight() const = 0;

        virtual BOOLEAN IsInstanceOf(INT id) const;
};

#endif  // Apoxi_BoundedItem_hpp


