/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CallHdlBase_hpp)
#define Asc_CallHdlBase_hpp


// #define NO_CALL_DEBUG

#include <Asc/Types.hpp>
#include <Auxiliary/TimeSpan.hpp>
#include <Auxiliary/DateTime.hpp>

class CallHdlBase {

    public:

        //---------------------------------------------------------------------
        // Construction, destruction 
        //---------------------------------------------------------------------
        
        CallHdlBase();

        virtual ~CallHdlBase();


        // --------------------------------------------------------------------
        // call related operations on CallHdl
        // --------------------------------------------------------------------

#if defined(APOXI_SYNC_RELEASE)
        virtual CallApiRc Release(TimeSpan * calling_time = 0, BOOLEAN wait_condition = TRUE) = 0;
#else
        virtual CallApiRc Release(TimeSpan * calling_time = 0, BOOLEAN wait_condition = FALSE) = 0;
#endif


        static CallApiRc ReleaseAllActiveCalls();


        static CallApiRc ReleaseAllHeldCalls();

        
        static void ReportCurrentCallMeter(BOOLEAN activate);


        static void ReportCurrentCharge(BOOLEAN activate);


        virtual CallApiRc Swap();

        
        virtual CallApiRc Join();

        virtual BOOLEAN IsActive() const = 0;
        
        virtual BOOLEAN IsHeld() const = 0;

        virtual BOOLEAN IsValid() const = 0;


        virtual DateTime GetStartTime() const = 0;

        virtual TimeSpan GetCallDuration() const = 0;

        virtual CallApiRc StartDtmfToneGeneration(KeyCode key){return UnexpectedResult;}
        
        virtual CallApiRc StopDtmfToneGeneration(){return UnexpectedResult;}

        // --------------------------------------------------------------------
        // misc
        // --------------------------------------------------------------------

        virtual BOOLEAN IsHoldPermitted() const = 0;

        virtual BOOLEAN IsRetrievePermitted() const = 0;
        
        BOOLEAN IsSwapPermitted() const;

        BOOLEAN IsJoinPermitted() const;

        static CallApiRc RejectAllMtc(BOOLEAN activate);

        static CallApiRc RejectAllMoc(BOOLEAN activate);

        static void ClearBlacklist();

        static void SetRediallingEnable(BOOLEAN action);

        virtual void Invalidate() = 0;

        virtual CallIndex GetCallIndex() const = 0;

        static INT GetCallCount();



        static CallErrorCause ReadLastMnCause();
#if !defined(NO_CALL_DEBUG)     
        static WString & GetStatusString();

        static WString m_status_string;

#endif // NO_CALL_DEBUG

};

#endif // Asc_CallHdlBase_hpp


