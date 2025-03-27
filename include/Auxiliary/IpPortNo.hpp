/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IpPortNo_hpp)
#define Apoxi_IpPortNo_hpp

#include <Auxiliary/Iana.hpp>
#include <Kernel/MachType.hpp>

class IpPortNo {
    public:
        IpPortNo(UINT16 port = 0, BOOLEAN convert_from_native = FALSE);

        IpPortNo(Iana::PortNumber n);

        UINT16 GetPortNumber() const { return m_port.m_val.m_uint16; }

        UINT16 GetNativePortNumber() const { return Native16Bit(m_port).m_val.m_uint16; }

    private:
        BigEndian16Bit m_port;
};

#endif  // Apoxi_IpPortNo_hpp

