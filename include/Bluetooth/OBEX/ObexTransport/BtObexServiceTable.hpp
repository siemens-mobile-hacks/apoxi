/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_BtObexServiceTable_hpp)
#define Apoxi_BtObexServiceTable_hpp

#include <Kernel/Types.hpp>
#include <Bluetooth/BtTypes.hpp>

#ifndef APOXI_BT_OBEX_SYSTEM_CLIENT_SECURITY
    #define APOXI_BT_OBEX_SYSTEM_CLIENT_SECURITY BtSesNoSecurity
#endif

#ifndef APOXI_BT_OBEX_SYSTEM_SERVER_SECURITY
    #define APOXI_BT_OBEX_SYSTEM_SERVER_SECURITY BtSesAuthorization
#endif

// Forward declarations of classes
class   ByteBuffer;


class BtObexServiceTable {

    public:
        enum {
            MAX_LEN_TARGET = 24
        };

        typedef UINT8   ServiceType;

        struct ObexTarget {
            UINT8       data[MAX_LEN_TARGET];
            UINT8       length;
        };

        struct Security {
            BtSecuritySettings  client;
            BtSecuritySettings  server;
        };

        struct Entry {
            ServiceType         service_type;
            Security            service_ses;
            BtUUID              service_class;
            const CHAR *        service_name;
            ObexTarget          obex_target;
        };


        class   ServiceInfo {

            friend class BtObexServiceTable;

            public:
                ServiceInfo();

                BOOLEAN             IsValid() const
                {
                    return ( m_desc_ptr != 0 );
                }

                BOOLEAN             IsEqualTo(const ServiceInfo &   rhs) const
                {
                    return ( m_desc_ptr == rhs.m_desc_ptr );
                }

                ServiceType         GetServiceType() const
                {
                    return IsValid() ? m_desc_ptr->service_type : 0;
                }

                const CHAR *        GetServiceName() const
                {
                    return IsValid() ? m_desc_ptr->service_name : "";
                }

                BtSecuritySettings  GetClientSecurity() const
                {
                    return IsValid() ? m_desc_ptr->service_ses.client
                                     : APOXI_BT_OBEX_SYSTEM_CLIENT_SECURITY;
                }

                BtSecuritySettings  GetServerSecurity() const
                {
                    return IsValid() ? m_desc_ptr->service_ses.server
                                     : APOXI_BT_OBEX_SYSTEM_SERVER_SECURITY;
                }

                BOOLEAN             GetServiceClass(BtUUID &    uuid) const;

                BOOLEAN             GetObexTarget(ByteBuffer &  target) const;

            private:
                const Entry *   m_desc_ptr;

                ServiceInfo(const Entry *   m_desc_ptr);
        };

        static  ServiceInfo     GetServiceInfoByType(UINT                   serv_type);
        static  ServiceInfo     GetServiceInfoByUuid(const BtUUID &         uuid);
        static  ServiceInfo     GetServiceInfoByTarget(const ByteBuffer &   target);

        static  void            ExtendToUuid128(BtUUID &                    uuid128,
                                                const BtUUID &              uuid_in);
    private:
        static  const Entry     s_table[];

        BtObexServiceTable();
       ~BtObexServiceTable();

        static  BOOLEAN         TestUuidsEqual(const BtUUID &   lhs,
                                               const BtUUID &   rhs);
};


inline  BOOLEAN     operator==(const BtObexServiceTable::ServiceInfo &  lhs,
                               const BtObexServiceTable::ServiceInfo &  rhs)
{
    return  lhs.IsEqualTo(rhs);
}


inline  BOOLEAN     operator!=(const BtObexServiceTable::ServiceInfo &  lhs,
                               const BtObexServiceTable::ServiceInfo &  rhs)
{
    return  ! lhs.IsEqualTo(rhs);
}


#endif  // BtObexServiceTable.hpp

