/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_SsClHandler_hpp)
#define Asc_SsClHandler_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Kernel/Types.hpp>

#include <Asc/SsBaseHandler.hpp>

class SsClHandler : public SsBaseHandler {
    typedef SsBaseHandler Base;

protected:
    SsApiRc Interrogate(const InputParser::SsCode mmi_ss_code, const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE);

    virtual ReturnCode CreateInterrogateResultMsg(const SsInterrogateIndArg &arg, SsMessage*& msg) const = 0;

    virtual ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &arg);

    virtual BOOLEAN CheckSelector(const SsInterrogateIndArg &arg) const;
};
#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // Asc_SsClHandler_hpp


