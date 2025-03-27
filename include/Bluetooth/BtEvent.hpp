/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtEvent_hpp)
#define BtEvent_hpp

#include <Bluetooth/BtTypes.hpp>

class BtEvent
{
    public:
        BtEvent(BtResultCode result);

        virtual ~BtEvent();


        BtResultCode GetResult() const;

    public:

        virtual UINT16 GetId() const = 0;

    private:
        BtResultCode m_result;
};

#endif  // BtEvent_hpp


