/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpTypes_hpp)
#define BtAvrcpTypes_hpp

#include <stack/extensions.h>


/*  ------------------------------------------------------------------------
    Enums
    ------------------------------------------------------------------------ */

enum BtAvrcpCommand {
    BtAcConnect,
    BtAcDisconnect,
    BtAcNotCongested
};

// Roles defined in AVRCP
enum BtAvrcpRole {
    BtAroleController   = BTAPI_AVRCP_CONTROLLER,
    BtAroleTarget       = BTAPI_AVRCP_TARGET
};

enum BtAvrcpCategory {
    BtAcCategory1       =   BTAPI_AVRCP_CATEGORY_1,
    BtAcCategory2       =   BTAPI_AVRCP_CATEGORY_2,
    BtAcCategory3       =   BTAPI_AVRCP_CATEGORY_3,
    BtAcCategory4       =   BTAPI_AVRCP_CATEGORY_4
};

enum BtAvrcpStateFlag {
    BtAsfButtonPress   = BTAPI_AVRCP_BUTTON_PRESS,
    BtAsfButtonRelease = BTAPI_AVRCP_BUTTON_RELEASE
};

enum BtAvrcpResponseType {
    BtArNotImplemented    = BTAPI_AVRCP_RESPONSE_NOT_IMPLEMENTED,
    BtArAccepted          = BTAPI_AVRCP_RESPONSE_ACCEPTED,
    BtArRejected          = BTAPI_AVRCP_RESPONSE_REJECTED,
    BtArInTransition      = BTAPI_AVRCP_RESPONSE_IN_TRANSITION,
    BtArImplementedStable = BTAPI_AVRCP_RESPONSE_IMPLEMENTED_STABLE,
    BtArResponseChanged   = BTAPI_AVRCP_RESPONSE_CHANGED,
    BtArInterim           = BTAPI_AVRCP_RESPONSE_INTERIM,
    BtArNotDefined        = 99
};

enum BtAvrcpOperation {
    BtAoSelect        = BTAPI_AVRCP_OP_SELECT,
    BtAoUp            = BTAPI_AVRCP_OP_UP,
    BtAoDown          = BTAPI_AVRCP_OP_DOWN,
    BtAoLeft          = BTAPI_AVRCP_OP_LEFT,
    BtAoRight         = BTAPI_AVRCP_OP_RIGHT,
    BtAoRightUp       = BTAPI_AVRCP_OP_RIGHT_UP,
    BtAoRightDown     = BTAPI_AVRCP_OP_RIGHT_DOWN,
    BtAoLeftUp        = BTAPI_AVRCP_OP_LEFT_UP,
    BtApLeftDown      = BTAPI_AVRCP_OP_LEFT_DOWN,
    BtAoRootMenu      = BTAPI_AVRCP_OP_ROOT_MENU,
    BtAoSetupMenu     = BTAPI_AVRCP_OP_SETUP_MENU,
    BtAoContentsMenu  = BTAPI_AVRCP_OP_CONTENTS_MENU,
    BtAoFavouriteMenu = BTAPI_AVRCP_OP_FAVORITE_MENU,
    BtAoExit          = BTAPI_AVRCP_OP_EXIT,
    BtAo0             = BTAPI_AVRCP_OP_0,
    BtAo1             = BTAPI_AVRCP_OP_1,
    BtAo2             = BTAPI_AVRCP_OP_2,
    BtAo3             = BTAPI_AVRCP_OP_3,
    BtAo4             = BTAPI_AVRCP_OP_4,
    BtAo5             = BTAPI_AVRCP_OP_5,
    BtAo6             = BTAPI_AVRCP_OP_6,
    BtAo7             = BTAPI_AVRCP_OP_7,
    BtAo8             = BTAPI_AVRCP_OP_8,
    BtAo9             = BTAPI_AVRCP_OP_9,
    BtAoDot           = BTAPI_AVRCP_OP_DOT,
    BtAoEnter         = BTAPI_AVRCP_OP_ENTER,
    BtAoClear         = BTAPI_AVRCP_OP_CLEAR,
    BtAoChannelUp     = BTAPI_AVRCP_OP_CHANNEL_UP,
    BtAoChannelDown   = BTAPI_AVRCP_OP_CHANNEL_DOWN,
    BtAoPrevChannel   = BTAPI_AVRCP_OP_PREVIOUS_CHANNEL,
    BtAoSoundSelect   = BTAPI_AVRCP_OP_SOUND_SELECT,
    BtAoInputSelect   = BTAPI_AVRCP_OP_INPUT_SELECT,
    BtAoDisplayInfo   = BTAPI_AVRCP_OP_DISPLAY_INFORMATION,
    BtAoHelp          = BTAPI_AVRCP_OP_HELP,
    BtAoPageUp        = BTAPI_AVRCP_OP_PAGE_UP,
    BtAoPageDown      = BTAPI_AVRCP_OP_PAGE_DOWN,
    BtAoPower         = BTAPI_AVRCP_OP_POWER,
    BtAoVolumeUp      = BTAPI_AVRCP_OP_VOLUME_UP,
    BtAoVolumeDown    = BTAPI_AVRCP_OP_VOLUME_DOWN,
    BtAoMute          = BTAPI_AVRCP_OP_MUTE,
    BtAoPlay          = BTAPI_AVRCP_OP_PLAY,
    BtAoStop          = BTAPI_AVRCP_OP_STOP,
    BtAoPause         = BTAPI_AVRCP_OP_PAUSE,
    BtAoRecord        = BTAPI_AVRCP_OP_RECORD,
    BtAoRewind        = BTAPI_AVRCP_OP_REWIND,
    BtAoFastForward   = BTAPI_AVRCP_OP_FAST_FORWARD,
    BtAoEject         = BTAPI_AVRCP_OP_EJECT,
    BtAoForward       = BTAPI_AVRCP_OP_FORWARD,
    BtAoBackward      = BTAPI_AVRCP_OP_BACKWARD,
    BtAoAngle         = BTAPI_AVRCP_OP_ANGLE,
    BtAoSubpicture    = BTAPI_AVRCP_OP_SUBPICTURE,
    BtAoF1            = BTAPI_AVRCP_OP_F1,
    BtAoF2            = BTAPI_AVRCP_OP_F2,
    BtAoF3            = BTAPI_AVRCP_OP_F3,
    BtAoF4            = BTAPI_AVRCP_OP_F4,
    BtAoF5            = BTAPI_AVRCP_OP_F5,
    BaAoVendorUnique  = BTAPI_AVRCP_OP_VENDOR_UNIQUE,
    BtAoNotDefined    = BTAPI_AVRCP_OPERATION_NOT_DEFINED
}; 

enum BtAvrcpControlType {
    BtActControl         = BTAPI_AVRCP_CTYPE_CONTROL,
    BtActStatus          = BTAPI_AVRCP_CTYPE_STATUS,
    BtActSpecificInquiry = BTAPI_AVRCP_CTYPE_SPECIFIC_INQUIRY,
    BtActNotify          = BTAPI_AVRCP_CTYPE_NOTIFY,
    BtActGeneralInquiry  = BTAPI_AVRCP_CTYPE_GENERAL_INQUIRY
};

enum BtAvrcpSubunitType {
    BtAstMonitor       = BTAPI_AVRCP_SUBUNIT_MONITOR,
    BtAstAudio         = BTAPI_AVRCP_SUBUNIT_AUDIO,
    BtAstPrinter       = BTAPI_AVRCP_SUBUNIT_PRINTER,
    BtAstDisc          = BTAPI_AVRCP_SUBUNIT_DISC,
    BtAstTapeRecPlayer = BTAPI_AVRCP_SUBUNIT_TAPE_RECORDER_PLAYER,
    BtAstTuner         = BTAPI_AVRCP_SUBUNIT_TUNER,
    BtAstCa            = BTAPI_AVRCP_SUBUNIT_CA,
    BtAstCamera        = BTAPI_AVRCP_SUBUNIT_CAMERA,
    BtAstPanel         = BTAPI_AVRCP_SUBUNIT_PANEL,
    BtAstBulletinBoard = BTAPI_AVRCP_SUBUNIT_BULLETIN_BOARD,
    BtAstCameraStorage = BTAPI_AVRCP_SUBUNIT_CAMERA_STORAGE,
    BtAstVendorUnique  = BTAPI_AVRCP_SUBUNIT_VENDOR_UNIQUE,
    BtAstUnit          = BTAPI_AVRCP_SUBUNIT_UNIT
};

enum BtAvrcpOpcode {
    BtAocUnitInfo         = BTAPI_AVRCP_OPCODE_UNIT_INFO,
    BtAocSubunitInfo      = BTAPI_AVRCP_OPCODE_SUBUNIT_INFO,
    BtAocVendorDependent  = BTAPI_AVRCP_OPCODE_VENDOR_DEPENDENT,
    BtAocPanelPassThrough = BTAPI_AVRCP_OPCODE_PANEL_PASS_THROUGH   
};

/*  ------------------------------------------------------------------------
    Structures
    ------------------------------------------------------------------------ */

typedef struct {
    BtAvrcpSubunitType m_subunit_type;
    UINT8              m_max_subunit_id;
} BtAvrcpSubunitInfoEntry;

#endif // BtAvrcpTypes_hpp

