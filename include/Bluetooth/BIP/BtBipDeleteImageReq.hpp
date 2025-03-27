/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipDeleteImageReq_hpp)
#define BtBipDeleteImageReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipDeleteImageReq : public BtBipReq
{
    private:
        typedef BtBipReq Base;

    public:
        BtBipDeleteImageReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipDeleteImageReq();


        virtual BtRequestType GetRequestType() const;


        /**********************************************************************/
        /* Put Image Req parameter access methods                         */
        /**********************************************************************/


        void SetImageHdl(const BtBipImageHdlPtr& hdl);
        void SetImageDesc(const BtBipImageDescPtr& img_desc);



        void SetFileLen(UINT32 file_len) { m_file_len = file_len; }
        UINT32 GetFileLen() { return m_file_len; }

    protected:

        virtual BOOLEAN Execute();

    private:
        /* Parameters */
        const btapi_bip_img_hdl_t*  GetApiSettings();
        const btapi_bip_img_hdl_t*  m_operation_params;

        BtBipImageHdlPtr    m_img_hdl;

        /* Results */
        UINT16  m_img_len;
        UINT8*  m_img_body;
        UINT32  m_file_len;
        
    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipDeleteImageReq_hpp

