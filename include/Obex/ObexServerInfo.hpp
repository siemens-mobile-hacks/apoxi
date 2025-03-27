/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexServerInfo_hpp)
#define Apoxi_ObexServerInfo_hpp

#include <Auxiliary/Linkable.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexResult.hpp>

//  Forward declarartions of classes
class ObexServerVisitor;

class ObexServerInfo : public Linkable<ObexServerInfo> {

    friend  class ObexServerMngr;

    public:
        enum {
            NoServerId    =   0,    
            FirstServerId =   1,    
            DefaultServerId = 254,  
            OppImplServerId = 255   
        };

        ObexServerInfo();

        virtual ~ObexServerInfo();

        virtual BOOLEAN         Accept(ObexServerVisitor &  v) = 0;

        /*  @brief  Registers a server information record with the server
                    manager.

            @param  checker     An ObexServerVisitor which performs an ambiguity
                                check on the record to be registered.
                                If ambiguity is detected, \c Accept(checker) shall
                                return \c 'FALSE'.

            @param  propose_id  Permits specifying a reserved id, like for OPP
                                or the default inbox. When \c 'FirstServerId'
                                is passed, a regular entry is assumed and the
                                id is assigned by \c ObexServerMngr. */
        ObexResult  Register(ObexServerVisitor &    checker,
                             ObexServerId           propose_id = FirstServerId);

        void        Deregister();

        /*  @brief  Returns the ObexServerId assigned at registration time.

            @return \c ObexServerId assigned by the server manager or
                    \c NoServerId when currectly not registered. */
        inline  ObexServerId    GetServerId() const;

    private:
        ObexServerId            m_server_id;

        inline  void            SetServerId(ObexServerId    server_id);
};

/*  ----------------------------------------------------------------------
    GetServerId
    ---------------------------------------------------------------------- */
ObexServerId    ObexServerInfo::GetServerId()
const
{
    return  m_server_id;
}// GetServerId

/*  ----------------------------------------------------------------------
    SetServerId
    ---------------------------------------------------------------------- */
void    ObexServerInfo::SetServerId(ObexServerId    server_id)
{
    m_server_id = server_id;
}// SetServerId

#endif  // Apoxi_ObexServerInfo_hpp


