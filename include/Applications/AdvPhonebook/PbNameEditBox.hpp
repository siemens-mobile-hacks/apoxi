/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbNameEditBox_hpp)
#define Mmi_PbNameEditBox_hpp

#include <Gui/LineEditor.hpp>

class PbNameEditBox : public LineEditor {
    typedef LineEditor Base;

    public:
        PbNameEditBox();
        virtual ~PbNameEditBox();

        void Init(Control* parent);
            
        void SetMaxAlphaTagSize(INT max_ats) { m_max_ats = max_ats; }

    protected:  
        virtual BOOLEAN OnKeyDown(KeyCode key_code);

    private:
        INT m_max_ats;
        INT m_old_key;
};

#endif  // Mmi_PbNameEditBox_hpp
