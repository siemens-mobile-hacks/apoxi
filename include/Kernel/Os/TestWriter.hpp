/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestWriter_hpp)
#define Apoxi_TestWriter_hpp
#include <Kernel/Types.hpp>

#ifdef APOXI_TESTING

#define WRITESTATE(eventId, value) TestWriter::WriteState (eventId, value)

/* macro used for state output, can be switched on/off by defining/undefining APOXI_TESTING */
#define WRITE_STATE(args) TestWriter::WriteState args

#define WRITE_MSG(byte, bit) if ((TestWriter::array[byte] & (1 << bit)) == 0) TestWriter::array[byte] = TestWriter::array[byte] | (1 << bit);

#else

#define WRITESTATE(eventId, value)

#define WRITE_STATE(args)

#endif

class TestWriter {
    public:
        static void WriteState(UINT16 eventId, const CHAR* value= "", ...);

        static void WriteState(UINT16 eventId, const WCHAR* value = L"", ...);
        
        static void WriteCoverageBuffer();

     enum { WINDOW_OPENED_MSG = 11,
            WINDOW_CLOSED_MSG = 12,
            MENU_OPENED_MSG = 13,
            MENU_CLOSED_MSG = 14,
            MENU_ACTIVATED_MSG = 15,
            MENU_CHANGED_MSG = 16,
            SOFTKEY_SHOW_MSG = 17,
            SOFTKEY_PRESSED_MSG = 18,
            PIC_OUTPUT_MSG = 19,
            TEXT_OUTPUT_MSG = 20,
            MESSAGE_SENT_MSG = 21,
            MESSAGE_RECEIVED_MSG = 22,
            ACTION_EXECUTED_MSG = 23,
            VARIABLE_CHANGED_MSG = 24,
            APP_LOAD_MSG = 25,
            APP_EXIT_MSG = 26,
            METHOD_CALLED_MSG = 27,
            KEY_RECEIVED_MSG = 28,
                ANIM_OUTPUT_MSG = 29,
                ITEM_SELECTED_MSG = 30,
                ITEM_COUNT_MSG = 31,
                RADIO_SELECTED_MSG = 32,
                RADIO_ACTIVE_MSG = 33,
                CHECKBOX_ACTIVE_MSG = 34,
                CHECKBOX_SELECTED_MSG = 35,
                ACTION_DISABLED_MSG = 36
    };

    static CHAR array[];
}; // TestWriter
#endif

