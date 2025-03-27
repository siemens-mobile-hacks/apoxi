/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_IpAddrEditorDocument_hpp)
#define Apoxi_IpAddrEditorDocument_hpp

#include <Gui/TextEditorDocument.hpp>
#include <Gui/CharItem.hpp>
#include <Gui/IpAddrCompoundItem.hpp>
#include <Auxiliary/WString.hpp>
#include <Auxiliary/IpAddr.hpp>

class IpAddrEditorDocument : public TextEditorDocument {
    typedef TextEditorDocument Base;

    public:
        IpAddrEditorDocument();

        explicit IpAddrEditorDocument(const IpAddr& ip_addr);

        virtual ~IpAddrEditorDocument();

        virtual INT GetMaxItemCount() const;

        void Init(const IpAddr& ip_addr);

        void SetIpAddr(const IpAddr& ip_addr);

        IpAddr GetIpAddr() const;

        BOOLEAN IsSeparator(INT index) const;

        BOOLEAN IsInvalid(INT index) const;
};

#endif  // Apoxi_IpAddrEditorDocument_hpp


