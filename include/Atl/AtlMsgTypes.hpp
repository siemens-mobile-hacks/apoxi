/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "igelpasc_apoxitest_sv\lnz_apoxi\Apoxi\Atl\AtlMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Atl_AtlMsgTypes_hpp)
#define Atl_AtlMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Auxiliary/DataItem.hpp>
#include <Atl/Features/FeatureID.hpp>
#include <Atl/Features/Feature.hpp>
#include <Config/AtlConfig.hpp>
#include <Gui/Item.hpp>


class Feature;
class FeatureItem;
class PropertyItem;
class ContextFeatureItem;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class IndicatorBarUpdateMsg
    ====================================================================== */

class IndicatorBarUpdateMsg : public Message {
    public:
        IndicatorBarUpdateMsg();
        virtual ~IndicatorBarUpdateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 13000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class CloseAllMsg
    ====================================================================== */

class CloseAllMsg : public Message {
    public:
        CloseAllMsg(const AtlConfig::BeforeClosingAction& action = AtlConfig::DoNothing);
        virtual ~CloseAllMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAction(const AtlConfig::BeforeClosingAction& action) { m_action = action; }
        const AtlConfig::BeforeClosingAction& GetAction() const { return m_action; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        AtlConfig::BeforeClosingAction m_action;
        
    };


/*  ======================================================================
    Class UpdateContextItemMsg
    ====================================================================== */

class UpdateContextItemMsg : public Message {
    public:
        UpdateContextItemMsg(ContextFeatureItem* context_item);
        virtual ~UpdateContextItemMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        ContextFeatureItem* GetContextItem() const { return m_context_item; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13002
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ContextFeatureItem* m_context_item;
        
    };


/*  ======================================================================
    Class FeatureChangedMsg
    ====================================================================== */

class FeatureChangedMsg : public Message {
    public:
        FeatureChangedMsg(Feature* feature, INT property_id = Feature::UnspecifiedAttributeId);
        virtual ~FeatureChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Feature* GetFeature() const { return m_feature; }
        INT GetPropertyId() const { return m_property_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13003
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Feature* m_feature;
        INT m_property_id;
        
    };


/*  ======================================================================
    Class PropertyTriggerMsg
    ====================================================================== */

class PropertyTriggerMsg : public ContextMsg {
    public:
        PropertyTriggerMsg(ExecutionContext* context, PropertyItem* property_item);
        virtual ~PropertyTriggerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPropertyItem(PropertyItem* property_item) { m_property_item = property_item; }
        PropertyItem* GetPropertyItem() const { return m_property_item; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13004
            };
        
    private:
        static const MsgMetaData m_meta_data;
        PropertyItem* m_property_item;
        
    };


/*  ======================================================================
    Class FeatureTriggerMsg
    ====================================================================== */

class FeatureTriggerMsg : public ContextMsg {
    public:
        FeatureTriggerMsg(ExecutionContext* context, const FeatureID& feature_id);
        virtual ~FeatureTriggerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetFeatureId(const FeatureID& feature_id) { m_feature_id = feature_id; }
        const FeatureID& GetFeatureId() const { return m_feature_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13005
            };
        
    private:
        static const MsgMetaData m_meta_data;
        FeatureID m_feature_id;
        
    };


/*  ======================================================================
    Class ContextFeatureTriggerMsg
    ====================================================================== */

class ContextFeatureTriggerMsg : public ContextMsg {
    public:
        ContextFeatureTriggerMsg(ExecutionContext* context, const FeatureID& feature_id, const DataItem& context_item);
        virtual ~ContextFeatureTriggerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetFeatureId(const FeatureID& feature_id) { m_feature_id = feature_id; }
        const FeatureID& GetFeatureId() const { return m_feature_id; }
        void SetContextItem(const DataItem& context_item) { m_context_item = context_item; }
        const DataItem& GetContextItem() const { return m_context_item; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13006
            };
        
    private:
        static const MsgMetaData m_meta_data;
        FeatureID m_feature_id;
        DataItem m_context_item;
        
    };


/*  ======================================================================
    Class UpdateItemMsg
    ====================================================================== */

class UpdateItemMsg : public ContextMsg {
    public:
        UpdateItemMsg(ExecutionContext* context, Item* item);
        virtual ~UpdateItemMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Item* GetItem() const { return m_item; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13007
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Item* m_item;
        
    };


/*  ======================================================================
    Class DisabledFeatureTriggeredMsg
    ====================================================================== */

class DisabledFeatureTriggeredMsg : public ContextMsg {
    public:
        DisabledFeatureTriggeredMsg(ExecutionContext* context, const FeatureID& feature_id);
        virtual ~DisabledFeatureTriggeredMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetFeatureId(const FeatureID& feature_id) { m_feature_id = feature_id; }
        const FeatureID& GetFeatureId() const { return m_feature_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 13008
            };
        
    private:
        static const MsgMetaData m_meta_data;
        FeatureID m_feature_id;
        
    };

#endif // Atl_AtlMsgTypes_hpp

