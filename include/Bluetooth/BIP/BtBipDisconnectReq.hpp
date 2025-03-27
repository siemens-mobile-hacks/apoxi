/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipDisconnectReq_hpp)
#define BtBipDisconnectReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipDisconnectReq: public BtBipReq
{
    private:
        typedef BtBipReq Base;

    public:
        BtBipDisconnectReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipDisconnectReq();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


//      virtual void ExecutionCallback(BtResultCode result);

    private:

        friend class BtBipController;
};

#endif

#endif  // BtBipDisconnectReq_hpp

