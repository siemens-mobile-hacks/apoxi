                               /*   ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CbsDispatcher_hpp)
#define Asc_CbsDispatcher_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Message.hpp>

#include <Asc/StackMsgDispatcher.hpp>
#include <Asc/CbsFilterList.hpp>

/*  ========================================================================
    CbsDispatcher
    ======================================================================== */
class CbsDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        CbsDispatcher();
        virtual ~CbsDispatcher();
        CbsFilterList & GetCbsFilterList() { return m_filterlist; }  

    protected:
        BOOLEAN OnCbsNewDataInd(const StackMsgArgument &arg);
        BOOLEAN OnCbsLimitInd(const StackMsgArgument &arg);


    private:
        static const StackMsgArgMap<CbsDispatcher> m_arg_map[];
        StackMsgArgMapContainer<CbsDispatcher> m_arg_map_container;

        static CbsFilterList m_filterlist;  // global filter list

};

#endif // Asc_CbsDispatcher_hpp


