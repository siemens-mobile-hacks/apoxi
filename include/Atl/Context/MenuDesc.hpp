//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_MenuDesc_hpp)
#define Atl_Context_MenuDesc_hpp

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Features/MenuID.hpp>
#include <Atl/Context/MenuProperties.hpp>
#include <Atl/Features/FeatureItemContainer.hpp>
#endif  // APOXI_COMPAT_2_7_0

#include <Gui/ResourceParser.hpp>
#include <Config/GuiObjectFactory.hpp>

class FeatureItemContainer;
class MenuProperties;

class MenuDesc {
    public:
        MenuDesc();

        MenuDesc(FeatureItemContainer* container, 
                 const MenuProperties* menu_properties);

        virtual ~MenuDesc();

        BOOLEAN SetProperty(ResourceParser& parser, 
                            const GuiObjectFactory::PropertyId prop_id);

        void Init(FeatureItemContainer* container, 
                  const MenuProperties* menu_properties);

        FeatureItemContainer* GetItemContainer() const { return m_item_container; }

        const MenuProperties* GetMenuProperties() const { return m_menu_properties; } 

    private:
        FeatureItemContainer* m_item_container;
        const MenuProperties*  m_menu_properties;
    };

#endif /* Atl_Context_MenuDesc_hpp */


