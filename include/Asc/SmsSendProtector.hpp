/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsSendProtector_hpp)
#define Asc_SmsSendProtector_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Kernel/Types.hpp>

class ExecutionContext;

/*  ========================================================================
    SmsSendProtector
    ======================================================================== */
class SmsSendProtector
{
    public:
        SmsSendProtector();

        virtual ~SmsSendProtector();

        BOOLEAN Lock();

        BOOLEAN Unlock();

        BOOLEAN IsAllowed() const;

    private:
        ExecutionContext *m_pending_context;
}; // class 


#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // Asc_SmsSendProtector_hpp


