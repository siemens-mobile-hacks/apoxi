/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ContextFeature_hpp)
#define ContextFeature_hpp

#include <Atl/Features/Feature.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Auxiliary/DataItem.hpp>
#endif  // APOXI_COMPAT_2_7_0
class DataItem;

class ContextFeature : public Feature {
    typedef Feature Base;
public:

    enum {
         ID = 2
    };

    enum ContextType {
        WStringType,
        NumberType,
        ItemTextType,
        PhoneNumberType,
        ItemType,
        ProviderType,
        ContainerType,
        UndefinedType
    };

    ContextFeature();

    ContextFeature(AtlApplication* app, 
                   const FeatureID& id);

    virtual ~ContextFeature();

    void Init(AtlApplication* app,  
              const FeatureID& id, 
              ContextType contextType = ItemType);
        
    // TODO: Remove
    virtual INT GetID() const;

    virtual BOOLEAN IsInstanceOf(INT id) const;

    virtual BOOLEAN IsEqual(const Feature& feature) const;
    
    virtual BOOLEAN Execute();

    virtual BOOLEAN Execute(const DataItem& data_item);

    void        SetContextType(ContextType type) { m_context_type = type; }

    ContextType GetContextType() const { return m_context_type; }
      
private:
    ContextFeature(const ContextFeature& orig);
    ContextFeature& operator = (const ContextFeature& rhs);

    ContextType m_context_type;
};

#endif /* ContextFeature_hpp */

