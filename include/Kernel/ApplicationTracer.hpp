/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(APPLICATION_TRACER_HPP)
#define APPLICATION_TRACER_HPP

#if !defined(APOXI_APPLICATION_TRACER_MAX_APPS)
    #define APOXI_APPLICATION_TRACER_MAX_APPS 50
#endif


class  _NullApplicationTracer {
    public:
        _NullApplicationTracer(const void* app) {}
        void TraceAttach(const void* app, const void* container, const WCHAR* appName) {}
        void TraceDetach(const void* app) {}
        void TraceMessage(const void* msg) {}
        static UINT8 GetCurApplicationID() { return 0; }
};  //_NullApplicationTracer

class  _ApplicationTracer {
    public:
        _ApplicationTracer(const void* app) {
            AddApplication(app);
        }
        
        void TraceAttach(const void* app, const void* container, const WCHAR* appName) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceAppAttach(linkreg, app, container, appName, GetID(app));
        }
        
        void TraceDetach(const void* app) {
            const void* linkreg=0;
            #if defined(APOXI_RTOS_NUC32)
                // get linkregister, contains caller address
                #if (__ARMCC_VERSION<200000)
                    __asm
                    {
                        mov linkreg,r14
                    }
                #else
                    linkreg = (const void*) __return_address();
                #endif
            #endif
            InternalTracer::TraceAppDetach(linkreg, app, GetID(app));
        }
        
        static unsigned char GetCurApplicationID();
        
        
    private:
        enum {
            MAX_APPS = APOXI_APPLICATION_TRACER_MAX_APPS
        };
        
        static const void* g_apps[MAX_APPS];
        static UINT8 g_appID;
        
        static void AddApplication(const void* app) {
            if (g_appID < MAX_APPS-1)
                g_apps[++g_appID] = app;
        }   // AddApplication
        
        
        static UINT8 GetID(const void* app) {
            for (UINT8 i=0; i<=g_appID; i++) {
                if (app == g_apps[i])
                    return i;
            }
            return 0;
        }   // GetID
        
};  // _ApplicationTracer


#endif // APPLICATION_TRACER_HPP


