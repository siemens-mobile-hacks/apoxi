/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBppRequest_hpp)
#define BtBppRequest_hpp

#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BPP/BtBppService.hpp>
//#include <Bluetooth/BPP/BtBppController.hpp>
#include <Bluetooth/BPP/BtBppTypes.hpp>


/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBppController;

class BtBppReq: public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtBppReq(BtBppService& obex_service);

        virtual ~BtBppReq();

    protected:

        virtual BtRequestState ChangeRequestState(BOOLEAN success);

        virtual void SetRequestState(BtRequestState request_state);



        virtual BOOLEAN EvaluateExecutionResult(BtResultCode result);
        

        void SetObexResult(UINT8 res) { m_obex_result = res; }
        void SetBppResult(BtBppResult res) { m_bpp_result = res; }


    private:
        BtBppResult m_bpp_result;
        UINT8   m_obex_result;
        friend class BtBppController;
};

#endif  // BtBppRequest_hpp

