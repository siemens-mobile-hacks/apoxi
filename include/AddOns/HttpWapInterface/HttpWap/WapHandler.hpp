/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(WapHandler_hpp)
#define WapHandler_hpp

#include <Kernel/UserDispatcher.hpp>
#include <Auxiliary/BinData.hpp>
#include <Auxiliary/WString.hpp>
#include "HttpWapMgrBase.hpp"
#include "HttpWapMgr.hpp"

/*
 * forward declarations
 */
class Message;

class WapHandler : public UserDispatcher  {   


public:


enum WapSessionStatus {
  WapSessionConnected,
  WapSessionSuspended
};
    

    WapHandler();
    virtual ~WapHandler();


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapRegister(INT pr_id, 
                                WString& mime,
                                INT app_id = 0);
#else
    virtual BOOLEAN RegisterWap(INT pr_id, 
                                WString& mime,
                                INT app_id = 0);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapUnregister(INT pr_id);
#else
    virtual BOOLEAN UnregisterWap(INT pr_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapSuspend(INT conn_id);
#else
    virtual BOOLEAN SuspendWap(INT conn_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapResume(INT conn_id);
#else
    virtual BOOLEAN ResumeWap(INT conn_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual  INT WapGetConnId();
#else
    virtual  INT GetConnIdWap();
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual WapSessionStatus WapGetSessionStatus() ;
#else
    virtual WapSessionStatus GetSessionStatusWap() ;
#endif


    virtual BOOLEAN AddRootCertificate(INT conn_id, const COMM_ROOT_CERT *pRootCert);


    virtual BOOLEAN ClearRootCertificate(INT conn_id, const COMM_ROOT_CERT *pRootCert);


    virtual BOOLEAN ReadRootCertificate(INT conn_id, UINT8** certData, UINT32* certLen);


    virtual BOOLEAN ReadUserCertificate(INT conn_id, UINT8** certData, UINT32* certLen, UINT8** certKey,UINT32* certKeyLen);


    virtual BOOLEAN AddUserCertificate(INT conn_id, const COMM_USER_CERT *pUserCert);


    virtual BOOLEAN ClearUserCertificate(INT conn_id, const COMM_USER_CERT *pUserCert);

    virtual BOOLEAN GetCipherSuiteName (INT conn_id, const UINT8** pCipherSuiteName);

    
protected:



    virtual BOOLEAN DecodeMessage(const Message& msg,
                                  INT& conn_id, 
                                  INT& requ_id,
                                  INT& status,
                                  WString& header, 
                                  BinData** body,
                                  INT& more,
                                  INT& length,
                                  WString& url);
    

    virtual BOOLEAN OnMessage(const Message& msg)=0;


    virtual BOOLEAN OnPush(const Message& msg) = 0;


    virtual BOOLEAN SetWapPushReceived(const CHAR* header, 
                                       const BinData* body);

    private :

        HttpWapMgr* m_http_Wap_mgr;

    INT m_connection_id;
    WapSessionStatus  m_conn_status;


#if defined(APOXI_COMPAT_2_3_0)
    BOOLEAN WapSetConnId(INT conn_id);
#else
    BOOLEAN SetConnIdWap(INT conn_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    BOOLEAN WapSetConnStatus(WapSessionStatus status);
#else
    BOOLEAN SetConnStatusWap(WapSessionStatus status);
#endif



};
#endif  // WapHandler_hpp

