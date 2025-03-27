/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bt_Types_hpp)
#define Bt_Types_hpp

#include <stack/extensions.h>
#include <Kernel/Types.hpp>

/*****************************************************************************
 * Bluetooth general definitions                                             *
 *****************************************************************************

 *---------------------------------------------------------------------------*
 * Bluetooth general constants                                               *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * Bluetooth general enums                                                   *
 *---------------------------------------------------------------------------*/


typedef enum {
    BtRcAccepted =  2,
    BtRcPending  =  3,
    BtRcOk       =  0,
    BtRcRejected = -1,
    BtRcIgnored  = -2,
    BtRcError    = -3,
    BtRcUnknown  = -128
} BtResultCode;


typedef enum {
    BtRqsUnknown = -1,
    BtRqsInitialized,
    BtRqsAccepted,
    BtRqsRejected,
    BtRqsAcceptedCancelation,
    BtRqsExecuting,
    BtRqsIgnored,
    BtRqsExecutingCancelation,
    BtRqsFinishedOk,
    BtRqsFinishedFailure
} BtRequestState;


typedef enum {
    BtRqtUnknown,
    BtRqtDevicePair,
    BtRqtDeviceUnpair,
    BtRqtDeviceTrust,
    BtRqtDeviceUntrust,
    BtRqtSetRemoteDeviceName,
    BtRqtQuerySupportedProfiles,
    BtRqtSendPasskey,
    BtRqtRespondAuthorization,
    BtRqtDeviceSearch,
    BtRqtServiceVerify,
    BtRqtSddbRegisterServiceRecord,
    BtRqtSddbUnregisterServiceRecord,
    BtRqtDunDisconnect,
    BtRqtFaxDisconnect,
    BtRqtHsConnect,
    BtRqtHsDisconnect,
    BtRqtHsRing,
    BtRqtHsStopRing,
    BtRqtHsHangUp,
    BtRqtHsTransferAudioToPhone,
    BtRqtHsTransferAudioToAccessory,
    BtRqtHsSetMicrophoneGain,
    BtRqtHsSetSpeakerGain,
    BtRqtHfConnect,
    BtRqtHfDisconnect,
    BtRqtHfTransferAudioToPhone,
    BtRqtHfTransferAudioToAccessory,
    BtRqtHfSetMicrophoneGain,
    BtRqtHfSetSpeakerGain,
    BtRqtObexRegisterServer,
    BtRqtObexUnregisterServer,
    BtRqtObexSendResponse,
    BtRqtObexRegisterClient,
    BtRqtObexUnregisterClient,
    BtRqtObexConnect,
    BtRqtObexDisconnect,
    BtRqtObexSetPath,
    BtRqtObexGet,
    BtRqtObexPut,
    BtRqtObexAbort,
    BtRqtAvrcpConnect,
    BtRqtAvrcpConnectRsp,
    BtRqtAvrcpDisconnect,
    BtRqtAvrcpRegister,
    BtRqtAvrcpDeRegister,
    BtRqtAvrcpUnitInfo,
    BtRqtAvrcpPanelPassThrough,
    BtRqtAvrcpRawFrame,
    BtRqtAvrcpSubunitInfo, 
    BtRqtAvrcpPanelPassThroughRsp,
    BtRqtAvrcpRawFrameRsp,
    BtRqtBppSndFilePushReq,
    BtRqtBppSndGetRefObjRsp,
    BtRqtBppSndAbortReq,
    BtRqtBppSndAuthenticationReqRes,
    BtRqtBipConnect,
    BtRqtBipDisconnect,
    BtRqtBipAbort,
    BtRqtBipPutImage,
    BtRqtBipPutLinkedThumbnail,
    BtRqtBipPutLinkedAttachment,
    BtRqtBipGetImagesList,
    BtRqtBipGetImage,
    BtRqtBipGetLinkedThumbnail,
    BtRqtBipGetLinkedAttachment,
    BtRqtBipGetImageProperties,
    BtRqtBipDeleteImage,
    BtRqtBipGetImagingCapabilities
} BtRequestType;


typedef enum {
    BtOpPerformServiceVerify,
    BtOpSelectDevice,
    BtOpSelectDeviceAndPerformServiceVerify
} BtOperationType;


typedef enum {
    BtDsKnown,
    BtDsPaired,
    BtDsTrusted,
    BtDsConnected
} BtDeviceState;


typedef enum {
    BtProfileUnknown = -1,
    BtProfileGapAndSdap,
    BtProfileDun     = BTAPI_DUN,
    BtProfileHs      = BTAPI_HS,
    BtProfileHf      = BTAPI_HF,
    BtProfileOpp     = BTAPI_OPP,
    BtProfileFtp     = BTAPI_FTP,
    BtProfileObex    = BTAPI_OBEX,
    BtProfileSap     = BTAPI_SAP,
    BtProfileFax     = BTAPI_FAX,
    BtProfileA2dp    = BTAPI_A2DP,
    BtProfileAad     = BtProfileA2dp,
    BtProfilePap     = BTAPI_PAP,
    BtProfileAvrcp   = BTAPI_AVRCP,
    BtProfileBip     = BTAPI_BIP,
    BtProfileBpp     = BTAPI_BPP
    
} BtProfile;


typedef enum {
    BtSesNoSecurity                                     = BTAPI_NO_SECURITY,
    BtSesAuthentication                                 = BTAPI_AUTHENTICATION,
    BtSesAuthenticationEncryption                       = BTAPI_AUTHENTICATION_ENCRYPTION,
    BtSesAuthenticationAuthorization                    = BTAPI_AUTHENTICATION_AUTHORISATION,
    BtSesAuthenticationEncryptionAuthorization          = BTAPI_AUTHENTICATION_ENCRYPTION_AUTHORISATION,
    BtSesAlwaysAuthenticatedTrustedDevices              = BTAPI_ALWAYS_AUTHENTICATED_TRUSTED_DEVICES,
    BtSesAuthorizationAlwaysAuthenticatedTrustedDevices = BTAPI_AUTHORISATION_ALWAYS_AUTHENTICATED_TRUSTED_DEVICES,
    BtSesAuthorization                                  = BTAPI_AUTHORISATION
} BtSecuritySettings;

/*---------------------------------------------------------------------------*
 * Bluetooth general types                                                   *
 *---------------------------------------------------------------------------*/

/*****************************************************************************
 * GAP & SDAP definitions                                                    *
 *****************************************************************************

 *---------------------------------------------------------------------------*
 * GAP & SDAP constants                                                      *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * GAP & SDAP enums                                                          *
 *---------------------------------------------------------------------------*/


typedef enum  {
    BtCtBmscr = BTAPI_BT_HW_BMSCR,
    BtCtBmu = BTAPI_BT_HW_BMU
} BtChipType;


typedef enum {
    BtSsNotInitialized = BTAPI_STACK_NOT_INITIALIZED,
    BtSsInitialized = BTAPI_STACK_INITIALIZED,
    BtSsOn = BTAPI_STACK_ON,
    BtSsOff = BTAPI_STACK_OFF,
    BtSsError = BTAPI_STACK_ERROR,
    BtSsNoState
} BtStackState;


typedef enum {
    BtDmNonDiscoverable     = BTAPI_NON_DISCOVERABLE,
    BtDmGeneralDiscoverable = BTAPI_GENERAL_DISCOVERABLE,
    BtDmLimitedDiscoverable = BTAPI_LIMITED_DISCOVERABLE
} BtDiscoverableMode;


typedef enum {
    BtPmNonPairable = BTAPI_NON_PAIRABLE,
    BtPmPairable    = BTAPI_PAIRABLE
} BtPairableMode;


typedef enum {
    BtCmNonConnectable = BTAPI_NON_CONNECTABLE,
    BtCmConnectable    = BTAPI_CONNECTABLE
} BtConnectableMode;


typedef enum {
    BtIacGlobal = BTAPI_GIAC,
    BtIacLocal  = BTAPI_LIAC
} BtInquiryAccessCode;


typedef enum {
    BtDrNone                  = BTAPI_NO_RELATION,
    BtDrTrusted               = BTAPI_TRUSTED,
    BtDrConnected             = BTAPI_CONNECTED,
    BtDrTrustedAndConnected   = BTAPI_TRUSTED_AND_CONNECTED
} BtDeviceRelation;


typedef enum {
    BtUuid16  = BTAPI_UUID_16,
    BtUuid32  = BTAPI_UUID_32,
    BtUuid128 = BTAPI_UUID_128
} BtUuidType;


typedef enum {
    BtDetNil         = BTAPI_NIL,
    BtDetUint        = BTAPI_SDAP_UINT,
    BtDetSint        = BTAPI_SDAP_SINT,
    BtDetUuid        = BTAPI_SDAP_UUID,
    BtDetString      = BTAPI_SDAP_STRING,
    BtDetBool        = BTAPI_SDAP_BOOL,
    BtDetSequence    = BTAPI_SDAP_DATA_SEQ,
    BtDetEnumeration = BTAPI_SDAP_DATA_ALT,
    BtDetUrl         = BTAPI_SDAP_URL
} BtDataElementType;

/*---------------------------------------------------------------------------*
 * GAP & SDAP types                                                          *
 *---------------------------------------------------------------------------*/


typedef struct {
    BtChipType chip_type;
    UINT16 lm_fw_vers;
    UINT16 lc_fw_vers;
} BtChipBmscr;


typedef struct {
    BtChipType chip_type;
    UINT8 hw_platform;
    UINT8 hw_variant;
    UINT8 hw_revision;
    UINT8 fw_varinat;
    UINT8 fw_revision;
    UINT8 fw_build[3];
    UINT8 fw_patch;
} BtChipBmu;


typedef union {
    BtChipType chip_type;
    BtChipBmscr bmscr;
    BtChipBmu bmu;
} BtChipVersion;


typedef struct {
    UINT8      uuid[16];
    BtUuidType type;
} BtUUID;


typedef struct {
    union {
        UINT16 id;
        UINT16 range[2];
    }   attribute;
    BOOLEAN attribute_range;
} BtAttributeId;

#endif // Bt_Types_hpp

