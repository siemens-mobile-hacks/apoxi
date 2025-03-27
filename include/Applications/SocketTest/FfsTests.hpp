/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTests_hpp)
#define ApoxiApp_FfsTests_hpp

#include <Adc/FlsFile.hpp>
#include <SocketTest/FfsTestError.hpp>
#include <SocketTest/FfsTestBase.hpp>

class FfsTests
{
    public:
        FfsTests();
        virtual ~FfsTests();

        UINT32 FfsTest_T1();
        UINT32 FfsTest_T2();
        UINT32 FfsTest_T3();
        UINT32 FfsTest_T4();
        UINT32 FfsTest_T5();
        UINT32 FfsTest_T6();

    private:
        FlsFile m_file;
        UINT32 m_req_filesize;

        UINT32 OpenTestFile(const CHAR *a_file_name);
};

#endif // ApoxiApp_FfsTests_hpp
