/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_BtObexImplAddress_hpp)
#define Apoxi_BtObexImplAddress_hpp

#include <Auxiliary/String.hpp>
#include <Auxiliary/SharedPtr.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Obex/ObexAddress.hpp>


class BtObexServerObserverImpl;
class BtObexTransport;

class BtObexClientAddr : public ObexClientAddr
{
    friend class BtObexTransport;

    private:
        typedef ObexClientAddr Base;

    public:
        static SharedPtr<BtObexClientAddr>
                            Create(BtSecuritySettings       security    = BtSesNoSecurity,
                                   const BtDeviceAddress &  device_addr = bt_c_empty_device_address,
                                   UINT8                    rfcomm_chan = 0);

        virtual ObexResult  ToString(String &  obex_url) const;

        inline const BtDeviceAddress &  GetDeviceAddress() const
        {
            return  m_device_addr;
        }

        inline UINT8                    GetRfCommChannel() const
        {
            return  m_rfcomm_chan;
        }

        inline UINT8                    GetRemoteRfComm()
        {
            return  m_rfcomm_chan;
        }

        inline BtSecuritySettings       GetSecurity() const
        {
            return  m_security;
        }

        void                        GetRemoteAddr( UINT8* remote_addr );

        void    BtObexSetClientAddrInfo(const UINT8* remote_addr, UINT8 remote_channel );

    protected:
        BtObexClientAddr(BtSecuritySettings         security,
                         const BtDeviceAddress &    device_addr,
                         UINT8                      rfcomm_chan);

    private:
        BtDeviceAddress     m_device_addr;
        UINT8               m_rfcomm_chan;
        BtSecuritySettings  m_security;
};


class BtObexServerAddr : public ObexServerAddr
{
    friend class BtObexServerObserverImpl;
    friend class BtObexTransport;

    public:

        enum BtObexServerCodes
        {
            InvalidRfCommPortNumber = 0xFF
        };

        static SharedPtr<BtObexServerAddr> Create();

        virtual ObexResult ToString(String &  obex_url) const;

        UINT8   GetRfCommPortNumber();
        void    SetRfCommPortNumber( UINT8 rfcomm );
        void    SetServerUuid128( UINT8* service_id );
        void    SetServerTargetString( String target );

        void    SetSddbCase( UINT16 sddb_case );
        UINT16  GetSddbCase();
        void    SetServerDefaultParam();
        void    SetSecurity(BtSecuritySettings security) {m_security = security;};

        const String &      GetServiceName() const
        {
            return m_service_name;
        }

        BtSecuritySettings  GetSecurity() {return m_security;};

    protected:
        BtObexServerAddr();

    private:
        typedef ObexServerAddr Base;

        UINT8               m_uuid128[16];  
        UINT16              m_sddb_case;
        UINT8               m_local_rfcomm; 
        String              m_service_name;
        String              m_target;
        BtSecuritySettings  m_security;

        void                SetServiceName(const String &   service_name)
        {
            m_service_name = service_name;
        }

};

#endif

