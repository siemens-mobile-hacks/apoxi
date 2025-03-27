/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_PbConfig_hpp)
#define Mmi_PbConfig_hpp

#include <Phonebook/PbTypes.hpp>

//#define APOXI_SIM_ONLY

const INT c_max_name_len = 25;
const INT c_max_email_len = 30;
const INT c_max_pb_name_entries = 100;
const INT c_max_pb_number_entries = 200;
const WString c_empty_string = Tr(L"< empty >");

const INT c_max_phonenos = 2;

#endif  // Mmi_PbConfig_hpp
