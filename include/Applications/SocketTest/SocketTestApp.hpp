/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestApp_hpp)
#define ApoxiApp_SocketTestApp_hpp

#include <Common/MmiApplication.hpp>
#include <GuiExtensions/MenuAction.hpp>
#include <Socket/SocketHandler.hpp>
#include <SocketTest/SocketTestWin.hpp>
#include <SocketTest/SocketTestTests.hpp>

class SocketTestApp : public MmiApplication
{
    typedef MmiApplication Base;

    public:
        virtual ~SocketTestApp(); 

        static SocketTestApp* GetInstance() { return &m_app; } 

        void Init(); 

        struct menuItems {
            IpAddr m_ipGatewayAddr; 
            IpPortNo m_nGatewayPort; 
            UINT32 m_nMaxTCPPacketSize; 
            UINT32 m_nMaxUDPPacketSize; 
            UINT32 m_nMaxTCPSockets; 
            UINT32 m_nMaxUDPSockets; 
            UINT32 m_nTimeout; 
        } *m_settings;

        SocketTestTests *GetTests() { return m_tests; } 
        FfsTestBase* GetFfsTestBase() { return m_FfsTestBase; } 

        void    StartTests(); 
        void    StopTests(); 
        BOOLEAN areTestsFinished() { return !m_bTestsRunning;}
        void    SkipCurrentTest(); 

        INT GetCurrentTestNr() { return m_nCurrentTestNr; }
        INT GetCurrentTestID() { return ((m_nCurrentTestGroup + 1) * 100 + m_nCurrentTestNr + 1); }
        INT GetCurrentTestGroup() { return m_nCurrentTestGroup; }
        SocketTestT::Status     GetLastStatus() { return m_tests->m_sTests[m_nCurrentTestGroup].m_nStatus[m_nCurrentTestNr]; }
        UINT32      GetTotalIterations() { return m_tests->m_sTests[m_nCurrentTestGroup].m_nIterationsTotal[m_nCurrentTestNr]; }
        UINT32      GetSuccessfullIterations() { return m_tests->m_sTests[m_nCurrentTestGroup].m_nIterationsSuccessfull[m_nCurrentTestNr]; }
        UINT32      GetLastIteration() { return m_tests->m_sTests[m_nCurrentTestGroup].m_nIterationsDone[m_nCurrentTestNr]; }
        INT     GetLastError() { return m_tests->m_sTests[m_nCurrentTestGroup].m_nErrorCode[m_nCurrentTestNr]; }
        
        void    StartTimeoutTimer() { if (m_settings->m_nTimeout) { m_timer.Init(&m_app, 1000*m_settings->m_nTimeout); m_timer.Start(); } } 
        void    StopTimeoutTimer() { if (m_timer.IsActive()) m_timer.Stop(); } 

        DataConnProfileId   m_nPSDid; 
        DataConnProfileId   m_nCSDid; 
        DataConnProfileId   m_nSERid; 

        void                FindDataConnProfiles(); 

    protected:
        static SocketTestApp        m_app; 

        virtual void OnStartup();
        void OnOpen(); 

        BOOLEAN OnMessage(const Message &msg); 
        void OnTriggerNotification (INT16 arg); 

#if !defined(ADLER_JUPITER)
        CommonMessageBox m_wait_msgbox;
#endif

//      INT m_nDownloadTime;
        virtual void OnTimer();

    private:
        friend class TriggerTimer<SocketTestApp>;
        TriggerTimer<SocketTestApp> m_timer;

        void ExecuteSocketTest(UINT group, UINT test, BOOLEAN finish = FALSE);
        void ExecuteNextSocketTest();
        BOOLEAN m_bTestsRunning;
        INT m_nCurrentTestNr;
        INT m_nCurrentTestGroup;
        SocketTestApp(); 

        SocketTestWin       m_socket_test_win; 
        MenuAction          m_open_sockettest_action; 

        SocketTestTests     *m_tests; 
        FfsTestBase         *m_FfsTestBase; 

        SocketHandler       m_socket_handler; 
};

#endif // ApoxiApp_SocketTestApp_hpp
