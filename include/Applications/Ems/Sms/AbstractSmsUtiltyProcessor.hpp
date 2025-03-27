/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_AbstractSmsUtilityProcessor_hpp)
#define Mmi_AbstractSmsUtilityProcessor_hpp
#include <Sms/SmsPreComp.hpp>
//#include <Sms/AbstractSmsApp.hpp>
#include <Sms/AbstractSmsComposeWin.hpp>
#include <Sms/AbstractSmsViewerWin.hpp>

class AbstractSmsApp;
class AbstractSmsUtilityProcessor  {

    public:
        
        virtual void SendImpl(const SmsContext& profile, const EditorDocumentObtainer& obtainer) = 0;
        virtual AbstractSmsComposeWin* GetSmsComposer() = 0;    
        virtual AbstractSmsViewerWin* GetSmsViewer() = 0;
        virtual SmsFactory* GetSmsFactory() = 0;
        virtual void StoreImpl(const SmsContext& profile, const EditorDocumentObtainer& obtainer) = 0;
        virtual void OnExportConfirmation(AbstractSmsApp::SmsExportType export_type, Sms::Result result_code, const SmsContext& profile, INT pending_segment_count = 0) = 0;
        virtual void RelaySms(Provider* provider, INT act_row, BOOLEAN reply) = 0;  
        
};

#endif  // Mmi_SmsApp_hpp
