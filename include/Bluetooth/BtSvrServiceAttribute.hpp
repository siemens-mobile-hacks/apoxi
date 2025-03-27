/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSvrServiceAttribute_hpp)
#define BtSvrServiceAttribute_hpp

#include <stack/extensions.h>
#include <Bluetooth/BtSvrDataElement.hpp>

/*  ------------------------------------------------------------------------
    forward declartion
    ------------------------------------------------------------------------ */
class BtSvrServiceRecord;

class BtSvrServiceAttribute
{
    private:
        friend class BtSvrServiceRecord;

    public:
        BtSvrServiceAttribute();

        virtual ~BtSvrServiceAttribute();

    public:

        BOOLEAN IsValid() const;


        UINT16 GetAttributeId() const;


        BOOLEAN GetAttributeValue(BtSvrDataElement& svr_data_element) const;

    private:

        BtSvrServiceAttribute(const btapi_attr_t& service_attribute);


        BtSvrServiceAttribute& operator=(const BtSvrServiceAttribute& srv_service_attribute);

    private:
        BOOLEAN m_is_valid;

        btapi_attr_t m_service_attribute;
};

#endif  // BtSvrServiceAttribute_hpp

