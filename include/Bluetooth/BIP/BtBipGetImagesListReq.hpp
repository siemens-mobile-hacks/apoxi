/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImagesListReq_hpp)
#define BtBipGetImagesListReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipGetReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipGetImagesListReq : public BtBipGetReq
{
    private:
        typedef BtBipGetReq Base;

    public:
        BtBipGetImagesListReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipGetImagesListReq();


        virtual BtRequestType GetRequestType() const;


        /**********************************************************************/
        /* Put Image Req parameter access methods                         */
        /**********************************************************************/




        void SetNrOfHandles(UINT16 nr_of_handles) { m_operation_params.NrOfHandles = nr_of_handles; }

        void SetStartOffset(UINT16 start_offset) { m_operation_params.StartOffset = start_offset; }

        void SetSortByLatest(BOOLEAN sort_by_latest) { m_operation_params.SortByLatest = sort_by_latest; }

        void SetHandleDesc(const BtBipImageHdlDescPtr& img_hdl_desc);

        void SetImageListSink(const DataSinkPtr& sink) { m_img_list_sink = sink; }

        const BtBipImageListPtr& GetImageList();
        //TODO: GetAppliedHandleDesc

    protected:

        virtual BOOLEAN Execute();

    private:
        /* Results */
        void SetAppliedHandleDesc(UINT16 hdl_desc_len, const UINT8* hdl_desc);

        btapi_bip_get_imgs_list_t*  GetApiSettings();
        btapi_bip_get_imgs_list_t   m_operation_params;

        BtBipImageListPtr   m_img_list;
        DataSinkPtr         m_img_list_sink;
        
    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipGetImagesListReq_hpp

