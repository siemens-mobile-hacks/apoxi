/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Host_ValueMap_hpp)
#define Asc_Host_ValueMap_hpp

/*  ------------------------------------------------------------------------
    This file is used to map enums and constants to configuration dependent 
    (e.g. different protocol stacks, different build mode, ...) values.
    If a class-scope is used, then a configuration independent scope macro 
    must be defined in file <Asc/ValueMap.hpp>.
    ------------------------------------------------------------------------ */


/*  ------------------------------------------------------------------------
    PdpContextManager <Asc/PdpContextManager.hpp>
    ------------------------------------------------------------------------ */

// constants 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_c_max_cid_array_len c_max_cid_array_len = 11

/*  ------------------------------------------------------------------------
    PdpContextManager::AttachStatus <Asc/PdpContextManager.hpp>
    ------------------------------------------------------------------------ */

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_AttachStatus_StateAccepted StateAccepted = 0
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_AttachStatus_StateRejected StateRejected = 1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_AttachStatus_StateFiveTimeT3310Expiry StateFiveTimeT3310Expiry = 2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_AttachStatus_StateUserInteruption StateUserInteruption = 3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_AttachStatus_StateUnknownCause StateUnknownCause = 4

/*  ------------------------------------------------------------------------
    PdpContext <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// constants
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_c_max_access_point_name_len c_max_access_point_name_len = 101

// enum Type
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_X25Type X25Type 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IpType IpType
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IpStaticType IpStaticType
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IpDynamicType IpDynamicType
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_OspihType OspihType
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PppType PppType
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NoType NoType

// enum Protocol
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NullProtocol NullProtocol 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PppProtocol PppProtocol 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PadProtocol PadProtocol 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_X25Protocol X25Protocol 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ManufProtocol ManufProtocol 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NoProtocol NoProtocol 

// enum Origin
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Network Network 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MobileStation MobileStation 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnknownOrigin UnknownOrigin 

// enum ErrorCause
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IllegalMs IllegalMs = 3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IllegalMe IllegalMe = 6
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_GprsServiceNotAllowed GprsServiceNotAllowed = 7
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PlmnNotAllowed PlmnNotAllowed = 11
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_LaNotAllowed LaNotAllowed = 12
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NationalRoamingNotAllowed NationalRoamingNotAllowed = 13

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_LlcOrSndcpFailure LlcOrSndcpFailure = 25
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_InsufficientRessources InsufficientRessources = 26
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MissingOrUnknownApn MissingOrUnknownApn = 27
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnknownPdpAddress UnknownPdpAddress = 28
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_AuthenticationFailure AuthenticationFailure = 29
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationRejectedByGgsn ActivationRejectedByGgsn = 30
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnspecifiedActivationRejection UnspecifiedActivationRejection = 31
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ServiceOptionNotSupported ServiceOptionNotSupported = 32
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_RequestedServiceOptionNotSubscribed RequestedServiceOptionNotSubscribed = 33
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ServiceOptionTemporaryOutOfOrder ServiceOptionTemporaryOutOfOrder = 34
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NsapiAlreadyUsed NsapiAlreadyUsed = 35
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_RegularDeactivation RegularDeactivation = 36
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QosNotAccepted QosNotAccepted = 37
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NetworkFailure NetworkFailure = 38
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ReactivationRequired ReactivationRequired = 39
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_InvalidTi InvalidTi = 81
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_SemanticIncorrectMsg SemanticIncorrectMsg = 95
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_InvalidMandatoryIe InvalidMandatoryIe = 96
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MsgTypeNotExistent MsgTypeNotExistent = 97
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MsgTypeNotCompatible MsgTypeNotCompatible = 98
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IeNonExistent IeNonExistent = 99
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ConditionalIeError ConditionalIeError = 100
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MsgNotCompatible MsgNotCompatible = 101
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnspecifiedProtocolError UnspecifiedProtocolError = 111

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UndefinedError UndefinedError 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NoError NoError 


/*  ------------------------------------------------------------------------
    PdpContext::Address <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// constants
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Address_c_max_len c_max_len = 19

/*  ------------------------------------------------------------------------
    PdpContext::Authentication <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// constants
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_c_max_account_len c_max_account_len = 20
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_c_max_password_len c_max_password_len = 10

// enum Type
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_None None
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_Pap Pap
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_Chap Chap

/*  ------------------------------------------------------------------------
    PdpContext::QualityOfService <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// enum Precedence
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceSubscribed PrecedenceSubscribed
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceHigh PrecedenceHigh
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceNormal PrecedenceNormal
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceLow PrecedenceLow
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceReserved PrecedenceReserved


// enum Delay
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelaySubscribed DelaySubscribed
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayClass1 DelayClass1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayClass2 DelayClass2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayClass3 DelayClass3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayBestEffort DelayBestEffort
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayReserved DelayReserved

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilitySubscribed ReliabilitySubscribed
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass1 ReliabilityClass1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass2 ReliabilityClass2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass3 ReliabilityClass3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass4 ReliabilityClass4
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass5 ReliabilityClass5
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass6 ReliabilityClass6
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityReserved ReliabilityReserved

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRateSubscribed PeakRateSubscribed
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate1K PeakRate1K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate2K PeakRate2K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate4K PeakRate4K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate8K PeakRate8K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate16K PeakRate16K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate32K PeakRate32K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate64K PeakRate64K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate128K PeakRate128K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate256K PeakRate256K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRateReserved PeakRateReserved

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRateSubscribed MeanRateSubscribed
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate100 MeanRate100
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate200 MeanRate200
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate500 MeanRate500
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate1K MeanRate1K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate2K MeanRate2K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate5K MeanRate5K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate10K MeanRate10K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate20K MeanRate20K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate50K MeanRate50K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate100K MeanRate100K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate200K MeanRate200K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate500K MeanRate500K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate1M MeanRate1M
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate2M MeanRate2M
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate5M MeanRate5M
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate10M MeanRate10M
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate20M MeanRate20M
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate50M MeanRate50M
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRateReserved MeanRateReserved
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRateBestEffort MeanRateBestEffort

/*  ------------------------------------------------------------------------
    PdpContext::ActivationStatus <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_StateAccepted StateAccepted = 0
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_StateRejected StateRejected = 1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_StateFiveTimeT3380Expiry StateFiveTimeT3380Expiry = 2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_StateUserInteruption StateUserInteruption = 3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_StateUnknownCause StateUnknownCause = 4

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_RadioPriorityLevel_1 RadioPriorityLevel_1 = 1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_RadioPriorityLevel_2 RadioPriorityLevel_2 = 2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_RadioPriorityLevel_3 RadioPriorityLevel_3 = 3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_RadioPriorityLevel_4 RadioPriorityLevel_4 = 4
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_RadioPriorityLevel_Undefined RadioPriorityLevel_Undefined = 0

// enum LlcSapi
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_NotAssigned LlcSapi_NotAssigned = 0
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_1 LlcSapi_1 = 1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_3 LlcSapi_3 = 3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_5 LlcSapi_5 = 5
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_7 LlcSapi_7 = 7
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_9 LlcSapi_9 = 9
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_11 LlcSapi_11 = 11
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationStatus_LlcSapi_Invalid LlcSapi_Invalid = 255

/*  ------------------------------------------------------------------------
    PdpContext::PacketFilter <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// enum Type
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PacketFilter_Type_1 Type_1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PacketFilter_Type_2 Type_2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PacketFilter_Type_3 Type_3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PacketFilter_Type_Unknown Type_Unknown

#endif  // Asc_Host_ValueMap_hpp

