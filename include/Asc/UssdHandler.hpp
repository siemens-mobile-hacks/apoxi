/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_UssdHandler_hpp)
#define Asc_UssdHandler_hpp

#include <Kernel/Types.hpp>

#include <Apc/SsStackMsgArgs.hpp>

#include <Asc/SsBaseHandler.hpp>


class UssdBeginMsg;
class UssdNotifyMsg;
class UssdRequestMsg;


class UssdHandler : public SsBaseHandler {
    friend class UssdBeginMsg;

    typedef SsBaseHandler Base;

public:
    enum { ID = UssdHandlerId };    
    UssdHandler();
         
    virtual HandlerId GetHandlerId() const;
        
    // SCCH - TBD
    // Do we need to be able to send SSEndReqInds?

    
    virtual SsApiRc Acknowledge(const UssdNotifyMsg& msg);

    virtual SsApiRc Acknowledge(Tipd tipd);

    virtual SsApiRc Reply(const UssdRequestMsg& msg, const WString& ctrl_info, const DataCodingScheme& dcs);

    virtual SsApiRc Reply(Tipd tipd, const WString& ctrl_info, const DataCodingScheme& dcs);

    virtual SsApiRc SendError(Tipd tipd, SsErrorCode error_code);

    virtual SsApiRc SendRejection(Tipd tipd, TaggedProblemCode code = TaggedProblemCode::ResourceLimitation);

protected:
    virtual ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument& arg);

    SsApiRc BeginTransaction(const SsStackMsgArgument& arg);

    virtual ReturnCode EndTransaction(const Tipd tipd);

private:
    ReturnCode CreateRequestMsg(const SsUssdIndArg& arg, SsMessage*& msg) const;

    ReturnCode CreateNotifyMsg(const SsUssdIndArg& arg, SsMessage*& msg) const;
};

#endif // Asc_UssdHandler_hpp


