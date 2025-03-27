/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexConfig_hpp)
#define Apoxi_ObexConfig_hpp


//#define   APOXI_OBEX_DBG_OUT  36001   // OBEX  36000 - 36010
#define APOXI_OBEX_DBG_OUT  40222
#define APOXI_OBEX_OPP_DBG  36002
#define APOXI_OBEX_FTP_DBG  36003

#ifndef APOXI_OBEX_MAX_NO_TRANSPORTS
    #define APOXI_OBEX_MAX_NO_TRANSPORTS  3
#endif

#ifndef APOXI_OBEX_MAX_NO_SELECTIONS
    #define APOXI_OBEX_MAX_NO_SELECTIONS  2
#endif


/* Sanity checks for definitions - please don't 'customize' them, it will
 * break your code !
 */
#if (APOXI_OBEX_MAX_NO_TRANSPORTS < 1)
    #error "APOXI_OBEX_MAX_NO_TRANSPORTS must be >= 1 when OBEX is used."
#endif

#if (APOXI_OBEX_MAX_NO_SELECTIONS < 1)
    #error "APOXI_OBEX_MAX_NO_SELECTIONS must be >= 1 when OBEX is used."
#endif

#endif  // Apoxi_ObexConfig_hpp

