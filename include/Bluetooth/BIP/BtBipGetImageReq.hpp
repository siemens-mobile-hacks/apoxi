/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImageReq_hpp)
#define BtBipGetImageReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipGetReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipGetImageReq : public BtBipGetReq
{
    private:
        typedef BtBipGetReq Base;

    public:
        BtBipGetImageReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipGetImageReq();


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
        btapi_bip_get_img_t*    GetApiSettings();
        btapi_bip_get_img_t m_operation_params;

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

#endif  // BtBipGetImageReq_hpp

