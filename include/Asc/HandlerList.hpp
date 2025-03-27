/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_HandlerList_hpp)
#define Asc_HandlerList_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>

#include <Asc/HandlerData.hpp>

class BaseHandler;
class MainHandler;

/*  ========================================================================
    HandlerListEntry
    ======================================================================== */
class HandlerListEntry : public Linkable<HandlerListEntry> {
    friend class MainHandler;
    typedef Linkable<HandlerListEntry> Base;
    public:
        HandlerListEntry(HandlerId m_id);
        virtual ~HandlerListEntry();

        HandlerId Id() const { return (m_id); }

        BaseHandler* GetHandler() const { return (m_handler); }

        BOOLEAN Init(MainHandler *main_handler);
        BOOLEAN Cleanup(MainHandler *main_handler, BOOLEAN force = FALSE);

    private:
        HandlerId m_id;
        INT m_ref_count;
        BaseHandler *m_handler;

        static struct HandlerData m_handler_data_table[];

        static HandlerData* GetHandlerData(HandlerId id);

        INT RefCount() const { return (m_ref_count); }
        void AddRef(INT i) { m_ref_count += i; }
};

/*  ========================================================================
    HandlerList
    ======================================================================== */
typedef LinkedList<HandlerListEntry> HandlerList;

#endif  // Asc_HandlerList_hpp


