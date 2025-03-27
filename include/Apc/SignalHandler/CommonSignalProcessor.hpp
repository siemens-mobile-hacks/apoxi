/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_CommonSignalProcessor_hpp)
#define Apc_SignalHandler_CommonSignalProcessor_hpp


/*  ========================================================================
    CommonSignalProcessor
    ======================================================================== */
class CommonSignalProcessor {
    public:
        /*  ================================================================
            AT handling
            ================================================================ */
        static void PostAtAlphaTagReq(const ProcessPtr &process_ptr);
        static void PostAtPbSelectReq(const ProcessPtr &process_ptr);
        static void PostAtPbListReq(const ProcessPtr &process_ptr);
        static void PostAtGenericCmdReq(const ProcessPtr &process_ptr);
        static void PostAtAccessoryRegisterReq(const ProcessPtr &process_ptr);

        /*  ================================================================
            Atc signal-transformation
            ================================================================ */
        static void PostAtKeyReq(const ProcessPtr &process_ptr);

    #if defined(APOXI_ENABLE_RUNTIME_CONFIGURATION)
        static void PostAtApoxiReq(const ProcessPtr &process_ptr);
    #endif

        /*  ================================================================
            Audio
            ================================================================ */
        static void PostAudDriverRsp(const ProcessPtr &process_ptr);

        /*  ================================================================
            CallMisc signal-transformation
            ================================================================ */
        static void PostCallProgressInd(const ProcessPtr &process_ptr);
        static void PostCallDiscInd(const ProcessPtr &process_ptr);
        static void PostCallRelCnf(const ProcessPtr &process_ptr);
        static void PostCallRelInd(const ProcessPtr &process_ptr);
#if defined(APOXI_AT_MMI_INTERWORKING_CALL)
        static void PostCallInd(const ProcessPtr &process_ptr);
#endif
        static void PostStartDtmfCnf(const ProcessPtr &process_ptr);
        static void PostStopDtmfCnf(const ProcessPtr &process_ptr);
        static void PostStartDtmfRej(const ProcessPtr &process_ptr);
        static void PostDtmfBufferClearedInd(const ProcessPtr &process_ptr);
        static void PostNotifyInd(const ProcessPtr &process_ptr);
#if defined(APOXI_3GPP_REL_97_DOWNGRADE)    
        static void PostCallDiscCnf(const ProcessPtr &process_ptr);
        static void PostNwDiscStartInd(const ProcessPtr &process_ptr);
#endif
        static void PostDiagnosticInd(const ProcessPtr &process_ptr);

#if defined(APOXI_CTM)
        static void PostCtmInfoInd(const ProcessPtr &process_ptr);
#endif
        static void PostRedialStatusInd(const ProcessPtr &process_ptr);
        static void PostRedialQueryInd(const ProcessPtr &process_ptr);
#if defined(APOXI_AT_MMI_INTERWORKING_SIMTK)
        static void PostCallIndCallControlInfo(const ProcessPtr &process_ptr);
#endif
#if defined(APOXI_AT_MMI_INTERWORKING_REJECT)   
        static void PostMocSetupRejIndArg(const ProcessPtr &process_ptr);
#endif

        /*  ================================================================
            Cbs signal-transformation
            ================================================================ */
        static void PostCbsNewDataInd(const ProcessPtr &process_ptr);
        static void PostCbsStartRej(const ProcessPtr &process_ptr);
        static void PostCbsStopRej(const ProcessPtr &process_ptr);
        static void PostCbsStartCnf(const ProcessPtr &process_ptr);
        static void PostCbsStopCnf(const ProcessPtr &process_ptr);
        static void PostCbsLimitInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            CFU
            ================================================================ */
        static void PostCfuDataInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Network Eccs
            ================================================================ */
        static void PostEccListInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Chv signal-transformation
            ================================================================ */
        static void PostChvVerifyInd(const ProcessPtr &process_ptr);
        static void PostChvChangeInd(const ProcessPtr &process_ptr);
        static void PostChvUnblockInd(const ProcessPtr &process_ptr);
        static void PostPinEnableInd(const ProcessPtr &process_ptr);
        static void PostPinDisableInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Crss signal-transformation
            ================================================================ */
        static void PostCallRelatedSsCnf(const ProcessPtr &process_ptr);
        static void PostCallRelatedSsRej(const ProcessPtr &process_ptr);
        static void PostCallHoldRej(const ProcessPtr &process_ptr);
        static void PostCallHoldCnf(const ProcessPtr &process_ptr);
        static void PostMptyCnf(const ProcessPtr &process_ptr);
        static void PostEctCnf(const ProcessPtr &process_ptr);
        static void PostAocInd(const ProcessPtr &process_ptr);
        static void PostChargeInd(const ProcessPtr &process_ptr);
        static void PostCallDeflectionInd(const ProcessPtr &process_ptr);//Manik added for CD 07-August-2003
        static void PostChargeUnitsInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Image signal-transformation
            ================================================================ */
        static void PostIconDescReadInd(const ProcessPtr &process_ptr);
        static void PostImageReadInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Mdh signal-transformation
            ================================================================ */
        static void PostMdhSmsInitFinishedInd(const ProcessPtr &process_ptr);
        static void PostMdhDeregistrationCnf(const ProcessPtr &process_ptr);
        static void PostMdhMakeViewCnf(const ProcessPtr &process_ptr);
        static void PostMdhNewMessageInd(const ProcessPtr &process_ptr);
        static void PostMdhNewStatusReportInd(const ProcessPtr &process_ptr);
        static void PostMdhRegistrationCnf(const ProcessPtr &process_ptr);
        static void PostMdhRemoveViewCnf(const ProcessPtr &process_ptr);
        static void PostMdhSetConfigCnf(const ProcessPtr &proess_ptr);
        static void PostMdhSetStorageCnf(const ProcessPtr &process_ptr);
        static void PostMdhSmsReadInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsStatusInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsUpdStatusInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsWriteCnf(const ProcessPtr &process_ptr);
        static void PostMdhSmsRefreshInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsStorageRefreshInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsUpdStatusRefreshInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsWaitingInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsTransmitStartInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsTransmitInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsTransmitStopInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsReportReadInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsDeletionInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsConcRefNumInd(const ProcessPtr &process_ptr);
        static void PostMdhSmsExtendedDataInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Misc signal-transformation
            ================================================================ */
        static void PostKbdtControl(const ProcessPtr &process_ptr);
        static void PostSignalStrengthLevelInd(const ProcessPtr &process_ptr);
        static void PostUrrcSignalStrengthLevelInd(const ProcessPtr &process_ptr);
        static void PostImeiReadInd(const ProcessPtr &process_ptr);
        static void PostGetTermProfileCnfInd(const ProcessPtr &process_ptr);
        static void PostSetTermProfileCnfInd(const ProcessPtr &process_ptr);
        static void PostSetTermProfileRejInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Moc signal-transformation
            ================================================================ */
        static void PostMocSetupRej(const ProcessPtr &process_ptr);
        static void PostMocSetupAcc(const ProcessPtr &process_ptr);
        static void PostMocAlertInd(const ProcessPtr &process_ptr);
        static void PostMocSetupCnf(const ProcessPtr &process_ptr);
        static void PostRedialInd(const ProcessPtr &process_ptr);
        static void PostRedialSetupInd(const ProcessPtr &process_ptr);
        static void PostRedialStopInd(const ProcessPtr &process_ptr);
        static void PostAutoCallRestrictInd(const ProcessPtr &process_ptr);
        static void PostClearBlacklistCnf(const ProcessPtr &process_ptr);

        /*  ================================================================
            Mtc signal-transformation
            ================================================================ */
        static void PostMtcAcceptRej(const ProcessPtr &process_ptr);
        static void PostMtcConfInd(const ProcessPtr &process_ptr);
        static void PostMtcSetupInd(const ProcessPtr &process_ptr);
        static void PostMtcSetupCompl(const ProcessPtr &process_ptr);

        /*  ================================================================
            Network signal-transformation
            ================================================================ */
        static void PostConnectionInd(const ProcessPtr &process_ptr);
        static void PostCellInfoInd(const ProcessPtr &process_ptr);
        static void PostHomezoneInd(const ProcessPtr &process_ptr);
        static void PostMnInformationInd(const ProcessPtr &process_ptr);
        static void PostEngineeringModeControlResponse(const ProcessPtr &process_ptr);
        static void PostTestparamInd(const ProcessPtr &process_ptr);
        static void PostBandCnf(const ProcessPtr &process_ptr);
        static void PostBandRej(const ProcessPtr &process_ptr);

        /*  ================================================================
            Om signal-transformation
            ================================================================ */
        static void PostOmMultiSlotCnf(const ProcessPtr &process_ptr);
        static void PostOmMultiSlotRej(const ProcessPtr &process_ptr);
        static void PostOmBandStatusCnf(const ProcessPtr &process_ptr);

        /*  ================================================================
            PhoneBook signal-transformation
            ================================================================ */
        static void PostPbEntryReadInd(const ProcessPtr &process_ptr);
        static void PostPbEntryUpdInd(const ProcessPtr &process_ptr);
        static void PostPbInfoReadInd(const ProcessPtr &process_ptr);
        static void PostFdnInd(const ProcessPtr &process_ptr);
        static void PostBdnInd(const ProcessPtr &process_ptr);
        static void PostPbCountInd(const ProcessPtr &process_ptr);
        
        /*  ================================================================
            Plmn signal-transformation
            ================================================================ */
        static void PostPlmnListCnf(const ProcessPtr &process_ptr);
        static void PostPlmnListRej(const ProcessPtr &process_ptr);
        static void PostOmRatChangeCnf(const ProcessPtr &process_ptr);
        static void PostOmRatChangeInd(const ProcessPtr &process_ptr);
        static void PostNRegStateInd(const ProcessPtr &process_ptr);
        static void PostRegStateInd(const ProcessPtr &process_ptr);
        static void PostAttachCnf(const ProcessPtr &process_ptr);
        static void PostAttachRej(const ProcessPtr &process_ptr);
        static void PostAttachAllowedInd(const ProcessPtr &process_ptr);
        static void PostDetachCnf(const ProcessPtr &process_ptr);
        static void PostGprsClassInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Plmn inside imsi sending
            ================================================================ */
        static void PostSimMccMncInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Power signal-transformation
            ================================================================ */
        static void PostPowerDownCnf(const ProcessPtr &process_ptr);
        static void PostOmControlInd(const ProcessPtr &process_ptr);
        static void PostPowerDownInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            PrefPlmn signal-transformation
            ================================================================ */
//      static void PostPrefPlmnUpdInd(const ProcessPtr &process_ptr);
//      static void PostPrefPlmnReadInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            SimMisc signal-transformation
            ================================================================ */
        static void PostSimErrorInd(const ProcessPtr &process_ptr);
        static void PostSstReadInd(const ProcessPtr &process_ptr);
        static void PostSimGenericInd(const ProcessPtr &process_ptr);
        static void PostAcmReadInd(const ProcessPtr &process_ptr);
        static void PostAcmUpdInd(const ProcessPtr &process_ptr);
        static void PostAcmMaxReadInd(const ProcessPtr &process_ptr);
        static void PostAcmMaxUpdInd(const ProcessPtr &process_ptr);

        static void PostCbmiReadInd(const ProcessPtr &process_ptr);
        static void PostCbmirReadInd(const ProcessPtr &process_ptr);
        static void PostCbmiUpdInd(const ProcessPtr &process_ptr);
        static void PostCbmirUpdInd(const ProcessPtr &process_ptr);

        static void PostPuctReadInd(const ProcessPtr &process_ptr);
        static void PostPuctUpdInd(const ProcessPtr &process_ptr);
        static void PostPrefLangReadInd(const ProcessPtr &process_ptr);
        static void PostPrefLangUpdInd(const ProcessPtr &process_ptr);
        static void PostPrefExtLangReadInd(const ProcessPtr &process_ptr);
        static void PostPrefExtLangUpdInd(const ProcessPtr &process_ptr);
        static void PostSpnReadInd(const ProcessPtr &process_ptr);
        static void PostSimFileInfoInd(const ProcessPtr &process_ptr);

        static void PostCphsIstReadInd(const ProcessPtr &process_ptr);
        static void PostCphsVmwfReadInd(const ProcessPtr &process_ptr);
        static void PostCphsVmwfUpdInd(const ProcessPtr &process_ptr);
        static void PostCphsCfufReadInd(const ProcessPtr &process_ptr);
        static void PostCphsCfufUpdInd(const ProcessPtr &process_ptr);
        static void PostCphsOnmReadInd(const ProcessPtr &process_ptr);
        static void PostCphsOnsReadInd(const ProcessPtr &process_ptr);
        static void PostCphsCspReadInd(const ProcessPtr &process_ptr);
        static void PostCphsCspUpdInd(const ProcessPtr &process_ptr);

        static void PostODynReadInd(const ProcessPtr &process_ptr);
        static void PostODyn2ReadInd(const ProcessPtr &process_ptr);
        static void PostODynUpdInd(const ProcessPtr &process_ptr);
        static void PostODyn2UpdInd(const ProcessPtr &process_ptr);
        static void PostSimMruPropertyUpdCnf(const ProcessPtr &process_ptr);
        static void PostSimMruPropertyRefreshInd(const ProcessPtr &process_ptr);

        static void PostCcpReadInd(const ProcessPtr &process_ptr);
        static void PostCcpUpdInd(const ProcessPtr &process_ptr);

        static void PostSmsrReadInd(const ProcessPtr &process_ptr);
        static void PostSmsrUpdInd(const ProcessPtr &process_ptr);
        static void PostCmiReadInd(const ProcessPtr &process_ptr);
        
        static void PostChv1EnableInd(const ProcessPtr &process_ptr);
        static void PostChv1DisableInd(const ProcessPtr &process_ptr);
        static void PostChvRefreshInd(const ProcessPtr &process_ptr);
        static void PostSimFullAccessInd(const ProcessPtr &process_ptr);
        static void PostSimInfoInd(const ProcessPtr &process_ptr);
        static void PostSimInitInd(const ProcessPtr &process_ptr);
        static void PostSimLockStatusInd(const ProcessPtr &process_ptr);
        static void PostSimModifyLockInd(const ProcessPtr &process_ptr);
        static void PostSimRefreshInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Sms signal-transformation
            ================================================================ */
        static void PostSmsCapacityExceeded(const ProcessPtr &process_ptr);
        static void PostSmsCapacityAvailable(const ProcessPtr &process_ptr);
        static void PostSmsSendCnf(const ProcessPtr &process_ptr);
        static void PostSmsSendRej(const ProcessPtr &process_ptr);
        static void PostSmsGetMoreMessageStatusInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            Ss signal-transformation
            ================================================================ */
        static void PostSsBeginAcc(const ProcessPtr &process_ptr);
        static void PostSsFacilityRej(const ProcessPtr &process_ptr);
        static void PostSsForwardingInd(const ProcessPtr &process_ptr);
        static void PostSsBarringInd(const ProcessPtr &process_ptr);
        static void PostSsDataInd(const ProcessPtr &process_ptr);
        static void PostSsNotifyInd(const ProcessPtr &process_ptr);
        static void PostSsInterrogateInd(const ProcessPtr &process_ptr);
        static void PostSsPasswordInd(const ProcessPtr &process_ptr);
        static void PostSsUnstructInd(const ProcessPtr &process_ptr);
        static void PostSsForwcheckInd(const ProcessPtr &process_ptr);
        static void PostSsRetResInd(const ProcessPtr &process_ptr);
        static void PostSsEndInd(const ProcessPtr &process_ptr);
        static void PostSsRej(const ProcessPtr &process_ptr);
        static void PostSsErrInd(const ProcessPtr &process_ptr);
        static void PostSsGetPasswordInd(const ProcessPtr &process_ptr);
        static void PostSsGetPasswordRej(const ProcessPtr &process_ptr);
        static void PostSsUssdInd(const ProcessPtr &process_ptr);
        static void PostSsUssdResentInd(const ProcessPtr &process_ptr);
        static void PostSsCauseInd(const ProcessPtr &process_ptr);
#if defined(APOXI_AT_MMI_INTERWORKING_USSD)
        static void PostUssdAnswerInd(const ProcessPtr &process_ptr);
#endif
#if defined(APOXI_AT_MMI_INTERWORKING_SS)
        static void PostSsFacilityInd(const ProcessPtr &process_ptr);
#endif
        static void PostSsCcbsReCallInd(const ProcessPtr &process_ptr);
        static void PostSsClientRej(const ProcessPtr &process_ptr);
        static void PostSsCcbsResultInd(const ProcessPtr &process_ptr);
        static void PostSsCcbsStatusInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            SimTk signal-transformation
            ================================================================ */
        static void PostSimTkRefreshReq(const ProcessPtr &process_ptr);
        static void PostSimTkRefreshNewReq(const ProcessPtr &process_ptr);
        static void PostSimTkRefreshResetReq(const ProcessPtr &process_ptr);
        static void PostSimTkResetCnfReq(const ProcessPtr &process_ptr);
        static void PostSimTkResetCnf(const ProcessPtr &process_ptr);
        static void PostSimTkRefreshQueryReq(const ProcessPtr &process_ptr);
        static void PostSimTkRefreshCnfReq(const ProcessPtr &process_ptr);

        static void PostDisplayTextReq(const ProcessPtr &process_ptr);
        static void PostGetInputReq(const ProcessPtr &process_ptr);
        static void PostGetInkeyReq(const ProcessPtr &process_ptr);
        static void PostSelectItemReq(const ProcessPtr &process_ptr);
        static void PostSetupMenuReq(const ProcessPtr &process_ptr);
        static void PostMenuSelectionRej(const ProcessPtr &process_ptr);
        static void PostPlayToneReq(const ProcessPtr &process_ptr);
        static void PostSetupIdleModeTextReq(const ProcessPtr &process_ptr);
        static void PostEndSimToolkitInd(const ProcessPtr &process_ptr);
        static void PostLanguageNotificationInd(const ProcessPtr &process_ptr);
        static void PostSetupEventReq(const ProcessPtr &process_ptr);
        static void PostLanguageSettingReq(const ProcessPtr &process_ptr);

        static void PostExtProactiveCmdInd(const ProcessPtr &process_ptr);

        static void PostTermRspCnf(const ProcessPtr &process_ptr);

        static void PostLaunchBrowserReq(const ProcessPtr &process_ptr);
        static void PostLaunchBrowserPromptReq(const ProcessPtr &process_ptr);
        static void PostBrowserTermRes(const ProcessPtr &process_ptr);

        static void PostSimTkRunAtCmdInfoInd(const ProcessPtr &process_ptr);

        static void PostSimTkSendDtmfInd(const ProcessPtr &process_ptr);
        static void PostSimTkSendDtmfEndInd(const ProcessPtr &process_ptr);

        static void PostSimTkInterfaceInd(const ProcessPtr &process_ptr);
        static void PostSimTkCallSetupInd(const ProcessPtr &process_ptr);
        static void PostSimTkSmsPpInd(const ProcessPtr &process_ptr);
        static void PostSimTkSsInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            SimTk call control signal-transformation
            ================================================================ */
        static void PostCallControlSetupInd(const ProcessPtr &process_ptr);
        static void PostCallControlSsInd(const ProcessPtr &process_ptr);
        static void PostCallControlUssdInd(const ProcessPtr &process_ptr);
        static void PostSmsControlInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            USIMAP
            ================================================================ */
#if defined(APOXI_ICC_USIM)
        static void PostUsimReadRej(const ProcessPtr &process_ptr);
        static void PostUsimReadRecordRej(const ProcessPtr &process_ptr);
        static void PostUsimUpdCnfArg(const ProcessPtr &process_ptr);
        static void PostUsimUpdRejArg(const ProcessPtr &process_ptr);

        static void PostUsimUstReadInd(const ProcessPtr &process_ptr);
        static void PostUsimEstReadInd(const ProcessPtr &process_ptr);
        static void PostUsimCsLociReadInd(const ProcessPtr &process_ptr);
        static void PostUsimPsLociReadInd(const ProcessPtr &process_ptr);
        static void PostUsimPlmnReadInd(const ProcessPtr &process_ptr);
        static void PostUsimLangReadInd(const ProcessPtr &process_ptr);
        static void PostUsimEccReadInd(const ProcessPtr &process_ptr);
        static void PostUsimSmsParamReadInd(const ProcessPtr &process_ptr);
        static void PostUsimSmsParamExtInd(const ProcessPtr &process_ptr);
        static void PostUsimCardTypeReadInd(const ProcessPtr &process_ptr);

        static void PostUsimSmsParamUpdInd(const ProcessPtr &process_ptr);
        static void PostUsimFilePropertyInd(const ProcessPtr &process_ptr);
#endif

        /*  ================================================================
            USIM phonebook
            ================================================================ */
#if defined(APOXI_ENABLE_USIM_PHONEBOOK) && ! defined(APOXI_USIM_PB_SIMULATION)
        static void PostUsimPbLocationInd(const ProcessPtr &process_ptr);
        static void PostUsimPbSelectRes(const ProcessPtr &process_ptr);
        static void PostUsimPbReadRes(const ProcessPtr &process_ptr);
        static void PostUsimPbReadRefRes(const ProcessPtr &process_ptr);
        static void PostUsimPbReadDataRes(const ProcessPtr &process_ptr);
        static void PostUsimPbUpdRes(const ProcessPtr &process_ptr);
        static void PostUsimPbUpdRefRes(const ProcessPtr &process_ptr);
        static void PostUsimPbUpdDataRes(const ProcessPtr &process_ptr);
        static void PostUsimPbFillStatusRes(const ProcessPtr &process_ptr);
        static void PostUsimPbStopRes(const ProcessPtr &process_ptr);
        static void PostUsimPbUidRefreshInd(const ProcessPtr &process_ptr);
        static void PostUsimPbReadyInd(const ProcessPtr &process_ptr);
#endif

#ifdef APOXI_LETTERCLASSE_SUPPORT
        /*  ================================================================
            SimTk Letter Class E (Sim to Proactive Client)
            ================================================================ */
        static void PostSiChannelOpenPromptReq(const ProcessPtr &process_ptr);
        static void PostSiChannelCloseInfoInd(const ProcessPtr &process_ptr);
        static void PostSiChannelSendInfoInd(const ProcessPtr &process_ptr);
        static void PostSiChannelReceiveInfoInd(const ProcessPtr &process_ptr);

        /*  ================================================================
            SimTk Letter Class E (Sim to IP-Stack)
            ================================================================ */
        static void PostDhChannelOpenReq(const ProcessPtr &process_ptr);
        static void PostDhChannelCloseReq(const ProcessPtr &process_ptr);
        static void PostDhChannelSendReq(const ProcessPtr &process_ptr);
        static void PostDhChannelDataAvailableRes(const ProcessPtr &process_ptr);
        static void PostDhChannelReceiveReq(const ProcessPtr &process_ptr);
        static void PostDhChannelChangeStatusRes(const ProcessPtr &process_ptr);
#endif  // APOXI_LETTERCLASSE_SUPPORT

#ifdef APOXI_UUS_SUPPORT

        /*  ================================================================
            User-to-User-Signaling (UUS)
            ================================================================ */
        static void PostUus1Ind(const ProcessPtr &process_ptr);
        static void PostUus1QueryInd(const ProcessPtr &process_ptr);
        static void PostUus1QueryRej(const ProcessPtr &process_ptr);
#endif
    private:
        static Ticks m_duration;
        static KeyCode m_keycode;

};

#endif  // Apc_SignalHandler_CommonSignalProcessor_hpp

