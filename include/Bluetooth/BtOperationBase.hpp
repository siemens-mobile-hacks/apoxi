/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtOperationBase_hpp)
#define BtOperationBase_hpp

#include <Auxiliary/ObjectReferrer.hpp>
#include <Auxiliary/SharedPtr.hpp>
#include <Bluetooth/BtTypes.hpp>

class BtOperationBase: public ReferableObject
{
    private:
        typedef ReferableObject Base;

    public:
        typedef enum { BtErUnknown, BtErUserBreak, BtErOperationResultInvalid, BtErOperationFailure } BtErrorReason;

    public:
        BtOperationBase();

        virtual ~BtOperationBase();

    public:

        virtual BtOperationType GetOperationType() const = 0;


        BtResultCode GetResult() const;


        void SetResult(BtResultCode result, BtErrorReason error_reason = BtErUnknown);


        BtErrorReason GetErrorReason() const;


        void SetErrorReason(BtErrorReason error_reason);

    protected:

        virtual void OnResult(BtResultCode result) = 0;

    private:
        BtResultCode m_result;

        BtErrorReason m_error_reason;
};

typedef SharedPtr<BtOperationBase> BtOperationPtr;

#endif // BtOperationBase_hpp

