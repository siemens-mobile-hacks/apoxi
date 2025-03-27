/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CbsStopDispatcher_hpp)
#define Asc_CbsStopDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    CbsStopDispatcher
    ======================================================================== */
class CbsStopDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        CbsStopDispatcher();
        virtual ~CbsStopDispatcher();

        BOOLEAN Succeded() const {return m_success;};

    protected:
        BOOLEAN OnCbsStopRej(const StackMsgArgument &arg);
        BOOLEAN OnCbsStopCnf(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<CbsStopDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CbsStopDispatcher> m_arg_map_container;
        INT m_success;
};

#endif  // Asc_CbsStopDispatcher_hpp


