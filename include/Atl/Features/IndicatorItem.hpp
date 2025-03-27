//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#ifndef Atl_IndicatorItem_hpp
#define Atl_IndicatorItem_hpp

#include <Atl/Features/FeatureItem.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Properties/PropertyID.hpp>
#include <Atl/Properties/PropertyEditorID.hpp>
#include <Atl/Properties/PropertyDescriptor.hpp>
#endif  // APOXI_COMPAT_2_7_0

class AtlApplication;
class ImageObtainer;
class Property;
class PropertyDescriptor;

class IndicatorItem: public FeatureItem {
    typedef FeatureItem Base;

public:

    enum {
        ID = 102
    };

    IndicatorItem();

    IndicatorItem(Property* property);

    IndicatorItem(Property* property, PropertyDescriptor* descriptor);

    IndicatorItem(Property* property, 
        const WString& text, 
        const ImageObtainer& icon);

    virtual ~IndicatorItem();

    void Init(Property* property, 
        const WString& text = "", 
        const ImageObtainer& icon = ImageObtainer());

    virtual void Update();

    BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

    virtual BOOLEAN IsInstanceOf(INT id) const;

    void SetDescriptor(PropertyDescriptor* descriptor);

    const PropertyDescriptor* GetDescriptor() const;

    virtual BOOLEAN Execute();

private:
    IndicatorItem(const IndicatorItem&) {};
    IndicatorItem& operator = (const IndicatorItem& rhs);

    const PropertyDescriptor* m_descriptor;
};

#endif  // Atl_IndicatorItem_hpp

