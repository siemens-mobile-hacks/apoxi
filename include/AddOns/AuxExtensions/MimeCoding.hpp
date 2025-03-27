/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifndef Apoxi_MimeCoding_hpp
#define Apoxi_MimeCoding_hpp

#include <Kernel/Types.hpp>

#define APOXI_MIME_LINE_WIDTH 76

class MimeCoding
{
    public:
        static INT EncodeQuotedPrintable(CHAR *buffer, INT buffer_length, const CHAR *data, INT data_length, BOOLEAN is_text);

        static INT DecodeQuotedPrintable(CHAR *buffer, INT buffer_length, const CHAR *data, INT data_length, BOOLEAN is_text);

        static INT EncodeBase64(CHAR *buffer, INT buffer_length, const CHAR *data, INT data_length, BOOLEAN is_text);

        static INT DecodeBase64(CHAR *buffer, INT buffer_length, const CHAR *data, INT data_length, BOOLEAN is_text);
};

class MimeCoder
{
    public:
        MimeCoder(CHAR *buffer = 0, INT buffer_length = 0, BOOLEAN is_text = TRUE);
        
        void Advance(INT amount);
        BOOLEAN Check(INT amount) const;
        BOOLEAN IsText() const { return m_is_text; }

    protected:
        CHAR *m_buffer_ptr;
        INT m_buffer_length;
        INT m_buffer_left;
        
        INT m_line_length;

        BOOLEAN m_is_text;
};

class QuotedPrintableCoder : public MimeCoder
{
    public:
        QuotedPrintableCoder(CHAR *buffer = 0, INT buffer_length = 0, BOOLEAN is_text = TRUE);
        
        BOOLEAN EncodePush(CHAR data, BOOLEAN last);
        BOOLEAN EncodeChar(CHAR data, BOOLEAN last, BOOLEAN coded = TRUE);
        INT EncodeEnd();
        
        BOOLEAN DecodePush(CHAR data);
        INT DecodeChar(CHAR data);
        INT DecodeEnd();
    private:
        CHAR m_pending;
};

class Base64Coder : public MimeCoder
{
    public:
        Base64Coder(CHAR *buffer = 0, INT buffer_length = 0, BOOLEAN is_text = TRUE);
        
        BOOLEAN EncodePush(CHAR data);
        INT EncodeEnd();

        BOOLEAN DecodePush6Bits(INT code);
        BOOLEAN DecodePush(CHAR data);
        INT DecodeEnd();
    private:

        UINT32 m_group;
        INT m_group_length;
};

#endif // Apoxi_MimeCoding_hpp


