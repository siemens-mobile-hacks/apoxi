/*  ------------------------------------------------------------------------
    Copyright (C) 2002 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Asc_PdpContextControl_hpp)
#define Asc_PdpContextControl_hpp

#include <Asc/PdpContext.hpp>

class PdpContextControl
{
    friend class PdpContextManager;

    private:
        PdpContext* m_pdp_context;

        void AttachContext(PdpContext *pdp_context) {
            m_pdp_context = pdp_context;
        }

    public:
        PdpContextControl() : m_pdp_context(0) { }
        virtual ~PdpContextControl() { }

        PdpContext* GetContext() const {
            return m_pdp_context;
        }


        virtual void OnDefineCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnUndefineCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnAuthenticateCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnSetQualityOfServiceCompleted(
            PdpContext::ErrorCause cause) { }

        virtual void OnSetMinimumQualityOfServiceCompleted(
            PdpContext::ErrorCause cause) { }

        virtual void OnActivateCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnDeactivateCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnConnectCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnSetCounterCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnReadCounterCompleted(PdpContext::ErrorCause cause) { }

        virtual void OnSetPacketFilterCompleted(PdpContext::ErrorCause cause)
            { }

        virtual void OnUnsetPacketFilterCompleted(PdpContext::ErrorCause cause)
            { }

        virtual void OnSetAutomaticDnsServerNegotiationCompleted(
            PdpContext::ErrorCause cause) { }

        virtual void OnReadNegotiatedDnsServerAddressCompleted(
            PdpContext::ErrorCause cause) { }



        virtual void OnReactivateIndication() { }

        virtual void OnDeactivateIndication(PdpContext::ErrorCause cause,
            PdpContext::Origin origin = PdpContext::UnknownOrigin) { }

        virtual void OnActivationStatusContextIndication() { }

};

#endif // Asc_PdpContextControl_hpp


