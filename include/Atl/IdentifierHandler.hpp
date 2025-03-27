/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_IdentifierHandler_hpp)
#define Atl_IdentifierHandler_hpp

class Feature;
class Property;

class IdentifierHandler  {

public:
    static WString      GetIdentifier(Feature* feature);
    static Feature*     GetFeature(const WString& identifier);
    static Property*    GetProperty(const WString& identifier);

#if defined(APOXI_COMPAT_2_7_0)

    static ImageObtainer GetImage(const WString& uri);
#endif

private:
    static Feature*     LookupById(const WString& identifier);
    
};

#endif  // Atl_IdentifierHandler_hpp


