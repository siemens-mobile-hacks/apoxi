/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_VCardItem_hpp)
#define Apoxi_VCardItem_hpp

#include <AddOns/MultiMedia/BoundedItem.hpp>
#include <Auxiliary/VCard.hpp>

class VCardItem : public BoundedItem {
    typedef BoundedItem Base;

    public:
        enum {
            ID = 14
        };

        explicit VCardItem(const VCard& vcard);
        virtual ~VCardItem();

        virtual INT GetId() const;

        virtual XYDIM GetWidth() const;

        virtual XYDIM GetHeight() const;

        virtual void Draw(DeviceContext* dc, const Rect& bounds) const;

        const VCard& GetVCard() const { return m_vcard; }

        virtual AtomItem* Clone() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;
    
    private:
        VCard m_vcard;
};

#endif  // Apoxi_VCardItem_hpp

