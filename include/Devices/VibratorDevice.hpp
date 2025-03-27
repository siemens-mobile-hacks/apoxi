/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NewAPI_VibratorDevice_hpp)
#define Apoxi_NewAPI_VibratorDevice_hpp


#include <Kernel/Types.hpp>
#include <Auxiliary/SharedPtr.hpp>

class VibratorDevice : public SystemTimer
{
    private:
        //Use GetInstance() instead.
        VibratorDevice();

    public:
        static VibratorDevice& GetInstance();

        enum VibratorMode
        {
            Vibrator_Sync_Control,
            Vibrator_Async_1,
            Vibrator_Async_2,
            Vibrator_Async_3,
            Vibrator_Async_4,
            Vibrator_Async_5,
            Vibrator_Async_6,
        };

        BOOLEAN StartVibrator(VibratorMode mode = Vibrator_Async_1, UINT16 channel = 0);

        void StopVibrator();
        
        BOOLEAN IsVibratorOn();
        
    protected:
        static VibratorDevice m_instance;
        static void OnTimer(void *data);
        //TRUE if Vibrator is in On period, FALSE if it is in Off period
        BOOLEAN m_on;
        //TRUE if Vibrator was started and is in either in On or Off period,FALSE if the vibrator is not started or it has been stoped using StopVibrator
        BOOLEAN m_active;
        //on-off period of time matching the mode in which Vibrator was started
        UINT16 m_PeriodTime;
        
        
};


#endif  // Apoxi_NewAPI_VibratorDevice_hpp


