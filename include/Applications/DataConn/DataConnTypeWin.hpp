/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DataConnTypeWin_hpp)
#define Apoxi_DataConnTypeWin_hpp

#include <Socket/DataConnProfile.hpp>
#include <GuiExtensions/MmiDialog.hpp>

class DataConnTypeWin : public MmiDialog {
    public:
        typedef MmiDialog Base;

        DataConnTypeWin();
        virtual ~DataConnTypeWin();
        
        void Init();

        DataConnProfile::ProfileType GetProfileType() { return (DataConnProfile::ProfileType) m_rb_list.GetPressedItem()->GetValue(); }

    private:
        RadioButtonList m_rb_list;
        RadioButtonItem m_csd_item;
        RadioButtonItem m_psd_item;

};

#endif  // Apoxi_DataConnTypeWin_hpp
