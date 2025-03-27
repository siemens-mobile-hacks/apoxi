/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexTypes_hpp)
#define Apoxi_ObexTypes_hpp

#include <Kernel/Types.hpp>


typedef UINT8   ObexTransportId;

typedef UINT8   ObexAddrTypeId;

typedef UINT8   ObexServerId;

enum  ObexProtocolId {

    ObexPrIdObex,   
    ObexPrIdOpp     
};

enum  ObexMsgType {

    // Common opcodes
    ObexMsgResult,      
    ObexMsgBuffer,      

    // OBEX opcodes
    ObexMsgResponse,    
    ObexMsgPut,         
    ObexMsgGet,         
    ObexMsgConnect,     
    ObexMsgDisconnect,  
    ObexMsgSetPath,     
    ObexMsgAbort        
};

enum  ObexAppMsgType {

    ObexAppMsgTransportSelectionReq
};

enum  ObexTransportMsgType {

    ObexTrAvStateChanged,

    ObexTrEnableRejected,

    ObexTrSelectionResult
};

#endif  // Apoxi_ObexTypes_hpp

