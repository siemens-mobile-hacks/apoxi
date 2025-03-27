/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestRunner_hpp)
#define Apoxi_UnitTestRunner_hpp

#include "UnitTest.hpp"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

class UnitTestRunner {

private:
    UnitTestRunner();
    virtual ~UnitTestRunner();

public:
    static void Run(UnitTestHandle test_hdl, UnitTestResult& test_result);

    static void Run(UnitTestHandle test_hdl, UnitTestResult& test_result, UINT8 repetitions);

    

};
#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestRunner_hpp


