//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#ifndef Atl_PropertyDescriptor_hpp
#define Atl_PropertyDescriptor_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/DataItem.hpp>

#include <Gui/ImageObtainer.hpp>
#include <Config/GuiObjectFactory.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Gui/ResourceParser.hpp>
#include <Atl/Properties/Property.hpp>
#endif  // APOXI_COMPAT_2_7_0

#include <Atl/Context/ContextID.hpp>

class Property;
class ResourceParser;

class PropertyDescriptor {

    public:
        enum {
            ID = 1
        };

        PropertyDescriptor();

        PropertyDescriptor(const WString& title);

        PropertyDescriptor(const WString& title, const WString& label);

        PropertyDescriptor(const WCHAR* title, const WCHAR* label = 0); 

        PropertyDescriptor(const ContextID& context_id, const WString& label); 

        PropertyDescriptor(const CHAR* context_id, const WCHAR* label = 0); 

        virtual ~PropertyDescriptor();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        void Init(const WString& title, const WString& label);

        void Init(const WCHAR* title, const WCHAR* label = 0);
        
        void Init(const ContextID& context_id, const WString& label); 

        void Init(const CHAR* context_id, const WCHAR* label = 0); 

        virtual BOOLEAN IsInstanceOf(const INT id) const;
        
        const WString& GetLabel() const { return m_label; }

        const WString& GetTitle() const { return m_title; }

        virtual WString GetText(const Property* property) const;

        virtual WString GetText(const DataItem& item) const;

        virtual ImageObtainer GetIcon(const Property* property) const;

        virtual ImageObtainer GetIcon(const DataItem& item) const;

        void SetLabel(const WString& label) { m_label = label; }

        void SetTitle(const WString& title) { m_title = title; }

        const ContextID& GetContextId() const { return m_context_id; }

#if defined(APOXI_COMPAT_2_6_0)

        virtual void GetRepresentation(const Property* property, WString& representation) const;

        virtual void GetRepresentation(const Property* property, ImageObtainer& icon) const;
#endif

    protected:
        WString m_title;
        WString m_label;
        ContextID m_context_id;

};

#endif  // Atl_PropertyDescriptor_hpp

