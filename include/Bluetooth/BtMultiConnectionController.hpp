/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtMultiConnectionController_hpp)
#define BtMultiConnectionController_hpp

#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtConnectionBasedController.hpp>

class BtMultiConnectionController: public BtConnectionBasedController
{
    private:
        typedef BtConnectionBasedController Base;

    public:
        BtMultiConnectionController();

        virtual ~BtMultiConnectionController();

    protected:
        virtual BOOLEAN IsDeviceConnected(const BtDevice& device) const;


//      BtServiceRequest* GetExecutingRequest() const;


        BOOLEAN PrepareRequestExecution(void* apoxi_handle, BtServiceRequest* request);


    BtServiceRequest* CleanUpRequestExecution(void* apoxi_handle, BtResultCode result_code, BtRequestType request_type);

    public:
        class BtConnection
        {
            public:
                BtConnection();

                virtual ~BtConnection();


                void* GetApoxiHandle() const;


                void SetApoxiHandle(void* apoxi_handle);


                BtServiceRequest* GetRunningRequest() const;


                void SetRunningRequest(BtServiceRequest* request);


                const BtDevice& GetDevice() const;


                void SetDevice(const BtDevice& device);


                BtConnection* GetNext() const;


                void SetNext(BtConnection* next);

            private:
                void* m_apoxi_handle;

                BtDevice m_connected_device;

                BtServiceRequest* m_running_request;

                BtConnection* m_next;
        };

    protected:

        BtConnection* GetFirstConnection() const;


        BtConnection* GetNextConnection(const BtConnection* current) const;


        BOOLEAN InsertConnection(BtConnection* connection_to_insert, const BtConnection* location = 0);


        BtConnection* RemoveConnection(const BtConnection* connection_to_remove);


        BtConnection* FindConnectionByApoxiHandle(const void* apoxi_handle) const;


        BtConnection* FindConnectionByDevice(const BtDevice& device) const;


        BtConnection* FindConnectionByRequest(const BtServiceRequest* request) const;

    protected:
        Mutex m_connection_list_mutex;

    private:
        BtConnection* m_connection_list;
};

#endif  // BtMultiConnectionController_hpp


