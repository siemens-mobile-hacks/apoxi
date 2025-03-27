/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestTests_hpp)
#define ApoxiApp_SocketTestTests_hpp

#include <SocketTest/SocketTestT1.hpp>
#include <SocketTest/SocketTestT2.hpp>
#include <SocketTest/SocketTestT5.hpp>
#include <SocketTest/SocketTestT6.hpp>
#include <SocketTest/SocketTestT7.hpp>
#include <SocketTest/SocketTestT8.hpp>

class SocketTestTests
{
public:
    enum defs { 
        m_nNrOfTestGroups = 8,  
        m_nMaxNrOfTestsInGroup = 10 
    };

    struct TestGroupInfo {
        WCHAR m_wsName[16];     
        BOOLEAN m_bTestEnabled;     
        UINT m_nNrOfSubtests;   
        UINT32 m_nIterationsTotal[m_nMaxNrOfTestsInGroup];  
        UINT32 m_nIterationsDone[m_nMaxNrOfTestsInGroup];   
        UINT32 m_nIterationsSuccessfull[m_nMaxNrOfTestsInGroup];    
        SocketTestT::Status m_nStatus[m_nMaxNrOfTestsInGroup]; 
        SocketTestT::internalStatus m_nInternalStatus[m_nMaxNrOfTestsInGroup]; 
        INT m_nErrorCode[m_nMaxNrOfTestsInGroup]; 
        BOOLEAN m_bReportSent[m_nMaxNrOfTestsInGroup]; 
    };

public:
    BOOLEAN ExecuteTest(INT group, INT test, BOOLEAN finish = FALSE); 
    void FinishGroup(INT group); 
    
    SocketTestTests();
    virtual ~SocketTestTests();

    TestGroupInfo m_sTests[m_nNrOfTestGroups]; 

    UINT    GetTotalNumberOfTests() { return m_nTotalTests; } 
    UINT    GetNumberOfEnabledTests() { return m_nEnabledTests; } 
    void    CalculateNumberOfEnabledTests(); 
    UINT    GetNumberOfFinishedTests() { return m_nFinishedTests; } 
    UINT    GetNumberOfPassedTests() { return m_nPassedTests; }

    void    SetDefaultTests(); 
    void    DisableAllTests(); 

    void    StartTest(); 

    BOOLEAN GetTestInProgress(INT &group, INT &test); 
    
    SocketTestT3& GetSocketTestT3() { return m_testT3;}
    SocketTestT5& GetSocketTestT5() { return m_testT5;}
    static const DownloadSettings* GetDownloadDefaultValues() { return &DownloadDefaultValues;}

private:
    UINT    m_nTotalTests; 
    UINT    m_nEnabledTests; 
    UINT    m_nFinishedTests; 
    UINT    m_nPassedTests; 

    INT m_nCurrentGroup; 
    INT m_nCurrentTest; 

    SocketTestT1    m_testT1; 
    SocketTestT2    m_testT2; 
    SocketTestT3    m_testT3; 
    SocketTestT4    m_testT4; 
    SocketTestT5    m_testT5; 
    SocketTestT6    m_testT6; 
    SocketTestT7    m_testT7; 
    SocketTestT8    m_testT8; 

    static const struct TestGroupInfo DefaultTestValues[m_nNrOfTestGroups]; 
    static const DownloadSettings DownloadDefaultValues; 
};

#endif // ApoxiApp_SocketTestTests_hpp
