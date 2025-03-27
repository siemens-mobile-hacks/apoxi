/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_OpenContextMenuAction_hpp)
#define Apoxi_OpenContextMenuAction_hpp

class AbstractItemContainer;

#include <Gui/Action.hpp>
#include <Gui/ContextMenu.hpp>

class OpenContextMenuAction : public Action {
    typedef Action Base;

    public:
        OpenContextMenuAction();

        OpenContextMenuAction(Dispatcher* dispatcher,
                              const WString& text,
                              const ImageObtainer& icon,
                              BOOLEAN enabled = TRUE,
                              AbstractItemContainer* item_cont = 0,
                              ContextMenu::Corner corner = ContextMenu::BottomLeft,
                              XYDIM x = -1,
                              XYDIM y = -1);

        OpenContextMenuAction(Dispatcher* dispatcher,
                              const WString& text,
                              AbstractItemContainer* item_cont = 0,
                              ContextMenu::Corner corner = ContextMenu::BottomLeft,
                              XYDIM x = -1,
                              XYDIM y = -1);

        virtual ~OpenContextMenuAction();

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const ImageObtainer& icon,
                  BOOLEAN enabled = TRUE,
                  AbstractItemContainer* item_cont = 0,
                  ContextMenu::Corner corner = ContextMenu::BottomLeft,
                  XYDIM x = -1,
                  XYDIM y = -1);


        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  AbstractItemContainer* item_cont = 0,
                  ContextMenu::Corner corner = ContextMenu::BottomLeft,
                  XYDIM x = -1,
                  XYDIM y = -1);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        AbstractItemContainer* GetItemContainer() const { return m_item_cont; }

        BOOLEAN AddItem(Item* item);

        virtual BOOLEAN Execute();

    private:
        BOOLEAN m_allocated_item_cont;
        ContextMenu::Corner m_corner;
        XYDIM m_x;
        XYDIM m_y;
        AbstractItemContainer* m_item_cont;
};

#endif  // Apoxi_OpenContextMenuAction_hpp


