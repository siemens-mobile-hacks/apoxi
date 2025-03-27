/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImagingCapabilitiesRsp_hpp)
#define BtBipGetImagingCapabilitiesRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Auxiliary/DataSink.hpp>
#include <Bluetooth/BIP/BtBipGetRsp.hpp>
#include <Bluetooth/BIP/BtBipTypes.hpp>

class BtBipGetImagingCapabilitiesRsp : BtBipGetRsp
{
    private:
        typedef BtBipGetRsp Base;

    public:
        BtBipGetImagingCapabilitiesRsp();
        virtual ~BtBipGetImagingCapabilitiesRsp();

        virtual BtRequestType GetRequestType() const { return BtRqtBipGetImagingCapabilities; }

        void GetImagingCapabilitesInd();

        void SetImagingCapabilities(const BtBipImagingCapabilitiesPtr& caps);

    protected:
        virtual BOOLEAN ExecuteRsp();

        UINT8*  m_img_caps;


    private:
        friend class BtBipController;
        friend class BtBipServerService;
};
#endif

#endif  // BtBipGetImagingCapabilitiesRsp_hpp

