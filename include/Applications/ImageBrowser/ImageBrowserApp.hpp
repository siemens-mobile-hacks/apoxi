/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageBrowserApp_hpp)
#define Apoxi_ImageBrowserApp_hpp
#include <Afs/Rfs/StorageDevice.hpp>
#include <Common/MmiServices.hpp>
#include <Common/MmiApplication.hpp>
#include <Common/MmiWaitingBox.hpp>
#include <ImageBrowser/Common/BrowserSaveWin.hpp>
#include <ImageBrowser/Common/MediaFilter.hpp>
#include <ImageBrowser/Common/RenameFileDialog.hpp>
#include <Atl/Gui/MmiItemListWindow.hpp>

#include "ImageBrowserDetailWin.hpp"

#include "ImageRefContainer.hpp"

class ImageRef;
class ImageRefContainer;
class ImageFilter;

class ImageBrowserApp : public MmiApplication, public ImageManagementService
{
    typedef MmiApplication Base;

    public:

        virtual ~ImageBrowserApp();

        static ImageBrowserApp* GetInstance() { return &m_app; }

        virtual void OnStartup();

       BOOLEAN  m_mirrored;
        BOOLEAN  m_reversed;
        ServiceResult SelectImage(MediaRefPtr &img_ref,
            const ImageFilter &img_filter = ImageFilter());


        ServiceResult SaveImage(const BinData *raw_data, const Path &path, DrmMimeType drm_mime_type, MimeType mime_type);
        ServiceResult SaveImage(const Image *image, const Path &path);
        ServiceResult GetResourceNames(Vector<Path>& paths, const ImageFilter& image_filter = ImageFilter());


    protected:

        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);

        virtual DataItem GetContextDataItem(ContextFeature *feature);

        void OnOpen();

        void OnClose();

        BOOLEAN OnMessage(const Message &msg);

    private:

        ImageBrowserApp();

        Image* ProcessDrmImage(FfsDrmAttrib &attrib,ImageRef &img_ref);

        INT AddToImageDb(MediaRefPtr &image_ref_ptr,FfsDrmAttrib &attrib);


        void OpenBrowser();

        void ShowImage();

        void Delete();

        void Rename();

        void Select();

        void DisplayInfo(BOOLEAN is_media_info = TRUE) const;

        // Updates the item container
        void UpdateItemContainer(INT idx = -1, BOOLEAN delete_elem = FALSE);

        // Updates the Image List
        void UpdateImageList(BOOLEAN app_filer = FALSE);
        //
        void SendAsMms();
        //
        void HandleErrImg(UINT8 err_no);
    #if defined(APOXI_INCLUDE_DRM)
        INT HandleDcf(MediaRefPtr &img_ref_ptr);
    #endif

        void HandleSelectImage();
        void HandleSaveImage();
        void HandleMmc();
        void HandleImg();

    private:

        enum OpenMode {
            NotOpen,
            OpenSelectionService,
            OpenSaveService,
            OpenApplication
        };

        enum FeatureItemIds {
            IbImageBrowser,
            IbMmc, 
            IbSelect,
            IbShow,
            IbRename,
            IbDelete,
            IbScreenSaver, //shown as menu item in ScreenSaver Settings
            IbWallPaper,
            IbInfo,
#if defined(APOXI_INCLUDE_DRM)
            IbDrmInfo,
#endif
            IbSendAsMms,
            IbClose,
            Mirror,
            Reverse,
            Start,
            Stop,
            IbFeatureCnt
        };

        enum ServiceState {
            NoService,
            SelectService,
            SaveService
        };

        Feature m_items[IbFeatureCnt];
        OpenMode m_mode;

        static ImageBrowserApp m_app;
        BrowserSaveWin m_browser_save_win;

        static BooleanCondition s_condition_sel;
        MmiWaitingBox m_saving_pro_win;

        ImageRefContainer *m_img_refs;

        ItemContainer* m_item_cont;
        MmiItemListWindow m_media_list_win;
        RenameFileDialog m_rename_file_dialog;

        ServiceState m_srv_state;
        BOOLEAN m_srv_success;

        MediaFilter *p_image_filter;

        const BinData *m_bin_data;
        const Image *m_image;
        DrmMimeType m_drm_mime_type;
        MimeType    m_mime_type;
        Path        m_path;

        ImageBrowserDetailWin image_win;


}; // ImageBrowserApp

#endif  // Apoxi_ImageBrowserApp_hpp
