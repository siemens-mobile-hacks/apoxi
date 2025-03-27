/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipPutAttachReq_hpp)
#define BtBipPutAttachReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BIP/BtBipReq.hpp>
#include <Bluetooth/BIP/BtBipPutReq.hpp>

#include <Gui/ImageObtainer.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipPutAttachReq : public BtBipPutReq
{
    private:
        typedef BtBipPutReq Base;

    public:
        BtBipPutAttachReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipPutAttachReq();


        virtual BtRequestType GetRequestType() const;
        
        /**********************************************************************/
        /* Put Image Req parameter access methods                             */
        /**********************************************************************/


        void SetImageHdl(const BtBipImageHdlPtr& img_hdl);
        void SetAttachmentDesc(const BtBipAttachmentDescPtr& attach_desc);

        /**********************************************************************/
        /**********************************************************************/

        virtual void PrepareNextPacket();

    protected:

        virtual BOOLEAN Execute();

        virtual void CleanUp();

    private:

        btapi_bip_put_linked_attachment_t*  GetApiSettings();
        btapi_bip_put_linked_attachment_t   m_operation_params;

        BtBipImageHdlPtr        m_img_hdl;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipPutAttachReq_hpp

