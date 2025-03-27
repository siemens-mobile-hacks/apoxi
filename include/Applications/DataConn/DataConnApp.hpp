/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_DataConnApp_hpp)
#define Mmi_DataConnApp_hpp
#include <Atl/Gui/AtlItemMenuWindow.hpp>
#include <Atl/Gui/AtlItemListWindow.hpp>
#include <Atl/Features/ProviderProxyContainer.hpp>
#include <Atl/Features/FeatureID.hpp>

#include <Common/MmiApplication.hpp>
#include <Config/DataConnConfig.hpp>

#include <DataConn/MyDataConnProfileStorage.hpp>
#include <DataConn/DataConnProvider.hpp>
#include <DataConn/CsdDataConnProvider.hpp>
#include <DataConn/PsdDataConnProvider.hpp>
#include <DataConn/SerDataConnProvider.hpp>

#if !defined(DATA_CONN_APP_EXCLUDE_SERIAL)
    #include <Socket/SerDataConnProfile.hpp>
#endif  

class Property;

typedef DataConnProfile::ProfileType DataConnProfileType;
typedef DataConnConfig::PropertyType DataConnPropertyType;

class DataConnApp : public MmiApplication {
    typedef MmiApplication Base;

    public:
        virtual ~DataConnApp();
        static DataConnApp* GetInstance();
    
        struct EditableSettingTable {
            INT type;
            BOOLEAN always_editable;
        };

        class DataConnDescription {
            public:
                DataConnDescription(Property* property, INT prop_cnt, DataConnProfileType profile_type, 
                                DataConnProvider* provider, EditableSettingTable* editable_table = 0, BOOLEAN allocated_dynamically = TRUE);

                Property* GetFirstProperty() const { return m_property; }
                INT GetPropCnt() const { return m_prop_cnt; }
                DataConnProfileType GetDataConnProfileType() const { return m_type; }
                DataConnProvider* GetProvider() const { return m_provider; }
                EditableSettingTable* GetEditableTable() const { return m_editable_table; }
                BOOLEAN IsAllocatedDynamically() const { return m_allocated_dynamically; }
            private:
                Property* m_property;
                INT m_prop_cnt;
                DataConnProfileType m_type;
                DataConnProvider* m_provider;
                EditableSettingTable* m_editable_table;
                BOOLEAN m_allocated_dynamically;
        };
        
        enum FeatureId {
            FeatViewDataConnList,
            FeatEditProfile,
            FeatDeleteProfile,
            FeatSaveProfile,
            FeatSetDefaultProfile,
            FeatureCnt
        };

        enum { PropInvalidId = -1 };

        enum CommonPropertyId {
            PropName, 
            PropAccount,
            PropPasswd,
            PropQueryPasswd,
            PropPrimaryDnsServerAddress,
            PropSecondaryDnsServerAddress,
            CommonPropCount
        };

        enum CsdPropertyId {
            PropCallType,
            PropPhoneNo,
            PropDataRate,
            PropIdleTimer,
            PropLingerTimer,
            CsdPropCount
        };

        enum PsdPropertyId {
            PropApnName,
            PropLocalAddr,
            PropAuthType,
            PropDataCompr,
            PropQosPrecedence,
            PropQosDelay,
            PropQosReliability,
            PropQosPeakRate,
            PropQosMeanRate,
#ifdef APOXI_STACK_UMTS
            Prop3GPresent,
            PropTrafficClass,
            PropDeliveryOrder,
            PropErrorSduDelivery,
            PropMaxSduSize,
            PropBitRateUp,
            PropBitRateDown,
            PropResidualBer,
            PropSduErrorRatio,
            PropTransferDelay,
            PropTrafficPriority,
            PropGuaranteedBitRateUp,
            PropGuaranteedBitRateDown,
#endif
            PsdPropCount
        };

        enum SerPropertyId {
#if !defined(DATA_CONN_APP_EXCLUDE_SERIAL)
            PropSerIdleTimer,
            PropSerLingerTimer,
#endif
            SerPropCount
        };
        
        virtual void OnStartup();

        virtual BOOLEAN UpdateItem(Item* item);

        void AddDataConnDescription(DataConnDescription* dataconn_desc);

    protected:
        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);
        virtual BOOLEAN OnContextFeatureTriggered (const FeatureID& feature_id, const DataItem& context_item);

    private:
        DataConnApp();

        INT AddProfile(DataConnProfile::ProfileType profile_type);
        void EditProfile(INT row);
        void UpdateProperties(DataConnProfileType type, INT row);
        void UpdateProperties(Property* property, INT prop_cnt, Provider* provider, INT row, INT id_offset);
        BOOLEAN IsMyFeatureItem(Item* item) const;
        INT GetPropertyId(DataConnPropertyType type, const FeatureID& property_id) const;
        DataConnProvider* GetDataConnProvider(INT row);

        BOOLEAN SettingAlwaysEditable(EditableSettingTable* table, INT setting);
        void UpdateAvailableProperties(DataConnProfileType actual_type);
        DataConnDescription* GetDataConnDescription(DataConnProfileType type) const;
        void CommitProperties(INT row);
        void CommitProperties(Property* property, INT prop_cnt, Provider* provider, INT id_offset);

        BOOLEAN IsReadOnly(INT row, INT prop_id);

        ContextFeature m_new_profile;
        Feature m_features[FeatureCnt];
        static const CHAR* m_feature_strings[FeatureCnt + CommonPropCount + CsdPropCount + PsdPropCount + SerPropCount];
        Property m_common_properties[CommonPropCount];
        Property m_csd_properties[CsdPropCount];
        Property m_psd_properties[PsdPropCount];
#if !defined(DATA_CONN_APP_EXCLUDE_SERIAL)
        Property m_ser_properties[SerPropCount];
        SerDataConnProvider m_ser_provider;
#endif

        AtlItemListWindow m_list_win;
        AtlItemMenuWindow m_edit_win;
        ProviderProxyContainer m_item_cont;
        CsdDataConnProvider m_csd_provider;
        PsdDataConnProvider m_psd_provider;
                                    
        Vector<DataConnDescription*> m_dataconn_desc_vec;
        
        MyDataConnProfileStorage        m_storage;
};

#endif  // Mmi_DataConnApp_hpp

