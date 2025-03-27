/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtBipGetImagePropertiesRsp_hpp)
#define BtBipGetImagePropertiesRsp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Auxiliary/DataSink.hpp>
#include <Bluetooth/BIP/BtBipGetRsp.hpp>

class BtBipGetImagePropertiesRsp : BtBipGetRsp
{
    private:
        typedef BtBipGetRsp Base;

    public:
        BtBipGetImagePropertiesRsp();
        virtual ~BtBipGetImagePropertiesRsp();

        virtual BtRequestType GetRequestType() const { return BtRqtBipGetImageProperties; }

        void GetImagePropertiesInd(const BtBipImageHdlPtr& hdl);
        void SetImageProperties(const BtBipImagePropertiesPtr& img_props);

protected:
        virtual BOOLEAN ExecuteRsp();
        
    private:
        BtBipImagePropertiesPtr m_img_props;
        UINT8*  m_img_props_text;

    private:
        friend class BtBipController;
        friend class BtBipServerService;
};

#endif

#endif  // BtBipGetImagePropertiesRsp_hpp

