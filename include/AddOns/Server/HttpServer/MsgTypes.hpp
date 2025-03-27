/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "working\_views\Oberhube_server_FTP_HTTP_sv\lnz_apoxi\Apoxi\AddOns\Server\HttpServer\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Server_HttpServer_MsgTypes_hpp)
#define AddOns_Server_HttpServer_MsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Socket/InetSocketAddr.hpp>
#include <Socket/DataConnProfile.hpp>
#include <AddOns/Server/HttpServer/HttpTypes.hpp>
#include <AddOns/Server/HttpServer/HttpRequest.hpp>
#include <AddOns/Server/HttpServer/HttpSocket.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class HttpServiceMessage
    ====================================================================== */

class HttpServiceMessage : public Message {
    public:
        HttpServiceMessage(const HttpServiceCommand& cmd, const InetSocketAddr& socketAddr = InetSocketAddr(), const DataConnProfileId& dataConnProfileId = c_invalid_data_conn_profile_id);
        virtual ~HttpServiceMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const HttpServiceCommand& GetCmd() const { return m_cmd; }
        const InetSocketAddr& GetSocketAddr() const { return m_socketAddr; }
        const DataConnProfileId& GetDataConnProfileId() const { return m_dataConnProfileId; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4510
            };
        
    private:
        static const MsgMetaData m_meta_data;
        HttpServiceCommand m_cmd;
        InetSocketAddr m_socketAddr;
        DataConnProfileId m_dataConnProfileId;
        
    };


/*  ======================================================================
    Class HttpErrorMessage
    ====================================================================== */

class HttpErrorMessage : public Message {
    public:
        HttpErrorMessage(const HttpServiceCommand& cmd, const HttpServiceCommandError& code);
        virtual ~HttpErrorMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const HttpServiceCommand& GetCmd() const { return m_cmd; }
        const HttpServiceCommandError& GetCode() const { return m_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4511
            };
        
    private:
        static const MsgMetaData m_meta_data;
        HttpServiceCommand m_cmd;
        HttpServiceCommandError m_code;
        
    };


/*  ======================================================================
    Class HttpRequestMessage
    ====================================================================== */

class HttpRequestMessage : public Message {
    public:
        HttpRequestMessage(UINT clientId, const HttpRequest& httpRequest);
        virtual ~HttpRequestMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT GetClientId() const { return m_clientId; }
        const HttpRequest& GetHttpRequest() const { return m_httpRequest; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4512
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT m_clientId;
        HttpRequest m_httpRequest;
        
    };


/*  ======================================================================
    Class HttpConnectMessage
    ====================================================================== */

class HttpConnectMessage : public Message {
    public:
        HttpConnectMessage(const InetSocketAddr& peerAddr, const HttpSocketPtr& peerSocket);
        virtual ~HttpConnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const InetSocketAddr& GetPeerAddr() const { return m_peerAddr; }
        const HttpSocketPtr& GetPeerSocket() const { return m_peerSocket; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4513
            };
        
    private:
        static const MsgMetaData m_meta_data;
        InetSocketAddr m_peerAddr;
        HttpSocketPtr m_peerSocket;
        
    };


/*  ======================================================================
    Class HttpDisconnectMessage
    ====================================================================== */

class HttpDisconnectMessage : public Message {
    public:
        HttpDisconnectMessage(UINT clientId);
        virtual ~HttpDisconnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT GetClientId() const { return m_clientId; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4514
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT m_clientId;
        
    };

#endif // AddOns_Server_HttpServer_MsgTypes_hpp

