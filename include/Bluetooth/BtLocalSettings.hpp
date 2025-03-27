/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtLocalSettings_hpp)
#define BtLocalSettings_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Kernel/Condition.hpp>
#include <Kernel/Application.hpp>
#include <Kernel/UserDispatcher.hpp>

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtGapAndSdapRequestMessage.hpp>

class BtLocalSettings: public UserDispatcher, private BooleanCondition
{
    private:
        typedef UserDispatcher Base;

    public:
        BtLocalSettings(Application* application);

        virtual ~BtLocalSettings();


        UINT32 GetLocalSettingsId();


        BtStackState GetLocalState() const;


        BtResultCode TurnOn(BOOLEAN execute_synchron = FALSE);


        BtResultCode TurnOff(BOOLEAN execute_synchron = FALSE);


        BtResultCode GetChipVersion(BtChipVersion& chip_version) const;


        BtResultCode GetLocalAddress(BtDeviceAddress& device_address) const;


        BtResultCode GetLocalName(WString& local_name) const;


        BtResultCode SetLocalName(const WString& local_name, BOOLEAN execute_synchron = FALSE);


        BtResultCode GetDiscoverableMode(BtDiscoverableMode& discoverable_mode) const;


        BtResultCode SetDiscoverableMode(BtDiscoverableMode discoverable_mode = BtDmGeneralDiscoverable, BOOLEAN execute_synchron = FALSE);


        BtResultCode GetPairableMode(BtPairableMode& pairable_mode) const;


        BtResultCode SetPairableMode(BtPairableMode pairable_mode = BtPmPairable, BOOLEAN execute_synchron = FALSE);


        BtResultCode GetConnectableMode(BtConnectableMode& connectable_mode) const;


        BtResultCode SetConnectableMode(BtConnectableMode connectable_mode = BtCmConnectable, BOOLEAN execute_synchron = FALSE);


        BtResultCode GetIsProfileActive(BtProfile profile, BOOLEAN& active);


        BtResultCode SetIsProfileActive(BtProfile profile, BOOLEAN active, BOOLEAN execute_synchron = FALSE);


        using BooleanCondition::IsTrue;

    protected:

        virtual BOOLEAN OnMessage(const Message& message);


        virtual void OnStateChange(BtStackState stack_state);


        virtual void OnLocalName(BtResultCode result);


        virtual void OnDiscoverableMode(BtResultCode result);


        virtual void OnPairableMode(BtResultCode result);


        virtual void OnConnectableMode(BtResultCode result);


        virtual void OnProfileActivation(BtResultCode result);

    protected:

        typedef enum 
        {
            BtArNone = 0,
            BtArSwitchState       = BtStateChangedMessage::ID,
            BtArLocalName         = BtLocalNameMessage::ID,
            BtArDiscoverability   = BtDiscoverabilityMessage::ID,
            BtArPairability       = BtPairabilityMessage::ID,
            BtArConnectablity     = BtConnectabilityMessage::ID,
            BtArProfileActivation = BtProfileActivationMessage::ID
        } BtActiveRequest;

    private:

        BtLocalSettings* GetLocalSettings(BOOLEAN execute_synchron);


        BOOLEAN GetDone(void) const;


        void SetDone(BOOLEAN done);


        BtActiveRequest GetActiveRequest() const;


        BOOLEAN BeginRequest(BtActiveRequest active_request);


        void EndRequest();

    private:
        Mutex m_active_request_mutex;

        BtActiveRequest m_active_request;

        Application* m_application;

        BtResultCode* m_result;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtLocalSettings_hpp

