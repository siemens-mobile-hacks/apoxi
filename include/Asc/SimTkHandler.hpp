/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SimTkHandler_hpp)
#define Asc_SimTkHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/SimTkDispatcher.hpp>

class SimIconDescription;
class SimImage;
class SimItemId;
class WString;

/*  ========================================================================
    SimTkHandler
    ======================================================================== */
class SimTkHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = SimTkHandlerId };

        SimTkHandler();
        virtual ~SimTkHandler();

        virtual HandlerId GetHandlerId() const;

        BOOLEAN SmsSetupResponse(const ProactiveCause &cause, const SimReferenceNumber &ref_no) const;
        BOOLEAN SsSetupResponse(const ProactiveCause &cause, const SimReferenceNumber &ref_no) const;

        CallApiRc AcceptCallSetup(const ProactiveCause &cause, BOOLEAN ctm = FALSE) const;


        BOOLEAN RejectCallSetup(const ProactiveCause &cause = UserDidNotAcceptCallSetupRequest) const;

        BOOLEAN TextDisplayed(const SimTkTransactionId & tid, const ProactiveCause &cause) const;
        BOOLEAN TextDisplayed(const ProactiveCause &cause) const;

        BOOLEAN Input(const SimTkTransactionId & tid, const ProactiveCause &cause, 
                      const WString &text, BOOLEAN ucs2_coding = FALSE, BOOLEAN packed = TRUE) const;
        BOOLEAN Input(const ProactiveCause &cause, 
                      const WString &text, BOOLEAN ucs2_coding = FALSE, BOOLEAN packed = TRUE) const;

        BOOLEAN Inkey(const SimTkTransactionId & tid, const ProactiveCause &cause, 
                      const WString &text, BOOLEAN ucs2_coding = FALSE) const;
        BOOLEAN Inkey(const ProactiveCause &cause, const WString &text, BOOLEAN ucs2_coding = FALSE) const;
        BOOLEAN Inkey(const SimTkTransactionId & tid, const ProactiveCause &cause, SimKey key = SimKeyInvalid) const;
        BOOLEAN Inkey(const ProactiveCause &cause, SimKey key = SimKeyInvalid) const;

        BOOLEAN ItemSelected(const SimTkTransactionId & tid, const ProactiveCause &cause, const SimItemId &item_id) const;  
        BOOLEAN ItemSelected(const ProactiveCause &cause, const SimItemId &item_id) const;

        BOOLEAN SetupMenuDone(const SimTkTransactionId & tid, const ProactiveCause &cause) const;
        BOOLEAN SetupMenuDone(const ProactiveCause &cause) const;

        BOOLEAN MenuItemSelected(const SimItemId &item_id, BOOLEAN help_requested = FALSE) const;

        BOOLEAN TonePlayed(const SimTkTransactionId & tid, const ProactiveCause &cause) const;
        BOOLEAN TonePlayed(const ProactiveCause &cause) const;

        BOOLEAN SetupIdleModeTextDone(const SimTkTransactionId & tid, const ProactiveCause &cause) const;
        BOOLEAN SetupIdleModeTextDone(const ProactiveCause &cause) const;

        BOOLEAN SendUserActivityEvent();

        BOOLEAN SendIdleScreenAvailEvent();

        BOOLEAN SendLanguageSelectEvent();

        BOOLEAN SetActiveExtLanguage(const WString & language);

        BOOLEAN SetSimResetPossible(BOOLEAN isresetable);

        BOOLEAN SetSimRefreshPossible(BOOLEAN isrefreshable);

        BOOLEAN SendSimTkRefreshRsp();

        BOOLEAN GetSimIconDescription(INT id, SimIconDescription & data);

        BOOLEAN GetSimImage(const SimImageDescriptor & imgdesc, SimImage & data);

        BOOLEAN RegisterBrowser(SiClientFlags siclientflags);

        BOOLEAN LaunchBrowser(const SimTkTransactionId & tid, SdlByte generalresult);
        BOOLEAN LaunchBrowser(SdlByte generalresult);

        BOOLEAN BrowserLaunched(const SimTkTransactionId & tid, ProactiveCause proactivecause);
        BOOLEAN BrowserLaunched(ProactiveCause proactivecause);

        BOOLEAN BrowserTerminated(UINT8 termcause );

        BOOLEAN RunAtCommandResponse(const SimTkTransactionId & tid, ProactiveCause proactivecause);

        BOOLEAN ConfirmDtmfSending(const ProactiveCause &icon_display_cause);

        BOOLEAN StopDtmfSending();

        void SimTkProfileFactoryReset() const;

        void GetSimTkProfileReq() const;

        void UpdateSimTkProfileReq(const SimTkProfile &profile_data) const;

        static void EnableProactiveDtmfTones(BOOLEAN enable = TRUE);

    //from protocol stack: is in Dispatcher

    private:
        SimTkDispatcher m_stk_dispatcher;       // main dispatcher for retrieving asynchronous messages

};

#endif // Asc_SimTkHandler_hpp


