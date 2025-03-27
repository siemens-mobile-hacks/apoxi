
/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipController_hpp)
#define BtBipController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <stack/extensions.h>
#include <Bluetooth/BtSingleConnectionController.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipService;
class BtBipServerService;
class BtBipClientService;
class BtBipConnectReq;      
class BtBipDisconnectReq;
class BtBipAbortReq;
class BtBipPutImageReq;
class BtBipPutThumbReq;
class BtBipPutAttachReq;
class BtBipGetImagesListReq;
class BtBipGetImageReq;
class BtBipGetLinkedThumbnailReq;
class BtBipGetLinkedAttachmentReq;
class BtBipDeleteImageReq;
class BtBipGetImagingCapabilitiesReq;
class BtBipGetImagePropertiesReq;

class BtBipController: public BtSingleConnectionController
{
    
    public:

        static BtBipController& GetInstance();

        virtual ~BtBipController();


        virtual const WCHAR* GetName() const;

    protected:
        // Register BIP Server Service at controller
        BOOLEAN RegisterBipServer(BtBipServerService* svr);

        BOOLEAN BipConnectReq(BtBipConnectReq* req);

        BOOLEAN BipConnectRsp(BtObexResponseCode obex_result);

        BOOLEAN BipDisconnectReq(BtBipDisconnectReq* req);

        BOOLEAN BipAbortReq(BtBipAbortReq* req);

        BOOLEAN BipAbortRsp(BtObexResponseCode obex_result);

        BOOLEAN BipGetImagingCapabilitiesReq(BtBipGetImagingCapabilitiesReq* req);

        BOOLEAN BipGetImagingCapabilitesRsp(BtObexResponseCode obex_result, UINT16 img_cap_len, const UINT8* img_cap);


        BOOLEAN BipPutImageReq(BtBipPutImageReq* req);

        BOOLEAN BipPutImageRsp(BtObexResponseCode obex_result, const BtBipImageHdlPtr& img_hdl);


        BOOLEAN BipPutLinkedThumbReq(BtBipPutThumbReq* req);


        BOOLEAN BipPutLinkedThumbRsp(BtObexResponseCode obex_result);


        BOOLEAN BipPutLinkedAttachmentReq(BtBipPutAttachReq* req);

        BOOLEAN BipPutLinkedAttachmentRsp(BtObexResponseCode obex_result);

        BOOLEAN BipGetImagesListReq(BtBipGetImagesListReq* req);

        BOOLEAN BipGetImagesListRsp(BtObexResponseCode obex_result, UINT16 img_count, UINT16 filter_len, const UINT8* filter, UINT16 list_len, const UINT8* list);

        BOOLEAN BipGetImagePropertiesReq(BtBipGetImagePropertiesReq* req);

        BOOLEAN BipGetImagePropertiesRsp(BtObexResponseCode obex_result, UINT16 img_props_len, const UINT8* img_props);

        BOOLEAN BipGetImageReq(BtBipGetImageReq* req);

        BOOLEAN BipGetImageRsp(BtObexResponseCode obex_result, UINT32 file_length, UINT16 body_len, const UINT8* body);

        BOOLEAN BipGetLinkedThumbReq(BtBipGetLinkedThumbnailReq* req);

        BOOLEAN BipGetLinkedThumbRsp(BtObexResponseCode obex_result, UINT16 body_len, const UINT8* body);

        BOOLEAN BipGetLinkedAttachmentReq(BtBipGetLinkedAttachmentReq* req);

        BOOLEAN BipGetLinkedAttachmentRsp(BtObexResponseCode obex_result, UINT16 body_len, const UINT8* body);

        BOOLEAN BipDeleteImageReq(BtBipDeleteImageReq* req);

        BOOLEAN BipDeleteImageRsp(BtObexResponseCode obex_result);

    private:

        typedef BtSingleConnectionController Base;

        /*---------------------------------------------------------------------*/
        /* The following functions must not be called by an application.       */
        /* They are the entry point from the stack callback functions into our */
        /* object orientated framework (APOXI).                                */
        /* They are implemented as static because they have to be passed as    */
        /* normal C function pointers. The reason for this is the BT-API Stack */
        /* interface that demands C function pointers for callback the         */
        /* callback functions it calls to state the progress of ongoing        */
        /* operations                                                          */
        /*---------------------------------------------------------------------*/


        // Callbacks where no paramters are passed
        static void CommonBipCb(btapi_result_t Result, btapi_common_bipcb_t Type);

        // Callback for Connect Confirmation (BIP_CONNECT_CFM)
        static void BipConnectCfmCb(btapi_result_t Result, btapi_bip_common_cfm_t *cfm);

        // Callback for Connect Ind (BIP_CONNECT_IND)
        static void BipConnectIndCb(btapi_result_t Result, btapi_bip_connect_t *ind);

        // Callback for Disconnect Confirmation (BIP_DISCONNECT_CFM)
        static void BipDisconnectCfmCb(btapi_result_t Result, btapi_bip_common_cfm_t *cfm);

        // Callback for Abort Confirmation (BIP_ABORT_CFM)
        static void BipAbortCfmCb(btapi_result_t Result, btapi_bip_common_cfm_t *cfm);

        // Callback for Abort Indication (BIP_ABORT_IND)
        static void BipAbortIndCb(btapi_result_t Result, btapi_bip_abort_ind_t *cfm);

        // Callback for Get Imaging Capabilities Confirmation (BIP_GET_CAPABILITIES_CFM)
        static void BipGetImagingCapabilitiesCfmCb(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Put Img Confirmation (BIP_PUT_IMAGE_CFM)
        static void BipPutImageCfmCb(btapi_result_t result, const btapi_bip_put_img_cfm_t *cfm);

        // Callback for Put Img Indication (BIP_PUT_IMAGE_IND)
        static void BipPutImageIndCb(btapi_result_t result, const btapi_bip_put_img_ind_t *ind);

        // Callback for Put Linked Thumbnail Confirmation (BIP_PUT_LINKED_THUMBNAIL_CFM)
        static void BipPutLinkedThumbnailCfmCb(btapi_result_t result, const btapi_bip_common_cfm_t *cfm);

        // Callback for Put Linked Thumbnail Indication (BIP_PUT_LINKED_THUMBNAIL_IND)
        static void BipPutLinkedThumbnailIndCb(btapi_result_t result, const btapi_bip_put_linked_thumb_t *ind);

        // Callback for Put Linked Attachment Confirmation (BIP_PUT_LINKED_ATTACHMENT_CFM)
        static void BipPutLinkedAttachmentCfmCb(btapi_result_t result, const btapi_bip_common_cfm_t *cfm);

        // Callback for Put Linked Attachment Indication (BIP_PUT_LINKED_ATTACHMENT_IND)
        static void BipPutLinkedAttachmentIndCb(btapi_result_t result, const btapi_bip_put_linked_attachment_t *ind);

        // Callback for Get Imgs List Confirmation (BIP_GET_IMAGES_LIST_CFM)
        static void BipGetImgsListCfmCb(btapi_result_t result, const btapi_bip_get_imgs_list_cfm_t *cfm);

        // Callback for Get Imgs List Indication (BIP_GET_IMAGES_LIST_IND)
        static void BipGetImgsListIndCb(btapi_result_t result, const btapi_bip_get_imgs_list_t *ind);

        // Callback for Get Img Properites Confirmation (BIP_GET_IMAGE_PROPERTIES_CFM)
        static void BipGetImgPropertiesCfmCb(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Img Properties Indication (BIP_GET_IMAGE_PROPERTIES_IND)
        static void BipGetImgPropertiesIndCb(btapi_result_t result, const btapi_bip_img_hdl_t *ind);

        // Callback for Get Img Confirmation (BIP_GET_IMAGE_CFM)
        static void BipGetImgCfmCb(btapi_result_t result, const btapi_bip_get_img_cfm_t *cfm);

        // Callback for Get Img Indication (BIP_GET_IMAGE_IND)
        static void BipGetImgIndCb(btapi_result_t result, const btapi_bip_get_img_t *cfm);

        // Callback for Get Linked Thumbnail Confirmation (BIP_GET_LINKED_THUMBNAIL_CFM)
        static void BipGetLinkedThumbnailCfmCb(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Linked Thumbnail Indication (BIP_GET_LINKED_THUMBNAIL_IND)
        static void BipGetLinkedThumbnailIndCb(btapi_result_t result, const btapi_bip_img_hdl_t *ind);

        // Callback for Get Linked Attachment Indication (BIP_GET_LINKED_ATTACHMENT_CFM)
        static void BipGetLinkedAttachmentCfmCb(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Linked Attachment Indication (BIP_GET_LINKED_ATTACHMENT_IND)
        static void BipGetLinkedAttachmentIndCb(btapi_result_t result, const btapi_bip_get_linked_attach_ind_t *ind);

        // Callback for Delete Image Confirmation (BIP_DELETE_IMAGE_CFM)
        static void BipDeleteImgCfmCb(btapi_result_t result, const btapi_bip_common_cfm_t *cfm);

        // Callback for Delete Image Indication (BIP_DELETE_IMAGE_IND)
        static void BipDeleteImgIndCb(btapi_result_t result, const btapi_bip_img_hdl_t *ind);

        // Callbacks where no paramters are passed
        void OnBipCommon(btapi_result_t Result, btapi_common_bipcb_t Type);

        // Callback for Connect Confirmation (BIP_CONNECT_CFM)
        void OnBipConnectCfm(btapi_result_t Result, btapi_bip_common_cfm_t *cfm);

        // Callback for Connect Ind (BIP_CONNECT_IND)
        void OnBipConnectInd(btapi_result_t Result, btapi_bip_connect_t *ind);

        // Callback for Disconnect Confirmation (BIP_DISCONNECT_CFM)
        void OnBipDisconnectCfm(btapi_result_t Result, btapi_bip_common_cfm_t *cfm);

        // Callback for Disconnect Confirmation (BIP_DISCONNECT_IND)
        void OnBipDisconnectInd(btapi_result_t Result);

        // Callback for Abort Confirmation (BIP_ABORT_CFM)
        void OnBipAbortCfm(btapi_result_t Result, btapi_bip_common_cfm_t *cfm);

        // Callback for Abort Indication (BIP_ABORT_IND)
        void OnBipAbortInd(btapi_result_t Result, btapi_bip_abort_ind_t *cfm);

        // Callback for Get Imaging Capabilities Confirmation (BIP_GET_CAPABILITIES_CFM)
        void OnBipGetImagingCapabilitiesCfm(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Imaging Capabilities Confirmation (BIP_GET_CAPABILITIES_CFM)
        void OnBipGetImagingCapabilitesInd(btapi_result_t result);

        // Callback for Put Img Confirmation (BIP_PUT_IMAGE_CFM)
        void OnBipPutImageCfm(btapi_result_t result, const btapi_bip_put_img_cfm_t *cfm);

        // Callback for Put Img Indication (BIP_PUT_IMAGE_IND)
        void OnBipPutImageInd(btapi_result_t result, const btapi_bip_put_img_ind_t *ind);

        // Callback for Put Linked Thumbnail Confirmation (BIP_PUT_LINKED_THUMBNAIL_CFM)
        void OnBipPutLinkedThumbnailCfm(btapi_result_t result, const btapi_bip_common_cfm_t *cfm);

        // Callback for Put Linked Thumbnail Indication (BIP_PUT_LINKED_THUMBNAIL_IND)
        void OnBipPutLinkedThumbnailInd(btapi_result_t result, const btapi_bip_put_linked_thumb_t *ind);

        // Callback for Put Linked Attachment Confirmation (BIP_PUT_LINKED_ATTACHMENT_CFM)
        void OnBipPutLinkedAttachmentCfm(btapi_result_t result, const btapi_bip_common_cfm_t *cfm);

        // Callback for Put Linked Attachment Indication (BIP_PUT_LINKED_ATTACHMENT_IND)
        void OnBipPutLinkedAttachmentInd(btapi_result_t result, const btapi_bip_put_linked_attachment_t *ind);

        // Callback for Get Imgs List Confirmation (BIP_GET_IMAGES_LIST_CFM)
        void OnBipGetImgsListCfm(btapi_result_t result, const btapi_bip_get_imgs_list_cfm_t *cfm);

        // Callback for Get Imgs List Indication (BIP_GET_IMAGES_LIST_IND)
        void OnBipGetImgsListInd(btapi_result_t result, const btapi_bip_get_imgs_list_t *ind);

        // Callback for Get Img Properites Confirmation (BIP_GET_IMAGE_PROPERTIES_CFM)
        void OnBipGetImgPropertiesCfm(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Img Properties Indication (BIP_GET_IMAGE_PROPERTIES_IND)
        void OnBipGetImgPropertiesInd(btapi_result_t result, const btapi_bip_img_hdl_t *ind);

        // Callback for Get Img Confirmation (BIP_GET_IMAGE_CFM)
        void OnBipGetImgCfm(btapi_result_t result, const btapi_bip_get_img_cfm_t *cfm);

        // Callback for Get Img Indication (BIP_GET_IMAGE_IND)
        void OnBipGetImgInd(btapi_result_t result, const btapi_bip_get_img_t *cfm);
        
        // Callback for Get Img Body Complete Indication (BIP_BODY_COMPLETE_IND)
        void OnBipBodyCompleteInd(btapi_result_t result);

        // Callback for Get Linked Thumbnail Confirmation (BIP_GET_LINKED_THUMBNAIL_CFM)
        void OnBipGetLinkedThumbnailCfm(btapi_result_t result, const btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Linked Thumbnail Indication (BIP_GET_LINKED_THUMBNAIL_IND)
        void OnBipGetLinkedThumbnailInd(btapi_result_t result, const btapi_bip_img_hdl_t *ind);

        // Callback for Get Linked Attachment Indication (BIP_GET_LINKED_ATTACHMENT_CFM)
        void OnBipGetLinkedAttachmentCfm(btapi_result_t result, const  btapi_bip_common_body_cfm_t *cfm);

        // Callback for Get Linked Attachment Indication (BIP_GET_LINKED_ATTACHMENT_IND)
        void OnBipGetLinkedAttachmentInd(btapi_result_t result, const btapi_bip_get_linked_attach_ind_t *ind);

        // Callback for Delete Image Confirmation (BIP_DELETE_IMAGE_CFM)
        void OnBipDeleteImgCfm(btapi_result_t result, const btapi_bip_common_cfm_t *cfm);

        // Callback for Delete Image Indication (BIP_DELETE_IMAGE_IND)
        void OnBipDeleteImgInd(btapi_result_t result, const btapi_bip_img_hdl_t *ind);

        //<em>Singleton</em>
        BtBipController();


        virtual void Register();


        virtual void Unregister();

        void BigTroubleWithLittleEndian(WString& str);

//      btapi_bip_handle_t GetBipHandle(const void* apoxi_handle);

        btapi_bipcb_funp_t* m_bip_callbacks;

        BtBipServerService* m_bip_server;

        static BtBipController m_controller;

        friend class BtBipService;
        friend class BtBipServerService;
        friend class BtBipClientService;
        friend class BtBipConnectReq;
        friend class BtBipDisconnectReq;
        friend class BtBipPutImageReq;
        friend class BtBipPutThumbReq;
        friend class BtBipPutAttachReq;
        friend class BtBipGetReq;
        friend class BtBipGetImagePropertiesReq;
        friend class BtBipGetImagePropertiesRsp;
        friend class BtBipGetImagingCapabilitiesReq;
        friend class BtBipGetImagesListReq;
        friend class BtBipGetImageReq;
        friend class BtBipGetLinkedThumbnailReq;
        friend class BtBipGetLinkedThumbnailRsp;
        friend class BtBipGetLinkedAttachmentReq;
        friend class BtBipGetLinkedAttachmentRsp;
        friend class BtBipDeleteImageReq;
        friend class BtBipDeleteImageRsp;
        friend class BtBipPutRsp;
        friend class BtBipPutImageRsp;
        friend class BtBipPutThumbRsp;
        friend class BtBipPutAttachRsp;
        friend class BtBipPutReq;
        friend class BtBipAbortReq;
        friend class BtBipGetRsp;
        friend class BtBipGetImagingCapabilitiesRsp;
        friend class BtBipGetImagesListRsp;
        friend class BtBipGetImageRsp;

};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif  // BtBipController_hpp


