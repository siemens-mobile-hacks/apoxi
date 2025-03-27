/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutAttachRsp_hpp)
#define BtBipPutAttachRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipPutRsp.hpp>

class BtBipPutAttachRsp : public BtBipPutRsp
{
    private:
        typedef BtBipPutRsp Base;

    public:
        BtBipPutAttachRsp();

        virtual ~BtBipPutAttachRsp();

        void PutLinkedAttachmentInd(const BtBipImageHdlPtr& img_hdl, const UINT8* attach_desc, UINT16 attach_desc_len,
                                    const UINT8* body, UINT16 body_len, BOOLEAN last_msg);

        virtual BOOLEAN ExecuteRsp();

        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }
        const BtBipAttachmentDescPtr& GetAttachDesc() { return m_attach_desc; }

        virtual BtRequestType GetRequestType() const { return BtRqtBipPutLinkedAttachment; }

    protected:
        
    private:
        BtBipImageHdlPtr    m_img_hdl;
        BtBipAttachmentDescPtr  m_attach_desc;

    private:
        friend class BtBipController;
};
#endif

#endif  // BtBipPutAttachRsp_hpp

