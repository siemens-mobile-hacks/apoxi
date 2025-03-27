/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ThreadSafeProvider_hpp)
#define Apoxi_ThreadSafeProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <Auxiliary/Protector.hpp>

class ThreadSafeProvider : public Provider {
    typedef Provider Base;

    public:
        ThreadSafeProvider();

        ThreadSafeProvider(Protector *protector);

        virtual ~ThreadSafeProvider();

        void Init(Protector *protector);

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

    private:
        Protector   *m_protector;
};

#endif  // Apoxi_ThreadSafeProvider_hpp


