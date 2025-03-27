/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtUncancelableRequest_hpp)
#define BtUncancelableRequest_hpp

#include <Bluetooth/BtLocalRequest.hpp>

class BtUncancelableRequest: public BtLocalRequest
{
    private:
        typedef BtLocalRequest Base;

    public:
        BtUncancelableRequest();

        virtual ~BtUncancelableRequest();


        virtual BOOLEAN IsCancelable() const;

    protected:

        virtual BOOLEAN Cancel();
};

#endif  // BtUncancelableRequest_hpp


