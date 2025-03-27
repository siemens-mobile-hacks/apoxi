/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtUtil_hpp)
#define BtUtil_hpp

#include <stack/extensions.h>
#include <Bluetooth/BtTypes.hpp>

/*  ************************************************************************
    BTAPI -> APOXI conversion functions 
    ************************************************************************ */


BtResultCode ToResultCode(btapi_result_t result);


BtProfile ToProfile(btapi_profile_t profile);

/*  ************************************************************************
    UTF-8 utility functions
    ************************************************************************ */


BOOLEAN ConvertUtf8ToWString(const CHAR* utf_char_pointer, WString& w_string);

/*  ************************************************************************
    fuctions for dealing with BtXXX - structures
    ************************************************************************ */


void ExtendUuidTo128Bit(const BtUUID& uuid_base, BtUUID& uuid_128);


BOOLEAN operator==(const BtUUID& left_value, const BtUUID& right_value);


BOOLEAN operator!=(const BtUUID& left_value, const BtUUID& right_value);

#ifdef _DEBUG
/*  ************************************************************************
    Debugging functions
    ************************************************************************ */

/***
*/
const CHAR* BooleanAsString(BOOLEAN boolean);

/***
*/
const CHAR* BtapiResultTAsString(btapi_result_t result);

/***
*/
const CHAR* BtResultAsString(BtResultCode result);


const CHAR* BtRequestStateAsString(BtRequestState state);
#endif /* _DEBUG */

#endif


