/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtBppService_hpp)
#define BtBppService_hpp

#include <Kernel/UserDispatcher.hpp>
#include <Bluetooth/BtService.hpp>

class BtBppController;


class BtBppService: public BtService
{
    private:
        typedef BtService Base;

    public:
        BtBppService();

        virtual ~BtBppService();


        virtual BtProfile GetProfile() const;


        virtual BOOLEAN IsServerService() const = 0;


        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


    protected:

        virtual void RegisterMessages() const;
        virtual void UnregisterMessages() const;

        void SetDispatcher();
        void RemoveDispatcher();


    private:

        BOOLEAN m_disp_added;
};

#endif  // BtBppService_hpp

