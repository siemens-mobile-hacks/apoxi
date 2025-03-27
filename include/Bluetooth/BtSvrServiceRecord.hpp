/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSvrServiceRecord_hpp)
#define BtSvrServiceRecord_hpp

#include <stack/extensions.h>
#include <Bluetooth/BtSvrServiceAttribute.hpp>

/*  ------------------------------------------------------------------------
    forward declaration
    ------------------------------------------------------------------------ */

class BtServiceVerifyResult;

class BtSvrServiceRecord
{
    private:
        friend class BtServiceVerifyResult;

    public:
        BtSvrServiceRecord();

        virtual ~BtSvrServiceRecord();

    public:

        BOOLEAN IsValid() const;


        UINT16 GetNumberOfServiceAttributes() const;


        BOOLEAN GetServiceAttributeAtIndex(UINT16 index, BtSvrServiceAttribute& svr_service_attribute) const;


        BOOLEAN GetServiceAttributeById(UINT16 id, BtSvrServiceAttribute& svr_service_attribute) const;

    private:

        BtSvrServiceRecord(const btapi_de_t& service_record);


        BtSvrServiceRecord& operator=(const BtSvrServiceRecord& svr_service_record);

    private:
        BOOLEAN m_is_valid;

        btapi_de_t m_service_record;

        UINT16 m_number_of_service_attributes;
};

#endif  // BtSvrServiceRecord_hpp

