/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAvrcpConnectResponse_hpp)
#define BtAvrcpConnectResponse_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */
class BtAvrcpOperationService;
class BtAvrcpOperationController;


class BtAvrcpConnectResponse : public BtAvrcpRequest
{
    private:
        typedef BtAvrcpRequest Base;

    public:
        BtAvrcpConnectResponse(BtAvrcpOperationService& avrcp_service);

        void SetBtapiHandle(btapi_avrcp_handle_t hdl) { m_hdl = hdl; };

        virtual ~BtAvrcpConnectResponse();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();

    private:
        btapi_avrcp_handle_t GetApiSettings() { return m_hdl; };
        btapi_avrcp_handle_t m_hdl;
    
    private:
        friend class BtAvrcpOperationService;
        friend class BtAvrcpOperationController;


};

#endif  // BtAvrcpConnectResponse_hpp

