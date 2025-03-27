/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtController_hpp)
#define BtController_hpp

#include <Kernel/Os/Mutex.hpp>
#include <Kernel/SubSystem.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtController: public SubSystem
{
    private:
        typedef SubSystem Base;

    public:
        BtController();

        virtual ~BtController();


        virtual void OnPowerUp();


        virtual void OnPowerDown();


        virtual BootSequenceState InvokeAt() const;

    protected:

        virtual void Init() = 0;


        virtual void CleanUp();


        virtual void Register() = 0;


        virtual void Unregister() = 0;


        BOOLEAN GetIsRegistered() const;


        void SetIsRegistered(BOOLEAN is_registered);


        virtual btapi_userid_t GetUserId() const = 0;


        virtual btapi_cb_funp_t* GetCallbackFunctionPointers() const = 0;


        void PerformExecutionCallback(BtRequest* request, BtResultCode result);

    private:
        BOOLEAN m_is_registered;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtController_hpp


