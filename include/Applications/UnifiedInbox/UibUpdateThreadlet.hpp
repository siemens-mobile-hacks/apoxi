/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(UibUpdateThreadlet_hpp)
#define UibUpdateThreadlet_hpp

#include <Kernel/Threadlet.hpp>
#include <Auxiliary/Provider.hpp>

class UibUpdateThreadlet : public Threadlet {
    typedef Threadlet Base;

    public:
        UibUpdateThreadlet();

        virtual ~UibUpdateThreadlet();

        void Init(Provider* provider) { m_provider = provider; }

        void SetProvider(Provider* provider) { m_provider = provider; }

        virtual INT Fn();
        
    private:
        Provider* m_provider;
};

#endif  // Apoxi_UibUpdateThreadlet_hpp
