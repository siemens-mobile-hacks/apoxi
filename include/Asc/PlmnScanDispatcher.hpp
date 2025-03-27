/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Gprs_PlmnScanDispatcher_gprs_hpp)
#define Asc_Gprs_PlmnScanDispatcher_gprs_hpp

#include <Kernel/Types.hpp>

#include <Apc/PlmnScanList.hpp>

#include <Asc/StackMsgActiveWaitDispatcher.hpp>

/*  ========================================================================
    PlmnScanDispatcher
    ======================================================================== */
class PlmnScanDispatcher : public StackMsgActiveWaitDispatcher {
    typedef StackMsgActiveWaitDispatcher Base;
    public:
        PlmnScanDispatcher(PlmnScanList &plmn_scan_list);
        virtual ~PlmnScanDispatcher();

    protected:
        BOOLEAN OnPlmnListCnf(const StackMsgArgument &arg);
        BOOLEAN OnPlmnListRej(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<PlmnScanDispatcher> m_arg_map[];
        StackMsgArgMapContainer<PlmnScanDispatcher> m_arg_map_container;
        
        PlmnScanList &m_plmn_scan_list;
};

#endif  // Asc_Gprs_PlmnScanDispatcher_gprs_hpp

