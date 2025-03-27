/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(_MmiSimProtocol_h)
#define _MmiSimProtocol_h

/*----------------------------------------------------------------
                            Constants
  ----------------------------------------------------------------*/

#define MMISIM_MASK_NONE        0x00000000
#define MMISIM_MASK_SHIFT       0x00000001
#define MMISIM_MASK_ALT         0x00000002
#define MMISIM_MASK_CTRL        0x00000004

#define MMISIM_PORT             5555
#define MMISIM_PORT_RANGE       10
#define MMISIM_LOCALHOST        "localhost"

#define MMISIM_ENV_VAR_HOST     "MMISIM_HOST"
#define MMISIM_ENV_VAR_PORT     "MMISIM_PORT"
#define MMISIM_ENV_VAR_DISABLE  "MMISIM_DISABLE"

enum MmiSimMsgId {
    MmiSimDisplayUpdateHeaderId = 1,
    MmiSimDisplayUpdateDataId = 2,
    MmiSimBacklightStateId = 10,
    MmiSimVibrationStateId = 11,
    MmiSimLedStateId = 12,
    MmiSimKeyDownId = 200,
    MmiSimKeyUpId = 201,
    MmiSimCharId = 220,
    MmiSimPenDownId = 250,
    MmiSimPenUpId = 251,
    MmiSimPenMoveId = 252
};

/*  Each data transfer between MmiSim and simulation environment is a sequence of MmiSimMsgs and 
    an optional data buffer, whose length is typically defined by one of the MmiSimMsg's MmiSimMsgArgs.<br />
    <br />
    Example 1: A DisplayUpdate Notification looks like this:
    <pre>
    |------------------------------------------------------------------------------------------------------------------------------|
    | MmiSimMsg                                                                                                                    |
    |------------------------------------------------------------------------------------------------------------------------------|
    | id                    | args[0].t_xydim[0] | args[0].t_xydim[1] | args[1].t_xydim[0] | args[1].t_xydim[1] | args[2].t_uint32 |
    |------------------------------------------------------------------------------------------------------------------------------|
    | DisplayUpdateHeaderId | r_blit_left        | r_blit_top         | r_blit_right       | r_blit_bottom      | data_count       |
    |------------------------------------------------------------------------------------------------------------------------------|

    Followed by [data_count] times (in case once we want to support a list of several independent blit rectangles):
    |-----------------------------------------------------------| |------| .....
    | MmiSimMsg                                                 | | Data | .....
    |-----------------------------------------------------------| |------| .....
    | id                  | args[0].t_uint32 | args[1].t_uint32 | | .... | .....
    |-----------------------------------------------------------| |------| .....
    | DisplayUpdateDataId | data_len         | data_offset      | | .... | .....
    |-----------------------------------------------------------| |------| .....
    </pre>
    <br />
    Example 2: A BackLight Notification looks like this:

    <pre>
    |--------------------------------|
    | MmiSimMsg                      |
    |--------------------------------|
    | id          | args[0].t_uint32 |
    |--------------------------------|
    | BackLightId | backlight_state  |
    |--------------------------------|
    </pre>
    <br>
    This the format for switching the vibration device on and off:
    
    <pre>
    |-------------------------------------------|
    | MmiSimMsg                                 |
    |-------------------------------------------|
    | id                     | args[0].t_uint32 |
    |-------------------------------------------|
    | MmiSimVibrationStateId |vibration_state   |
    |-------------------------------------------|
    </pre>
    <br>
    To handle the LED this message format should be used:
    
    <pre>
    |------------------------------------------------------------|
    | MmiSimMsg                                                  |
    |------------------------------------------------------------|
    | id               | args[0].t_uint32     | args[1].t_uint32 |
    |------------------------------------------------------------|
    | MmiSimLedStateId | led_state (on / off) | led color (rgb)  |
    |------------------------------------------------------------|
    </pre>
*/

typedef union {
    char t_char[4];
    unsigned char t_uchar[4];
    unsigned char t_byte[4];
    char t_int8[4];
    unsigned short t_wchar[2];
    short t_int16[2];
    unsigned short t_uint[2];
    short t_xydim[2];
    int t_int32;
    unsigned int t_uint32;
    int t_int;
    void* t_void;
} MmiSimMsgArg;

// todo: id should be of type MmiSimMsgId. This change must be done synchronously for MmiSim and Apoxi, in order not to break compatibility.
typedef struct {
    short id;
    MmiSimMsgArg args[4];
} MmiSimMsg;

#endif  // _MmiSimProtocol_h


