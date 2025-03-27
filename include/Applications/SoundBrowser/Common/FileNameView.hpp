/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileNameView_hpp)
#define Apoxi_FileNameView_hpp

#include "BrowserView.hpp"
#include "FileNameListBoxModel.hpp"

class FileNameView : public BrowserView
{
    typedef BrowserView Base;

    public:
        FileNameView();
        virtual ~FileNameView();

        void Init(Control *parent, MediaRefContainer &media_refs);

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);
        virtual void OnGetFocus();

    private:
        FileNameListBoxModel m_list_model;
};

#endif  // Apoxi_FileNameView_hpp
