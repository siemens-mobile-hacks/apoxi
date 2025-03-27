/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_AocHandler_hpp)
#define Asc_AocHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/AocDispatcher.hpp>


class AocHandler : public BaseHandler {
    typedef BaseHandler Base;

    public:
        enum { ID = AocHandlerId };

        AocHandler();
        virtual ~AocHandler();
        
        virtual HandlerId GetHandlerId() const;

        void ReportChargeUnits(BOOLEAN activate);

        void ReportCurrentCharge(BOOLEAN activate);

        CallApiRc RequestCurrentCharge(CallIndex call_index);

        CallApiRc RequestChargeUnits(CallIndex call_index);


    private:
        CallApiRc CheckAocRequestRestrictions(CallIndex call_index, Tipd & tipd);
        AocDispatcher m_aoc_disp;
};

#endif // Asc_AocHandler_hpp


