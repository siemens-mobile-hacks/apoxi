/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexClientOperationRequest_hpp)
#define BtObexClientOperationRequest_hpp

#include <Bluetooth/OBEX/BtObexRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexController;

class BtObexClientOperationRequest: public BtObexRequest
{
    private:
        typedef BtObexRequest Base;

    public:
        BtObexClientOperationRequest(BtObexService& obex_service);

        virtual ~BtObexClientOperationRequest();

    public:

        UINT8 GetResponseCode() const;


        void SetResponseCode(UINT8 response_code);


        BOOLEAN GetAborted() const;

    protected:

        virtual BOOLEAN GetAcceptAbort() const;


        void SetAborted(BOOLEAN aborted);

    private:
        UINT8 m_response_code;

        BOOLEAN m_aborted;

    private:
        friend class BtObexController;
};

#endif  // BtObexClientOperationRequest_hpp

