/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Adc_DataHandler_hpp)
#define Adc_DataHandler_hpp

#include <Kernel/Types.hpp>
#include <Kernel/SubSystem.hpp>
#include <Kernel/SubSystemManager.hpp>
#include <Auxiliary/BitVector.hpp>

#include <Apc/LockTypes.hpp>

#include <Adc/Types.hpp>

#include <Adc/SimAccessor.hpp>
#include <Adc/SimAuxHandler.hpp>
#include <Adc/SimPbBaseHandler.hpp>
#include <Adc/SimSmsParamHandler.hpp>
#include <Adc/SimChvHandler.hpp>
#include <Adc/SimPduHandler.hpp>

#include <Adc/PbBaseProvider.hpp>
#include <Adc/AuxProvider.hpp>
#include <Adc/PrefPlmnProvider.hpp>
#include <Adc/PrefLangProvider.hpp>
#include <Adc/PrefExtLangProvider.hpp>
#include <Adc/SstProvider.hpp>
#include <Adc/EccProvider.hpp>

#include <Adc/ChvProvider.hpp>
#include <Adc/SmsProvider.hpp>

#if defined(APOXI_SMS_NEW_PROVIDERS)
    #include <Adc/SmsBaseInboxProvider.hpp>
    #include <Adc/SmsBaseOutboxProvider.hpp>
    #include <Adc/SmsBaseArchiveProvider.hpp>
    #include <Adc/SmsBaseStatusReportProvider.hpp>
    #include <Adc/SmsBaseUnreadProvider.hpp>
#elif !defined(APOXI_DISABLE_FILTERED_SMS_PROVIDERS)
#include <Adc/SmsUnreadProvider.hpp>
    #include <Adc/SmsReadProvider.hpp>
#include <Adc/SmsUnsentProvider.hpp>
    #include <Adc/SmsSentProvider.hpp>
#endif // (APOXI_SMS_NEW_PROVIDERS)

#include <Adc/SmsClass0Provider.hpp>
#include <Adc/SmsParamProvider.hpp>
#include <Adc/CountryProvider.hpp>
#include <Adc/PlmnProvider.hpp>
#include <Adc/StatusProvider.hpp>
#include <Adc/LockProvider.hpp>
#include <Adc/CbmiProvider.hpp>
#include <Adc/CbmiRangeProvider.hpp>
#include <Adc/CphsAuxProvider.hpp>
#include <Adc/CphsServPflProvider.hpp>
#include <Adc/SimCphsHandler.hpp>
#include <Adc/SimTkMainMenuProvider.hpp>
#include <Adc/CmiProvider.hpp>
#include <Adc/MbiProvider.hpp>

#include <Adc/SimAccessor.hpp>
#include <Auxiliary/TimeZone.hpp>
#include <Auxiliary/MainProvider.hpp>
#include <Apc/SimMiscStackMsgArgs.hpp>

#include <Apc/UsimPbTypes.hpp>
#if defined(APOXI_ENABLE_USIM_PHONEBOOK)
    #include <Apc/PhoneBookStackMsgArgs.hpp>
    #include <Adc/UsimPbAccessor.hpp>
    #include <Adc/UsimPbHandler.hpp>
    #include <Adc/UsimPbXasProvider.hpp>
    #include <Adc/UsimPbPropertyProvider.hpp>
    #include <Adc/UsimPbProvider.hpp>
#endif

class BlobObject;

/*  ========================================================================
    DataHandler
    ======================================================================== */

class DataHandler : public MainProvider
{
    friend class SimAccessor;
    friend class SimPduHandler;

    public:
        typedef MainProvider Base;

        DataHandler();
        virtual ~DataHandler();

        BOOLEAN Startup();
        BOOLEAN Shutdown();

        SimAccessor *   GetSimAccessor() { return (&m_simaccessor); }

        SimChvHandler * GetSimChvHandler() { return (&m_simchvhandler); }

        SimPduHandler * GetSimPduHandler() { return (&m_simpduhandler); }

        SimCphsHandler * GetSimCphsHandler() { return (&m_simcphshandler); }

        MainProvider * GetMainProvider() { return this; }

        virtual Provider * GetProvider(INT columnid);

        DataAvailability GetDataAvailability(INT columnid);

    /* /////////////////////////////////////////////////////////////////
    // these calls can directly be called

        BOOLEAN ActivateFdn();
        BOOLEAN DeactivateFdn();
        BOOLEAN ActivateBdn();
        BOOLEAN DeactivateBdn();

        BOOLEAN IsSimPresent();
        BOOLEAN IsSimAccessAllowed();
        BOOLEAN IsUsimInserted();
        BOOLEAN WasSimChanged();
    
        BOOLEAN IsFdnActivated() const { return m_simaccessor.IsFdnActivated(); }
        BOOLEAN IsBdnActivated() const { return m_simaccessor.IsBdnActivated(); }
        BOOLEAN IsAdnReadWritableIfFdnActive() const { return m_simaccessor.IsAdnReadWritableIfFdnActive(); }
        BOOLEAN IsBdnReadWritableIfBdnNotActive() const { return m_simaccessor.IsBdnReadWritableIfBdnNotActive(); }

        BOOLEAN IsGprsFdnActivationCodePresent();

        BOOLEAN GetSimIconDescription(INT recno, SimIconDescription & data);
        BOOLEAN GetSimImage(const SimImageDescriptor & imgdesc, SimImage & data);

        BOOLEAN UpdateLockInformation();
        BOOLEAN ModifyLock(const SecLockAction lockaction, const SecLockType locktype,
                           const WString & oldpwd, const WString & newpwd);

        void SetInitialPrefferedStorageMedia(Sms::StorageType storagetype);
        BOOLEAN ChangePreferredStorageMedia(Sms::StorageType storagetype);
        Sms::StorageType GetPreferredStorageMedia() const;

        WString GetActiveExtLanguage() const;
        void SetActiveExtLanguage(const WString & language);
        BOOLEAN IsSimResetPossible() const;
        void SetSimResetPossible(BOOLEAN resetable);
        BOOLEAN IsSimRefreshPossible() const;
        void SetSimRefreshPossible(BOOLEAN refreshable);


        UINT8 GetConcSmsPduMaxNo() { return SimPduHandler::GetConcSmsPduMaxNo(); }
        void SetConcSmsPduMaxNo(UINT8 no) { SimPduHandler::SetConcSmsPduMaxNo(no); }
    
        BOOLEAN IsPartlyConcSmsStateChangeable() { return SimPduHandler::IsPartlyConcSmsStateChangeable(); }
        void SetPartlyConcSmsStateChangeable(BOOLEAN changeable) { SimPduHandler::SetPartlyConcSmsStateChangeable(changeable); }

        void EnablePidCheckForConcSms(BOOLEAN pidcheck = TRUE) { SimPduHandler::EnablePidCheckForConcSms(pidcheck); }

        void SetMaxNoOfPduCache(UINT16 pdu_no_cache) { SimPduHandler::SetMaxNoOfPduCache(pdu_no_cache); }

        void SetSmsHeaderCacheParams(INT noofentries = 30, INT noofchars = 20) { SimPduHandler::SetSmsHeaderCacheParams(noofentries,noofchars); }

        SimUpdateStatus GetLastSimUpdateStatus() { return m_simaccessor.GetLastSimUpdateStatus(); }

        void EnableBuiltinEccCodes(BOOLEAN enable = TRUE) { 
            DBG_OUT((L"Obsolete Interface DataHandler::EnableBuiltinEccCodes used, Builtin ECCs are always enabled\n"));
        }

        BOOLEAN MdhRequestCsmsRefNo(UINT16 & ref_no);

        BOOLEAN GetEmlppSubscription(EmlppPriorityLevel idx, BOOLEAN & subscribed);

        BOOLEAN GetEmlppSetupCallCondition(EmlppPriorityLevel idx, BOOLEAN & condition);
        
        PowerMode GetPowerMode();
    
        BOOLEAN LookupAlphaId(const PhoneNumber & phno, WString & alphaid, BOOLEAN uselookupalphaext = TRUE);

        BcdPlmn GetHomeBcdPlmn() const;
        Plmn GetHomePlmn() const;

        Plmn GetRegisteredPlmn() const;
        BcdPlmn GetRegisteredBcdPlmn() const;

        UINT16 GetRegisteredLac() const;

        BOOLEAN GetEonsPlmnName(const BcdPlmn & checkplmn, UINT16 lac, WString & longname, WString & shortname);
        BOOLEAN GetEonsPlmnName(const Plmn & checkplmn, UINT16 lac, WString & longname, WString & shortname);

        BOOLEAN CheckSpnData(const BcdPlmn & regplmn,   // registered Plmn
                            BOOLEAN & showregplmn,      // show the registered plmn name
                            BOOLEAN & showspnname,      // show the spn name
                            WString & spnname,          // returned spn name
                            BOOLEAN use_spn_display_condition = FALSE);
        BOOLEAN CheckSpnData(const Plmn & regplmn,  // registered Plmn
                            BOOLEAN & showregplmn,  // show the registered plmn name
                            BOOLEAN & showspnname,  // show the spn name
                            WString & spnname,      // returned spn name
                            BOOLEAN use_spn_display_condition = FALSE);

        BOOLEAN LookupPlmnName(const BcdPlmn & plmn, WString & longname, WString & shortname, 
                                NetType & nettype, WString & countryname);
        BOOLEAN LookupPlmnName(const Plmn & plmn, WString & longname, WString & shortname, 
                                NetType & nettype, WString & countryname);

        BOOLEAN InitMexe();
        UINT GetSimMexeCertificateCount() const;
        SimMexeCertificate * GetSimMexeCertificate(UINT idx);

        BOOLEAN IsEccCode(const WString & checkstr);

        EccCategory GetEccCategory(const WString & checkstr);

        const CfuServiceArray & GetCfuServiceArray() const;

        BOOLEAN IsCingularNetworkSelectionMenuControlSupportEnabled(BOOLEAN & enabled);

        BOOLEAN IsCingularSimInserted();

        BOOLEAN IsCspPlmnModeBitSet(BOOLEAN & isset);

        EccCustomization * GetEccCustomization();
    
        BOOLEAN IsSimServiceEnabled(SimServiceId id, BOOLEAN & enabled);
        BOOLEAN GetUsimPbLocReport(UsimPbLocReport & report);

        BOOLEAN SelectUsimPb(UsimPbLocation location);

        UsimPbLocation GetSelectedUsimPb() const;

        BOOLEAN DeselectUsimPb();


    /* //////////////////////////////////////////////////////////////////
    //
    // these calls are called internally 
    //

        void Reset();
        void CancelAllSimRequests() { m_simaccessor.CancelAllRequests(); }
        
        void SetSecLockStates(const SecLockStates & lockstates);
        void SetSimLockStates(const SimLockStates & lockstates);

        BOOLEAN RefreshData(const SimRefreshIndArg & arg);
        BOOLEAN RefreshDataSimTk(const SimEfRefresh & refreshstruct);
        BOOLEAN RefreshSimMruProperty(const SimMruPropertyRefreshIndArg & arg);

        void SetSimInfo(const SimInfo & info);
        void SetSimAccess(const SimIndicator indicator);
        void SetSimInitInfo(const SimInitResult & info, const Imsi & imsi, UINT8 adnbyte, UINT8 bdnbyte);
        void SetSimErrorCode(const SimErrorCode errorcode);
        void SetMdhWaitingIndicatorArray(const MdhWaitIndicatorArray & wia);
        void SetCfuServiceArray(const CfuServiceArray & servicearray);
        void SetEccNetworkArray(const EccNetworkArray & eccarray);

        void ReloadNewMsgTpdu(Tpdu &tpdu, INT tpduno);
        void ReloadTpdu(INT recno);
        BOOLEAN StoreTpdu(const Tpdu &tpdu);
        BOOLEAN StoreTpdu(const Tpdu &tpdu, const Sms::StorageType storage_type);
        BOOLEAN ActivateSmsUsage();
        void SetMaxConcRefNo(UINT16 refno);

        void SetSimTkMainMenu(const SetupMenuReqArg & arg);
        void SetBatteryLoadLevel(const BatteryLoadLevel level);

        void SetRegisterMode(const RegisterMode mode);
        void SetRegisterStatus(const RegisterStatus status);
        void SetRegisteredPlmn(const Plmn & plmn);
        void SetRegisterRejectCause(const RegisterRejectCause rejectcause);

        void SetSignalStrengthLevel(const SignalStrengthLevel signalstrength);
        void SetSignalQualityLevel(const SignalQualityLevel signalquality);


        void SetSignalStrengthMax(const SignalStrengthMax signalstrength);
        void SetSignalQualityMax(const SignalQualityMax signalquality);


        void SetGprsAttached(BOOLEAN gprs_attached);

        void SetNetworkNameLong(const WString &network_name_long);
        void GetNetworkNameLong(WString &network_name_long);
        void SetNetworkNameShort(const WString &network_name_short);        
        void GetNetworkNameShort(WString &network_name_short);

        void SetTimeZone(const TimeZone &timezone); 
        void GetTimeZone(TimeZone &timezone);

        void GetLsaIdentifier(LsaIdentifier &lsaidentifier);
        void SetLsaIdentifier(const LsaIdentifier &lsaidentifier);
        void GetIsLsaIdentifierPresent(BOOLEAN islsaidentifierpresent);
        void SetIsLsaIdentifierPresent(const BOOLEAN islsaidentifierpresent);

        void SetLastCcm(UINT32 last_ccm);
    // SetLastCcm2 is used for Line2 when using ALS
        void SetLastCcm2(UINT32 last_ccm);

        void SetLai(const Lai &lai); 
        void SetCellId(const CellId & cellid); 
    
        void SetGprsClass(const GprsClass gprs_class){m_statusprovider.SetGprsClass(gprs_class);}
        void SetGprsClassChangeOrigin(const ProcessSource gprs_class_change_origin){m_statusprovider.SetGprsClassChangeOrigin(gprs_class_change_origin);}
        void SetRadioAccessTechnology(const RadioAccessTechnology &rat){m_statusprovider.SetRadioAccessTechnology(rat);}
        void SetGsmBand(const GsmBand & band){m_statusprovider.SetGsmBand(band);}
        void SetPowerMode(PowerMode power_mode) {m_statusprovider.SetPowerMode(power_mode);}
        void SetRatChangeMode(const RatChangeMode &rat_change_mode){m_statusprovider.SetRatChangeMode(rat_change_mode);}
        void SetScanStatus(BOOLEAN scan_status);
        BOOLEAN GetScanStatus();
        RadioAccessTechnology GetRadioAccessTechnology(){return m_statusprovider.GetRadioAccessTechnology();}
        GsmBand GetGsmBand(){return m_statusprovider.GetGsmBand();}
        BatteryLoadLevel GetBatteryLoadLevel(){return m_statusprovider.GetBatteryLoadLevel();}
        SignalStrengthLevel GetSignalStrengthLevel(){return m_statusprovider.GetSignalStrengthLevel();}
        SignalQualityLevel GetSignalQualityLevel(){return m_statusprovider.GetSignalQualityLevel();}
    
    private:
        SimAccessor             m_simaccessor;       // responsible for retrieving data from sim

        SimAuxHandler           m_simauxhandler;
        SimSmsParamHandler      m_smsparamhandler;
        SimPduHandler           m_simpduhandler;
        SimPbBaseHandler        m_simadnhandler;
        SimPbBaseHandler        m_simlndhandler;
        SimPbBaseHandler        m_simfdnhandler;
        SimPbBaseHandler        m_simbdnhandler;
        SimPbBaseHandler        m_simsdnhandler;
        SimPbBaseHandler        m_simmsisdnhandler;
        SimPbBaseHandler        m_simcphsmboxhandler;
        SimPbBaseHandler        m_simcphsinfonohandler;
        SimPbBaseHandler        m_simmbdnhandler;

        SimCphsHandler          m_simcphshandler;
        SimChvHandler           m_simchvhandler;


        AuxProvider             m_auxprovider;
        PrefPlmnProvider        m_prefplmnprovider;
        PrefLangProvider        m_preflangprovider;
        PrefExtLangProvider     m_prefextlangprovider;
        EccProvider             m_eccprovider;
        SstProvider             m_sstprovider;

        PbBaseProvider          m_adnprovider;
        PbBaseProvider          m_msisdnprovider;
        PbBaseProvider          m_fdnprovider;
        PbBaseProvider          m_lndprovider;
        PbBaseProvider          m_cphsmboxprovider;
        PbBaseProvider          m_cphsinfonoprovider;
        PbBaseProvider          m_bdnprovider;
        PbBaseProvider          m_sdnprovider;
        PbBaseProvider          m_mbdnprovider;

        ChvProvider             m_chvprovider;

        SmsProvider             m_sms_provider;

#if defined(APOXI_SMS_NEW_PROVIDERS)
        SmsBaseInboxProvider        m_sms_base_inbox_provider;
        SmsBaseOutboxProvider       m_sms_base_outbox_provider;
        SmsBaseArchiveProvider      m_sms_base_archive_provider;
        SmsBaseStatusReportProvider m_sms_base_statusreport_provider;
        SmsBaseUnreadProvider       m_sms_base_unread_provider;
#elif !defined(APOXI_DISABLE_FILTERED_SMS_PROVIDERS)
        SmsReadProvider         m_sms_read_provider;
        SmsUnreadProvider       m_sms_unread_provider;
        SmsSentProvider         m_sms_sent_provider;
        SmsUnsentProvider       m_sms_unsent_provider;
#endif  // (APOXI_SMS_NEW_PROVIDERS

        SmsParamProvider        m_smsparamprovider;
        SmsCountProvider        m_sms_count_provider;
        SmsMsgWaitingProvider   m_sms_msg_wait_provider;

        CphsAuxProvider         m_cphs_auxprovider;
        CphsServPflProvider     m_cphs_servpflprovider;

        CbmiProvider            m_cbmiprovider;
        CbmiRangeProvider       m_cbmirangeprovider;

        SimTkMainMenuProvider   m_simtkmainmenuprov;
        SmsClass0Provider       m_sms_class0_provider;

        CountryProvider         m_countryprovider;
        PlmnProvider            m_plmnprovider;
        StatusProvider          m_statusprovider;
        LockProvider            m_lockprovider;

        CmiProvider             m_cmiprovider;
        MbiProvider             m_mbiprovider;

        Protector               m_phonebookprotector;
        Protector               m_smsprotector;
        Protector               m_auxiliaryprotector;

#if defined(APOXI_ICC_USIM)
        UstProvider             m_ustprovider;
        EstProvider             m_estprovider;
        PrefExtLangProvider     m_prefextlang2provider;
#endif
        EccCustomization        m_ecccustomization;     
        SimServices             m_simservices;

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)
    public:
        UsimPbHandler * GetUsimPbHandler() { return (&m_usimpbhandler); }
    private:
        UsimPbAccessor          m_usimpbaccessor;
        UsimPbHandler           m_usimpbhandler;
        UsimPbXasProvider       m_usimpb_gas_provider;
        UsimPbXasProvider       m_usimpb_aas_provider;
        UsimPbPropertyProvider  m_usimpb_prop_provider;
        UsimPbProvider          m_usimpb_provider;
#endif

};

/*  ========================================================================
    BootState
    ======================================================================== */

class BootState
{
    public:
        enum {
            NO_PROVIDERS = c_end_provider_range - c_start_provider_range,
            BITS_PER_UINT = sizeof(UINT) * 8,
            BITFIELDSIZE = (((NO_PROVIDERS*2) + BITS_PER_UINT - 1) / BITS_PER_UINT) * BITS_PER_UINT,
        };

        BootState();
        ~BootState();

        BOOLEAN IsUpdated(INT providerid) const;
        BOOLEAN IsAvailable(INT providerid) const;

        void SetUpdated(INT providerid); 
        void SetAvailable(INT providerid);

#if defined(_DEBUG)
        void DumpStates();
#endif

    private:
        // first NO_PROVIDERS describes IsLoaded, next NO_PROVIDERS describes IsAvailable 
        BitVector<BITFIELDSIZE> m_bitvector;
};

/*  ========================================================================
    BootControl
    ======================================================================== */

class BootControl
{
    public:
        friend class SmsLoadingFinishedCondition;

        BootControl();
        ~BootControl();
        enum {
            NO_PROVIDERS = c_end_provider_range - c_start_provider_range,
        };


        // is called from Asc/BootHandler
        void RequestOnStartup(INT providerid, BootNotification notification);

        // is called from Asc/BootDispatcher
        void StartLoading();
        
        // is called from Asc/BootDispatcher
        void OnFinishedSmsLoading();

        // is called from handlers and providers
        void SendDataControlBootProgressMsg(INT providerid, INT progress);

        // is called after a Sim init is received
        void DisableLoading() { m_allowed = FALSE; }

        // is called after a Sim full access is received
        void EnableLoading() { m_allowed = TRUE; }

        // checks if loading is allowed
        BOOLEAN IsLoadingAllowed() { return m_allowed; }

    private:
        BootNotification GetBootNotification(INT providerid);
        BOOLEAN ShallBeLoaded(INT providerid);
        void UpdateProvider(INT providerid);
        void SendDataControlBootMsg();

        UINT8 m_provider_control[NO_PROVIDERS];

        BootState m_bootstate;
        BOOLEAN   m_smsloaded;
        BOOLEAN   m_allowed;
};

/*  ========================================================================
    DataControl
    ======================================================================== */

class DataControl : public SubSystem
{
    public:
        typedef SubSystem Base;
        
        DataControl();

        virtual ~DataControl();

        virtual const WCHAR* GetName() const;

        virtual void OnPowerUp();

        virtual void OnPowerDown();

        virtual UINT8 GetPriority() const;

        virtual SubSystemManager::BootSequenceState InvokeAt() const;

        static DataHandler* GetDataHandler();
        static MainProvider* GetMainProvider();
        static void PostNotification(DataControlType type);
        static SimAccessor * GetSimAccessor() { return m_datahandler.GetSimAccessor(); }
        static BootControl * GetBootControl() { return &m_bootcontrol; }

    private:
        static DataControl * m_instance;
        static DataHandler   m_datahandler;
        static BootControl   m_bootcontrol;
};

/*  ========================================================================
    LookupAlphaIdExtension
    ======================================================================== */

class LookupAlphaIdExtension {
   
    public:
        LookupAlphaIdExtension();
        virtual ~LookupAlphaIdExtension();

        static LookupAlphaIdExtension* GetInstance();
        static void Register(LookupAlphaIdExtension * alpha);
        static void Unregister();
        static BOOLEAN IsRegistered();
        virtual BOOLEAN LookupAlphaId(const PhoneNumber & phno, WString & alphaid);

    private:
        static LookupAlphaIdExtension * m_registerdalphaid; 
};


#endif

