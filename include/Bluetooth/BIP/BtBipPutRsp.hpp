/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutRsp_hpp)
#define BtBipPutRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Auxiliary/DataSink.hpp>

class BtBipPutRsp
{
    public:
        BtBipPutRsp();
        virtual ~BtBipPutRsp();

        void SetBody(const UINT8* buf, UINT16 buf_len);
        void SetDataSink(const DataSinkPtr& ds);
        void SetLastMsg(BOOLEAN last_msg) { m_last_msg = last_msg; }
        void SetObexResult(BtObexResponseCode obex_resp_code) { m_obex_resp = obex_resp_code; }
        
        BOOLEAN IsFirst() { return ((m_cur_sink.Get() == 0) || (m_first_msg)); }
        BOOLEAN IsFinished() { return m_last_msg; }

        void SetFirstMsg(BOOLEAN first) { m_first_msg = first; }
        void PrepareNextPacket();
        BOOLEAN Execute();

        void Abort(const WString& desc);

        virtual BtRequestType GetRequestType() const = 0;

        UINT32 GetProgressInBytes() { return m_bytes_transfered; }

    protected:
        BtObexResponseCode GetObexResult() { return m_obex_resp; }

        virtual BOOLEAN ExecuteRsp() = 0;
        
    private:

        DataSinkPtr     m_cur_sink;
        UINT8*          m_cur_buf;
        UINT16          m_cur_buf_len;

        BOOLEAN         m_last_msg;
        BOOLEAN         m_first_msg;
        BOOLEAN         m_active;
        BOOLEAN         m_rsp_pending;
        BOOLEAN         m_abort_pending;

        BtObexResponseCode  m_obex_resp;
        UINT16          m_packet_cnt;
        WString         m_abort_desc;
        
        UINT32          m_bytes_transfered; 
        

    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipPutRsp_hpp

