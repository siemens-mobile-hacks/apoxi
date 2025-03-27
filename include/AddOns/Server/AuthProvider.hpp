/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_AuthProvider_hpp)
#define Apoxi_AddOns_Server_AuthProvider_hpp

#include <Auxiliary/NiSharedPtr.hpp>
#include <Afs/Rfs/Path.hpp>

class AuthProvider;

typedef NiSharedPtr<AuthProvider> AuthProviderPtr;

class AuthProvider 
{
    public:
        AuthProvider();

        virtual ~AuthProvider();

        virtual BOOLEAN AuthorizeUser(const String& username) = 0;

        virtual BOOLEAN AuthorizeUserPassword(const String& username, const String& password) = 0;

        virtual BOOLEAN IsAccessGranted(const String& username, const Path& path) = 0;
        
};

#endif  // Apoxi_AddOns_Server_AuthProvider_hpp

