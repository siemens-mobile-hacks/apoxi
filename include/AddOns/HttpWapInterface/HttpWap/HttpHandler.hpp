/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifndef HttpHandler_hpp
#define HttpHandler_hpp


#include <Kernel/UserDispatcher.hpp>
#include <Auxiliary/BinData.hpp>
#include <Auxiliary/WString.hpp>



#ifdef APOXI_WAP_STACK
#include <Wap/Main/WapService.hpp>
#include <Wap/Main/BrowserMsgTypes.hpp>
#endif //APOXI_WAP_STACK
#include "HttpWapMgrBase.hpp"


/*
 * forward declarations
 */
class Message;
class HttpWapMgr;





class HttpHandler : public UserDispatcher  {


public:

  enum HttpConnStatus {
  HttpConnError,
  HttpConnClosed,
  HttpConnOpen,
  HttpConnSuspended
};
    
     HttpHandler();

        virtual ~HttpHandler();
    

#if defined(APOXI_COMPAT_2_3_0)
        virtual BOOLEAN HttpOpen(INT id);
#else
        virtual BOOLEAN OpenHttp(INT id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
        virtual BOOLEAN HttpRequestGet(INT& requ_id, const CHAR* URL,
                                       const CHAR* header);
#else                       
        virtual BOOLEAN RequestGetHttp(INT& requ_id, const CHAR* URL,
                                       const CHAR* header);
#endif                         


#if defined(APOXI_COMPAT_2_3_0)
         virtual BOOLEAN HttpRequestHead(INT& requ_id, const CHAR* URL,
                                         const CHAR* header);
#else                            
         virtual BOOLEAN RequestHeadHttp(INT& requ_id, const CHAR* URL,
                                         const CHAR* header);
#endif                           


#if defined(APOXI_COMPAT_2_3_0)    
         virtual BOOLEAN HttpRequestPost(INT& requ_id,
                                         const CHAR* URL, 
                                         const CHAR* header, 
                                         BinData* body, 
                                         INT more);
#else                    
         virtual BOOLEAN RequestPostHttp(INT& requ_id,
                                         const CHAR* URL, 
                                         const CHAR* header, 
                                         BinData* body, 
                                         INT more);
#endif


#if defined(APOXI_COMPAT_2_3_0) 
           virtual BOOLEAN HttpRequestPostData(INT& request_id,
                                               BinData* body, 
                                               INT more);
#else                          
           virtual BOOLEAN RequestPostDataHttp(INT& request_id,
                                               BinData* body, 
                                               INT more);
#endif                         


#if defined(APOXI_COMPAT_2_3_0) 
         virtual BOOLEAN HttpCancel(INT requ_id);
#else         
         virtual BOOLEAN CancelHttp(INT requ_id);
#endif         


#if defined(APOXI_COMPAT_2_3_0)     
      virtual BOOLEAN HttpClose();
#else     
      virtual BOOLEAN CloseHttp();
#endif    


#if defined(APOXI_COMPAT_2_3_0)     
       virtual BOOLEAN HttpSuspend();
#else      
       virtual BOOLEAN SuspendHttp();
#endif


#if defined(APOXI_COMPAT_2_3_0)      
       virtual BOOLEAN HttpResume();
#else     
       virtual BOOLEAN ResumeHttp();
#endif              


#if defined(APOXI_COMPAT_2_3_0) 
       virtual INT HttpGetConnId();
#else
       virtual INT GetConnIdHttp();
#endif  


#if defined(APOXI_COMPAT_2_3_0) 
        virtual HttpConnStatus HttpGetConnStatus();
#else   
        virtual HttpConnStatus GetConnStatusHttp();
#endif        
#ifdef APOXI_WAP_STACK
    /*CN200014015: Change request to return Get Secure session info 
    By Markus Dannel(Java Team) */
#if defined(APOXI_COMPAT_2_3_0)
       virtual BOOLEAN HttpGetSessionInfo(INT& request_id);
#else
       virtual BOOLEAN GetSessionInfoHttp(INT& request_id);
#endif        
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


    virtual BOOLEAN OnMessage(const Message& msg)=0 ;


    virtual BOOLEAN OnResponse(const Message& msg)=0;

#ifdef APOXI_WAP_STACK

    virtual BOOLEAN DecodeGetSessionInfoResponseMessage(const Message& msg,
                                                        INT& result,
                                                        INT& conn_id,
                                                        INT& connection_type,
                                                        String& cipher_info,
                                             CertificateInfo_t& certificate);
#endif //APOXI_WAP_STACK

    
private:

    INT m_conn_id;
    
    HttpConnStatus m_conn_status;

    HttpWapMgr* m_http_wap_mgr;


      BOOLEAN SetHttpResponseReceived(const CHAR* header, 
                                      const BinData* body) ;


#if defined(APOXI_COMPAT_2_3_0)
    BOOLEAN HttpSetConnId(INT conn_id);
#else
    BOOLEAN SetConnIdHttp(INT conn_id);
#endif


#if defined(APOXI_COMPAT_2_3_0)
    BOOLEAN HttpSetConnStatus(HttpConnStatus status);
#else
    BOOLEAN SetConnStatusHttp(HttpConnStatus status);
#endif


};

#endif  // HttpHandler_hpp


