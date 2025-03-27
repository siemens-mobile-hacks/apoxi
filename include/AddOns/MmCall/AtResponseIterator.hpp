/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AtResponseIterator_hpp)
#define Apoxi_AtResponseIterator_hpp

#include <AddOns/MmCall/AtCommand.hpp>
#include <AddOns/MmCall/AtResponse.hpp>

const INT c_it_buffer_size = 128;
const INT c_it_read_size = 1;

class AtResponseIterator 
{
    public:     
        AtResponseIterator(SerialTerminal* terminal);

        virtual ~AtResponseIterator();

        BOOLEAN HasMoreResponses();

        const AtResponse GetNextResponse();
        
    private:
        static AtResponse::ResponseType ParseResponseType(const String &at_response); 

        static void ParseResponse(const String &at_response, AtResponse& structured_response); 
        

        SerialTerminal* m_terminal;
        
        AtResponse m_current_response;
        
        BOOLEAN m_received_connect;
        
        CHAR m_response_buffer[c_it_buffer_size];
        
        UINT m_buffer_index;

        UINT m_next_response_index;

        BOOLEAN m_has_more_responses_called;
};

#endif /* Apoxi_AtResponseIterator_hpp */

