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

#if ! defined(_Adc_GenericObject_hpp)
#define _Adc_GenericObject_hpp

#include <Kernel/Types.hpp>



typedef INT GenericTypeId;

const GenericTypeId c_apoxi_base_gentypes = 0;
const GenericTypeId c_user_base_gentypes  = 1000;

class GenericObject
{
    public:
        GenericObject();

        GenericObject(const GenericObject &);

        virtual ~GenericObject();
    
        virtual GenericObject * Copy() const = 0;
        virtual BOOLEAN         IsEqual(GenericObject * object) = 0;
        virtual GenericTypeId   GetTypeId() = 0;
        BOOLEAN IsSameType(GenericObject * object);
};


#endif


