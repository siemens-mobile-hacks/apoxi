/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_PropertyEditor_hpp)
#define Atl_PropertyEditor_hpp

#include <Atl/Properties/PropertyEditorID.hpp>
#include <Atl/Properties/Property.hpp>
#include <Atl/AtlWindow.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Properties/PropertyItem.hpp>
#endif  // APOXI_COMPAT_2_7_0

class PropertyItem;
class PropertyEditor: public AtlWindow {
    typedef AtlWindow Base;

    public:
        PropertyEditor(const PropertyEditorID& id);

        PropertyEditor(const PropertyEditorID& id, 
                       ContextID& context);

        virtual ~PropertyEditor();

        const virtual PropertyEditorID& GetID() const {return m_editor_id;}

        virtual BOOLEAN EditProperty(PropertyItem& item);
      
        virtual void GetNewPropertyValue(DataItem& value) = 0;

    protected:
        void    SetPropertyItem(PropertyItem& item) {m_property_item = &item;}

        const PropertyItem* GetPropertyItem() {return m_property_item;}

        void    SetDescriptor(const PropertyDescriptor* descriptor);

        const PropertyDescriptor*   GetDescriptor() {return m_descriptor;}

        virtual BOOLEAN CanEdit();
        
        virtual void Init();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

        BOOLEAN SendNotification(const Property::Notification notification, BOOLEAN new_data = TRUE);

        virtual BOOLEAN OnCancel();
        
    private:
        PropertyItem                *m_property_item;
        const PropertyDescriptor    *m_descriptor;

        PropertyEditorID m_editor_id;   
};

#endif  // Atl_PropertyEditor_hpp

