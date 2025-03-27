/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipTypes_hpp)
#define BtBipTypes_hpp

// Imaging Capabilities

#include <Bluetooth/BtObexResponseCode.hpp>

/*  ------------------------------------------------------------------------
    Enums
    ------------------------------------------------------------------------ */

enum BtBipEncoding {

    // BtBip specified standard encodings
    BtBipJpeg,
    BtBipGif,
    BtBipWBmp,
    BtBipPng,
    BtBipJpeg2000,
    BtBipBmp,

    BtBipInvalidEncoding

    // BtBip User defineable encodings
};

enum BtBipTransformation {
    BtBipNone = 0,
    BtBipStretch = 1,
    BtBipCrop = 2,
    BtBipFill = 3,
    BtBipInvalidTransformation = 4
};

enum BtBipResult {
    BipOk,
    BipContinue,
    BipPartialContent,
    BipCallError,
    BipObexFailed,
    BipSdapFailed,
    BipPadaptFailed,
};

enum BtBipSessionId {
    BipImagePush,
    BipImagePull,
    BipInvalidSessionId
};

/*enum BtBipObexResult {
    BipObexOk,
    BipObexContinue,
    BipObexPartialContent,
    
    BipObexBadRequest,
    BipObexNotImplemented,
    BipObexForbidden,
    BipObexUnauthorised,
    BipObexPreconditionFailed,
    BipObexNotFound,
    BipObexNotAcceptable,
    BipObexServiceUnavailable,
    BipObexUndefined
};*/

extern const int c_bip_invalid_res;

#define BIP_IMG_HDL_SIZE 8

/*  ------------------------------------------------------------------------
    Data Wrappers
    ------------------------------------------------------------------------ */

class BtBipImageFormat
{
public:
    
    struct ImageDim {
        UINT16 min_width;
        UINT16 min_height;
        UINT16 max_width;
        UINT16 max_height;
    };

    void SetEncoding(BtBipEncoding encoding) { m_encoding = encoding; }
    
    void SetImageDim(UINT16 width, UINT16 height);
    
    void SetImageDim(UINT16 min_width, UINT16 max_width, UINT16 max_height);

    void SetImageDim(UINT16 min_width, UINT16 min_height, UINT16 max_width, UINT16 max_height);

    void SetMaxImageSize(UINT32 max_size) { m_max_size = max_size; }

    void SetTransformation(BtBipTransformation transformation) { m_transformation = transformation; }

    BtBipEncoding GetEncoding() const { return m_encoding; }
    
    void GetImageDim(ImageDim& dim) const { dim = m_dim; }

    const ImageDim& GetImageDim() const { return m_dim; }

    UINT32 GetMaxImageSize() const { return m_max_size; }

    BtBipTransformation GetTransformation() const { return m_transformation; }


private:
    BtBipEncoding m_encoding;
    BtBipTransformation m_transformation;

    ImageDim m_dim;

    UINT32 m_max_size;
};

typedef NiSharedPtr<BtBipImageFormat> BtBipImageFormatPtr;

class BtBipImageDesc;

typedef NiSharedPtr<BtBipImageDesc> BtBipImageDescPtr;


class BtBipImageDesc
{
public:
    void SetEncoding(BtBipEncoding encoding) { 
        m_img_format.SetEncoding(encoding);
    }

    void SetImageDim(UINT16 width, UINT16 height) { 
        m_img_format.SetImageDim(width, height); 
    }

    void SetImageDim(UINT16 min_width, UINT16 max_width, UINT16 max_height) { 
        m_img_format.SetImageDim(min_width, max_width, max_height); 
    }

    void SetImageDim(UINT16 min_width, UINT16 min_height, UINT16 max_width, UINT16 max_height) {
        m_img_format.SetImageDim(min_width, min_height, max_width, max_height); 
    }

    void SetMaxImageSize(UINT32 max_size) { m_img_format.SetMaxImageSize(max_size); }

    void SetTransformation(BtBipTransformation transformation) { 
        m_img_format.SetTransformation(transformation);
    }

    void SetImageSize(UINT32 size) { m_size = size; }

    BtBipEncoding GetEncoding() const { 
        return m_img_format.GetEncoding(); 
    }
    
    BtBipTransformation GetTransformation() const { 
        return m_img_format.GetTransformation(); 
    }

    UINT32 GetMaxImageSize() const { 
        return m_img_format.GetMaxImageSize(); 
    }

    void GetImageDim(BtBipImageFormat::ImageDim& dim) const { 
        m_img_format.GetImageDim(dim); 
    }

    const BtBipImageFormat::ImageDim& GetImageDim() const {
        return m_img_format.GetImageDim();
    }

    UINT32 GetImageSize() const { return m_size; }

private:
    BtBipImageFormat m_img_format;
    UINT32           m_size;
};


class BtBipImageHdl;

typedef NiSharedPtr<BtBipImageHdl> BtBipImageHdlPtr;

extern const UINT32 c_bip_max_image_hdl;


class BtBipImageHdl
{

public:
    ~BtBipImageHdl();


    static void CreateImageHdl(UINT32 id, BtBipImageHdlPtr& hdl_ptr);

//  BOOLEAN operator == (const BtBipImageHdl& hdl) const { return m_hdl.CompareTo(hdl.m_hdl) == 0; }

    String AsString() { return String((CHAR*)m_hdl, sizeof(m_hdl)); }

private:

    typedef UINT8 ImgHdl[8];

    BtBipImageHdl(UINT32 id);
    BtBipImageHdl(const ImgHdl* id);

    static void  CreateImageHdl(const ImgHdl* id, BtBipImageHdlPtr& hdl_ptr);

    const ImgHdl* GetHdl() const { return &m_hdl; }

    ImgHdl m_hdl;

//  friend class BtBipClientService;
    friend class BtBipServerService;
    friend class BtBipPutImageReq;
    friend class BtBipPutThumbReq;
    friend class BtBipPutAttachReq;
    friend class BtBipGetImagePropertiesReq;
    friend class BtBipGetImageReq;
    friend class BtBipGetLinkedThumbnailReq;
    friend class BtBipGetLinkedAttachmentReq;
    friend class BtBipDeleteImageReq;
    friend class BtBipController;
    friend class BtBipDataConverter;
    // hack to make integration possible, think about twice another time
    friend class BtBipMecelXmlConverter;
};


class BtBipImageHdlDesc
{
public:
    BtBipImageHdlDesc();
    virtual ~BtBipImageHdlDesc();

    void SetCreatedFrom(UINT16 year, UINT16 month, UINT16 day, UINT16 hour=0, UINT16 minute=0, UINT16 second=0);
    void SetCreatedFrom(const DateTime& from) { m_created_from = from;  }
    void SetCreatedTo(UINT16 year, UINT16 month, UINT16 day, UINT16 hour=23, UINT16 minut=59, UINT16 second=59);
    void SetCreatedTo(const DateTime& to) { m_created_to = to; }

    void SetModifiedFrom(UINT16 year, UINT16 month, UINT16 day, UINT16 hour, UINT16 minute, UINT16 second);
    void SetModifiedFrom(const DateTime& from) { m_modified_from = from; }
    void SetModifiedTo(UINT16 year, UINT16 month, UINT16 day, UINT16 hour, UINT16 minute, UINT16 second);
    void SetModifiedTo(const DateTime& to) { m_modified_to = to; }

    void SetEncoding(BtBipEncoding encoding) { m_img_format.SetEncoding(encoding); }

    void SetImageDim(UINT16 width, UINT16 height) { m_img_format.SetImageDim(width, height); }
    void SetImageDim(UINT16 min_width, UINT16 max_width, UINT16 max_height) { 
        m_img_format.SetImageDim(min_width, max_width, max_height);
    }

    void SetImageDim(UINT16 min_width, UINT16 min_height, UINT16 max_width, UINT16 max_height) {
        m_img_format.SetImageDim(min_width, min_height, max_width, max_height);
    }

    const DateTime& GetCreatedFrom() const { return m_created_from; }
    const DateTime& GetCreatedTo() const { return m_created_to; }
    const DateTime& GetModifiedFrom() const { return m_modified_from; }
    const DateTime& GetModifiedTo() const { return m_modified_to; }

    void GetImageDim(BtBipImageFormat::ImageDim& dim) const { 
        m_img_format.GetImageDim(dim); 
    }
    
    const BtBipImageFormat::ImageDim& GetImageDim() const { return m_img_format.GetImageDim(); }
    
    BtBipEncoding GetEncoding() const { return m_img_format.GetEncoding(); }

private:
    DateTime m_created_from;
    DateTime m_created_to;
    
    DateTime m_modified_from;
    DateTime m_modified_to;

    BtBipImageFormat m_img_format;
};

typedef NiSharedPtr<BtBipImageHdlDesc> BtBipImageHdlDescPtr;


class BtBipImage;
typedef NiSharedPtr<BtBipImage> BtBipImagePtr;

class BtBipImage
{
public:
    BtBipImage(const BtBipImageHdlPtr& hdl, const DateTime& created, const DateTime& modified);
    virtual ~BtBipImage();

    void SetImageHdl(const BtBipImageHdlPtr& hdl) { m_img_hdl = hdl; }
    void SetCreatedDate(const DateTime& created) { m_created = created; }
    void SetModifiedDate(const DateTime& modified) { m_modified = modified; }

    const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }
    const DateTime& GetCreated() const { return m_created; }
    const DateTime& GetModified() const { return m_modified; }

private:
    BtBipImageHdlPtr m_img_hdl;
    DateTime m_created;
    DateTime m_modified;  
};

class BtBipImageList
{
public:
    typedef Vector<BtBipImagePtr> ImageList;

    BtBipImageList();
    virtual ~BtBipImageList();

    void AddImage(const BtBipImagePtr& image);
    void AddImage(const BtBipImageHdlPtr& handle, const DateTime& created, const DateTime& modified);

    const ImageList& GetImageList() const { return m_image_list; }

private:
    ImageList m_image_list;
};

typedef NiSharedPtr<BtBipImageList> BtBipImageListPtr;

class BtBipAttachmentFormat
{
public:
    BtBipAttachmentFormat();
    ~BtBipAttachmentFormat();
    void SetMimeType(ApoxiMimeTypeId mime_type) { m_mime_type = mime_type; }
    void SetCharset(const String& charset) { m_charset = charset; }

    ApoxiMimeTypeId GetMimeType() const { return m_mime_type; }
    const String& GetCharset() const { return m_charset; }

private:
    ApoxiMimeTypeId m_mime_type;
    String m_charset;
};

typedef NiSharedPtr<BtBipAttachmentFormat> BtBipAttachmentFormatPtr;

class BtBipImagingCapabilities
{
public:
    typedef Vector<BtBipImageFormatPtr> BtBipImageFormatList;
    typedef Vector<BtBipAttachmentFormatPtr> BtBipAttachmentFormatList;

    BtBipImagingCapabilities();
    ~BtBipImagingCapabilities();

    void SetPreferredFormat(const BtBipImageFormat& format) { m_preferred_format = format; }

    void SetPreferredFormat(BtBipEncoding encoding, UINT16 width, UINT16 height, BtBipTransformation transformation, UINT32 max_size);

    /* The height of an image is calculated using the formula H=(W*H2)/W2.
       The aspect ratio of the image is not changed.
       @param min_width min. width of image
       @param max_width max. width of image
       @param max_height max. height of image
    */
    void SetPreferredFormat(BtBipEncoding encoding, UINT16 min_width, UINT16 max_width, UINT16 max_height, BtBipTransformation transformation, UINT32 max_size);

    /* An image can be transformed freely, the aspect ratio may be changed. */
    void SetPreferredFormat(BtBipEncoding encoding, UINT16 min_width, UINT16 min_height, UINT16 max_width, UINT16 max_height, BtBipTransformation transformation, UINT32 max_size);

    void AddImageFormat(const BtBipImageFormatPtr& format) { m_supported_img_formats.PushBack(format); }
    void AddImageFormat(BtBipEncoding, UINT16 res_x, UINT16 res_y, UINT32 max_size);
    
    void AddAttachmentFormat(const BtBipAttachmentFormatPtr& format) { m_supported_attach_formats.PushBack(format); }
    void AddAttachmentFormat(ApoxiMimeTypeId mime_type, const String& charset);
    
    void SetDpofOptions(UINT8 dpof_options) { m_dpof_options = dpof_options; }
    void SetFilterParamters(UINT8 filter_params) { m_filter_params = filter_params; }

    const BtBipImageFormat& GetPreferredFormat() const { return m_preferred_format; }
    BtBipEncoding GetPrefEncoding() const { return m_preferred_format.GetEncoding(); }
    UINT8   GetDpofOptions() const { return m_dpof_options; }
    UINT8   GetFilterParams() const { return m_filter_params; }


    // fix size min(w|h)==max(w|h)
    // w/aspect minh == maxh
    // n/aspect ratio min(w|h) like set
    UINT16      GetPrefMinWidth() const { return m_preferred_format.GetImageDim().min_width; }
    UINT16      GetPrefMaxWidth() const { return m_preferred_format.GetImageDim().max_width; }
    UINT16      GetPrefMinHeight() const { return m_preferred_format.GetImageDim().min_height; }
    UINT16      GetPrefMaxHeight() const { return m_preferred_format.GetImageDim().max_height; }
    UINT16      GetPrefTransformation() const { return m_preferred_format.GetTransformation(); }
    UINT32      GetPrefMaxSize() const { return m_preferred_format.GetMaxImageSize(); }

    BOOLEAN     IsDpofOptionSupported(UINT8 dpof_options) const { return (m_dpof_options & dpof_options) > 0; }
    BOOLEAN     IsFilterSupported(UINT8 filter) const { return (m_filter_params & filter) > 0; }

    const BtBipImageFormatList& GetSupportedImageFormatList() const { return m_supported_img_formats; }
    const BtBipAttachmentFormatList& GetSupportedAttachmentFormatList() const { return m_supported_attach_formats; }

private:
    UINT8                   m_dpof_options;
    UINT8                   m_filter_params;

    BtBipImageFormat            m_preferred_format;
    BtBipImageFormatList        m_supported_img_formats;
    BtBipAttachmentFormatList   m_supported_attach_formats;
};

typedef NiSharedPtr<BtBipImagingCapabilities> BtBipImagingCapabilitiesPtr;


class BtBipAttachment 
{
public:
    void SetAttachmentFormat(const BtBipAttachmentFormat& format) { m_format = format; }
    void SetMimeType(ApoxiMimeTypeId mime_type) { m_format.SetMimeType(mime_type); }
    void SetCharset(const String& charset) { m_format.SetCharset(charset); }

    void SetName(const String& name){ m_name = name; }
    void SetSize(UINT32 size){ m_size = size; }
    void SetCreateDate(const DateTime& date) { m_created = date; }
    void SetModifyDate(const DateTime& date) { m_modified = date; }

    ApoxiMimeTypeId GetMimeType() { return m_format.GetMimeType(); }
    const String& GetCharset() { return m_format.GetCharset(); }
    const String& GetName() { return m_name; }
    const DateTime& GetCreateDate() { return m_created; }
    const DateTime& GetModifyDate() { return m_modified; }
    UINT32 GetSize() { return m_size; }
    
private:
    BtBipAttachmentFormat m_format;
    String              m_name;
    UINT32              m_size;
    DateTime            m_created;
    DateTime            m_modified;
};

typedef NiSharedPtr<BtBipAttachment> BtBipAttachmentPtr;



class BtBipAttachmentDesc
{
public:

    BtBipAttachmentDesc();
    ~BtBipAttachmentDesc();

    void SetMimeType(ApoxiMimeTypeId mime_type) { m_format.SetMimeType(mime_type); }
    void SetCharset(const String& charset) { m_format.SetCharset(charset); }

    void SetName(const String& name){ m_name = name; }
    void SetSize(UINT32 size){ m_size = size; }
    void SetCreateDate(const DateTime& date) { m_created = date; }

    ApoxiMimeTypeId GetMimeType() const { return m_format.GetMimeType(); }
    const String& GetCharset() const { return m_format.GetCharset(); }
    const String& GetName() const { return m_name; }
    const DateTime& GetCreated() const { return m_created; }
    UINT32 GetSize() const { return m_size; }
    
private:
    BtBipAttachmentFormat m_format;
    String              m_name;
    UINT32              m_size;
    DateTime            m_created;
};

typedef NiSharedPtr<BtBipAttachmentDesc> BtBipAttachmentDescPtr;

class BtBipImageProperties
{
public:
    typedef Vector<BtBipImageFormatPtr> BtBipVariantList;
    typedef Vector<BtBipAttachmentPtr> BtBipAttachmentList;

    void SetImageHandle(const BtBipImageHdlPtr& hdl)  { m_img_hdl = hdl; }
    void SetFriendlyName(const String& name) { m_img_name = name; }

    void SetNativeFormat(const BtBipImageFormat& fmt) { m_native_fmt = fmt; }
    void SetNativeEncoding(BtBipEncoding encoding) { m_native_fmt.SetEncoding(encoding); }
    void SetNativeDim(UINT16 width, UINT16 height) { m_native_fmt.SetImageDim(width, height); }
    void SetNativeSize(UINT32 size) { m_native_fmt.SetMaxImageSize(size); }

    void AddVariant(const BtBipImageFormatPtr& fmt) { m_variants.PushBack(fmt); }
    void AddVariant(BtBipEncoding encoding, UINT16 width, UINT16 height, UINT32 max_size, BtBipTransformation transformation);
    void AddVariant(BtBipEncoding encoding, UINT16 min_width, UINT16 max_width, UINT16 max_height, UINT32 max_size, BtBipTransformation transformation);
    void AddVariant(BtBipEncoding encoding, UINT16 min_width, UINT16 min_height, UINT16 max_width, UINT16 max_height, UINT32 max_size, BtBipTransformation transformation);

    void AddAttachment(const BtBipAttachmentPtr& attach) { m_attaches.PushBack(attach); }
    void AddAttachment(ApoxiMimeTypeId mime_type, const String& charset, const String& name, UINT32 size, const DateTime& created, const DateTime& modified);

    const BtBipImageFormat& GetNativeFormat() const { return m_native_fmt; }
    BtBipEncoding GetNativeEncoding() const { return m_native_fmt.GetEncoding(); }
    UINT16 GetNativeWidth() const { return m_native_fmt.GetImageDim().min_width; }
    UINT16 GetNativeHeight() const { return m_native_fmt.GetImageDim().min_height; }

    const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }
    const String& GetImageName() const { return m_img_name; }
    UINT32 GetNativeSize() const { return m_native_fmt.GetMaxImageSize(); }

    const BtBipVariantList& GetVariantList() const { return m_variants; }
    const BtBipAttachmentList& GetAttachmentList() const { return m_attaches; }

private:
    BtBipImageHdlPtr        m_img_hdl;
    String                  m_img_name;

    BtBipImageFormat        m_native_fmt;
    BtBipVariantList        m_variants;
    BtBipAttachmentList     m_attaches;
};

typedef NiSharedPtr<BtBipImageProperties> BtBipImagePropertiesPtr;


#endif // BtBipTypes_hpp

