/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_SatteliteGraphWin_hpp)
#define Mmi_SatteliteGraphWin_hpp

#include <AddOns/Lcs/Common/LcsTypes.hpp>
#include <Common/MmiWindow.hpp>

class SatteliteGraphWin : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        SatteliteGraphWin();

        virtual ~SatteliteGraphWin();

        void Init();

        void SetGraphData(SatelliteInfo sat_info[], UINT8 num_sats);
        
        const WCHAR* GetTitleText() const;


    protected:

        virtual void OnPaint(const Rect& repaint_rect);


    private:

        struct SatelliteBar {
            // Id of the tracked satellite
            UINT8 m_sat_id;
            // Strength (in dB) of the tracked satellite
            INT16 m_sig_strength;
        } m_sat_bar[MAX_SATS];
        
}; // SatteliteGraphWin

#endif // Mmi_SatteliteGraphWin_hpp
