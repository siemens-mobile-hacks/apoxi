/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileNameListBoxModel_hpp)
#define Apoxi_FileNameListBoxModel_hpp

#include <GuiExtensions/LabelListBoxModel.hpp>

class MediaRefContainer;

class FileNameListBoxModel : public LabelListBoxModel
{
    typedef LabelListBoxModel Base;

    public:
        FileNameListBoxModel();
        FileNameListBoxModel(DrawableObjectListBox *control, 
            const MediaRefContainer &media_refs);
        virtual ~FileNameListBoxModel();

        void Init(DrawableObjectListBox *control, 
            const MediaRefContainer &media_refs);

        virtual const WCHAR* GetCellText(INT index, BOOLEAN highlighted);

    private:
        const MediaRefContainer *m_media_refs;
};

#endif  // Apoxi_FileNameListBoxModel_hpp
