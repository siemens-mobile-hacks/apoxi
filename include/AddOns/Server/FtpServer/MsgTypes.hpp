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
    defined in "working\_views\Oberhube_server_FTP_HTTP_sv\lnz_apoxi\Apoxi\AddOns\Server\FtpServer\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(AddOns_Server_FtpServer_MsgTypes_hpp)
#define AddOns_Server_FtpServer_MsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Socket/InetSocketAddr.hpp>
#include <Socket/DataConnProfile.hpp>
#include <AddOns/Server/FtpServer/FtpTypes.hpp>
#include <AddOns/Server/FtpServer/FtpRequest.hpp>
#include <AddOns/Server/FtpServer/FtpSocket.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class FtpServiceMessage
    ====================================================================== */

class FtpServiceMessage : public Message {
    public:
        FtpServiceMessage(const FtpServiceCommand& cmd, const InetSocketAddr& socketAddr = InetSocketAddr(), const DataConnProfileId& dataConnProfileId = c_invalid_data_conn_profile_id);
        virtual ~FtpServiceMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const FtpServiceCommand& GetCmd() const { return m_cmd; }
        const InetSocketAddr& GetSocketAddr() const { return m_socketAddr; }
        const DataConnProfileId& GetDataConnProfileId() const { return m_dataConnProfileId; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4500
            };
        
    private:
        static const MsgMetaData m_meta_data;
        FtpServiceCommand m_cmd;
        InetSocketAddr m_socketAddr;
        DataConnProfileId m_dataConnProfileId;
        
    };


/*  ======================================================================
    Class FtpErrorMessage
    ====================================================================== */

class FtpErrorMessage : public Message {
    public:
        FtpErrorMessage(const FtpServiceCommand& cmd, const FtpServiceCommandError& code);
        virtual ~FtpErrorMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const FtpServiceCommand& GetCmd() const { return m_cmd; }
        const FtpServiceCommandError& GetCode() const { return m_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4501
            };
        
    private:
        static const MsgMetaData m_meta_data;
        FtpServiceCommand m_cmd;
        FtpServiceCommandError m_code;
        
    };


/*  ======================================================================
    Class FtpTransferMessage
    ====================================================================== */

class FtpTransferMessage : public Message {
    public:
        FtpTransferMessage(UINT clientId, const FtpTransferDirection& direction, const FtpTransferError& error);
        virtual ~FtpTransferMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT GetClientId() const { return m_clientId; }
        const FtpTransferDirection& GetDirection() const { return m_direction; }
        const FtpTransferError& GetError() const { return m_error; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4502
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT m_clientId;
        FtpTransferDirection m_direction;
        FtpTransferError m_error;
        
    };


/*  ======================================================================
    Class FtpRequestMessage
    ====================================================================== */

class FtpRequestMessage : public Message {
    public:
        FtpRequestMessage(const FtpRequest& ftpRequest);
        virtual ~FtpRequestMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const FtpRequest& GetFtpRequest() const { return m_ftpRequest; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4503
            };
        
    private:
        static const MsgMetaData m_meta_data;
        FtpRequest m_ftpRequest;
        
    };


/*  ======================================================================
    Class FtpConnectMessage
    ====================================================================== */

class FtpConnectMessage : public Message {
    public:
        FtpConnectMessage(const InetSocketAddr& peerAddr, const FtpSocketPtr& peerSocket);
        virtual ~FtpConnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        const InetSocketAddr& GetPeerAddr() const { return m_peerAddr; }
        const FtpSocketPtr& GetPeerSocket() const { return m_peerSocket; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4504
            };
        
    private:
        static const MsgMetaData m_meta_data;
        InetSocketAddr m_peerAddr;
        FtpSocketPtr m_peerSocket;
        
    };


/*  ======================================================================
    Class FtpDisconnectMessage
    ====================================================================== */

class FtpDisconnectMessage : public Message {
    public:
        FtpDisconnectMessage(UINT clientId, const FtpConnectionType& connType = c_ftp_conn_type_control);
        virtual ~FtpDisconnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT GetClientId() const { return m_clientId; }
        const FtpConnectionType& GetConnType() const { return m_connType; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 4505
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT m_clientId;
        FtpConnectionType m_connType;
        
    };

#endif // AddOns_Server_FtpServer_MsgTypes_hpp

