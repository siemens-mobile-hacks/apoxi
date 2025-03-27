/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Protector_hpp)
#define Apoxi_Protector_hpp

#include <Kernel/Os/Mutex.hpp>

class Protector {
    public:
        Protector();

        virtual ~Protector();

        void Init();

        BOOLEAN IsInitialized() { return m_initialized; }

        virtual BOOLEAN Lock();

        virtual BOOLEAN Unlock();

    private:
        BOOLEAN m_initialized;
        Mutex   m_mutex;
};

#endif  // Apoxi_Protector_hpp


