/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractItemContainer_hpp)
#define Apoxi_AbstractItemContainer_hpp

class ItemRendererProperties;
#include <Gui/Item.hpp>

class AbstractItemContainer : public Item {
    typedef Item Base;

    public:
        enum {
            ID = 2
        };

        enum AbstractItemContainerPropertyId {
            ItemPropertyId = 4,
            RendererPropertyId = 5,
        };

        AbstractItemContainer();

        AbstractItemContainer(Dispatcher* dispatcher,
                      const WCHAR* text,
                      const BitmapRes* icon = 0,
                      BOOLEAN enabled = TRUE);

        AbstractItemContainer(Dispatcher* dispatcher,
                      const WString& text,
                      const BitmapRes* icon = 0,
                      BOOLEAN enabled = TRUE);

        AbstractItemContainer(Dispatcher* dispatcher,
                      const WString& text,
                      const ImageObtainer& icon,
                      BOOLEAN enabled = TRUE);

        AbstractItemContainer(Dispatcher* dispatcher,
                              const WString& text,
                              const IconSet& icon_set,
                              BOOLEAN enabled = TRUE);

        virtual ~AbstractItemContainer();

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

        virtual BOOLEAN AddItem(Item* item) = 0;

        virtual BOOLEAN InsertItem(INT index, Item* item) = 0;

        virtual BOOLEAN RemoveItem(INT index) = 0;

        virtual BOOLEAN RemoveAllItems() = 0;

        virtual Item* GetItem(INT index) const = 0;

        virtual INT GetItemIndex(const Item& item) const = 0;

        virtual INT GetItemCount() const = 0;

        BOOLEAN ContainsItem(const Item& item) const;

        virtual BOOLEAN SetParentContainer(AbstractItemContainer* container) = 0;

        virtual AbstractItemContainer* GetParentContainer() = 0;
        
        virtual BOOLEAN SetRendererProperties(const ItemRendererProperties* properties);
        
        virtual const ItemRendererProperties* GetRendererProperties() const;
};
 
#endif  // Apoxi_Item_hpp

