/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtServiceRequest_hpp)
#define BtServiceRequest_hpp

#include <Kernel/Os/Os.hpp>
#include <Bluetooth/BtRequest.hpp>
#include <Bluetooth/BtService.hpp>

class BtServiceRequest: public BtRequest
{
    private:
        typedef BtRequest Base;

    public:

        BtServiceRequest(BtService &service);

        virtual ~BtServiceRequest();


        const BtService& GetService() const;


        BtService& GetService();


        virtual BtRequestState ExecuteRequest();


        virtual BOOLEAN IsCancelable() const;

    protected:

        virtual void SetRequestState(BtRequestState request_state);


        virtual BOOLEAN Cancel();


        virtual void ExecutionCallback(BtResultCode result);

    private:
        BtService& m_service;

        Semaphore m_execution_semaphore;

    private:
        friend class BtController;
};

#endif  // BtServiceRequest_hpp


