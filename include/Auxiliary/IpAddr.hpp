/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_IpAddr_hpp)
#define Apoxi_IpAddr_hpp

#include <Kernel/MachType.hpp>
#include <Auxiliary/String.hpp>

/*  -------------------------------------------------------------------------
                                Types
    ------------------------------------------------------------------------- */


class IpAddr {
    public:
        enum PredefIpAddr {
            c_ipaddr_loopback,
            c_ipaddr_any,
            c_ipaddr_broadcast
        };

        typedef UINT32 Persist;

        IpAddr(UINT32 addr = 0, BOOLEAN convert_from_native = FALSE);

        IpAddr(UINT8 a, UINT8 b, UINT8 c, UINT8 d);

        IpAddr(const CHAR *str, INT len = -1);

        IpAddr(PredefIpAddr pre);

        IpAddr(const WCHAR *str, INT len = -1);

        UINT32 GetAddr() const { return m_addr.m_val.m_uint32; }

        UINT32 GetNativeAddr() const { return Native32Bit(m_addr).m_val.m_uint32; }

        void SetAddr(UINT32 addr, BOOLEAN convert_from_native = FALSE);

        UINT8 GetAPart() const { return m_addr.m_val.m_uint8.m_a; }
        void SetAPart(UINT8 a) { m_addr.m_val.m_uint8.m_a = a; }
        UINT8 GetBPart() const { return m_addr.m_val.m_uint8.m_b; }
        void SetBPart(UINT8 b) { m_addr.m_val.m_uint8.m_b = b; }
        UINT8 GetCPart() const { return m_addr.m_val.m_uint8.m_c; }
        void SetCPart(UINT8 c) { m_addr.m_val.m_uint8.m_c = c; }
        UINT8 GetDPart() const { return m_addr.m_val.m_uint8.m_d; }
        void SetDPart(UINT8 d) { m_addr.m_val.m_uint8.m_d = d; }

        BOOLEAN InitFrom(const CHAR *str, INT len = -1);

        BOOLEAN InitFrom(const WCHAR *str, INT len = -1);

        void operator<<(const Persist &p) { m_addr.m_val.m_uint32 = p; }

        void operator>>(Persist &p) const { p = m_addr.m_val.m_uint32; }

        String Verbose() const;

    private:
        BigEndian32Bit m_addr;
};

#endif  // Apoxi_IpAddr_hpp


