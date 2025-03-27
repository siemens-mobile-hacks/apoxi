/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bluetooth_Lib_hpp)
#define Bluetooth_Lib_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtConstants.hpp>
#include <Bluetooth/BtApplicationMessage.hpp>
#include <Bluetooth/BtRequestMessage.hpp>
#include <Bluetooth/BtRequestOperationMessage.hpp>
#include <Bluetooth/BtServiceMessage.hpp>
#include <Bluetooth/BtEvent.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtDeviceAndServiceClass.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtDeviceFilter.hpp>
#include <Bluetooth/BtDeviceListIterator.hpp>
#include <Bluetooth/BtDeviceListReverseIterator.hpp>
#include <Bluetooth/BtDeviceList.hpp>
#include <Bluetooth/BtOperationBase.hpp>
#include <Bluetooth/BtRequest.hpp>
#include <Bluetooth/BtCancelableRequest.hpp>
#include <Bluetooth/BtCancelableBroadcastRequest.hpp>
#include <Bluetooth/BtCancelableMulticastRequest.hpp>
#include <Bluetooth/BtUncancelableRequest.hpp>
#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>
#include <Bluetooth/BtRequestRespondRequest.hpp>
#include <Bluetooth/BtService.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtConnectRequest.hpp>
#include <Bluetooth/BtDisconnectRequest.hpp>
#include <Bluetooth/BtAudioAccessoryService.hpp>
#include <Bluetooth/BtObservableService.hpp>
#include <Bluetooth/BtServiceObserver.hpp>
#include <Bluetooth/BtController.hpp>
#include <Bluetooth/BtConnectionBasedController.hpp>
#include <Bluetooth/BtSingleConnectionController.hpp>
#include <Bluetooth/BtMultiConnectionController.hpp>
#include <Bluetooth/BtUtility.hpp>

#include <Bluetooth/BtGapAndSdapApplicationMessage.hpp>
#include <Bluetooth/BtGapAndSdapRequestMessage.hpp>
#include <Bluetooth/BtGapAndSdapController.hpp>
#include <Bluetooth/BtTransport.hpp>
#include <Bluetooth/BtLocalSettings.hpp>
#include <Bluetooth/BtLocalRequest.hpp>
#include <Bluetooth/BtOperationSelectDevice.hpp>
#include <Bluetooth/BtOperationSelectDeviceAndPerformServiceVerify.hpp>
#include <Bluetooth/BtDevicePairRequest.hpp>
#include <Bluetooth/BtDeviceUnpairRequest.hpp>
#include <Bluetooth/BtDeviceTrustRequest.hpp>
#include <Bluetooth/BtDeviceUntrustRequest.hpp>
#include <Bluetooth/BtSetRemoteDeviceNameRequest.hpp>
#include <Bluetooth/BtQuerySupportedProfilesRequest.hpp>
#include <Bluetooth/BtSendPasskeyRequest.hpp>
#include <Bluetooth/BtRespondAuthorizationRequest.hpp>
#include <Bluetooth/BtDeviceSearchRequest.hpp>
#include <Bluetooth/BtServiceVerifyRequest.hpp>
#include <Bluetooth/BtServiceVerifyResult.hpp>
#include <Bluetooth/BtSvrServiceRecord.hpp>
#include <Bluetooth/BtSvrServiceAttribute.hpp>
#include <Bluetooth/BtSvrDataElement.hpp>

#include <Bluetooth/BtSddbEvent.hpp>
#include <Bluetooth/BtSddbServiceMessage.hpp>
#include <Bluetooth/BtSddbService.hpp>
#include <Bluetooth/BtSddbServiceObserver.hpp>
#include <Bluetooth/BtSddbRequest.hpp>
#include <Bluetooth/BtSddbRegisterServiceRecordRequest.hpp>
#include <Bluetooth/BtSddbUnregisterServiceRecordRequest.hpp>
#include <Bluetooth/BtSddbServiceRecord.hpp>
#include <Bluetooth/BtSddbDataElements.hpp>
#include <Bluetooth/BtSddbServiceAttribute.hpp>
#include <Bluetooth/BtServiceDiscoveryDatabase.hpp>

#endif  // Bluetooth_Lib_hpp


