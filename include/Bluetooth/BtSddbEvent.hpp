/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbEvent_hpp)
#define BtSddbEvent_hpp

#include <Bluetooth/BtEvent.hpp>

class BtSddbEvent: public BtEvent
{
    private:
        typedef BtEvent Base;

    public:
        BtSddbEvent(BtResultCode result);

        virtual ~BtSddbEvent();
};

class BtSddbRegisterServiceEvent: public BtSddbEvent
{
    private:
        typedef BtSddbEvent Base;

    public:
        BtSddbRegisterServiceEvent(BtResultCode result, UINT32 service_record_handle);

        virtual ~BtSddbRegisterServiceEvent();


        UINT32 GetSerivceRecordHandle() const;

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 1 };

    private:
        UINT32 m_service_record_handle;
};

class BtSddbUnregisterServiceEvent: public BtSddbEvent
{
    private:
        typedef BtSddbEvent Base;

    public:
        BtSddbUnregisterServiceEvent(BtResultCode result);

        virtual ~BtSddbUnregisterServiceEvent();

    public:

        virtual UINT16 GetId() const;

    public:
        enum { ID = 2 };
};

#endif  // BtSddbEvent_hpp


