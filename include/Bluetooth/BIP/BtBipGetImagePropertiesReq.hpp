/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImagePropertiesReq_hpp)
#define BtBipGetImagePropertiesReq_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Bluetooth/BIP/BtBipGetReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipGetImagePropertiesReq : public BtBipGetReq
{
    private:
        typedef BtBipGetReq Base;

    public:
        BtBipGetImagePropertiesReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipGetImagePropertiesReq();


        virtual BtRequestType GetRequestType() const;

        /**********************************************************************/
        /* Put Image Req parameter access methods                         */
        /*********************************************************************/

        void SetImagePropertiesSink(const DataSinkPtr& sink) { m_img_props_sink = sink; }
        void SetImageHdl(const BtBipImageHdlPtr& hdl);

        const BtBipImagePropertiesPtr& GetImageProperties();

    protected:

        virtual BOOLEAN Execute();

    private:

        const btapi_bip_img_hdl_t*  GetApiSettings() { return m_operation_params; }
        const btapi_bip_img_hdl_t*  m_operation_params;

        BtBipImagePropertiesPtr     m_img_props;
        DataSinkPtr                 m_img_props_sink;
        BtBipImageHdlPtr            m_img_hdl;

    private:
        friend class BtBipController;
        friend class BtBipClientService;
};

#endif

#endif  // BtBipGetImagePropertiesReq_hpp

