/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_ColrHandler_hpp)
#define Asc_ColrHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/SsClHandler.hpp>

class ColrHandler : public SsClHandler {
    typedef SsClHandler Base;

public:
    enum { ID = ColrHandlerId };    
         
    virtual HandlerId GetHandlerId() const;
        
    SsApiRc RequestStatus(const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE);


protected:
    virtual ReturnCode CreateInterrogateResultMsg(const SsInterrogateIndArg &arg, SsMessage*& msg) const;
};

#endif // Asc_ColrHandler_hpp


