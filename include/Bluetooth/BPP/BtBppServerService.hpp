/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppServerService_hpp)
#define BtBppServerService_hpp

//#include <Bluetooth/BPP/BtBppServerServiceObserver.hpp>
//#include <Bluetooth/BPP/BtBppRegisterServerRequest.hpp>
//#include <Bluetooth/BPP/BtBppUnregisterServerRequest.hpp>
//#include <Bluetooth/BPP/BtBppSendResponseRequest.hpp>
#include <Bluetooth/BPP/BtBppService.hpp>
#include <Bluetooth/BPP/BtBppController.hpp>

#include <Bluetooth/BPP/BtBppTypes.hpp>

class BtBppServerService: public BtBppService
{
    private:
        typedef BtBppService Base;

    public:
        BtBppServerService();

        virtual ~BtBppServerService();


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual BOOLEAN IsServerService() const;


        virtual BtRequestState RegisterRequest(UINT8* header_buffer, UINT16 header_buffer_size, BtSecuritySettings security_settings = BtSesNoSecurity);


        virtual BtRequestState UnregisterRequest();


        UINT8 GetRfComChannel() const;


        BOOLEAN ConnectResponse();
            


        //to discuss, if application should need to handle this, or if it is better handled "under the hood"
        BtRequestState BppSndGetRefObjRsp( const BtDeviceAddress& device, BppObjectTypeEnum bpp_object_type_enum,  const Pathname& pathname);



    private:

        void BppSndGetRefObjIndCb(BtResultCode result);
        void BppSndGetRefObjCompleteIndCb(BtResultCode result);


};

#endif  // BtBppServerService_hpp

