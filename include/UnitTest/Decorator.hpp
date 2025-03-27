/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestDecorator_hpp)
#define Apoxi_UnitTestDecorator_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

#include "UnitTest.hpp"
#include "UnitTestResult.hpp"

class Decorator : public UnitTest {

    public:
        virtual ~Decorator() {};
    protected:
        Decorator(UnitTestHandle unit_test_case) {
            _unit_test_case = unit_test_case;
        }

    protected:
        UnitTestHandle _unit_test_case;

        virtual BOOLEAN _Execute(UnitTestResult& test_result) = 0;
};


class RepeatedUnitTest : public Decorator {
    typedef Decorator Base;

    public:
        virtual ~RepeatedUnitTest() {};

    
    protected:
        RepeatedUnitTest(UnitTestHandle unit_test_case, INT loops) : Base(unit_test_case) {
            m_loops = loops;
        }

        INT m_loops;
        
        virtual BOOLEAN _Execute(UnitTestResult& test_result);
};

/*  ------------------------------------------------------------------------
    DEFINE_REPEATED_UNITTEST
    ------------------------------------------------------------------------ */
#define DEFINE_REPEATED_UNITTEST(RepeatedUnitTestClass, UnitTestClass, loops) \
class RepeatedUnitTestClass : public RepeatedUnitTest {\
        typedef RepeatedUnitTest Base;\
        \
        private:\
            RepeatedUnitTestClass(UnitTestHandle unit_test_case) : Base(unit_test_case, loops) {} \
        public: \
            static BOOLEAN (*GetDescendantsAccessMethod()) (UINT16, UnitTestSuiteData *) {return UnitTestClass::GetDescendantsAccessMethod();}; \
            static UnitTest* CreateInstance() { \
                return new RepeatedUnitTestClass(GET_UNITTEST_HANDLE(UnitTestClass)); \
            } \
    } \



#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestDecorator_hpp

