/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_DbgDataDump_hpp)
#define Auxiliary_DbgDataDump_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>
#include <Auxiliary/WString.hpp>



class DbgDump
{
    public:
        static WString CreateHexCodes(const UINT8 * buffer, INT len);

#ifdef _DEBUG
        static void DbgOutHexAndAscii(INT code, const UINT8 * buffer, INT len);
#endif

};


#ifdef _DEBUG
    #define DBG_DUMP(params)    DbgDump::DbgOutHexAndAscii params
#else
    #define DBG_DUMP(params)
#endif


#endif // EOF


