/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_ServerAddressWin_hpp)
#define Mmi_ServerAddressWin_hpp

#include <Common/MmiWindow.hpp>
#include <Gui/IpAddrEditor.hpp>

class ServerAddressWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        ServerAddressWin();

        virtual ~ServerAddressWin();

        void Init();


    protected:

        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

        virtual void OnLayoutClient();


    private:

        TextBox m_label_gl_server_addr;

        IpAddrEditor m_gl_server_addr;

        TextBox m_label_wai_address;

        LineEditor m_wai_address;

        TextBox m_label_ff_address;

        LineEditor m_ff_address;

}; // ServerAddressWin

#endif // Mmi_ServerAddressWin_hpp
