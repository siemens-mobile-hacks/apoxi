/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestData_hpp)
#define Apoxi_UnitTestData_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

#include "UnitTest.hpp"

class UnitTestData {
    public: 
#ifdef APOXI_UNITTEST_NO_TESTNAMES      

        UnitTestData(const UnitTestHandle unit_test_handle, const INT id, const UnitTestData* next);
#else 

        UnitTestData(const UnitTestHandle unit_test_handle, const WCHAR* name, const INT id, const UnitTestData* next);
#endif // APOXI_UNITTEST_NO_TESTNAMES
        
        UnitTestData():next(0) {};
        
        UnitTest* (*CreateTest)();
                
        INT m_id;
        
        BOOLEAN m_is_testsuite;

        static INT m_instance_counter;

        static const UnitTestData* m_latest_instance;
        const UnitTestData* const next;
#ifndef APOXI_UNITTEST_NO_TESTNAMES

        const WCHAR* m_name;
#endif // APOXI_UNITTEST_NO_TESTNAMES
};

class UnitTestSuiteData : public UnitTestData {
    public: 
#ifdef APOXI_UNITTEST_NO_TESTNAMES      

        UnitTestSuiteData(const UnitTestHandle unit_test_handle, const INT id, const UnitTestData* next, BOOLEAN (*get_test_at_static)(UINT16, UnitTestSuiteData *));
#else 

        UnitTestSuiteData(const UnitTestHandle unit_test_handle, const WCHAR* name, const INT id, const UnitTestData* next, BOOLEAN (*get_test_at_static)(UINT16, UnitTestSuiteData *));
#endif // APOXI_UNITTEST_NO_TESTNAMES
        
        UnitTestSuiteData():UnitTestData(){};

        BOOLEAN (*m_get_test_at_static)(UINT16, UnitTestSuiteData *);
};



#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_UnitTestData_hpp


