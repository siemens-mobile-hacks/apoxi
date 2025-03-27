/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CallInfoParser_hpp)
#define Apoxi_CallInfoParser_hpp

#include <AddOns/MmCall/AtResponseIterator.hpp>

class XCallInfoResponseParser {
    public:

        enum CallInfoType {
            CallInfoNotValid = 0,
            CallControlCallSetupInfo = 1,
            CallSetup = 2,
            CallClearing = 3,
            DualServiceCallModification = 4,
            CrssTransaction = 5
        };

        enum CcPerformed {
            CCNotValid = 0,
            CCNotPerformed = 1,
            CCPerformed = 2
        };

        enum SetupState {
            SetupStateNotValid = 0,
            MoCallRequested = 1,
            MoCallDialing = 2,
            MocRemoteUserAlerted = 3,
            MtcConfirmed = 4,
            MtcIndicated = 5,
            MtcBcNegotiated = 6,
            MtcAccepted = 7,
            CallActive = 8
        };

        enum CallDirection {
            CdNotValid = 0,
            MOC = 1,
            MTC = 2
        };


        enum EstablishmentCause {
            EstCauseNotValid = 0,
            EmergencyCall = 1,
            NormalCall = 2
        };

        enum CallType {
            CallTypeNotValid = 0,
            SingleVoiceCall = 1,
            SingleFaxCall = 2,
            SingleDataCall = 3,
            DualCall = 4
        };

        enum CallMode {
            CallModeNotValid = 0,
            Voice = 1,
            Fax = 2,
            Data = 3
        };

        enum SelectedLine {
            SelLineNotValid = 0,
            Speech = 1,
            AuxiliarySpeech = 3
        };

        enum CtmStatus {
            CtmNotValid = 0,
            CtmCall = 1,
            AudioBasedCall = 2
        };

        enum CliValidity {
            CliValid = 0,
            CliWithheldByOriginator = 1,
            CliNotAvailable = 2,
            CliInvalid
        };

        enum ClearingState {
            ClearingStateNotValid = 0,
            MocSetupRejected = 1,
            Disconnected = 2,
            DisconnectIndicated = 3,
            Cleared = 4
        };
    
        enum ModificationState {
            ModificationStateNotValid = 0,
            ModificationIndicated = 1,
            ModificationStarted = 2,
            ModificationRejected = 3,
            ModificationCompleted = 4
        };

        enum CrssState {
            CrssNotValid = 0,
            CallHeldStarted = 1,
            CallHeldRejected = 2,
            CallHeldCompleted = 3,
            CallRetrieveStarted = 4,
            CallRetrieveRejected = 5,
            CallRetrieveCompleted = 6,
            MultiPartyStarted = 7,
            MultiPartyRejected = 8,
            MultiPartyCompleted = 9,
            MultiPartyHeldStarted = 10,
            MultiPartyHeldRejected = 11,
            MultiPartyHeldCompleted = 12,
            MultiPartyRetrieveStarted = 13,
            MultiPartyRetrieveRejected = 14,
            MultiPartyRetrieveCompleted = 15,
            MultiPartySplitStarted = 16,
            MultiPartySplitRejected = 17,
            MultiPartySplitCompleted = 18,
            ExplicitCallTransferStarted = 19,
            ExplicitCallTransferRejected = 20,
            ExplicitCallTransferCompleted = 21,
            CallDeflectionStarted = 22,
            CallDeflectionRejected = 23,
            CallDeflectionCompleted = 24
        };

        XCallInfoResponseParser(const AtResponse &response);
        
        ~XCallInfoResponseParser();

        CallInfoType GetType() const;

        INT GetCallId() const;

        Tipd GetTipd() const;

        CcPerformed GetCcPerformed() const;

        INT GetSimResult() const;

        const String GetAlpha() const;

        SetupState GetSetupState() const;

        CallDirection GetCallDirection() const;

        EstablishmentCause GetEstCause() const;

        INT GetEccCategory() const;

        CallType GetCallType() const;

        CallMode GetCallMode() const;

        INT GetChannelMode() const;

        SelectedLine GetSelectedLine() const;

        CtmStatus GetCtmStatus() const;

        const PhoneNumber GetPhoneNumber() const;

        CliValidity GetCliValidity() const;

        ClearingState GetClearingState() const;

        INT GetClearingCause() const;

        ModificationState GetModificationState() const;

        CallMode GetCurrentCallMode() const;

        CrssState GetCrssState() const;

    private:
        AtResponse          m_response;
        CallInfoType        m_type;

    
};


#endif // Apoxi_CallInfoParser_hpp

