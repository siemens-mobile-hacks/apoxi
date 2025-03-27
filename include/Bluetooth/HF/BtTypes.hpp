/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bt_Hf_Types_hpp)
#define Bt_Hf_Types_hpp

#include <stack/extensions.h>
#include <Kernel/Types.hpp>

/*****************************************************************************
 * Bluetooth HF definitions                                                  *
 *****************************************************************************

 *---------------------------------------------------------------------------*
 * Bluetooth HF constants                                                    *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * Bluetooth HF enums                                                        *
 *---------------------------------------------------------------------------*/

typedef enum{ 
    BtHfsNotConnected,
    BtHfsConnected,
    BtHfsAvailableForAudio,
    BtHfsAudioActive
} BtHfState;

typedef enum {
    BtHfCe
} BtHfCallEvent;

typedef enum {
    BtHfClNoCall,
    BtHfClCallOnPhone,
    BtHfClCallOnAccessory
} BtHfCallLocation;

/*---------------------------------------------------------------------------*
 * Bluetooth HF types                                                        *
 *---------------------------------------------------------------------------*/

#endif // Bt_Hf_Types_hpp

