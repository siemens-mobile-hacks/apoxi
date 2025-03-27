//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_SoftkeyDesc_hpp)
#define Atl_Context_SoftkeyDesc_hpp

#if defined(APOXI_COMPAT_2_7_0)
#include <Config/KeyboardConfig.hpp>
#endif  // APOXI_COMPAT_2_7_0

#include <Gui/Window.hpp>

#include <Atl/Features/AppFeatureID.hpp>
#include <Atl/Features/MenuID.hpp>
#include <Atl/Features/ContextFeatureItem.hpp>

class SoftkeyDesc {
    public:
        SoftkeyDesc();

        
        SoftkeyDesc(const AppFeatureID& feature_id) {
            m_feature_id = feature_id;
        }

        SoftkeyDesc(const AppFeatureID& feature_id, 
                    const WString& text) {
            m_feature_id = feature_id;
            m_sk_text = text;
        }

        SoftkeyDesc(const MenuID& menu_id) {
            m_menu_id = menu_id;
        }
        
        SoftkeyDesc(const MenuID& menu_id, 
                    const WString& text) {
            m_menu_id = menu_id;
            m_sk_text = text;
        }

        ~SoftkeyDesc();

        FeatureItem* GetSoftkeyFeatureItem(INT sk_id) const;

        void SetFeatureId(const AppFeatureID& id) { m_feature_id = id; }

        const AppFeatureID& GetFeatureId() const { return m_feature_id; }

        void SetMenuId(const MenuID& id) { m_menu_id = id; }

        const MenuID& GetMenuId() const { return m_menu_id; }

        const WString& GetSkText() const { return m_sk_text; }

        void SetSkText(const WString& text) { m_sk_text = text; }

        void SetSkText(const WCHAR* text) { m_sk_text = text; }

        void SetSkIcon(const ImageObtainer& icon) { m_sk_icon = icon; }

        const ImageObtainer& GetSkIcon() const { return m_sk_icon; }

    private:
        AppFeatureID m_feature_id;
        MenuID m_menu_id;
        mutable WString m_sk_text;
        mutable ImageObtainer m_sk_icon;
        mutable INT m_language_id;
        
        static ContextFeatureItem m_open_menu[APOXI_MAX_SOFTKEY_COUNT];
        static FeatureItem        m_softkey_feature_items[APOXI_MAX_SOFTKEY_COUNT];
        static ContextFeature     m_open_menu_context_feature;

};

#endif // Atl_Context_SoftkeyDesc_hpp 


