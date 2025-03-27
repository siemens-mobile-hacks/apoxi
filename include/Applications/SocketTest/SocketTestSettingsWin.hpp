/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiaPP_SocketTestSettingsWin_hpp)
#define ApoxiaPP_SocketTestSettingsWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/MmiMenuWindow.hpp>
#include <GuiExtensions/MmiPrompt.hpp>
#include "IpAddrPrompt.hpp"

class SocketTestSettingsWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        SocketTestSettingsWin();
        virtual ~SocketTestSettingsWin();

        void Init();

    protected:
        virtual void OnActionExecuted(Action* action);
        
    private:
        Action m_select_action;
        Action m_close_action;

        ItemContainer m_choose_tests_item_container;
        Action m_disable_all_tests_action;
        Action m_choose_default_tests_action;
        Action m_gateway_ip_action;
        Action m_gateway_port_action;
        Action m_max_tcp_packet_size_action;
        Action m_max_udp_packet_size_action;
        Action m_max_tcp_sockets_action;
        Action m_max_udp_sockets_action;
        Action m_timeout_action;

        ItemMenu m_menu;

        IpAddrPrompt m_gateway_ip_prompt;
        MmiPrompt m_prompt;

        void UpdateGatewayIp();
        void UpdateGatewayPort();
        void UpdateMaxTcpPacketSize();
        void UpdateMaxUdpPacketSize();
        void UpdateMaxTcpSockets();
        void UpdateMaxUdpSockets();
        void UpdateTimeout();
        void EnterValue(const WCHAR*title, UINT32 &value);

        void AddChooseTestsItems();
};

#endif  // ApoxiaPP_SocketTestSettingsWin_hpp

