/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_AtlApplication_hpp)
#define Atl_AtlApplication_hpp

#include <Auxiliary/Vector.hpp>

#include <Kernel/Application.hpp>

#include <Atl/Features/FeatureID.hpp>
#include <Atl/Features/MenuID.hpp>
#include <Atl/Features/FeaturePool.hpp>
#include <Atl/Features/ApplicationID.hpp>
#include <Atl/Context/ContextID.hpp>
#include <Atl/Context/ContextManager.hpp>
#include <Atl/Properties/Property.hpp>

#if defined(APOXI_COMPAT_2_7_0)
    #include <Atl/Gui/AtlItemMenuWindow.hpp>
#endif  // APOXI_COMPAT_2_7_0

class AtlApplicationPlugin;
class AtlItemMenuWindow;
class ContextFeature;
class ContextFeatureItem;
class FeatureItem;
class FeatureItemContainer;
class PropertyItem;


class UserActivityListener {
    public:
        UserActivityListener(){}
        ~UserActivityListener(){}
        virtual void OnUserActivity() = 0;
};


class AtlApplication : public Application {
    typedef Application Base;

    friend class KeyManager;
    friend class AtlApplicationPlugin;


    public:
        AtlApplication(const WCHAR* app_name,
                       UINT stacksize = 0);

        virtual ~AtlApplication();

        virtual ApplicationID GetID() const;

        virtual void OnStartup();

        
        FeaturePool* GetFeaturePool();

        void TriggerFeatureItemUpdate(FeatureItem* item);

        void OnOpenMenu(FeatureItemContainer* item_cont);

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification,
                                               const Property* property,
                                               const DataItem& value);

        virtual DataItem GetContextDataItem(ContextFeature* feature);

    protected:
        AtlApplication();

        virtual BOOLEAN RouteMessage(const Message& msg);

        static void RegisterUserActivityListener(UserActivityListener* useractivity);
        static void UnregisterUserActivityListener(UserActivityListener* useractivity);
        static void PropagateUserActivity();

        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnMessage(const Message &msg);

        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

        virtual BOOLEAN OnContextFeatureTriggered (const FeatureID& feature_id,
                                                   const DataItem& context_item);

        virtual void UpdateContextItem(ContextFeatureItem* item);

        virtual BOOLEAN UpdateItem(Item* item);

        const ContextID* GetContextId() { return ContextManager::GetInstance().GetContextId(); }


        void AttachAtlApplicationPlugin(AtlApplicationPlugin* plugin);

    private:
        void TriggerSoftkey(INT idx);
        AtlItemMenuWindow* GetMenuWin(const MenuID& menu_id);

        static Vector<UserActivityListener*> m_useractivity_listener;

        FeaturePool m_features;
        Vector<AtlItemMenuWindow*> m_menu_vec;
        Vector<AtlApplicationPlugin*> m_app_plugins;
};

#endif  // Atl_AtlApplication_hpp

