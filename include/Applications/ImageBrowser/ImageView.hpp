/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageView_hpp)
#define Apoxi_ImageView_hpp

#include <ImageBrowser/Common/BrowserView.hpp>
#include <ImageBrowser/Common/MediaRef.hpp>
#include <ImageBrowser/ImageViewListBoxModel.hpp>

#define IMAGE_ITEM_HEIGHT           36  /*Item height of thumbnail view*/

class ImageListBoxView : public AbstractListBoxView
{
    typedef AbstractListBoxView Base;

    public:
        ImageListBoxView();
        ImageListBoxView(XYDIM item_height);

        void Init(XYDIM item_height);

        void DrawItem(const AbstractListBox &listbox, DeviceContext *dc, 
            INT index, const Rect &item_rect) const;
};

class ImageView : public BrowserView
{
    typedef BrowserView Base;

    public:
        ImageView();
        virtual ~ImageView();

        void Init(Control *control, MediaRefContainer &media_refs);

        virtual void NotifyDelete();

        ImageViewListBoxModel* GetModel() {return &m_list_model;};

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);

        virtual void OnGetFocus();

    private:
        ImageViewListBoxModel m_list_model;
        static ImageListBoxView m_view;
};

#endif  // Apoxi_ImageView_hpp
