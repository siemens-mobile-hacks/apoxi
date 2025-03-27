/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_CommonStackMsgProcessor_hpp)
#define Apc_SignalHandler_CommonStackMsgProcessor_hpp

#include <Apc/SignalHandler/StackMsgProcessor.hpp>

class StackMsgArgument;

/*  ========================================================================
    CommonStackMsgProcessor
    ======================================================================== */
class CommonStackMsgProcessor : public StackMsgProcessor {
    public:
        /*  ================================================================
            AT confirmations
            ================================================================ */
        static void ProcessAtAlphaTagCnf(const StackMsgArgument &arg);
        static void ProcessAtPbSelectCnf(const StackMsgArgument &arg);
        static void ProcessAtPbListCnf(const StackMsgArgument &arg);
        static void ProcessAtPbInfoInd(const StackMsgArgument &arg);
        static void ProcessAtGenericCmdInd(const StackMsgArgument & arg);
        static void ProcessAtAccessoryNotificationInd(const StackMsgArgument &arg);
        static void ProcessAtAccessoryRegisterCnf(const StackMsgArgument &arg);

        /*  ================================================================
            CallMisc argument-transformation
            ================================================================ */
        static void ProcessCallDiscReq(const StackMsgArgument &arg);
        static void ProcessStartDtmfReq(const StackMsgArgument &arg);
        static void ProcessStopDtmfReq(const StackMsgArgument &arg);
        static void ProcessRejectCallsInd(const StackMsgArgument &arg);
        static void ProcessRedialingQueryReq(const StackMsgArgument &arg);

        /*  ================================================================
            Cbs argument-transformation
            ================================================================ */
        static void ProcessCbsStartReq(const StackMsgArgument &arg);
        static void ProcessCbsNewDataRej(const StackMsgArgument &arg);
        static void ProcessCbsStopReq(const StackMsgArgument &arg);

        /*  ================================================================
            Chv argument-transformation
            ================================================================ */
        static void ProcessChvVerifyReq(const StackMsgArgument &arg);
        static void ProcessChvChangeReq(const StackMsgArgument &arg);
        static void ProcessChvUnblockReq(const StackMsgArgument &arg);
        static void ProcessChv1EnableReq(const StackMsgArgument &arg);
        static void ProcessChv1DisableReq(const StackMsgArgument &arg);
        static void ProcessPinEnableReq(const StackMsgArgument &arg);
        static void ProcessPinDisableReq(const StackMsgArgument &arg);


        /*  ================================================================
            Crss argument-transformation
            ================================================================ */
        static void ProcessCallRelatedSsReq(const StackMsgArgument &arg);
        static void ProcessCallDeflectSsReq(const StackMsgArgument &arg); 
        static void ProcessSetAutoCharge(const StackMsgArgument &arg);
        static void ProcessChargeReq(const StackMsgArgument &arg);
        static void ProcessSetChargeUnits(const StackMsgArgument &arg);
        static void ProcessChargeUnitsReq(const StackMsgArgument &arg);

        /*  ================================================================
            Image argument-transformation
            ================================================================ */
        static void ProcessImageReadReq(const StackMsgArgument &arg);
        static void ProcessIconDescReadReq(const StackMsgArgument &arg);

        /*  ================================================================
            Mdh argument-transformation
            ================================================================ */
        static void ProcessMdhDeregistrationReq(const StackMsgArgument &arg);
        static void ProcessMdhMakeViewReq(const StackMsgArgument &arg);
        static void ProcessMdhRegistrationReq(const StackMsgArgument &arg);
        static void ProcessMdhRemoveViewReq(const StackMsgArgument &arg);
        static void ProcessMdhSetConfigReq(const StackMsgArgument &arg);
        static void ProcessMdhSetStorageReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsStatusReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsUpdStatusReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsReadReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsWriteReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsSetWaitingReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsTransmitStartAck(const StackMsgArgument &arg);
        static void ProcessMdhSmsTransmitAck(const StackMsgArgument &arg);
        static void ProcessMdhSmsReportReadReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsDeletionReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsConcRefNumReq(const StackMsgArgument &arg);
        static void ProcessMdhSmsExtendedDataReq(const StackMsgArgument &arg);

        /*  ================================================================
            Misc argument-transformation
            ================================================================ */
        static void ProcessImeiReadReq(const StackMsgArgument &arg);
        static void ProcessTestparamReq(const StackMsgArgument &arg);
        static void ProcessBandSelectionReq(const StackMsgArgument &arg);
        static void ProcessSimModifyLockReq(const StackMsgArgument &arg);
        static void ProcessEngineeringModeControlRequest(const StackMsgArgument &arg);

        /*  ================================================================
            Moc argument-transformation
            ================================================================ */
        static void ProcessRedialRej(const StackMsgArgument &arg);
        static void ProcessRediallingDisabledInd(const StackMsgArgument &arg);
        static void ProcessClearBlacklistReq(const StackMsgArgument &arg);
        static void ProcessMocSetupReq(const StackMsgArgument &arg);

        /*  ================================================================
            Mtc argument-transformation
            ================================================================ */
        static void ProcessMtcAccept(const StackMsgArgument &arg);
        static void ProcessMtcAlertReq(const StackMsgArgument &arg);

        /*  ================================================================
            Network argument-transformation
            ================================================================ */
        static void ProcessMnTriggerReq(const StackMsgArgument &arg);
        static void ProcessMnNetworkSearchModeReq(const StackMsgArgument &arg);

        /*  ================================================================
            Om argument-transformation
            ================================================================ */
        static void ProcessOmMultiSlotReq(const StackMsgArgument &arg);
        static void ProcessOmBandStatusReq(const StackMsgArgument &arg);

        /*  ================================================================
            PhoneBook argument-transformation
            ================================================================ */
        static void ProcessPbInfoReadReq(const StackMsgArgument &arg);
        static void ProcessPbEntryReadReq(const StackMsgArgument &arg);
        static void ProcessPbEntryUpdReq(const StackMsgArgument &arg);
        static void ProcessFdnReq(const StackMsgArgument &arg);
        static void ProcessBdnReq(const StackMsgArgument &arg);
        static void ProcessPbCountReq(const StackMsgArgument &arg);

        /*  ================================================================
            Plmn argument-transformation
            ================================================================ */
        static void ProcessPlmnListAbort(const StackMsgArgument &arg);
        static void ProcessPlmnListReq(const StackMsgArgument &arg);
        static void ProcessPrefPlmnChange(const StackMsgArgument &arg);
        static void ProcessOmRatChangeReq(const StackMsgArgument &arg);
        static void ProcessPrefServiceSetReq(const StackMsgArgument &arg);
        static void ProcessAttachReq(const StackMsgArgument &arg);
        static void ProcessDetachReq(const StackMsgArgument &arg);
        static void ProcessPlmnInfoReq(const StackMsgArgument &arg);
        static void ProcessGprsClassReq(const StackMsgArgument &arg);

        /*  ================================================================
            Power argument-transformation
            ================================================================ */
        static void ProcessOmPowerUp(const StackMsgArgument &arg);

        static void ProcessClientRegistration(const StackMsgArgument &arg);
        static void ProcessClientDeregistration(const StackMsgArgument &arg);
        static void ProcessStartSignalStrengthListening(const StackMsgArgument &arg);
        static void ProcessControlHwDataOnlyReq(const StackMsgArgument &arg);
        static void ProcessStopBatteryLoadListening(const StackMsgArgument &arg);
        static void ProcessStopSignalStrengthListening(const StackMsgArgument &arg);
        static void ProcessPowerDownReq(const StackMsgArgument &arg);

        /*  ================================================================
            SimMisc argument-transformation
            ================================================================ */
        static void ProcessSimGenericReq(const StackMsgArgument &arg);
        static void ProcessSstReadReq(const StackMsgArgument &arg);
        static void ProcessAcmReadReq(const StackMsgArgument &arg);
        static void ProcessAcmUpdReq(const StackMsgArgument &arg);
        static void ProcessAcmMaxReadReq(const StackMsgArgument &arg);
        static void ProcessAcmMaxUpdReq(const StackMsgArgument &arg);
        static void ProcessCbmiReadReq(const StackMsgArgument &arg);
        static void ProcessCbmirReadReq(const StackMsgArgument &arg);
        static void ProcessCbmiUpdReq(const StackMsgArgument &arg);
        static void ProcessCbmirUpdReq(const StackMsgArgument &arg);

        static void ProcessPuctReadReq(const StackMsgArgument &arg);
        static void ProcessPuctUpdReq(const StackMsgArgument &arg);
        static void ProcessPrefLangReadReq(const StackMsgArgument &arg);
        static void ProcessPrefLangUpdReq(const StackMsgArgument &arg);
        static void ProcessPrefExtLangReadReq(const StackMsgArgument &arg);
        static void ProcessPrefExtLangUpdReq(const StackMsgArgument &arg);
        static void ProcessSpnReadReq(const StackMsgArgument &arg);
        static void ProcessSimFileInfoReq(const StackMsgArgument &arg);
        static void ProcessCcpReadReq(const StackMsgArgument &arg);
        static void ProcessCcpUpdReq(const StackMsgArgument &arg);
        static void ProcessSmsrReadReq(const StackMsgArgument &arg);
        static void ProcessSmsrUpdReq(const StackMsgArgument &arg);

        static void ProcessCphsIstReadReq(const StackMsgArgument &arg);
        static void ProcessCphsVmwfReadReq(const StackMsgArgument &arg);
        static void ProcessCphsVmwfUpdReq(const StackMsgArgument &arg);
        static void ProcessCphsCfufReadReq(const StackMsgArgument &arg);
        static void ProcessCphsCfufUpdReq(const StackMsgArgument &arg);
        static void ProcessCphsOnmReadReq(const StackMsgArgument &arg);
        static void ProcessCphsOnsReadReq(const StackMsgArgument &arg);
        static void ProcessCphsCspReadReq(const StackMsgArgument &arg);
        static void ProcessCphsCspUpdReq(const StackMsgArgument &arg);

        static void ProcessCmiReadReq(const StackMsgArgument &arg);

        static void ProcessODynReadReq(const StackMsgArgument &arg);
        static void ProcessODyn2ReadReq(const StackMsgArgument &arg);
        static void ProcessODynUpdReq(const StackMsgArgument &arg);
        static void ProcessODyn2UpdReq(const StackMsgArgument &arg);
        static void ProcessSimMruPropertyUpdReq(const StackMsgArgument &arg);

        /*  ================================================================
            SimTk argument-transformation
            ================================================================ */
        static void ProcessSimTkRefreshCnfInd(const StackMsgArgument &arg);
        static void ProcessSimTkRefreshQueryRes(const StackMsgArgument &arg);
        static void ProcessSimTkRefreshRsp(const StackMsgArgument &arg);
        static void ProcessSimTkRefreshNewRsp(const StackMsgArgument &arg);
        static void ProcessSimTkRefreshResetRsp(const StackMsgArgument &arg);
        static void ProcessSimTkResetCnfInd(const StackMsgArgument &arg);

        static void ProcessDisplayTextRsp(const StackMsgArgument &arg);
        static void ProcessGetInputRsp(const StackMsgArgument &arg);
        static void ProcessGetInkeyRsp(const StackMsgArgument &arg);
        static void ProcessSelectItemRsp(const StackMsgArgument &arg);
        static void ProcessSetupMenuRsp(const StackMsgArgument &arg);
        static void ProcessMenuSelectionReq(const StackMsgArgument &arg);
        static void ProcessPlayToneRsp(const StackMsgArgument &arg);
        static void ProcessSetupIdleModeTextRsp(const StackMsgArgument &arg);
        static void ProcessSetupEventCnf(const StackMsgArgument &arg);
        static void ProcessUserActivityEvent(const StackMsgArgument &arg);
        static void ProcessIdleScreenAvailEvent(const StackMsgArgument &arg);
        static void ProcessLanguageSelectEvent(const StackMsgArgument &arg);
        static void ProcessLanguageSettingInd(const StackMsgArgument &arg);

        static void ProcessExtProactiveCmdReq(const StackMsgArgument &arg);
        static void ProcessExtProactiveCmdCnf(const StackMsgArgument &arg);

        static void ProcessSimTkRunAtCmdInfoRes(const StackMsgArgument &arg);

        static void ProcessSimTkSendDtmfCnf(const StackMsgArgument &arg);
        static void ProcessSimTkStopSendDtmfReq(const StackMsgArgument &arg);

        static void ProcessSimTkSmsPpRsp(const StackMsgArgument &arg);
        static void ProcessSimTkSsRsp(const StackMsgArgument &arg);
        static void ProcessSimTkCallSetupAcc(const StackMsgArgument &arg);
        static void ProcessSimTkCallSetupRej(const StackMsgArgument &arg);

        /*  ================================================================
            SimTk launch Browser
            ================================================================ */
        static void ProcessBrowserRegisterReq(const StackMsgArgument &arg);
        static void ProcessLaunchBrowserPromptInd(const StackMsgArgument &arg);
        static void ProcessLaunchBrowserInd(const StackMsgArgument &arg);
        static void ProcessBrowserTermEvent(const StackMsgArgument &arg);

        /*  ================================================================
            SimTk Letter Class E
            ================================================================ */
        //---------Proactive Client to SIM------------------------------------------
        static void ProcessSiChannelOpenPromptRes(const StackMsgArgument &arg);
        static void ProcessSiChannelCloseReq(const StackMsgArgument &arg);
        static void ProcessSiChannelCloseInfoRes(const StackMsgArgument &arg);
        static void ProcessSiChannelSendInfoRes(const StackMsgArgument &arg);
        static void ProcessSiChannelReceiveInfoRes(const StackMsgArgument &arg);
        //---------IP-Stack to SIM--------------------------------------------------
        static void ProcessDhChannelOpenCnf(const StackMsgArgument &arg);
        static void ProcessDhChannelOpenRej(const StackMsgArgument &arg);
        static void ProcessDhChannelCloseInd(const StackMsgArgument &arg);
        static void ProcessDhChannelSendInd(const StackMsgArgument &arg);
        static void ProcessDhChannelDataAvailEvent(const StackMsgArgument &arg);
        static void ProcessDhChannelReceiveInd(const StackMsgArgument &arg);
        static void ProcessDhChannelChangeStatusEvent(const StackMsgArgument &arg);
        //-------

        /*  ================================================================
            Sms argument-transformation
            ================================================================ */
        static void ProcessSmsConfigIndArg(const StackMsgArgument &arg);
        static void ProcessSmsSendReq(const StackMsgArgument &arg);
        static void ProcessSmsSetMoreMessageReq(const StackMsgArgument &arg);
        static void ProcessSmsGetMoreMessageStatusReq(const StackMsgArgument &arg);

        /*  ================================================================
            Ss argument-transformation
            ================================================================ */
        static void ProcessSsSendReq(const StackMsgArgument &arg);
        static void ProcessSsSendEndReq(const StackMsgArgument &arg);
        static void ProcessSsGetPasswordRsp(const StackMsgArgument &arg);
        static void ProcessSsErrReq(const StackMsgArgument &arg);
        static void ProcessSsRejReq(const StackMsgArgument &arg);
        static void ProcessSsUssdReq(const StackMsgArgument &arg);

        static void ProcessSsCcbsInvoke(const StackMsgArgument &arg);
        static void ProcessSsCcbsReject(const StackMsgArgument &arg);
        static void ProcessSsCcbsReCallRequest(const StackMsgArgument &arg);

        /*  ================================================================
            Status argument-transformation
            ================================================================ */
        static void ProcessOmFactoryResetInd(const StackMsgArgument &arg);
        static void ProcessOmGetTermProfileReq(const StackMsgArgument &arg);
        static void ProcessOmSetTermProfileReq(const StackMsgArgument &arg);

        /*  ================================================================
            USIMAP
            ================================================================ */
#if defined(APOXI_ICC_USIM)
        static StackMsgArgId GetLastUsimRequestId();

        static void ProcessUsimUstReadReq(const StackMsgArgument &arg);
        static void ProcessUsimEstReadReq(const StackMsgArgument &arg);
        static void ProcessUsimCsLociReadReq(const StackMsgArgument &arg);
        static void ProcessUsimPsLociReadReq(const StackMsgArgument &arg);
        static void ProcessUsimPlmnReadReq(const StackMsgArgument &arg);
        static void ProcessUsimLangReadReq(const StackMsgArgument &arg);
        static void ProcessUsimEccReadReq(const StackMsgArgument &arg);
        static void ProcessUsimSmsParamReadReq(const StackMsgArgument &arg);
        static void ProcessUsimCardTypeReadReq(const StackMsgArgument &arg);

        static void ProcessUsimPlmnUpdReq(const StackMsgArgument &arg);
        static void ProcessUsimLangUpdReq(const StackMsgArgument &arg);
        static void ProcessUsimSmsParamUpdReq(const StackMsgArgument &arg);
        static void ProcessUsimFilePropertyReq(const StackMsgArgument &arg);
#endif
        /*  ================================================================
            USIM Phonebook
            ================================================================ */
#if defined(APOXI_ENABLE_USIM_PHONEBOOK) && ! defined(APOXI_USIM_PB_SIMULATION)
        static void ProcessUsimPbLocationReq(const StackMsgArgument &arg);
        static void ProcessUsimPbSelectReq(const StackMsgArgument &arg);
        static void ProcessUsimPbReadReq(const StackMsgArgument &arg);
        static void ProcessUsimPbReadRefReq(const StackMsgArgument &arg);
        static void ProcessUsimPbReadDataReq(const StackMsgArgument &arg);
        static void ProcessUsimPbUpdReq(const StackMsgArgument &arg);
        static void ProcessUsimPbUpdRefReq(const StackMsgArgument &arg);
        static void ProcessUsimPbUpdDataReq(const StackMsgArgument &arg);
        static void ProcessUsimPbFillStatusReq(const StackMsgArgument &arg);
        static void ProcessUsimPbStopReq(const StackMsgArgument &arg);
        static void ProcessUsimPbReadCnf(const StackMsgArgument &arg);
#endif


#if defined(APOXI_UUS_SUPPORT)
        /*  ================================================================
            UUS
            ================================================================ */
        static void ProcessUus1Req(const StackMsgArgument &arg);
        static void ProcessUus1QueryReq(const StackMsgArgument &arg);
#endif

};

#endif  // Apc_SignalHandler_CommonStackMsgProcessor_hpp

