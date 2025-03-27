/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexAddress_hpp)
#define Apoxi_ObexAddress_hpp

#include <Auxiliary/ObjectReferrer.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexResult.hpp>

// Forward declarations of classes.
class ObexAbstractTransport;


class ObexAddress : public ReferableObject {

    public:
        typedef ReferableObject Base;

        virtual ObexAddrTypeId      GetTypeId() const = 0;

        virtual ObexResult          ToString(String &  obex_url) const;

        inline  ObexTransportId     GetTransportId() const;

        ObexAbstractTransport &     GetTransport() const;

    protected:
        ObexAddress(ObexTransportId     transport_id);

    private:
        const ObexTransportId   c_transport_id;
};


class ObexClientAddr : public ObexAddress {

    public:
        typedef ObexAddress Base;

        virtual ObexAddrTypeId  GetTypeId() const;

    protected:
        ObexClientAddr(ObexTransportId  transport_id);
};


class ObexServerAddr : public ObexAddress {

    public:
        typedef ObexAddress Base;

        virtual ObexAddrTypeId  GetTypeId() const;

        /*  @brief  Tells whether address was auto - registered by transport.

            The default implementation returns always \c 'TRUE'.

            @return \c 'TRUE' when the transport that created this address has
                    registered it with a service discovery database or if no
                    such facility exists, \c 'FALSE' if application software
                    needs to perform service registration. */
        virtual BOOLEAN         IsAutoRegistered() const;

    protected:
        ObexServerAddr(ObexTransportId  transport_id);
};

/*  ----------------------------------------------------------------------
    GetTransportId
    ---------------------------------------------------------------------- */
ObexTransportId     ObexAddress::GetTransportId()
const
{
    return  c_transport_id;
}

#endif  // Apoxi_ObexAddress_hpp

