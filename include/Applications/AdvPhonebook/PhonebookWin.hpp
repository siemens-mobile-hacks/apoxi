/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(PhonebookWin_hpp)
#define PhonebookWin_hpp

#include <AdvPhonebook/PbBaseWin.hpp>

class PbDetails;
class PhonebookWin : public PbBaseWin {
    public:
        typedef PbBaseWin Base;

        PhonebookWin();
        virtual ~PhonebookWin();

        void Init(Provider* pb_provider = 0, INT sort_colid = c_name_id, BOOLEAN read_only = FALSE);

        virtual void SetDisplaySimPos(BOOLEAN display_simpos);

        void AddDetailMenuAction(Action *action, BOOLEAN separate = FALSE);

        void Update();

        virtual BOOLEAN IsReadOnly();

        virtual PbDetails* GetDetailWin() = 0;

    protected:
        virtual void UpdateEnabledActions();

    private:
        OpenWindowAction        m_open_detail_action;
        BOOLEAN m_read_only;
};

#endif  // PhonebookWin_hpp
