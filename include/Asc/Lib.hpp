/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Lib_hpp)
#define Asc_Lib_hpp

#include <Apc/Lib.hpp>
#include <Adc/Lib.hpp>

#include <Asc/Types.hpp>
#include <Asc/HandlerId.hpp>
#include <Asc/MainHandler.hpp>
#include <Asc/StackIndicationMsgTypes.hpp>
#include <Asc/StackControl.hpp>
#if defined(APOXI_COMPAT_2_2_0)
    #include <Asc/BattHandler.hpp>
#endif
#include <Asc/CallHandler.hpp>
#include <Asc/CallHdl.hpp>
#include <Asc/CbsHandler.hpp>
#if defined(APOXI_COMPAT_2_2_0)
    #include <Asc/ChrHandler.hpp>
#endif
#include <Asc/CrssHandler.hpp>
#include <Asc/CallDeflectionHandler.hpp>
#include <Asc/MocVoiceHandler.hpp>
#include <Asc/MptyCallHdl.hpp>
#include <Asc/MtcVoiceHandler.hpp>
#include <Asc/NetworkHandler.hpp>
#include <Asc/PlmnHandler.hpp>
#include <Asc/PowerHandler.hpp>
#include <Asc/RtcHandler.hpp>
#include <Asc/SigHandler.hpp>
#include <Asc/SimHandler.hpp>
#include <Asc/AtcHandler.hpp>
#include <Asc/SmsHandler.hpp>
#include <Asc/SmsContext.hpp>
#include <Asc/SmsFactory.hpp>
#include <Asc/SmsSocket.hpp>
#include <Asc/SmsSocketListener.hpp>
#include <Asc/SsCcbsHandler.hpp>
#include <Asc/SimTkHandler.hpp>
#include <Asc/AocHandler.hpp>

#include <Asc/DataCall.hpp>
#include <Asc/PdpContextManager.hpp>

// obsolete moved to Compat
#if defined(APOXI_COMPAT_1_7_0) 
#include <Asc/SsHandler.hpp>
#endif

#endif  // Asc_Lib_hpp


