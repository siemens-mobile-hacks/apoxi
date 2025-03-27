/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtQuerySupportedProfilesRequest_hpp)
#define BtQuerySupportedProfilesRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

class BtQuerySupportedProfilesRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtQuerySupportedProfilesRequest(const BtDevice& device);

        virtual ~BtQuerySupportedProfilesRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN IsHsServiceSupported() const;


        const WString& GetHsServiceName() const;


        BOOLEAN HasRemoteVolumeControl() const;


        BOOLEAN IsHfServiceSupported() const;


        const WString& GetHfServiceName() const;


        UINT16 GetSupportedFeatures() const;


        BOOLEAN IsPaServiceSupported() const;


        const WString& GetPaServiceName() const;

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);


        virtual void OnHsProfileSupported(BtResultCode result, const WString& name, BOOLEAN has_remote_volume_control);


        virtual void OnHsProfileSupported(const WString& name, BOOLEAN has_remote_volume_control);


        virtual void OnHfProfileSupported(BtResultCode result, const WString& name, UINT16 supported_features);


        virtual void OnHfProfileSupported(const WString& name, UINT16 supported_features);


        virtual void OnPaProfileSupported(BtResultCode result, const WString& name);


        virtual void OnPaProfileSupported(const WString& name);

    private:

        void Reset(void);

    private:
        BOOLEAN m_is_hs_service_supported;

        WString m_hs_service_name;

        BOOLEAN m_has_remote_volume_control;

        BOOLEAN m_is_hf_service_supported;

        WString m_hf_service_name;

        UINT16 m_suported_features;

        BOOLEAN m_is_pa_service_supported;

        WString m_pa_service_name;
};

#endif  // BtQuerySupportedProfilesRequest_hpp

