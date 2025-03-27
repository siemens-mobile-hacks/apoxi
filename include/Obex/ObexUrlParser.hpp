/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexUrlParser_hpp)
#define Apoxi_ObexUrlParser_hpp

#include "Auxiliary/String.hpp"
#include "Auxiliary/ByteBuffer.hpp"

#include "Obex/ObexResult.hpp"

class   ObexUrlStrParser {
    public:
        ObexUrlStrParser(const String &     url_str) :
            m_url_str(url_str),
            m_pos(0)
        {
        }

        ObexResult  ParseTarget(ByteBuffer &    out_val);

    protected:
        inline  BOOLEAN     IsAtEnd() const
        {
            return ( m_pos == - 1 );
        }

        BOOLEAN         StartSymbol(char                symbol);
        BOOLEAN         MatchSymbol(char                symbol);
        BOOLEAN         MatchString(const CHAR *        key_str);

        BOOLEAN         ScanAsciiString(ByteBuffer &    out_val);
        BOOLEAN         ScanOctetString(ByteBuffer &    out_val);

    private:
        ByteBuffer      m_buffer;
        const String &  m_url_str;
        INT             m_pos;
};

#endif  // Apoxi_ObexUrlParser_hpp


