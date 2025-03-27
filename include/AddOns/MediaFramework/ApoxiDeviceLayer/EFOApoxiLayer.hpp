/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EFOApoxiLayer_hpp)
#define EFOApoxiLayer_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal header file which should not be used by the MMI in a
    direct manner, and the interface may be changed in future releases.

*/

typedef enum
{
    kReadOnlyMode,
    kWriteOnlyMode,
    kReadAndWriteMode
} EFOFileOpenMode;

typedef enum 
{
    kBinDataType,
    kFileType,
    kDataSinkType,
    kObjectTypeCount    // Number of Stream Types supported.
} EFOFileStreamType;

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EFOApoxiLayer_hpp

