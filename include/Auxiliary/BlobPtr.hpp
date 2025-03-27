/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(_Adc_BlobPtr_hpp)
#define _Adc_BlobPtr_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/GenericObject.hpp>

const GenericTypeId c_blobptr_type = c_apoxi_base_gentypes + 1;

class BlobPtr : public GenericObject
{
    public:
        typedef GenericObject Base;

        BlobPtr();
        BlobPtr(UINT8 * data, INT length);
        BlobPtr(const BlobPtr & obj);

        virtual ~BlobPtr();

        BlobPtr & operator = (const BlobPtr & szCopy);

        virtual GenericObject * Copy() const;
        virtual BOOLEAN         IsEqual(GenericObject * object);
        virtual GenericTypeId   GetTypeId();

        UINT8 * GetDataPtr() const { return m_data; };
        INT GetLength() const { return m_length; };

    protected:
        UINT8 *  m_data;
        INT    m_length;

};

#endif

