/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Adc_Types_hpp)
#define Adc_Types_hpp

/*  ========================================================================
    DataControlType
    ======================================================================== */

enum DataControlType
{   
    SimAdnPhonebook,
    SimFdnPhonebook,
    SimMsisdnPhonebook,
    SimLndPhonebook,
    SimCphsMBoxPhonebook,
    SimCphsInfoNoPhonebook,
    SimSdnPhonebook,
    SimBdnPhonebook,
    SimMbdnPhonebook,
    SimSmsParameters,
    SimSms,
    SimPreferedLanguages,
    SimPreferedExtLanguages,
    SimPreferedPlmns,
    SimPuct,
    SimAcm,
    SimAcmMax,
    SimSst,
    SimImsi,
    SimSpn,
    SimEcc,
    SimCphsInfo,
    SimCphsOpName,
    SimCphsOpShortName,
    SimCphsCsp,
    SimCbmi,
    SimCbmiRange,
    SimCcp,
    UsimPhonebook,
    DynamicAlsFlags,
    SimAll
};
    
    
/*  ========================================================================
    BootNotification
    ======================================================================== */

enum BootNotification
{   
    BootNoRequest,
    BootFinishedNotification,
    BootLoadNotification,
    BootNotAvailable,
};


#endif  // Asc_Types_hpp


