/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(FeatureItemContainer_hpp)
#define FeatureItemContainer_hpp

#include <Gui/ItemContainer.hpp>
#include <Atl/Features/FeatureItemContainerID.hpp>
#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Features/Feature.hpp>
#include <Atl/Properties/SubstitutedText.hpp>
#endif  // APOXI_COMPAT_2_7_0
#include <Atl/Context/ContextID.hpp>

class Feature;
class FeatureItemContainer : public ItemContainer {
    public:
        typedef ItemContainer Base;

        enum Identifier 
        {
            ID = 106
        };

        enum FeatureItemContainerPropertyId {
            ContextPropertyId = 5
        };


        FeatureItemContainer(BOOLEAN ignore_unavailable_features = TRUE);

        FeatureItemContainer(FeatureItemContainerID container_id, BOOLEAN ignore_unavailable_features = TRUE);

        virtual ~FeatureItemContainer();

        BOOLEAN SetProperty(ResourceParser& parser, 
                            const GuiObjectFactory::PropertyId prop_id, 
                            UINT16 object_id);

        virtual INT GetID() const;
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual BOOLEAN IsEqual (const Item& item) const;

        void Init(FeatureItemContainerID container_id, BOOLEAN ignore_unavailable_features = TRUE);

        void Init(FeatureItemContainerID container_id, 
                const WString& text, BOOLEAN ignore_unavailable_features = TRUE);

        void SetContextId(const ContextID& id);

        void SetContextId(const CHAR * id);

        const ContextID& GetContextId() const { return m_context_id; }

        void SetContainerId(FeatureItemContainerID container_id) { m_container_id = container_id; }

        FeatureItemContainerID GetContainerId() const { return m_container_id; } 
                
    
        virtual BOOLEAN AddItem(Item* item);

        virtual BOOLEAN InsertItem(INT index, Item* item);

        virtual BOOLEAN RemoveItem(INT index);

        virtual BOOLEAN RemoveAllItems();

        virtual Item* GetItem(INT index) const;

        virtual INT GetItemIndex(const Item& item) const;

        virtual INT GetItemCount() const;
      
        BOOLEAN IsAvailable() const;

        BOOLEAN ContainsFeature(Feature* feature);

        void    Invalidate();

        void IgnoreUnavailableFeatures(BOOLEAN flag) { m_ignore_unavailable_features = flag; }

        BOOLEAN UnavailableFeaturesIgnored() const { return m_ignore_unavailable_features; }


   private:
        INT LookupIndex(INT i) const { return (!m_index_table) ? i : m_index_table[i]; }

        void BuildIndexTable() const;

        FeatureItemContainerID  m_container_id;
        mutable BOOLEAN                 m_invalid;
        BOOLEAN                 m_ignore_unavailable_features;
        mutable INT             *m_index_table;
        mutable INT             m_index_table_size;

        static Mutex                m_mutex;
        static BOOLEAN          m_initialized;

        ContextID m_context_id;
};

#endif /* FeatureItemContainer_hpp */

