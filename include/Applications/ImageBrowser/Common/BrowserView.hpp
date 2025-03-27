/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BrowserView_hpp)
#define Apoxi_BrowserView_hpp

#include <GuiExtensions/DrawableObjectListBox.hpp>
#include "MediaRefContainer.hpp"

//struct MediaRefPtr;
class MediaRefContainer;

class BrowserView : public DrawableObjectListBox
{
    typedef DrawableObjectListBox Base;

    public:
        BrowserView();
        virtual ~BrowserView();

        void Init(Control *parent, MediaRefContainer &media_refs, 
            DrawableObjectListBoxModel *model);

        virtual void NotifyDelete();

        MediaRefPtr& GetSelectedMediaRef();

        const MediaRefPtr& GetSelectedMediaRef() const;

    private:
        MediaRefContainer *m_media_refs;
};

#endif  // Apoxi_BrowserView_hpp
