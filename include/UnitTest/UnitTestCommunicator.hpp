/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UnitTestCommunicator_hpp)
#define Apoxi_UnitTestCommunicator_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef APOXI_UNITTEST
#ifdef APOXI_UNITTEST_TCPIP

#include <Socket/SocketHandler.hpp>
#include <Socket/InetSocketAddr.hpp>

#include <UnitTest/UnitTestData.hpp>
#include <UnitTest/MsgTypes.hpp>
#include <UnitTest/UTTcpSocket.hpp>


//WARING: IMPORTANT: Do not change this buffer for some reason, because this buffer
//is strictly dependent on the buffersize on the Unit Test Management Tools (host tools).
//The socket communication on the X60 target is highly instable, when the host
//tool reads faster than the socket can write. this can cause your X60 to crash.
//this buffer sends 25 test handles at once, then the host tools waits for some time
//to let the buffer be refilled.
#define c_test_case_handle_buffer_size 100


class UnitTestCommunicator {
    private:
        UnitTestCommunicator();
    public:
        ~UnitTestCommunicator();

        static UnitTestCommunicator* GetInstance();
        void Init();
        
        void Communicate();

        BOOLEAN OpenConnection(const IpAddr &ipAddr);

        void CloseConnection();

        void ConnectionLost();
        
        
        static BOOLEAN SendTestDataAction(const UnitTestData * test_data);
        
        static BOOLEAN FindTestDataAction(const UnitTestData * test_data);

    private:

        BOOLEAN SendTestCases();
        BOOLEAN RunTest();

        BYTE* m_test_case_handle_buffer;
        void SocketWrite(BYTE* buffer, UINT16 buffer_size);
        void SocketFlush();
        void SocketClear();
        UINT16 m_socket_buffer_pos;
        
        UTTcpSocket m_tcpSocket;
        InetSocketAddr m_clientAddr;
        SocketHandler m_handler;

        BooleanCondition m_no_communication_in_progress;
        
        enum OrderType {
            GetTestCases = 0,
            RunTestCase = 1,
            Invalid
        };

        static UnitTestCommunicator m_instance;
    
        const CHAR* GetLastSlashPos(const CHAR* str);
        const CHAR* GetNullTerminationPos(const CHAR* str);
        
        
    
        UtcStatusMessage m_utc_status_message;
        
        UINT32 m_requested_test_address;
        
        UnitTestData m_execute_ut_data;

        BYTE m_read_command_byte;

        DataConnProfileId m_dcp_id;
    };
#endif //APOXI_UNITTEST_TCPIP
#endif //APOXI_UNITTEST
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_UnitTestApp_hpp

