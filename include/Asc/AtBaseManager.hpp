/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AtBaseManager_hpp)
#define Apoxi_AtBaseManager_hpp

#if defined(APOXI_ENABLE_GENERIC_AT_INTERFACE)

#include <Apc/AtcTypes.hpp>

class AtBaseManager {
    
    public:

        static AtBaseManager& GetInstance();

        /*  ----------------------------------------------------------------
                                AT command specific
            ---------------------------------------------------------------- */

        typedef BOOLEAN (*CallBackFn)(const String& str);       
        struct CallBackItem {
            CallBackFn  fn;
            INT         timeout;
        };

        BOOLEAN Parse(const String& str);
        
        BOOLEAN SplitAtCommand(const String& str, const String& token, 
                               String& cmd_str, String& arg_str);

        BOOLEAN SendAtResponse(const String& str, const BOOLEAN final = TRUE);

        BOOLEAN Register(const String& cmd_str, const INT timeout, CallBackFn fn = 0);

        BOOLEAN Unregister(const String& cmd_str);

        void SetCallBackFn(const CallBackFn fn) { m_fn = fn; }

        void ResetCallBackFn() { m_fn = 0; }

        /*  ----------------------------------------------------------------
                            accessory application specific
            ---------------------------------------------------------------- */

        typedef BOOLEAN (*AccCallBackFn)(const BOOLEAN enable);

        void SetAccessoryCallBackFn(const AccCallBackFn fn) { m_acc_fn = fn; }

        void ResetAccessoryCallBackFn() { m_acc_fn = 0; }

        void SendAccessoryRegistrationRequest(const BOOLEAN enable);

        void SendAccessoryRegistrationResponse(const AtStatusType status, 
            const BOOLEAN enable);
        
        BOOLEAN IsAccessoryRegistrationEnabled() const { return m_acc_registered; }

        BOOLEAN SendAccessoryCommand(const String& acc_str);
        
    private:
        
        static void OnTimeout(void *);
        
        /* Extract command header from full string.
            @param str          AT command string
            @param cmd_str      extracted command header
            @param pass_through allow to assign str to cmd_str 
                                when splitting fails
            @return             TRUE, if successfully split */
        BOOLEAN ExtractCommandString(const String& str, String& cmd_str, 
                                     const BOOLEAN pass_through = FALSE);
        void TrimAtCommand(String& str);
        BOOLEAN SendAtResponse(AtStatusType status, const String& str, 
            const BOOLEAN final = TRUE);
        Semaphore m_sem;
        SimpleMap<String, CallBackItem> m_map;
        CallBackFn m_fn;
        SystemTimer m_timer;
        AccCallBackFn m_acc_fn;
        BOOLEAN m_acc_registered;
};

#endif  // APOXI_ENABLE_GENERIC_AT_INTERFACE

#endif  // Apoxi_AtBaseManager_hpp

