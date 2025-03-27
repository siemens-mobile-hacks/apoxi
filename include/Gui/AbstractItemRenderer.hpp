/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractItemRenderer_hpp)
#define Apoxi_AbstractItemRenderer_hpp

#include <Kernel/Timer.hpp>
#include <Gui/AbstractGrid.hpp>
#include <Gui/Item.hpp>
#include <Auxiliary/Vector.hpp>
#include <Gui/ItemContainer.hpp>
#include <Gui/ItemRendererProperties.hpp>

class AbstractItemRenderer {
    public:
        enum ItemStyle {
            DefaultStyle            = 0,
            SelectedStyle           = 1,
            HeaderStyle             = 2,
            AnimatedStyle           = 3,
            CustomStyle             = 100
        };

        AbstractItemRenderer(const ItemRendererProperties* properties = 0);

        virtual ~AbstractItemRenderer();

        const ItemRendererProperties* GetProperties() const { return m_properties; }

        virtual Rect GetIconRect(const Item& item, const Rect& bounds) const = 0;

        virtual XYDIM GetItemHeight(INT item_style = DefaultStyle) const = 0;

        virtual void DrawBackground(DeviceContext* dc,
                                    const Item& item,
                                    const Rect& bounds,
                                    INT item_style) const = 0;

        virtual void DrawItem(DeviceContext* dc,
                              const Item& item,
                              const Rect& bounds,
                              INT item_style) const = 0;

        virtual BOOLEAN StartTextScrolling(const Item& item, const Rect& bounds) const;
        
        virtual void StopTextScrolling(const Item& item) const;

        virtual BOOLEAN ScrollText() const;
        
        virtual IconState::Size GetIconSizeState(INT item_style = DefaultStyle) const;

    protected:
        void SetProperties(const ItemRendererProperties* properties) { m_properties = properties; }

    private:
        const ItemRendererProperties* m_properties;
};

#endif  // Apoxi_AbstractItemRenderer_hpp

