/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CbsStartDispatcher_hpp)
#define Asc_CbsStartDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    CbsStartDispatcher
    ======================================================================== */
class CbsStartDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        CbsStartDispatcher();
        virtual ~CbsStartDispatcher();

        BOOLEAN Succeded() const { return m_success; }

    protected:
        BOOLEAN OnCbsStartCnf(const StackMsgArgument &arg);
        BOOLEAN OnCbsStartRej(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<CbsStartDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CbsStartDispatcher> m_arg_map_container;
        BOOLEAN m_success;
};

#endif  // Asc_CbsStartDispatcher_hpp


