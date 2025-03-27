/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtRequest_hpp)
#define BtRequest_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Bluetooth/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtController;

class BtRequest
{
    public:
        BtRequest();

        virtual ~BtRequest();


        virtual BtRequestType GetRequestType() const = 0;


        BtRequestState GetRequestState() const;


        UINT32 GetRequestId() const;


        virtual BOOLEAN CanExecuteRequest() const;


        virtual BtRequestState ExecuteRequest() = 0;


        virtual BOOLEAN IsCancelable() const = 0;


        virtual BOOLEAN CanCancelRequest() const;


        BtRequestState CancelRequest();

    protected:

        virtual void SetRequestState(BtRequestState request_state) = 0;


        virtual void ResetRequestState();


        virtual BOOLEAN Execute() = 0;


        virtual BOOLEAN Cancel() = 0;


        virtual BtRequestState ChangeRequestState(BOOLEAN success);


        virtual BtRequestState ChangeRequestStateForCancel(BOOLEAN success);


        virtual BOOLEAN EvaluateExecutionResult(BtResultCode result);


        virtual void ExecutionCallback(BtResultCode result) = 0;

    protected:
        BtRequestState m_state;

        Mutex m_is_registered_mutex;

    private:
        friend class BtController;
};

#endif  // BtRequest_hpp


