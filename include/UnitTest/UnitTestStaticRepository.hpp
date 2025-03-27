/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestStaticRepository_hpp)
#define Apoxi_UnitTestStaticRepository_hpp

#include "UnitTestData.hpp"
#include "UnitTestRepository.hpp"
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST
#ifdef APOXI_UNITTEST_STATIC_REPOSITORY
/*  ------------------------------------------------------------------------
    DEFINES FOR THE REPOSITORY 
    ------------------------------------------------------------------------ */
#define BEGIN_UNITTEST_REPOSITORY UnitTestData UnitTestStaticRepository::m_unit_test_table[] = {
#ifdef APOXI_TARGETSYSTEM_HOST 
    #ifdef APOXI_UNITTEST_NO_TESTNAMES
        #define ADD_TEST(ClassName) UnitTestData(ClassName::CreateInstance, 0, 0),
    #else
        #define ADD_TEST(ClassName) UnitTestData(ClassName::CreateInstance, L#ClassName, 0, 0),
    #endif
#else
    #ifdef APOXI_UNITTEST_NO_TESTNAMES
        #define ADD_TEST(ClassName) UnitTestData(ClassName::CreateInstance, 0, 0),
    #else
        #define ADD_TEST(ClassName) UnitTestData(ClassName::CreateInstance, L#ClassName, 0, 0),
    #endif
#endif

#ifdef APOXI_UNITTEST_NO_TESTNAMES
    #define END_UNITTEST_REPOSITORY UnitTestData(0, 0, 0) };
#else
    #define END_UNITTEST_REPOSITORY UnitTestData(0, (WCHAR*)0, 0, 0) };
#endif

// DEFINES FOR THE REPOSITORY 


class UnitTestStaticRepository: public UnitTestRepository {

    public:
        friend UnitTestRepository;
        

        virtual ~UnitTestStaticRepository();

        UINT16 GetTestCount() const { return m_count; }

        const UnitTestData* GetTestAt(UINT16 index) const;
        const UnitTestData* GetTestAt(void* address) const;

        BOOLEAN CopyHandleToBuffer(void* buffer, UINT16 index) const;
        
        void Travert(BOOLEAN (*test_action) (UnitTestData * data), BOOLEAN travert_suites, BOOLEAN travert_tests) {};
    
    private:
        UnitTestStaticRepository();
        static UnitTestStaticRepository* m_instance;

        static UnitTestData m_unit_test_table[];
        static UINT16 m_count;   
};

#endif //APOXI_UNITTEST_STATIC_REPOSITORY
#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_UnitTestStaticRepository_hpp


