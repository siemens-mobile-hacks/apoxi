/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundBrowserApp_hpp)
#define Apoxi_SoundBrowserApp_hpp

#include <Common/MmiServices.hpp>
#include <Common/MmiApplication.hpp>
#include <ImageBrowser/Common/RenameFileDialog.hpp>
#include <ImageBrowser/Common/MediaRefContainer.hpp>
#include <ImageBrowser/Common/BrowserSaveWin.hpp>
#include <ImageBrowser/Common/MediaFilter.hpp>
#include <Atl/Gui/MmiItemListWindow.hpp>

class SoundRef;
class SoundRefContainer;

class SoundBrowserApp : public MmiApplication, public SoundManagementService
{
    typedef MmiApplication Base;

    public:

        virtual ~SoundBrowserApp();

        static SoundBrowserApp* GetInstance() { return &m_app; }

        ServiceResult SelectSound(MediaRefPtr &media_ref_ptr,
            const SoundFilter &snd_filter = SoundFilter());

        ServiceResult SaveSound(const BinData *raw_data, const Path &path, DrmMimeType drm_mime_type, MimeType mime_type);

        ServiceResult GetResourceNames(Vector<Path>& paths, const SoundFilter& sound_filter = SoundFilter());


        //
        virtual BOOLEAN UpdateItem(Item* item);


    protected:

        BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);
        virtual DataItem GetContextDataItem(ContextFeature *feature);

        void OnStartup();

        void OnOpen();

        void OnClose();
        BOOLEAN OnMessage(const Message &msg);

    private:

        SoundBrowserApp();

        void OpenBrowser();

        void PlaySelectedSound();

        void StopSound();

        void Delete();

        void Rename();

        void DisplayInfo(BOOLEAN is_media_info = TRUE) const;

        // Updates the item container
        void UpdateItemContainer(INT idx = -1, BOOLEAN delete_elem = FALSE);
        //
        void SendAsMms();

        //
        void Select();

        // Updates the Image List
        void UpdateSoundList(BOOLEAN filter = FALSE);

        void OnErrorNotification(const SharedPtr<AudioReference>& audio_reference,
                                AudioError::ErrorType err_no);

        void OnStopNotification(const SharedPtr<AudioActiveReference>& active_reference, BOOLEAN auto_stop);
        //
        void HandleSelectSound();
        //
        void HandleSaveSound();

    private:

        enum OpenMode {
            NotOpen,
            OpenSelectionService,
            OpenSaveService,
            OpenApplication

        };

        enum FeatureItemIds {
            SbSoundBrowser,
            SbSelect,
            SbPlay,
            SbStop,
            SbRename,
            SbDelete,
            SbSendAsMms,
            SbInfo,
#if defined(APOXI_INCLUDE_DRM)
            SbDrmInfo,
#endif
            SbKeyUpDown,
            SbClose,
            SbFeatureCnt
        };

        enum SndServiceState {
            NoSndService,
            SelectSndService,
            SaveSndService
        };
        Feature m_items[SbFeatureCnt];

        static SoundBrowserApp m_app;

        BrowserSaveWin m_browser_save_win;

        static BooleanCondition m_condition_sav;

        SoundRefContainer *m_snd_refs;

        OpenMode m_mode;

        ItemContainer* m_item_cont;

        MmiItemListWindow m_media_list_win;

        RenameFileDialog m_rename_file_dialog;

        SharedPtr<AudioActiveReference> m_active_file_ref;

        UINT8 HUGE* m_current_sound_buffer;


        static BooleanCondition s_condition_sel;


        BOOLEAN m_success;

        SoundRef* m_current_sound_ref;

        BOOLEAN m_sndsrv_success;
        SndServiceState m_snd_state;

        const BinData   *m_snd_bin_data;
        DrmMimeType     m_snd_drm_mime_type;
        Path            m_snd_path;
        SoundFilter     *p_sound_filter;

}; // SoundBrowserApp

#endif  // Apoxi_SoundBrowserApp_hpp
