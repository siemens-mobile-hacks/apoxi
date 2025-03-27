/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtServiceObserver_hpp)
#define BtServiceObserver_hpp

#include <Bluetooth/BtEvent.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObservableService;

class BtServiceObserver
{
    public:
        BtServiceObserver();

        virtual ~BtServiceObserver();

    protected:

        virtual void OnEvent(const BtEvent& event) = 0;

    private:
        friend class BtObservableService;
};

#endif  // BtServiceObserver_hpp


