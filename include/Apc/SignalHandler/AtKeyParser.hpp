/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if !defined(Apc_SignalHandler_AtKeyParser_hpp)
#define Apc_SignalHandler_AtKeyParser_hpp

#include <Apc/SignalHandler/KeyMsgGenerator.hpp>

class AtKeyParser 
{
    public:
        AtKeyParser(INT length, UINT8 * key_string, INT time, INT pause);

        ~AtKeyParser();

        BOOLEAN GetFirstKey(KeyMsgGenerator::Key & key);

        BOOLEAN GetNextKey(KeyMsgGenerator::Key & key);
        

    private:
        BOOLEAN GetKey(KeyMsgGenerator::Key & key);

        INT     m_length;
        UINT8 * m_key_string;
        INT     m_time;
        INT     m_pause;
        INT     m_str_idx;

};

void TestAtKeyParser();

#endif


