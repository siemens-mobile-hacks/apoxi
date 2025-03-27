/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Target_TypeDef_hpp)
#define Asc_Target_TypeDef_hpp

/*  ------------------------------------------------------------------------
    This file is used to map enums and constants to configuration dependent 
    (e.g. different protocol stacks, different build mode, ...) values.
    If a class-scope is used, then a configuration independent scope macro 
    must be defined in file <Asc/ValueMap.hpp>.
    ------------------------------------------------------------------------ */


#include <Apc/SignalTypes.hpp>

/*  ------------------------------------------------------------------------
    PdpContextManager <Asc/PdpContextManager.hpp>
    ------------------------------------------------------------------------ */

// constants 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContextManager_c_max_cid_array_len c_max_cid_array_len = MAX_CID_ARRAY_LENGTH

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
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_c_max_access_point_name_len c_max_access_point_name_len = APN_LEN

// enum Type
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_X25Type X25Type = X25_TYPE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IpType IpType = IP_TYPE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IpStaticType IpStaticType = IP_TYPE_STATIC
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IpDynamicType IpDynamicType = IP_TYPE_DYNAMIC
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_OspihType OspihType = OSPIH_TYPE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PppType PppType = PPP_TYPE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NoType NoType = NO_TYPE

// enum Protocol
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NullProtocol NullProtocol = L2_NULL 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PppProtocol PppProtocol = L2_PPP  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PadProtocol PadProtocol = L2_PAD
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_X25Protocol X25Protocol = L2_X25 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ManufProtocol ManufProtocol = L2_MANUF
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NoProtocol NoProtocol = L2_NONE 

// enum Origin
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Network Network = PCH_NW 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MobileStation MobileStation = PCH_MS  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnknownOrigin UnknownOrigin

// enum ErrorCause
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IllegalMs IllegalMs =  ERR_ILLEGAL_MS
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IllegalMe IllegalMe =  ERR_ILLEGAL_ME
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_GprsServiceNotAllowed GprsServiceNotAllowed = ERR_GPRS_NOT_ALLOWED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_PlmnNotAllowed PlmnNotAllowed = ERR_PLMN_NOT_ALLOWED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_LaNotAllowed LaNotAllowed = ERR_LA_NOT_ALLOWED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NationalRoamingNotAllowed NationalRoamingNotAllowed = ERR_NAT_ROAMING_NOT_ALLOWED

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ServiceOptionNotSupported ServiceOptionNotSupported = SM_SERVICE_OPT_NOT_SUPPORTED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_RequestedServiceOptionNotSubscribed RequestedServiceOptionNotSubscribed = SM_REQ_SERVICE_NOT_SUBSCRIBED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ServiceOptionTemporaryOutOfOrder ServiceOptionTemporaryOutOfOrder = SM_SERVICE_TEMP_OUT_OF_ORDER
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NsapiAlreadyUsed NsapiAlreadyUsed = SM_NSAPI_ALREADY_USED

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnspecifiedProtocolError UnspecifiedProtocolError = SM_PROTOCOL_ERROR_UNSPECIFIED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_AuthenticationFailure AuthenticationFailure = SM_USER_AUTH_FAILED

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_LlcOrSndcpFailure LlcOrSndcpFailure = SM_LLC_OR_SNDCP_FAILURE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_InsufficientRessources InsufficientRessources = SM_INSUFFICIENT_RESOURCES
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MissingOrUnknownApn MissingOrUnknownApn = SM_MISSING_OR_UNKNOWN_APN
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnknownPdpAddress UnknownPdpAddress = SM_UNKNOWN_PDP_ADDRESS
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ActivationRejectedByGgsn ActivationRejectedByGgsn = SM_ACTIVATION_REJECTED_BY_GGSN
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UnspecifiedActivationRejection UnspecifiedActivationRejection = SM_ACTIVATION_REJECTED_UNSPECIFIED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_RegularDeactivation RegularDeactivation = SM_REGULAR_DEACTIVATION
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QosNotAccepted QosNotAccepted = SM_QOS_NOT_ACCEPTED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NetworkFailure NetworkFailure = SM_NETWORK_FAILURE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ReactivationRequired ReactivationRequired = SM_REACTIVATION_REQUIRED
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_InvalidTi InvalidTi = SM_INVALID_TI
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_SemanticIncorrectMsg SemanticIncorrectMsg = SM_SEMANT_INCORRECT_MSG
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_InvalidMandatoryIe InvalidMandatoryIe = SM_INV_MANDATORY_IE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MsgTypeNotExistent MsgTypeNotExistent = SM_MSG_TYPE_NOT_EXISTENT
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MsgTypeNotCompatible MsgTypeNotCompatible = SM_MSG_TYPE_NOT_COMPATIBLE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_IeNonExistent IeNonExistent = SM_IE_NON_EXISTENT
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_ConditionalIeError ConditionalIeError = SM_CONDITIONAL_IE_ERROR
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_MsgNotCompatible MsgNotCompatible = SM_MSG_NOT_COMPATIBLE

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_UndefinedError UndefinedError 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_NoError NoError 


/*  ------------------------------------------------------------------------
    PdpContext::Address <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// constants
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Address_c_max_len c_max_len = PDP_ADDRESS_LEN

/*  ------------------------------------------------------------------------
    PdpContext::Authentication <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// constants
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_c_max_account_len c_max_account_len = AUTH_USERNAME_LEN
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_c_max_password_len c_max_password_len = AUTH_PASSWORD_LEN

// enum Type
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_None None = PCH_AUTH_NONE
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_Pap Pap = PCH_AUTH_PAP
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_Authentication_Chap Chap = PCH_AUTH_CHAP

/*  ------------------------------------------------------------------------
    PdpContext::QualityOfService <Asc/PdpContext.hpp>
    ------------------------------------------------------------------------ */
// enum Precedence
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceSubscribed PrecedenceSubscribed = PRECEDENCE_CLASS_S
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceHigh PrecedenceHigh = PRECEDENCE_CLASS_H
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceNormal PrecedenceNormal = PRECEDENCE_CLASS_N
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceLow PrecedenceLow = PRECEDENCE_CLASS_L
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PrecedenceReserved PrecedenceReserved = PRECEDENCE_CLASS_R

// enum Delay
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelaySubscribed DelaySubscribed = DELAY_CLASS_S
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayClass1 DelayClass1 = DELAY_CLASS_1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayClass2 DelayClass2 = DELAY_CLASS_2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayClass3 DelayClass3 = DELAY_CLASS_3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayBestEffort DelayBestEffort = DELAY_CLASS_4
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_DelayReserved DelayReserved = DELAY_CLASS_R

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilitySubscribed ReliabilitySubscribed = RELIABILITY_CLASS_S
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass1 ReliabilityClass1 = RELIABILITY_CLASS_1
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass2 ReliabilityClass2 = RELIABILITY_CLASS_2
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass3 ReliabilityClass3 = RELIABILITY_CLASS_3
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass4 ReliabilityClass4 = RELIABILITY_CLASS_4
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass5 ReliabilityClass5 = RELIABILITY_CLASS_5
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityClass6 ReliabilityClass6 = RELIABILITY_CLASS_6
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_ReliabilityReserved ReliabilityReserved = RELIABILITY_CLASS_R

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRateSubscribed PeakRateSubscribed = PEAK_THP_S   
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate1K PeakRate1K = PEAK_THP_1K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate2K PeakRate2K = PEAK_THP_2K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate4K PeakRate4K = PEAK_THP_4K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate8K PeakRate8K = PEAK_THP_8K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate16K PeakRate16K = PEAK_THP_16K 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate32K PeakRate32K = PEAK_THP_32K 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate64K PeakRate64K = PEAK_THP_64K 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate128K PeakRate128K = PEAK_THP_128K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRate256K PeakRate256K = PEAK_THP_256K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_PeakRateReserved PeakRateReserved = PEAK_THP_R   

#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRateSubscribed MeanRateSubscribed = MEAN_THP_S   
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate100 MeanRate100 = MEAN_THP_100 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate200 MeanRate200 = MEAN_THP_200 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate500 MeanRate500 = MEAN_THP_500 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate1K MeanRate1K = MEAN_THP_1K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate2K MeanRate2K = MEAN_THP_2K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate5K MeanRate5K = MEAN_THP_5K  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate10K MeanRate10K = MEAN_THP_10K 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate20K MeanRate20K = MEAN_THP_20K 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate50K MeanRate50K = MEAN_THP_50K 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate100K MeanRate100K = MEAN_THP_100K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate200K MeanRate200K = MEAN_THP_200K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate500K MeanRate500K = MEAN_THP_500K
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate1M MeanRate1M = MEAN_THP_1M  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate2M MeanRate2M = MEAN_THP_2M  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate5M MeanRate5M = MEAN_THP_5M  
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate10M MeanRate10M = MEAN_THP_10M 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate20M MeanRate20M = MEAN_THP_20M 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRate50M MeanRate50M = MEAN_THP_50M 
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRateReserved MeanRateReserved = MEAN_THP_R     
#define APOXI_DEFINE_SCOPE_ENTITY_PdpContext_QualityOfService_MeanRateBestEffort MeanRateBestEffort = MEAN_THP_BE

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

#endif  // Asc_Target_TypeDef_hpp

