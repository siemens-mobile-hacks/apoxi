/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtBipService_hpp)
#define BtBipService_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/UserDispatcher.hpp>
#include <Bluetooth/BtService.hpp>

class BtBipController;


class BtBipService: public BtService
{
    private:
        typedef BtService Base;

    public:
        enum MsgType {
            ClientPutNextPacket,
            ClientGetNextPacket,
            ServerPutNextPacket,
            ServerGetNextPacket
        };

        BtBipService();

        virtual ~BtBipService();


        virtual BtProfile GetProfile() const;


        virtual BOOLEAN IsServerService() const = 0;


        virtual BOOLEAN OnMessage(const Message& msg);

        void SetBufferSize(UINT16 buf_size) { m_buf_size = buf_size; }
 
    protected:


        virtual void RegisterMessages() const;
        virtual void UnregisterMessages() const;

        void SetDispatcher();
        void RemoveDispatcher();

        void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);

        UINT16              m_buf_size;

    private:

        BOOLEAN m_disp_added;


};
#endif

#endif  // BtBipService_hpp

