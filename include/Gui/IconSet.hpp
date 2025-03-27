/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IconSet_hpp)
#define Apoxi_IconSet_hpp

#include <Gui/IconState.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Auxiliary/Vector.hpp>

class IconSet {
    public:
        IconSet();

        IconSet(const ImageObtainer& default_icon);
        
        ~IconSet(); // non-virtual

        void SetDefaultIcon(const ImageObtainer& icon) { m_default_icon = icon; }

        const ImageObtainer& GetDefaultIcon() const { return m_default_icon; }

        BOOLEAN AddIcon(const IconState& state, const ImageObtainer& icon);

        const ImageObtainer& GetIcon(const IconState& state) const;

        const ImageObtainer& GetIcon(INT index) const;

        INT GetIconCount() const;
        
        void RemoveAllIcons();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);
        
        IconSet& operator=(const IconSet& icon_set);

#ifdef APOXI_COMPAT_2_1_0

        explicit IconSet(INT id);

        INT GetId() const { return 0; }
#endif
        
    private:
        struct IconElem {
            IconState state;
            ImageObtainer icon;
        };

        ImageObtainer m_default_icon;
        Vector<IconElem>* m_icon_vec;

        BOOLEAN HasIconForState(const IconState& state) const;

        BOOLEAN ConvertToImage(ImageObtainer& icon);
};

#endif // Apoxi_IconSet_hpp


