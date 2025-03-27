/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_InputStream_hpp)
#define Apoxi_InputStream_hpp

#include <Kernel/Types.hpp>

#ifndef APOXI_NOSTREAMING

class InputStream{
    public:
        InputStream();

        virtual ~InputStream();

        virtual INT Read(BYTE& data) = 0;

        virtual INT Read(BYTE* data, INT len);

        virtual INT Read(BYTE* data, INT offset, INT len);

        virtual InputStream& operator >> (char& c);

        virtual InputStream& operator >> (unsigned char& c);

        virtual InputStream& operator >> (signed char& c);

        virtual InputStream& operator >> (char* s);

        virtual InputStream& operator >> (unsigned char* s);

        virtual InputStream& operator >> (signed char* s);

        virtual InputStream& operator >> (const wchar_t* w);

        #if defined(APOXI_RTOS_NUC16) | defined(APOXI_RTOS_SIM166)

        virtual InputStream& operator >> (const WCHAR& w);
        #endif

        virtual InputStream& operator >> (short& n);

        virtual InputStream& operator >> (unsigned short& n);

        virtual InputStream& operator >> (int& n);

        virtual InputStream& operator >> (unsigned int& n);

        virtual InputStream& operator >> (long& n);

        virtual InputStream& operator >> (unsigned long& n);

        virtual UINT32 Available() = 0;
};

#endif

#endif // Apoxi_InputStream_hpp


