/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ContextMenu_hpp)
#define Apoxi_ContextMenu_hpp

class AbstractItemContainer;
class Item;
class ItemRendererProperties;
class AbstractItemRenderer;

#include <Gui/Window.hpp>
#include <Gui/Action.hpp>
#include <Gui/ItemGrid.hpp>

class ContextMenu : public Window {
    typedef Window Base;

    public:
        enum {
            ID = 8
        };

        enum Corner {
            TopLeft,
            TopRight,
            BottomLeft,
            BottomRight
        };
        
        ContextMenu(XYDIM x,
                    XYDIM y,
                    Corner corner = TopLeft,
                    AbstractItemContainer* item_cont = 0,
                    ContextMenu* parent_menu = 0);

        /*  Constructor used by Aragon to create the instance out of a resource file.
            This constructor may not be used by the MMI in a direct manner
            and the interface may be changed in future releases. */
        ContextMenu();

        virtual ~ContextMenu();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        void SetRenderer(const ItemRendererProperties* properties = 0);

        const AbstractItemRenderer* GetRenderer() const;

        BOOLEAN AddItem(Item* item);

        AbstractItemContainer* GetItemContainer() const;

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);
        
        virtual void OnActionExecuted(Action* action);

        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

    private:
        Corner m_corner;
        XYDIM m_x;
        XYDIM m_y;
        ContextMenu* m_parent_menu;
        ContextMenu* m_child_menu;
        ItemGrid m_item_grid;
        Action m_select_action;
        Action m_cancel_action;

        XYDIM GetItemHeight() const;

        void AdjustBounds(XYDIM& x, XYDIM& y, XYDIM& width, XYDIM& height) const;
};

#endif  // Apoxi_ContextMenu_hpp


