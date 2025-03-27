/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MsgArgs_hpp)
#define Asc_MsgArgs_hpp

#include <Kernel/Os/Os.hpp>

#include <Asc/CallHdl.hpp>
#include <Apc/DataCodingScheme.hpp>


struct CallDisconnectingArg {
    // A <em>CallHdl</em> object holding the <em>call_index</em> of the disconnected call. 
    CallHdl         call;
    // The phone number of the call, since the <em>CallInstance</em> has already been deleted. 
    PhoneNumber     phone_no;
    // The cause for the disconnect. Supplied by MN. 
    CallErrorCause  cause;
    // The time span, since the call has been established. 
    TimeSpan        call_duration;
};

struct CallInfoArg {
    CallHdl     call;
    CallState   state;
    CallType    type;
};

struct DtmfStartCnfArg {
    CallHdl call;
    KeyCode     key;
};


struct DtmfRejectArg {
    CallHdl call;
    CallErrorCause  cause;
};


struct CallSetupProgressArg {
    CallHdl call;
    CallProgressInd progress_ind;
};


enum RemotePartyActionArg {
    RemoteHold,
    RemoteRetrieve,
    RemoteMbuild,
    VoidAction
};


struct ForwardingInfoReceivedArg {
    SsOperationCode operation_code;
    ForwardingInfo  forwarding_info;
};


struct BarringInfoReceivedArg {
    SsOperationCode operation_code;
    CallBarringInfo barring_info;
};


struct SsDataReceivedArg {
    SsOperationCode operation_code;
    SsData          data;
};


struct SsNotificationArg {
    SsOperationCode operation_code;
    NotifySsArg notify_arg;
};


struct InterrogationResultArg {
    SsOperationCode operation_code;
    InterrogateSsResult result;
};


struct PasswordReceivedArg {
    SsOperationCode operation_code;
    WString password;
};


struct UssDataArg {
    SsOperationCode operation_code;
    WString uss_data;
    DataCodingScheme dcs;
};



#endif  // Asc_MsgArgs_hpp


