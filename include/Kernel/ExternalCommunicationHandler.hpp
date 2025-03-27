/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#ifndef Apoxi_ExternalCommunicationHandler_hpp
#define Apoxi_ExternalCommunicationHandler_hpp

#include <Auxiliary/NonCloneable.hpp>

class MessageReferrer;
class AbstractExternalData;

class ExternalCommunicationHandler : public NonCloneable {
    public:
        enum HandlerType { 
            SignalHandlerType,
            AtHandlerType,
            InvalidHandlerType
        };

        ExternalCommunicationHandler();
        virtual ~ExternalCommunicationHandler();

        virtual void Init(const AbstractExternalData* external_data = 0);

        virtual void RouteData(const AbstractExternalData& external_data);

        virtual void PostMessage(const MessageReferrer& msg_ref);


        virtual HandlerType GetHandlerType() const = 0;

}; //class Handler

#endif  // Apoxi_ExternalCommunicationHandler_hpp


