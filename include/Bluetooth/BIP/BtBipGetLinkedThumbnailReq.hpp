/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetLinkedThumbnailReq_hpp)
#define BtBipGetLinkedThumbnailReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipGetReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipGetLinkedThumbnailReq : public BtBipGetReq
{
    private:
        typedef BtBipGetReq Base;

    public:
        BtBipGetLinkedThumbnailReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipGetLinkedThumbnailReq();


        virtual BtRequestType GetRequestType() const;


        /**********************************************************************/
        /* Put Image Req parameter access methods                         */
        /**********************************************************************/


        void SetImageHdl(const BtBipImageHdlPtr& hdl);



    protected:

        virtual BOOLEAN Execute();

    private:
        /* Parameters */
        const btapi_bip_img_hdl_t*  GetApiSettings() { return m_operation_params; }
        const btapi_bip_img_hdl_t*  m_operation_params;

        BtBipImageHdlPtr    m_img_hdl;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipGetLinkedThumbnailReq_hpp

