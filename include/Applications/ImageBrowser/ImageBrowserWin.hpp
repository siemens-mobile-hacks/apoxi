/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageBrowserWin_hpp)
#define Apoxi_ImageBrowserWin_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>
#include <Common/MmiWaitingBox.hpp>
#include <ImageBrowser/Common/BrowserViewContainer.hpp>
#include <ImageBrowser/Common/RenameFileDialog.hpp>
#include <ImageBrowser/Common/FileNameView.hpp>
#include <ImageBrowser/ImageView.hpp>
#include <ImageBrowser/Common/InfoDialog.hpp>


class ImageRef;
class ImageRefContainer;
class ImageFilter;

class ImageBrowserWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:
        ImageBrowserWin();
        virtual ~ImageBrowserWin();

        void Init(BooleanCondition &condition, ImageRefContainer &img_refs);

        BOOLEAN SetImageFilter(const ImageFilter &img_filter, BOOLEAN show_select_button);

        MediaRefPtr& GetSelectedImageRef();

        BOOLEAN GetSuccess() const;

        BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);
        
    protected:
        BOOLEAN OnKeyDown(KeyCode key_code);
        void OnLayoutClient();
        BOOLEAN OnCancel();
        BOOLEAN OnConfirm();
        void OnOpen();
        void OnClose();

    private:
        void DisplayAlert(const WCHAR *msg);
        void HandleErrImg(UINT8 err_no);
        BrowserViewContainer m_views;
        FileNameView m_fnv;
        ImageView m_img_view;
        MmiWaitingBox m_waiting_box;

        ImageRefContainer *m_img_refs;
        
        BooleanCondition *m_condition;
        BOOLEAN m_success;
        BOOLEAN m_show_select_button;

        RenameFileDialog m_rename_file_dialog;
        InfoDialog m_info_dialog;
};


#endif  // Apoxi_ImageBrowserWin_hpp
