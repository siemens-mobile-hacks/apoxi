/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexProtocol_hpp)
#define Apoxi_ObexProtocol_hpp

#include <Auxiliary/NonCloneable.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexResult.hpp>
#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexOperationId.hpp>

// Forward declarations of classes.
class ObexChannel;

class ObexProtocol : public NonCloneable {

    public:
        typedef ObexProtocolId TypeId;

        inline TypeId       GetTypeId() const;

        virtual ObexResult  AcquireClientChannel(ObexChannel &        result,
                                                 const ObexAddrPtr &  addr_ptr,
                                                 BOOLEAN              reserve) = 0;

        virtual ObexResult  AcquireServerChannel(ObexChannel &        result,
                                                 const ObexAddrPtr &  addr_ptr,
                                                 BOOLEAN              reserve) = 0;

        virtual ObexResult  ReleaseChannel(ObexChannel &  channel) = 0;

        virtual void OpenClientChannel(const ObexChannel &  client_chan,
                                       ObexOperationId      oper_id,
                                       const ObexAddrPtr &  addr_ptr) = 0;

        virtual void BindServerChannel(const ObexChannel &  server_chan,
                                       ObexOperationId      oper_id,
                                       const ObexAddrPtr &  addr_ptr) = 0;

        virtual void CloseChannel(const ObexChannel &  channel,
                                  ObexOperationId      oper_id) = 0;

    protected:
        ObexProtocol(TypeId  type_id);

        void    OnTransportError(const ObexChannel &    channel,
                                 ObexOperationId        oper_id,
                                 ObexResult             status);

        void    OnComplete(const ObexChannel &  channel,
                           ObexOperationId      oper_id,
                           ObexResult           result);
    private:
        const TypeId  m_type_id;
};


/*  ----------------------------------------------------------------------
    GetTypeId
    ---------------------------------------------------------------------- */
ObexProtocol::TypeId  ObexProtocol::GetTypeId()
const
{
    return m_type_id;
}// GetTypeId

#endif  // Apoxi_ObexProtocol_hpp

