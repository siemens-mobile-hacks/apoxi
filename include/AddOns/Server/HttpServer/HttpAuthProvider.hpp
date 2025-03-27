/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpAuthProvider_hpp)
#define Apoxi_AddOns_Server_HttpAuthProvider_hpp

#include <AddOns/Server/AuthProvider.hpp>
#include <Afs/Rfs/Pathname.hpp>

class HttpAuthProvider;

typedef NiSharedPtr<HttpAuthProvider> HttpAuthProviderPtr;

class HttpAuthProvider : public AuthProvider
{
    typedef AuthProvider Base;

    public:
        HttpAuthProvider();

        virtual ~HttpAuthProvider();

        virtual BOOLEAN AuthorizeUser(const String& username);

        virtual BOOLEAN AuthorizeUserPassword(const String& username, const String& password);

        virtual BOOLEAN IsAccessGranted(const String& username, const Path& path);
        
};

#endif  // Apoxi_AddOns_Server_HttpAuthProvider_hpp

