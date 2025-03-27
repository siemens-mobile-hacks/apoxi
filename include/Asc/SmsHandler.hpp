/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsHandler_hpp)
#define Asc_SmsHandler_hpp

#include <Kernel/Types.hpp>

#include <Apc/MdhTypes.hpp>
#include <Apc/Tpdu.hpp>
#include <Asc/BaseHandler.hpp>
#include <Asc/SmsDispatcher.hpp>

/*  ========================================================================
    SmsHandler
    ======================================================================== */
class SmsHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = SmsHandlerId };     

        SmsHandler();
        virtual ~SmsHandler();

        virtual HandlerId GetHandlerId() const;

#if !defined(DOWNSTRIP_TO_GSM)
        Sms::Result SendSms(Tpdu &tpdu, BOOLEAN wait_for_response = TRUE, GsmService service = CircuitSwitched);
#else
        Sms::Result SendSms(Tpdu &tpdu, BOOLEAN wait_for_response = TRUE);
#endif

        Sms::Result StoreSms(const Tpdu &tpdu, const Sms::StorageType storage_type) const;

        Sms::Result StoreSms(const Tpdu &tpdu) const;
        
        void SetSendingResult(Tpdu &tpdu, Sms::Result result, const SmsReferenceNumber &reference_number = 0xFF);
        BOOLEAN ChangePreferredStorageMedia(Sms::StorageType storagetype);

        BOOLEAN EnableResendingSmsOverCs(UINT32 timer);

        BOOLEAN SetMessageWaitIndicators(const MdhSetWaitIndicatorArray & wia);

        BOOLEAN SetSmsMoreMessageType(const SmsMoreMessageType & type);

        SmsMoreMessageType QuerySmsMoreMessageType();

    private:
        SmsDispatcher m_sms_dispatcher; // main dispatcher for retrieving asynchronous messages
};

#endif // Asc_SmsHandler_hpp

