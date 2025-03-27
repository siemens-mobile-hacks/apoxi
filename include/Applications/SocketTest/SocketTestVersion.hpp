/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(SocketTestVersion_hpp)
#define SocketTestVersion_hpp


/*
SocketTestVersion.hpp contains the official Uib Version which should be used in the
different <Module>Version.cpp files as long as those Modules are not versioned and
released separately
*/
#define SOCKETVERSION "2.10.0_TIV_04"

// Add for Version
extern "C" unsigned char get_sw_version();
// Add for AT Command Version
extern "C" UINT8 get_sw_version_text(char *ver_text, UINT8 max_len);

#endif  // SocketTestVersion_hpp
