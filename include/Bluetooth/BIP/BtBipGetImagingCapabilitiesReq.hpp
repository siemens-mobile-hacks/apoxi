/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImagingCapabilitiesReq_hpp)
#define BtBipGetImagingCapabilitiesReq_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Bluetooth/BIP/BtBipGetReq.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtBipClientService;

class BtBipGetImagingCapabilitiesReq : public BtBipGetReq
{
    private:
        typedef BtBipGetReq Base;

    public:
        BtBipGetImagingCapabilitiesReq(BtBipClientService& Bip_client_service);

        virtual ~BtBipGetImagingCapabilitiesReq();


        virtual BtRequestType GetRequestType() const;

        /**********************************************************************/
        /* Put Image Req parameter access methods                         */
        /*********************************************************************/

        void SetImageHdl(const BtBipImageHdlPtr& hdl);
        void SetImageCapabilitiesSink(const DataSinkPtr& sink) { m_img_caps_sink = sink; }

        const BtBipImagingCapabilitiesPtr& GetImagingCapabilities();

    protected:

        virtual BOOLEAN Execute();

    private:

        BtBipImagingCapabilitiesPtr m_img_caps;
        DataSinkPtr                 m_img_caps_sink;
        
    private:
        friend class BtBipController;
        friend class BtBipClientService;
};
#endif

#endif  // BtBipGetImagingCapabilitiesReq_hpp

