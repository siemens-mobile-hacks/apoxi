 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CrssHandler_hpp)
#define Asc_CrssHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/CrssDispatcher.hpp>

// class CallHandlingData;
class CrssDispatcher;

// enum CallApiRc;

class CrssHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = CrssHandlerId };
        
        CrssHandler();
        virtual ~CrssHandler();
        
        virtual HandlerId GetHandlerId() const;


        SsErrorCode GetLastErrorCode() const { return m_last_error_code; }


        CallApiRc Hold(CallIndex idx) ;


        CallApiRc Retrieve(CallIndex idx) ;

        
        CallApiRc SwapCalls() const;


        CallApiRc ReleaseAllHeldCalls() const;


        CallApiRc ReleaseAllActiveCalls() const; 


        CallApiRc ReleaseActiveCall() const;


        CallApiRc JoinCalls();

        CallApiRc SplitMpty(CallIndex call_index);

        
#if defined(APOXI_SYNC_RELEASE)
        CallApiRc ReleaseMpty(UINT32 & duration, BOOLEAN wait_condition = TRUE) const;
#else
        CallApiRc ReleaseMpty(UINT32 & duration, BOOLEAN wait_condition = FALSE) const;
#endif


        CallApiRc ExplicitCallTransfer(CallIndex call_index); 
        
    private:
#if defined(APOXI_SYNC_RELEASE)
        CallApiRc CrssRelease(CallIndex call_index, CallRelatedSs crss, BOOLEAN wait_condition = TRUE) const;
#else
        CallApiRc CrssRelease(CallIndex call_index, CallRelatedSs crss, BOOLEAN wait_condition = FALSE) const;
#endif
        CallApiRc ProcessCrssRequest(CallIndex call_index, CallRelatedSs crss);
        //CallApiRc SwapCallAndMpty(); Methode removed because of CN200007816

        CrssDispatcher *m_crss_disp;
        SsErrorCode     m_last_error_code;
};

#endif // Asc_CrssHandler_hpp


