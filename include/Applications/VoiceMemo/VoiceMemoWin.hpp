/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_VoiceMemoWin_hpp)
#define Mmi_VoiceMemoWin_hpp

#include <GuiExtensions/MmiMenuWindow.hpp>
#include <GuiExtensions/ActionAccessor.hpp>

#include <VoiceMemo/VoiceMemoMenuAccessor.hpp>
#include <VoiceMemo/VoiceMemoRecordWin.hpp>

class VoiceMemoWin : public MmiMenuWindow {
    typedef MmiMenuWindow Base;

    public:
        VoiceMemoWin();
        virtual ~VoiceMemoWin();
        void Init();
        SharedPtr<AudioActiveReference> Record();
        BOOLEAN StopRecord();
        BOOLEAN PauseRecord();
        BOOLEAN ResumeRecord();

    protected:
        virtual void OnActionExecuted(Action *action);

    private:
        VoiceMemoMenuAccessor               m_accessor;
        Action                              m_new;
        Action                              m_close;
        VoiceMemoRecordWin                  m_record_win;
};

#endif  // Mmi_VoiceMemoWin_hpp
