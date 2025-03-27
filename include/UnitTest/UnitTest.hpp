/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTest_hpp)
#define Apoxi_UnitTest_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST
#include "UnitTestResult.hpp"

/*  ------------------------------------------------------------------------
    GET_UNITTEST_HANDLE
    ------------------------------------------------------------------------ */
#define GET_UNITTEST_HANDLE(TestClass)  TestClass::CreateInstance
// GET_UNITTEST_HANDLE

class UnitTest {

public:
    UnitTest() {};
    virtual ~UnitTest() {};

    BOOLEAN Run(UnitTestResult& test_result) { return _Execute(test_result); }
  
    
protected:
    
    

    virtual BOOLEAN _Execute(UnitTestResult& test_result) = 0;
    
    BOOLEAN m_track_errors;
    
    BOOLEAN m_error_occured;

}; // UnitTest

typedef UnitTest* (*UnitTestHandle)();


#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTest_hpp

