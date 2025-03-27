/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutThumbReq_hpp)
#define BtBipPutThumbReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipPutReq.hpp>

#include <Gui/ImageObtainer.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipPutThumbReq : public BtBipPutReq
{
    private:
        typedef BtBipPutReq Base;

    public:
        BtBipPutThumbReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipPutThumbReq();


        virtual BtRequestType GetRequestType() const;
        
        /**********************************************************************/
        /* Put Image Req parameter access methods                             */
        /**********************************************************************/


        void SetImageHdl(const BtBipImageHdlPtr& img_hdl);
        void SetImageObtainer(const ImageObtainer& img_obt);

        /**********************************************************************/
        /**********************************************************************/

        virtual void PrepareNextPacket();

    protected:

        virtual BOOLEAN Execute();

        virtual void CleanUp();


//      virtual void ExecutionCallback(BtResultCode result);

    private:

        btapi_bip_put_linked_thumb_t*   GetApiSettings();

        btapi_bip_put_linked_thumb_t    m_operation_params;

        BtBipImageHdlPtr        m_img_hdl;

        ImageObtainer*          m_cur_img_obt;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipPutThumbReq_hpp

