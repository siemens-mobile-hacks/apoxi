/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutImageReq_hpp)
#define BtBipPutImageReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipPutReq.hpp>

#include <Gui/ImageObtainer.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipPutImageReq : public BtBipPutReq
{
    private:
        typedef BtBipPutReq Base;

    public:
        BtBipPutImageReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipPutImageReq();


        virtual BtRequestType GetRequestType() const;
        
        /**********************************************************************/
        /* Put Image Req parameter access methods                             */
        /**********************************************************************/


        void SetImageName(const WCHAR* img_name);
        void SetImageDesc(const BtBipImageDescPtr& img_desc);
        void SetImageObtainer(const ImageObtainer& img_obt);

        /**********************************************************************/
        /**********************************************************************/
        void SetImageHdl(const BtBipImageHdlPtr& hdl) { m_img_hdl = hdl; }
        const BtBipImageHdlPtr& GetImageHdl() { return m_img_hdl; }

        virtual void PrepareNextPacket();

    protected:

        virtual BOOLEAN Execute();

        virtual void CleanUp();


//      virtual void ExecutionCallback(BtResultCode result);

    private:

        btapi_bip_put_img_t*    GetApiSettings();

        btapi_bip_put_img_t     m_operation_params;

        BtBipImageHdlPtr        m_img_hdl;
        ImageObtainer*          m_cur_img_obt;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipPutImageReq_hpp

