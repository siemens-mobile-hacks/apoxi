/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_VoiceMemoMenuAccessor_hpp)
#define Mmi_VoiceMemoMenuAccessor_hpp

#include <GuiExtensions/MmiAlert.hpp>
#include <GuiExtensions/AbstractMmiMenuAccessor.hpp>

class VoiceMemoMenuAccessor : public AbstractMmiMenuAccessor {
    typedef AbstractMmiMenuAccessor Base;

    public:
        VoiceMemoMenuAccessor();

        virtual ~VoiceMemoMenuAccessor();

        void Init();

        virtual BOOLEAN First();

        virtual BOOLEAN Next();

        virtual const WCHAR* GetItemText(BOOLEAN highlighted);

        virtual const WCHAR* GetHiglightedText();

    private:
        FfsFileId               m_id;
};

#endif  // Mmi_VoiceMemoMenuAccessor_hpp
