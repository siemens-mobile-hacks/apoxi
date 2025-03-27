/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImageRsp_hpp)
#define BtBipGetImageRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Auxiliary/DataSink.hpp>
#include <Bluetooth/BIP/BtBipGetRsp.hpp>

class BtBipGetImageRsp : BtBipGetRsp
{
    private:
        typedef BtBipGetRsp Base;

    public:
        BtBipGetImageRsp();
        virtual ~BtBipGetImageRsp();

        virtual BtRequestType GetRequestType() const { return BtRqtBipGetImage; }

        void GetImageInd(const BtBipImageHdlPtr& img_hdl, const UINT8* img_desc, UINT16 img_desc_len);
        void SetFileLen(UINT32 file_len) { m_file_len = file_len; }

        BtBipImageDescPtr&  GetImageDesc() { return m_img_desc; }

    protected:
        virtual BOOLEAN ExecuteRsp();
        
    private:
        UINT32  m_file_len;
        BtBipImageDescPtr   m_img_desc;

    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipGetImageRsp_hpp

