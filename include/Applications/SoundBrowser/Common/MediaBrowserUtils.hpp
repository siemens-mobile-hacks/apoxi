/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaBrowserUtils_hpp)
#define Apoxi_MediaBrowserUtils_hpp

#include <GuiExtensions/MmiInfoBox.hpp>

class MediaBrowserUtils
{
    public:

        ~MediaBrowserUtils();

        static MediaBrowserUtils* GetInstance();

#if defined(APOXI_INCLUDE_DRM)

        WString GetDrmErrorString(INT error_code) const; 
#endif
        
        MmiDialog::ReturnId DisplayDlg(const WString& msg, 
                                        MmiInfoBox::MmiInfoBoxType type = MmiInfoBox::Error) const;

        BOOLEAN ValidateFileName(const WString& name);


    private:

        MediaBrowserUtils();

    private:

        static MediaBrowserUtils* m_app;

}; // MediaBrowserUtils

#endif // Apoxi_MediaBrowserUtils_hpp
