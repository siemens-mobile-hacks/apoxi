/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_BattHandler_hpp)
#define Asc_BattHandler_hpp
#if defined(APOXI_COMPAT_2_2_0)

#include <Asc/BaseHandler.hpp>

class BattHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = BattHandlerId };

        BattHandler();
        virtual ~BattHandler();
        virtual HandlerId GetHandlerId() const;
        
        void Start() const;

        void Stop() const;
};

#endif //APOXI_COMPAT_2_2_0

#endif // Asc_BattHandler_hpp


