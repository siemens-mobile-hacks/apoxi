/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CbsHandler_hpp)
#define Asc_CbsHandler_hpp

#include <Kernel/Types.hpp>

#include <Apc/Cbs.hpp>

#include <Asc/BaseHandler.hpp>

#include <Asc/CbsDispatcher.hpp>
#include <Asc/CbsFilterList.hpp>

/*  ========================================================================
    CbsHandler
    ======================================================================== */
class CbsHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = CbsHandlerId };     

        CbsHandler();
        virtual ~CbsHandler();

        virtual HandlerId GetHandlerId() const;

        BOOLEAN Start(const Cbs::Filter &filter);
        BOOLEAN Stop();
        CbsFilterList & GetCbsFilterList() { return m_cbs_dispatcher.GetCbsFilterList(); }   

    private:
        CbsDispatcher m_cbs_dispatcher;     // main dispatcher for retrieving asynchronous messages

};

#endif // Asc_PowerHandler_hpp


