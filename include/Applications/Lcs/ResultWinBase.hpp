/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_ResultWinBase_hpp)
#define Mmi_ResultWinBase_hpp

#include <Common/MmiWindow.hpp>

class ResultWinBase : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        enum ResWinAction
        {
            ViewPrevious = 0,
            ViewNext,
            Pause,
            CloseWindow,
            Invalid
        };


        ResultWinBase();

        virtual ~ResultWinBase();

        void Init();


    protected:

        TextBox m_label1;

        TextBox m_label2;

        TextBox m_label3;

        TextBox m_label4;

        TextBox m_data1;

        TextBox m_data2;

        TextBox m_data3;

        TextBox m_data4;

}; // ResultWinBase

#endif // Mmi_ResultWinBase_hpp
