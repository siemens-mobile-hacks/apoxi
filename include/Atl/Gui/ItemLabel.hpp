/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_ItemLabel_hpp)
#define Atl_Gui_ItemLabel_hpp

#include <Gui/DrawableObject.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Gui/Color.hpp>
#include <Gui/ImageBox.hpp>
#endif  // APOXI_COMPAT_2_7_0

class ItemRendererProperties;
class AbstractItemRenderer;


class ItemLabel : public DrawableObject {
    typedef DrawableObject Base;

    public:     
        ItemLabel();

        ItemLabel(Control *control, const Item& item, BOOLEAN auto_draw = TRUE);

        virtual ~ItemLabel();

        void Init(Control *control);

        void Init(Control *control, const Item& item, BOOLEAN auto_draw = TRUE);

        void SetItem(const Item& item) { m_item = item; };

        const Item& GetItem() const { return m_item; }

        void SetRenderer(const ItemRendererProperties* properties = 0);

        AbstractItemRenderer* GetRenderer() const { return m_renderer; }

    private:
        void SetDefaults();

        Item m_item;    

        AbstractItemRenderer* m_renderer;
        const ItemRendererProperties* m_renderer_properties;
};

class ItemLabelView : public DrawableObjectView {
    
    typedef DrawableObjectView Base;

    public:
        ItemLabelView();
        virtual ~ItemLabelView();

        virtual void Draw(const Component &component, 
                          DeviceContext *dc, 
                          const Rect &repaint_rect) const;
};

#endif  // Atl_Gui_ItemLabel_hpp

