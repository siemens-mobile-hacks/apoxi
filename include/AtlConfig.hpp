/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_AtlConfig_hpp)
#define Atl_AtlConfig_hpp

#include <Atl/Features/BackToIdleFeature.hpp>
#include <Atl/Features/TriggerKeyFeature.hpp>
#include <Atl/Features/FeaturePool.hpp>
#include <Atl/Features/FeatureItem.hpp>
#include <Atl/Features/MenuPool.hpp>
#include <Atl/Properties/PropertyEditor.hpp>
#include <Atl/Properties/PropertyEditorID.hpp>
#include <Atl/Context/ContextManager.hpp>

#ifdef APOXI_ARAGON_SUPPORT
static const WString c_aragon_menu_filename = L"/ffs/dynamic_menu_pool.rc";
#endif  


class AtlConfig {
    friend class ContextManager;

    public:
        static PropertyEditor* CreateEditor(const PropertyEditorID& id);

        static MenuPool* GetMenuPool();

        static FeatureItem* GetPlatformFeatureItem(FeatureID& featureID);

    private:
        AtlConfig();
        
        enum FeatureIds {
            TriggerSelect,
            TriggerBack,
            TriggerClose,
            TriggerCancel,
            TriggerConfirm,
            TriggerDelete,
            CloseAll,
            FeatureCnt
        };

        static void SetPlatformFeaturesEnabled(BOOLEAN enabled);
        static KeyCode GetKeyCode(INT feature_id);

        static FeaturePool       m_default_feature_pool;
        static TriggerKeyFeature m_trigger_keys[FeatureCnt - 1];
        static BackToIdleFeature m_close_all_feature;
        static FeatureItem m_feature_items[FeatureCnt];
        static const CHAR* m_feature_ids[FeatureCnt - 1];
        static const CHAR* m_feature_texts[FeatureCnt];
};

#endif  // Atl_AtlConfig_hpp

