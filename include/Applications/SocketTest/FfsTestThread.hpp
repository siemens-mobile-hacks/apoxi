/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestThread_hpp)
#define ApoxiApp_FfsTestThread_hpp

#include <Kernel/Os/Os.hpp>
#include <SocketTest/FfsTests.hpp>

class FfsTestThread : public Thread
{
    typedef Thread Base;

    public:
        FfsTestThread();
        virtual ~FfsTestThread();

        virtual INT ThreadFn();

        static void SetRunning(BOOLEAN bRunning) { m_running = bRunning; 
                                                    m_nCurrentTest = 0; };

        static BOOLEAN GetRunning() { return m_running; }
        static UINT32 GetCurrentTest() { return m_nCurrentTest; }

        void UpdateTestInfo(UINT32 aError);
        
        void SetMutex(Mutex* aMutex) {  ASSERT_DEBUG(aMutex != NULL);
                                            m_disp_mutex = aMutex; }

    private:
        void ExecuteTests();
        BOOLEAN IsEnable();

        static BOOLEAN m_running;
        static UINT32 m_nCurrentTest;

        FfsTests m_tests;
        Mutex *m_disp_mutex;
        FfsTestBase* m_test_info;
};

#endif // ApoxiApp_FfsTestThread_hpp
