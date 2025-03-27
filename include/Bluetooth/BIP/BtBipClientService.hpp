/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipClientService_hpp)
#define BtBipClientService_hpp
#include <Auxiliary/DataSink.hpp>
#include <Auxiliary/DataSource.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtTypes.hpp>

#include <Bluetooth/BIP/BtBipService.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>
#include <Bluetooth/BIP/BtBipConnectReq.hpp>
#include <Bluetooth/BIP/BtBipDisconnectReq.hpp>
#include <Bluetooth/BIP/BtBipPutImageReq.hpp>
#include <Bluetooth/BIP/BtBipPutThumbReq.hpp>
#include <Bluetooth/BIP/BtBipGetImagingCapabilitiesReq.hpp>
#include <Bluetooth/BIP/BtBipGetImagePropertiesReq.hpp>
#include <Bluetooth/BIP/BtBipPutAttachReq.hpp>
#include <Bluetooth/BIP/BtBipGetImagesListReq.hpp>
#include <Bluetooth/BIP/BtBipGetImageReq.hpp>
#include <Bluetooth/BIP/BtBipGetLinkedThumbnailReq.hpp>
#include <Bluetooth/BIP/BtBipGetLinkedAttachmentReq.hpp>
#include <Bluetooth/BIP/BtBipDeleteImageReq.hpp>


#include <Gui/ImageObtainer.hpp>

//#include "BtBipConnectReq.hpp"


extern const UINT16 c_bip_client_read_buf_size;

class BtBipClientService : public BtBipService
{
    private:
        typedef BtBipService Base;

    public:
        BtBipClientService();

        virtual ~BtBipClientService();


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual BOOLEAN IsServerService() const;


        BOOLEAN IsConnected() const;

        // General requests

        BtRequestState ConnectReq(BtBipSessionId session_id, const BtDevice& device);


        BtRequestState DisconnectReq();


        BtRequestState AbortReq(const WString& reason);


        BtRequestState GetImagingCapabilitiesReq();

        // Image Push
        

        BtRequestState PutImageReq(const WString& name, const BtBipImageDescPtr& img_desc, const DataSourcePtr& img);


        BtRequestState PutImageReq(const WString& name, BtBipImageDescPtr& img_desc, const ImageObtainer& image);


        BtRequestState PutImageReq(const WString& name, const ImageObtainer& image);


        BtRequestState PutLinkedThumbnailReq(const BtBipImageHdlPtr& img_hdl, const ImageObtainer& thumb);


        BtRequestState PutLinkedThumbnailReq(const BtBipImageHdlPtr& img_hdl, const DataSourcePtr& thumb);


        BtRequestState PutLinkedAttachmentReq(const BtBipImageHdlPtr& img_hdl, const BtBipAttachmentDescPtr& attach_desc, const DataSourcePtr& attach);

        // Image Pull

        BtRequestState GetImagesListReq(UINT16 first_index, UINT16 max_images, BOOLEAN sort_by_latest_first, const BtBipImageHdlDescPtr& filter);


        BtRequestState GetImagePropertiesReq(const BtBipImageHdlPtr& img_hdl);


        BtRequestState GetImageReq(const BtBipImageHdlPtr& img_hdl, const BtBipImageDescPtr& img_desc, const DataSinkPtr& image);


        BtRequestState GetLinkedThumbnailReq(const BtBipImageHdlPtr& img_hdl, const DataSinkPtr& thumb);


        BtRequestState GetLinkedAttachmentReq(const BtBipImageHdlPtr& img_hdl, const WString& file_name, const DataSinkPtr& attach);


        BtRequestState DeleteImageReq(const BtBipImageHdlPtr& img_hdl);

        BtResultCode GetResult();

        BtObexResponseCode GetObexResponseCode();

        BtBipResult GetBipResult();


        BtResultCode GetImagingCapabilites(BtBipImagingCapabilitiesPtr& caps);


        BtResultCode GetImageHdl(BtBipImageHdlPtr& img_hdl);


        BtResultCode GetImagesList(BtBipImageListPtr& img_list);
        

        BtResultCode GetImageProperties(BtBipImagePropertiesPtr& props);


        UINT32  GetProgressInBytes() {return m_cur_req ? m_cur_req->GetBytesTransfered():0; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        virtual BOOLEAN OnMessage(const Message& msg);
#endif  

    protected:
        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);

        virtual void RegisterMessages() const;
        virtual void UnregisterMessages() const;

    private:

        BOOLEAN PutNextPacket();
        BOOLEAN GetNextPacket();

        BtBipConnectReq                 m_connect_req;
        BtBipDisconnectReq              m_disconnect_req;
        BtBipGetImagingCapabilitiesReq  m_get_cap_req;
        BtBipPutImageReq                m_put_img_req;
        BtBipPutThumbReq                m_put_thumb_req;
        BtBipPutAttachReq               m_put_attach_req;
        BtBipGetImagesListReq           m_get_imgs_list_req;
        BtBipGetImageReq                m_get_img_req;
        BtBipGetLinkedThumbnailReq      m_get_thumb_req;
        BtBipGetLinkedAttachmentReq     m_get_attach_req;
        BtBipDeleteImageReq             m_delete_img_req;
        BtBipGetImagePropertiesReq      m_get_img_props_req;

        // currently active request
        BtBipReq*                       m_cur_req;

        friend class BtBipConnectReq;
};

#endif  // BtBipClientService_hpp


