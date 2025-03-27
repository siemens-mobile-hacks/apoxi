/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if !defined(Asc_DtmfDispatcher_hpp)
#define Asc_DtmfDispatcher_hpp

#include <Asc/StackMsgDispatcher.hpp>
#include <Apc/StackMsgArgument.hpp>

class DtmfDispatcher : public StackMsgDispatcher {
    typedef StackMsgDispatcher Base;
    public:
        DtmfDispatcher();
        
        virtual ~DtmfDispatcher();

        void IncDtmfRequests() { m_n_dtmf_requests++; }
        
        void DecDtmfRequests() { m_n_dtmf_requests--; } 

        INT CountDtmfRequests() { return m_n_dtmf_requests; }

        Tipd GetTipd() { return m_tipd; }

        void SetTipd(Tipd tipd) { m_tipd = tipd; }

        BOOLEAN OnStartDtmfCnf(const StackMsgArgument &arg);

        
        BOOLEAN OnStopDtmfCnf(const StackMsgArgument &arg);

        
        BOOLEAN OnStartDtmfRej(const StackMsgArgument &arg);

        
        BOOLEAN OnDtmfBufferClearedInd(const StackMsgArgument &arg);

    private:
        static const StackMsgArgMap<DtmfDispatcher> m_arg_map[];
        StackMsgArgMapContainer<DtmfDispatcher> m_arg_map_container;
        
        Tipd    m_tipd;
        INT     m_n_dtmf_requests;

};

#endif // Asc_DtmfDispatcher_hpp

#endif // DOXYGEN_SHOULD_SKIP_THIS


