/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtConnectionBasedController_hpp)
#define BtConnectionBasedController_hpp

#include <Bluetooth/BtController.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtConnectionBasedController: public BtController
{
    private:
        typedef BtController Base;

    public:
        BtConnectionBasedController();

        virtual ~BtConnectionBasedController();


        virtual UINT8 GetPriority() const;

    protected:

        virtual void Init();


        virtual btapi_userid_t GetUserId() const;


        virtual btapi_cb_funp_t* GetCallbackFunctionPointers() const;


        virtual BOOLEAN IsDeviceConnected(const BtDevice& device) const = 0;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtConnectionBasedController_hpp


