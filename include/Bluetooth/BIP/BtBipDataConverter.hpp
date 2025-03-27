/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipDataConverter_hpp)
#define BtBipDataConverter_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipTypes.hpp>

class BtBipDataConverter
{

public:

    BtBipDataConverter();
    virtual ~BtBipDataConverter();

    virtual void Init() = 0;

    /* Encoding */
    virtual BOOLEAN ConvertBipImageDesc(const BtBipImageDesc& img_desc) = 0;
    virtual BOOLEAN ConvertBipImageHdlDesc(const BtBipImageHdlDesc& img_hdl_desc) = 0;
    virtual BOOLEAN ConvertBipImagesList(const BtBipImageList& img_list) = 0;
    virtual BOOLEAN ConvertBipImagingCapabilities(const BtBipImagingCapabilities& img_list) = 0;
    virtual BOOLEAN ConvertBipImageProperties(const BtBipImageProperties& img_props) = 0;
    virtual BOOLEAN ConvertBipAttachmentDesc(const BtBipAttachmentDesc& attach_hdl_desc) = 0;

    /* Decoding */  
    virtual void ConvertXmlImageDesc(const UINT8* body, UINT16 len, BtBipImageDesc& img_desc) = 0;
    virtual void ConvertXmlImageHdlDesc(const UINT8* body, UINT16 len, BtBipImageHdlDesc& img_hdl_desc) = 0;
    virtual void ConvertXmlImageList(const UINT8* body, UINT16 len, BtBipImageListPtr& img_list) = 0;
    virtual void ConvertXmlImagingCapabilities(const UINT8* body, UINT16 len, BtBipImagingCapabilities& img_list) = 0;
    virtual void ConvertXmlImageProperties(const UINT8* body, UINT16 len, BtBipImageProperties& img_props) = 0;
    virtual void ConvertXmlAttachmentDesc(const UINT8* body, UINT16 len, BtBipAttachmentDesc& attach_hdl_desc)  = 0;

protected:
    BtBipEncoding TextToBtBipEncoding(CHAR* text, UINT16 len);
    void BtBipToTextEncoding(BtBipEncoding encoding, String& enc_str);
    void TextToBtBipImageDim(CHAR* text, UINT16 len, BtBipImageFormat::ImageDim& img_dim);
    
    void CreateImageHdl(const BtBipImageHdl::ImgHdl* hdl, BtBipImageHdlPtr& hdl_ptr) { BtBipImageHdl::CreateImageHdl(hdl, hdl_ptr); }
    const BtBipImageHdl::ImgHdl* GetImageHdl(const BtBipImageHdlPtr& hdl) { return hdl->GetHdl(); }
};

#endif // APOXI_SHOULD SKIP_THIS
#endif // BtBipDataConverter

