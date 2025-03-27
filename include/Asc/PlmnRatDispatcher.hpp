/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_PlmnRatDispatcher_hpp)
#define Asc_PlmnRatDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    PlmnRatDispatcher
    ======================================================================== */
class PlmnRatDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        PlmnRatDispatcher();
        virtual ~PlmnRatDispatcher();

    protected:
        BOOLEAN OnOmRatChangeCnf(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<PlmnRatDispatcher> m_arg_map[];
        StackMsgArgMapContainer<PlmnRatDispatcher> m_arg_map_container;
};

#endif  // Asc_PlmnRatDispatcher_hpp

