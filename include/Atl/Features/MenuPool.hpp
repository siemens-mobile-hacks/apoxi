/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_MenuPool_hpp)
#define Atl_MenuPool_hpp
#include <Atl/Features/MenuID.hpp>
#include <Atl/Features/FeatureItemContainerID.hpp>
#include <Atl/Context/MenuDesc.hpp>
#include <Atl/Config/MenuResourceTable.hpp>
#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Features/FeatureItem.hpp>
#endif  // APOXI_COMPAT_2_7_0

class MenuProperties;
class FeatureItemContainer;
class ItemRendererProperties;
class Feature;


class MenuPool
{
public:

    struct FeatureItemContainerTableEntry;

    enum itemType {
        itemTypeNone = 0,
        itemTypeFeatureItem,
        itemTypeContextFeatureItem,
        itemTypeFixedContextFeatureItem,
        itemTypePropertyItem,
        itemTypeFeatureItemContainer
    };
    
    struct MenuTableEntry {
        const FeatureItemContainerTableEntry HUGE_64K*  container_table_entry;
        const CHAR*     menu_id;
        const MenuProperties* menu_properties;
    };
    
    struct FeatureItemContainerContentTableEntry {
        UINT8           item_type;
        const FeatureItemContainerTableEntry HUGE_64K*  container_table_entry;
        const CHAR*     application_id;
        const CHAR*     feature_id;
        const CHAR*     text;
        const CHAR*     icon_id;
        const void*     datum; // pointer to DataItem or pointer to PropertyDescriptor
        const CHAR*     property_editor_id;
        const CHAR*     context_id;
    };
    
    struct FeatureItemContainerTableEntry {
        const FeatureItemContainerContentTableEntry HUGE_64K*   container_content_table_entry;
        const CHAR*                     container_id;
        const CHAR*                     text;
        const CHAR*                     icon_id;
        const ItemRendererProperties*   render_properties;
        const CHAR*                     context_id;
    };
    
    MenuPool();

    virtual ~MenuPool();
    
    virtual void InitMenus();

    virtual MenuDesc* GetMenu(const MenuID& id);

    virtual void OnFeatureAdded(Feature* feature);

    virtual void OnFeatureStatusChanged(Feature* feature);

    BOOLEAN MenuFileExists() const;

private:
    class MenuMapItem
    {
        public:
            MenuMapItem();
            MenuMapItem(const MenuID& id, const MenuDesc&  menu) : m_id(id), m_menu(menu) {};

            MenuID& GetMenuID() { return m_id; }
            MenuDesc& GetMenu() { return m_menu; }
    
        private:
            MenuID m_id;
            MenuDesc m_menu;
    };
    
    BOOLEAN IsIconSet(const String& name) const;
    
    const MenuTableEntry* GetMenuTableEntry(const MenuID& id) const;

    FeatureItemContainer* GetFeatureItemContainer(FeatureItemContainerID container_id) const;

    FeatureItemContainer* ConstructFeatureItemContainer(const HUGE_64K FeatureItemContainerTableEntry* container_table_entry, BOOLEAN recursive = FALSE);
    
    BOOLEAN ConstructMenu(const MenuID& id);

    void UpdateContainerItems(FeatureItemContainer* container, Feature* feature);

    Vector<MenuMapItem> m_menus;
    Vector< FeatureItemContainer* > m_containers;
    MenuResourceTable* m_menu_resource_table;
    
};

#endif  // Atl_MenuPool_hpp


