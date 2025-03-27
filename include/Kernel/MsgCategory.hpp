/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Kernel_MsgCategory_hpp)
#define Kernel_MsgCategory_hpp

#include <Auxiliary/ObjectReferrer.hpp>

typedef UINT16 MsgId;

typedef UINT16 MsgCategory;

enum MsgOrigin{
    externalMsg,
    internalMsg
};

struct MsgMetaData {
    MsgId       msg_id;
    MsgCategory msg_class;
    MsgOrigin   msg_origin;
};

// common message classes
const MsgCategory MC_NOT_VALID      = 0U;

const MsgCategory MC_SYSTEM         = 0x0001U;

const MsgCategory MC_CONTEXT        = 0x0002U;  

const MsgCategory MC_APP = MC_CONTEXT;

const MsgCategory MC_CONTROL        = 0x0004U;  

const MsgCategory MC_WIN = MC_CONTROL;  

const MsgCategory MC_FOCUS          = 0x0008U;  

const MsgCategory MC_BROADCAST      = 0x0100U;  


// interprocess communication specific message classes (used internally)

const MsgCategory MC_IPC            = 0x0020U;  

const MsgCategory MC_SIGNAL         = 0x0040U;  

const MsgCategory MC_AT             = 0x0080U; 

// obsolete message classes

const MsgCategory MC_STACK_CONTROL  = 0x0010U;  

//ft_old const MsgCategory MC_FOCUS_TRANSFER = 0x1000U;

#endif // Kernel_MsgCategory_hpp


