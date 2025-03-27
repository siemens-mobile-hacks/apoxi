/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TickValue_hpp)
#define Apoxi_TickValue_hpp


#include <Kernel/Types.hpp>

class TickValue {
    public:
        TickValue() : m_tick_value(0) {}

        TickValue(UINT32 tick_value) : m_tick_value(tick_value) {}

        void Set(UINT32 tick_value) {m_tick_value = tick_value; }
        UINT32 Get() const {return m_tick_value; }

    protected:

    private:
        UINT32 m_tick_value;
};


#endif  // Apoxi_TickValue_hpp

