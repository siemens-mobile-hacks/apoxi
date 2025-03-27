/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpResponse_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpResponse_hpp

#include <AddOns/AfsRam/RamDataSink.hpp>

// Defines the format of the contained headers.
typedef Vector<String> HttpResponseHeaders;

class HttpResponse;

class HttpResponse
{
    public:
        HttpResponse();

        String GetStatusLine();

        void SetStatusLine(String line);

        HttpResponseHeaders GetHeaders();

        FilePtr GetFile();

        void SetFile(FilePtr file);

        RamDataSinkPtr GetBody();

        virtual ~HttpResponse();

        BOOLEAN Append(HUGE void* data, UINT length);

        BOOLEAN Append(String textStr);

        BOOLEAN AppendHeader(String headerStr);

    protected:
        // the status line
        String m_statusLine;
        // vector of response headers to send
        HttpResponseHeaders m_headers;
        // eventually file used for response
        FilePtr m_file;
        // body data to send
        RamDataSinkPtr m_body;
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpResponse_hpp

