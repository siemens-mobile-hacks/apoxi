/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_ClirHandler_hpp)
#define Asc_ClirHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/SsClHandler.hpp>

class ClirHandler : public SsClHandler {
    typedef SsClHandler Base;

public:
    enum { ID = ClirHandlerId };    
         
    virtual HandlerId GetHandlerId() const;
        
    SsApiRc RequestStatus(const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE);


protected:
    virtual ReturnCode CreateInterrogateResultMsg(const SsInterrogateIndArg &arg, SsMessage*& msg) const;

    virtual BOOLEAN CheckSelector(const SsInterrogateIndArg &arg) const;
};

#endif // Asc_ClirHandler_hpp


