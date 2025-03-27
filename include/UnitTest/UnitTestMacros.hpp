/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(UnitTestMacros_hpp)
#define UnitTestMacros_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

/*  ------------------------------------------------------------------------
    System Settings
    ------------------------------------------------------------------------ */
#ifdef APOXI_TARGETSYSTEM_HOST
    #define APOXI_UNITTEST_PATH_SEPARATOR_CHAR '\\'
    #define APOXI_UNIT_MAX_ERROR_HARD_LIMIT 500
#else //APOXI_TARGETSYSTEM_HOST
    #define APOXI_UNITTEST_PATH_SEPARATOR_CHAR '/'
    #define APOXI_UNIT_MAX_ERROR_HARD_LIMIT 30
#endif 

/*  ------------------------------------------------------------------------
    Display Settings
    ------------------------------------------------------------------------ */
#define ASYNC_TEST_STATUS_TEXT_INTERVAL 500

#ifdef APOXI_UNITTEST_TCPIP
    #define APOXI_UNITTEST_HOST_IP_ADDR_FILE_NAME "/unit_test_properties"
    #define APOXI_UNITTEST_PROPERTIES_FILE_SIZE 15
#endif //APOXI_UNITTEST_TCPIP


/*  ------------------------------------------------------------------------
    Keyboard Configuration
    ------------------------------------------------------------------------ */
#define APOXI_UNIT_SHORTCUT_HELP 7
#define APOXI_UNIT_SHORTCUT_SELECT_ALL 1
#define APOXI_UNIT_SHORTCUT_SELECT_NONE 2
#define APOXI_UNIT_SHORTCUT_RUN_TESTS 3
#define APOXI_UNIT_SHORTCUT_CONNECT 9



/*  ------------------------------------------------------------------------
    Errors and Warnings, if compile settings do not match
    ------------------------------------------------------------------------ */
#ifdef APOXI_UNITTEST_MMI
    #ifdef APOXI_UNITTEST_NO_TESTNAMES
    #error APOXI_UNITTEST_NO_TESTNAMES may not be defined, when using APOXI_UNITTEST_MMI
    #endif //APOXI_UNITTEST_NO_TESTNAMES
#endif //APOXI_UNITTEST_MMI

#ifdef APOXI_UNITTEST_NO_FILENAMES
    #ifndef APOXI_UNITTEST_NO_MESSAGES
    #error APOXI_UNITTEST_NO_FILENAMES may not defined without defining APOXI_UNITTEST_NO_MESSAGES. First try to eliminate the messages to save memory, not the file names
    #endif //APOXI_UNITTEST_NO_MESSAGES
#endif //APOXI_UNITTEST_NO_FILENAMES

#ifdef APOXI_UNITTEST_TRACE
    #if !defined(APOXI_TRACE) & !defined(APOXI_TRACE_LEVEL_2) & !defined(APOXI_TRACE_LEVEL_3) | defined(APOXI_TRACE_DISABLED)
        #pragma message ("APOXI_UNITTEST_TRACE will not produce any output without enabling the APOXI_TRACE options")
    #endif //APOXI_UNITTEST_NO_MESSAGES
#endif //APOXI_UNITTEST_NO_FILENAMES

#if !defined(APOXI_TARGETSYSTEM_HOST) & defined(APOXI_UNITTEST_TRACE) & defined(APOXI_UNITTEST_TCPIP) 
    #pragma message ("APOXI_UNITTEST_TRACE and APOXI_UNITTEST_TCPIP will not properly work togehter on the target. you will not be able to use the TCP connection while using trace! you can disable trace-out using AT-commands")
#endif

#if !defined(APOXI_TARGETSYSTEM_HOST) & defined(APOXI_UNITTEST_TCPIP) & !defined(APPLICATION_DATACONN)
    #pragma message ("APOXI_UNITTEST_TCPIP will not work without the DataConn-Application on the target")
#endif



#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // UnitTestMacros_hpp

