/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_AtlItemRenderer_hpp)
#define Atl_AtlItemRenderer_hpp

#include <Gui/DefaultItemRenderer.hpp>
#include <Gui/Item.hpp>
#include <Atl/Properties/SubstitutedText.hpp>

class AtlItemRenderer : public DefaultItemRenderer {
    typedef DefaultItemRenderer Base;

    public:
        AtlItemRenderer(const ItemRendererProperties* properties = 0);

        virtual ~AtlItemRenderer();

        virtual Rect GetIconRect(const Item& item, const Rect& bounds) const;

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

    private:
        const Item& GetSubstitutedItem(const Item& item) const;

        mutable Item                m_item;
        mutable SubstitutedText     m_substituted_text;
};

#endif  // Atl_AtlItemRenderer_hpp


