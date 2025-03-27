/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsSocketListener_hpp)
#define Asc_SmsSocketListener_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/MutexObtainer.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>

#include <Apc/InformationElement.hpp>
#include <Apc/SignalHandler/SignalMapTableEntry.hpp>

#include "SmsSocket.hpp"

#if ! defined(APOXI_SMSSOCKET_MAX_SUBSCRIBED_APPS)
    #define APOXI_SMSSOCKET_MAX_SUBSCRIBED_APPS 2
#endif

#if ! defined(APOXI_SMSSOCKET_MAX_CACHED_TPDUS)
    #define APOXI_SMSSOCKET_MAX_CACHED_TPDUS 12
#endif


class SmsSocketSignalMapTableNode;
/*  ========================================================================
    SmsSocketListener
    ======================================================================== */
class SmsSocketListener {
    enum {
        c_max_subscribed_contexts = APOXI_SMSSOCKET_MAX_SUBSCRIBED_APPS,
        c_max_cached_tpdus = APOXI_SMSSOCKET_MAX_CACHED_TPDUS,
        c_max_confirm_info = c_max_subscribed_contexts * c_max_cached_tpdus
    };

    friend class SmsSocket;
    friend class SmsSocketSignalMapTableNode;
    public:
        // one time initialization method (called in init method of referring system - StackControl::OnPowerUp())
        static void Startup();

        static BOOLEAN Register(SmsSocket *sms_socket);

        static SmsSocket* GetSocket(SmsPortNo sms_port_no);

        static BOOLEAN Unregister(SmsSocket *sms_socket);

        static BOOLEAN IsInUse(SmsPortNo sms_port_no);

        static BOOLEAN HasPorts(ExecutionContext *context = 0);

        static BOOLEAN Subscribe(ExecutionContext *context);

        static BOOLEAN Unsubscribe(ExecutionContext *context);

        static BOOLEAN Confirm(ExecutionContext *context, SmsPortNo portno, BOOLEAN accept);

        static BOOLEAN EmptyCache(SmsPortNo portno);

        // dump debug info
        static void DumpTables();

    private:
        struct ConfirmInfo {
            ExecutionContext* m_context;
            Tpdu *        m_tpdu;
            SmsPortNo     m_portno;
            BOOLEAN       m_confirmed;
            BOOLEAN       m_confirmed_state;
        };

        class Lock : public MutexObtainer {
            public:
                Lock() : MutexObtainer(&SmsSocketListener::m_mutex) { };
        };
        friend class Lock;

        static BOOLEAN m_initialized;
        static Mutex m_mutex;
        static LinkedList<SmsSocket>   m_sms_socket_list;
        static ExecutionContext* m_subscribed_contexts[c_max_subscribed_contexts];
        static Tpdu *                  m_cached_tpdus[c_max_cached_tpdus];
        static ConfirmInfo             m_confirm_info[c_max_confirm_info];


        // Processes new incoming signal, stored socket info and sends back acknowledge to stack
        static void ProcessIncomingPortSms(const ProcessPtr &process_ptr);
        
        /* Returns the next socket found for the given context, starting the search 
            (in global list) with *sms_socket. Locking, if needed, must be done from calling instance. */
        static SmsSocket* SearchSocket(ExecutionContext *context, SmsSocket *sms_socket = 0);

        /* Returns the next socket with the port number sms_port_no, starting the search 
            (in global list) with *sms_socket. Normally there exists only one socket for one port number! 
            Locking, if needed, must be done from calling instance. */
        static SmsSocket* SearchSocket(SmsPortNo sms_port_no, SmsSocket *sms_socket = 0);

        // Checks if an context is subscribed
        static BOOLEAN IsSubscribed(ExecutionContext *context);
        // Checks if any context is subscribed
        static BOOLEAN HasSubscription();

        // puts Tpdu into the cache
        static BOOLEAN PutIntoCache(Tpdu * tpdu);
        // remove Tpdu from cache
        static BOOLEAN RemoveFromCache(Tpdu * tpdu);
        // insert the confirmation information
        static BOOLEAN InsertConfirmInfo(ExecutionContext* context, Tpdu* tpdu, SmsPortNo smsportno);
        // checks if a tpdu with a certain portno can be deleted out of the cache, when 
        // all contexts have confirmed and no context was interested
        static BOOLEAN CheckTpduDeletion(SmsPortNo portno);
        static BOOLEAN PushTpdus(SmsSocket * socket);

        static void DeleteConfirmInfo(Tpdu * tpdu);


};

#endif  // Asc_SmsSocketListener_hpp


