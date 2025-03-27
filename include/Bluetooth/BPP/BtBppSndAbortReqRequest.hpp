/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppSndAbortReqRequest_hpp)
#define BtBppSndAbortReqRequest_hpp

#include <Bluetooth/BPP/BtBppTypes.hpp>
#include <Bluetooth/BPP/BtBppReq.hpp>
//#include <Bluetooth/BPP/BtBppClientService.hpp>


/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBppClientService;

class BtBppSndAbortReqRequest: public BtBppReq
{
    private:
        typedef BtBppReq Base;

    public:
        BtBppSndAbortReqRequest(BtBppClientService& Bpp_client_service);

        virtual ~BtBppSndAbortReqRequest();


        virtual BtRequestType GetRequestType() const;


        BtDevice GetTargetDevice() const;


//      void SetTargetDevice(const BtDevice& target_device);
//      void SetObjectType( BppObjectTypeEnum bpp_object_type);
//      void SetObjectName( UINT16* object_name);
//      void SetObjectDescription( UINT16* object_description);

//      void SetBuffer(UINT8 * buffer, UINT32  buff_used_bytes, UINT32 total_body_length, BOOLEAN is_final_buff);

        virtual BtRequestState ChangeRequestState(BOOLEAN success);
        virtual void SetRequestState(BtRequestState request_state);

/*      enum BppSubstate {
            bpp_state1_initial,
            bpp_state2_pushsent,
            bpp_state3_connect_ind_received_ok,
            bpp_state3_connect_ind_received_failed,
            bpp_state4_push_cfm_received_ok_send_more,
            bpp_state4_push_cfm_received_ok_final,
            bpp_state4_push_cfm_received_failed,
            bpp_state5_disconnect_ind_received,


        }; */

//      void SetBppSubState(BppSubstate substate) { m_bpp_sub_state = substate; }
//      BppSubstate GetBppSubState() { return m_bpp_sub_state; }

    protected:

        virtual BOOLEAN Execute();


        virtual void ExecutionCallback(BtResultCode result);

//      btapi_bpp_snd_abort_req_t* GetApiSettings();

    private:

//      btapi_bpp_snd_abort_req_t   m_operation_params;


//      BppSubstate m_bpp_sub_state;

        friend class BtBppController;
    public:
//      UINT8 * buff;
//      UINT32  buff_used_bytes;

};

#endif  // BtBppSndAbortReqRequest_hpp

