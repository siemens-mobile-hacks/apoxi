/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtFaxService_hpp)
#define BtFaxService_hpp

#include <Bluetooth/BtService.hpp>
#include <Bluetooth/FAX/BtFaxDisconnectRequest.hpp>

class BtFaxService: public BtService
{
    private:
        typedef BtService Base;

    public:
        BtFaxService();

        virtual ~BtFaxService();


        virtual BtProfile GetProfile() const;


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        BOOLEAN IsConnected() const;


        BtRequestState DisconnectRequest();

    protected:

        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);

    private:
        BtFaxDisconnectRequest m_fax_disconnect_request;

        BOOLEAN m_dispatcher_added;
};

#endif  // BtFaxService_hpp


