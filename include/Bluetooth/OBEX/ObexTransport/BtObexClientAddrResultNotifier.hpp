/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_BtObexClientAddrResultNotifier_hpp)
#define Apoxi_BtObexClientAddrResultNotifier_hpp

#include <Obex/ObexOperationId.hpp>

#include <Bluetooth/BtOperationSelectDeviceAndPerformServiceVerify.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>


class BtObexClientAddrResultNotifier: public BtOperationSelectDeviceAndPerformServiceVerify
{
    private:
        typedef BtOperationSelectDeviceAndPerformServiceVerify Base;

    public:
        static SharedPtr<BtObexClientAddrResultNotifier>
                    Create(const ObexOperationId &  job_id,
                           BtSecuritySettings       security,
                           const BtDeviceAddress &  device_addr,
                           UINT8                    rfcomm_chan);

    protected:
        BtObexClientAddrResultNotifier(const ObexOperationId &  job_id,
                                       BtSecuritySettings       security,
                                       const BtDeviceAddress &  device_addr,
                                       UINT8                    rfcomm_chan);

        virtual void OnResult(BtResultCode result);

    private:
        BtDeviceAddress     m_device_addr_2_verify;
        UINT8               m_rfcomm_chan_2_verify;
        BtSecuritySettings  m_security_settings;
        ObexOperationId     m_job_id;
};

#endif  // Apoxi_BtObexClientAddrResultNotifier_hpp

