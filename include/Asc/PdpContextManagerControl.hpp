/*  ------------------------------------------------------------------------
    Copyright (C) 2002 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_PdpContextManagerControl_hpp)
#define Asc_PdpContextManagerControl_hpp

#include <Asc/PdpContext.hpp>

class PdpContextManagerControl
{
    public:
        PdpContextManagerControl() { }
        virtual ~PdpContextManagerControl() { }


        virtual void OnAttachCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnDetachCompleted(PdpContext::ErrorCause cause) { }



        virtual void OnAttachRep(BOOLEAN attached) { }

        virtual void OnAttachStatusIndication() { }

        virtual void OnDetachIndication(PdpContext::ErrorCause cause, 
            PdpContext::Origin origin = PdpContext::UnknownOrigin) { }

        virtual void OnActivateContextIndication(PdpContext::Type type, 
            PdpContext::Address address) { }
};

#endif // Asc_PdpContextManagerControl_hpp


