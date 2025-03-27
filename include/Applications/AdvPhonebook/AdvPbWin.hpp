/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_AdvPbWin_hpp)
#define Mmi_AdvPbWin_hpp

#include <Auxiliary/FilterProvider.hpp>

#include <AdvPhonebook/PhonebookWin.hpp>
#include <AdvPhonebook/PbAdvDetails.hpp>

class AdvPbApp;
class AdvPbWin : public PhonebookWin {
    typedef PhonebookWin Base;

    public:
        AdvPbWin();
        virtual ~AdvPbWin();

        void Init(AdvPbApp* pb_app, Provider* pb_provider = 0, INT sort_colid = c_name_id, BOOLEAN read_only = FALSE);
        
        virtual INT GetSelectedRow();

        virtual Provider* GetMyPbProvider();

        virtual PbDetails* GetDetailWin();
                
    protected:
        virtual INT GetListBoxRow(INT prov_row);
        
    private:
        Provider*               m_pb_provider;
        PbAdvDetails            m_detail_win;
        static const INT        m_detail_columns[5];

        FilterProvider          m_filtered_prov;
        EqualsRule              m_rule;
};

#endif  // Mmi_AdvPbWin_hpp
