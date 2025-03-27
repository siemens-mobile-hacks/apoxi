/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SimHandler_hpp)
#define Asc_SimHandler_hpp

#include <Apc/SignalTypes.hpp>

#include <Asc/BaseHandler.hpp>

#include <Asc/SimDispatcher.hpp>

/*  ========================================================================
    SimHandler
    ======================================================================== */
class SimHandler : public BaseHandler {
    typedef BaseHandler Base;

    public:
        enum { ID = SimHandlerId };     

        SimHandler();
        virtual ~SimHandler();

        virtual HandlerId GetHandlerId() const;

        BOOLEAN ActivateFdn();
        BOOLEAN DeactivateFdn();

        BOOLEAN ActivateBdn();
        BOOLEAN DeactivateBdn();

        void SetPbAlphaTagRequestBehaviour(PbRequestBehaviour ) {
            DBG_OUT((0,"SimHandler::SetPbAlphaTagRequestBehaviour obsolete -> moved to AtcHandler\n"));
        }
        BOOLEAN ConfirmPbAlphaTagRequest(
            const WString & , const PhoneNumber & , BOOLEAN apoxilookup = FALSE)
        {
            DBG_OUT((0,"SimHandler::ConfirmPbAlphaTagRequest obsolete -> moved to AtcHandler\n"));
            return FALSE;
        }

    private:
        SimDispatcher m_sim_dispatcher;     // main dispatcher for retrieving asynchronous messages

};

#endif // Asc_SimHandler_hpp


