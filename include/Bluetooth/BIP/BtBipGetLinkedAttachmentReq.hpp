/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetLinkedAttachmentReq_hpp)
#define BtBipGetLinkedAttachmentReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipGetReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipGetLinkedAttachmentReq : public BtBipGetReq
{
    private:
        typedef BtBipGetReq Base;

    public:
        BtBipGetLinkedAttachmentReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipGetLinkedAttachmentReq();


        virtual BtRequestType GetRequestType() const;


        /**********************************************************************/
        /* Put Image Req parameter access methods                         */
        /**********************************************************************/


        void SetImageHdl(const BtBipImageHdlPtr& hdl);
        void SetFileName(const WString& filename);



    protected:

        virtual BOOLEAN Execute();

    private:
        /* Parameters */
        btapi_bip_get_linked_attach_req_t*  GetApiSettings() { return &m_operation_params; }
        btapi_bip_get_linked_attach_req_t       m_operation_params;

        WString             m_file_name;
        BtBipImageHdlPtr    m_img_hdl;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipGetLinkedAttachmentReq_hpp

