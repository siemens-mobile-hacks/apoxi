/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ItemBox_hpp)
#define Apoxi_ItemBox_hpp

class ItemRendererProperties;
class AbstractItemRenderer;
class Item;
#include <Gui/DrawableObject.hpp>
#include <Auxiliary/TriggerTimer.hpp>

class ItemBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        ItemBoxView();
        virtual ~ItemBoxView();
        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;
    
    private:
        void DrawImage(DeviceContext* dc,
                       const Item& item,
                       const Rect& bounds) const;
};

class ItemBox : public DrawableObject {
    typedef DrawableObject Base;

    public:
        enum {
            ID = 37
        };

        ItemBox();
        
        ItemBox(Control* control, 
                Item* item);

        virtual ~ItemBox();

        void Init(Control* control,
                  Item* item);

        Item* GetItem() const { return m_item; }

        void SetRenderer(const ItemRendererProperties* properties = 0);

        const AbstractItemRenderer* GetRenderer() const { return m_renderer; }

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual XYDIM GetDefaultWidth() const;

        virtual XYDIM GetDefaultHeight() const;
        
    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();

        virtual void OnResize(XYDIM dx, XYDIM dy);

    private:
        friend class TriggerTimer<ItemBox>;

        Item* m_item;
        AbstractItemRenderer* m_renderer;
        TriggerTimer<ItemBox> m_timer;

        static ItemBoxView m_view;

        void InitProperties(Item* item);

        BOOLEAN UseImageSize() const;

        void OnTimer();

        void StartTextScrolling();
};

#endif  // Apoxi_ItemBox_hpp


