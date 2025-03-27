    /*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CallHandler_hpp)
#define Asc_CallHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/CallDispatcher.hpp>
#include <Asc/DtmfDispatcher.hpp>


enum CallApiRc;

class CallHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = CallHandlerId };
        
        CallHandler();
        virtual ~CallHandler();
        
        virtual HandlerId GetHandlerId() const;

        CallDispatcher * GetCallDispatcher() { return &m_call_disp; }


        DtmfDispatcher * GetDtmfDispatcher() { return &m_dtmf_disp; }


#if defined(APOXI_SYNC_RELEASE)
        CallApiRc Release(CallIndex call_index, UINT32 & call_duration, CallErrorCause cause, BOOLEAN wait_condition = TRUE);
#else
        CallApiRc Release(CallIndex call_index, UINT32 & call_duration, CallErrorCause cause, BOOLEAN wait_condition = FALSE);
#endif


        CallApiRc StartDtmfToneGeneration(CallIndex idx, KeyCode key);


        CallApiRc StopDtmfToneGeneration(CallIndex idx);


        static CallApiRc RejectAllMtc(BOOLEAN activate);

        static CallApiRc RejectAllMoc(BOOLEAN activate);

        static void ClearBlacklist();


        static void SetMnRediallingEnabled(BOOLEAN action);
        
        static void RequestRedialStatus();

#if !defined(APOXI_PLATFORM_BP30)


        static BOOLEAN SetDefaultClirMode(ClirMode clir_mode);


        static BOOLEAN GetDefaultClirMode(ClirMode &clir_mode);


        static BOOLEAN SetDefaultCugInfo(const CugDescriptor& cug_desc);


        static BOOLEAN GetDefaultCugInfo(CugDescriptor& cug_desc);

#endif // !APOXI_PLATFORM_BP30
        
    private:
        static CallApiRc RejectAllCalls(BOOLEAN activate, CallRefuseDirection direction);

        CallDispatcher  m_call_disp;
        DtmfDispatcher  m_dtmf_disp;
};

#endif // Asc_CallHandler_hpp


