/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageViewListBoxModel_hpp)
#define Apoxi_ImageViewListBoxModel_hpp

#include <Gui/Image.hpp>
#include <ImageBrowser/ImageListBoxModel.hpp>
#include <ImageBrowser/ImageRef.hpp>
#include <ImageBrowser/Common/MediaRefContainer.hpp>

class ImageViewListBoxModel : public ImageListBoxModel
{
    typedef ImageListBoxModel Base;

    public:
        ImageViewListBoxModel();
        ImageViewListBoxModel(DrawableObjectListBox *control, 
            const MediaRefContainer &media_refs);
        virtual ~ImageViewListBoxModel();

        void Init(DrawableObjectListBox *control, 
            const MediaRefContainer &media_refs);

        virtual DrawableObject* GetItem(INT index, BOOLEAN highlighted);

        virtual const WString GetCellText(INT index, BOOLEAN highlighted);
        virtual void NotifyDelete();
        const WString GetResolution(INT index, BOOLEAN highlighted);

    protected:
        virtual ImageObtainer GetSelectedImage(INT index);

        virtual void OnSelectionChanged(INT selected_index);

    private:
        INT m_prev_image;
        INT m_current_image;
        const MediaRefContainer *m_media_refs;
};

#endif  // Apoxi_ImageViewListBoxModel_hpp
