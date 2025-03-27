/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipMecelXMLConverter_hpp)
#define BtBipMecelXMLConverter_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipDataConverter.hpp>

extern const int c_bip_convert_buf_size ;

/*
*/
class BtBipMecelXmlConverter : public BtBipDataConverter
{
public:

    BtBipMecelXmlConverter();

    virtual ~BtBipMecelXmlConverter();

    /* The text can be retrieved once after a conversion. Afterwards, the internal buffer is freed.
       If buffer_handover is set to TRUE, the caller has to take the responsibilitie
       to free the buffer. 
    */
    UINT8* GetXmlText(BOOLEAN buffer_handover = FALSE);
    
    virtual void Init();

    /* Encoding Data->XML */
    virtual BOOLEAN ConvertBipImageDesc(const BtBipImageDesc& img_desc);
    virtual BOOLEAN ConvertBipImageHdlDesc(const BtBipImageHdlDesc& img_hdl_desc);
    virtual BOOLEAN ConvertBipImagesList(const BtBipImageList& img_list);
    virtual BOOLEAN ConvertBipImagingCapabilities(const BtBipImagingCapabilities& img_list);
    virtual BOOLEAN ConvertBipImageProperties(const BtBipImageProperties& img_props);
    virtual BOOLEAN ConvertBipAttachmentDesc(const BtBipAttachmentDesc& attach_hdl_desc);

    /* Decoding XML->Data */
    virtual void ConvertXmlImageDesc(const UINT8* body, UINT16 len, BtBipImageDesc& img_desc);
    virtual void ConvertXmlImageHdlDesc(const UINT8* body, UINT16 len, BtBipImageHdlDesc& img_hdl_desc);
    virtual void ConvertXmlImageList(const UINT8* body, UINT16 len, BtBipImageListPtr& img_list);
    virtual void ConvertXmlImagingCapabilities(const UINT8* body, UINT16 len, BtBipImagingCapabilities& img_list);
    virtual void ConvertXmlImageProperties(const UINT8* body, UINT16 len, BtBipImageProperties& img_props);
    virtual void ConvertXmlAttachmentDesc(const UINT8* body, UINT16 len, BtBipAttachmentDesc& attach_hdl_desc);

private:

    void BtBipMecelXmlConverter::ConvertBipImageDim(const BtBipImageFormat::ImageDim& img_dim, String& dim_str);

    UINT8*  m_buffer;
    UINT8*  m_buffer_ptr;
    UINT16  m_free_bytes;
    BOOLEAN m_keep_buffer;
};
#endif
#endif // BtBipMecelXMLConverter_hpp

