/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LocationResultWin_hpp)
#define Mmi_LocationResultWin_hpp

#include "ResultWinBase.hpp"

#include <AddOns/Lcs/Common/LcsTypes.hpp>

class LocationResultWin : public ResultWinBase
{
    typedef ResultWinBase Base;

    public:

        LocationResultWin();

        virtual ~LocationResultWin();

        void Init();

        void SetLocationEstimate(const LocationEstimate& loc_estimate, BOOLEAN first_half);

        void SetGpsFixData(const GpsFixData& gps_fix_data, BOOLEAN first_half);

        const WString& GetTitleText() const { return m_title_text; }

        
    protected:

        virtual void OnLayoutClient();


    private:

        TextBox m_label5;

        TextBox m_data5;

        WString m_title_text;

}; // LocationResultWin

#endif // Mmi_LocationResultWin_hpp
