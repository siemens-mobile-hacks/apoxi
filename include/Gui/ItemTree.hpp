/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ItemTree_hpp)
#define Apoxi_ItemTree_hpp

#include <Kernel/Timer.hpp>
#include <Gui/AbstractItemGrid.hpp>
#include <Gui/ItemContainer.hpp>

class ItemTree : public AbstractItemGrid {
    typedef AbstractItemGrid Base;

    public:
        enum {
            ID = 14
        };

        //
        ItemTree();

        ItemTree(Control* parent, AbstractItemContainer* item_cont = 0);

        virtual ~ItemTree();

        void Init(Control* parent, AbstractItemContainer* item_cont = 0);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual INT GetColumnCount() const;

        virtual BOOLEAN Trigger(INT index = -1);

        virtual AbstractItemContainer* GetItemContainer() const;

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual Rect GetItemRect(INT item_index) const;

        virtual void DrawItemBorder(DeviceContext* dc,
                                    const Rect& cell_rect,
                                    const Rect& item_rect,
                                    INT item_index) const;

        virtual void Refresh(const Rect& rect);
        
        virtual void Cleanup();

    private:
        AbstractItemContainer* m_root_cont;
        ItemContainer m_view_cont;
        Vector<INT> m_level;

        void ToggleItemContainer(INT index);

        BOOLEAN AddItemToView(Item* item);
        BOOLEAN InsertItemToView(INT index, Item* item);
        BOOLEAN RemoveItemFromView(INT index);
        void RemoveAllItemsFromView();
        void CopyRootItemsToView();
};

#endif  // Apoxi_ItemTree_hpp


