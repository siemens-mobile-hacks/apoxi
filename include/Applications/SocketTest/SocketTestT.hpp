/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestT_hpp)
#define ApoxiApp_SocketTestT_hpp

class SocketTestT
{
public:
    enum Status {
        Skipped,     
        InProgress,  
        Passed,      
        Failed       
    };

    enum internalStatus {
        NotStarted,
        FinishedOK,
        FinishedErr,
        Started,
        WaitingForInit,
        WaitingForConnect,
        Write,
        WaitingForWrite,
        WaitingForRead,
        WaitingForClose
    };

    SocketTestT();
    virtual ~SocketTestT();

    virtual internalStatus  TestA(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestB(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestC(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestD(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestE(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestF(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestG(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestH(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual internalStatus  TestI(internalStatus instatus, INT &ErrorCode) { return NotStarted; }
    virtual void FinishGroup() { }
    
protected:
    UINT32 Random(UINT32 start, UINT32 end) { return rand() % (end - start + 1) + start; } 
};

enum testMessageType {
    SEND_UDP,
    SEND_TCP,
    REPORT,
    FINAL_REPORT,
    RESPONSE,
    STOP_UDP,
    STOP_TCP,
    STOP_ALL
};

typedef struct 
{
    UINT32 m_nDataSize;
    UINT32 m_nPacketSize;
    UINT32 m_nServerDelay;
    UINT32 m_nDownloadTime;
} DownloadSettings;

class SocketTestMessage
{
public:
    SocketTestMessage(INT size);
    SocketTestMessage();
    ~SocketTestMessage();

    INT GetSize() { return m_nSize; }
    char* GetMessage() { return m_pMessage; }
    BOOLEAN AddToMessage(enum testMessageType type, UINT32 size = 0, UINT32 packets = 1, UINT32 freq = 0);
    void Clean();
    
private:
    INT  m_nSize;
    char *m_pMessage;
    void AddPreviousTests(String &tmpstring, INT last_group);
};

#endif // ApoxiApp_SocketTestT_hpp
