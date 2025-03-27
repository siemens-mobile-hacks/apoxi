/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_SignalHandler_hpp)
#define Apc_SignalHandler_SignalHandler_hpp

#include <Auxiliary/Macros.hpp>
#include <Kernel/ExternalCommunicationHandler.hpp>

class SignalHandler : public ExternalCommunicationHandler {
    typedef ExternalCommunicationHandler Base;
    public:
        static SignalHandler* GetInstance();

        virtual ~SignalHandler();

        virtual void Init(const AbstractExternalData *external_data);

        virtual void RouteData(const AbstractExternalData &external_data);

        virtual void PostMessage(const MessageReferrer &msg_ref);

        virtual HandlerType GetHandlerType() const { return SignalHandlerType; }

    private:
        static SignalHandler *m_signal_handler;

        // hide constructor as SignalHandler should be a singleton
        SignalHandler();
};

#endif  // Apc_SignalHandler_SignalHandler_hpp


