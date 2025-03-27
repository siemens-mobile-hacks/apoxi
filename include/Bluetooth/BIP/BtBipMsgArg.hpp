/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------*/

#if !defined(Bluetooth_BtBipMsgArg_hpp)
#define Bluetooth_BtBipMsgArg_hpp


typedef NiSharedPtr<BtBipMsgArg> BtBipMsgArgPtr;

class BtBipMsgArg
{
public:
    BtBipMsgArg();
    virtual ~BtBipMsgArg();
};


class BtBipGetImagingCapabilitesIndArg : public BtBipMsgArg
{
    enum {
        ID = 9
    };

    BtBipGetImagingCapabilitiesIndArg();
};


class BtBipPutImageIndArg : public BtBipMsgArg
{
    enum  {
        ID = 10
    };

    BtBipPutImageIndArg(const WString& name, const BipImageDescriptor& img_desc, BOOLEAN img_complete);

private:
    WString name;
    BipImageDescriptor img_desc;
    DataSourcePtr img;
    BOOLEAN img_complete;
};



class BtBipPutLinkedThumbnailIndArg : public BtBipMsgArg
{
    enum  {
        ID = 11
    };

    BtBipPutLinkedThumbnailIndArg(const BipImageHandle& img_handle, BOOLEAN thumb_complete);
};


class BtBipPutLinkedAttachmentInd : public BtBipMsgArg
{
    enum  {
        ID = 12
    };

    BtBipPutLinkedAttachmentInd(const BipImageHandle& img_handle, const BipImageDescriptor& img_desc, BOOLEAN attachment_complete)
};


class BtBipGetImagesListInd : public BtBipMsgArg
{
    enum  {
        ID = 13
    };

    BtBipGetImagesListInd(INT first_index, INT max_images, BOOLEAN sort_by_latest_first, const ImageHandleDescriptor& filter);
};


class BtBipGetImagePropertiesInd : public BtBipMsgArg
{
    enum  {
        ID = 14
    };

    BtBipGetImagePropertiesInd(const BipImageHandle& img_handle);
};


class BtBipGetImageInd : public BtBipMsgArg
{
    enum  {
        ID = 15
    };

    BtBipGetImageInd(const BipImageHandle& img_handle, const BipImageDescriptor& img_desc);
};


class BtBipGetLinkedThumbnailInd : public BtBipMsgArg
{
    enum  {
        ID = 16
    };

    BtBipGetLinkedThumbnailInd(const BipImageHandle& img_handle);
};


class BtBipGetLinkedAttachmentInd : public BtBipMsgArg
{
    enum  {
        ID = 17
    };

    BtBipGetLinkedAttachmentInd(const BipImageHandle& img_handle, const WString& file_name);
};


class BtBipDeleteImageIndArg : public BtBipMsgArg
{
    enum  {
        ID = 18
    };

    BtBipDeleteImageIndArg(const BipImageHandle& img_handle);
};

#endif // Bluetooth_BtBipMsgArg_hpp

