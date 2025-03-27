/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RenameDialog_hpp)
#define Apoxi_RenameDialog_hpp

#include <GuiExtensions/MmiDialog.hpp>
#include <Afs/Rfs/Path.hpp>

class RenameFileDialog : public MmiDialog
{
    typedef MmiDialog Base;

    public:
        RenameFileDialog();
        virtual ~RenameFileDialog();

        void Init();
        void Init(Control *control);

        WString GetNewFilename() const;

        void SetCurrentPath(const Path &current_path);

        BOOLEAN GetSuccess() const;

    protected:
        virtual void OnOpen();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

        virtual void OnLayoutClient();

    private:
        //TextBox m_current_name;
        //TextBox m_file_name;
        TextBox m_new_name;
        TextBox m_extension;
        TextBox m_error_tb;
        LineEditor m_new_file_name;
        TextBox m_new_extension;

        WString m_str_full_file_name;
        WString m_str_file_name;
        WString m_str_file_extension;


        BOOLEAN m_success;

};

#endif  // Apoxi_RenameDialog_hpp
