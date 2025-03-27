/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceListsWindows_hpp)
#define BtDeviceListsWindows_hpp

#include <Auxiliary/Provider.hpp>
#include <Auxiliary/GenericObject.hpp>
#include <Gui/ItemMenu.hpp>
#include <Atl/Gui/AtlItemListWindow.hpp>
#include <Atl/Features/ProviderProxyContainer.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtDeviceList.hpp>
#include <Bluetooth/BtDeviceListIterator.hpp>
#include <Bluetooth/BtLocalSettings.hpp>
#include <Bluetooth/BtOperationSelectDeviceAndPerformServiceVerify.hpp>
#include <Bluetooth/BtOperationSelectDevice.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include <BtApp/BtApplicationRequests.hpp>
#include <BtApp/BtDeviceDetailWindow.hpp>



class BtDeviceAddressGenericObject : public GenericObject
{
    private:
        typedef GenericObject Base;

    public:
        BtDeviceAddressGenericObject();


        BtDeviceAddressGenericObject(const BtDeviceAddressGenericObject& generic_object);


        BtDeviceAddressGenericObject(const BtDeviceAddress& device_address);

        virtual ~BtDeviceAddressGenericObject();


        virtual GenericObject* Copy() const;


        virtual BOOLEAN IsEqual(GenericObject* object);


        virtual GenericTypeId GetTypeId();

        const BtDeviceAddress& GetDeviceAddress() const;

    private:
        BtDeviceAddress m_device_address;
};

class BtDeviceListProvider : public Provider
{
    private:
        typedef Provider Base;

    public:

        BtDeviceListProvider(const BtDeviceList* device_list);

        virtual ~BtDeviceListProvider();


        void SetDeviceList(const BtDeviceList* device_list);


        virtual INT GetProviderId() const;


        virtual Status GetStatus() const;


        virtual INT RowCount();


        virtual BOOLEAN GetDataItem(INT column, INT row, DataItem& data_item);

    protected:

        BOOLEAN GetDeviceName(INT index, DataItem& data_item);


        BOOLEAN GetDeviceAddress(INT index, DataItem& data_item);


        BOOLEAN GetDeviceMajorClass(INT index, DataItem& data_item);

        BOOLEAN GetDeviceMinorClass(INT index, DataItem& data_item);


        BtDeviceListConstantIterator GetDeviceAtIndex(INT index);

    private:
        const BtDeviceList* m_device_list;
};


class BtDeviceListItem: public Item
{
    private:
        typedef Item Base;

    public:
        BtDeviceListItem(Dispatcher* dispatcher, const WString& device_name, const BtDeviceAddress& device_address);

        virtual ~BtDeviceListItem();


        const BtDeviceAddress& GetDeviceAddress() const;

    private:
        BtDeviceAddress m_device_address;
};


class BtDeviceListWindow : public AtlItemListWindow
{
    private:
        typedef AtlItemListWindow Base;

    public:
        typedef enum
        {
            BtDlwPairedDevices,
            BtDlwFoundDevices

        } BtDeviceListWindowType;

    public:
        BtDeviceListWindow();
        virtual ~BtDeviceListWindow();
        void Init();
        BtDeviceListWindowType GetType();
        void SetType(BtDeviceListWindowType type);
        void UpdateConnectProfileSelectedWindow(BOOLEAN open);

        BOOLEAN OnFeatureTriggered(const FeatureID &feature_id);

        void OnShowDetailsActionExecuted();
        void OnPairDeviceActionExecuted();
        void OnUnpairDeviceActionExecuted();
        void OnTrustDeviceActionExecuted();
        void OnUntrustDeviceActionExecuted();
        void OnSetDeviceNameActionExecuted();
        void OnSearchAgainActionExecuted();
        void OnConnectActionExecuted();
        void OnRemoteDeviceSetNameNotification(BtDevice device, WString device_name);
        void OnRequestFinished(BOOLEAN success);
        void OnSupportedProfileSearch();
        const WString& GetDeviceName(INT index, Provider* prov);
        const BtDeviceAddress& GetDeviceAddress(INT index,  Provider* prov);
        const BtDeviceAndServiceClass& GetDeviceClass(INT index, Provider* prov);
        const BitmapRes* GetDeviceIcon(INT index, Provider* prov);
        void UpdateDeviceList();
        BtDeviceListProvider* GetDeviceListProvider() { return &m_device_list_provider; }

        BOOLEAN DoRequestOperation(BtOperationPtr operation);
        void SetCanSelect(BOOLEAN can_select);
        void OnServiceVerifyRequestFinished(BOOLEAN success);
        BOOLEAN GetImmediateSearch();
        void SetImmediateSearch(BOOLEAN immediate_search);

        void OnDeviceNameFound();
        void DeviceSearchCancelRequest();
        void UpdateOptionMenu(INT index);
        void UpdateConnectOptions(BOOLEAN enable);
        void OnDeviceSelectActionExecuted();
        BtDevice GetSelectedDevice() { return m_selected_device; }

    protected:
        virtual void OnOpen();
        void OnPairDeviceActionFinished(BOOLEAN success);
        void OnUnpairDeviceActionFinished(BOOLEAN success);
        void OnTrustDeviceActionFinished(BOOLEAN success);
        void OnUntrustDeviceActionFinished(BOOLEAN success);
        void OnSearchAgainActionFinished(BOOLEAN success);
        void OnQuerySupportedProfileFinished(BOOLEAN success);
        void UpdateList(void);
        void OnServiceVerifyRequestExecuted(const BtDevice& device, const BtUUID* services_to_verify, UINT8 number_of_services_to_verify, const BtAttributeId* attributes_requested, UINT8 number_of_attributes_requested);
        void DoOperation(const BtDeviceFilter& device_filter);
        void OnOperationFinished();

    private:
        void ValidateRequest();
        BtDeviceListWindowType m_type;
        BtDevice m_selected_device;
        BtDevice m_obex_selected_device;
        BtDeviceList m_device_list;
        BtDeviceListProvider m_device_list_provider;

        AtlItemListWindow           m_device_list_win;
        ProviderProxyContainer      m_device_list_container;
        ItemContainer               m_item_cont;
        Item                        m_item;
        BtApplicationSetRemoteDeviceNameRequest m_set_remote_device_name_request;

        BtAlertMessageWindow m_alert_message_window;
        BtRequestRunningWindow m_request_running_window;
        BtDeviceDetailWindow m_device_detail_window;
        BtApplicationDevicePairRequest m_device_pair_request;
        BtApplicationDeviceUnpairRequest m_device_unpair_request;
        BtApplicationDeviceTrustRequest m_device_trust_request;
        BtApplicationDeviceUntrustRequest m_device_untrust_request;
        BtApplicationDeviceSearchRequest m_device_search_request;

        BtApplicationQuerySupportedProfilesRequest m_query_supported_profiles_request;
        BOOLEAN m_can_select;
        BtApplicationServiceVerifyRequest m_service_verify_request;
        BtOperationPtr m_operation;
        BtDeviceAndServiceClass m_device_and_service_class;
        BtRequestState m_state;
        BtLocalSettings*                    m_local_settings;

        WString m_selection_device_name;
        BtDeviceAndServiceClass m_device_class;
        BtDeviceAddress m_selection_device_address;

    private:

        friend class BtApplicationDevicePairRequest;
        friend class BtApplicationDeviceUnpairRequest;
        friend class BtApplicationDeviceSearchRequest;
        friend class BtApplicationDeviceTrustRequest;
        friend class BtApplicationDeviceUntrustRequest;
        friend class BtApplicationQuerySupportedProfilesRequest;
        friend class BtApplicationServiceVerifyRequest;
};




#endif /* BtDeviceListsWindows_hpp */
