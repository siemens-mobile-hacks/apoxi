/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexTransport_hpp)
#define BtObexTransport_hpp

#include <Kernel/SubSystem.hpp>
#include <Devices/AbstractTransport.hpp>
#include <Obex/ObexTransport.hpp>
#include <Bluetooth/OBEX/ObexTransport/BtObexImpl.hpp>

// Forward declaration of classes
class BtDeviceAddress;


class BtObexTransport: public ObexAbstractTransport
{
    friend class BtObexClientAddrResultNotifier;

    private:
        typedef ObexAbstractTransport Base;

    public:

        static BtObexTransport* GetInstance();


        static BtObexImpl& GetObexInstance();


        virtual ObexProtocol* GetProtocol(ObexProtocolId level);


        virtual void ResolveClientAddr(const String& client_url, ObexProtocolId prot_id, ObexOperationId job_id);

        virtual void ResolveServerAddr(const String& server_url, ObexProtocolId prot_id, BOOLEAN sdb_autocreate, ObexOperationId job_id);

        virtual ~BtObexTransport();

    protected:

        BtObexTransport();
        void Init();

    private:
        static BtObexTransport  m_bt_obex_transport;
        static BOOLEAN          m_already_inst;
        BtObexImpl              m_bt_obex_impl;
};

class BtObexSubSystem : public SubSystem {
    public:
        virtual const WCHAR* GetName() const
        {
            return L"Bluetooth Obex";
        }
        virtual void OnPowerUp();

        virtual BootSequenceState InvokeAt() const
        {
           return SubSystemManager::c_run_level_1;
        }

    private:
        static BtObexSubSystem     s_bt_obex_sub_system;
};

#endif  // BtObexTransport_hpp


