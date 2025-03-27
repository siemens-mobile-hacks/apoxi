/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDevicePairRequest_hpp)
#define BtDevicePairRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtDevicePairRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtDevicePairRequest(const BtDevice& device);

        virtual ~BtDevicePairRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN GetCreateTrust() const;


        void SetCreateTrust(BOOLEAN create_trust);

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;



        virtual BOOLEAN OnMessage(const Message& message);

    private:

        const btapi_bond_settings_t* GetApiSettings() const;

    private:
        btapi_bond_settings_t m_api_bond_settings;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtDevicePairRequest_hpp


