/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GeneralCompoundItem_hpp)
#define Apoxi_GeneralCompoundItem_hpp

#include <Gui/CompoundItem.hpp>
#include <Auxiliary/Vector.hpp>
#include <AddOns/MultiMedia/BoundedItem.hpp>

class GeneralCompoundItem : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 12
        };

        static GeneralCompoundItem* CreateInstance();

        virtual ~GeneralCompoundItem();

        virtual INT GetId() const;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual const AtomItem* GetItem(INT index) const;

        virtual BOOLEAN Split(INT index, CompoundItem* *compound_item);

        virtual BOOLEAN Merge(const CompoundItem& compound_item);

        virtual CompoundItem* Clone() const;

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;

        virtual INT GetItemCount() const;

        virtual void Clear();

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        GeneralCompoundItem();

    private:
        Vector<const BoundedItem*> m_editor_item_vector;
};

#endif  // Apoxi_GeneralCompoundItem_hpp

