/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CallHdl_hpp)
#define Asc_CallHdl_hpp

#include <Kernel/Os/Os.hpp>

#include <Asc/CallHdlBase.hpp>
#include <Apc/SimDataTypes.hpp>

class CallHandler;
// enum CallApiRc;
struct MptyMembers;

class CallHdl : public CallHdlBase {
    typedef CallHdlBase Base;

    public:

        //---------------------------------------------------------------------
        // Construction, destruction initialization
        //---------------------------------------------------------------------

        explicit CallHdl(CallIndex call_index = c_null_call_index); 

        virtual ~CallHdl();

        // --------------------------------------------------------------------
        // providing CallHdls for active, held and setup call
        // --------------------------------------------------------------------

        static CallHdl GetActiveCallHdl();


        static CallHdl GetHeldCallHdl();


        static CallHdl GetSetupCallHdl();


        // --------------------------------------------------------------------
        // call related operations on CallHdl
        // --------------------------------------------------------------------


        CallApiRc Setup(const PhoneNumber & phone_no, 
                        ClirMode clir_mode = DontCare,
                        BOOLEAN redial = FALSE,
                        const CugDescriptor * cug = 0,
                        LineSelector call_line = Line1,
                        BOOLEAN ctm = FALSE,
                        CallEstCause est_cause = HalfTchSpeech,
                        const EccCategory * ecc_category = 0);


        CallApiRc SetupAndRedial(const PhoneNumber & phone_no, 
                                 ClirMode clir_mode = DontCare, 
                                 const CugDescriptor * cug = 0,
                                 LineSelector call_line = Line1,
                                 BOOLEAN ctm = FALSE,
                                 CallEstCause est_cause = HalfTchSpeech,
                                 const EccCategory * ecc_category = 0);


        CallApiRc Accept();  


        CallApiRc SendAlertInd();


#if defined(APOXI_SYNC_RELEASE)
        virtual CallApiRc Release(TimeSpan * calling_time = 0, BOOLEAN wait_condition = TRUE);
#else
        virtual CallApiRc Release(TimeSpan * calling_time = 0, BOOLEAN wait_condition = FALSE);
#endif

#if defined(APOXI_SYNC_RELEASE)
        CallApiRc Reject(ClearCause cause = SubscriberBusy, BOOLEAN wait_condition = TRUE);
#else
        CallApiRc Reject(ClearCause cause = SubscriberBusy, BOOLEAN wait_condition = FALSE);
#endif
        

        virtual CallApiRc Hold();   
        

        virtual CallApiRc Retrieve();


        virtual CallApiRc StartDtmfToneGeneration(KeyCode key);

        
        virtual CallApiRc StopDtmfToneGeneration();


        static void CancelRedialling(); 


        CallApiRc ExplicitCallTransfer(); 


        CallApiRc GetCurrentCallMeter();
                    

        CallApiRc GetCurrentChargeData();


        // --------------------------------------------------------------------
        // access to miscellaneous call data
        // --------------------------------------------------------------------

        const PhoneNumber & GetPhoneNumber() const;

        const PhoneNumber & GetConnectedToPhoneNumber() const;

        CallRelatedSsCode GetSsCode() const;


        GsmSignal GetGsmSignal() const;


        virtual DateTime GetStartTime() const;      
        
        
        // --------------------------------------------------------------------
        // general information of call referred by a CallHdl
        // --------------------------------------------------------------------

        virtual BOOLEAN IsActive() const;


        virtual BOOLEAN IsHeld() const;


        BOOLEAN IsInSetup() const;


        BOOLEAN IsSame(const CallHdl & call) const;


        virtual BOOLEAN IsValid() const { return m_call_index != c_null_call_index &&
                                                 m_call_index < (CallIndex)c_max_calls; }


        BOOLEAN IsMptyMember() const;


        BOOLEAN IsMobileOriginated() const;


        BOOLEAN IsMobileTerminated() const;


        // --------------------------------------------------------------------
        // misc
        // --------------------------------------------------------------------

        BOOLEAN IsSetupPermitted() const;

        BOOLEAN IsAcceptPermitted() const;

        virtual BOOLEAN IsHoldPermitted()const;

        virtual BOOLEAN IsRetrievePermitted() const;

        BOOLEAN IsExplicitCallTransferPermitted() const;

        BOOLEAN IsStartDtmfToneGenerationPermitted() const;

        virtual void Invalidate() { m_call_index = c_null_call_index; }

        virtual CallIndex GetCallIndex() const { return m_call_index; }

        //Madhavi added for ALS on 1st Aug. 2003 begins
        LineSelector GetCallLine() const;
        //Madhavi added ends

        CallType GetCallType() const;

        virtual TimeSpan GetCallDuration() const;

#ifdef APOXI_CTM

        BOOLEAN GetCtm() const;
#endif

        CallEstCause GetEstablishCause() const;

        ClirMode GetClirMode() const;               

        EccCategory GetEccCategory() const;
        
        BOOLEAN IsCallControlPerformed() const;     
        
        SimCallControlResult GetCallControlResult() const;      
        
        SimAlphaIdentifier GetAlphaIdentifier() const;      

    private:
        CallIndex   m_call_index;
};

#endif // Asc_CallHdl_hpp

