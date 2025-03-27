/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_UnitTestCase_hpp)
#define Apoxi_UnitTestCase_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

#include "UnitTest.hpp"
#include "UnitTestResult.hpp"

class UnitTestSuiteData;
/*  ------------------------------------------------------------------------
    UNITTEST_ERROR
    ------------------------------------------------------------------------ */
#if defined APOXI_UNITTEST_NO_FILENAMES
    #define UNITTEST_ERROR(file, line, msg) \
        Error();
#elif defined APOXI_UNITTEST_NO_MESSAGES
    #define UNITTEST_ERROR(file, line, msg) \
        Error(file, line);
#else
    #define UNITTEST_ERROR(file, line, msg) \
        Error(file, line, msg);
#endif
// UNITTEST_ERROR


/*  ------------------------------------------------------------------------
    CLAIM_TRUE
    ------------------------------------------------------------------------ */
#define CLAIM_TRUE(condition) \
    if (!(condition)) { \
        UNITTEST_ERROR(__FILE__,__LINE__, #condition);  \
        return; \
    }
// CLAIM_TRUE


/*  ------------------------------------------------------------------------
    CLAIM_TRUE_INFO
    ------------------------------------------------------------------------ */
#define CLAIM_TRUE_INFO(condition, msg) \
    if (!(condition)) { \
        UNITTEST_ERROR(__FILE__,__LINE__, #msg);    \
        return; \
    }
// CLAIM_TRUE_INFO

/*  ------------------------------------------------------------------------
    CLAIM_FALSE
    ------------------------------------------------------------------------ */
#define CLAIM_FALSE(condition) \
    if ((condition)) {  \
        UNITTEST_ERROR(__FILE__,__LINE__, #condition);  \
        return; \
    }
// CLAIM_FALSE

/*  ------------------------------------------------------------------------
    CLAIM_FALSE_INFO
    ------------------------------------------------------------------------ */
#define CLAIM_FALSE_INFO(condition, msg) \
    if ((condition)) {  \
        UNITTEST_ERROR(__FILE__,__LINE__, #msg);    \
        return; \
    }
// CLAIM_FALSE_INFO


/*  ------------------------------------------------------------------------
    CLAIM_NOT_NULL
    ------------------------------------------------------------------------ */
#define CLAIM_NOT_NULL(pointer) \
    if (pointer == 0) { \
        UNITTEST_ERROR(__FILE__,__LINE__, #pointer);    \
        return; \
    }
// CLAIM_NOT_NULL

/*  ------------------------------------------------------------------------
    CLAIM_NOT_NULL_INFO
    ------------------------------------------------------------------------ */
#define CLAIM_NOT_NULL_INFO(pointer, msg) \
    if (pointer == 0) { \
        UNITTEST_ERROR(__FILE__,__LINE__, msg); \
        return; \
    }
// CLAIM_NOT_NULL_INFO

/*  ------------------------------------------------------------------------
    CLAIM_NULL
    ------------------------------------------------------------------------ */
#define CLAIM_NULL(pointer) \
    if (pointer != 0) { \
        UNITTEST_ERROR(__FILE__,__LINE__, #pointer);    \
        return; \
    }
// CLAIM_NULL

/*  ------------------------------------------------------------------------
    CLAIM_NULL_INFO
    ------------------------------------------------------------------------ */
#define CLAIM_NULL_INFO(pointer, msg) \
    if (pointer != 0) { \
        UNITTEST_ERROR(__FILE__,__LINE__, #msg);    \
        return; \
    }
// CLAIM_NULL_INFO

/*  ------------------------------------------------------------------------
    APOXI_UNITTEST_INSTANCE_PER_TEST_METODS
    ------------------------------------------------------------------------ */
# define APOXI_UNITTEST_INSTANCE_PER_TEST_METHODS(TestClass) \
            TestClass* m_single_test_instance; \
            void CreateSingleTestInstance() { m_single_test_instance = new TestClass(); } \
            TestClass* GetSingleTestInstance() { return m_single_test_instance; } \
            void DeleteSingleTestInstance() { delete m_single_test_instance; m_single_test_instance = 0;} \
            void SetUnitTestResult (UnitTestResult* test_result) { m_test_result = test_result; } \
            BOOLEAN GetCurrentTestSuccess() { return m_current_test_success; } \
            void SetCurrentTestSuccess(BOOLEAN current_test_success) { m_current_test_success = current_test_success; } \
            \

// APOXI_UNITTEST_INSTANCE_PER_TEST_METODS

/*  ------------------------------------------------------------------------
    BEGIN_UNITTEST_CLASS
    ------------------------------------------------------------------------ */
#ifdef APOXI_UNITTEST_NO_TESTNAMES
    #define BEGIN_UNITTEST_CLASS(TestClass) \
        public: \
            static UnitTest* CreateInstance() { return new TestClass(); } \
            static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return 0;}; \
        protected: \
            APOXI_UNITTEST_INSTANCE_PER_TEST_METHODS(TestClass) \
            \
            BOOLEAN _Execute(UnitTestResult& test_result) \
            {\
                \
                BOOLEAN success = TRUE;\
                Init();\
                m_test_result = &test_result
#else
    #define BEGIN_UNITTEST_CLASS(TestClass) \
        public: \
            static UnitTest* CreateInstance() { return new TestClass(); } \
            static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return 0;}; \
            virtual const CHAR* GetName() { return #TestClass; } \
            \
        protected: \
            APOXI_UNITTEST_INSTANCE_PER_TEST_METHODS(TestClass) \
\
            BOOLEAN _Execute(UnitTestResult& test_result) \
            {\
                \
                BOOLEAN success = TRUE; \
                Init();\
                m_test_result = &test_result
#endif

// BEGIN_UNITTEST_CLASS

/*  ------------------------------------------------------------------------
    ADD_TEST_CASE
    ------------------------------------------------------------------------ */
#define ADD_TEST_CASE(TestMethod) \
        CreateSingleTestInstance(); \
        GetSingleTestInstance()->SetUnitTestResult(&test_result); \
        GetSingleTestInstance()->SetCurrentTestSuccess(TRUE); \
        GetSingleTestInstance()->EnterSetup(); \
        GetSingleTestInstance()->Setup(); \
        GetSingleTestInstance()->LeaveSetup(); \
        if (!GetSingleTestInstance()->SetupErrorOccured()) { \
            GetSingleTestInstance()->TestMethod(); \
            if (GetSingleTestInstance()->GetCurrentTestSuccess()) { \
                m_current_test_success = true; \
                test_result.AddSuccess(); \
            } \
            else { \
                m_current_test_success = false; \
                success = FALSE; \
            } \
        } \
        GetSingleTestInstance()->EnterTeardown(); \
        GetSingleTestInstance()->Teardown(); \
        GetSingleTestInstance()->LeaveTeardown(); \
        DeleteSingleTestInstance();

// ADD_TEST_CASE

/*  ------------------------------------------------------------------------
    END_UNITTEST_CLASS
    ------------------------------------------------------------------------ */
#define END_UNITTEST_CLASS \
            return success; \
                };
// END_UNITTEST_CLASS


class UnitTestCase : public UnitTest {

    public:

        UnitTestCase() : 
          m_in_teardown(false), m_in_setup(false), 
          m_teardown_error_occured(false), m_setup_error_occured(false)  
        {};
        virtual ~UnitTestCase() {};

        virtual void Setup() {};
        virtual void Teardown() {};

        virtual void Init() {};

        void EnterSetup() {m_in_setup = true;};
        void LeaveSetup() {m_in_setup = false;};

        BOOLEAN SetupErrorOccured() const {return m_setup_error_occured;};

        void EnterTeardown() {m_in_teardown = true;};

        void LeaveTeardown() {m_in_teardown = false;};

        BOOLEAN TeardownErrorOccured() const {return m_teardown_error_occured;};

    protected:
#if defined APOXI_UNITTEST_NO_FILENAMES
        void Error();
#elif defined APOXI_UNITTEST_NO_MESSAGES
        void Error(const CHAR* file_name, INT line_number);
#else
        void Error(const CHAR* file_name, INT line_number, const CHAR* condition);
#endif //APOXI_UNITTEST_NO_FILENAMES,APOXI_UNITTEST_NO_MESSAGES

#if (defined APOXI_TARGETSYSTEM_HOST || defined APOXI_UNITTEST_TRACE)
        static String m_error_message;
#endif

    protected:
        UnitTestResult* m_test_result;
        BOOLEAN m_current_test_success;
        BOOLEAN m_in_teardown;
        BOOLEAN m_in_setup;
        BOOLEAN m_teardown_error_occured;
        BOOLEAN m_setup_error_occured;



};
#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestCase_hpp

