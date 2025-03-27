/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Gprs_PdpTypes_hpp)
#define Apc_Gprs_PdpTypes_hpp

#include <Apc/SignalTypes.hpp>

typedef T_PCH_REG_CLIENT PchClient;

typedef T_CID PdpCid;

typedef T_ATT_STATE PdpAttachState;

enum L2Protocol {
    L2Null = L2_NULL,
    L2Ppp = L2_PPP,
    L2Pad = L2_PAD,
    L2X25 = L2_X25,
    L2Manuf = L2_MANUF,
    L2None = L2_NONE,
};

typedef T_CID_STAT_ARRAY PdpCidStatArray; // fill up with context data or replace with existing structs (Sockets)

typedef T_CID_ARRAY PdpCidArray;    // fill up with context data or replace with existing structs (Sockets)

typedef T_PDP_CONTEXT PdpContextData;   // fill up with context data or replace with existing structs (Sockets)

typedef T_QOS Qos;  // fill up with context data or replace with existing structs (Sockets)

typedef T_PDP_QOS PdpQos;   // fill up with context data or replace with existing structs (Sockets)

typedef T_AUTH PdpAuthentification; // fill up with context data or replace with existing structs (Sockets)

typedef T_PDP_ARRAY PdpArray;   // fill up with context data or replace with existing structs (Sockets)

typedef T_QOS_ARRAY PdpQosArray;    // fill up with context data or replace with existing structs (Sockets)

enum PdpType {
    PdpX25Type = X25_TYPE,
    PdpIpType = IP_TYPE,
    PdpIpStaticType = IP_TYPE_STATIC, 
    PdpIpDynamicType = IP_TYPE_DYNAMIC,
    PdpOspihType = OSPIH_TYPE,
    PdpPppType = PPP_TYPE,
    PdpNoType = NO_TYPE
};

typedef T_PDP_ADDRESS PdpAddress;

enum PchOrigin {
    PchNw = PCH_NW,
    PchMs = PCH_MS
};

#endif  // Apc_Gprs_PdpTypes_hpp

