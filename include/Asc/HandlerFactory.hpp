/*  ------------------------------------------------------------------------
  Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
  ------------------------------------------------------------------------
  This document contains proprietary information belonging to COMNEON.
  Passing on and copying of this document, use and communication of its
  contents is not permitted without prior written authorisation.
  ------------------------------------------------------------------------ */
#if !defined(Asc_HandlerFactory_hpp)
#define Asc_HandlerFactory_hpp

#include <Asc/AccHandler.hpp>
#include <Asc/AocHandler.hpp>
#if defined(APOXI_COMPAT_2_2_0)
#include <Asc/BattHandler.hpp>
#endif
#include <Asc/CallHandler.hpp>
#include <Asc/CbsHandler.hpp>
#if defined(APOXI_COMPAT_2_2_0)
#include <Asc/ChrHandler.hpp>
#endif
#include <Asc/CrssHandler.hpp>
//Manik added for Call Deflection - Begin
#include <Asc/CallDeflectionHandler.hpp>
//Manik added for Call Deflection - End
#include <Asc/MocVoiceHandler.hpp>
#include <Asc/MtcVoiceHandler.hpp>
#include <Asc/NetworkHandler.hpp>
#include <Asc/PlmnHandler.hpp>
#include <Asc/PowerHandler.hpp>
#include <Asc/RtcHandler.hpp>
#include <Asc/SigHandler.hpp>
#include <Asc/SimHandler.hpp>
#include <Asc/AtcHandler.hpp>
#include <Asc/SimTkHandler.hpp>
#include <Asc/SimTkLceHandler.hpp>
#include <Asc/SmsHandler.hpp>

// obsolete moved to Compat
#if defined(APOXI_COMPAT_1_7_0) 
#include <Asc/SsHandler.hpp>
#endif

#include <Asc/SsCcbsHandler.hpp>
#include <Asc/BootHandler.hpp>

#include <Asc/SsMainHandler.hpp>
#include <Asc/CallWaitingHandler.hpp>
#include <Asc/CallForwardingHandler.hpp>
#include <Asc/CallBarringHandler.hpp>
#include <Asc/EmlppHandler.hpp>
#include <Asc/ClipHandler.hpp>
#include <Asc/ClirHandler.hpp>
#include <Asc/ColpHandler.hpp>
#include <Asc/ColrHandler.hpp>
#include <Asc/CnapHandler.hpp>
#include <Asc/UssdHandler.hpp>
#include <Asc/MobileOriginatedUssdHandler.hpp>

#ifdef APOXI_UUS_SUPPORT
    #include <Asc/UusHandler.hpp>
#endif

#include <Asc/CallControlHandler.hpp>

#include <Asc/MultiSlotHandler.hpp>

#ifdef APOXI_COMPAT_2_0_0
    #include <Devices/RtcMsgTypes.hpp>
#endif

#if defined APOXI_LIB_ADDON_VR
    #include <AddOns/VoiceRecognition/VrHandler.hpp>
#endif

#if defined APOXI_LIB_ADDON_MMCALL
    #include <AddOns/MmCall/MmCallHandler.hpp>
#endif


#ifdef APOXI_COMPAT_2_2_0
    #include <Devices/ChargerMsgTypes.hpp>
#endif

/* ========================================================================
   HandlerFactory
   ======================================================================== */
class HandlerFactory {
    public:
        static BaseHandler* CreateAccHandler() { return (new AccHandler); }
        static BaseHandler* CreateAocHandler() { return (new AocHandler); }
#if defined(APOXI_COMPAT_2_2_0)
        static BaseHandler* CreateBattHandler() { 
            ExecutionContext& context = ExecutionContext::GetCurrentContext();
            context.RegisterMessage(BatteryLoadLevelMsg::ID);
            return (new BattHandler); 
        }
#endif
        static BaseHandler* CreateCallHandler() { return (new CallHandler); }
        static BaseHandler* CreateCbsHandler() { return (new CbsHandler); }
#ifdef APOXI_COMPAT_2_2_0
        static BaseHandler* CreateChrHandler() { 
            ExecutionContext& context = ExecutionContext::GetCurrentContext();
            context.RegisterMessage(BatteryChargerRemovedMsg::ID);
            context.RegisterMessage(BatteryChargingMsg::ID);
            context.RegisterMessage(BatteryChargingPausedMsg::ID);
            context.RegisterMessage(BatteryChargingResumedMsg::ID);
            context.RegisterMessage(BatteryLowMsg::ID);
            context.RegisterMessage(BatteryIdErrorMsg::ID);
            context.RegisterMessage(BatteryEmptyMsg::ID);
            context.RegisterMessage(BatteryStopChargingMsg::ID);

            context.RegisterMessage(ChargerInfoMsg::ID);
            return (new ChrHandler); 
        }
#endif

        static BaseHandler* CreateCrssHandler() { return (new CrssHandler); }
        static BaseHandler* CreateMocVoiceHandler() { return (new MocVoiceHandler); }
        static BaseHandler* CreateMtcVoiceHandler() { return (new MtcVoiceHandler); }
        static BaseHandler* CreateNetworkHandler() { return (new NetworkHandler); }
        static BaseHandler* CreatePlmnHandler() { return (new PlmnHandler); }
        static BaseHandler* CreatePowerHandler() { return (new PowerHandler); }
    #ifdef APOXI_COMPAT_2_0_0
        static BaseHandler* CreateRtcHandler() { 
            ExecutionContext& context = ExecutionContext::GetCurrentContext();
            context.RegisterMessage(MinuteTickMsg::ID);
            context.RegisterMessage(AlarmMsg::ID);
            return (new RtcHandler); 
        }
    #endif
        static BaseHandler* CreateSigHandler() { return (new SigHandler); }
        static BaseHandler* CreateSimHandler() { return (new SimHandler); }
        static BaseHandler* CreateSmsHandler() { return (new SmsHandler); }
        static BaseHandler* CreateAtcHandler() { return (new AtcHandler); }
            
        // obsolete moved to Compat
        #if defined(APOXI_COMPAT_1_7_0) 
            static BaseHandler* CreateSsHandler() { return (new SsHandler); }
        #endif
    
        static BaseHandler* CreateSimTkHandler() { return (new SimTkHandler); }
#ifdef  APOXI_LETTERCLASSE_SUPPORT
        static BaseHandler* CreateSimTkLceHandler() { return (new SimTkLceHandler); }
#endif

        static BaseHandler* CreateSsMainHandler() { return (new SsMainHandler); }
        static BaseHandler* CreateCallWaitingHandler() { return (new CallWaitingHandler); }
        static BaseHandler* CreateCallForwardingHandler() {return (new CallForwardingHandler); }
        static BaseHandler* CreateCallBarringHandler() {return (new CallBarringHandler); }
        static BaseHandler* CreateEmlppHandler() {return (new EmlppHandler); }
        static BaseHandler* CreateClipHandler() {return (new ClipHandler); }
        static BaseHandler* CreateClirHandler() {return (new ClirHandler); }
        static BaseHandler* CreateColpHandler() {return (new ColpHandler); }
        static BaseHandler* CreateColrHandler() {return (new ColrHandler); }
        static BaseHandler* CreateUssdHandler() {return (new UssdHandler); }
        static BaseHandler* CreateMoUssdHandler() {return (new MobileOriginatedUssdHandler); }

        static BaseHandler* CreateCnapHandler() {return (new CnapHandler); }
        static BaseHandler* CreateCallControlHandler() {return (new CallControlHandler); }
        static BaseHandler* CreateCallDeflectionHandler() { return (new CallDeflectionHandler); }
        static BaseHandler* CreateBootHandler() { return (new BootHandler); }
        static BaseHandler* CreateMultiSlotHandler() { return (new MultiSlotHandler); }
        static BaseHandler* CreateSsCcbsHandler() { return (new SsCcbsHandler); }

#if defined(APOXI_LIB_ADDON_VR)
    static BaseHandler* CreateVrHandler() { return (new VrHandler); }
#endif

#if defined(APOXI_UUS_SUPPORT)
    static BaseHandler* CreateUusHandler() { return (new UusHandler); }
#endif

#if defined(APOXI_LIB_ADDON_MMCALL)
    static BaseHandler* CreateMmCallHandler() { return (new MmCallHandler); }
#endif
};

#endif  // Asc_HandlerFactory_hpp

