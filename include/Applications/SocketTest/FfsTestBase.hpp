/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestBase_hpp)
#define ApoxiApp_FfsTestBase_hpp

#if defined(APOXI_RTOS_WIN32)
    #define _SLEEP(x) Sleep(x);
#else
    #include <Kernel/Os/Os.hpp>
    #define _SLEEP(x) Os::Sleep(x);
#endif

#define ADLER_JUPITER // define for Jupiter release only

class FfsTestBase
{
public:
    enum Status {
        Passed,      
        Failed       
    };

    enum eTotalNumberOfTests 
    { 
        m_OpenClose,
        m_WriteRead,
        m_Overwrite,
        m_Append,
        m_Rename,
        m_Copy,
        m_nTotalNumberOfTests,  
    };

    struct FfsTestInfo {
        WCHAR   m_wsName[20];       
        BOOLEAN m_bTestEnabled;     
        UINT32      m_nIterationsTotal; 
        UINT32      m_nIterationsDone;  
        UINT32      m_nIterationsSuccessfull;   
        UINT32      m_nErrorCode; 
        Status  m_nStatus; 
    };

public:
    FfsTestBase();
    virtual ~FfsTestBase();

    FfsTestInfo m_FfsTests[m_nTotalNumberOfTests]; 
    
    UINT32      GetTotalNumberOfTests() { return m_nTotalTests; } 
    UINT32      GetNumberOfEnabledTests() { return m_nEnabledTests; } 
    UINT32      GetNumberOfFinishedTests() { return m_nFinishedTests; } 
    UINT32      GetNumberOfPassedTests() { return m_nPassedTests; }
    void        CalculateNumberOfEnabledTests();
    void        AddFinished() { m_nFinishedTests++; }
    void        AddPassed()   {m_nPassedTests++; }

    void    SetDefaultTests(); 
    void    DisableAllTests(); 
        
    void    StartTestSet(); 

private:
    UINT32 m_nTotalTests; 
    UINT32 m_nEnabledTests; 
    UINT32 m_nFinishedTests; 
    UINT32 m_nPassedTests; 

    static const struct FfsTestInfo DefaultTestValues[m_nTotalNumberOfTests]; 
};

#endif // ApoxiApp_FfsTestBase_hpp
