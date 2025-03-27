/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipServerService_hpp)
#define BtBipServerService_hpp

#include <Bluetooth/BIP/BtBipService.hpp>
#include <Bluetooth/BIP/BtBipController.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>
#include <Bluetooth/BIP/BtBipPutImageRsp.hpp>
#include <Bluetooth/BIP/BtBipPutThumbRsp.hpp>
#include <Bluetooth/BIP/BtBipPutAttachRsp.hpp>
#include <Bluetooth/BIP/BtBipGetImagingCapabilitiesRsp.hpp>
#include <Bluetooth/BIP/BtBipGetImagePropertiesRsp.hpp>
#include <Bluetooth/BIP/BtBipGetImagesListRsp.hpp>
#include <Bluetooth/BIP/BtBipGetImageRsp.hpp>
#include <Bluetooth/BIP/BtBipGetLinkedThumbnailRsp.hpp>
#include <Bluetooth/BIP/BtBipGetLinkedAttachmentRsp.hpp>

#include <Auxiliary/DataSink.hpp>
#include <Auxiliary/DataSource.hpp>


class BtBipServerService : public BtBipService
{
    friend class BtBipController;

    private:
        typedef BtBipService Base;

    public:

        BtBipServerService();

        virtual ~BtBipServerService();


        virtual BtRequestState GetRequestState(BtRequestType request_type) const {
            return BtRqsUnknown;
        }


        virtual BOOLEAN IsServerService() const;

        BOOLEAN RegisterBipServer();


        UINT8 GetRfComChannel() const;


        BOOLEAN ConnectRsp(BtObexResponseCode obex_result);


        BOOLEAN AbortRsp(BtObexResponseCode obex_result);


        BOOLEAN Cancel(BtObexResponseCode obex_result);
            

        BOOLEAN PutImageRsp(BtObexResponseCode obex_result, const BtBipImageHdlPtr& hdl, const DataSinkPtr& image);


        BOOLEAN PutLinkedThumbnailRsp(BtObexResponseCode obex_result, const DataSinkPtr& thumb);


        BOOLEAN PutLinkedAttachmentRsp(BtObexResponseCode obex_result, const DataSinkPtr& attach);


        BOOLEAN GetImagingCapabilitiesRsp(BtObexResponseCode obex_result, const BtBipImagingCapabilitiesPtr& img_cap);


        BOOLEAN GetImagesListRsp(BtObexResponseCode obex_result, const BtBipImageListPtr& image_list, const BtBipImageHdlDescPtr& applied_filter);


        BOOLEAN GetImagePropertiesRsp(BtObexResponseCode obex_result, const BtBipImagePropertiesPtr& img_props);


        BOOLEAN GetImageRsp(BtObexResponseCode obex_result, UINT32 file_length, const DataSourcePtr& img); 


        BOOLEAN GetLinkedThumbnailRsp(BtObexResponseCode obex_result, const DataSourcePtr& thumb);


        BOOLEAN GetLinkedAttachmentRsp(BtObexResponseCode obex_result, const DataSourcePtr& attach);
        

        BOOLEAN DeleteImageRsp(BtObexResponseCode obex_result);


        BOOLEAN ErrorRsp(BtRequestState rc);
    

        UINT32  GetProgressInBytes();


#ifndef DOXYGEN_SHOULD_SKIP_THIS

        virtual BOOLEAN OnMessage(const Message& msg);
#endif

    protected:
        virtual void RegisterMessages() const;
        virtual void UnregisterMessages() const;

        virtual void OnRequestStateChange(BtRequestType request_type, BtRequestState old_request_state, BtRequestState new_request_state) {}

    private:

        void ConnectInd(BtBipSessionId session_id, const BtDeviceAddress& device_adr);
        void DisconnectInd();
        void AbortInd(const WString& desc);
        void PutImageInd(const WString& name, const UINT8* img_desc, UINT16 img_desc_len, const UINT8* body, UINT16 body_len, BOOLEAN last_msg);
        void PutLinkedThumbnailInd(const BtBipImageHdlPtr& img_handle, const UINT8* body, UINT16 body_len, BOOLEAN last_msg);
        void PutLinkedAttachmentInd(const BtBipImageHdlPtr& img_handle, const UINT8* attach_desc, UINT16 attach_desc_len, const UINT8* body, UINT16 body_len, BOOLEAN last_msg);
        void GetImagingCapabilitiesInd();
        void GetImagesListInd(UINT16 first_index, UINT16 max_images, BOOLEAN sort_by_latest_first, UINT16 filter_len, UINT8* filter);
        void GetImagePropertiesInd(const BtBipImageHdlPtr& img_hdl);
        void GetImageInd(const BtBipImageHdlPtr& img_hdl, const UINT8* img_desc, UINT16 img_desc_len);
        void BodyCompleteInd();
        void GetLinkedThumbnailInd(const BtBipImageHdlPtr& img_handle);
        void GetLinkedAttachmentInd(const BtBipImageHdlPtr& img_handle, const WString& file_name);
        void DeleteImageInd(const BtBipImageHdlPtr& img_handle);



        BtBipPutRsp*        m_cur_put_rsp;
        BtBipPutImageRsp    m_put_img_rsp;
        BtBipPutThumbRsp    m_put_thumb_rsp;
        BtBipPutAttachRsp   m_put_attach_rsp;

        BtBipGetRsp*        m_cur_get_rsp;

        BtBipGetImagingCapabilitiesRsp  m_get_img_caps_rsp;
        BtBipGetImagesListRsp           m_get_imgs_list_rsp;
        BtBipGetImageRsp                m_get_img_rsp;
        BtBipGetLinkedThumbnailRsp      m_get_thumb_rsp;
        BtBipGetLinkedAttachmentRsp     m_get_attach_rsp;
        BtBipGetImagePropertiesRsp      m_get_img_props_rsp;
};
#endif  // BtBipServerService_hpp

