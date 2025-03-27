/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestRepository_hpp)
#define Apoxi_UnitTestRepository_hpp

#include "UnitTestData.hpp"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST

class UnitTestRepository {

    public:
        static UnitTestRepository* GetInstance();

        virtual ~UnitTestRepository();

        UINT16 GetTestCount() const;

        
        UINT16 GetTestCountDeep() const;
        
        const UnitTestData* GetTestAt(UINT16 index) const;
        const UnitTestData* GetTestAt(void* address) const;

        BOOLEAN CopyHandleToBuffer(void* buffer, UINT16 index) const;
        
        BOOLEAN Travert(BOOLEAN (*test_action) (const UnitTestData * data), BOOLEAN perform_action_on_suites, BOOLEAN perform_action_on_tests) const;
        
        BOOLEAN TravertTestSuite(BOOLEAN (*test_action) (const UnitTestData * data), const UnitTestSuiteData* suite_data, BOOLEAN perform_action_on_suites, BOOLEAN perform_action_on_tests, UINT16* size = 0) const;
    
    protected:
        UnitTestRepository();
    private:
        static BOOLEAN IncrementTestCountAction(const UnitTestData * test_data);

        
        
        static UnitTestRepository* m_instance;
        UINT16 m_count_deep;
};

#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS
#endif // Apoxi_UnitTestRepository_hpp


