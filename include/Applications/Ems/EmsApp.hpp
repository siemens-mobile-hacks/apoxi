/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_EmsApp_hpp)
#define Mmi_EmsApp_hpp

#include <Apc/SimDataTypes.hpp>

#include <Sms/AbstractSmsApp.hpp>
#include <Ems/EmsComposeWin.hpp>
#include <Ems/EmsViewerWin.hpp>
#include <Ems/EmsInsertPrompt.hpp>
#include <GuiExtensions/MmiTextFormatChooser.hpp>

class EmsApp : public AbstractSmsApp {
    typedef AbstractSmsApp Base;

    public:
        static EmsApp* GetInstance();
        virtual ~EmsApp();
        
        virtual void ForwardSms(Provider* provider, INT act_row);
        virtual void ReplySms(Provider* provider, INT act_row);

        static EmsCreator* GetEmsCreator() { return &m_creator; }
        virtual AbstractSmsComposeWin* GetSmsComposer();

    protected:
        virtual void OnOpen();
        virtual void OnStartup();
        
        virtual AbstractSmsViewerWin* GetSmsViewer();
        
        virtual SmsFactory* GetSmsFactory() { return &m_ems_factory; }

        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

        virtual void StoreImpl(const SmsContext& profile, const EditorDocumentObtainer& obtainer);
        
        virtual void SendImpl(const SmsContext& profile, const EditorDocumentObtainer& obtainer);

        virtual void OnExportConfirmation(SmsExportType export_type, Sms::Result result_code, const SmsContext& profile, INT pending_segement_count = 0);
        
        virtual void SendToManyRecipient(SmsContext *profile,INT nCnt, const EditorDocumentObtainer& obtainer);     

    private:

        enum FeatureItemIds {
            EmsFormat, 
            EmsInsert,
            EmsFeatureCnt
        };

        EmsApp();   //lint !e1704
        static EmsApp m_app;
                
//      void RelaySms(Provider* provider, INT act_row, BOOLEAN grab_destination);

        static SmsFactory           m_ems_factory;
        static EmsCreator           m_creator;

        static MmiTextFormatChooser m_font_chooser;
        static EmsInsertPrompt      m_insert_prompt;

        static EmsComposeWin        m_compose_win;
        static EmsViewerWin         m_viewer_win;
        
        const EditorDocument*       m_doc_cache;

        Feature                 m_items[EmsFeatureCnt];
        
};

#endif  // Mmi_EmsApp_hpp
