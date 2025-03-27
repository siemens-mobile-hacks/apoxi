/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSingleConnectionController_hpp)
#define BtSingleConnectionController_hpp

#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtConnectionBasedController.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations
    ------------------------------------------------------------------------ */

class BtConnectRequest;
class BtDisconnectRequest;

class BtSingleConnectionController: public BtConnectionBasedController
{
    private:
        typedef BtConnectionBasedController Base;

    public:
        BtSingleConnectionController();

        virtual ~BtSingleConnectionController();

    protected:

        virtual BOOLEAN IsDeviceConnected(const BtDevice& device) const;


        const BtDevice& GetConnectedDevice() const;


        BOOLEAN SetConnectedDevice(const BtDevice& connected_device);


        void ClearConnectedDevice();


        BOOLEAN ConnectRequest(BtConnectRequest* connect_request);


        BOOLEAN DisconnectRequest(BtDisconnectRequest* disconnect_request);


        BtServiceRequest* GetExecutingRequest() const;


        BOOLEAN PrepareRequestExecution(BtServiceRequest* request);


        BtServiceRequest* CleanUpRequestExecution(BtResultCode result_code, BtRequestType request_type);

    private:
        Mutex m_connected_device_mutex;

        BtDevice m_connected_device;

        Mutex m_executing_request_mutex;

        BtServiceRequest* m_executing_request;
};

#endif  // BtSingleConnectionController_hpp


