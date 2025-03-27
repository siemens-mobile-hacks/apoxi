/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\bt_avrcp_multiconnection\lnz_apoxi\Apoxi\Bluetooth\AVRCP\BtAvrcpNotificationMessageArgument.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Bluetooth_AVRCP_BtAvrcpNotificationMessageArgument_hpp)
#define Bluetooth_AVRCP_BtAvrcpNotificationMessageArgument_hpp
#include <Apc/StackMsgArgument.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class BtAvrcpNmaConnect
    ====================================================================== */
class BtAvrcpNmaConnect : public StackMsgArgument {
    friend class BtAvrcpMessageArgumentsDestroyTableNode;
    public:
        BtAvrcpNmaConnect(const btapi_avrcp_connect_handle_t& btapi_hdl);
        BtAvrcpNmaConnect();
        ~BtAvrcpNmaConnect();
        
        static const BtAvrcpNmaConnect& Cast(const StackMsgArgument& arg);
        const btapi_avrcp_connect_handle_t& GetBtapiHdl() const { return m_btapi_hdl; }
        
        enum  {
            ID = 10
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtAvrcpNmaConnect*) arg); }
        
        btapi_avrcp_connect_handle_t m_btapi_hdl;
        
    };
// Inline definitions
inline const BtAvrcpNmaConnect& BtAvrcpNmaConnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtAvrcpNmaConnect!\n");
    return ((BtAvrcpNmaConnect &) arg);
}
/*  ======================================================================
    Class BtAvrcpNmaDisconnect
    ====================================================================== */
class BtAvrcpNmaDisconnect : public StackMsgArgument {
    friend class BtAvrcpMessageArgumentsDestroyTableNode;
    public:
        BtAvrcpNmaDisconnect(void* app_hdl);
        BtAvrcpNmaDisconnect();
        ~BtAvrcpNmaDisconnect();
        
        static const BtAvrcpNmaDisconnect& Cast(const StackMsgArgument& arg);
        void* GetAppHdl() const { return m_app_hdl; }
        
        enum  {
            ID = 11
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((BtAvrcpNmaDisconnect*) arg); }
        
        void* m_app_hdl;
        
    };
// Inline definitions
inline const BtAvrcpNmaDisconnect& BtAvrcpNmaDisconnect::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to BtAvrcpNmaDisconnect!\n");
    return ((BtAvrcpNmaDisconnect &) arg);
}
#endif // Bluetooth_AVRCP_BtAvrcpNotificationMessageArgument_hpp

