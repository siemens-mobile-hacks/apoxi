/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImgBrowserSaveWin_hpp)
#define Apoxi_ImgBrowserSaveWin_hpp

#include <GuiExtensions/MmiDialog.hpp>
#include <Afs/Rfs/RootFileSystem.hpp>

class MediaRefContainer;

class BrowserSaveWin : public MmiDialog
{
    typedef MmiDialog Base;

    public:
        BrowserSaveWin();
        virtual ~BrowserSaveWin();

        void Init(BooleanCondition &condition, 
            const MediaRefContainer &media_refs);

        Path GetNewPath() const;

        void SetTargetPath(const Path &path);

        BOOLEAN GetSuccess() const {
            return m_success;
        }

    protected:
        virtual void OnOpen();
        
        virtual void OnLayoutClient();
        
        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();


    private:
        BOOLEAN m_success;

        // TO DO enhance dialog for also asking for the storage device Id.
        static const WCHAR *m_deviceId;
        LineEditor m_file_name;
        TextBox m_name;
        TextBox m_error_tb;

        BooleanCondition *m_condition;
        const MediaRefContainer *m_media_refs;
        MimeType m_mime_type;
};

#endif  // Apoxi_ImgBrowserSaveWin_hpp
