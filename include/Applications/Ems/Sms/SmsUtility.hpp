/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SmsUtility_hpp)
#define Mmi_SmsUtility_hpp

#include <Sms/AbstractSmsApp.hpp>
#include <Sms/SmsComposeWin.hpp>
#include <Sms/SmsViewerWin.hpp>
#include <Sms/AbstractSmsUtiltyProcessor.hpp>
class SmsUtility : public AbstractSmsUtilityProcessor {
    typedef AbstractSmsUtilityProcessor Base;

    public:
        SmsUtility();
        static SmsUtility* GetInstance();
        ~SmsUtility();
        void SendImpl(const SmsContext& profile, const EditorDocumentObtainer& obtainer);
        AbstractSmsComposeWin* GetSmsComposer() { return &m_compose_win; }  
        void Init();
    private:
        //void OnOpen();
        
        AbstractSmsViewerWin* GetSmsViewer() {return &m_viewer_win;} 
        SmsFactory* GetSmsFactory() { return &m_sms_factory; }
        
        void StoreImpl(const SmsContext& profile, const EditorDocumentObtainer& obtainer);
        
        void OnExportConfirmation(AbstractSmsApp::SmsExportType export_type, Sms::Result result_code, const SmsContext& profile, INT pending_segment_count = 0);
        void RelaySms(Provider* provider, INT act_row, BOOLEAN reply);

        //void SendToManyRecipient(SmsContext *profile,INT nCnt, const EditorDocumentObtainer& obtainer);
        
        
        void CreateBodyText(const EditorDocumentObtainer& obtainer);

        static SmsUtility m_app;        
        static SmsFactory           m_sms_factory;
        static SmsComposeWin        m_compose_win;
        static SmsViewerWin         m_viewer_win;
        WString                     m_sms_body;

        AbstractSmsApp              *p_app;
        
};

#endif  // Mmi_SmsUtility_hpp
