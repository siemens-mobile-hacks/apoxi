// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if !defined(UibSettingsTest_hpp)
#define UibSettingsTest_hpp

#include <UnifiedInbox/UibSettingsProvider.hpp>
#include <UnifiedInbox/UibSettingsWin.hpp>

#include <MmiTest/MmiUnitTest/MmiUnitTest.hpp>

class UibSettingsTest : public MmiUnitTest {
    typedef MmiUnitTest Base;
    public:
        UibSettingsTest() {};

        virtual ~UibSettingsTest();

        void Init(WCHAR* name, MmiUnitTestSuite* suite);
        
        virtual TestResult Run();

        void TestSettingsProvider(const DataItem& sort_crit, const DataItem& sort_asc);

        void TestSettingsDisplay();
        void TestPredefinedSettings();
        void TestSettingsModification(const DataItem& sort_crit, const DataItem& sort_asc);

    private:
        const WCHAR* GetSortKeyText(UINT8 sort_crit);

        UibSettingsProvider m_settings_provider;
        UibSettingsWin m_settings_win;

};

#endif /* UibSettingsTest_hpp */
