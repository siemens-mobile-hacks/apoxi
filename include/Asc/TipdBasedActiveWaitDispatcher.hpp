/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_TipdBasedActiveWaitDispatcher_hpp)
#define Asc_TipdBasedActiveWaitDispatcher_hpp

#include <Asc/StackMsgActiveWaitDispatcher.hpp>
#include <Apc/SignalTypes.hpp>

class TipdBasedActiveWaitDispatcher : public StackMsgActiveWaitDispatcher {

    typedef StackMsgActiveWaitDispatcher Base;

    public:
        enum AbortCause {
            UserAbort,      // the user aborted the active wait loop
            RemoteAbort,    // a remote event aborted the active wait loop
            NotSpecified    // the cause for the abort is not specified
        };

        TipdBasedActiveWaitDispatcher(Tipd tipd);
        
        virtual ~TipdBasedActiveWaitDispatcher() {}

        BOOLEAN IsEqualTipd(Tipd tipd) const { return m_tipd == tipd; }

        virtual void AbortIfEqualTipd(Tipd tipd, AbortCause cause = NotSpecified);
        
        AbortCause GetAbortCause() const { return m_cause; }

    protected:
        Tipd GetTipd() const { return m_tipd; }

        void SetTipd(Tipd tipd) { m_tipd = tipd; }

    private:
        Tipd m_tipd;
        AbortCause m_cause;

};

#endif // Asc_TipdBasedActiveWaitDispatcher_hpp


