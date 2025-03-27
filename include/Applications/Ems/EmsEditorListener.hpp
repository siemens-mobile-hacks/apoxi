/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsEditorListener_hpp)
#define Ems_EmsEditorListener_hpp

class EditorDocument;

class EmsEditorListener {
    public:
        EmsEditorListener();

        virtual ~EmsEditorListener();

    protected:
        virtual void OnDocumentChanged(const EditorDocument* document) = 0;

    private:
        friend class EmsEditor;
};

#endif  // Ems_EmsEditorListener_hpp
