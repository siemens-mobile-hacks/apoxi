/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_PbAdvAddEditEntry_hpp)
#define Mmi_PbAdvAddEditEntry_hpp

#include <AdvPhonebook/PbNameEditBox.hpp>
#include <AdvPhonebook/PbConfig.hpp>
#include <GuiExtensions/MmiDialog.hpp>
#include <Gui/LineEditor.hpp>

class PbAdvAddEditEntry : public MmiDialog {
    typedef MmiDialog Base;

    public:
        //
        PbAdvAddEditEntry();
        
        //
        void Init();
    
        //
        void SetName(const WString &name);

        //
        const WString& GetName() const;

        //
        void SetPhoneNo(const PhoneNumber &phone_no);

        //
        PhoneNumber GetPhoneNo() const;
        
        //
        void SetMaxAlphaTagSize(INT ats);

    protected:
        virtual void OnOpen();
        virtual void OnLayoutClient();
        virtual BOOLEAN OnConfirm();

    private:
        TextLine            m_name_text;
        PbNameEditBox       m_name_editor;

        TextLine            m_phone_no_text;
        LineEditor          m_phone_no_editor;
};

#endif  // Mmi_PbAdvAddEditEntry_hpp
