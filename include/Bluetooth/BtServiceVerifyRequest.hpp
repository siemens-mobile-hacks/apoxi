/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtServiceVerifyRequest_hpp)
#define BtServiceVerifyRequest_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtCancelableMulticastRequest.hpp>
#include <Bluetooth/BtServiceVerifyResult.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtServiceVerifyRequest: public BtCancelableMulticastRequest
{
    private:
        typedef BtCancelableMulticastRequest Base;

    public:
        BtServiceVerifyRequest(const BtDeviceList& device_list);

        virtual ~BtServiceVerifyRequest();


        virtual BtRequestType GetRequestType() const;


        BtDeviceRelation GetDeviceRelation() const;


        void SetDeviceRelation(BtDeviceRelation device_relation);


        UINT8 GetNumberOfServicesToVerify() const;


        const BtUUID* GetServicesToVerify() const;


        BOOLEAN SetServicesToVerify(const BtUUID* uuids, UINT8 number_of_uuids);


        UINT8 GetNumberOfAttributesRequested() const;


        const BtAttributeId* GetAttributesRequested() const;


        BOOLEAN SetAttributesRequested(const BtAttributeId* attribute_ids, UINT8 number_of_attribute_ids);


        const BtServiceVerifyResult* GetServiceVerifyResult(const BtDeviceAddress& device_address) const;

    protected:

        virtual BOOLEAN Execute();


        virtual BOOLEAN Cancel();


        virtual void RegisterMessages(void) const;


        virtual void UnregisterMessages(void) const;


        virtual BOOLEAN OnMessage(const Message& message);


        virtual void OnServiceVerifyResultReceived(const BtDeviceAddress& device_address, const WString& device_name, const BtServiceVerifyResult* service_verify_result);

    private:

        void ClearServiceVerifyResultList();

    private:
        class BtServiceVerifyResultNode
        {
            public:
                BtServiceVerifyResultNode(const BtDeviceAddress& device_address, BtServiceVerifyResult* service_verify_result = 0, BtServiceVerifyResultNode* next = 0);

                ~BtServiceVerifyResultNode();


                BtServiceVerifyResultNode* GetNext();

                /* <em>SetNext</em> sets thelink pointer to the passed in node 
                    that should become the successor of <em>this</em> node.
                    @param next A pointer to a 
                                    <em>BtServiceVerifyResultNode</em> that 
                                    should become <em>this</em> nodes 
                                    successor. */
                void SetNext(BtServiceVerifyResultNode* next);


                BtDeviceAddress& GetDeviceAddress();


                BtServiceVerifyResult* GetServiceVerifyResult();


                void SetServiceVerifyResult(BtServiceVerifyResult* service_verify_result);

            private:
                BtServiceVerifyResultNode* m_next;

                BtDeviceAddress m_device_address;

                BtServiceVerifyResult* m_service_verify_result;
        };

    private:

        const btapi_service_search_req_t* GetApiSettings() const;

    private:
        btapi_service_search_req_t m_api_service_verify;

        BtServiceVerifyResultNode* m_anchor;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtServiceVerifyRequest_hpp


