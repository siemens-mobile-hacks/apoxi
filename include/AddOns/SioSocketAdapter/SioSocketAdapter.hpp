/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SioSocketAdapter_hpp)
#define Apoxi_SioSocketAdapter_hpp

#include <AddOns/SerialSocket/SerialIoAdapter.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include "IrSocketAddr.hpp"

class SerialServerSocket;
class SerialClientSocket;

typedef NiSharedPtr<SerialServerSocket> SerialServerSocketPtr;
typedef NiSharedPtr<SerialClientSocket> SerialClientSocketPtr;

class SioSocketAdapter
{
    private:
        enum {
            /* 0 .. (c_sioadapter_max_sockets - 1)                            -> server socket
               c_sioadapter_max_sockets .. (2 * c_sioadapter_max_sockets - 1) -> client socket
               else                                                           -> invalid
             */
            c_sioadapter_max_sockets = 8,
            c_sioadapter_invalid_sock_id = 2 * c_sioadapter_max_sockets
        };

        class SerialServerSockEventListener : public SocketEventListener {
            virtual void OnSocketEvent(Socket::Event event, Socket *socket);
        };

        class SerialClientSockEventListener : public SocketEventListener {
            virtual void OnSocketEvent(Socket::Event event, Socket *socket);
        };
        
        friend class SioSocketAdapter::SerialClientSockEventListener;
        friend class SioSocketAdapter::SerialServerSockEventListener;

        // Forbid construction.
        SioSocketAdapter();
        // Forbid destruction.
        ~SioSocketAdapter();

    public:
        typedef INT8 SocketId;
        typedef UINT16 IrdaParams;

        typedef void (*SimpleCb)(SocketId sock_id, INT32 result);
        typedef void (*AcceptCb)(SocketId sock_id, INT32 result, SocketId client_sock_id);

        struct SioSocketCallbacks {
    //      SimpleCb m_close_cnf_cb;
    //      SimpleCb m_listen_cnf_cb;
    //???       AcceptCb m_accept_cnf_cb;
            SimpleCb m_connect_ind_cb;       //Server only
            SimpleCb m_disconnect_ind_cb;
            SimpleCb m_connect_cnf_cb;       //Client only
            SimpleCb m_write_cnf_cb;         //Data successfully written
    //      SimpleCb m_read_cnf_cb;
    //      SimpleCb m_send_data_cnf_cb;
            SimpleCb m_data_available_ind_cb;   //You can/shall read data now
        };

        static void Init(const SioSocketCallbacks &callbacks);

        static SocketId Create(SerialIoAdapter::SocketFamily fam, INT protocol,
            const SocketAddr *address = 0, BOOLEAN is_server = FALSE);

        static void Close(SocketId sock_id);

        static BOOLEAN Listen(SocketId sock_id, INT backlog);

        static SocketId Accept(SocketId sock_id, SocketAddr &client_addr);

        static BOOLEAN Connect(SocketId sock_id, SocketAddr &serv_addr);

// TO DO set these parameters before Connect()
// !!!!!        UINT32 idType, const IrdaParams *pAttr = 0, const CHAR *pIas = 0, UINT32 iasLength = 0);

        static UINT32 Write(SocketId sock_id, const UINT8 *pDataBuf, UINT32 dataSize);

        static UINT32 Read(SocketId sock_id, UINT8 *pReadBuf, UINT32 readSize);

        // todo: comments: really needed???
//      static INT IoCtl(INT requestcode, INT argument);

        static INT OptGet(INT optname, void *optval, INT &optlen);

        static INT OptSet(INT optname, const void *optval, INT optlen);

        // TO DO set these parameters before Connect()
        // !!!!!        UINT32 idType, const IrdaParams *pAttr = 0, const CHAR *pIas = 0, UINT32 iasLength = 0);



    private:
        static SocketId GetSocketIdBySerialSocket(const Socket &socket);
        static SocketId GetNextFreeSocketId(BOOLEAN is_server);
        
        static const SioSocketCallbacks *s_sock_cbs;

        static SerialServerSocketPtr m_server_socket[c_sioadapter_max_sockets];
        static SerialClientSocketPtr m_client_socket[c_sioadapter_max_sockets];
        static SerialServerSockEventListener m_socket_event_listener;
//      static IrdaSocketAddr *m_rfCommAddr;
//      static L2CapSocketAddr *m_l2capAddr;
};




/* Instruction, how to set IrDA-Hint Bits, from Headerfile \Apoxi\Irda\IrdaTransport.hpp:

//      void SetHintBits(UINT byte_offset, UINT8 bit_mask) const;

//      void ClearHintBits(UINT byte_offset, UINT8 bit_mask) const;

/* Example Code:
  #include <Irda/IrdaTransport.hpp>

  IrdaTransport::GetInstance().SetHintBits  (byte_offset, bit_mask); //byte_offset = 0..1
  IrdaTransport::GetInstance().ClearHintBits(byte_offset, bit_mask); //byte_offset = 0..1
        
          
            
              
*/


// TODO: obsolete or into own headerfile:
/*
struct IrdaParams {
    UINT16 irda_hintbits;
};
*/

//      void SetIrdaSocketParams(SocketId sock_id, IrdaParams *pAttr, const UINT8 *pIas, UINT32 iasLength);



#endif  //Apoxi_SioSocketAdapter_hpp

