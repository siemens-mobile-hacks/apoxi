/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutReq_hpp)
#define BtBipPutReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipAbortReq.hpp>

extern const UINT16 c_bip_client_put_packet_size;

class BtBipPutReq : public BtBipReq
{
    private:
        typedef BtBipReq Base;

    public:
        BtBipPutReq(BtBipClientService& bip_client_service);

        virtual ~BtBipPutReq();

        BOOLEAN Init(const DataSourcePtr& ds);
        virtual void PrepareNextPacket() = 0;
        void SetPacketSize(UINT16 packet_size) { m_packet_size = packet_size; }
        
        virtual BOOLEAN Abort(const WString& abort_desc);
        virtual void AbortCfm(BtBipResult bip_result, const BtObexResponseCode& obex_response);

        UINT32  GetBytesSent() { return m_bytes_sent; }

        virtual UINT32  GetBytesTransfered() { return GetBytesSent(); }


    protected:
        

        const UINT8* ReadNextPacket(UINT32& bytes_read);

        BOOLEAN Finished() { return (m_cur_src.Get() == 0); }
        
        // called by BtBipPutReq if request is finished
        virtual void CleanUp() = 0;

        virtual void ExecutionCallback(BtResultCode result);
        

    private:
        void ReleaseEverything();

        DataSourcePtr   m_cur_src;
        UINT8*          m_cur_buf;
        UINT16          m_cur_buf_len;
        UINT16          m_packet_size;

        UINT16          m_packet_cnt;
        UINT32          m_bytes_sent;

        BtBipAbortReq*  m_abort_req;
        BOOLEAN         m_req_pending;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipPutReq_hpp

