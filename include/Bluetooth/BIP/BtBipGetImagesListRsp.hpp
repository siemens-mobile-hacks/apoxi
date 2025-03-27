/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImagesListRsp_hpp)
#define BtBipGetImagesListRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Auxiliary/DataSink.hpp>
#include <Bluetooth/BIP/BtBipGetRsp.hpp>

class BtBipGetImagesListRsp : BtBipGetRsp
{
    private:
        typedef BtBipGetRsp Base;

    public:
        BtBipGetImagesListRsp();
        virtual ~BtBipGetImagesListRsp();

        virtual BtRequestType GetRequestType() const { return BtRqtBipGetImagesList; }

        void GetImagesListInd(UINT16 first_index, UINT16 max_images, BOOLEAN sort_by_latest_first, UINT16 filter_len, UINT8* filter);
        void SetImagesList(const BtBipImageListPtr& image_list);

        const BtBipImageHdlDescPtr& GetFilter() { return m_filter; }

protected:
        virtual BOOLEAN ExecuteRsp();
        
    private:
        UINT16  m_imgs_cnt;
        BtBipImageHdlDescPtr m_filter;
        UINT8*  m_img_desc_text;

    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipGetImagesListRsp_hpp

