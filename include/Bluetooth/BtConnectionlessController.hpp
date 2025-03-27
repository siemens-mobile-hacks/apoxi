/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtConnectionlessController_hpp)
#define BtConnectionlessController_hpp

#include <Bluetooth/BtController.hpp>
#include <Bluetooth/BtServiceRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtConnectionlessController: public BtController
{
    private:
        typedef BtController Base;

    public:
        BtConnectionlessController();

        virtual ~BtConnectionlessController();


        virtual UINT8 GetPriority() const;

    protected:

        virtual void Init();


        virtual btapi_userid_t GetUserId() const;


        virtual btapi_cb_funp_t* GetCallbackFunctionPointers() const;


        BtServiceRequest* GetExecutingRequest() const;


        BOOLEAN PrepareRequestExecution(BtServiceRequest* request);


        BtServiceRequest* CleanUpRequestExecution(BtResultCode result_code, BtRequestType request_type);

    private:
        Mutex m_executing_request_mutex;

        BtServiceRequest* m_executing_request;
    private:
        friend class BtGapAndSdapController;
};

#endif  // BtConnectionlessController_hpp

