/*  ------------------------------------------------------------------------
    Copyright (C) 2003 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IrdaTypes_hpp)
#define Apoxi_IrdaTypes_hpp

/* IrLMP Service Hints */
#define APOXI_IRDA_HINT_PNP                 0x01
#define APOXI_IRDA_HINT_PDA                 0x02
#define APOXI_IRDA_HINT_COMPUTER            0x04
#define APOXI_IRDA_HINT_PRINTER             0x08
#define APOXI_IRDA_HINT_MODEM               0x10
#define APOXI_IRDA_HINT_FAX                 0x20
#define APOXI_IRDA_HINT_LAN                 0x40
#define APOXI_IRDA_HINT_EXT                 0x80

#define APOXI_IRDA_OFFSET_HINT_PNP          0
#define APOXI_IRDA_OFFSET_HINT_PDA          0
#define APOXI_IRDA_OFFSET_HINT_COMPUTER     0
#define APOXI_IRDA_OFFSET_HINT_PRINTER      0
#define APOXI_IRDA_OFFSET_HINT_MODEM        0
#define APOXI_IRDA_OFFSET_HINT_FAX          0
#define APOXI_IRDA_OFFSET_HINT_LAN          0

#define APOXI_IRDA_HINT_TELEPHONY           0x01
#define APOXI_IRDA_HINT_FILE                0x02
#define APOXI_IRDA_HINT_IRCOMM              0x04
#define APOXI_IRDA_HINT_MESSAGE             0x08
#define APOXI_IRDA_HINT_HTTP                0x10
#define APOXI_IRDA_HINT_OBEX                0x20

#define APOXI_IRDA_OFFSET_HINT_TELEPHONY    1
#define APOXI_IRDA_OFFSET_HINT_FILE         1
#define APOXI_IRDA_OFFSET_HINT_IRCOMM       1
#define APOXI_IRDA_OFFSET_HINT_MESSAGE      1
#define APOXI_IRDA_OFFSET_HINT_HTTP         1
#define APOXI_IRDA_OFFSET_HINT_OBEX         1

/* IrLMP Character Code Values */
#define APOXI_IRDA_CHAR_SET_CODE_ASCII        0
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_1   1
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_2   2
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_3   3
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_4   4
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_5   5
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_6   6
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_7   7
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_8   8
#define APOXI_IRDA_CHAR_SET_CODE_ISO_8859_9   9
#define APOXI_IRDA_CHAR_SET_CODE_UNICODE    255

#endif  // Apoxi_IrdaTypes_hpp


