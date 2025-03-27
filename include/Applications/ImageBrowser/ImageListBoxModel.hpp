/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageListBoxModel_hpp)
#define Apoxi_ImageListBoxModel_hpp

#include <GuiExtensions/DrawableObjectListBox.hpp>

class ImageListBoxModel : public DrawableObjectListBoxModel
{
    typedef DrawableObjectListBoxModel Base;

    public:
        ImageListBoxModel();
        ImageListBoxModel(DrawableObjectListBox *control);
        virtual ~ImageListBoxModel();

        void Init(DrawableObjectListBox *control);

        virtual void AdjustThemeDependencies();

        virtual DrawableObject* GetItem(INT index, BOOLEAN highlighted);

        virtual DrawableObjectView* GetRenderingView(INT index, BOOLEAN highlighted);

        virtual void Update(INT item_count = -1);

        void SetImageChanged(BOOLEAN changed = TRUE);

        virtual void NotifyDelete();

    protected:
        virtual ImageObtainer GetSelectedImage(INT index) = 0;

        virtual void OnSelectionChanged(INT selected_index);

    private:

        ImageBox        *m_imagebox;
        BOOLEAN m_image_changed;
};

#endif  // Apoxi_ImageListBoxModel_hpp
