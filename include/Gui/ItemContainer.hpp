/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ItemContainer_hpp)
#define Apoxi_ItemContainer_hpp

#include <Gui/AbstractItemContainer.hpp>

class ItemContainer : public AbstractItemContainer {
    typedef AbstractItemContainer Base;

    public:
        enum {
            ID = 3
        };

        ItemContainer();

        ItemContainer(Dispatcher* dispatcher,
                      const WCHAR* text,
                      const BitmapRes* icon = 0,
                      BOOLEAN enabled = TRUE);

        ItemContainer(Dispatcher* dispatcher,
                      const WString& text,
                      const BitmapRes* icon = 0,
                      BOOLEAN enabled = TRUE);

        ItemContainer(Dispatcher* dispatcher,
                      const WString& text,
                      const ImageObtainer& icon,
                      BOOLEAN enabled = TRUE);

        ItemContainer(Dispatcher* dispatcher,
                      const WString& text,
                      const IconSet& icon_set,
                      BOOLEAN enabled = TRUE);

        virtual ~ItemContainer();

        void Init(Dispatcher* dispatcher,
                  const WCHAR* text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const ImageObtainer& icon,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const IconSet& icon_set,
                  BOOLEAN enabled = TRUE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual BOOLEAN AddItem(Item* item);

        virtual BOOLEAN InsertItem(INT index, Item* item);

        virtual BOOLEAN RemoveItem(INT index);

        virtual BOOLEAN RemoveAllItems();

        virtual Item* GetItem(INT index) const;

        virtual INT GetItemIndex(const Item& item) const;

        virtual INT GetItemCount() const;

        virtual BOOLEAN SetParentContainer(AbstractItemContainer* container);

        virtual AbstractItemContainer* GetParentContainer();

        virtual BOOLEAN SetRendererProperties(const ItemRendererProperties* properties);

        virtual const ItemRendererProperties* GetRendererProperties() const;
        
        virtual BOOLEAN IsEnabled() const;

    private:
        Vector<Item*> m_item_vec;
        AbstractItemContainer* m_parent_container;
        const ItemRendererProperties* m_renderer_properties;
        
        BOOLEAN IsValidIndex(INT index) const;
};
 
#endif  // Apoxi_Item_hpp

