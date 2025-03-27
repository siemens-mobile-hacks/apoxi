/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MainHandlerAccess_hpp)
#define Asc_MainHandlerAccess_hpp

#include <Auxiliary/Macros.hpp>


class Application;
class DataHandler;
class MainHandler;
class CallHandlingData;
class Semaphore;
class Mutex;

/*  ========================================================================
    MainHandlerAccess
    ======================================================================== */
class MainHandlerAccess {
    public:
        MainHandlerAccess(MainHandler *main_handler = 0);
        ~MainHandlerAccess();

        Application* GetApplication();
        
        MainHandler* GetMainHandler() const { return (m_main_handler); };

    private:
        MainHandler *m_main_handler;
};

#endif // Asc_MainHandlerAccess_hpp


