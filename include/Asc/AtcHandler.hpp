/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AtcHandler_hpp)
#define Asc_AtcHandler_hpp

#include <Apc/SignalTypes.hpp>

#include <Asc/BaseHandler.hpp>
#include <Asc/AtcDispatcher.hpp>

/*  ========================================================================
    AtcHandler
    ======================================================================== */
class AtcHandler : public BaseHandler {
    typedef BaseHandler Base;

    public:

        enum { ID = AtcHandlerId };

        AtcHandler();
        virtual ~AtcHandler();

        virtual HandlerId GetHandlerId() const;

        void SetPbAlphaTagRequestBehaviour(PbRequestBehaviour behaviour) {
            m_atc_dispatcher.SetPbAlphaTagRequestBehaviour(behaviour);
        }
        BOOLEAN ConfirmPbAlphaTagRequest(
            const WString & alphatag, const PhoneNumber & phno, BOOLEAN apoxilookup = FALSE)
        {
            return m_atc_dispatcher.ConfirmPbAlphaTagRequest(alphatag,phno, apoxilookup);
        }

        void SetPbRecordRequestBehaviour(BOOLEAN mmicontrolled) {
            m_atc_dispatcher.SetPbRecordRequestBehaviour(mmicontrolled);
        }

        BOOLEAN CommitPbInformation(const MePhonebookDescription & description)
        {
            return m_atc_dispatcher.CommitPbInformation(description);
        }

        BOOLEAN ConfirmPbSizeRequest(
            BOOLEAN capable,         // MMI has to set the value to TRUE if it is capable of detecting the size.
            MePhoneBookType type,    // the requested phonebook type as used in PbSizeRequestMsg
            INT usedrecords,         // used records inside the phonebook
            INT totalrecords = 0)    // obsolete parameter, as this is sent with CommitPbInformation
        {
            return m_atc_dispatcher.ConfirmPbSizeRequest(capable,type,usedrecords);
        }

        BOOLEAN ConfirmPbEntryRequest(
            BOOLEAN capable,                    // MMI has to set the value to TRUE if it was capable of returning the entry correctly.
            MePhoneBookType type,               // the requested phonebook type as used in PbSizeRequestMsg
            INT recordnumber,                   // the record number requested by the AT via the message PbEntryRequestMsg
            const WString & alphaidentifier,    // it can be also be an empty string 
            const PhoneNumber & phno)           // it can also be an empty phonenumber
        {
            return m_atc_dispatcher.ConfirmPbEntryRequest(capable,type,recordnumber,alphaidentifier,phno);
        }


    private:
        AtcDispatcher m_atc_dispatcher;     // main dispatcher for retrieving asynchronous messages

};


#endif  // Asc_AtcHandler_hpp


