/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bt_Constants_hpp)
#define Bt_Constants_hpp

/*---------------------------------------------------------------------------*
 * Constants for GAP & SDAP                                                  *
 *---------------------------------------------------------------------------*/

// BT...Bluetooth, MSC...Major Service Class
#define BT_MSC_SHIFT           13
#define BT_MSC_MASK            0x7FF
#define BT_MSC_POSITIONING     0x008
#define BT_MSC_NETWORK         0x010
#define BT_MSC_RENDERING       0x020
#define BT_MSC_CAPTURING       0x040
#define BT_MSC_OBJECT_TRANSFER 0x080
#define BT_MSC_AUDIO           0x100
#define BT_MSC_TELEPHONY       0x200
#define BT_MSC_INFORMATION     0x400

// BT...Bluetooth, MDC...Major Device Class
#define BT_MDC_SHIFT         8
#define BT_MDC_MASK          0x1F
#define BT_MDC_COMPUTER      0x01
#define BT_MDC_PHONE         0x02
#define BT_MDC_LAN           0x03
#define BT_MDC_AUDIO_VIDEO   0x04
#define BT_MDC_PERIPHERAL    0x05
#define BT_MDC_IMAGING       0x06
#define BT_MDC_UNCATEGORIZED 0x1F

// BT...Bluetooth, SDC...(Sub) minor Device Class
#define BT_SDC_SHIFT 2
#define BT_SDC_MASK  0x3F

// Minor Device Class for BT_MDC_COMPUTER
#define BT_SDC_DESKTOP_WORKSTATION   0x01
#define BT_SDC_SERVER_CLASS_COMPUTER 0x02
#define BT_SDC_LAPTOP                0x03
#define BT_SDC_HANDHELD_PC_PDA       0x04
#define BT_SDC_PALM_SIZED_PS_PDA     0x05
#define BT_SDC_WEARABLE_COMPUTER     0x06

// Minor Device Class for BT_MDC_PHONE
#define BT_SDC_CELLULAR                     0x01
#define BT_SDC_CORDLESS                     0x02
#define BT_SDC_SMART_PHONE                  0x03
#define BT_SDC_WIRED_MODEM_OR_VOICE_GATEWAY 0x04
#define BT_SDC_COMMON_ISDN_ACCESS           0x05

// Minor Device Class for BT_MDC_LAN
#define BT_SDC_01_TO_17_UTILIZED 0x08
#define BT_SDC_17_TO_33_UTILIZED 0x10
#define BT_SDC_33_TO_50_UTILIZED 0x18
#define BT_SDC_50_TO_67_UTILIZED 0x20
#define BT_SDC_67_TO_83_UTILIZED 0x28
#define BT_SDC_83_TO_99_UTILIZED 0x30
#define BT_SDC_NO_SERVICE        0x38

// Minor Device Class for BT_MDC_AUDIO_VIDEO
#define BT_SDC_HEADSET                       0x01
#define BT_SDC_HANDS_FREE                    0x02
#define BT_SDC_MICROPHONE                    0x04
#define BT_SDC_LOUDSPEAKER                   0x05
#define BT_SDC_HAEDPHONES                    0x06
#define BT_SDC_PORTABLE_AUDIO                0x07
#define BT_SDC_CAR_AUDIO                     0x08
#define BT_SDC_SET_TOP_BOX                   0x09
#define BT_SDC_HIFI_AUDIO                    0x0A
#define BT_SDC_VCR                           0x0B
#define BT_SDC_VIDEO_CAMERA                  0x0C
#define BT_SDC_CAMCORDER                     0x0D
#define BT_SDC_VIDEO_MONITOR                 0x0E
#define BT_SDC_VIDEO_DISPLAY_AND_LOUDSPEAKER 0x0F
#define BT_SDC_VIDEO_CONFERENCING            0x10
#define BT_SDC_GAMING_TOY                    0x12

// Minor Device Class for BT_MDC_PERIPHERAL
#define BT_SDC_KEYBOARD                       0x01
#define BT_SDC_POINTING_DEVICE                0x02
#define BT_SDC_COMBO_KEYBOARD_POINTING_DEVICE 0x03
#define BT_SDC_JOYSTICK                       0x04
#define BT_SDC_GAMEPAD                        0x08
#define BT_SDC_REMOTE_CONTROL                 0x0C
#define BT_SDC_SENSING_DEVICE                 0x10
#define BT_SDC_DIGITIZER_TABLET               0x14
#define BT_SDC_CARD_READER                    0x18

// Minor Device Class for BT_MDC_IMAGING
#define BT_SDC_DISPLAY 0x04
#define BT_SDC_CAMERA  0x08
#define BT_SDC_SCANNER 0x10
#define BT_SDC_PRINTER 0x20

#endif //Bt_Constants_hpp

