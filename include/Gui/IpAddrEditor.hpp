/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IpAddrEditor_hpp)
#define Apoxi_IpAddrEditor_hpp

#include <Gui/AbstractLineEditor.hpp>
#include <Gui/IpAddrEditorDocument.hpp>

class DefaultCaret;

class IpAddrEditor : public AbstractLineEditor {
    typedef AbstractLineEditor Base;

    public:
        enum {
            ID = 31
        };

        IpAddrEditor();

        explicit IpAddrEditor(Control* parent, const IpAddr& ip_addr = IpAddr());

        virtual ~IpAddrEditor();

        void Init(Control* parent, const IpAddr& ip_addr = IpAddr());

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;
        
        void SetIpAddr(const IpAddr& ip_addr);

        IpAddr GetIpAddr() const;

    protected:
        virtual Model* CreateModel() const;

    private:
        BOOLEAN m_valid;

        IpAddrEditorDocument* GetMyDocument() { return (IpAddrEditorDocument*)GetModel(); } //lint !e1762
        const IpAddrEditorDocument* GetMyDocument() const { return (const IpAddrEditorDocument*)GetModel(); }

        DefaultCaret* GetMyCaret() { return (DefaultCaret*)GetCaret(); }
};

#endif  // Apoxi_IpAddrEditor_hpp


