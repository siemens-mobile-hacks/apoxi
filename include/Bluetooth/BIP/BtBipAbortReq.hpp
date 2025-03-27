/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipAbortReq_hpp)
#define BtBipAbortReq_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BIP/BtBipReq.hpp>

extern const UINT16 c_bip_client_put_packet_size;

class BtBipAbortReq : public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtBipAbortReq(BtBipClientService& bip_client_service, BtBipReq* parent);

        virtual ~BtBipAbortReq();
        virtual BtRequestType GetRequestType() const;

        void SetAbortDesc(const WString& desc) { m_desc = desc; }
        BtObexResponseCode GetObexResult() { return m_obex_result; }
        BtBipResult GetBipResult() { return m_bip_result; }

    protected:
        

        virtual BOOLEAN Execute();

        virtual void ExecutionCallback(BtResultCode result);

        void SetObexResult(BtObexResponseCode res) { m_obex_result = res; }
        void SetBipResult(BtBipResult res) { m_bip_result = res; }


private:

        const WCHAR* GetApiSettings() { return m_desc.GetCString(); }
        WString     m_desc;
        BtBipReq*   m_parent;

        BtBipResult m_bip_result;
        BtObexResponseCode  m_obex_result;

        friend class BtBipController;
        friend class BtBipClientService;
        friend class BtBipPutReq;
        friend class BtBipGetReq;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif  // BtBipAbortReq_hpp

