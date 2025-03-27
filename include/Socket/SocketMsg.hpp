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
    defined in "linz\socket_dev\src\Apoxi\Socket\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(SocketMsg_hpp__ST_1044273316690)
#define SocketMsg_hpp__ST_1044273316690

#include <Kernel/Message.hpp>
#include <Socket/SocketTypes.hpp>
#include <Asc/PdpContext.hpp>
#include <Asc/Types.hpp>

class ExecutionContext;
class SocketData;
class Socket;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class SocketControlMsg
    ====================================================================== */

class SocketControlMsg : public ContextMsg {
    public:
        SocketControlMsg(ExecutionContext* context, UINT32 msg_id, SocketData* socket_data, const SocketControlMsgType& control_type);
        SocketControlMsg(ExecutionContext* context, UINT32 msg_id, Socket* socket, const SocketControlMsgType& control_type);
        virtual ~SocketControlMsg();

        virtual const MsgMetaData& GetMetaData() const;
        UINT32 GetMsgId() const { return m_msg_id; }
        void SetSocketData(SocketData* socket_data) { m_socket_data = socket_data; }
        SocketData* GetSocketData() const { return m_socket_data; }
        Socket* GetSocket() const;
        void SetControlType(const SocketControlMsgType& control_type) { m_control_type = control_type; }
        const SocketControlMsgType& GetControlType() const { return m_control_type; }
        virtual Message* Clone() const;

        enum {
            ID = 19101
            };

    private:
        static const MsgMetaData m_meta_data;
        UINT32 m_msg_id;
        SocketData* m_socket_data;
        Socket* m_socket;
        SocketControlMsgType m_control_type;

    };

/*  ======================================================================
    Class DataConnInfoMsg
    ====================================================================== */
class DataConnInfoMsg : public Message {
    public:
        DataConnInfoMsg(const DataConnInfoMsgType& type,
            const DataConnProfileId& profile,
            DcError csd_err = NoCallError,
            CallApiRc csd_dial_err = NoError,
            PdpContext::ErrorCause psd_err = PdpContext::NoError);
        virtual ~DataConnInfoMsg();

        virtual const MsgMetaData& GetMetaData() const;
        void SetType(const DataConnInfoMsgType& type) { m_type = type; }
        const DataConnInfoMsgType& GetType() const { return m_type; }
        void SetProfile(const DataConnProfileId& profile) { m_profile = profile; }
        const DataConnProfileId& GetProfile() const { return m_profile; }
        virtual Message* Clone() const;
        DcError GetCsdError() { return m_csd_err; }
        CallApiRc GetCsdDialError() { return m_csd_dial_err; }
        PdpContext::ErrorCause GetPsdError() { return m_psd_err; }

        enum {
            ID = 19102
            };

    private:
        static const MsgMetaData m_meta_data;
        DataConnInfoMsgType m_type;
        DataConnProfileId m_profile;
        DcError m_csd_err;
        PdpContext::ErrorCause m_psd_err;
        CallApiRc m_csd_dial_err;
    };

/*  ======================================================================
    Class DataConnProfileInfoMsg
    ====================================================================== */
class DataConnProfileInfoMsg : public Message {
    public:
        DataConnProfileInfoMsg(const DataConnProfileInfoMsgType& type, const DataConnProfileId& profileId, const WString& profileName, BOOLEAN temporaryProfile);
        virtual ~DataConnProfileInfoMsg();

        virtual const MsgMetaData& GetMetaData() const;
        void SetType(const DataConnProfileInfoMsgType& type) { m_type = type; }
        const DataConnProfileInfoMsgType& GetType() const { return m_type; }
        void SetProfileId(const DataConnProfileId& profileId) { m_profileId = profileId; }
        const DataConnProfileId& GetProfileId() const { return m_profileId; }
        void SetProfileName(const WString& profileName) { m_profileName = profileName; }
        const WString& GetProfileName() const { return m_profileName; }
        void SetTemporaryProfile(BOOLEAN temporaryProfile) { m_temporaryProfile = temporaryProfile; }
        BOOLEAN IsTemporaryProfile() const { return m_temporaryProfile; }
        virtual Message* Clone() const;

        enum  {
            ID = 19103
            };

    private:
        static const MsgMetaData m_meta_data;
        DataConnProfileInfoMsgType m_type;
        DataConnProfileId m_profileId;
        WString m_profileName;
        BOOLEAN m_temporaryProfile;

    };

#endif // SocketMsg_hpp__ST_1044273316690

