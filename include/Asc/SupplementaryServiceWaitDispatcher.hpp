/*  ------------------------------------------------------------------------
  Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
  ------------------------------------------------------------------------
  This document contains proprietary information belonging to COMNEON.
  Passing on and copying of this document, use and communication of its
  contents is not permitted without prior written authorisation.
  ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_SupplementaryServiceWaitDispatcher_hpp)
#define Asc_SupplementaryServiceWaitDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/* ========================================================================
   SupplementaryServiceWaitDispatcher
   ======================================================================== */
class SupplementaryServiceWaitDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
 public:
    SupplementaryServiceWaitDispatcher();
    virtual ~SupplementaryServiceWaitDispatcher();
        
    BOOLEAN WasRejected() { return m_rejected; }
    BOOLEAN WasChangedToMoc() { return m_changed_to_moc; }
    BOOLEAN WasChangedToSs() { return m_changed_to_ss; }
    BOOLEAN WasChangedToUssd() { return m_changed_to_ussd; }

    const PhoneNumber& GetCalledPartyNumber() { return m_called_phone_number; }
    const WString& GetUserInput() { return m_user_input; }
    DataCodingScheme::Language GetUserLanguage() { return m_user_language; }


    Tipd GetTipd() { return m_tipd; }
    CallErrorCause GetCause() { return m_cause; }

    void ChangeToSsIndication(const WString& user_input, DataCodingScheme::Language user_language);
    void ChangeToUssdIndication(const WString& user_input, DataCodingScheme::Language user_language);
    void ChangeToMocIndication(const PhoneNumber& called_phone_number);

 protected:
    BOOLEAN OnSsBeginAcc(const StackMsgArgument &arg);
    BOOLEAN OnSsFacilityRej(const StackMsgArgument &arg);
    BOOLEAN OnCallControlSetupInd(const StackMsgArgument &arg);
    BOOLEAN OnCallControlSsInd(const StackMsgArgument &arg);
    BOOLEAN OnCallControlUssdInd(const StackMsgArgument &arg);

 private:
    static const StackMsgArgMap<SupplementaryServiceWaitDispatcher> m_arg_map[];
    StackMsgArgMapContainer<SupplementaryServiceWaitDispatcher> m_arg_map_container;
        
    Tipd m_tipd;
    BOOLEAN m_rejected;

    CallErrorCause m_cause;

    BOOLEAN m_changed_to_moc;
    BOOLEAN m_changed_to_ss;
    BOOLEAN m_changed_to_ussd;

    WString m_user_input;
    DataCodingScheme::Language m_user_language;
    PhoneNumber m_called_phone_number;
};

#endif  // Asc_SupplementaryServiceWaitDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


