/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtlApplicationPlugin_hpp)
#define AtlApplicationPlugin_hpp

#include <Kernel/UserDispatcher.hpp> 
#include <Atl/Features/FeatureID.hpp>
#include <Atl/Properties/Property.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Features/ContextFeatureItem.hpp>
#endif  // APOXI_COMPAT_2_7_0

class Application;
class ContextFeatureItem;
class Action;
class Item;

class AtlApplicationPlugin : public UserDispatcher
{
      typedef UserDispatcher Base;
        
    
   public:
        
      virtual ~AtlApplicationPlugin();

      virtual void Init(Application *host_application);
                
      void Attach();
        
      void Detach();
        
      Application *GetApplication() { return m_app; }

      const WCHAR* GetPluginName() const { return m_plugin_name; }
        
      void SetPluginName(const WCHAR* plugin_name) { m_plugin_name = plugin_name; }
        
      virtual void OnUpdateContextItem(ContextFeatureItem* item);
    
      virtual BOOLEAN OnPropertyNotification(const Property::Notification notification, 
                                             const Property* property, 
                                             const DataItem& value);
        
   protected:
      AtlApplicationPlugin();
        
      virtual BOOLEAN OnMessage(const Message &msg);
        
      virtual BOOLEAN OnKeyDown(KeyCode key_code);
        
      virtual BOOLEAN OnKeyUp(KeyCode key_code, UINT32 duration);
        
      virtual BOOLEAN OnLongKeyPress(KeyCode key_code);

      virtual BOOLEAN OnVeryLongKeyPress(KeyCode key_code);
        
      virtual BOOLEAN OnKeyAutoRepeat(KeyCode key_code);
        
      virtual BOOLEAN OnInputChar(WCHAR chr);

      virtual BOOLEAN OnTimeout(const Timer& timer);

      virtual void OnThemeChanged();

      virtual void OnLanguageChanged();

      virtual void OnAppGetFocus();

      virtual void OnAppLoseFocus();
        
      virtual void OnAppOpen();
        
      virtual void OnAppClose();
        
      virtual BOOLEAN OnActionExecuted (Action *action);

      virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);
        
      virtual BOOLEAN OnContextFeatureTriggered(const FeatureID& feature_id, 
                                                const DataItem& item);
        
      virtual BOOLEAN UpdateItem(Item* item);
        
      const WCHAR *m_plugin_name;
      Application *m_app;
};

#endif

