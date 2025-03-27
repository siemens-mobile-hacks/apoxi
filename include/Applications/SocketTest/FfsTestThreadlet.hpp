/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_FfsTestThreadlet_hpp)
#define ApoxiApp_FfsTestThreadlet_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Threadlet.hpp>
#include <SocketTest/FfsTests.hpp>

class FfsTestDispWin;

class FfsTestThreadlet : public Threadlet
{
    typedef Threadlet Base;
    
    public:
        static FfsTestThreadlet* CreateInstance(FfsTestDispWin* dispWin);

        virtual void ReleaseInstance(); 

        virtual INT Fn();

        static void SetRunning(BOOLEAN bRunning) { m_running = bRunning; 
                                                    m_nCurrentTest = 0; };

        static BOOLEAN GetRunning() { return m_running; }
        static UINT32 GetCurrentTest() { return m_nCurrentTest; }

    private:
        FfsTestThreadlet(FfsTestDispWin* dispWin);

        void ExecuteTests();
        BOOLEAN IsEnable();

        void UpdateTestInfo(UINT32 aError);

        static BOOLEAN m_running;
        static UINT32 m_nCurrentTest;

        FfsTests m_tests;
        FfsTestBase* m_test_info;
        FfsTestDispWin* m_FfsTestDispWin;
};

#endif // ApoxiApp_FfsTestThreadlet_hpp
