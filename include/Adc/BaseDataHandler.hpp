/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_BaseDataHandler_hpp)
#define Adc_BaseDataHandler_hpp

#include <Adc/SimAccessor.hpp>

class BaseDataHandler
{
    public:
        BaseDataHandler();
        virtual ~BaseDataHandler();   

        void Init(SimAccessor * handler);

        BOOLEAN IsSimAccessAllowed() const { return SimAccessor::IsSimAccessAllowed(); }
        BOOLEAN IsSimPresent() const  { return SimAccessor::IsSimPresent(); }
        BOOLEAN IsUsimInserted() const { return SimAccessor::IsUsimInserted(); };

    protected:
        SimAccessor *   m_sim_handler;
};

#endif


