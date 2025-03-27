/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpService_hpp)
#define BtAvrcpService_hpp

#include <Bluetooth/BtService.hpp>

class BtAvrcpService : public BtService
{
    private:
        typedef BtService Base;

    public:
        BtAvrcpService();

        virtual ~BtAvrcpService();


        virtual void Init();


        virtual BtProfile GetProfile() const;


    protected:

        virtual BOOLEAN OnMessage(const Message& message);


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;

};

#endif  // BtAvrcpService_hpp

