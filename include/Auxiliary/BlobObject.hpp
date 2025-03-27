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

#if ! defined(_Adc_BlobObject_hpp)
#define _Adc_BlobObject_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/BlobPtr.hpp>

const GenericTypeId c_blobobject_type = c_apoxi_base_gentypes + 2;

class BlobObject : public BlobPtr
{
    public:
        typedef BlobPtr Base;

        BlobObject();
        BlobObject(const UINT8 * data, INT length);
        BlobObject(const BlobObject & obj);

        virtual ~BlobObject();

        BlobObject & operator = (const BlobObject & szCopy);

        virtual GenericObject * Copy() const;
        virtual BOOLEAN         IsEqual(GenericObject * object);
        virtual GenericTypeId   GetTypeId();

        void Update(const UINT8 *data, INT length);

        void Clear();

        void Allocate(INT length);

        void Reallocate(INT length);

        void Append(const UINT8 *data, INT length);

        void CutOff(INT length);

        INT  Poke(INT offset, const UINT8 *data, INT length);

        INT Peek(INT offset, UINT8 *&data, INT length);

        BOOLEAN IsEmpty() const { return (m_data == 0 || m_length == 0); }

    private:

};

#endif


