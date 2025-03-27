/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MainHandler_hpp)
#define Asc_MainHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/HandlerList.hpp>
#include <Asc/CallHandlingData.hpp>

class Application;      // from Kernel
class DataHandler;      // from Adc
class MainProvider;     // from Adc
class SimAccessor;      // from Adc
class BaseHandler;
class StackMsgArgument;

/*  ========================================================================
    MainHandler
    ======================================================================== */
class MainHandler : public Linkable<MainHandler>{
    public:
        MainHandler();
        virtual ~MainHandler();

        static BOOLEAN Startup();

        BOOLEAN Init(ExecutionContext *context);
        BOOLEAN Mount(HandlerId id);
        BaseHandler* GetHandler(HandlerId id) const;
        BOOLEAN IsMounted(HandlerId id) const;
        BOOLEAN Unmount(HandlerId id);
        BOOLEAN Cleanup();

        ExecutionContext* GetExecutionContext() const;

        static CallHandlingData* GetCallHandlingData() { return &m_call_handling_data; }

        static Mutex* GetCallDataMutex() { return &m_call_data_mutex; }

        static void PostMsg(const Message & msg);
        static void PostToStackMsg(StackMsgArgument * arg);


    private:
        ExecutionContext *m_context;
        HandlerList m_handler_list;

        static Mutex            m_call_data_mutex; // 
        static CallHandlingData m_call_handling_data;
        static BOOLEAN          m_call_data_mutex_is_initialized;
        static const struct HandlerDependency {
            HandlerId trigger;
            HandlerId to_mount;
        } m_handler_dependency_table[];

        void MountDependentHandler(HandlerId trigger);
        void UnmountDependentHandler(HandlerId trigger);
        
        HandlerListEntry* GetHandlerListEntry(HandlerId id) const;

        BOOLEAN IsInitialized() const { return (m_context != 0); }
};

/*  ========================================================================
    HandlerList
    ======================================================================== */
typedef LinkedList<MainHandler> MainHandlerList;

#endif


