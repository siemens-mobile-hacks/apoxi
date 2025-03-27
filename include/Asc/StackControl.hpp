/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_StackControl_hpp)
#define Asc_StackControl_hpp

#include <Kernel/SubSystem.hpp>
#include <Asc/MainHandler.hpp>

class BaseHandler;

/*  ========================================================================
    StackControl
    ======================================================================== */
class StackControl : public SubSystem {
    public:
        StackControl();

        static StackControl* GetInstance() { return m_instance; }

        virtual const WCHAR* GetName() const { return L"APOXI StackControl"; }

        virtual BootSequenceState InvokeAt() const { return (SubSystemManager::c_run_level_1); }

        virtual UINT8 GetPriority() const { return (100); } 

        virtual void OnPowerUp();

        virtual void OnPowerDown();
        
        static BOOLEAN Subscribe(HandlerId id);

        static BaseHandler* GetHandler(HandlerId id);

        static BOOLEAN Unsubscribe(HandlerId id);

    private:
        static StackControl     *m_instance;
        static MainHandlerList  m_main_handler_list;

        // returns the MainHandler of the active application context
        static MainHandler* GetActiveMainHandler();
};

#endif  // Asc_StackControl_hpp


