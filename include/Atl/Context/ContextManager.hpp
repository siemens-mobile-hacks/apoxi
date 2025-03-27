//  ------------------------------------------------------------------------
//  Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
//  All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------

#if !defined(Atl_Context_ContextManager_hpp)
#define Atl_Context_ContextManager_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Atl/AtlWindow.hpp>
#include <Atl/Context/KeyMapping.hpp>
#include <Atl/Context/ContextID.hpp>
#include <Atl/Context/ContextDescription.hpp>
#include <Atl/Context/ContextDescriptionTypes.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Config/AtlConfig.hpp>
#endif  // APOXI_COMPAT_2_7_0

#if defined(APOXI_COMPAT_2_6_0)
#include <Atl/Gui/IndicatorPaneObject.hpp>
#endif  // APOXI_COMPAT_2_6_0

class ContextDescription;
class ContextManager {
    friend class AtlWindow;
    public:

        static ContextManager& GetInstance() { return m_instance; }

        virtual ~ContextManager();

        void NotifyContextSwitch(AtlWindow* win, 
                                 const ContextID& context_id);

        void NotifyContextItemSwitch();

        const ContextID* GetContextId();

        Dispatcher* GetDispatcher() const { return m_dispatcher; }

        KeyMapping& GetKeyMap();

        ContextDescription* GetContextDesc(const ContextID& context_id);

    protected:
        void UpdateSoftkeys(AtlWindow* win, 
            const ContextID& context_id);

    private:
        ContextManager();
        void Init();

        void CreateContextDescriptions();
        void SetSoftkeyDescToContextDesc(ContextDescription& desc, const ContextTableEntry* entry);
        void SetKeyMapToContextDesc(ContextDescription& desc, const ContextTableEntry* entry);

        static ContextManager m_instance;

        typedef Vector<ContextDescription*> ContextDescVec;
        static ContextDescVec m_context_descriptions;

        ContextDescription* m_context_desc;
#if defined(APOXI_COMPAT_2_7_0)
        ContextDescription m_default_context;
#endif  //APOXI_2_7_0)
        Dispatcher* m_dispatcher;       
        Mutex m_mutex;
        ContextID m_last_context_id;
        BOOLEAN m_initialized;

#if defined(APOXI_COMPAT_2_6_0)
        void SetIndicatorEnvironment(AtlWindow* win);
        Vector<IndicatorPaneObject*> m_pane_objects;      
        IndicatorDescriptionContainer m_lost_indicator_descriptions;
#endif
};

#endif // Atl_Context_ContextManager_hpp 


