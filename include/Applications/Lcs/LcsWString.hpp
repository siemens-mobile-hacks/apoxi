/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsWString_hpp)
#define Mmi_LcsWString_hpp

#include <Auxiliary/WString.hpp>

struct ClientId;
struct ClientName;

class LcsWString : public WString
{
    typedef WString Base;

    public:

        LcsWString();

        LcsWString(const WString& rhs);

        ~LcsWString();

        LcsWString& operator =(const WString& rhs);

        LcsWString& operator <<(const CHAR* rhs);
    
        LcsWString& operator <<(UINT16 invoke_id);

        LcsWString& operator <<(const ClientId& client_id);

        LcsWString& operator <<(const ClientName& client_name);

        operator UINT32() const;

        operator INT32() const;

        void ConvertToBcd(BYTE* type, INT size);

}; // LcsWString

#endif // Mmi_LcsWString_hpp
