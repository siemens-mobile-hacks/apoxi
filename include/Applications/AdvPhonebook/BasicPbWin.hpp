/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_BasicPbWin_hpp)
#define Mmi_BasicPbWin_hpp

#include <AdvPhonebook/PhonebookWin.hpp>
#include <AdvPhonebook/PbDetails.hpp>

class PhonebookApp;
class BasicPbWin : public PhonebookWin {
    public:
        typedef PhonebookWin Base;

        BasicPbWin();
        virtual ~BasicPbWin();

        void Init(Provider* pb_provider = 0, INT sort_colid = c_name_id, BOOLEAN read_only = FALSE);

    protected:
        virtual PbDetails* GetDetailWin();

    private:
        PbDetails               m_detail_win;
        static const INT        m_detail_columns[3];
};

#endif  // Mmi_BasicPbWin_hpp
