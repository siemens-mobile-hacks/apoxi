/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AudioDef_hpp)
#define AudioDef_hpp

// If the #define AUD_DBG_OUT(x) DBG_OUT(x) is defined than all function 
// calls to the audio driver (see aud_drv.h) incl. the calling paramter are dumped.
#define AUD_DBG_OUT(x) DBG_OUT(x)
// #define AUD_DBG_OUT(x)
#define AUD_DBG_NR  (0)

#endif // #define AudioDef_hpp

