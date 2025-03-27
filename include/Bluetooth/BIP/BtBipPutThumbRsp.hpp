/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutThumbRsp_hpp)
#define BtBipPutThumbRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BIP/BtBipPutRsp.hpp>

class BtBipPutThumbRsp : public BtBipPutRsp
{
    private:
        typedef BtBipPutRsp Base;

    public:
        BtBipPutThumbRsp();

        virtual ~BtBipPutThumbRsp();

        void PutLinkedThumbnailInd(const BtBipImageHdlPtr& img_hdl, const UINT8* body, UINT16 body_len, BOOLEAN last_msg);

        virtual BOOLEAN ExecuteRsp();

        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }

        virtual BtRequestType GetRequestType() const { return BtRqtBipPutLinkedThumbnail; }

    protected:
        
    private:
        BtBipImageHdlPtr    m_img_hdl;

    private:
        friend class BtBipController;
};
#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif  // BtBipPutThumbRsp_hpp

