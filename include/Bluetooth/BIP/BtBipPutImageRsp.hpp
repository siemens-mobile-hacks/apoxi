/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BipPutImageRsp_hpp)
#define BipPutImageRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipPutRsp.hpp>

class BtBipPutImageRsp : public BtBipPutRsp
{
    private:
        typedef BtBipPutRsp Base;

    public:
        BtBipPutImageRsp();

        virtual ~BtBipPutImageRsp();

        void PutImageInd(const WString& name, const UINT8* img_desc, 
                         UINT16 img_desc_len, const UINT8* body, UINT16 body_len, BOOLEAN last_msg);

        void SetImageHdl(const BtBipImageHdlPtr& img_hdl) { m_img_hdl = img_hdl; }
        virtual BOOLEAN ExecuteRsp();

        const WString& GetName() { return m_name; }
        const BtBipImageDescPtr& GetImageDesc() { return m_img_desc; }
        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }

        virtual BtRequestType GetRequestType() const { return BtRqtBipPutImage; }

    protected:
        
    private:
        WString             m_name;
        BtBipImageDescPtr   m_img_desc;
        BtBipImageHdlPtr    m_img_hdl;

//      BOOLEAN             m_abort_pending;
//      BOOLEAN             m_rsp_pending;

    private:
        friend class BtBipController;
};
#endif

#endif  // BipPutImageRsp_hpp

