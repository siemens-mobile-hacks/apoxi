/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CompoundItem_hpp)
#define Apoxi_CompoundItem_hpp

class AtomItem;

#include <Gui/AbstractEditorItem.hpp>
#include <Gui/EditorDocument.hpp>

class CompoundItem : public AbstractEditorItem {
    public:
        enum {
            ID = 1
        };

        virtual ~CompoundItem();

        virtual void ReleaseInstance();

        virtual INT GetId() const;

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const = 0;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const = 0;

        virtual XYDIM GetLineWidth(INT index, INT count) const = 0;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const = 0;

        virtual INT GetItemCount() const = 0;

        virtual BOOLEAN InsertItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN ReplaceItem(const AtomItem& item, INT index = -1);

        virtual BOOLEAN RemoveItem(INT index = -1);

        virtual BOOLEAN Split(INT index, CompoundItem** compound_item);

        virtual BOOLEAN Merge(const CompoundItem& compound_item);

        virtual CompoundItem* Clone() const;

        virtual void Clear();

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        CompoundItem();
};

#endif  // Apoxi_CompoundItem_hpp

