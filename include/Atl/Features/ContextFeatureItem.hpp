//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(ContextFeatureItem_hpp)
#define ContextFeatureItem_hpp

#include <Atl/Features/FeatureItem.hpp>
#include <Atl/Features/ContextFeature.hpp>
#include <Auxiliary/DataItem.hpp>

class AtlApplication;

class ContextFeatureItem : public FeatureItem {
    public:

        typedef FeatureItem Base;
        
        enum {
            ID = 101
        };
        
        ContextFeatureItem();

        ContextFeatureItem(ContextFeature* feature,
                           const WString& text = "", 
                           BOOLEAN fixed_context = FALSE);

        ContextFeatureItem(ContextFeature* feature, 
                           const WString& text = "", 
                           const ImageObtainer& icon = ImageObtainer(), 
                           BOOLEAN fixed_context = FALSE);
        
        virtual ~ContextFeatureItem();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        // TODO: Remove
        virtual INT GetID() const;
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        void Init(ContextFeature* feature, 
                  const WString& text = "", 
                  BOOLEAN fixed_context = FALSE);

        void Init(ContextFeature* feature, 
                  const WString& text = "", 
                  const ImageObtainer& icon = ImageObtainer(), 
                  BOOLEAN fixed_context = FALSE);

        void SetContextItem(const DataItem& item) { m_context_item = item; };

        const DataItem& GetContextItem() const { return m_context_item; };

        virtual BOOLEAN Execute();

        ContextFeature::ContextType GetContextType() const;

        virtual BOOLEAN IsFixedContext() { return m_fixed_context;}

    private:
        DataItem m_context_item;
        BOOLEAN  m_fixed_context;
};

#endif /* ContextFeatureItem_hpp*/

