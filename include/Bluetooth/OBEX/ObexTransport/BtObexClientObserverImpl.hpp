
#if !defined(Apoxi_BtObexClientObserverImpl_hpp)
#define Apoxi_BtObexClientObserverImpl_hpp

#include <Bluetooth/OBEX/BtObexClientServiceObserver.hpp>
#include <Obex/ObexObject.hpp>
#include <Obex/ObexBuffer.hpp>
class BtObexImpl;

class BtObexClientObserverImpl: public BtObexClientServiceObserver
{

    typedef BtObexClientServiceObserver Base;

    public:
        BtObexClientObserverImpl();

        virtual ~BtObexClientObserverImpl();

    protected:

        virtual void OnRegister(BtResultCode code);


        virtual void OnResponse(BtResultCode code, UINT8 response_code);


        virtual void OnUnregister(BtResultCode result);


        virtual void OnHeader(BtResultCode result, const BtObexHeader& header);


        virtual void OnHeaderSent( BtResultCode resul ){}; //unuseful for Client, ignore


        virtual void OnDataRequested(BtResultCode result);


        virtual void OnBufferRequested(BtResultCode result, UINT16 last_buffer_filled, BOOLEAN delete_object, BOOLEAN create_empty_object);


        virtual void OnTransportDisconnect(BtResultCode result); //cannot be implemented before controller availability, lack of specification


        virtual void OnError(BtObexErrorCode error){}; //cannot be implemented before controller availability, lack of specification

        //New Interface. Under evaluation, remapping on the OnResponse only?
        virtual void OnConnect(BtResultCode code, UINT8 response_code);


        virtual void OnDisconnect(BtResultCode code, UINT8 response_code);


        virtual void OnSetPath(BtResultCode code, UINT8 response_code);


        virtual void OnGet(BtResultCode code, UINT8 response_code);


        virtual void OnPut(BtResultCode code, UINT8 response_code);


        virtual void OnAbort(BtResultCode code, UINT8 response_code);


    private:


        inline void SetIndex( UINT8 id ) { m_id = id; };

        void ResetObserverInstance();

        void AllocateResponseObexBufferIfNeeded();

        UINT8 m_id;

        UINT32 m_req_buf_byte_read;

        ObexObject m_curr_resp_obj;

        ObexBuffer m_curr_resp_buf;

        friend class BtObexImpl; 

};

#endif

