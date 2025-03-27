/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestSuite_hpp)
#define Apoxi_UnitTestSuite_hpp

#include "UnitTest.hpp"
#include "UnitTestData.hpp"
#include "UnitTestRunner.hpp"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST
#ifndef REGISTER_UNITTESTSUITE
    #define REGISTER_UNITTESTSUITE
#endif
/*  ------------------------------------------------------------------------
    BEGIN_UNITTEST_SUITE
    ------------------------------------------------------------------------ */
#ifdef APOXI_UNITTEST_NO_TESTNAMES
    #define BEGIN_UNITTEST_SUITE(TestClass) \
        class TestClass : public UnitTestSuite { \
            public: \
                TestClass() {}; \
                virtual ~TestClass() {}; \
                \
                static UnitTest* CreateInstance() { return new TestClass(); } \
                static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return TestClass::GetTestAtStatic;}; \
                const UnitTestSuiteData* GetTestAt(UINT16 index) {  \
                    if (GetTestAtStatic(index, &m_test_suite_data)) \
                    { \
                        return &m_test_suite_data;\
                    } \
                     else \
                    { \
                        return 0;\
                    }\
                } \
                static BOOLEAN GetTestAtStatic(UINT16 index, UnitTestSuiteData* test_suite_data ) { \
                    UINT16 l_index; \
                    l_index = 0;

#else
    #define BEGIN_UNITTEST_SUITE(TestClass) \
        class TestClass : public UnitTestSuite { \
            public: \
                TestClass() {}; \
                virtual ~TestClass() {}; \
                \
                static UnitTest* CreateInstance() { return new TestClass(); } \
                static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return TestClass::GetTestAtStatic;}; \
                \
                static const CHAR* const GetName() { return #TestClass; } \
                \
                const UnitTestSuiteData* GetTestAt(UINT16 index) {  \
                    if (GetTestAtStatic(index, &m_test_suite_data)) \
                    { \
                        return &m_test_suite_data;\
                    } \
                     else \
                    { \
                        return 0;\
                    }\
                } \
                static BOOLEAN GetTestAtStatic(UINT16 index, UnitTestSuiteData* test_suite_data ) { \
                    UINT16 l_index; \
                    l_index = 0;

#endif // APOXI_UNITTEST_NO_TESTNAMES
// BEGIN_UNITTEST_SUITE

/*  ------------------------------------------------------------------------
    ADD_UNITTEST_CLASS
    ------------------------------------------------------------------------ */
#ifdef APOXI_UNITTEST_NO_TESTNAMES
    #define ADD_TEST_CLASS(UnitTestClass) \
                if (l_index == index) \
                { \
                    test_suite_data->CreateTest = UnitTestClass::CreateInstance; \
                    if (UnitTestClass::GetDescendantsAccessMethod() != 0) {\
                        test_suite_data->m_is_testsuite = TRUE;\
                    } else {\
                        test_suite_data->m_is_testsuite = FALSE;\
                    }\
                    test_suite_data->m_get_test_at_static = UnitTestClass::GetDescendantsAccessMethod();\
                    /*index of subtestcase is only unique within the scope of the TestSuite*/ \
                    test_suite_data->m_id = l_index; \
                    return TRUE; \
                } \
                l_index++;
#else 
    #define ADD_TEST_CLASS(UnitTestClass) \
                if (l_index == index) \
                { \
                    test_suite_data->CreateTest = UnitTestClass::CreateInstance; \
                    if (UnitTestClass::GetDescendantsAccessMethod() != 0) {\
                        test_suite_data->m_is_testsuite = TRUE;\
                    } else {\
                        test_suite_data->m_is_testsuite = FALSE;\
                    }\
                    test_suite_data->m_get_test_at_static = UnitTestClass::GetDescendantsAccessMethod();\
                    test_suite_data->m_name = L###UnitTestClass;\
                    /*index of subtestcase is only unique within the scope of the TestSuite*/ \
                    test_suite_data->m_id = l_index; \
                    return TRUE; \
                } \
                l_index++;

#endif // APOXI_UNITTEST_NO_TESTNAMES
// ADD_UNITTEST_CLASS


/*  ------------------------------------------------------------------------
    END_UNITTEST_SUITE
    ------------------------------------------------------------------------ */
#define END_UNITTEST_SUITE \
        return FALSE;\
        } \
    };
// END_UNITTEST_SUITE


class UnitTestSuite : public UnitTest { 
    public:
        UnitTestSuite();
        virtual ~UnitTestSuite();
        
        virtual const UnitTestSuiteData* GetTestAt(UINT16 index) = 0;

    protected:
        virtual BOOLEAN _Execute(UnitTestResult& test_result);      
        UnitTestSuiteData m_test_suite_data;
    private:
        static BOOLEAN ExecuteDescendantTestAction(const UnitTestData * test_data);

};



#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestSuite_hpp


