/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_GltpAidingDataWin_hpp)
#define Mmi_GltpAidingDataWin_hpp

#include <Common/MmiWindow.hpp>

class GltpAidingDataWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        GltpAidingDataWin();

        virtual ~GltpAidingDataWin();

        void Init();


    protected:

        virtual void OnOpen();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

        virtual void OnLayoutClient();


    private:

        TextBox m_label_latitude;

        LineEditor m_latitude;

        TextBox m_label_longitude;

        LineEditor m_longitude;

        TextBox m_label_unit_id;

        LineEditor m_unit_id;

        TextBox m_label_agps_mode;

        LineEditor m_agps_mode;

        TextBox m_label_repeat_interval;

        LineEditor m_repeat_interval;


}; // GltpAidingDataWin

#endif // Mmi_GltpAidingDataWin_hpp
