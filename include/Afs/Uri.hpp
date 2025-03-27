/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_Uri_hpp)
#define Apoxi_Uri_hpp
#include <Auxiliary/String.hpp>

class Uri : private String {

    typedef String Base;

    public:

        Uri() {};

        ~Uri() {};

        Uri(const Uri& szCopy);

        Uri(const Uri* szCopy);

        Uri(const String& szCopy);

        Uri(const CHAR* pchCopy);

        Uri & operator =(const Uri & szCopy);


        using Base::find;
        using Base::compare;
        using Base::Compare;
        using Base::c_str;
        using Base::length;
        using Base::Clear;
        using Base::IsEmpty;
        //using Base::operator +;

        Uri operator+ (const Uri & szConcat) const
        {
            return Base::operator + (szConcat);
        }
                
        void operator += (const Uri & szConcat);

        Uri & operator << (const Uri & right);

        BOOLEAN operator == (const Uri & szcompare) const;

        BOOLEAN operator != (const Uri & szcompare) const;

        BOOLEAN endswith(const Uri & other) const;
        
        BOOLEAN startswith(const Uri & other) const;

        BOOLEAN ValidateUri() const;

        void FormatUriHeader(Uri& return_string) const;

        void GetUriHeader(Uri& return_string) const;

        void FormatLockTableUri(Uri& return_string) const; 

        void TruncateUri(Uri& return_string) const;

        BOOLEAN GetParentUri(Uri& return_uri) const;

    
        BOOLEAN GetChildName(String& node_name) const;

        INT GetUriDepth() const;

        using Base::empty;
        
        using Base::ToWString;

};
#endif

