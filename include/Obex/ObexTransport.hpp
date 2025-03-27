/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexTransport_hpp)
#define Apoxi_ObexTransport_hpp

#include <Auxiliary/Observer.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexConfig.hpp>
#include <Obex/ObexResult.hpp>
#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexOperationId.hpp>

// Forward declarations of classes
class ObexProtocol;
class AbstractTransport;

class ObexAbstractTransport : public Observer {

    public:
        typedef ObexTransportId     ObjectId;

        enum {
            ClientAddrTypeId = 0,   
            ServerAddrTypeId = 0x80 
        };

        enum {
            NoObjectId = APOXI_OBEX_MAX_NO_TRANSPORTS
        };

        inline  ObjectId                GetObjectId() const;

        inline  ObexAddrTypeId          GetClientAddrTypeId() const;

        inline  ObexAddrTypeId          GetServerAddrTypeId() const;

        inline  AbstractTransport &     GetDeviceAbstraction() const;

        inline  const CHAR *    GetUrlScheme() const;

        BOOLEAN                 IsMatchedByUrl(const String &  obex_url) const;

        virtual ObexProtocol *  GetProtocol(ObexProtocolId  level) = 0;

        virtual void    ResolveServerAddr(const String &    local_url,
                                          ObexProtocolId    prot_id,
                                          BOOLEAN           sdb_autocreate,
                                          ObexOperationId   job_id) = 0;

        virtual void    ResolveClientAddr(const String &    remote_url,
                                          ObexProtocolId    prot_id,
                                          ObexOperationId   job_id) = 0;

        virtual void    AbortResolveClientAddr(const ObexOperationId &  job_id) {}

    protected:
        ObexAbstractTransport();

        void            Init(AbstractTransport &    device_abs,
                             const CHAR *           scheme_url);

        void            Register();

        void            ReturnObexAddress(const ObexAddrPtr &   addr_ptr,
                                          ObexOperationId       oper_id,
                                          ObexResult            result);
        virtual void    OnUpdate(ObservableObject *     obs_obj);

    private:
        const CHAR *            m_scheme_ptr;   
        AbstractTransport *     m_abs_xp_ptr;   
        ObjectId                m_object_id;    

        ObexAbstractTransport(const ObexAbstractTransport &);

        ObexAbstractTransport &     operator=(const ObexAbstractTransport &);

        inline  BOOLEAN             IsRegistered() const;
};


/*  ----------------------------------------------------------------------
    GetObjectId
    ---------------------------------------------------------------------- */
ObexAbstractTransport::ObjectId     ObexAbstractTransport::GetObjectId()
const
{
    return m_object_id;
}// GetObjectId

/*  ----------------------------------------------------------------------
    GetClientAddrTypeId
    ---------------------------------------------------------------------- */
ObexAddrTypeId  ObexAbstractTransport::GetClientAddrTypeId()
const
{
    return ( ClientAddrTypeId + GetObjectId() );
}// GetClientAddrTypeId

/*  ----------------------------------------------------------------------
    GetServerAddrTypeId
    ---------------------------------------------------------------------- */
ObexAddrTypeId  ObexAbstractTransport::GetServerAddrTypeId()
const
{
    return ( ServerAddrTypeId + GetObjectId() );
}// GetServerAddrTypeId

/*  ----------------------------------------------------------------------
    GetDeviceAbstraction
    ---------------------------------------------------------------------- */
AbstractTransport &     ObexAbstractTransport::GetDeviceAbstraction()
const
{
    ASSERT_DEBUG_HOST(m_abs_xp_ptr != 0);

    return  *m_abs_xp_ptr;
}// GetDeviceAbstraction

/*  ----------------------------------------------------------------------
    GetUrlSchemePtr
    ---------------------------------------------------------------------- */
const CHAR *    ObexAbstractTransport::GetUrlScheme()
const
{
    return m_scheme_ptr;
}

/*  ----------------------------------------------------------------------
    IsRegistered
    ---------------------------------------------------------------------- */
BOOLEAN     ObexAbstractTransport::IsRegistered()
const
{
    return  ( GetObjectId() != NoObjectId );
}

#endif  // Apoxi_ObexTransport_hpp

