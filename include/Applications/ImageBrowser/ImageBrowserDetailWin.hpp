/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageBrowserDetailWin_hpp)
#define Apoxi_ImageBrowserDetailWin_hpp

#include <Atl/AtlWindow.hpp>
#include <Gui/Image.hpp>

class ImageBrowserDetailWin : public AtlWindow {
    typedef AtlWindow Base;

    public:
        ImageBrowserDetailWin();
        virtual ~ImageBrowserDetailWin();

        void Init(Image *image);
        void StartStop(BOOLEAN start);
        BOOLEAN SetTransformation(DeviceContext::TransformationMode transformation);
    protected:
        virtual BOOLEAN OnKeyDown(KeyCode key_code);
        virtual void OnLayoutClient();
        virtual BOOLEAN OnCancel();
        virtual void OnOpen();
        virtual void OnClose();

        void RepositionImage();

    private:
        ImageBox                m_image_box;

        XYDIM                   m_XPos,m_YPos;
        XYDIM                   m_Height,m_Width;
        XYDIM                   m_MaxXPos, m_MaxYPos;
};

#endif  // Apoxi_ImageBrowserDetailWin_hpp
