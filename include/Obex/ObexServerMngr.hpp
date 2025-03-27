/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexServerMngr_hpp)
#define Apoxi_ObexServerMngr_hpp

#include <Auxiliary/LinkedList.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexResult.hpp>
#include <Obex/ObexServerInfo.hpp>

//  Forward declarartions of classes
class ObexServer;
class ObexOppServer;
class ObexServerVisitor;

class ObexServerMngr
{
    public:
        ObexServerMngr();

        ObexServerId    Register(ObexServerInfo &       info_item,
                                 ObexServerVisitor &    checker,
                                 ObexServerId           special_id);

        void            Deregister(ObexServerInfo &     server_info);

        ObexServerId    Iterate(ObexServerVisitor &     visitor);

    private:
        typedef LinkedList<ObexServerInfo>  ServerInfoList;

        ServerInfoList  m_server_info_list;
};

#endif  // Apoxi_ObexServerMngr_hpp

