/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AtManager_hpp)
#define Apoxi_AtManager_hpp

#if defined(APOXI_ENABLE_GENERIC_AT_INTERFACE)

/*  AtManager is able to receive incoming command strings sent via AT. It will 
    only exist once so it cannot be initialized a second time. If one aims to 
    listen to a command string it has to register for it. The concept allows 
    the OnAtCommand() method to be overridden. As a result the deriving object 
    can handle forwarded AT command strings on its own. */
class AtManager {

    public:

        BOOLEAN Init(AtManager * obj);
        BOOLEAN IsInitialized();
        void Reset();

        BOOLEAN RegisterAtCommand(const String& str, const INT timeout = 0);
        BOOLEAN UnregisterAtCommand(const String& str);
        BOOLEAN SplitAtCommand(const String& str, const String& token, 
            String& cmd_str, String& arg_str);
        BOOLEAN SendAtResponse(const String& str, const BOOLEAN final = TRUE);
        
        void SetReceiveAccessoryCommandEnabled(const BOOLEAN enable);
        BOOLEAN IsAccessoryRegistrationEnabled();
        void SendAccessoryRegistrationResponse(const AtStatusType status, 
            const BOOLEAN enable);
        BOOLEAN SendAccessoryCommand(const String& acc_str);

    protected:

        virtual BOOLEAN OnAtCommand(const String& str);
        virtual BOOLEAN OnAccessoryRegistrationRequest(const BOOLEAN enable);

    private:
        
        static BOOLEAN WrapAtCommand(const String& str);
        static BOOLEAN WrapAccessoryRegistrationRequest(const BOOLEAN enable);
        static AtManager * m_registered_manager;

};

#endif  // APOXI_ENABLE_GENERIC_AT_INTERFACE

#endif  // Apoxi_AtManager_hpp

