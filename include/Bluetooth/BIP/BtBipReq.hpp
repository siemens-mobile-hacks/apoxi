/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipRequest_hpp)
#define BtBipRequest_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BIP/BtBipService.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>
#include <stack/extensions.h>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipController;

class BtBipReq : public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtBipReq(BtBipService& obex_service);

        virtual ~BtBipReq();

        virtual BOOLEAN Abort(const WString& abort_desc) { return FALSE; } // should be abstract if implemented in all sub classes
        virtual void AbortCfm(BtBipResult bip_result, const BtObexResponseCode& obex_response) {}

        BtObexResponseCode GetObexResult() { return m_obex_result; }
        BtBipResult GetBipResult() { return m_bip_result; }

        virtual UINT32  GetBytesTransfered() { return 0; }


    protected:

        virtual BtRequestState ChangeRequestState(BOOLEAN success);


//      virtual BOOLEAN EvaluateExecutionResult(BtResultCode result);

        void SetObexResult(BtObexResponseCode res) { m_obex_result = res; }
        void SetBipResult(BtBipResult res) { m_bip_result = res; }

        BOOLEAN IsAbortPending() { return m_abort_pending; }
        void SetAbortPending(BOOLEAN abort_pending) { m_abort_pending = abort_pending; }

        BtBipSessionId BtApi2ApoxiBipSessionId(btapi_bip_session_id_t btapi_session_id) const;
        btapi_bip_session_id_t Apoxi2BtApiBipSessionId(BtBipSessionId apoxi_session_id) const;

    private:
        BOOLEAN m_abort_pending;
        BtBipResult m_bip_result;
        BtObexResponseCode  m_obex_result;
        friend class BtBipController;
};
#endif

#endif  // BtBipRequest_hpp

