/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MultiSlotHandler_hpp)
#define Asc_MultiSlotHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/MultiSlotDispatcher.hpp>

class MultiSlotHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = MultiSlotHandlerId };

        MultiSlotHandler();
        virtual ~MultiSlotHandler();
        virtual HandlerId GetHandlerId() const;

        BOOLEAN SetMultiSlot(MultiSlotMode multi_slot_mode);
        
    private:
        MultiSlotDispatcher m_multislot_dispatcher; // main dispatcher for retrieving asynchronous messages
};

#endif // Asc_MultiSlotHandler_hpp


