/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
*/

#if !defined(Bluetooth_BIP_BtBipServerNotificationMsgArg_hpp)
#define Bluetooth_BIP_BtBipServerNotificationMsgArg_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/DataSource.hpp>
#include <Auxiliary/DataSink.hpp>

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

// Base class for all BtBipServerNotificationMsgArgs
class BtBipServerNotificationMsgArg
{
public:
    BtBipServerNotificationMsgArg(INT id);
    virtual ~BtBipServerNotificationMsgArg();

    INT Id() const { return m_id; }

private:
    INT m_id;
};

typedef NiSharedPtr<BtBipServerNotificationMsgArg> BtBipServerNotificationMsgArgPtr;


/*  ------------------------------------------------------------------------
    Connect
    ------------------------------------------------------------------------ */


class BtBipConnectIndArg : public BtBipServerNotificationMsgArg {
 
    typedef BtBipServerNotificationMsgArg Base;

    public:
        BtBipConnectIndArg(const BtBipSessionId& session_id, const BtDeviceAddress& device_adr);
        virtual ~BtBipConnectIndArg();
        
        static const BtBipConnectIndArg& Cast(const BtBipServerNotificationMsgArg& arg);
        
        BtBipSessionId GetSessionId() const { return m_session_id; }
        const BtDeviceAddress& GetDeviceAdr() const { return m_device_adr; }
        
        enum  {
            ID = 1
            };
        
    private:
        
        BtBipSessionId m_session_id;
        BtDeviceAddress m_device_adr;
        
};

// Inline definitions
inline const BtBipConnectIndArg& BtBipConnectIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipConnectIndArg!\n");
    return ((const BtBipConnectIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    Disconnect
    ------------------------------------------------------------------------ */


class BtBipDisconnectIndArg : public BtBipServerNotificationMsgArg {
 
    typedef BtBipServerNotificationMsgArg Base;

    public:
        BtBipDisconnectIndArg();
        virtual ~BtBipDisconnectIndArg();
        
        static const BtBipDisconnectIndArg& Cast(const BtBipServerNotificationMsgArg& arg);
        
        enum  {
            ID = 2
            };
        
    private:
        
};

// Inline definitions
inline const BtBipDisconnectIndArg& BtBipDisconnectIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipDisconnectIndArg!\n");
    return ((const BtBipDisconnectIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    Abort
    ------------------------------------------------------------------------ */


class BtBipAbortIndArg : public BtBipServerNotificationMsgArg {
 
    typedef BtBipServerNotificationMsgArg Base;

    public:
        BtBipAbortIndArg(const WString& abort_desc);
        virtual ~BtBipAbortIndArg();
        
        static const BtBipAbortIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const WString& GetAbortDesc() const { return m_desc; }
        
        enum  {
            ID = 7
            };
        
    private:
        WString m_desc;
        
};

// Inline definitions
inline const BtBipAbortIndArg& BtBipAbortIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipAbortIndArg!\n");
    return ((const BtBipAbortIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    PutImage
    ------------------------------------------------------------------------ */


class BtBipPutImageIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipPutImageIndArg(const WString& name, const BtBipImageDescPtr& img_desc);
        virtual ~BtBipPutImageIndArg();

        const WString& GetImageName() const { return m_name; }
        const BtBipImageDescPtr& GetImageDesc() const { return m_img_desc; }

        static const BtBipPutImageIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        enum  {
            ID = 3
        };

    private:
        WString m_name;
        BtBipImageDescPtr m_img_desc;
};

// Inline definitions
inline const BtBipPutImageIndArg& BtBipPutImageIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipPutImageIndArg!\n");
    return ((const BtBipPutImageIndArg&) arg);
};


class BtBipPutImageCompleteArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipPutImageCompleteArg(const BtBipImageHdlPtr& img_hdl);
        virtual ~BtBipPutImageCompleteArg();

        static const BtBipPutImageCompleteArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }

        enum  {
            ID = 4
        };

    private:
        BtBipImageHdlPtr    m_img_hdl;
};

// Inline definitions
inline const BtBipPutImageCompleteArg& BtBipPutImageCompleteArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipPutImageIndArg!\n");
    return ((const BtBipPutImageCompleteArg&) arg);
};

/*  ------------------------------------------------------------------------
    PutThumb
    ------------------------------------------------------------------------ */


class BtBipPutLinkedThumbnailIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipPutLinkedThumbnailIndArg(const BtBipImageHdlPtr& img_hdl);
        virtual ~BtBipPutLinkedThumbnailIndArg();

        const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }

        static const BtBipPutLinkedThumbnailIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        enum  {
            ID = 10
        };

    private:
        BtBipImageHdlPtr m_img_hdl;
};

// Inline definitions
inline const BtBipPutLinkedThumbnailIndArg& BtBipPutLinkedThumbnailIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipPutLinkedThumbnailIndArg!\n");
    return ((const BtBipPutLinkedThumbnailIndArg&) arg);
};


class BtBipPutLinkedThumbnailCompleteArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipPutLinkedThumbnailCompleteArg(const BtBipImageHdlPtr& img_hdl);
        virtual ~BtBipPutLinkedThumbnailCompleteArg();

        static const BtBipPutLinkedThumbnailCompleteArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }

        enum  {
            ID = 11
        };

    private:
        BtBipImageHdlPtr    m_img_hdl;
};

// Inline definitions
inline const BtBipPutLinkedThumbnailCompleteArg& BtBipPutLinkedThumbnailCompleteArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipPutLinkedThumbnailCompleteArg!\n");
    return ((const BtBipPutLinkedThumbnailCompleteArg&) arg);
};

/*  ------------------------------------------------------------------------
    PutAttach
    ------------------------------------------------------------------------ */


class BtBipPutLinkedAttachmentIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipPutLinkedAttachmentIndArg(const BtBipImageHdlPtr& img_hdl, const BtBipAttachmentDescPtr& attach_desc);
        virtual ~BtBipPutLinkedAttachmentIndArg();

        const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }
        const BtBipAttachmentDescPtr& GetAttachmentDesc() const { return m_attach_desc; }

        static const BtBipPutLinkedAttachmentIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        enum  {
            ID = 12
        };

    private:
        BtBipImageHdlPtr m_img_hdl;
        BtBipAttachmentDescPtr m_attach_desc;
};

// Inline definitions
inline const BtBipPutLinkedAttachmentIndArg& BtBipPutLinkedAttachmentIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipPutLinkedAttachmentIndArg!\n");
    return ((const BtBipPutLinkedAttachmentIndArg&) arg);
};


class BtBipPutLinkedAttachmentCompleteArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipPutLinkedAttachmentCompleteArg(const BtBipImageHdlPtr& img_hdl);
        virtual ~BtBipPutLinkedAttachmentCompleteArg();

        static const BtBipPutLinkedAttachmentCompleteArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }

        enum  {
            ID = 13
        };

    private:
        BtBipImageHdlPtr    m_img_hdl;
};

// Inline definitions
inline const BtBipPutLinkedAttachmentCompleteArg& BtBipPutLinkedAttachmentCompleteArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipPutLinkedAttachmentCompleteArg!\n");
    return ((const BtBipPutLinkedAttachmentCompleteArg&) arg);
};

/*  ------------------------------------------------------------------------
    BtBipGetImagesListInd
    ------------------------------------------------------------------------ */


class BtBipGetImagesListIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipGetImagesListIndArg(UINT16 first_index, UINT16 max_images, BOOLEAN sort_by_latest_first, const BtBipImageHdlDescPtr& filter);
        virtual ~BtBipGetImagesListIndArg();

        static const BtBipGetImagesListIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        INT GetFirstIndex() const { return m_first_index; }
        INT GetMaxImages() const { return m_max_images; }
        BOOLEAN GetSortByLatestFirst() const { return m_sort_by_latest; }
        const BtBipImageHdlDescPtr& GetFilter() const { return m_filter; }

        enum  {
            ID = 5
        };

    private:
        BtBipImageHdlDescPtr    m_filter;
        UINT16                  m_first_index;
        UINT16                  m_max_images;
        BOOLEAN                 m_sort_by_latest;

};

// Inline definitions
inline const BtBipGetImagesListIndArg& BtBipGetImagesListIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipGetImagesListIndArg!\n");
    return ((const BtBipGetImagesListIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    BtBipGetImageProperties
    ------------------------------------------------------------------------ */


class BtBipGetImagePropertiesIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipGetImagePropertiesIndArg(const BtBipImageHdlPtr& hdl);
        virtual ~BtBipGetImagePropertiesIndArg();

        static const BtBipGetImagePropertiesIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }

        enum  {
            ID = 14
        };

    private:
        BtBipImageHdlPtr        m_img_hdl;
};

// Inline definitions
inline const BtBipGetImagePropertiesIndArg& BtBipGetImagePropertiesIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipGetImagePropertiesIndArg!\n");
    return ((const BtBipGetImagePropertiesIndArg&) arg);
};


class BtBipOpFinishedArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipOpFinishedArg(BtObexResponseCode obex_rsp, BtRequestType request_type);
        virtual ~BtBipOpFinishedArg();

        static const BtBipOpFinishedArg& Cast(const BtBipServerNotificationMsgArg& arg);

        BtObexResponseCode GetObexResult() const { return m_obex_rsp; }

        BtRequestType GetRequestType() const { return m_req_type; }

        enum  {
            ID = 8
        };

    private:
        BtObexResponseCode      m_obex_rsp;
        BtRequestType           m_req_type;
};

// Inline definitions
inline const BtBipOpFinishedArg& BtBipOpFinishedArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipOpFinishedArg!\n");
    return ((const BtBipOpFinishedArg&) arg);
};

/*  ------------------------------------------------------------------------
    BtBipGetImageInd
    ------------------------------------------------------------------------ */


class BtBipGetImageIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipGetImageIndArg(const BtBipImageHdlPtr& img_hdl, const BtBipImageDescPtr& img_desc);
        ~BtBipGetImageIndArg();
 
        static const BtBipGetImageIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHandle() const { return m_img_hdl; }
        const BtBipImageDescPtr& GetImageDesc() const { return m_img_desc; }

        enum  {
            ID = 6
        };

    private:
        BtBipImageHdlPtr m_img_hdl;
        BtBipImageDescPtr m_img_desc;

};

// Inline definitions
inline const BtBipGetImageIndArg& BtBipGetImageIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipGetImageIndArg!\n");
    return ((const BtBipGetImageIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    BtBipGetLinkedThumbnailIndArg
    ------------------------------------------------------------------------ */


class BtBipGetLinkedThumbnailIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipGetLinkedThumbnailIndArg(const BtBipImageHdlPtr& hdl);
        virtual ~BtBipGetLinkedThumbnailIndArg();

        static const BtBipGetLinkedThumbnailIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }

        enum  {
            ID = 15
        };

    private:
        BtBipImageHdlPtr        m_img_hdl;
};

// Inline definitions
inline const BtBipGetLinkedThumbnailIndArg& BtBipGetLinkedThumbnailIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipGetLinkedThumbnailIndArg!\n");
    return ((const BtBipGetLinkedThumbnailIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    BtBipGetLinkedAttachmentIndArg
    ------------------------------------------------------------------------ */


class BtBipGetLinkedAttachmentIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipGetLinkedAttachmentIndArg(const BtBipImageHdlPtr& hdl, const WString& file_name);
        virtual ~BtBipGetLinkedAttachmentIndArg();

        static const BtBipGetLinkedAttachmentIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }
        const WString& GetFileName() const { return m_file_name; }

        enum  {
            ID = 16
        };

    private:
        BtBipImageHdlPtr        m_img_hdl;
        WString                 m_file_name;
};

// Inline definitions
inline const BtBipGetLinkedAttachmentIndArg& BtBipGetLinkedAttachmentIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipGetLinkedAttachmentIndArg!\n");
    return ((const BtBipGetLinkedAttachmentIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    BtBipDeleteImageIndArg
    ------------------------------------------------------------------------ */


class BtBipDeleteImageIndArg : public BtBipServerNotificationMsgArg
{
    typedef BtBipServerNotificationMsgArg Base;

    public:

        BtBipDeleteImageIndArg(const BtBipImageHdlPtr& hdl);
        virtual ~BtBipDeleteImageIndArg();

        static const BtBipDeleteImageIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        const BtBipImageHdlPtr& GetImageHdl() const { return m_img_hdl; }

        enum  {
            ID = 17
        };

    private:
        BtBipImageHdlPtr        m_img_hdl;
};

// Inline definitions
inline const BtBipDeleteImageIndArg& BtBipDeleteImageIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipDeleteImageIndArg!\n");
    return ((const BtBipDeleteImageIndArg&) arg);
};

/*  ------------------------------------------------------------------------
    GetImagingCapabilities
    ------------------------------------------------------------------------ */


class BtBipGetImagingCapabilitiesIndArg : public BtBipServerNotificationMsgArg
{
    private:
        typedef BtBipServerNotificationMsgArg Base;

    public:
        BtBipGetImagingCapabilitiesIndArg();
        ~BtBipGetImagingCapabilitiesIndArg();

        static const BtBipGetImagingCapabilitiesIndArg& Cast(const BtBipServerNotificationMsgArg& arg);

        enum {
            ID = 9
        };
};

// Inline definitions
inline const BtBipGetImagingCapabilitiesIndArg& BtBipGetImagingCapabilitiesIndArg::Cast(const BtBipServerNotificationMsgArg& arg) {
    ASSERT_INFO((arg.Id() == ID), L"BtBipServerNotificationMsgArg failed to cast to BtBipGetImagingCapabilitiesIndArg!\n");
    return ((const BtBipGetImagingCapabilitiesIndArg&) arg);
};


#endif // Bluetooth_BIP_BtBipServerNotificationMsgArg_hpp


