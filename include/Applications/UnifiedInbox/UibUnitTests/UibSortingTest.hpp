// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if !defined(UibSortingTest_hpp)
#define UibSortingTest_hpp

#include <AddOns/AuxExtensions/AppendProvider.hpp>

#include <UnifiedInbox/UibSettingsProvider.hpp>
#include <UnifiedInbox/UibServiceImpl.hpp>

#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>
#include <MmiTest/TestChildProvider1.hpp>
#include <MmiTest/TestChildProvider2.hpp>

class UibSortingTest : public MmiUnitTest {
    typedef MmiUnitTest Base;
    public:
        UibSortingTest() {};

        virtual ~UibSortingTest();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

    private:
        void ChangeSorting(UINT8 sort_crit, BOOLEAN asc);
        void CheckProvider(Provider* prov);
        void UpdateSortedProvider(INT sort_colid, BOOLEAN asc);

        Provider* m_prov1;
        Provider* m_prov2;
        QuickSortProvider m_ref_prov;
        AppendProvider m_append_prov;

        UINT8   m_sort_key;
        BOOLEAN m_sort_asc;

        UibServiceImpl m_service;
};

#endif /* UibSortingTest_hpp */
