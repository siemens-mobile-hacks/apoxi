/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AddOns_MmCallHdl_hpp)
#define Apoxi_AddOns_MmCallHdl_hpp

#include <Asc/Types.hpp>
#include <Auxiliary/PhoneNumber.hpp>
class Socket;

class MmCallHdl {

    public:

        //---------------------------------------------------------------------
        // Construction, destruction initialization
        //---------------------------------------------------------------------

        MmCallHdl(CallIndex call_index = c_null_call_index); 

        virtual ~MmCallHdl();

        // --------------------------------------------------------------------
        // call related operations on CallHdl
        // --------------------------------------------------------------------


        CallApiRc Setup(const PhoneNumber & phone_no, 
                        ClirMode clir_mode = DontCare);


        CallApiRc Accept();  


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
        
        static void ReportCurrentCallMeter(BOOLEAN activate);


        static void ReportCurrentCharge(BOOLEAN activate);

        CallApiRc GetCurrentCallMeter();
                    

        CallApiRc GetCurrentChargeData();


        // --------------------------------------------------------------------
        // access to miscellaneous call data
        // --------------------------------------------------------------------

        const PhoneNumber & GetPhoneNumber() const;

        const PhoneNumber & GetConnectedToPhoneNumber() const;


        virtual DateTime GetStartTime() const;      
        
        
        // --------------------------------------------------------------------
        // general information of call referred by a CallHdl
        // --------------------------------------------------------------------

        virtual BOOLEAN IsActive() const;


        BOOLEAN IsInSetup() const;


        BOOLEAN operator==(const MmCallHdl & call) const;


        virtual BOOLEAN IsValid() const;

        BOOLEAN IsMobileOriginated() const;


        BOOLEAN IsMobileTerminated() const;


        // --------------------------------------------------------------------
        // misc
        // --------------------------------------------------------------------

        static CallApiRc RejectAllMtc(BOOLEAN activate);

        BOOLEAN IsSetupPermitted() const;

        BOOLEAN IsAcceptPermitted() const;

        virtual void Invalidate() { m_call_index = c_null_call_index; }

        virtual CallIndex GetCallIndex() const { return m_call_index; }

        CallType GetCallType() const;

        static BOOLEAN IsPsdCallActive();
        
        static void DisconnectActivePsdCalls();

        virtual TimeSpan GetCallDuration() const;

        Socket* GetSocket() const;

        ClirMode GetClirMode() const;

    private:
        CallIndex   m_call_index;
};

#endif // Apoxi_AddOns_MmCallHdl_hpp

