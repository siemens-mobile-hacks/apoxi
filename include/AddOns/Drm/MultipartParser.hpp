/*  =============================================================================
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    =============================================================================

    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    =============================================================================*/

#if !defined(Apoxi_Multipart_Mime_hpp)
#define Apoxi_Multipart_Mime_hpp


/************************* #INCLUDES *************************/
#include <Auxiliary/BufferedData.hpp>
#include <Auxiliary/BinData.hpp>
#include <Kernel/Types.hpp>
#include <Auxiliary/String.hpp>
#include <Auxiliary/Vector.hpp>
/************************* DEBUGs *************************/

//#define MULTIPART_DEBUG

#ifdef MULTIPART_DEBUG
#include <stdio.h>
#define dprintf(x) printf x;
#else
#define dprintf(x)
#endif // MULTIPART_DEBUG

/************************** #DEFINES ****************************/
#define MULTIPART_LF '\n'
#define MULTIPART_CR '\r'
#define MULTIPART_TAB '\t'
#define MULTIPART_SPACE ' '
#define MULTIPART_COMMENT ';'
#define SKIP_SPACE(b, l) while(*b == MULTIPART_SPACE || *b == MULTIPART_TAB) { b++; l--; }

#define MULTIPART_SUCCESS                  0
#define MULTIPART_ERROR_UNKNOWN           -1
#define MULTIPART_ERROR_INVALID_START     -2
#define MULTIPART_ERROR_INVALID_END       -3
#define MULTIPART_ERROR_INVALID_BOUNDARY  -4
#define MULTIPART_ERROR_INVALID_INPUT     -5
#define MULTIPART_ERROR_INVALID_VALUE     -6
#define MULTIPART_ERROR_CONTENT_PARSING   -7
#define MULTIPART_ERROR_HEADER_PARSING    -8
#define MULTIPART_ERROR_NO_HEADER         -9
#define MULTIPART_ERROR_REACHED_EOF       -10
#define MULTIPART_ERROR_FILE_FORMAT       -11
#define MULTIPART_ERROR_NO_MEMORY         -12
#define MULTIPART_ERROR_VALUE_NOT_FOUND   -13

#define STR_CONTENT_TYPE     "Content-type"
#define STR_CONTENT_ENCODING "Content-Transfer-Encoding"
#define STR_CONTENT_ID       "Content-ID"
#define STR_DESCRIPTION      "Content-Description"
#define STR_DISPOSITION      "Content-Disposition"

/********************* Structure definations **********************/

typedef struct HeaderData
{
    String m_name;
    String m_value;
} HeaderData;

typedef struct MultiPartData
{
    INT m_bound_num;

    INT  m_content_offset;
    INT  m_content_len;

    Vector<HeaderData> m_header;

} MultiPartData;

class MultipartParser
{
    public:

        MultipartParser();
        ~MultipartParser();

        static INT  GetNumBoundaries(const BinData& msg);
        static INT  GetNumBoundaries(const String& msg);
        static INT  GetNumBoundaries(const CHAR* msg, INT len);

        static INT  Parse(const BinData& msg, INT bound_num, MultiPartData *data);
        static INT  Parse(const String& msg, INT bound_num, MultiPartData *data);
        static INT  Parse(const CHAR* msg, INT len, INT bound_num, MultiPartData *data);

        static INT GetIndexForValue(CHAR *header_name, MultiPartData *data);

    private:
        static INT ValidateEof(const CHAR *msg, INT len);
        static INT GetContentLength(const CHAR *msg, INT len, String boundary);
        static INT GetBoundaryName(const CHAR* msg, INT len, String &buf);
        static INT GetStringFromLine(const CHAR *msg, INT len, String& buf);
        static INT GetRawContentType(const CHAR *msg, INT len, String& buf);
        static INT GetContentId(const CHAR *msg, INT len, String& buf);
};

#endif

