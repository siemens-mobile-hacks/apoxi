/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ApoxiThread_hpp)
#define Apoxi_ApoxiThread_hpp

#include <Kernel/Os/Os.hpp>
#include <Auxiliary/Linkable.hpp>

class ExecutionContext;

class ApoxiThread : public Thread, public Linkable<ApoxiThread> {
    typedef Thread Base;

    public:
        ApoxiThread();
        virtual ~ApoxiThread();

        virtual ExecutionContext& GetContext() = 0;

        virtual const ExecutionContext& GetContext() const = 0;
};

#endif  // Apoxi_ApoxiThread_hpp


