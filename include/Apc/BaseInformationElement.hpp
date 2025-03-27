/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_BaseInformationElement_hpp)
#define Apc_BaseInformationElement_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/WString.hpp>
#include <Apc/InformationElement.hpp>


/*  ========================================================================
    BaseInformationElement 
    ======================================================================== */
class BaseInformationElement
{
    public:
        enum Type {
            WStringIE,
            UserDataHeaderIE,
            MissingPduIE,
            EndOfPduIE,
            Invalid
        };

        BaseInformationElement();
        BaseInformationElement(const BaseInformationElement & BaseInformationElement);
        BaseInformationElement(Type type);
        BaseInformationElement(const WString & wstr);
        BaseInformationElement(const InformationElement & udhie);
        BaseInformationElement(UINT8 * buffer);
        virtual ~BaseInformationElement();
        BOOLEAN IsValid() const { return m_type!=Invalid; }
        Type GetType() const { return m_type; }
        const WString & GetWString() const { return m_wstring; }
        const InformationElement & GetInformationElement() const { return m_udh_ie; }

        BaseInformationElement & operator = (const BaseInformationElement & item);

    private:
        Type                m_type;
        WString             m_wstring;
        InformationElement  m_udh_ie;
};



#endif  // Apc_BaseInformationElement_hpp


