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

#if ! defined(_Adc_RegBlobObject_hpp)
#define _Adc_RegBlobObject_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/BlobObject.hpp>
#include <Auxiliary/String.hpp>

#if !defined(APOXI_REG_MAX_MIME_TYPE_LEN)
    #define APOXI_REG_MAX_MIME_TYPE_LEN  30
#endif

static const INT c_apoxi_reg_max_mime_type_len = APOXI_REG_MAX_MIME_TYPE_LEN;

const GenericTypeId c_regblobobject_type = c_apoxi_base_gentypes + 3;

class RegBlobObject : public BlobObject
{
    public:
        typedef BlobObject Base;

        RegBlobObject();

        RegBlobObject(const UINT8 * data, INT length, const CHAR *mimetype);

        RegBlobObject(const RegBlobObject & obj);

        virtual ~RegBlobObject();

        RegBlobObject & operator = (const RegBlobObject & szCopy);

        virtual GenericObject * Copy() const;

        virtual BOOLEAN         IsEqual(GenericObject * object);

        virtual GenericTypeId   GetTypeId();

        void Update(const UINT8 *data, INT length, const CHAR *mime_type);

        void Clear();

        void Allocate(INT length);

        void Reallocate(INT length);

        void Append(const UINT8 *data, INT length);

        void CutOff(INT length);

        INT  Poke(INT offset, const UINT8 *data, INT length);

        INT Peek(INT offset, UINT8 *&data, INT length);

        BOOLEAN IsEmpty() const { return (m_data == 0 || m_length == 0); }

        BOOLEAN RegGetMimeType(String &mime_type);

        BOOLEAN RegSetMimeType(String &mime_type);
        
        INT32 RegGetSize() { return m_length + m_mime_type.GetLength() + 1; }

        INT32 RegGetDataSize() { return m_length; }

        INT16 RegGetMimeTypeSize() { return m_mime_type.GetLength() + 1; }


    private:
        String m_mime_type;

};


#endif


