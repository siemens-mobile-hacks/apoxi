/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IpAddrCompoundItem_hpp)
#define Apoxi_IpAddrCompoundItem_hpp

#include <Auxiliary/IpAddr.hpp>
#include <Gui/CompoundItem.hpp>

class IpAddrCompoundItem : public CompoundItem {
    typedef CompoundItem Base;

    public:
        enum {
            ID = 9
        };

        static IpAddrCompoundItem* CreateInstance(const IpAddr& ip_addr = IpAddr());

        virtual ~IpAddrCompoundItem();

        virtual INT GetId() const;

        void SetIpAddr(UINT32 ip_addr) { m_ip_addr.SetAddr(ip_addr); }

        void SetIpAddr(const IpAddr& ip_addr) { m_ip_addr = ip_addr; }

        const IpAddr& GetIpAddr() const { return m_ip_addr; }

        virtual void Draw(DeviceContext* dc,
                          XYDIM x,
                          XYDIM y,
                          INT index,
                          INT count) const;

        virtual INT WrapLine(INT index,
                             XYDIM width,
                             WrapPolicy wrap_policy = EditorDocument::WhitespaceWrap) const;

        virtual XYDIM GetLineWidth(INT index, INT count) const;

        virtual XYDIM GetLineHeight(INT index, INT count, XYDIM* baseline = 0) const;
        
        virtual INT GetItemCount() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

    protected:
        IpAddrCompoundItem(const IpAddr& ip_addr = IpAddr());

    private:
        IpAddr  m_ip_addr;
};

#endif  // Apoxi_IpAddrCompoundItem_hpp


