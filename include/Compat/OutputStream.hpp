/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_OutputStream_hpp)
#define Apoxi_OutputStream_hpp

#include <Kernel/Types.hpp>

#ifndef APOXI_NOSTREAMING

class OutputStream{
    public:
        OutputStream();
        virtual ~OutputStream();

        // output
        virtual INT Write (const BYTE data) = 0;
        virtual INT Write (const BYTE* data, INT len);
        virtual INT Write (const BYTE* data, INT offset, INT len);

        virtual OutputStream& operator << (const char c);
        virtual OutputStream& operator << (const unsigned char c);
        virtual OutputStream& operator << (const signed char c);

        virtual OutputStream& operator << (const char* s);
        virtual OutputStream& operator << (const unsigned char* s);
        virtual OutputStream& operator << (const signed char* s);

        virtual OutputStream& operator << (const wchar_t* w);

        virtual OutputStream& operator << (const short n);
        virtual OutputStream& operator << (const unsigned short n);

        virtual OutputStream& operator << (const int n);
        virtual OutputStream& operator << (const unsigned int n);

        virtual OutputStream& operator << (const long n);
        virtual OutputStream& operator << (const unsigned long n);

        virtual void Flush();
};

#endif

#endif // Apoxi_OutputStream_hpp


