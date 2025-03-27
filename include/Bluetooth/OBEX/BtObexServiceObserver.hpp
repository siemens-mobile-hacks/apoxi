/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexServiceObserver_hpp)
#define BtObexServiceObserver_hpp

#include <Bluetooth/BtEvent.hpp>
#include <Bluetooth/BtServiceObserver.hpp>
#include <Bluetooth/OBEX/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexService;

class BtObexServiceObserver: public BtServiceObserver
{
    private:
        typedef BtServiceObserver Base;

    public:
        BtObexServiceObserver();

        virtual ~BtObexServiceObserver();

    protected:

        virtual void OnEvent(const BtEvent& event);


        virtual void OnUnregister(BtResultCode result) = 0;


        virtual void OnHeader(BtResultCode result, const BtObexHeader& header) = 0;


        virtual void OnHeaderSent(BtResultCode result) = 0;


        virtual void OnBufferRequested(BtResultCode result, UINT16 last_buffer_filled, BOOLEAN delete_object, BOOLEAN create_empty_object) = 0;


        virtual void OnDataRequested(BtResultCode result) = 0;


        virtual void OnTransportDisconnect(BtResultCode result) = 0;


        virtual void OnError(BtObexErrorCode error) = 0;

    private:
        friend class BtObexService;
};

#endif  // BtObexServiceObserver_hpp


