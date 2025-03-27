/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_IpAddrPrompt_hpp)
#define Apoxi_IpAddrPrompt_hpp

#include <GuiExtensions/AbstractMmiPrompt.hpp>
#include <Gui/IpAddrEditor.hpp>

class IpAddrPrompt : public AbstractMmiPrompt {
    public:
        typedef AbstractMmiPrompt Base;

        IpAddrPrompt();
        virtual ~IpAddrPrompt();

        void Init(const WCHAR* title = 0);

        void SetIpAddr(const IpAddr &ip_addr) { m_editor.SetIpAddr(ip_addr); }
        IpAddr GetIpAddr() { return m_editor.GetIpAddr(); }
        
    protected:
        virtual AbstractEditor* GetEditor() { return &m_editor; }

    private:
        IpAddrEditor    m_editor;
};

#endif  // Apoxi_IpAddrPrompt_hpp

