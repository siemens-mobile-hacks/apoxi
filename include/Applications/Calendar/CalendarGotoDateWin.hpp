/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    -------------------------------------------------------- */
#if !defined(CalendarGotoDateWin_hpp)
#define CalendarGotoDateWin_hpp

#include "CalendarGrid.hpp"
#include "CalendarMonthSelector.hpp"
#include "CalendarAddRecordWin.hpp"
#include "CalendarMonthWin.hpp"

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/LabelListBoxModel.hpp>
#include <GuiExtensions/ActionAccessor.hpp>


class CalendarMonthWin;

class CalendarGotoDateWin : public MmiWindow {
    typedef MmiWindow Base;

    public:
        CalendarGotoDateWin();

        virtual ~CalendarGotoDateWin();

        void Init(CalendarMonthWin* parent);

    protected:
        virtual BOOLEAN OnCancel();

        virtual BOOLEAN OnConfirm();

        void OnLayoutClient();

    private:
        CalendarMonthWin*   m_parent_win;
        DateEditor          m_date_editor;
};

#endif 

