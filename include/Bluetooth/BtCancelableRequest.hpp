/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtCancelableRequest_hpp)
#define BtCancelableRequest_hpp

#include <Bluetooth/BtLocalRequest.hpp>

class BtCancelableRequest: public BtLocalRequest
{
    private:
        typedef BtLocalRequest Base;

    public:
        BtCancelableRequest();

        virtual ~BtCancelableRequest();


        virtual BOOLEAN IsCancelable() const;
};

#endif  // BtCancelableRequest_hpp


