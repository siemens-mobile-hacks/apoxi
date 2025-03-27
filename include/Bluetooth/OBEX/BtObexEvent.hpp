/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexEvent_hpp)
#define BtObexEvent_hpp

#include <Bluetooth/BtEvent.hpp>
#include <Bluetooth/OBEX/BtTypes.hpp>

class BtObexEvent: public BtEvent
{
    private:
        typedef BtEvent Base;

    public:
        BtObexEvent(BtResultCode result);

        virtual ~BtObexEvent();
};

class BtObexUnregisterEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexUnregisterEvent(BtResultCode result);

        virtual ~BtObexUnregisterEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 1 };
};

class BtObexHeaderIndicationEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexHeaderIndicationEvent(BtResultCode result, const BtObexHeader& header);

        virtual ~BtObexHeaderIndicationEvent();


        const BtObexHeader& GetHeader() const;

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 2 };

    private:
        const BtObexHeader& m_header;
};

class BtObexHeaderSentEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexHeaderSentEvent(BtResultCode result);

        virtual ~BtObexHeaderSentEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 3 };
};

class BtObexDataBufferIndicationEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexDataBufferIndicationEvent(BtResultCode result, UINT16 last_buffer_filled, BOOLEAN delete_object, BOOLEAN create_empty_object);

        virtual ~BtObexDataBufferIndicationEvent();


        UINT16 GetLastBufferFilled() const;


        BOOLEAN GetDeleteObect() const;


        BOOLEAN GetCreateEmptyObject() const;

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 4 };

    private:
        UINT16 m_last_buffer_filled;

        BOOLEAN m_delete_object;

        BOOLEAN m_create_empty_object;
};

class BtObexDataIndicationEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexDataIndicationEvent(BtResultCode result);

        virtual ~BtObexDataIndicationEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 5 };
};

class BtObexTransportDisconnectEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexTransportDisconnectEvent(BtResultCode result);

        virtual ~BtObexTransportDisconnectEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 6 };
};

class BtObexServerEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexServerEvent(BtResultCode result);

        virtual ~BtObexServerEvent();
};

class BtObexRegisterServerEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexRegisterServerEvent(BtResultCode result, UINT8 rfcom_channel);

        virtual ~BtObexRegisterServerEvent();


        UINT8 GetRfComChannel() const;

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 7 };

    private:
        UINT8 m_rfcom_channel;
};

class BtObexServerConnectIndicationEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexServerConnectIndicationEvent(BtResultCode result, const BtDevice& device);

        virtual ~BtObexServerConnectIndicationEvent();


        const BtDevice& GetDevice() const;

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 8 };

    private:
        BtDevice m_device;
};

class BtObexServerDisconnectIndicationEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexServerDisconnectIndicationEvent(BtResultCode result);

        virtual ~BtObexServerDisconnectIndicationEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 9 };
};


class BtObexServerSetPathIndicationEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexServerSetPathIndicationEvent(BtResultCode result, BOOLEAN backup, BOOLEAN create);

        virtual ~BtObexServerSetPathIndicationEvent();

    public:

        virtual UINT16 GetId() const;


        BOOLEAN GetBackup() const;


        BOOLEAN GetCreate() const;

    public:
        enum { ID = 10 };

    private:
        BOOLEAN m_backup;

        BOOLEAN m_create;
};

class BtObexServerGetIndicationEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexServerGetIndicationEvent(BtResultCode result);

        virtual ~BtObexServerGetIndicationEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 11 };
};

class BtObexServerPutIndicationEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexServerPutIndicationEvent(BtResultCode result);

        virtual ~BtObexServerPutIndicationEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 12 };
};

class BtObexServerAbortIndicationEvent: public BtObexServerEvent
{
    private:
        typedef BtObexServerEvent Base;

    public:
        BtObexServerAbortIndicationEvent(BtResultCode result);

        virtual ~BtObexServerAbortIndicationEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 13 };
};

class BtObexClientEvent: public BtObexEvent
{
    private:
        typedef BtObexEvent Base;

    public:
        BtObexClientEvent(BtResultCode result);

        virtual ~BtObexClientEvent();
};

class BtObexRegisterClientEvent: public BtObexClientEvent
{
    private:
        typedef BtObexClientEvent Base;

    public:
        BtObexRegisterClientEvent(BtResultCode result);

        virtual ~BtObexRegisterClientEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 14 };

    private:
        UINT8 m_rfcom_channel;
};

class BtObexClientOperationEvent: public BtObexClientEvent
{
    private:
        typedef BtObexClientEvent Base;

    public:
        BtObexClientOperationEvent(BtResultCode result, UINT8 response_code);

        virtual ~BtObexClientOperationEvent();

    public:

        UINT8 GetResponseCode() const;

    private:
        UINT8 m_response_code;
};

class BtObexClientConnectEvent: public BtObexClientOperationEvent
{
    private:
        typedef BtObexClientOperationEvent Base;

    public:
        BtObexClientConnectEvent(BtResultCode result, UINT8 response_code);

        virtual ~BtObexClientConnectEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 15 };
};

class BtObexClientDisconnectEvent: public BtObexClientOperationEvent
{
    private:
        typedef BtObexClientOperationEvent Base;

    public:
        BtObexClientDisconnectEvent(BtResultCode result, UINT8 response_code);

        virtual ~BtObexClientDisconnectEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 16 };
};

class BtObexClientSetPathEvent: public BtObexClientOperationEvent
{
    private:
        typedef BtObexClientOperationEvent Base;

    public:
        BtObexClientSetPathEvent(BtResultCode result, UINT8 response_code);

        virtual ~BtObexClientSetPathEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 17 };
};

class BtObexClientGetEvent: public BtObexClientOperationEvent
{
    private:
        typedef BtObexClientOperationEvent Base;

    public:
        BtObexClientGetEvent(BtResultCode result, UINT8 response_code);

        virtual ~BtObexClientGetEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 18 };
};

class BtObexClientPutEvent: public BtObexClientOperationEvent
{
    private:
        typedef BtObexClientOperationEvent Base;

    public:
        BtObexClientPutEvent(BtResultCode result, UINT8 response_code);

        virtual ~BtObexClientPutEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 19 };
};

class BtObexClientAbortEvent: public BtObexClientOperationEvent
{
    private:
        typedef BtObexClientOperationEvent Base;

    public:
        BtObexClientAbortEvent(BtResultCode resul, UINT8 response_code);

        virtual ~BtObexClientAbortEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 20 };
};

#endif  // BtObexEvent_hpp


