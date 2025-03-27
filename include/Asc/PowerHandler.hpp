/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_PowerHandler_hpp)
#define Asc_PowerHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/BaseHandler.hpp>
#include <Apc/SignalHandler/SignalMapTableEntry.hpp>
#include <Asc/PowerDispatcher.hpp>

/*  ========================================================================
    PowerHandler
    ======================================================================== */
class PowerHandler : public BaseHandler {
    friend class ShutDown;
    public:
        typedef BaseHandler Base;
        enum { ID = PowerHandlerId };       

        PowerHandler();
        virtual ~PowerHandler();

        virtual HandlerId GetHandlerId() const { return (PowerHandlerId); }

        static void PowerUp(const ProcessPtr process_ptr = GetApoxiProcessPtr());

        static void StartMobileNetwork(const ProcessPtr process_ptr = GetApoxiProcessPtr());
        
        static BOOLEAN IsMobileNetworkStarted() { return m_is_mobile_network_started; }

        static void StopMobileNetwork();

        static void PowerDown();
        
        static void StartSilentReset();

        static void StartAirplaneMode(const ProcessPtr process_ptr = GetApoxiProcessPtr());

    private:
        PowerDispatcher m_power_dispatcher;
        static BOOLEAN m_is_mobile_network_started;

        // method simply sends the OM_CONTROL_REQ signal, to send a new (resp. change the) power mode
        static void SendPowerMode(PowerMode mode, const ProcessPtr process_ptr = GetApoxiProcessPtr());
};


#endif // Asc_PowerHandler_hpp


