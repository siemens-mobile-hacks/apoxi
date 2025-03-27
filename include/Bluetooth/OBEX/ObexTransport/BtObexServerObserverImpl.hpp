
#if !defined(Apoxi_BtObexServerObserverImpl_hpp)
#define Apoxi_BtObexServerObserverImpl_hpp

#include <Bluetooth/OBEX/BtObexServerServiceObserver.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Obex/ObexObject.hpp>
#include <Obex/ObexBuffer.hpp>


class BtObexImpl;
class BtObexServerObserverImpl: public BtObexServerServiceObserver
{

    typedef BtObexServerServiceObserver Base;

    public:
        BtObexServerObserverImpl();

        virtual ~BtObexServerObserverImpl();

        inline void SetIndex( UINT8 id ) { m_id = id; };

    protected:

        virtual void OnRegister(BtResultCode code, UINT8 rfcom_channel);


        virtual void OnConnect(BtResultCode code, const BtDevice& device);


        virtual void OnDisconnect(BtResultCode code);


        virtual void OnSetPath(BtResultCode code, BOOLEAN backup, BOOLEAN create);


        virtual void OnGet(BtResultCode code);


        virtual void OnPut(BtResultCode code);


        virtual void OnAbort(BtResultCode code);


        virtual void OnHeaderSent(BtResultCode result);


        virtual void OnUnregister(BtResultCode result) ;


        virtual void OnHeader(BtResultCode result, const BtObexHeader& header);


        virtual void OnDataRequested(BtResultCode result);


        virtual void OnBufferRequested(BtResultCode result, UINT16 last_buffer_filled, BOOLEAN delete_object, BOOLEAN create_empty_object);


        virtual void OnTransportDisconnect(BtResultCode result); //cannot be implemented before controller availability, lack of specification


        virtual void OnError(BtObexErrorCode error){}; //cannot be implemented before controller availability, lack of specification

    private:

        void ResetObserverInstance();

        void AllocateIncomingObexBufferIfNeeded();

        UINT8 m_id;

        ObexObject m_incoming_obj;

        ObexBuffer m_incoming_buf;

        UINT32 m_buf_byte_read;

        friend class BtObexImpl; 

};

#endif

