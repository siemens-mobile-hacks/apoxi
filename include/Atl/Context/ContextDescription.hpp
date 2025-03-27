//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_ContextDescription_hpp)
#define Atl_Context_ContextDescription_hpp

#include <Atl/Context/ContextID.hpp>
#include <Atl/Context/SoftkeyDesc.hpp>
#include <Atl/Context/KeyMapping.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Config/KeyboardConfig.hpp>
#include <Config/Config.hpp>
#endif  // APOXI_COMPAT_2_7_0

#if defined(APOXI_COMPAT_2_6_0)
#include <Atl/Gui/IndicatorDescription.hpp>
typedef Vector<IndicatorDescription*> IndicatorDescriptionContainer;
typedef Vector<IndicatorDescription*>::Iterator IndicatorDescriptionContainerIterator;
typedef Vector<IndicatorDescription*>::ConstIterator IndicatorDescriptionContainerConstIterator;
#endif

class ContextDescription {
    public:
        ContextDescription();

        ~ContextDescription();

        void Init(const ContextID& context_id) { m_context_id = context_id; }

        void Init(const ContextID& context_id, 
                  const WString& window_title) { Init(context_id), m_window_title = window_title; }

        void SetSoftkeyDesc(INT sk_index, 
                            SoftkeyDesc sk_desc) { m_sk_desc[sk_index] = sk_desc; }

        const SoftkeyDesc& GetSoftkeyDesc(INT sk_index) { return m_sk_desc[sk_index]; }
          
        void SetWindowTitle(const WString& title) { m_window_title = title; }
          
        const WString& GetWindowTitle() { return m_window_title; }

        const ContextID& GetContextId() { return m_context_id; }

        KeyMapping& GetKeyMap() { return m_key_mapping;}

#if defined(APOXI_COMPAT_2_6_0)

        void AddIndicatorDescription(IndicatorDescription* desc);

        void RemoveIndicatorDescription(IndicatorDescription* desc);

        IndicatorDescriptionContainerIterator GetIndicatorDescriptionsBeginIterator();

        IndicatorDescriptionContainerIterator GetIndicatorDescriptionsEndIterator();
#endif
    
    private:
        ContextID m_context_id;
        SoftkeyDesc m_sk_desc[APOXI_MAX_SOFTKEY_COUNT];
        WString m_window_title;
        KeyMapping  m_key_mapping;
    
#if defined(APOXI_COMPAT_2_6_0)
        IndicatorDescriptionContainerIterator FindIndicatorDescription(IndicatorDescription* desc);
        IndicatorDescriptionContainer m_indicators;
#endif
};

#endif // Atl_Context_ContextDescription_hpp 


