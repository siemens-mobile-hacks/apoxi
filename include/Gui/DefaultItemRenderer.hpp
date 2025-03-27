/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultItemRenderer_hpp)
#define Apoxi_DefaultItemRenderer_hpp

class ItemRendererProperties;
class PaintDc;
#include <Kernel/Timer.hpp>
#include <Gui/AbstractItemRenderer.hpp>

class DefaultItemRenderer : public AbstractItemRenderer {
    typedef AbstractItemRenderer Base;

    public:
        DefaultItemRenderer(const ItemRendererProperties* properties = 0);

        virtual ~DefaultItemRenderer();

        virtual Rect GetIconRect(const Item& item, const Rect& bounds) const;

        virtual XYDIM GetItemHeight(INT item_style = DefaultStyle) const;

        virtual void DrawBackground(DeviceContext* dc,
                                    const Item& item,
                                    const Rect& bounds,
                                    INT item_style) const;

        virtual void DrawItem(DeviceContext* dc,
                              const Item& item,
                              const Rect& bounds,
                              INT item_style) const;

        virtual BOOLEAN StartTextScrolling(const Item& item, const Rect& bounds) const;

        virtual void StopTextScrolling(const Item& item) const;

        virtual BOOLEAN ScrollText() const;
        
        virtual IconState::Size GetIconSizeState(INT item_style = DefaultStyle) const;

    protected:
        virtual void DrawText(DeviceContext* dc,
                              const Item& item,
                              const Rect& text_rect,
                              INT item_style) const;

    private:
        mutable BOOLEAN m_first_scroll_cycle;
        IconState::Size m_icon_size_state;
        XYDIM m_item_height;
        XYDIM m_icon_width;
        mutable XYDIM m_scroll_pos;

        void SetPenColorForText(PaintDc& pdc, const Item& item, INT item_style) const;
        void DrawItemContIndicator(DeviceContext* dc, const Rect& bounds, INT item_style) const;
        XYDIM GetItemContIndicatorWidth() const { return 6; }       // TODO: should be replaced by a themeable bitmap-width
        void DrawBitmap(DeviceContext* dc,
                        const Item& item,
                        const Rect& bounds,
                        INT item_style) const;      
};

#endif  // Apoxi_DefaultItemRenderer_hpp

