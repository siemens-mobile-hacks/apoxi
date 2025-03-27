/*  ------------------------------------------------------------------------
  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
  All rights reserved.
  ------------------------------------------------------------------------
  This document contains proprietary information belonging to COMNEON.
  Passing on and copying of this document, use and communication of its
  contents is not permitted without prior written authorisation.
  ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_SupplementaryServiceDispatcher_hpp)
#define Asc_SupplementaryServiceDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>

#include <Asc/InputAnalyzer.hpp>

#include <Asc/StackMsgDispatcher.hpp>
#include <Asc/SsBaseHandler.hpp>
#include <Asc/SupplementaryServiceAction.hpp>

class SsMainHandler;

class SupplementaryServiceDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;

 public:
    SupplementaryServiceDispatcher();

    virtual ~SupplementaryServiceDispatcher();

    void SetSsMainHandler(SsMainHandler * ss_main_handler) {
        m_ss_main_handler = ss_main_handler;
    }

 protected:
    
    BOOLEAN OnSsForwcheckInd(const StackMsgArgument &arg);
        
    
    BOOLEAN OnSsFacilityRej(const StackMsgArgument &arg);
        
    
    BOOLEAN OnSsBeginAcc(const StackMsgArgument &arg);

    BOOLEAN OnSsResultInd(const StackMsgArgument &arg);
        
    BOOLEAN OnSsRej(const StackMsgArgument &arg);
        
    BOOLEAN OnSsErrInd(const StackMsgArgument &arg);

    BOOLEAN OnSsCauseInd(const StackMsgArgument &arg);
          
      
    BOOLEAN OnSsNotifyInd(const StackMsgArgument &arg);
        
    BOOLEAN OnSsEndInd(const StackMsgArgument &arg);

    BOOLEAN OnSsClientRej(const StackMsgArgument &arg);

    BOOLEAN OnCallControlInd(const StackMsgArgument &arg);

    BOOLEAN OnUus1QueryInd(const StackMsgArgument &arg);
    BOOLEAN OnUus1QueryRej(const StackMsgArgument &arg);
    BOOLEAN OnUus1Ind(const StackMsgArgument &arg);
#if defined(APOXI_AT_MMI_INTERWORKING_SS)
    BOOLEAN OnFacilityInd(const StackMsgArgument &arg);
#endif
#if defined(APOXI_AT_MMI_INTERWORKING_USSD)
    BOOLEAN OnUssdAnswerInd(const StackMsgArgument &arg);
#endif   

 private:
    void SendMessage(Tipd tipd, const Message &msg);

    void SendErrorMessage(Tipd tipd, SsBaseHandler::ReturnCode error_code, const WCHAR* error_text);

    void CheckReleaseComplete(BOOLEAN release_complete) const;

    BOOLEAN CheckNotificationFlags(const SsNotification &flags);

    void EndTransaction(SsBaseHandler &ss_handler, Tipd tipd);

    SsMainHandler * m_ss_main_handler;

    static const StackMsgArgMap<SupplementaryServiceDispatcher> m_arg_map[];

    StackMsgArgMapContainer<SupplementaryServiceDispatcher> m_arg_map_container;
        
};

#endif // Asc_SupplementaryServiceDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS

