 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if ! defined(BtAvrcpCommandInterface_hpp)
#define BtAvrcpCommandInterface_hpp

/*  AvrcpCommand mandatory and optional commands for Category 1. */
enum AvrcpCommand {
    ACKey0,
    ACKey1,
    ACKey2,
    ACKey3,
    ACKey4,
    ACKey5,
    ACKey6,
    ACKey7,
    ACKey8,
    ACKey9,
    ACDot,
    ACEnter,
    ACClear,
    ACSoundSelect,
    ACInputSelect,
    ACDisplayInformation,
    ACHelp,
    ACPower,
    ACPlay,
    ACStop,
    ACPause,
    ACRecord,
    ACRewind,
    ACFastForward,
    ACEject,
    ACForward,
    ACBackward,
    ACAngle,
    ACSubpicture,
    ACF1,
    ACF2,
    ACF3,
    ACF4,
    ACF5,
    ACNotDefined
};

/*  AvrcpResponse will be returned by media player plugin as a return value to the function call OnAvrcpCommand(). */
enum AvrcpResponse {
    ARNotImplemented,
    ARAccepted,
    ARRejected,
    ARInTransition,
    ARImplementedStable,
    ARResponseChanged,
    ARInterim
};

/*
    BtAvrcpCommandInterface defines the virtual functions that are to be implemented by
    Media App Plugins. Mmi panel application invokes these functions using the
    reference passed through the service interface AvrcpPanelService::RegsiterAvrcpApp().
*/
class BtAvrcpCommandInterface {

    public:

        virtual AvrcpResponse OnAvrcpCommand (AvrcpCommand cmd) const = 0;
};

#endif //#define BtAvrcpCommandInterface_hpp

