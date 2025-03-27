/*  ------------------------------------------------------------------------
Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(Apoxi_ValueMappingPropertyDescriptor_hpp)
#define Apoxi_ValueMappingPropertyDescriptor_hpp

#include <Atl/AtlPreComp.hpp>

#include <Gui/GuiObjectIterator.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Atl/Properties/MappingPolicy.hpp>
#include <Atl/Properties/ListPropertyDescriptor.hpp>
#include <Atl/Properties/TextIconPairArray.hpp>
#include <Atl/Properties/Property.hpp>

#ifdef APOXI_ARAGON_SUPPORT
    #include <AddOns/MultiMedia/ImageFactory.hpp>   // Aragon requires the addon MultiMedia 
    #include <Gui/ResourceManager.hpp>
#endif

template<class T_Container> class ValueMappingPropertyDescriptor : public ListPropertyDescriptor {
    typedef ListPropertyDescriptor Base;

    public:
        enum { 
            ID = 3
        };

        ValueMappingPropertyDescriptor() : m_dyn_policy(FALSE) { }

        ValueMappingPropertyDescriptor(const T_Container& pairs, 
                                       const MappingPolicy* policy = 0,
                                       const CHAR* context_id = 0);

        ValueMappingPropertyDescriptor(const WCHAR* title,
                                       const T_Container& pairs, 
                                       const MappingPolicy* policy = 0);

        ValueMappingPropertyDescriptor(const WString& title,
                                       const T_Container& pairs, 
                                       const MappingPolicy* policy = 0);

        virtual ~ValueMappingPropertyDescriptor();

        virtual void Init(const T_Container& pairs, 
                          const MappingPolicy* policy = 0,
                          const CHAR* context_id = 0);
        
        virtual void Init(const WCHAR* title,
                          const T_Container& pairs, 
                          const MappingPolicy* policy = 0);

        virtual void Init(const WString& title,
                          const T_Container& pairs, 
                          const MappingPolicy* policy = 0);

        virtual BOOLEAN IsInstanceOf(const INT id) const;

        INT GetTextCount() const { return m_text_icon_pairs.GetSize(); }
        
        const MappingPolicy* GetMappingPolicy() const { return m_policy; }

        BOOLEAN SetProperty(ResourceParser& parser, GuiObjectFactory::PropertyId property_id);

        virtual ImageObtainer GetIcon(const Property* property) const;

        virtual ImageObtainer GetIcon(const DataItem& value) const;

        virtual ImageObtainer GetIcon(INT index) const;

        virtual WString GetText(const Property* property) const;

        virtual WString GetText(const DataItem& value) const;

        virtual WString GetText(INT index) const;

        virtual DataItem GetValue(INT index) const;

        virtual INT GetItemCount() const { return m_text_icon_pairs.GetSize(); }

    private:
        T_Container m_text_icon_pairs;
        const MappingPolicy* m_policy;
        BOOLEAN m_dyn_policy;
};


/*  ------------------------------------------------------------------------
    ValueMappingPropertyDescriptor
    ------------------------------------------------------------------------ */
template<class T_Container> ValueMappingPropertyDescriptor<T_Container>::
	ValueMappingPropertyDescriptor(const T_Container& pairs, 
                               const MappingPolicy* policy, 
                               const CHAR* context_id):
    m_dyn_policy(FALSE)
{
    Init(pairs, policy, context_id);
}

/*  ------------------------------------------------------------------------
    ValueMappingPropertyDescriptor
------------------------------------------------------------------------ */
template<class T_Container> ValueMappingPropertyDescriptor<T_Container>::
	ValueMappingPropertyDescriptor(const WCHAR* title,
                                const T_Container& pairs, 
                                const MappingPolicy* policy):
    m_dyn_policy(FALSE)
{
    Init(title, pairs, policy);
}

/*  ------------------------------------------------------------------------
    ValueMappingPropertyDescriptor
    ------------------------------------------------------------------------ */
template<class T_Container> ValueMappingPropertyDescriptor<T_Container>::
	ValueMappingPropertyDescriptor(const WString& title,
                                   const T_Container& pairs, 
                                   const MappingPolicy* policy):
    m_dyn_policy(FALSE)
{
    Init(title, pairs, policy);
}

/*  ------------------------------------------------------------------------
    ~ValueMappingPropertyDescriptor
    ------------------------------------------------------------------------ */
template<class T_Container> ValueMappingPropertyDescriptor<T_Container>::
	~ValueMappingPropertyDescriptor() 
{
    if (m_dyn_policy) {
        delete m_policy;
    }
    m_policy = 0; 
}

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template<class T_Container> void ValueMappingPropertyDescriptor<T_Container>::
	Init(const T_Container& pairs, const MappingPolicy* policy, const CHAR* context_id)
{
    m_text_icon_pairs = pairs;

    if (policy == 0) {
        m_policy = new MappingPolicy();
        m_dyn_policy = TRUE;
    }
    else {
        m_policy = policy;
    }
    if (context_id != 0) {
        Base::Init(context_id);
    }
}

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template<class T_Container> void ValueMappingPropertyDescriptor<T_Container>::
	Init(const WCHAR* title, const T_Container& pairs, const MappingPolicy* policy)
{
    Init(pairs, policy);
    SetTitle(title);
}

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template<class T_Container> void ValueMappingPropertyDescriptor<T_Container>::
	Init(const WString& title, const T_Container& pairs, const MappingPolicy* policy)
{
    Init(pairs, policy);
    SetTitle(title);
}

/*  ------------------------------------------------------------------------
    IsInstanceOf
    ------------------------------------------------------------------------ */
template<class T_Container> BOOLEAN ValueMappingPropertyDescriptor<T_Container>::
	IsInstanceOf(const INT id) const
{
    return ValueMappingPropertyDescriptor::ID == id || Base::IsInstanceOf(id);
}   // IsInstanceOf

/*  ------------------------------------------------------------------------
    SetProperty
    ------------------------------------------------------------------------ */
template<class T_Container> BOOLEAN ValueMappingPropertyDescriptor<T_Container>::
SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId property_id)
{
#ifdef APOXI_ARAGON_SUPPORT
    BOOLEAN success = FALSE;

    switch (property_id) {
        case GuiObjectFactory::TextIconPairProp: {
            INT count = 0;
            success = parser.GetPropertyValue(GuiObjectFactory::TextIconPairCountProp, (void*) &count);
            if (success) {
                GuiObjectFactory::ParseType parse_type = GuiObjectFactory::MapPropertyIdToParseType(property_id);
                if (parse_type == GuiObjectFactory::TextIconPairType) {
                    WString text;
                    WString image_uri;
                    Image* img;
                    for (INT i = 0; i < count; i++) {
                        img = 0;
                        text = parser.ReadWString();
                        image_uri = parser.ReadWString();
                        if (!image_uri.IsEmpty()) {
                            ChildBinData* data = ResourceManager::GetInstance().GetData(image_uri, parser.GetResourceUri());                
                            if (data != 0) {
                                img = ImageFactory::CreateImage(data, &success);
                            }
                        }
                        if (text.IsEmpty() && img == 0) {
                            DBG_OUT((35700, "ValueMappingPropertyDescriptor::SetProperty: No text and no icon defined a value.\n"));
                        }
                        Item* item = new Item(0, text, ImageObtainer(img));
                        if (item != 0) {
                            m_text_icon_pairs.PushBack(item);
                        }
                    }
                    success = m_text_icon_pairs.GetSize() > 0;
                }
            }
            break;
        }
        case GuiObjectFactory::MappingPolicyProp: {
            GuiObjectIterator iterator(parser);
            if (iterator.HasNext()) {
                m_policy = (MappingPolicy*) GuiObjectFactory::Create(parser, iterator.GetNext());
                success = m_policy != 0;
            }
            break;
        }
        case GuiObjectFactory::ItemProp: {
            GuiObjectIterator item_it(parser);
            while (item_it.HasNext()) {
                Item* item = (Item*) GuiObjectFactory::Create(parser, item_it.GetNext());
                if (item != 0)
                    m_text_icon_pairs.PushBack(item);
            }
            item_it.Release();
            break;
        }
        default: {
            success = Base::SetProperty(parser, property_id);
            break;
        }
    }
    return success; 
#else //APOXI_ARAGON_SUPPORT
    return FALSE;
#endif //APOXI_ARAGON_SUPPORT
}   // SetProperty

/*  ------------------------------------------------------------------------
    GetIcon
    ------------------------------------------------------------------------ */
template<class T_Container> ImageObtainer ValueMappingPropertyDescriptor<T_Container>::
	GetIcon(const Property* property) const {
    ImageObtainer icon;
    if (property != 0) {
        if (property->IsInstanceOf(Property::ID)) {
            ASSERT_DEBUG(property->GetDataItem().GetDataType() == BooleanType || 
                property->GetDataItem().GetDataType() == NumberType);
            ASSERT_DEBUG(m_policy != 0);
            INT size = m_text_icon_pairs.GetSize();
            if (size > 0) {
                INT idx = m_policy->GetIndex(property->GetDataItem());
                if (idx >= 0 && idx < size && m_text_icon_pairs[idx] != 0) {
                    icon = m_text_icon_pairs[idx]->GetIcon();
                }
            }
        }
    }
    return icon;
}   // GetIcon

/*  ------------------------------------------------------------------------
    GetIcon
    ------------------------------------------------------------------------ */
template<class T_Container> ImageObtainer ValueMappingPropertyDescriptor<T_Container>::
	GetIcon(const DataItem& value) const {
    DBG_OUT((5003, L"Obsolete - Please retrieve the icon with the property.\n"));
    ImageObtainer icon;
    ASSERT_DEBUG(m_policy != 0);
    INT size = m_text_icon_pairs.GetSize();
    if (size > 0) {
        INT idx = m_policy->GetIndex(value);
        if (idx >= 0 && idx < size && m_text_icon_pairs[idx] != 0) {
            icon = m_text_icon_pairs[idx]->GetIcon();
        }
    }
    return icon;
}   // GetIcon

/*  ------------------------------------------------------------------------
    GetIcon
    ------------------------------------------------------------------------ */
template<class T_Container> ImageObtainer ValueMappingPropertyDescriptor<T_Container>::
	GetIcon(INT index) const {
    ImageObtainer icon;
    if (index < m_text_icon_pairs.GetSize()) {
        m_text_icon_pairs[index]->GetIcon();
    }
    return icon;
}   // GetIcon

/*  ------------------------------------------------------------------------
    GetText
    ------------------------------------------------------------------------ */
template<class T_Container> WString ValueMappingPropertyDescriptor<T_Container>::
	GetText(const Property* property) const {
    WString text;
    if (property != 0) {
        if (property->IsInstanceOf(Property::ID)) {
            ASSERT_DEBUG(property->GetDataItem().GetDataType() == BooleanType ||
                property->GetDataItem().GetDataType() == NumberType);
            ASSERT_DEBUG(m_policy != 0);
            INT size = m_text_icon_pairs.GetSize();
            if (size > 0) {
                INT idx = m_policy->GetIndex(property->GetDataItem());
                if (idx >= 0 && idx < size && m_text_icon_pairs[idx] != 0) {
                    text = m_text_icon_pairs[idx]->GetText();
                }
            }
        }
    }
    return text;
}   // GetText

/*  ------------------------------------------------------------------------
    GetText
    ------------------------------------------------------------------------ */
template<class T_Container> WString ValueMappingPropertyDescriptor<T_Container>::
	GetText(const DataItem& value) const {
    DBG_OUT((5003, L"Obsolete - Please retrieve the text with the property.\n"));
    WString text;
    ASSERT_DEBUG(m_policy != 0);
    INT size = m_text_icon_pairs.GetSize();
    if (size > 0) {
        INT idx = m_policy->GetIndex(value);
        if (idx >= 0 && idx < size && m_text_icon_pairs[idx] != 0) {
            text = m_text_icon_pairs[idx]->GetText();
        }
    }
    return text; 
}   // GetText

/*  ------------------------------------------------------------------------
    GetText
    ------------------------------------------------------------------------ */
template<class T_Container> WString ValueMappingPropertyDescriptor<T_Container>::
	GetText(INT index) const {
    WString text;
    if (index < m_text_icon_pairs.GetSize()) {
        text = m_text_icon_pairs[index]->GetText();
    }
    return text; 
}   // GetText

/*  ------------------------------------------------------------------------
    GetValue
    ------------------------------------------------------------------------ */
template<class T_Container> DataItem ValueMappingPropertyDescriptor<T_Container>::
	GetValue(INT index) const
{
    ASSERT_DEBUG(m_policy != 0);
    return m_policy->GetValue(index);
}   // GetValue

#ifdef APOXI_ARAGON_SUPPORT
typedef ValueMappingPropertyDescriptor< Vector<Item*> > DynamicValueMappingPropertyDescriptor;

#endif  // APOXI_ARAGON_SUPPORT
typedef ValueMappingPropertyDescriptor<TextIconPairArray> StaticValueMappingPropertyDescriptor;

#endif  // Apoxi_ValueMappingPropertyDescriptor_hpp


