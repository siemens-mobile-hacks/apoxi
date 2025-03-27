/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SigDispatcher_hpp)
#define Asc_SigDispatcher_hpp

#include <Kernel/Types.hpp>

#include <Asc/StackMsgDispatcher.hpp>

/*  ========================================================================
    SigDispatcher
    ======================================================================== */
class SigDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        SigDispatcher();
        virtual ~SigDispatcher();

    protected:
        BOOLEAN OnSignalStrengthLevelInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<SigDispatcher> m_arg_map[];
        StackMsgArgMapContainer<SigDispatcher> m_arg_map_container;
};

#endif // Asc_SigDispatcher_hpp


