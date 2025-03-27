/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexDispatcher_hpp)
#define Apoxi_ObexDispatcher_hpp

#include <Kernel/MessageMapDispatcher.hpp>
#include <Kernel/MessageMap.hpp>

#include <Obex/ObexTypes.hpp>

// Forward declarations of classes.
class ExecutionContext;
class ObexMsg;
class ObexAddrMsg;
class ObexTransportMsg;

class ObexEventHandler {

    friend class ObexDispatcher;

    public:
        virtual ~ObexEventHandler() {}

    protected:
        ObexEventHandler() {}

        virtual BOOLEAN     IsValidContext() const = 0;

        virtual BOOLEAN     OnObexMsg(const ObexMsg &   msg) = 0;
        virtual BOOLEAN     OnObexAddrMsg(const ObexAddrMsg &   msg) = 0;
        virtual BOOLEAN     OnObexTransportMsg(const ObexTransportMsg & msg) = 0;
};


class ObexDispatcher : public MessageMapDispatcher {

    public:
        ObexDispatcher(ObexProtocolId   type_id);

        virtual ~ObexDispatcher();

        virtual void                Init(ExecutionContext *     ctx_ptr,
                                         ObexEventHandler *     handler_ptr);

        void                        Attach();

        void                        Detach();

        BOOLEAN                     IsInValidContext() const;

        inline  ObexProtocolId      GetTypeId() const;

        inline  Application *       GetAppPtr() const;

        inline  ExecutionContext &  GetContext() const;

    private:
        typedef MessageMapDispatcher                    Base;
        typedef MessageMap<ObexEventHandler>            ObexMsgMapElement;
        typedef MessageMapContainer<ObexEventHandler>   ObexMsgMapContainer;

        static  const ObexMsgMapElement                 c_msg_map[];

        ObexMsgMapContainer                             m_msg_map_container;
        ExecutionContext *                              m_ctx_ptr;
        ObexEventHandler *                              m_handler_ptr;
        const ObexProtocolId                            c_type_id;
};

/*  ----------------------------------------------------------------------
    GetTypeId
    ---------------------------------------------------------------------- */
ObexProtocolId      ObexDispatcher::GetTypeId()
const
{
    return  c_type_id;
}// GetTypeId

/*  ----------------------------------------------------------------------
    GetAppPtr
    ---------------------------------------------------------------------- */
Application *       ObexDispatcher::GetAppPtr()
const
{
    return  (Application *) m_ctx_ptr;
}// GetAppPtr

/*  ----------------------------------------------------------------------
    GetContext
    ---------------------------------------------------------------------- */
ExecutionContext &  ObexDispatcher::GetContext()
const
{
    ASSERT_DEBUG(m_ctx_ptr != 0);

    return  *m_ctx_ptr;
}// GetContext

#endif  // Apoxi_ObexDispatcher_hpp

