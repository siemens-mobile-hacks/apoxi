/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SimTkLceService_hpp)
#define Apoxi_SimTkLceService_hpp

#include <Kernel/ServiceThread.hpp>

class SimTkLceService : public ServiceThread {
    typedef ServiceThread Base;

    public:
        virtual ~SimTkLceService();

        static SimTkLceService& GetInstance();

    protected:
        virtual void OnPowerUp();

        virtual void OnPowerDown();

        virtual BOOLEAN OnMessage(const Message& msg);

    private:
        SimTkLceService();
        SimTkLceService(const SimTkLceService&);
};

#endif  // Apoxi_SimTkLceService_hpp


