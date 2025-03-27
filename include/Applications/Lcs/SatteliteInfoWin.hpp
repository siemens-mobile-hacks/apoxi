/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SatteliteInfoWin_hpp)
#define Mmi_SatteliteInfoWin_hpp

#include "ResultWinBase.hpp"

struct SatelliteInfo;

class SatteliteInfoWin : public ResultWinBase
{
    typedef ResultWinBase Base;

    public:

        SatteliteInfoWin();

        virtual ~SatteliteInfoWin();

        void Init();

        void SetSatelliteData(const SatelliteInfo& sat_info);

        const WCHAR* GetTitleText() const;


    protected:

        virtual void OnLayoutClient();
        

    private:

        TextBox m_label5;

        TextBox m_label6;

        TextBox m_label7;

        TextBox m_data5;

        TextBox m_data6;

        TextBox m_data7;

}; // SatteliteInfoWin

#endif // Mmi_SatteliteInfoWin_hpp
