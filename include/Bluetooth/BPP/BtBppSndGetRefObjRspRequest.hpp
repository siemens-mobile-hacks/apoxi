/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppSndGetRefObjRspRequest_hpp)
#define BtBppSndGetRefObjRspRequest_hpp

#include <Bluetooth/BPP/BtBppReq.hpp>
#include "BtBppTypes.hpp"

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBppClientService;

class BtBppSndGetRefObjRspRequest: public BtBppReq
{
    private:
        typedef BtBppReq Base;

    public:
        BtBppSndGetRefObjRspRequest(BtBppClientService& Bpp_client_service);

        virtual ~BtBppSndGetRefObjRspRequest();


        virtual BtRequestType GetRequestType() const;


        BtDevice GetTargetDevice() const;


        void SetTargetDevice(const BtDevice& target_device);





    protected:

        virtual BOOLEAN Execute();


        virtual void ExecutionCallback(BtResultCode result);

        btapi_bpp_snd_get_ref_obj_ind_t* GetApiSettings();

    private:

        btapi_bpp_snd_get_ref_obj_ind_t m_operation_params;

        friend class BtBppController;
};

#endif  // BtBppSndGetRefObjRspRequest_hpp

