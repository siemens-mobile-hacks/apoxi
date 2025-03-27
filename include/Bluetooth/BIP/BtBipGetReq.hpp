/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetReq_hpp)
#define BtBipGetReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipAbortReq.hpp>
#include <Auxiliary/DataSink.hpp>

class BtBipGetReq : public BtBipReq
{
    private:
        typedef BtBipReq Base;

    public:
        BtBipGetReq(BtBipClientService& bip_client_service);

        virtual ~BtBipGetReq();

        BOOLEAN Init(const DataSinkPtr& ds);
        void WritePacket(UINT16 len, UINT8* data);
        
        virtual BOOLEAN Abort(const WString& abort_desc);
        virtual void AbortCfm(BtBipResult bip_result, const BtObexResponseCode& obex_response);


        UINT32  GetBytesReceived() { return m_bytes_rec; }

        virtual UINT32  GetBytesTransfered() { return GetBytesReceived(); }

    protected:
        

        BOOLEAN Finished() { return (m_cur_sink.Get() == 0); }
        
        // called by BtBipGetReq if request is finished
//      virtual void CleanUp() = 0;

        virtual void ExecutionCallback(BtResultCode result);
        

    private:
        void ReleaseEverything();

        DataSinkPtr     m_cur_sink;

        UINT16          m_packet_cnt;
        UINT32          m_bytes_rec;

        BtBipAbortReq*  m_abort_req;
        BOOLEAN         m_req_pending;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipGetReq_hpp

