/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LocResController_hpp)
#define Mmi_LocResController_hpp

#include "LocationResultWin.hpp"
#include "SatteliteInfoWin.hpp"
#include "SatteliteGraphWin.hpp"

#include <AddOns/Lcs/Common/LcsTypes.hpp>

class LocResController
{
    public:

        virtual ~LocResController();

        static LocResController* GetInstance();

        static void ReleaseInstance();

        void Init();

        void HandleWinEvent(ResultWinBase::ResWinAction event_code);

        void Open(const LocationEstimate& loc_estimate);

        void UpdateTitle();

        void SetStatus(INT32 conn_status);


    private:

        static LocResController* m_self;

        enum LocResWinState {
            InLocationWin,
            CrossLocWinToSatGraph,
            CrossSatGraphToLocWin,
            CrossSatGraphToSatData,
            CrossSatDataToSatGraph,
            InSatDataWin,
            Invalid
        };

        UINT8 m_counter;

        BOOLEAN m_pause;

        INT32 m_conn_status;

        LocationEstimate m_old_loc_estimate;

        LocationEstimate m_new_loc_estimate;

        LocationResultWin m_loc_res_win;

        SatteliteGraphWin m_sat_graph_win;

        SatteliteInfoWin m_sat_info_win;

        Timer m_timer;


    private:

        LocResController();

        void DisplaySatelliteInfo();

        void DisplayPositionInfo();

        void ProcessWinState(LocResWinState win_state);

}; // LocResController

#endif // Mmi_LocResController_hpp
