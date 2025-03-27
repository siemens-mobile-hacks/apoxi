//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#ifndef Atl_PropertyItem_hpp
#define Atl_PropertyItem_hpp

#include <Atl/Features/FeatureItem.hpp>
#include <Atl/Properties/PropertyEditorID.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Properties/PropertyID.hpp>
#include <Atl/Properties/PropertyDescriptor.hpp>
#endif  // APOXI_COMPAT_2_7_0


class PropertyDescriptor;
class AtlApplication; 

class PropertyItem : public FeatureItem {
    typedef FeatureItem Base;

    public:

        enum {
            ID = 104
        };

        PropertyItem();

        PropertyItem(Property* property,
                    const WString& text = "",
                    const ImageObtainer& icon = ImageObtainer());

        virtual ~PropertyItem();
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        void Init(Property* property, 
                    const WString& text = "", 
                    const ImageObtainer& icon = ImageObtainer());

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetPropertyEditorID(const PropertyEditorID& id);

        const PropertyEditorID& GetPropertyEditorID() const;

        virtual BOOLEAN Execute();

        void SetDescriptor(PropertyDescriptor* descriptor);

        const PropertyDescriptor* GetDescriptor() const;

        virtual void Update();

    private:
        PropertyItem(const PropertyItem&) {};
      
        PropertyEditorID m_editor; 
        const PropertyDescriptor* m_descriptor;
        BOOLEAN m_item_icon_configured;
};

#endif  // Atl_PropertyItem_hpp

