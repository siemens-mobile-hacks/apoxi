/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifndef HttpWapMgr_hpp
#define HttpWapMgr_hpp

#include <AddOns/HttpWapInterface/HttpWapPlugin/HttpWapMgrPlugin.hpp>

/*
 * forward declarations
 */
class BinData;
class Message;
class HttpHandler;
class HttpWapMgrPlugin;


#define APOXI_MAX_CONN_LIMIT       100

class HttpWapMgr {


public:

    virtual ~HttpWapMgr();

    

    static  HttpWapMgr* GetInstance();


protected:


    HttpWapMgrPlugin* m_http_plugin;



    INT m_conn_id_free_Slot[APOXI_MAX_CONN_LIMIT];



    virtual BOOLEAN DecodeMessage(const Message& msg,
                                  INT& conn_id, 
                                  INT& requ_id,
                                  INT& status,
                                  WString& header, 
                                  BinData** body,
                                  INT& more,
                                  INT& length,
                                  WString& url);
    


    BOOLEAN GetFreeConnId(INT& conn_id);



    void ReleaseConnId(INT& conn_id);


    /*********************

        HTTP functionality

    **********************/


#if defined(APOXI_COMPAT_2_3_0)
        virtual BOOLEAN HttpOpen(INT& conn_id, INT pr_id);
#else
        virtual BOOLEAN OpenHttp(INT& conn_id, INT pr_id);
#endif
  


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestGet( INT conn_id, 
                                    INT& requ_id, 
                                    const CHAR* URL, 
                                    const CHAR* header);
#else
    virtual BOOLEAN RequestGetHttp( INT conn_id, 
                                    INT& requ_id, 
                                    const CHAR* URL, 
                                    const CHAR* header);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestHead( INT conn_id, 
                                    INT& requ_id, 
                                    const CHAR* URL, 
                                    const CHAR* header);
#else
    virtual BOOLEAN RequestHeadHttp( INT conn_id, 
                                    INT& requ_id, 
                                    const CHAR* URL, 
                                    const CHAR* header);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestPost(INT conn_id, 
                                    INT& requ_id, 
                                    const CHAR* URL, 
                                    const CHAR* header, 
                                    BinData* body, 
                                    INT more);
#else
    virtual BOOLEAN RequestPostHttp(INT conn_id, 
                                    INT& requ_id, 
                                    const CHAR* URL, 
                                    const CHAR* header, 
                                    BinData* body, 
                                    INT more);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestPostData(INT conn_id, 
                                        INT  requ_id, 
                                        BinData* body, 
                                        INT more);
#else
    virtual BOOLEAN RequestPostDataHttp(INT conn_id, 
                                        INT  requ_id, 
                                        BinData* body, 
                                        INT more);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpCancel(INT conn_id, INT requ_id);
#else
    virtual BOOLEAN CancelHttp(INT conn_id, INT requ_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpClose(INT conn_id) ;
#else
    virtual BOOLEAN CloseHttp(INT conn_id) ;
#endif
     

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpSuspend(INT conn_id);
#else
    virtual BOOLEAN SuspendHttp(INT conn_id);
#endif
    

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpResume(INT conn_id) ;
#else
    virtual BOOLEAN ResumeHttp(INT conn_id) ;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual INT HttpGetConnStatus();
#else
    virtual INT GetConnStatusHttp();
#endif

#ifdef APOXI_WAP_STACK

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpGetSessionInfo(INT conn_id, INT& request_id);
#else
    virtual BOOLEAN GetSessionInfoHttp(INT conn_id, INT& request_id);
#endif

    virtual BOOLEAN DecodeGetSessionInfoResponseMessage(
                                const Message& msg,
                                          INT& result, 
                                INT& conn_id,
                                          INT& connection_type,
                                          String& cipher_info,
                                    CertificateInfo_t& certificate);

#endif //APOXI_WAP_STACK

    /********************

        WAP functionality

    *********************/


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapRegister(INT& conn_id,
                                INT pr_id, 
                                WString& mime,
                                INT app_id = 0);
#else
    virtual BOOLEAN RegisterWap(INT& conn_id,
                                INT pr_id, 
                                WString& mime,
                                INT app_id = 0);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapUnregister(INT& conn_id,const INT& pr_id);
#else
    virtual BOOLEAN UnregisterWap(INT& conn_id,const INT& pr_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapSuspend(INT  conn_id);
#else
    virtual BOOLEAN SuspendWap(INT  conn_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapResume(INT  conn_id);
#else
    virtual BOOLEAN ResumeWap(INT  conn_id);
#endif
 

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapGetSessionStatus(INT conn_id);
#else
    virtual BOOLEAN GetSessionStatusWap(INT conn_id);
#endif


    virtual BOOLEAN AddRootCertificate(INT conn_id, const COMM_ROOT_CERT *pRootCert);


    virtual BOOLEAN ClearRootCertificate(INT conn_id, const COMM_ROOT_CERT *pRootCert);


    virtual BOOLEAN ReadRootCertificate(INT conn_id, UINT8** certData, UINT32* certLen);


    virtual BOOLEAN ReadUserCertificate(INT conn_id, UINT8** certData, UINT32* certLen, UINT8** certKey,UINT32* certKeyLen);


    virtual BOOLEAN AddUserCertificate(INT conn_id, const COMM_USER_CERT *pUserCert);


    virtual BOOLEAN ClearUserCertificate(INT conn_id, const COMM_USER_CERT *pUserCert);

    virtual BOOLEAN GetCipherSuiteName (INT conn_id, const UINT8** pCipherSuiteName);

    private :

    friend class HttpHandler;
    friend class WapHandler;


    static HttpWapMgr m_http_wapmgr;

    HttpWapMgr();


};


#endif  // HttpWapMgr_hpp

