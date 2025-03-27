/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#ifndef HttpWapMgrBase_hpp
#define HttpWapMgrBase_hpp


#ifdef APOXI_WAP_STACK
#include <Wap/Main/WapService.hpp>
#include <Wap/Main/BrowserMsgTypes.hpp>
#endif //APOXI_WAP_STACK


#ifndef _JDI_COMMUNICATOR_H_
typedef struct comm_root_cert
{

    INT8 *psContent;
    UINT32 uiLength;
    INT8 *pszContentType;
    struct comm_root_cert *pNext;

} COMM_ROOT_CERT;


typedef struct comm_user_cert
{

    INT8 *psUserCert;
    UINT32 uiCertLen;
    INT8 *pszContentType;
    INT8 *psKey;
    UINT32 uiKeyLen;
    INT8 *pszPassword;
    struct comm_user_cert *pNext;

} COMM_USER_CERT;
#endif


class HttpWapMgrBase
{
    
public:

    HttpWapMgrBase(){};
    virtual ~HttpWapMgrBase(){};


    virtual BOOLEAN DecodeMessage(const Message& msg,INT& conn_id, INT& requ_id
                             ,INT& status,WString& header, BinData** body,
                             INT& more,INT& length,WString& url)=0;
    

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpOpen(INT& conn_id, INT pr_id)=0;
#else
    virtual BOOLEAN OpenHttp(INT& conn_id, INT pr_id)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestGet(INT   conn_id,INT& requ_id, 
                                const CHAR* URL, const CHAR* header)=0;
#else
    virtual BOOLEAN RequestGetHttp(INT   conn_id,INT& requ_id, 
                                const CHAR* URL, const CHAR* header)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestHead(INT conn_id,INT& requ_id,
                                        const CHAR* URL, const CHAR* header)=0;
#else
    virtual BOOLEAN RequestHeadHttp(INT conn_id,INT& requ_id,
                                        const CHAR* URL, const CHAR* header)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestPost(INT  conn_id, 
                                        INT& requ_id, 
                                        const CHAR* URL, 
                                        const CHAR* header, 
                                        BinData* body, 
                                        INT  more)=0;
#else
    virtual BOOLEAN RequestPostHttp(INT  conn_id, 
                                        INT& requ_id, 
                                        const CHAR* URL, 
                                        const CHAR* header, 
                                        BinData* body, 
                                        INT  more)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpRequestPostData(INT conn_id,
                                        INT& requ_id,
                                        BinData*  body, 
                                        INT more)=0;
#else
    virtual BOOLEAN RequestPostDataHttp(INT conn_id,
                                        INT& requ_id,
                                        BinData*  body, 
                                        INT more)=0;
#endif
    

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpCancel(INT conn_id,INT requ_id)=0;
#else
    virtual BOOLEAN CancelHttp(INT conn_id,INT requ_id)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpClose(INT conn_id)=0;
#else
    virtual BOOLEAN CloseHttp(INT conn_id)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpSuspend(INT conn_id)=0;
#else
    virtual BOOLEAN SuspendHttp(INT conn_id)=0;
#endif



#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpResume(INT conn_id)=0;
#else
    virtual BOOLEAN ResumeHttp(INT conn_id)=0;
#endif

#ifdef APOXI_WAP_STACK


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN HttpGetSessionInfo(INT conn_id, INT& request_id)=0;
#else
    virtual BOOLEAN GetSessionInfoHttp(INT conn_id, INT& request_id)=0;
#endif


    virtual BOOLEAN DecodeGetSessionInfoResponseMessage(
                                const Message& msg,
                                          INT& result,
                                INT& conn_id,
                                          INT& connection_type,
                                          String& cipher_info,
                                     CertificateInfo_t& certificate)=0;
#endif //APOXI_WAP_STACK



    virtual BOOLEAN IsMessageForMe()=0;


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapGetSessionStatus()=0 ;
#else
    virtual BOOLEAN GetSessionStatusWap()=0 ;
#endif

    

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapRegister(const INT& conn_id,INT pr_id, 
                                WString& mime, INT app_id)=0;
#else
    virtual BOOLEAN RegisterWap(const INT& conn_id,INT pr_id, 
                                WString& mime, INT app_id)=0;
#endif



#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapResume(INT conn_id)=0;
#else
    virtual BOOLEAN ResumeWap(INT conn_id)=0;
#endif
    

#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapUnregister(const INT& conn_id)=0;
#else
    virtual BOOLEAN UnregisterWap(const INT& conn_id)=0;
#endif


#if defined(APOXI_COMPAT_2_3_0)
    virtual BOOLEAN WapSuspend(INT conn_id)=0;
#else
    virtual BOOLEAN SuspendWap(INT conn_id)=0;
#endif


    virtual BOOLEAN AddRootCertificate(INT conn_id, const COMM_ROOT_CERT *pRootCert)=0;


    virtual BOOLEAN ClearRootCertificate(INT conn_id, const COMM_ROOT_CERT *pRootCert)=0;


    virtual BOOLEAN ReadRootCertificate(INT conn_id, UINT8** certData, UINT32* certLen)=0;


    virtual BOOLEAN ReadUserCertificate(INT conn_id, UINT8** certData, UINT32* certLen, UINT8** certKey,UINT32* certKeyLen)=0;


    virtual BOOLEAN AddUserCertificate(INT conn_id, const COMM_USER_CERT *pUserCert)=0;


    virtual BOOLEAN ClearUserCertificate(INT conn_id, const COMM_USER_CERT *pUserCert)=0;

    virtual BOOLEAN GetCipherSuiteName (INT conn_id, const UINT8** pCipherSuiteName) = 0;

};


#endif  



