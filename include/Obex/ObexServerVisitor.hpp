/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexServerVisitor_hpp)
#define Apoxi_ObexServerVisitor_hpp

//  Forward declarartions of classes
class ObexServer;
class ObexOppServer;

class ObexServerVisitor {

    public:
        virtual ~ObexServerVisitor();

        virtual BOOLEAN     VisitObexServer(const ObexServer &  server);

        virtual BOOLEAN     VisitOppServer(const ObexOppServer &  server);

    protected:
        //  Default constructor. Forbids direct instantiation of the class.
        ObexServerVisitor();
};

#endif  // Apoxi_ObexServerVisitor_hpp

