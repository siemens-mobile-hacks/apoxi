/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bt_Obex_Types_hpp)
#define Bt_Obex_Types_hpp

#include <stack/extensions.h>
#include <Kernel/Types.hpp>

/*****************************************************************************
 * Bluetooth OBEX definitions                                                *
 *****************************************************************************

 *---------------------------------------------------------------------------*
 * Bluetooth OBEX constants                                                  *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * Bluetooth OBEX enums                                                      *
 *---------------------------------------------------------------------------*/


typedef enum {
    BtOocConnect = BTAPI_GOEP_CONNECT,
    BtOocSetPath = BTAPI_GOEP_SETPATH,
    BtOocGet = BTAPI_GOEP_GET,
    BtOocPut = BTAPI_GOEP_PUT,
    BtOocAbort = BTAPI_GOEP_ABORT,
    BtOocDisconnect = BTAPI_GOEP_DISCONNECT
} BtObexOperationCode;


typedef enum {
    BtOecHandleUnknown = ObexHandleUnknown,
    BtOecOperationNotAllowed = ObexOperationNotAllowed,
    BtOecBusy = ObexBusy,
    BtOecNotConnected = ObexNotConnected,
    BtOecConnected = ObexConnected
} BtObexErrorCode;


typedef enum
{
    BtOhtUnicodeString = 0x00,
    BtOhtByteSequence  = 0x40,
    BtOhtByteValue     = 0x80,
    BtOhtDWordValue    = 0xC0
} BtObexHeaderType;

/*---------------------------------------------------------------------------*
 * Bluetooth OBEX types                                                      *
 *---------------------------------------------------------------------------*/

typedef struct {
    union {
        struct {
            const UINT8*  buffer;
            UINT16        size;
        }                 byte_sequence;
        struct {
            const UINT16* buffer;
            UINT16        size;
        }                 unicode_string;
        UINT8             byte_value;
        UINT32            dword_value;
    }                     value;
    BtObexHeaderType      header_type;
    UINT8                 header_id;
} BtObexHeader;

#endif // Bt_Obex_Types_hpp


