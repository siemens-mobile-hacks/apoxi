/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bt_Hs_Types_hpp)
#define Bt_Hs_Types_hpp

#include <stack/extensions.h>
#include <Kernel/Types.hpp>

/*****************************************************************************
 * Bluetooth HS definitions                                                  *
 *****************************************************************************

 *---------------------------------------------------------------------------*
 * Bluetooth HS constants                                                    *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * Bluetooth HS enums                                                        *
 *---------------------------------------------------------------------------*/


typedef enum {
    BtHssNotConnected,
    BtHssConnected,
    BtHssAvailableForAudio,
    BtHssAudioActive
} BtHsState;

typedef enum {
    BtHsCeCallOnPhone,
    BtHsCeCallOnHeadset,
    BtHsCeHangUp,
    BtHsCeCallRelease
} BtHsCallEvent;

typedef enum {
    BtHsClNoCall,
    BtHsClCallOnPhone,
    BtHsClCallOnAccessory
} BtHsCallLocation;

/*---------------------------------------------------------------------------*
 * Bluetooth HS types                                                        *
 *---------------------------------------------------------------------------*/

#endif // Bt_Hs_Types_hpp

