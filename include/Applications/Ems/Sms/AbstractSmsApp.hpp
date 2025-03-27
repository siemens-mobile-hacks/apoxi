/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_AbstractSmsApp_hpp)
#define Mmi_AbstractSmsApp_hpp

#include <Config/SmsCustomizationConfig.hpp>

#include <Common/MmiApplication.hpp> 
#include <Atl/Gui/AtlItemListWindow.hpp> 
#include <Atl/Gui/AtlItemMenuWindow.hpp>
#include <Atl/Features/ProviderProxyItem.hpp>
#include <Atl/Properties/PropertyItem.hpp>

#include <Common/MmiProviderProgressBox.hpp>
#include <Common/Items/ProviderProxyContainer.hpp>
#include <Common/MmiWaitingBox.hpp>

#include <Config/SmsConfig.hpp>

#include <Sms/SmsMsgTypes.hpp>
#include <Sms/SmsService.hpp>
#include <Sms/AbstractSmsComposeWin.hpp>
#include <Sms/AbstractSmsViewerWin.hpp>
#include <Sms/SmsAlerts.hpp>
#include <Sms/SmsSendingConfirmDialog.hpp>
#include <Sms/SmsTextMaps.hpp>

#include <Sms/SmsBasicProvider.hpp>
#include <Sms/SmsTemplateProvider.hpp>
#include <Sms/SmsSettingsProvider.hpp>

/* uib support */
#if defined (APPLICATION_UNIFIEDINBOX)
    #include <Sms/SmsFolderProvider.hpp>
#endif/* uib support */
#include <Common/AudioRequest.hpp>
#include <Common/Properties/Descriptors/BooleanPropertyDescriptor.hpp>
#include <Sms/SmsIndicationState.hpp>
#include <Atl/Properties/PropertyDescriptor.hpp>
#include <Common/Properties/Descriptors/SetPropertyDescriptor.hpp>
#include <Atl/Properties/PropertyEditorFactory.hpp>
#include <Common/MmiPhoneNumberPrompt.hpp>
class AbstractSmsUtilityProcessor;
#include <Common/WildcardMultiLineEditor.hpp>
#include <Common/MmiDialog.hpp>
#include <Asc/SmsContext.hpp>

class AbstractSmsApp : public MmiApplication {
    typedef MmiApplication Base;

    public:
        enum SmsServiceType {
            ComposeSmsType,
            SendSmsType,
            SendInternalSmsType,
            StoreSmsType
        };
        enum SmsExportType {
            ExportSendType,
            ExportStoreType
        };

        enum SmsSendingAnimationType {

            SendingAnimationType 
        };

        enum SmsStorageType{
            SmsSimPreferred,
            SmsFlashPreferred
        };

        enum SmsValidtyPeriodType{
            One_hour = 11, // 1 hour
            Twelve_Hour = 143, // 12 hours
            One_Day = 167,  // 1 day
            One_Week = 173, // 1 week
            Thirty_Days = 196,  // 30 days (~1 month)
            Three_Months = 205, // 3 months (13 weeks)
            Maximum = 255 // Maximum (63 weeks)

        };      

        enum PeriodData {
            PeriodCount = 7
        };
        explicit AbstractSmsApp(const WCHAR* app_name, UINT stacksize = 0); //lint !e1704
        virtual ~AbstractSmsApp();

        Provider* GetInboxProvider() const          { return m_inbox_provider; }
        Provider* GetInboxUnreadProvider() const { return m_sms_inbox_unread_provider; }
        Provider* GetOutboxProvider() const         { return m_outbox_provider; }

        Provider* GetArchiveProvider() const        { return m_archive_provider; }

        Provider* GetStatusReportProvider() const   { return m_statrep_provider; }

        Provider* GetArrivedProvider() const        { return m_arrived_provider; }
    

        Provider* GetTemplateProvider() const       { return &m_template_provider; }


        Provider* GetReadProvider()                 { return DataControl::GetMainProvider()->GetProvider(c_sms_read_provider_id); }

        Provider* GetUnreadProvider()               { return DataControl::GetMainProvider()->GetProvider(c_sms_unread_provider_id); }

        Provider* GetSentProvider()                 { return DataControl::GetMainProvider()->GetProvider(c_sms_sent_provider_id); }

        Provider* GetUnsentProvider()               { return DataControl::GetMainProvider()->GetProvider(c_sms_unsent_provider_id); }

        Provider* GetSmsClass0Provider()            { return DataControl::GetMainProvider()->GetProvider(c_sms_class0_provider_id); }

        Provider* GetSettingsProvider() const       { return &m_settings_provider; }

        Provider* GetProfileProvider() const        { return m_profile_provider; }

        Provider* GetSmsProvider() const            { return m_sms_provider; }

        SmsBasicProvider* GetSmsBasicProvider() const           { return &m_sms_basic_provider; }
        AbstractSmsUtilityProcessor*    GetUtilityProcessor()       { return    m_utlp;}
        
            
        virtual void ShowSms(Provider* provider, INT act_row);

        virtual void DeleteSms(Provider* provider, INT act_row);
        
        virtual void ForwardSms(Provider* provider, INT act_row);

        virtual void ReplySms(Provider* provider, INT act_row);

        virtual void ComposeSms (const PhoneNumber* destination = 0, BOOLEAN clear = TRUE);
        virtual void ComposeSms (const EditorDocumentObtainer& obtainer, const PhoneNumber* destination = 0, BOOLEAN clear = TRUE);

        virtual void StoreSms(const EditorDocumentObtainer& obtainer, const PhoneNumber* destination = 0);

        virtual void StoreSms(const Tpdu& tpdu);
        
        virtual void StoreSentSms(const SmsContext& profile);
        
        virtual void SendSms(const EditorDocumentObtainer& obtainer, const PhoneNumber* destination = 0, const PhoneNumber* service_center = 0);
        
        virtual void ShowArrivedSms(BOOLEAN show_status_report = FALSE);

        virtual BOOLEAN IsServiceAvailable(SmsServiceType type) const;
        
        WString GetNameForNumber(const PhoneNumber& phoneNr) const;

        void    SwitchReadStatus(Provider* provider, INT row, BOOLEAN switch_to_read, BOOLEAN immediate_update = FALSE);
        void    MoveSmsToArchive(Provider* provider, INT row);
        INT     GetCapacity() const;
        INT     GetExistentSmsCount() const { return m_valid_sms_cnt; }
        INT     GetFreeSmsCount() const;    
        virtual BOOLEAN Update(ProviderListener* listener = 0, BOOLEAN update_providers = TRUE);
        virtual void UpdateSettings(ProviderListener* listener = 0);
        void    SetWaitingBoxVisible(BOOLEAN flag) const;
        BOOLEAN GetProviderData(Provider* provider, INT id, INT row, DataItem& item) const;
        //BOOLEAN IsVoiceBoxNumberApplied(); 
        BOOLEAN             SetPreferredStorageType(Sms::StorageType storage_type);
        Sms::StorageType    GetPreferredStorageType();
        BOOLEAN             IsGprsAvailable();
        static DataCodingScheme::Alphabet MapAlphabet(const EditorDocumentObtainer& obtainer);
        static InputMapper::Alphabet MapAlphabet(DataCodingScheme::Alphabet alphabet);
        void RememberRepliedTpdu(CompoundTpduItem* tpdu) { m_replied_tpdu = tpdu; }
        void SetEditEnable(BOOLEAN enable); 
        //void UpdateSettingsOptions(BOOLEAN available);
        //void EditSettingsDisabled(BOOLEAN enable);
        virtual void    OnIndicateIncoming(SmsConfig::SmsIndicationType type);
        virtual void    OnExportConfirmation(SmsExportType export_type, Sms::Result result_code, const SmsContext& profile, INT pending_segment_count = 0);
        BOOLEAN IsReadyForSendingSms(const SmsContext& profile, INT segment_count = -1);
        BOOLEAN IsSmsComposeEnabled() const { return m_items[SmsComposeMessage].IsEnabled(); }
        void RegisterUtility(AbstractSmsUtilityProcessor *utlp);        
        virtual void RelaySms(Provider* provider, INT act_row, BOOLEAN reply);
        virtual void    OnOpen();
        
        BOOLEAN WildCharHandler(PhoneNumber& number);
        BOOLEAN ValidateValidityPeriod(ValidityPeriod &period);
        BOOLEAN ValidateProtocolIdentifier(ProtocolIdentifier &protocol_identifier);
        void    ValidateServiceCenterAddress();

        BOOLEAN     IsRequestReplyPath()    { return m_request_reply_path;}
        BOOLEAN     IsRequestStatusReport() { return m_request_status_report;}
        BOOLEAN     GetPeriodManual()       { return m_period_manual;}
        BOOLEAN     GetDeviceManual()       { return m_device_manual; }
        INT         GetDefaultProfile() const;
        SmsContext* GetSmsProfile()         { return &m_sms_profile;}
        void InitiateCall(const WString &text);
        void StoreInPhonebook(const WString &text);
        void ConnectToUrl(const WString &text);
        void AddBookmark(const WString &text);
        void StoreEmailInPhonebook(const WString &text);
        void SendEmail(const WString &text);

        BOOLEAN UpdateVoiceMailboxNumbers(PhoneNumber& voiceMailbox, LineSelector line, BOOLEAN read_write_number);     
    protected:
        
        virtual void OnLanguageChanged();
        
        virtual BOOLEAN UpdateItem(Item* item);

//      virtual void UpdateContextItem(ContextFeatureItem* item);
        virtual void    OnStartup();
        
        virtual void    OnClose();
        virtual void    OnLoseFocus();
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void    OnSmsService (SmsServiceType type, EditorDocumentObtainer obtainer, const PhoneNumber& number);
        virtual void    OnSimSmsReady();
        virtual void    OnSimRemoved();
        
        BOOLEAN IsSendingSmsConfirmed(const SmsContext& profile, INT segment_count = -1) const;
        
        void    SetSmsComposeEnabled(BOOLEAN flag);
        

        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

        virtual BOOLEAN OnContextFeatureTriggered (const FeatureID& feature_id, const DataItem& context_item);

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification, 
                                               const Property* property, 
                                               const DataItem& value);

    private:
        enum FeatureIds {
            SmsOpenTemplates = 0,
            SmsOpenMainSettings,
            SmsSend,
            SmsStore,
            SmsDeleteInbox,
            SmsDeleteOutbox,
            SmsDeleteReports,
            SmsDeleteArchive,
            SmsChangeSettings,
            SmsSelectSettings,
            SmsEditSettings,
            SmsChangeCommonSettings,
            SmsEditProfileSettings,
//          SmsSendAgain,
//          SmsSave,

            SmsT9Disabled,
            SmsT9English,
            SmsT9SimpChinese,
            SmsT9TradChinese,
            SmsT9Pinyin,
            SmsT9BoPoMoFo,
            SmsComposeMessage,
            SmsOpenInbox,
            SmsOpenOutbox,
            SmsOpenArchive,
            SmsOpenStatusReports,
            SmsOpenSettings,
            SmsShowArrivedMessage,
            SmsInsertTemplate,
            SmsTextInitiateCall,
            SmsTextStoreInPhoneBook,
            SmsTextSendSms,
            SmsTextConnectToURL,
            SmsTextAddBookMark,
            SmsTextStoreEmailInPhoneBook,
            SmsTextSendEmail,   
            SmsViewGreenKey,
            SmsFeatureCnt
        };
        enum ContextFeatureIds {
            SmsView,
            SmsDelete,
            SmsReply,
            SmsEdit,
            SmsForward,
            SmsCreate,
            SmsUseNumber,
            SmsFirst,
            SmsPrevious,
            SmsNext,
            SmsLast,
            SmsPerformCall,
            SmsToggleReadMode,
            SmsToPhonebook,
            SmsToArchive,
            SmsInsertTemplateText,
            SmsEmbItemPrevious,
            SmsEmbItemNext,         
            SmsContextFeatureCnt
        };
        enum PropertyIds {
            SmsStartNumberProperty = 0,
            SmsInboxProperty = SmsStartNumberProperty,
            SmsOutboxProperty,
            SmsArchiveProperty,
            SmsTemplatesProperty,
            SmsStatusReportsProperty,
            UnreadInboxProperty,        
            TotalInboxProperty,     
            SmsStartBooleanPropertyInitiallyTrue,
            ToggleRreadModeProperty = SmsStartBooleanPropertyInitiallyTrue,
            SmsStartStringProperty,
            ShowArrivedMsgProperty = SmsStartStringProperty,
            SmsStartOtherProperties,
            SmsVoiceboxNumberProperty = SmsStartOtherProperties,
            ServiceCenterTypeProperty,
            DefaultDestinationTypeProperty,
            SmsStartOtherNumberProperty,
            SmsConnectionProperty = SmsStartOtherNumberProperty,
            SmsStoreAtProperty,
            TelematicDeviceTypeProperty,
            ValidityPeriodTypeProperty,
            SmsStartBooleanPropertyInitiallyFalse,
            SmsReplyPathProperty = SmsStartBooleanPropertyInitiallyFalse,
            SmsDeliverReportProperty,
            SmsShowDeliverReportsOnIdleScreenProperty,
            SmsAutoStoreSentProperty,
            SmsConfirmProperty,
            SmsMandatorySendingPreviewProperty,
            SmsStartOtherStringProperty,
            ProfileNameProperty = SmsStartOtherStringProperty,
            SmsPropertyCnt
        };
        /*enum ProviderIds {
            SmsBaseIbxProvId = 1036,
            SmsBaseObxProvId,
            SmsBaseAchveProvId,
            SmsBaseStatRepProvId,
            SmsBaseUnrdProvId,
            SmsTmplteProvId = 7046,
            SmsCountProvId = 1020,
            SmsProvId = 1013,
            SstProvId = 1010,
            StatProvId = 1007,
            SmsParamProvId = 1018,
        };*/
        

        void UpdateSmsNavigationOption(INT current_row, INT last_row); 

        void UpdateSmsEmbItemsOption();
        
        PropertyIds GetPropertyId(const FeatureID &id) const;
        DataItem GetContextDataItem(ContextFeature* feature);
        void InitProperty();

        void Change(PropertyIds type, BOOLEAN flag);

        static const WCHAR* GetProtocolIdentifierName(const ProtocolIdentifier& pi);
        AbstractSmsApp();

        // Singleton. No need for a copy constructor. Made it private
        
        INT     GetActualCount(Provider* provider, ProviderListener* listener = 0, BOOLEAN update_providers = TRUE) const;
        void    RegisterSettingsProvider();
        INT     SingleUpdate(Provider* provider, ProviderListener* lstn, 
                          WString* buffer = 0, const WCHAR* text = 0, 
                          PropertyIds fid = SmsPropertyCnt, Provider* low_provider = 0, BOOLEAN update_providers = TRUE);
        BOOLEAN UpdateStorageType();
        void UpdateIndication();
        void RemoveReplyPathFlag(CompoundTpduItem* tpdu);
        /* uib support */
        #if defined (APPLICATION_UNIFIEDINBOX)
        AbstractDelegationProvider* GetExportedProvider(INT provider_id);
        #endif
        /* uib support */
        void UpdateIncoming(AudioRequest::ToneType, SmsAlert::SmsAlertType, BOOLEAN force_update);

        struct {
            UINT actual_sms_stored          : 2;
        } m_flags;
        void NavigateViewSms(Provider* provider, const FeatureID& feature_id);
        void NavigateSmsEmbItems(Provider* provider, const FeatureID& feature_id);
        void DisplaySettingsOptions();
        void SwitchDefaultProfile();
        void RestoreDefaultProfile();
        void UpdateProfilePrompt(Provider* p, INT col_id, PropertyIds prop_id);
        void UpdateCommonSettingsOption(Provider* p, INT col_id, PropertyIds prop_id);
        UINT8   GetValidtyPeriod(UINT8 index);
        static INT  m_valid_sms_cnt;
        static INT  m_waiting_cnt;
        static SmsContext           m_sms_profile;

        static SmsBasicProvider     m_sms_basic_provider;
        static Provider*            m_sms_provider;
        static Provider*            m_archive_provider;     
        static Provider*            m_inbox_provider;
        static Provider*            m_outbox_provider;
        static SmsTemplateProvider  m_template_provider;
        static Provider*            m_statrep_provider;
        static Provider*            m_arrived_provider;
        static SmsSettingsProvider  m_settings_provider;
        static Provider*            m_sms_inbox_unread_provider;

        static Provider*            m_profile_provider;
        /* uib support */
        #if defined (APPLICATION_UNIFIEDINBOX)
        static SmsFolderProvider    m_uib_provider;
        #endif
        /* uib support */
        SmsConfig::SmsIndicationType            m_new_message_type;
        BasicSmsService             m_service;
        static MmiProviderProgressBox   m_progress_alert;
        WString                     m_menu_text;
        WString                     m_inbox_text;
        WString                     m_outbox_text;
        WString                     m_archive_text;
        WString                     m_template_text;
        WString                     m_statrep_text;
        static MmiWaitingBox        m_waiting_alert;
        static SmsInfoBox           m_info_box;
        static SmsAlert             m_alert;
        static SmsSendingConfirmDialog m_sending_confirm_dlg;
        AudioRequest                m_sms_audio;
        CompoundTpduItem*           m_replied_tpdu;

        UINT8                       m_update_state;
        AtlItemListWindow           m_sms_box_win;
        ProviderProxyContainer      m_sms_box_cont;

        Feature                     m_items[SmsFeatureCnt];
        ContextFeature              m_context_items[SmsContextFeatureCnt];
        Property                    m_property[SmsPropertyCnt];
        BooleanPropertyDescriptor   m_desc;
        SmsIndicationState          m_indication_state;
        ProviderProxyItem           m_ppi;
        INT                         m_ppi_selected_index;
        AtlItemMenuWindow           m_menu_window;
        FeatureItemContainer        m_feat_item_cont;
        AtlItemListWindow           m_list_win;
        ItemContainer               m_item_cont;
        Item                        m_item[c_sms_max_profile];
        BOOLEAN                         m_manual;
        BOOLEAN                         m_save_on_commit;
        ProtocolIdentifier              m_pis[7];
        const UINT8                     m_pi_cnt;
        static BOOLEAN                  m_period_manual;
        static BOOLEAN                  m_device_manual;
        DataItem                        m_period_item;
        DataItem                        m_protocol_item;
        DataItem                        m_svc_ctr_item;
        static BOOLEAN                  m_request_reply_path;
        static BOOLEAN                  m_request_status_report;
        BOOLEAN                         m_preview_mandatory;
        BOOLEAN                         m_auto_store;
        PropertyItem                    m_phonenumber_prompt;
        PropertyItem                    m_period_prompt;
        PropertyItem                    m_device_prompt;
        static AbstractSmsUtilityProcessor      *m_utlp;

        WildcardMultiLineEditor         m_wildcards_editor;
        MmiDialog                       m_pn_win;

        BOOLEAN                     m_als_supported;
};

#endif  // Mmi_AbstractSmsApp_hpp

