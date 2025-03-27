/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetRsp_hpp)
#define BtBipGetRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Auxiliary/DataSource.hpp>

class BtBipGetRsp
{
    public:
        BtBipGetRsp();
        virtual ~BtBipGetRsp();

        void SetDataSource(const DataSourcePtr& ds);
        void SetLastMsg(BOOLEAN last_msg) { m_last_msg = last_msg; }
        void SetObexResult(BtObexResponseCode obex_rsp_code) { m_obex_rsp = obex_rsp_code; }
        
        BOOLEAN Execute();

        virtual BtRequestType GetRequestType() const = 0;


        void GetInd();
        void BodyCompleteInd();

        BOOLEAN Cancel(BtObexResponseCode obex_rsp_code);
        
        BOOLEAN IsFirst() { return m_first_msg; }
        BOOLEAN IsLast() { return m_last_msg; }
        BOOLEAN IsFinished() { return !m_active; }
        void Abort(const WString& desc);
        
        UINT32 GetProgressInBytes() { return m_bytes_transfered; }
        
        
    protected:
        BtObexResponseCode GetObexResult() { return m_obex_rsp; }
        const UINT8*    GetBody() { return m_cur_buf; }
        UINT16          GetBodyLen() { return m_cur_buf_len; }

        virtual BOOLEAN ExecuteRsp() = 0;
        
    private:

        DataSourcePtr   m_cur_src;
        UINT8*          m_cur_buf;
        UINT16          m_cur_buf_len;

        BtObexResponseCode  m_obex_rsp;
        UINT16              m_packet_cnt;
        WString             m_abort_desc;

        UINT16          m_packet_size;

        BOOLEAN         m_first_msg;
        BOOLEAN         m_last_msg;

        BOOLEAN         m_cancel_pending;
        BOOLEAN         m_abort_pending;
        BOOLEAN         m_rsp_pending;
        BOOLEAN         m_active;

        UINT32          m_bytes_transfered; 

    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipGetRsp_hpp

